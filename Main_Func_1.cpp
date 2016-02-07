#include "Robot.h"
#include "MapHandler.h"
#include "SIMU.h"
#include "Scan.h"
#include "ULSH.h"

#ifdef ENABLE_SIMULATION
#include <iostream>
using namespace std;
#endif

void main()
{
	/*-----------------Intialize project-------------*/
	Map RoomMap;
	Scan scan;
	ULSH uls;
	RobotPos robposition;
	RobotPos robPosInRect;
	robposition.theta = ROBOT_INIT_THETA;
	robposition.X_pos = ROBOT_INIT_X;
	robposition.Y_pos = ROBOT_INIT_Y;
	Robot cleaner = Robot::initRobotPosition(robposition);
	L_R_Dist diagonalList[FULL_SCAN_NUM];
#ifdef RECTANGLE
	RectSize rectsize;
	return_type Error_Check;
#endif
	RoomMap.initMap();
	scan.Init();

	/*-----------start implementing------------*/
	/*apply the scan routine and update rob theta and get list of diagonals*/
	scan.ScanRoutine(cleaner, diagonalList);
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
		cleaner.GetRobotPosition(&robposition);
#ifdef RECTANGLE
		RoomMap.AddRectangle(rect1, &robposition);
	}
#endif
	RoomMap.addRobotOnMap(robposition);

#ifdef ENABLE_SIMULATION
	simu sim;

	sim.printMap(RoomMap);

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
