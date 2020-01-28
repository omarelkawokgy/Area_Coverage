#include "Project_Path.h"
#include RELATIVE_PATH(Scan.h)
#include RELATIVE_PATH(ULSH.h)
#include RELATIVE_PATH(ERRH.h)
#undef PROJECT_PATH_H


#ifdef ENABLE_SIMULATION
#include <iostream>
using namespace std;
#endif

Scan& Scan::getInstanceScan()
{
	static Scan scan;
#if 0 
	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		scan.Distancelist[i].L_Distance = 0;
		scan.Distancelist[i].R_Distance = 0;
	}
#endif
	return scan;
}

void Scan::Init(void)
{
	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		Distancelist[i].L_Distance = 0;
		Distancelist[i].R_Distance = 0;
	}
}

#if 0
void Scan::CirclScanRoutine(Robot rob, L_R_Dist* scanlist)
{
	MOVE::MoveInitAngle(rob);

	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		MOVE::MoveTurn_CW(rob, SCAN_ANGLE);
		scanlist[i] = ULSH::ULS_getDistanceboth();
	}
}
#endif

return_type Scan::LinearScan(PointPos* leftpoint, PointPos* rightpoint, Robot rob, Heading heading)
{
	uint16 ScanDist;
	return_type ret = RET_NOT_OK;

		/*scan and cal point pos from right sensor*/
		ScanDist = ULSH::ULS_getLeftDist();
		ret = ValidatePointPos(leftpoint, LEFT_SENSOR, rob.GetRobotPosition(), ScanDist, heading);

		/*scan and cal point pos from left sensor*/
		ScanDist = ULSH::ULS_getRightDist();
		ret &= ValidatePointPos(rightpoint, RIGHT_SENSOR, rob.GetRobotPosition(), ScanDist, heading);

		if (ret == RET_NOT_OK)
		{
			ERRH::Error_logErrorClass(ERROR_SCAN_LINEARSCAN_FAIL);
		}

	return ret;
}

return_type Scan::ValidatePointPos(PointPos* pointPos, SensorID side, RobotPos robPos, uint16 distance, Heading heading)
{
	return_type ret = RET_NOT_OK;

	if (heading != INVALID_DIRECTION)
	{
		switch (side)
		{
		case LEFT_SENSOR:
			if (heading == NORTH)
			{
				pointPos->X_Column = robPos.X_pos - distance;
				pointPos->Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				pointPos->X_Column = robPos.X_pos;
				pointPos->Y_Row = robPos.Y_pos + distance;
			}
			else if (heading == SOUTH)
			{
				pointPos->X_Column = robPos.X_pos + distance;
				pointPos->Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				pointPos->X_Column = robPos.X_pos;
				pointPos->Y_Row = robPos.Y_pos - distance;
			}
			break;
		case RIGHT_SENSOR:
			if (heading == NORTH)
			{
				pointPos->X_Column = robPos.X_pos + distance;
				pointPos->Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				pointPos->X_Column = robPos.X_pos;
				pointPos->Y_Row = robPos.Y_pos - distance;
			}
			else if (heading == SOUTH)
			{
				pointPos->X_Column = robPos.X_pos - distance;
				pointPos->Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				pointPos->X_Column = robPos.X_pos;
				pointPos->Y_Row = robPos.Y_pos + distance;
			}
			break;
		}
		ret = RET_OK;
	}
	else
	{
		ret = RET_NOT_OK;
		ERRH::Error_logErrorClass(ERROR_SCAN_VALIDATION_DISTANCE_FAIL);
	}
	return ret;
}
