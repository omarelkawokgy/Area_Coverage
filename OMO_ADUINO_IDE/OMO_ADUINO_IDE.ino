
#include "Robot.h"
#include "MapHandler.h"
#include "Scan.h"
#include "OBJD.h"
#include "ULSH.h"
#include "MOVH.h"
#include "ENCOD.h"



#ifdef ENABLE_SIMULATION
#include "SIMU.h"
#include <iostream>
using namespace std;
#endif

/*global variable declaration*/
Point Pointlist[POINT_LIST_SIZE];
Map RoomMap;
static uint8 PointListIndex = 0;
static Boolean ZigZagFlag = FALSE;
static volatile Boolean BumperHit = FALSE;
Boolean ToStartPoint = TRUE;
enu_Direction_req Direction_req = REQUEST_NORTH;
Robot cleaner = Robot::initRobotPosition();

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
static void fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq);
static void ZigZagRoutine(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq);
static void GoToStartPoint(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq);
static SensorsReadings BumperHitSensorsView(Robot& rob, Map& RoomMap, enu_Direction_req RobHeadingReq);
static void ISR_left_Encoder_tick(void);
static void ISR_BumperHit(void);
#ifdef FINISHUP_EMPTY_SLOTS
#ifdef GO_TO_GOAL_STRAIGHTLINES
static void GoToGoal_Empty(Robot& cleaner, Map& RoomMap);
#endif
static void FinishUpLeftEmpty(Robot& cleaner, Map& RoomMap, enu_Direction_req* Direction_req);
#endif


void setup()
{
	/*=============================Intialize project==============================*/

	/*pin 0 in interrupt is pin 2 in arduino*/
	attachInterrupt(FRONT_SENSOR_PIN, ISR_BumperHit, RISING);
	attachInterrupt(ENCODER_PIN, ISR_left_Encoder_tick, RISING);
	/*------------------Map Init Data-------------------*/
	
	RoomMap.initMap();

	/*----------------Robot Init Data------------------*/
	RobotPos RobTempPosition = cleaner.GetRobotPosition();

	/*----------------------INIT--------------------*/
	
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
		GoToStartPoint(cleaner, RoomMap, &Direction_req);

		ZigZagRoutine(cleaner, RoomMap, &Direction_req);

#ifdef FINISHUP_EMPTY_SLOTS
#ifdef GO_TO_GOAL_STRAIGHTLINES
		GoToGoal_Empty(cleaner, RoomMap);
#endif
		FinishUpLeftEmpty(cleaner, RoomMap, &Direction_req);
#endif
#ifdef ENABLE_SIMULATION
		sim.printMap(RoomMap);
#endif


	/*TODO: check the right side of the Map to cover it all*/

	//system("pause");
	return;
}

