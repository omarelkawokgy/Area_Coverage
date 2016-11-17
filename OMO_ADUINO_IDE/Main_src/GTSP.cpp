#include "Project_Path.h"
#include RELATIVE_PATH(GTSP.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(COMH.h)
#undef PROJECT_PATH_H

void GTSP::GoToStartPoint(RobotDevice& theCleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
{
	uint8 interrupt = FALSE;
	SensorsReadings readingSensorsView = FAILURE_READING;
	Heading heading = INVALID_DIRECTION;
	if (ToStartPoint == TRUE)
	{
		heading = theCleaner.GetRobotHeading();
		theCleaner.getTheMove().MoveForward(heading);

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
			(void)theCleaner.getTheMove().MoveStop();
			(void)theCleaner.getTheMove().MoveBackward(heading);
			BumperHit = FALSE;
			readingSensorsView = BumperHitSensorsView(theCleaner.getPosition(), RoomMap, *RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
			case LEFT_EMPTY_RIGHT_CLEANED:
			case LEFT_EMPTY_RIGHT_BUSY:
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*turn Left*/
					theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), WEST_VALUE);
					*RobHeadingReq = REQUEST_WEST;
#ifdef ENABLE_SIMULATION
					cout << "in to start point Request_WEST" << endl;
#endif
				}
				else if (REQUEST_WEST == *RobHeadingReq)
				{
					/*start point reached*/
					theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), SOUTH_VALUE);
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
					theCleaner.getTheMove().UTurn(theCleaner.getPosition(), heading);
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
					theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), NORTH_VALUE);
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
				break;
			case LEFT_BUSY_RIGHT_BUSY:
			case LEFT_BUSY_RIGHT_CLEANED:
			case LEFT_CLEANED_RIGHT_BUSY:
			case LEFT_CLEANED_RIGHT_CLEANED:
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn start point reached*/
					theCleaner.getTheMove().UTurn(theCleaner.getPosition(), heading);
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
				ERRH::Error_logErrorClass(ERROR_GTSP_DEFAULT_CASE);
				break;
			}
		}
		else
		{

		}
		RoomMap.UpdateRobotPosition(theCleaner.getPosition());
	}
}

/*Bumper hit sensor view tell me when i hit an object the left and right situations on the map*/
SensorsReadings GTSP::BumperHitSensorsView(positionHeadingHandler& rob, Map& RoomMap, enu_Direction_req RobHeadingReq)
{
	SensorsReadings reading;
	RobotPos RobTempPosition = rob.GetRobotPosition();


	if (RobHeadingReq == REQUEST_NORTH)
	{
		if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY) &&

			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == UNCOVERED))
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
			ERRH::Error_logErrorClass(ERROR_GTSP_READ_SENSORS_NORTH_VIEW_FAIL);
		}
	}
	else if (RobHeadingReq == REQUEST_SOUTH)
	{
		if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY)

			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == UNCOVERED))
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos - 1) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos, RobTempPosition.X_pos + 1) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
			ERRH::Error_logErrorClass(ERROR_GTSP_READ_SENSORS_SOUTH_VIEW_FAIL);
		}

	}
	else if (RobHeadingReq == REQUEST_WEST)
	{
		if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
			ERRH::Error_logErrorClass(ERROR_GTSP_READ_SENSORS_WEST_VIEW_FAIL);
		}
	}
	else if (RobHeadingReq == REQUEST_EAST)
	{
		if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_BUSY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_CLEANED_RIGHT_EMPTY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_EMPTY_RIGHT_BUSY;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_EMPTY_RIGHT_CLEANED;
		}
		else if (((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == UNCOVERED))
			&&
			((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == EMPTY)
			||
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == UNCOVERED)))
		{
			reading = LEFT_EMPTY_RIGHT_EMPTY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_BUSY_RIGHT_BUSY;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_CLEANED_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == BUSY)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == CLEANED))
		{
			reading = LEFT_BUSY_RIGHT_CLEANED;
		}
		else if ((RoomMap.ReadPointFromMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos) == CLEANED)
			&&
			(RoomMap.ReadPointFromMap(RobTempPosition.Y_pos + 1, RobTempPosition.X_pos) == BUSY))
		{
			reading = LEFT_CLEANED_RIGHT_BUSY;
		}
		else
		{
			/*do nothing*/
			reading = FAILURE_READING;
			ERRH::Error_logErrorClass(ERROR_GTSP_READ_SENSORS_EAST_VIEW_FAIL);
		}
	}
	else
	{
		/*invalid direction*/
		reading = FAILURE_READING;
		ERRH::Error_logErrorClass(ERROR_GTSP_READ_SENSORS_ALL_VIEW_FAIL);
	}
	return reading;
}
