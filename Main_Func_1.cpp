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
	/*-----------------Intialize project-------------*/
	Map RoomMap;
	Scan scan = Scan::getInstanceScan();
	ULSH uls;
	RobotPos robposition;
	robposition.theta = ROBOT_INIT_THETA;
	robposition.X_pos = ROBOT_INIT_X;
	robposition.Y_pos = ROBOT_INIT_Y;
	return_type Error_Check = RET_NOT_OK;
	Robot cleaner = Robot::initRobotPosition(robposition);
#ifdef RECTANGLE
	L_R_Dist diagonalList[FULL_SCAN_NUM];
	RectSize rectsize;
	return_type Error_Check;
#endif
	RoomMap.initMap();


	/*-----------start implementing------------*/
	/*apply the scan routine and update rob theta and get list of diagonals*/

#ifdef DEBUG
	cout << "diagonal out of the scan rountine:" << diagonalList[5].L_Distance << endl;
#endif
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
		robposition = cleaner.GetRobotPosition();
#ifdef RECTANGLE
		RoomMap.AddRectangle(rect1, &robposition);
	}
#endif
	RoomMap.addRobotOnMap(cleaner.GetRobotPosition());
	/*check the ID of the point before creating new ones*/
	Error_Check = scan.LinearScan(Pointlist[0], LEFT_SENSOR, cleaner);
	Error_Check &= scan.LinearScan(Pointlist[1], RIGHT_SENSOR, cleaner);
	if (Error_Check == RET_OK)
	{
		RoomMap.addPointOnMap(Pointlist[0]);
		RoomMap.addPointOnMap(Pointlist[1]);
	}

#ifdef ENABLE_SIMULATION
	simu sim;	
	for (int i = 0; i < 9; i++)
	{
		Error_Check = MOVE::MoveForward(cleaner);
		if (Error_Check == RET_OK)
		{
			RoomMap.UpdateRobotPosition(cleaner);
			sim.printMap(RoomMap);
		}
	}



#endif
	/*--------------end of intialization------------*/
	//while (1)
	//{
		//the return of this function is input to rect calculate
		//rect1.ConstructRect(scan.ScanRoutine(cleaner));

		//TODO: get rectangle
	//}
	system("pause");
	return;
}
