#include "Robot.h"
#include "MapHandler.h"
#include "SIMU.h"
#include "Scan.h"
#include "OBJD.h"
#include "ULSH.h"
#include "MOVH.h"


#ifdef ENABLE_SIMULATION
#include <iostream>
using namespace std;
#endif

/*global variable declaration*/
Point Pointlist[POINT_LIST_SIZE];
static Boolean BumperHit;

/*static functions declaration*/
static Boolean CheckPointUpdatePos(PointPos TempPointPos, Heading heading, Map& RoomMap);
static uint8 NearBusyPointSearch(PointPos TempPointPos);
static void ISR_BumperHit(enu_Direction_req Request);


void main()
{
	/*=============================Intialize project==============================*/

	/*------------------Map Init Data-------------------*/
	Map RoomMap;
	RoomMap.initMap();

	/*----------------Scan Init Data--------------------*/
	Scan scan = Scan::getInstanceScan();

	/*-----------------Point Init Data -----------------*/
	PointPos LeftTempPointPos;
	PointPos RightTempPointPos;
	uint8 PointListIndex = 0;

	/*----------------Robot Init Data------------------*/
	RobotPos RobTempPosition;
	Heading RobTempHeading;
	RobTempPosition.theta = ROBOT_INIT_THETA;
	RobTempPosition.X_pos = ROBOT_INIT_X;
	RobTempPosition.Y_pos = ROBOT_INIT_Y;
	Robot cleaner = Robot::initRobotPosition(RobTempPosition);

	/*----------------Error Init Data-----------------*/
	return_type Error_Check = RET_NOT_OK;
	Boolean UpdatePointCheck;

	/*----------------Move Init Data-------------------*/
	enu_Direction_req DirectionReq = REQUEST_NONE;
	uint8 CompassRawReading;
#ifdef RECTANGLE
	L_R_Dist diagonalList[FULL_SCAN_NUM];
	RectSize rectsize;
	return_type Error_Check;
#endif



	/*-----------start implementing------------*/

	RobTempPosition = cleaner.GetRobotPosition();
	RoomMap.addRobotOnMap(RobTempPosition);
#ifdef RECTANGLE
	Error_Check = Rectangle::ConstructRect(diagonalList, &rectsize, cleaner, &robPosInRect);
	Rectangle rect1(rectsize);
#ifdef DEBUG
	Coordinates position;
	position.X_Column = 2;
	position.Y_Row = 3;
	rect1.UpdateRectangle(position,BUSY);
#endif
	rect1.getRectSize(&rectsize);

	if (Error_Check == RET_OK)
	{
#endif
#ifdef RECTANGLE
		RoomMap.AddRectangle(rect1, &RobTempPosition);
	}
#endif
	DirectionReq = REQUEST_NORTH;
while (1)
{
	RobTempHeading = cleaner.GetRobotHeading();
	if (BumperHit)
	{
		/*TODO: fix the turn to the requested direction after a hit*/
		RobTempPosition = cleaner.GetRobotPosition();
		if (DirectionReq == REQUEST_NORTH)
		{
			if (RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			{
				/*turn right*/
			}
			else if (RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY)
			{
				/*turn left*/
			}
		}
		else if (DirectionReq == REQUEST_SOUTH)
		{
			if (RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY)
			{
				/*turn left*/
			}
			else if (RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY)
			{
				/*turn right*/
			}
		}
		
	}
	
	/*check the ID of the point before creating new ones*/
	Error_Check = scan.LinearScan(&LeftTempPointPos, &RightTempPointPos, cleaner, RobTempHeading);
	if (Error_Check == RET_OK)
	{

		if ((RoomMap.room[LeftTempPointPos.Y_Row][LeftTempPointPos.X_Column] != BUSY) && (RoomMap.room[LeftTempPointPos.Y_Row][LeftTempPointPos.X_Column] != ROBOT))
		{
			UpdatePointCheck = CheckPointUpdatePos(LeftTempPointPos, RobTempHeading, RoomMap);
			if (UpdatePointCheck == FALSE)
			{
				Pointlist[PointListIndex].setPointPos(LeftTempPointPos);
				RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobTempHeading);
				PointListIndex++;
			}
		}
		else
		{
			/*Do nothing*/

		}

		if ((RoomMap.room[RightTempPointPos.Y_Row][RightTempPointPos.X_Column] != BUSY) && (RoomMap.room[RightTempPointPos.Y_Row][RightTempPointPos.X_Column] != ROBOT))
		{
			UpdatePointCheck = CheckPointUpdatePos(RightTempPointPos, RobTempHeading, RoomMap);
			if (UpdatePointCheck == FALSE)
			{
				Pointlist[PointListIndex].setPointPos(RightTempPointPos);
				RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobTempHeading);
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
		/*TODO: Fix the heading of the robot if its not ok*/

		CompassRawReading = Comp::ReadRawData();

		switch (DirectionReq)
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

	(void)MOVE::MoveForward(cleaner);
	RoomMap.UpdateRobotPosition(cleaner);
#ifdef ENABLE_SIMULATION
	simu sim;
	sim.printMap(RoomMap);
#endif

}
	system("pause");
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
		Pointlist[PointListIndex].setPointPos(TempPointPos);
		RoomMap.MergePointsOnMap(newPointPos, TempPointPos);
	}
	return PosUpdateCheck;
}

static uint8 NearBusyPointSearch(PointPos TempPointPos)
{
	for (uint8 PointListIndex = 0; PointListIndex < POINT_LIST_SIZE; PointListIndex++)
	{
		if ((Pointlist[PointListIndex].getPointPos().X_Column == TempPointPos.X_Column) &&
			(Pointlist[PointListIndex].getPointPos().Y_Row == TempPointPos.Y_Row))
		{
			return PointListIndex;
		}
	}
}

static void ISR_BumperHit(enu_Direction_req Request)
{
	BumperHit = TRUE;
}
