#ifndef MAPHANDLER_H
#define MAPHANDLER_H
#include "types.h"
#include "CONF.h"
#include "Robot.h"
#ifdef ENABLE_SIMULATION
#include <iostream>
#endif

class Map
{
private:
	//Rectangle* rect;
	/*
	uint8 MapRow[MAP_ROW];
	uint8 MapColumn[MAP_COLUMN];
	*/
	uint8 room[MAP_ROW][MAP_COLUMN];
public:
	
	Map();

	Map getMap(Map m);

	void initMap(void);

	//void AddRectangle(Rectangle rect, RobotPos* position);
#ifdef POINT_LIST_ENABLE
	void addPointOnMap(Point newpoint, Robot rob, Heading heading);
#else
	void addPointOnMap(PointPos PointPosition, Robot rob, Heading heading);
#endif
	void MergePointsOnMap(PointPos newPointPos, PointPos oldPointPos);

	void UpdateRobotPosition(Robot& rob);

	void addRobotOnMap(uint8 y, uint8 x);

	void addCleanedOnMap(uint8 y, uint8 x);

	void addBusyOnMap(uint8 y, uint8 x);

	void addEmptyOnMap(uint8 y, uint8 x);

	void addUnCoveredOnMap(uint8 y, uint8 x);

	PointStatus ReadPointFromMap(uint8 y, uint8 x);

#ifdef WORKING_WITH_ANGLES
	uint16 ScanEmptyArea(Robot& cleaner);
#else
	Coordinates ScanEmptyArea(Robot& cleaner);
#endif
};

#endif
