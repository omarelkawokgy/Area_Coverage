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
static uint8 PointListIndex = 0;
static Boolean BumperHit;
static Boolean ZigZagFlag = FALSE;

/*static functions declaration*/
static Boolean CheckPointUpdatePos(PointPos TempPointPos, Heading heading, Map& RoomMap);
static uint8 NearBusyPointSearch(PointPos TempPointPos);
static void UTurnLeft(Robot& cleaner, Heading RobCurrentHeading);
static void UTurnRight(Robot& cleaner, Heading RobCurrentHeading);
static void fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq);
static void ZigZagRoutine(Robot& cleaner, Map& RoomMap);
void ISR_BumperHit(void);

void main()
{
	/*=============================Intialize project==============================*/

	/*------------------Map Init Data-------------------*/
	Map RoomMap;
	RoomMap.initMap();

	/*----------------Robot Init Data------------------*/
	Robot cleaner = Robot::initRobotPosition();
	RobotPos RobTempPosition = cleaner.GetRobotPosition();

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
	
	ZigZagFlag = TRUE;

	ZigZagRoutine(cleaner, RoomMap);


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
	/*TODO: handle error if index not found*/
}

void ISR_BumperHit(void)
{
	BumperHit = TRUE;
	/*Stop Robot*/
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

static void UTurnRight(Robot& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		RobCurrentHeading = EAST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
		RobCurrentHeading = NORTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
		RobCurrentHeading = WEST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
		RobCurrentHeading = SOUTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		break;
	}
}

static void UTurnLeft(Robot& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
		RobCurrentHeading = WEST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
		RobCurrentHeading = SOUTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		RobCurrentHeading = EAST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
		RobCurrentHeading = NORTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		break;
	}
}

static void ZigZagRoutine(Robot& cleaner, Map& RoomMap)
{
	/*------------------Robot Init---------------------*/
	Heading RobCurrentHeading;
	RobotPos RobTempPosition;

	/*----------------Error Init Data-----------------*/
	return_type Error_Check = RET_NOT_OK;
	Boolean UpdatePointCheck;

	/*----------------Move Init Data-------------------*/
	enu_Direction_req RobHeadingReq = REQUEST_NONE;

	/*----------------Scan Init Data--------------------*/
	Scan scan = Scan::getInstanceScan();

	/*-----------------Point Init Data -----------------*/
	PointPos LeftTempPointPos;
	PointPos RightTempPointPos;

	RobHeadingReq = REQUEST_NORTH;

	while (ZigZagFlag)
	{
		RobCurrentHeading = cleaner.GetRobotHeading();

		/*triggers from ISR*/
		if (BumperHit)
		{
			/*TODO: fix the turn to the requested direction after a hit*/
			RobTempPosition = cleaner.GetRobotPosition();

			if (RobHeadingReq == REQUEST_NORTH)
			{
				if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED))
					&&
					((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)))
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_SOUTH;
					UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos] = CLEANED;
				}
				else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == BUSY) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == CLEANED))
					&&
					((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == EMPTY)))
				{
					/*uturn left*/
					RobHeadingReq = REQUEST_SOUTH;
					UTurnLeft(cleaner, RobCurrentHeading);
					RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos] = CLEANED;

				}
				else if ((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == UNCOVERED)
					&&
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED))
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_SOUTH;
					UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos] = CLEANED;
				}
				else
				{

				}
			}
			else if (RobHeadingReq == REQUEST_SOUTH)
			{
				if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED))
					&&
					((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)))
				{
					/*uturn left*/
					RobHeadingReq = REQUEST_NORTH;
					UTurnLeft(cleaner, RobCurrentHeading);

				}
				else if (((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == BUSY) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos - 1] == CLEANED))
					&&
					((RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == UNCOVERED) ||
					(RoomMap.room[RobTempPosition.Y_pos][RobTempPosition.X_pos + 1] == EMPTY)))
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_NORTH;
					UTurnRight(cleaner, RobCurrentHeading);

				}
				else
				{
					/*stop robot*/
				}
			}
			BumperHit = FALSE;
			RobCurrentHeading = cleaner.GetRobotHeading();
		}

		/*TODO: function to check that request is consistant with the heading*/
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
					Pointlist[PointListIndex].setPointPos(LeftTempPointPos);
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
					Pointlist[PointListIndex].setPointPos(RightTempPointPos);
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
			/*TODO: Fix the heading of the robot if its not ok*/
			fixRobotHeading(cleaner, RobHeadingReq);
		}

		(void)MOVE::MoveForward(cleaner, RobCurrentHeading);
		RoomMap.UpdateRobotPosition(cleaner);
#ifdef ENABLE_SIMULATION
		simu sim;
		sim.printMap(RoomMap);
#endif
	}

}
