#include <iostream>
#include "MapHandler.h"

using namespace std;

Map::Map()
{
	//Rectangle R1(20, 30);
}

void Map::initMap(void)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			room[i][j] = UNCOVERED;
		}
	}
}

#ifdef RECTANGLE
void Map::AddRectangle(Rectangle rect, RobotPos* position)
{
	Map::room;
	RectSize size;
	rect.getRectSize(&size);
	uint8 x_offset = size.X_Dist / 2;
	uint8 y_offset = size.Y_Dist / 2;

	for (uint8 i = 0; i < size.Y_Dist; i++)
	{
		for (uint8 j = 0; j < size.X_Dist; j++)
		{
			if ((Map::room[i][j] != CLEANED) && (Map::room[i][j] != BUSY))
			//Map::room[x_offset - i][y_offset - j] = EMPTY;
			Map::room[i][j] = EMPTY;
			else if (Map::room[i][j] == CLEANED)
			{

			}
			else if (Map::room[i][j] != BUSY)
			{

			}
		}
	}
}
#endif

void Map::addRobotOnMap(RobotPos robPosition)
{
	Map::room[robPosition.Y_pos][robPosition.X_pos] = ROBOT;
}

void Map::addPointOnMap(Point newpoint)
{
	PointPos position;
	position = newpoint.getPointPos();
	room[position.Y_Row][position.X_Column] = BUSY;
}

void Map::UpdateRobotPosition(Robot rob)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			if ((rob.GetRobotPosition().X_pos == i) && (rob.GetRobotPosition().Y_pos == j))
			{
				room[j][i] = ROBOT;
			}
			else if (room[j][i] == ROBOT)
			{
				room[j][i] = CLEANED;
			}
		}
	}
}
