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

Point Pointlist[20];

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
	RobTempPosition.theta = ROBOT_INIT_THETA;
	RobTempPosition.X_pos = ROBOT_INIT_X;
	RobTempPosition.Y_pos = ROBOT_INIT_Y;
	Robot cleaner = Robot::initRobotPosition(RobTempPosition);

	/*----------------Error Init Data-----------------*/
	return_type Error_Check = RET_NOT_OK;

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
while (1)
{

	/*check the ID of the point before creating new ones*/
	Error_Check = scan.LinearScan(&LeftTempPointPos, &RightTempPointPos, cleaner);
	if (Error_Check == RET_OK)
	{
		if (RoomMap.room[LeftTempPointPos.Y_Row][LeftTempPointPos.X_Column] != BUSY)
		{
			Pointlist[PointListIndex].setPointPos(LeftTempPointPos);
			RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner);
			PointListIndex++;
		}
		else
		{
			/*TODO: update point position by checking if theres a point near this remove it,
			and replace it with updated one*/
		}
		
		if (RoomMap.room[RightTempPointPos.Y_Row][RightTempPointPos.X_Column] != BUSY)
		{
			Pointlist[PointListIndex].setPointPos(RightTempPointPos);
			RoomMap.addPointOnMap(Pointlist[PointListIndex], cleaner);
			PointListIndex++;
		}
		else
		{
			/*TODO: update point position by checking if theres a point near this remove it,
			and replace it with updated one*/
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