static Boolean CheckPointUpdatePos(PointPos newPointPos, Heading heading, Map& RoomMap)
{
	uint8 PointListIndex;
	Boolean PosUpdateCheck = FALSE;
	PointPos TempPointPos = newPointPos;
	if ((heading == NORTH) || (heading == SOUTH))
	{
		if (RoomMap.room[TempPointPos.Y_Row][TempPointPos.X_Column - 1] == BUSY)
		{
			TempPointPos.X_Column = TempPointPos.X_Column - 1;
			PosUpdateCheck = TRUE;
		}
		else if (RoomMap.room[TempPointPos.Y_Row][TempPointPos.X_Column + 1] == BUSY)
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
		if (RoomMap.room[TempPointPos.Y_Row - 1][TempPointPos.X_Column] == BUSY)
		{
			TempPointPos.Y_Row = TempPointPos.Y_Row - 1;
			PosUpdateCheck = TRUE;
		}
		else if (RoomMap.room[TempPointPos.Y_Row + 1][TempPointPos.X_Column] == BUSY)
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

void ISR_BumperHit(void)
{
	BumperHit = TRUE;
#ifndef ENABLE_SIMULATION
	/*Stop Robot*/
	MOVE::MoveStop(cleaner);
#endif
}

void ISR_left_Encoder_tick()
{
	left_encoder::L_encoder();
}

static void fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq)
{
	uint16 CompassRawReading = Comp::ReadRawData();
	switch (RobHeadingReq)
	{
	case REQUEST_NORTH:
		if (CompassRawReading < SOUTH_VALUE)
		{
			MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
		}
		else
		{
			MOVE::MoveTurn_CCW(cleaner, NORTH_VALUE);
		}
		break;
	case REQUEST_WEST:
		if (CompassRawReading < EAST_VALUE)
		{
			MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
		}
		else
		{
			MOVE::MoveTurn_CCW(cleaner, WEST_VALUE);
		}
		break;
	case REQUEST_SOUTH:
		if (CompassRawReading < NORTH_VALUE)
		{
			MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
		}
		else
		{
			MOVE::MoveTurn_CCW(cleaner, SOUTH_VALUE);
		}
		break;
	case REQUEST_EAST:
		if (CompassRawReading < WEST_VALUE)
		{
			MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		}
		else
		{
			MOVE::MoveTurn_CCW(cleaner, EAST_VALUE);
		}
		break;
	default:
		break;
	}
}

static void ZigZagRoutine(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
{
	/*------------------Robot Init---------------------*/
	Heading RobCurrentHeading;
	RobotPos RobTempPosition;

	/*----------------Error Init Data-----------------*/
	return_type Error_Check = RET_NOT_OK;
	Boolean UpdatePointCheck;

	/*----------------Scan Init Data--------------------*/
	Scan scan = Scan::getInstanceScan();

	/*-----------------Point Init Data -----------------*/
	PointPos LeftTempPointPos;
	PointPos RightTempPointPos;
	uint8 interrupt;
	Boolean UturnFlag = FALSE;

	SensorsReadings readingSensorsView;
	if(ZigZagFlag)
	{
		RobCurrentHeading = cleaner.GetRobotHeading();
		(void)MOVE::MoveForward(cleaner, RobCurrentHeading);
#ifdef ENABLE_SIMULATION
		cout << "if Interrupt press '5'?" << endl;
		cin >> interrupt;
		if (interrupt == '5')
		{
			ISR_BumperHit();
		}
#endif
		/*triggers from ISR*/
		if (BumperHit == TRUE)
		{
			(void)MOVE::MoveStop(cleaner);
			(void)MOVE::MoveBackward(cleaner, RobCurrentHeading);
			
			RobTempPosition = cleaner.GetRobotPosition();
			readingSensorsView = BumperHitSensorsView(cleaner, RoomMap, *RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
				UturnFlag = FALSE;
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn right*/
					*RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					MOVE::UTurnLeft(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos);
				}
				else
				{
					/*do nothing*/
				}
				break;
			case LEFT_CLEANED_RIGHT_EMPTY:
			case LEFT_BUSY_RIGHT_EMPTY:
				UturnFlag = FALSE;
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn right*/
					*RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					MOVE::UTurn(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos);
				}
				else
				{
					/*do nothing*/
				}
				break;
			case LEFT_EMPTY_RIGHT_CLEANED:
			case LEFT_EMPTY_RIGHT_BUSY:
				UturnFlag = FALSE;
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnLeft(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					MOVE::UTurnLeft(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos);
				}
				else
				{
					/*do nothing*/
				}
				break;
			case LEFT_BUSY_RIGHT_BUSY:
			case LEFT_BUSY_RIGHT_CLEANED:
			case LEFT_CLEANED_RIGHT_BUSY:
			case LEFT_CLEANED_RIGHT_CLEANED:
				/*uturn*/
				if (UturnFlag == TRUE)
				{
					ZigZagFlag = FALSE;
				}
				UturnFlag = TRUE;
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
					*RobHeadingReq = REQUEST_SOUTH;
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos);
					*RobHeadingReq = REQUEST_NORTH;
				}
				MOVE::UTurn(cleaner, RobCurrentHeading);
				break;
			default:
				break;
			}
			BumperHit = FALSE;
			//RobCurrentHeading = cleaner.GetRobotHeading();
			RoomMap.UpdateRobotPosition(cleaner);
		}
		else
		{ 

			/*check the ID of the point before creating new ones*/
			Error_Check = scan.LinearScan(&LeftTempPointPos, &RightTempPointPos, cleaner, RobCurrentHeading);
			if (Error_Check == RET_OK)
			{

				if ((RoomMap.room[LeftTempPointPos.Y_Row][LeftTempPointPos.X_Column] != BUSY) &&
					(RoomMap.room[LeftTempPointPos.Y_Row][LeftTempPointPos.X_Column] != ROBOT))
				{
					UpdatePointCheck = CheckPointUpdatePos(LeftTempPointPos, RobCurrentHeading, RoomMap);
					if (UpdatePointCheck == FALSE)
					{
						Pointlist[PointListIndex].SetPosition(LeftTempPointPos);
						RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobCurrentHeading);
						PointListIndex++;
					}
				}
				else
				{
					/*Do nothing*/

				}

				if ((RoomMap.room[RightTempPointPos.Y_Row][RightTempPointPos.X_Column] != BUSY) &&
					(RoomMap.room[RightTempPointPos.Y_Row][RightTempPointPos.X_Column] != ROBOT))
				{
					UpdatePointCheck = CheckPointUpdatePos(RightTempPointPos, RobCurrentHeading, RoomMap);
					if (UpdatePointCheck == FALSE)
					{
						Pointlist[PointListIndex].SetPosition(RightTempPointPos);
						RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobCurrentHeading);
						PointListIndex++;
					}
				}
				else
				{
					/*Do nothing*/
				}
			}
			else
			{
				fixRobotHeading(cleaner, *RobHeadingReq);
			}

			RoomMap.UpdateRobotPosition(cleaner);
		}
	}

}

