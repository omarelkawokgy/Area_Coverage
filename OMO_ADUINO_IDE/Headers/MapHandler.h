#ifndef MAPHANDLER_H
#define MAPHANDLER_H
#include "types.h"
#include "CONF.h"
#include "positionHandler.h"
#ifdef ENABLE_SIMULATION
#include <iostream>
#endif

#define USING_STRUCT_MAP

#ifdef USING_STRUCT_MAP
typedef struct pointOnMap_S
{
	uint8 point_0:3;
	uint8 point_1:3;
	uint8 point_2:3;
	uint8 point_3:3;
	uint8 point_4:3;
	uint8 point_5:3;
	uint8 point_6:3;
	uint8 point_7:3;
	uint8 point_8:3;
	uint8 point_9:3;
	uint8 point_10:3;
	uint8 point_11:3;
	uint8 point_12:3;
	uint8 point_13:3;
	uint8 point_14:3;
	uint8 point_15:3;
	uint8 point_16:3;
	uint8 point_17:3;
	uint8 point_18:3;
	uint8 point_19:3;
}pointOnMap_T;
#endif

class Map : public positionHeadingHandler
{
private:

#ifdef USING_STRUCT_MAP
	pointOnMap_T room[MAP_ROW];
	void setPointOnMapStruct(uint8 i, uint8 j, CELL_STATE state);

	void getPointOnMapStruct(uint8 i, uint8 j, CELL_STATE* state);
#else
	uint8 room[MAP_ROW][MAP_COLUMN];
#endif

public:
	
	Map();

	static Map& getInstance(void);

	void initMap(void);

#ifdef POINT_LIST_ENABLE
	void addPointOnMap(Point newpoint, positionHeadingHandler rob, Heading heading);
#else
	void addPointOnMap(PointPos PointPosition, positionHeadingHandler& rob, Heading heading);
#endif
	void MergePointsOnMap(PointPos newPointPos, PointPos oldPointPos);

	void UpdateRobotPosition(positionHeadingHandler& rob);

	void addRobotOnMap(uint8 y, uint8 x);

	void addCleanedOnMap(uint8 y, uint8 x);

	void addBusyOnMap(uint8 y, uint8 x);

	void addEmptyOnMap(uint8 y, uint8 x);

	void addUnCoveredOnMap(uint8 y, uint8 x);

	PointStatus ReadPointFromMap(uint8 y, uint8 x);

#ifdef WORKING_WITH_ANGLES
	uint16 ScanEmptyArea(positionHeadingHandler& cleaner);
#else
	Coordinates ScanEmptyArea(positionHeadingHandler& cleaner);
#endif
};

#endif
