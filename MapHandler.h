#ifndef MAPHANDLER_H
#define MAPHANDLER_H

#include "rectangle.h"
#include "CONF.h"


class Map : public Rectangle
{
private:
	Rectangle* rect;
	/*
	uint8 MapRow[MAP_ROW];
	uint8 MapColumn[MAP_COLUMN];
	*/
public:
	uint8 room[MAP_ROW][MAP_COLUMN];

	Map();

	Map getMap(Map m);

	void initMap(void);

	void AddRectangle(Rectangle rect, RobotPos* position);

	void addRobotOnMap(RobotPos robPosition);


};

#endif
