#include "Project_Path.h"
#include RELATIVE_PATH(Robot.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(ZGZG.h)
#include RELATIVE_PATH(GTSP.h)
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(CNCH.h)
#include RELATIVE_PATH(MOVH.h)
#undef PROJECT_PATH_H

#ifdef ENABLE_SIMULATION
#include "Headers\SIMU.h"
#include <iostream>
using namespace std;
#endif

/*global variable declaration*/
#ifdef POINT_LIST_ENABLE
Point Pointlist[POINT_LIST_SIZE];
static uint8 PointListIndex = 0;
#endif

Map RoomMap;
Boolean ZigZagFlag = FALSE;
volatile Boolean BumperHit = FALSE;
Boolean ToStartPoint = TRUE;
enu_Direction_req Direction_req = REQUEST_NORTH;
Robot cleaner = Robot::initRobotPosition();
volatile uint64 last_micros = 0;

#ifdef FINISHUP_EMPTY_SLOTS
#ifdef GO_TO_GOAL_STRAIGHTLINES
static Boolean GoToGoal_Straightlines_Flag = FALSE;
#endif
static Boolean GoToGoal_PID_flag = FALSE;
#endif
static Boolean GO_BACK_TO_CHARGER = FALSE;

/*-----------------static functions declaration------------------*/
static Boolean CheckPointUpdatePos(PointPos TempPointPos, Heading heading, Map& RoomMap);
static uint8 NearBusyPointSearch(PointPos TempPointPos);
static void ISR_left_Encoder_tick(void);
static void ISR_BumperHit(void);
#ifdef FINISHUP_EMPTY_SLOTS
#ifdef GO_TO_GOAL_STRAIGHTLINES
static void GoToGoal_Empty(Robot& cleaner, Map& RoomMap);
#endif
static void FinishUpLeftEmpty(Robot& cleaner, Map& RoomMap, enu_Direction_req* Direction_req);
#endif
#ifdef DEBUG
static void Map_Print(Map room);
#endif


void setup()
{
        Wire.begin();
		
        #ifdef DEBUG
        Serial.begin(9600);
        Serial.println("start setup");
        #endif

		Comp compass;

	/*=============================Intialize project==============================*/
        
        /*input and output pins*/
        pinMode (RIGHT_MOTOR_POSITIVE_PIN, OUTPUT);
        pinMode (RIGHT_MOTOR_GROUND_PIN, OUTPUT);
        pinMode (LEFT_MOTOR_POSITIVE_PIN, OUTPUT);
        pinMode (LEFT_MOTOR_GROUND_PIN, OUTPUT);

        Comp::InitializeDirections();
        
        Serial.print("NORTH initial value: ");
        Serial.println(NORTH_VALUE);

        Serial.print("WEST initial value: ");
        Serial.println(WEST_VALUE);

        Serial.print("SOUTH initial value: ");
        Serial.println(SOUTH_VALUE);

        Serial.print("EAST initial value: ");
        Serial.println(EAST_VALUE);

        delay(2000);
  
	/*pin 0 in interrupt is pin 2 in arduino*/
		attachInterrupt(FRONT_SENSOR_INTERRUPT_NUMBER, ISR_BumperHit, RISING);
#ifdef ENCODER_ON_INTERRUPT
	attachInterrupt(ENCODER_INTERRUPT_NUMBER, ISR_left_Encoder_tick, RISING);
#endif
	/*------------------Map Init Data-------------------*/
	
	RoomMap.initMap();

	/*----------------Robot Init Data------------------*/
	RobotPos RobTempPosition = cleaner.GetRobotPosition();

	/*----------------------INIT--------------------*/
	CNCH RunConnectionCheck;
	Serial.print("Check connection result: ");
	Serial.println(RunConnectionCheck.Get_CheckResult());
  delay(2000);
 
#ifdef ENABLE_SIMULATION
	simu sim;
#endif
#ifdef RECTANGLE
	L_R_Dist diagonalList[FULL_SCAN_NUM];
	RectSize rectsize;
	return_type Error_Check;
#endif

	/*=========================Start Implementation=======================*/

	RobTempPosition = cleaner.GetRobotPosition();
	RoomMap.addRobotOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
#ifdef RECTANGLE
	Error_Check = Rectangle::ConstructRect(diagonalList, &rectsize, cleaner, &robPosInRect);
	Rectangle rect1(rectsize);
	rect1.getRectSize(&rectsize);

	if (Error_Check == RET_OK)
	{
		RoomMap.AddRectangle(rect1, &RobTempPosition);
	}
#endif
}