/*Bumper hit sensor view tell me when i hit an object the left and right situations on the map*/
static SensorsReadings BumperHitSensorsView(Robot& rob, Map& RoomMap, enu_Direction_req RobHeadingReq)
{
	SensorsReadings reading;
	RobotPos RobTempPosition = rob.GetRobotPosition();


	if (RobHeadingReq == REQUEST_NORTH)
	{
		if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY) &&

			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED))
			&&
			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
		}
	}
	else if (RobHeadingReq == REQUEST_SOUTH)
	{
		if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)

			&&
			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED))
			&&
			((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
		}

	}
	else if (RobHeadingReq == REQUEST_WEST)
	{
		if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
		}
	}
	else if (RobHeadingReq == REQUEST_EAST)
	{
		if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == UNCOVERED))
			&&
			((RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == EMPTY)
			||
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == BUSY)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == CLEANED))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else if ((RoomMap.room[RobTempPosition.Y_pos - 1][RobTempPosition.X_pos] == CLEANED)
			&&
			(RoomMap.room[RobTempPosition.Y_pos + 1][RobTempPosition.X_pos] == BUSY))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
		}
	}
	else
	{
		/*invalid direction*/
		reading = FAILURE_READING;
	}
	return reading;
}

static void GoToStartPoint(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
{
	uint8 interrupt = FALSE;
	SensorsReadings readingSensorsView = FAILURE_READING;
	Heading heading = INVALID_DIRECTION;

	if(ToStartPoint)
	{
		heading = cleaner.GetRobotHeading();
		MOVE::MoveForward(cleaner, heading);
#ifdef ENABLE_SIMULATION
		cout << "To Start Point if Interrupt press '5'?" << endl;
		cin >> interrupt;
		if (interrupt == '5')
		{
			ISR_BumperHit();
		}
#endif
		if (BumperHit == TRUE)
		{
			(void)MOVE::MoveStop(cleaner);
			(void)MOVE::MoveBackward(cleaner, heading);
			readingSensorsView = BumperHitSensorsView(cleaner, RoomMap, *RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
			case LEFT_EMPTY_RIGHT_CLEANED:
			case LEFT_EMPTY_RIGHT_BUSY:
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*turn Left*/
					MOVE::MoveTurn_CCW(cleaner, WEST_VALUE);
					*RobHeadingReq = REQUEST_WEST;
#ifdef ENABLE_SIMULATION
					cout << "in to start point Request_WEST" << endl;
#endif
				}
				else if (REQUEST_WEST == *RobHeadingReq)
				{
					/*start point reached*/
					MOVE::MoveTurn_CCW(cleaner, SOUTH_VALUE);
					*RobHeadingReq = REQUEST_SOUTH;
					ToStartPoint = FALSE;
					ZigZagFlag = TRUE;
#ifdef ENABLE_SIMULATION
					cout << "Start Point reached: Request_SOUTH" << endl;
#endif
				}
				else
				{
					/*do nothing*/
				}
				break;
			case LEFT_CLEANED_RIGHT_EMPTY:
			case LEFT_BUSY_RIGHT_EMPTY:
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn start point reached*/
					MOVE::UTurn(cleaner, heading);
					*RobHeadingReq = REQUEST_SOUTH;
					ToStartPoint = FALSE;
					ZigZagFlag = TRUE;
#ifdef ENABLE_SIMULATION
					cout << "Start Point reached: Request_SOUTH" << endl;
#endif
				}
				else if (REQUEST_WEST == *RobHeadingReq)
				{
					/*Start point reached*/
					MOVE::MoveTurn_CCW(cleaner, NORTH_VALUE);
					*RobHeadingReq = REQUEST_NORTH;
					ToStartPoint = FALSE;
					ZigZagFlag = TRUE;
#ifdef ENABLE_SIMULATION
					cout << "Start Point reached: Request_NORTH" << endl;
#endif
				}
				else
				{
					/*do nothing*/
				}
			case LEFT_BUSY_RIGHT_BUSY:
			case LEFT_BUSY_RIGHT_CLEANED:
			case LEFT_CLEANED_RIGHT_BUSY:
			case LEFT_CLEANED_RIGHT_CLEANED:
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn start point reached*/
					MOVE::UTurn(cleaner, heading);
					*RobHeadingReq = REQUEST_SOUTH;
					ToStartPoint = FALSE;
					ZigZagFlag = TRUE;
#ifdef ENABLE_SIMULATION
					cout << "Start Point reached: Request_SOUTH" << endl;
#endif
				}
				else if (REQUEST_WEST == *RobHeadingReq)
				{
					/*search for start point*/
					ToStartPoint = FALSE;
					ZigZagFlag = TRUE;
				}
				else
				{
					/*do nothing*/
				}
				ToStartPoint = FALSE;
				break;
			default:
				break;
			}
		}
		else
		{

		}
		RoomMap.UpdateRobotPosition(cleaner);
		BumperHit = FALSE;
	}
}

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

