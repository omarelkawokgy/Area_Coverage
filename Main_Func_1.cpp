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
static Boolean ZigZagFlag = FALSE;
static Boolean BumperHit = FALSE;

/*static functions declaration*/
static Boolean CheckPointUpdatePos(PointPos TempPointPos, Heading heading, Map& RoomMap);
static uint8 NearBusyPointSearch(PointPos TempPointPos);
static void fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq);
static void ZigZagRoutine(Robot& cleaner, Map& RoomMap);
static SensorsReadings BumperHitSensorsView(Robot& rob, Map& RoomMap, enu_Direction_req RobHeadingReq);
static enu_Direction_req GoToStartPoint(Robot& cleaner, Map& RoomMap);

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

	/*go to extreme left of map to scan room*/
	GoToStartPoint(cleaner, RoomMap);

	ZigZagRoutine(cleaner, RoomMap);

	/*TODO: check the right side of the Map to cover it all*/


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
		Pointlist[PointListIndex].SetPosition(TempPointPos);
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
	uint8 interrupt;
	Boolean UturnFlag = FALSE;

	RobHeadingReq = REQUEST_NORTH;
	SensorsReadings readingSensorsView;
	while (ZigZagFlag)
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
			
			/*TODO: fix the turn to the requested direction after a hit*/
			RobTempPosition = cleaner.GetRobotPosition();
			readingSensorsView = BumperHitSensorsView(cleaner, RoomMap, RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
				UturnFlag = FALSE;
				if (REQUEST_NORTH == RobHeadingReq)
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == RobHeadingReq)
				{
					/*uturn left*/
					RobHeadingReq = REQUEST_NORTH;
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
				if (REQUEST_NORTH == RobHeadingReq)
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnRight(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == RobHeadingReq)
				{
					/*uturn left*/
					RobHeadingReq = REQUEST_NORTH;
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
				if (REQUEST_NORTH == RobHeadingReq)
				{
					/*uturn left*/
					RobHeadingReq = REQUEST_SOUTH;
					MOVE::UTurnLeft(cleaner, RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == RobHeadingReq)
				{
					/*uturn right*/
					RobHeadingReq = REQUEST_NORTH;
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
				if (REQUEST_NORTH == RobHeadingReq)
				{
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == RobHeadingReq)
				{
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos);
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
				/*TODO: Fix the heading of the robot if its not ok*/
				fixRobotHeading(cleaner, RobHeadingReq);
			}

			RoomMap.UpdateRobotPosition(cleaner);
		}
		
#ifdef ENABLE_SIMULATION
		simu sim;
		sim.printMap(RoomMap);
#endif
		
	}

}

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
			FAILURE_READING;
		}

	}
	return reading;
}

enu_Direction_req GoToStartPoint(Robot& cleaner, Map& RoomMap)
{
	uint8 interrupt = FALSE;
	Boolean ToStartPoint = TRUE;
	SensorsReadings readingSensorsView = FAILURE_READING;
	enu_Direction_req RobHeadingReq = REQUEST_NORTH;
	Heading heading;

	while (ToStartPoint)
	{
		heading = cleaner.GetRobotHeading();
		MOVE::MoveForward(cleaner, heading);
#ifdef ENABLE_SIMULATION
		cout << "if Interrupt press '5'?" << endl;
		cin >> interrupt;
		if (interrupt == '5')
		{
			ISR_BumperHit();
		}
#endif
		if (BumperHit == TRUE)
		{
			readingSensorsView = BumperHitSensorsView(cleaner, RoomMap, RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
			case LEFT_EMPTY_RIGHT_CLEANED:
			case LEFT_EMPTY_RIGHT_BUSY:
				if (REQUEST_NORTH == RobHeadingReq)
				{
					/*turn Left*/
					MOVE::MoveTurn_CCW(cleaner, WEST_VALUE);
					RobHeadingReq = REQUEST_WEST;
				}
				else if (REQUEST_WEST == RobHeadingReq)
				{
					/**/
					MOVE::MoveTurn_CCW(cleaner, SOUTH_VALUE);
					RobHeadingReq = REQUEST_SOUTH;
					ToStartPoint = FALSE;
				}
				else
				{
					/*do nothing*/
				}
				break;
			case LEFT_CLEANED_RIGHT_EMPTY:
			case LEFT_BUSY_RIGHT_EMPTY:
			case LEFT_BUSY_RIGHT_BUSY:
			case LEFT_BUSY_RIGHT_CLEANED:
			case LEFT_CLEANED_RIGHT_BUSY:
			case LEFT_CLEANED_RIGHT_CLEANED:
				ToStartPoint = FALSE;
				break;
			default:
				break;
			}
		}
		else
		{

		}
	}
	return RobHeadingReq;
}