void loop()
{
		/*go to extreme left of map to scan room*/
#ifdef DEBUG_OFF
Serial.println("start loop");
#endif
#ifdef DEBUG
Serial.print("Robot position.Y: ");
Serial.println(cleaner.GetRobotPosition().Y_pos);
#endif
		GTSP::GoToStartPoint(cleaner, RoomMap, &Direction_req);

		ZGZG::ZigZagRoutine(cleaner, RoomMap, &Direction_req);

#ifdef DEBUG
		Map_Print(RoomMap);
#endif

#ifdef FINISHUP_EMPTY_SLOTS
#ifdef GO_TO_GOAL_STRAIGHTLINES
		GoToGoal_Empty(cleaner, RoomMap);
#endif
		FinishUpLeftEmpty(cleaner, RoomMap, &Direction_req);
#endif
#ifdef ENABLE_SIMULATION
		sim.printMap(RoomMap);
#endif

	//system("pause");
}

#ifdef UPDATE_POINT_POSITION
static Boolean CheckPointUpdatePos(PointPos newPointPos, Heading heading, Map& RoomMap)
{
	Boolean PosUpdateCheck = FALSE;
	PointPos TempPointPos = newPointPos;
	if ((heading == NORTH) || (heading == SOUTH))
	{
		if (RoomMap.ReadPointFromMap(TempPointPos.Y_Row, TempPointPos.X_Column - 1) == BUSY)
		{
			TempPointPos.X_Column = TempPointPos.X_Column - 1;
			PosUpdateCheck = TRUE;
		}
		else if (RoomMap.ReadPointFromMap(TempPointPos.Y_Row, TempPointPos.X_Column + 1) == BUSY)
		{
			TempPointPos.X_Column = TempPointPos.X_Column + 1;
			PosUpdateCheck = TRUE;
		}
		else
		{
			/*do nothing*/
		}
	}
	else if ((heading == WEST) || (heading == EAST))
	{
		if (RoomMap.ReadPointFromMap(TempPointPos.Y_Row - 1, TempPointPos.X_Column) == BUSY)
		{
			TempPointPos.Y_Row = TempPointPos.Y_Row - 1;
			PosUpdateCheck = TRUE;
		}
		else if (RoomMap.ReadPointFromMap(TempPointPos.Y_Row + 1, TempPointPos.X_Column) == BUSY)
		{
			TempPointPos.Y_Row = TempPointPos.Y_Row + 1;
			PosUpdateCheck = TRUE;
		}
		else
		{
			/*do nothing*/
		}
	}
	if (PosUpdateCheck == TRUE)
	{
		PointListIndex = NearBusyPointSearch(TempPointPos);
		if (PointListIndex != RET_NOT_OK)
		{
			Pointlist[PointListIndex].SetPosition(TempPointPos);
			RoomMap.MergePointsOnMap(newPointPos,TempPointPos);
		}
	}
	return PosUpdateCheck;
}
#endif

#ifdef UPDATE_POINT_POSITION
/*searchs near the busy point detected to update it*/
static uint8 NearBusyPointSearch(PointPos TempPointPos)
{
	uint8 result = RET_NOT_OK;

	for (uint8 PointListIndex = 0; PointListIndex < POINT_LIST_SIZE; PointListIndex++)
	{
		if ((Pointlist[PointListIndex].getPointPos().X_Column == TempPointPos.X_Column) &&
			(Pointlist[PointListIndex].getPointPos().Y_Row == TempPointPos.Y_Row))
		{
			result = PointListIndex;
		}
	}
	return result;
}
#endif

#if 0
/*work around for interrupt hardware debouncing*/
void debounceInterrupt() {
	if ((long)(micros() - last_micros) >= DEBOUNCING_TIME * MILLISECOND_SCALE) {
		ISR_BumperHit();
		last_micros = micros();
	}
}
#endif

void ISR_BumperHit(void)
{
  #ifdef DEBUG
  Serial.println("interrupt hit");
  #endif

	BumperHit = TRUE;
	

#ifndef ENABLE_SIMULATION
	/*Stop Robot*/
	MOVE::MoveStop(cleaner);

#endif
}

#ifdef ENCODER_ON_INTERRUPT
void ISR_left_Encoder_tick()
{
	left_encoder::L_encoder();
}
#endif

#ifdef GO_TO_GOAL_STRAIGHTLINES

