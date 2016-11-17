#include "Project_Path.h"
#include RELATIVE_PATH(ZGZG.h)
#include RELATIVE_PATH(Scan.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(COMH.h)
#undef PROJECT_PATH_H

void ZGZG::ZigZagRoutine(RobotDevice& theCleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq)
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
		RobCurrentHeading = theCleaner.GetRobotHeading();
		(void)theCleaner.getTheMove().MoveForward(RobCurrentHeading);
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
//			(void)theCleaner.getTheMove().MoveStop();
//			(void)theCleaner.getTheMove().MoveBackward(RobCurrentHeading);
			BumperHit = FALSE;

			RobTempPosition = theCleaner.GetRobotPosition();
			readingSensorsView = GTSP::BumperHitSensorsView(theCleaner.getPosition(), RoomMap, *RobHeadingReq);

			switch (readingSensorsView)
			{
			case LEFT_EMPTY_RIGHT_EMPTY:
				UturnFlag = FALSE;
				if (REQUEST_NORTH == *RobHeadingReq)
				{
					/*uturn right*/
					*RobHeadingReq = REQUEST_SOUTH;
					theCleaner.getTheMove().UTurnRight(theCleaner.getPosition(), RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					theCleaner.getTheMove().UTurnLeft(theCleaner.getPosition(), RobCurrentHeading);
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
					theCleaner.getTheMove().UTurnRight(theCleaner.getPosition(), RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					theCleaner.getTheMove().UTurn(theCleaner.getPosition(), RobCurrentHeading);
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
					theCleaner.getTheMove().UTurnLeft(theCleaner.getPosition(), RobCurrentHeading);
					RoomMap.addCleanedOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);
					RoomMap.addBusyOnMap(RobTempPosition.Y_pos - 1, RobTempPosition.X_pos);
				}
				else if (REQUEST_SOUTH == *RobHeadingReq)
				{
					/*uturn left*/
					*RobHeadingReq = REQUEST_NORTH;
					theCleaner.getTheMove().UTurnLeft(theCleaner.getPosition(), RobCurrentHeading);
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
				theCleaner.getTheMove().UTurn(theCleaner.getPosition(), RobCurrentHeading);
				break;
			default:
				ERRH::Error_logErrorClass(ERROR_ZGZG_DEFAULT_CASE);
				break;
			}
			//RobCurrentHeading = theCleaner.getPosition().GetRobotHeading();
			RoomMap.UpdateRobotPosition(theCleaner.getPosition());
		}
		else
		{
			/*entering straightline no BumperHit*/
			/*TODO:check the ID of the point before creating new ones*/
			Error_Check = scan.LinearScan(&LeftTempPointPos, &RightTempPointPos, theCleaner, RobCurrentHeading);
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
						RoomMap.addPointOnMap(Pointlist[PointListIndex], theCleaner.getPosition(), RobCurrentHeading);
						PointListIndex++;
					}
#else
					RoomMap.addPointOnMap(LeftTempPointPos, theCleaner.getPosition(), RobCurrentHeading);
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
						RoomMap.addPointOnMap(Pointlist[PointListIndex], theCleaner.getPosition(), RobCurrentHeading);
						PointListIndex++;
					}
#else
					RoomMap.addPointOnMap(RightTempPointPos, theCleaner.getPosition(), RobCurrentHeading);
#endif
				}
				else
				{
					/*Do nothing*/
				}
			}
			else
			{
				fixRobotHeading(theCleaner, *RobHeadingReq);
			}

			RoomMap.UpdateRobotPosition(theCleaner.getPosition());
		}
	}

}

void ZGZG::fixRobotHeading(RobotDevice& theCleaner, enu_Direction_req RobHeadingReq)
{
	uint16 CompassRawReading = theCleaner.getCompass().ReadRawData();
	switch (RobHeadingReq)
	{
	case REQUEST_NORTH:
		if (CompassRawReading < SOUTH_VALUE)
		{
			theCleaner.getTheMove().MoveTurn_CW(theCleaner.getPosition(), NORTH_VALUE);
		}
		else
		{
			theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), NORTH_VALUE);
		}
		break;
	case REQUEST_WEST:
		if (CompassRawReading < EAST_VALUE)
		{
			theCleaner.getTheMove().MoveTurn_CW(theCleaner.getPosition(), WEST_VALUE);
		}
		else
		{
			theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), WEST_VALUE);
		}
		break;
	case REQUEST_SOUTH:
		if (CompassRawReading < NORTH_VALUE)
		{
			theCleaner.getTheMove().MoveTurn_CW(theCleaner.getPosition(), SOUTH_VALUE);
		}
		else
		{
			theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), SOUTH_VALUE);
		}
		break;
	case REQUEST_EAST:
		if (CompassRawReading < WEST_VALUE)
		{
			theCleaner.getTheMove().MoveTurn_CW(theCleaner.getPosition(), EAST_VALUE);
		}
		else
		{
			theCleaner.getTheMove().MoveTurn_CCW(theCleaner.getPosition(), EAST_VALUE);
		}
		break;
	default:
		ERRH::Error_logErrorClass(ERROR_ZGZG_FIX_ROBOT_DEFAULT_CASE);
		break;
	}
}
