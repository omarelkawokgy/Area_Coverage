#include "Project_Path.h"
#include RELATIVE_PATH(ZGZG.h)
#include RELATIVE_PATH(Scan.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(COMH.h)
#undef PROJECT_PATH_H

void ZGZG::ZigZagRoutine(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
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
	if (ZigZagFlag)
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
			BumperHit = FALSE;

			RobTempPosition = cleaner.GetRobotPosition();
			readingSensorsView = GTSP::BumperHitSensorsView(cleaner, RoomMap, *RobHeadingReq);

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
				ERRH::Error_logErrorClass(ERROR_ZGZG_DEFAULT_CASE);
				break;
			}
			//RobCurrentHeading = cleaner.GetRobotHeading();
			RoomMap.UpdateRobotPosition(cleaner);
		}
		else
		{
			/*entering straightline no BumperHit*/
			/*TODO:check the ID of the point before creating new ones*/
			Error_Check = scan.LinearScan(&LeftTempPointPos, &RightTempPointPos, cleaner, RobCurrentHeading);
			if (Error_Check == RET_OK)
			{

				if ((RoomMap.ReadPointFromMap(LeftTempPointPos.Y_Row, LeftTempPointPos.X_Column) != BUSY) &&
					(RoomMap.ReadPointFromMap(LeftTempPointPos.Y_Row, LeftTempPointPos.X_Column) != ROBOT))
				{
#ifdef POINT_LIST_ENABLE
					UpdatePointCheck = CheckPointUpdatePos(LeftTempPointPos, RobCurrentHeading, RoomMap);
					if (UpdatePointCheck == FALSE)
					{
						Pointlist[PointListIndex].SetPosition(LeftTempPointPos);
						RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobCurrentHeading);
						PointListIndex++;
					}
#else
					RoomMap.addPointOnMap(LeftTempPointPos, cleaner, RobCurrentHeading);
#endif

				}
				else
				{
					/*Do nothing*/

				}

				if ((RoomMap.ReadPointFromMap(RightTempPointPos.Y_Row, RightTempPointPos.X_Column) != BUSY) &&
					(RoomMap.ReadPointFromMap(RightTempPointPos.Y_Row, RightTempPointPos.X_Column) != ROBOT))
				{
#ifdef POINT_LIST_ENABLE
					UpdatePointCheck = CheckPointUpdatePos(RightTempPointPos, RobCurrentHeading, RoomMap);
					if (UpdatePointCheck == FALSE)
					{
						Pointlist[PointListIndex].SetPosition(RightTempPointPos);
						RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner, RobCurrentHeading);
						PointListIndex++;
					}
#else
					RoomMap.addPointOnMap(RightTempPointPos, cleaner, RobCurrentHeading);
#endif
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

void ZGZG::fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq)
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
		ERRH::Error_logErrorClass(ERROR_ZGZG_FIX_ROBOT_DEFAULT_CASE);
		break;
	}
}