/*Goes to empty blocks left on the map to finish up the cleaning*/
static void GoToGoal_Empty(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
{

	Coordinates Empty_Position_Goal;
	uint16 Requested_Angle; 
	uint16 TempRequested_Angle = INVALID_ANGLE_VALUE;
	SensorsReadings LeftRightScan;
	RobotPos RobotPosition = cleaner.GetRobotPosition();
	Robot_to_Goal  Goal_Relative_to_Robot;

	if (GoToGoal_Empty_Flag == TRUE)
	{

		Empty_Position_Goal = RoomMap.ScanEmptyArea(cleaner);

		if ((Empty_Position_Goal.Y_Row == 0) && (Empty_Position_Goal.X_Column == 0))
		{
			GO_BACK_TO_CHARGER = TRUE;
		}
		else
		{
			/*TODO: flag so scaning of empty area is done once*/
		}
		
		if (BumperHit)
		{
			LeftRightScan = BumperHitSensorsView(cleaner, RoomMap, *RobHeadingReq);

			switch (LeftRightScan)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
				if (RobHeadingReq == EAST)
				break;
			case LEFT_CLEANED_RIGHT_EMPTY:
			case LEFT_BUSY_RIGHT_EMPTY:
				break;
			case LEFT_EMPTY_RIGHT_CLEANED:
			case LEFT_EMPTY_RIGHT_BUSY:
				break;
			case LEFT_BUSY_RIGHT_BUSY:
			case LEFT_BUSY_RIGHT_CLEANED:
			case LEFT_CLEANED_RIGHT_BUSY:
			case LEFT_CLEANED_RIGHT_CLEANED:
				break;
			default:
				break;
			}
		}

		if (No_Obstical_flag == TRUE)
		{
			Goal_Relative_to_Robot = Goal_FromRobot_UpdateReq(RobotPosition, Empty_Position_Goal, RobHeadingReq, &Requested_Angle);

			if (TempRequested_Angle != Requested_Angle)
			{
				MOVE::MoveTurn_CCW(cleaner, Requested_Angle);
				TempRequested_Angle = Requested_Angle;
			}

			MOVE::MoveForward(cleaner, cleaner.GetRobotHeading());
		}
	}
}


Robot_to_Goal Goal_FromRobot_UpdateReq(RobotPos RobotPosition, Coordinates Empty_Position_Goal, enu_Direction_req* RobHeadingReq, uint16* Requested_Angle)
{
	Robot_to_Goal  Goal_Relative_to_Robot;

	if ((RobotPosition.X_pos < Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos < Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_LES_X_GOAL_Y_ROBOT_LES_Y_GOAL;
		*RobHeadingReq = REQUEST_EAST;
		*Requested_Angle = EAST_VALUE;
	}
	else if ((RobotPosition.X_pos > Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos > Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_GR_X_GOAL_Y_ROBOT_GR_Y_GOAL;
		*RobHeadingReq = REQUEST_WEST;
		*Requested_Angle = WEST_VALUE;
	}
	else if ((RobotPosition.X_pos > Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos < Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_GR_X_GOAL_Y_ROBOT_LES_Y_GOAL;
		*RobHeadingReq = REQUEST_WEST;
		*Requested_Angle = WEST_VALUE;
	}
	else if ((RobotPosition.X_pos < Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos > Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_LES_X_GOAL_Y_ROBOT_GR_Y_GOAL;
		*RobHeadingReq = REQUEST_EAST;
		*Requested_Angle = EAST_VALUE;
	}
	else if ((RobotPosition.X_pos == Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos < Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_EQ_X_GOAL_Y_ROBOT_LES_Y_GOAL;
		*RobHeadingReq = REQUEST_SOUTH;
		*Requested_Angle = SOUTH_VALUE;
	}
	else if ((RobotPosition.X_pos == Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos > Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_EQ_X_GOAL_Y_ROBOT_GR_Y_GOAL;
		*RobHeadingReq = REQUEST_NORTH;
		*Requested_Angle = NORTH_VALUE;
	}
	else if ((RobotPosition.X_pos < Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos == Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_LES_X_GOAL_Y_ROBOT_EQ_Y_GOAL;
		*RobHeadingReq = REQUEST_EAST;
		*Requested_Angle = EAST_VALUE;
	}
	else if ((RobotPosition.X_pos > Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos == Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_GR_X_GOAL_Y_ROBOT_EQ_Y_GOAL;
		*RobHeadingReq = REQUEST_WEST;
		*Requested_Angle = WEST_VALUE;
	}
	else if ((RobotPosition.X_pos == Empty_Position_Goal.X_Column) && (RobotPosition.Y_pos == Empty_Position_Goal.Y_Row))
	{
		Goal_Relative_to_Robot = X_ROBOT_EQ_X_GOAL_Y_ROBOT_EQ_Y_GOAL;
		ZigZagFlag = TRUE;
		GoToGoal_Empty_Flag = FALSE;
	}
	return Goal_Relative_to_Robot;
}
#endif


static void FinishUpLeftEmpty(Robot& cleaner, Map& RoomMap, enu_Direction_req* Direction_req)
{

}

#ifdef DEBUG
static void Map_Print(Map map)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			Serial.print((int)map.ReadPointFromMap(i,j));
		}
		Serial.println();
	}
	Serial.println();
}
#endif
