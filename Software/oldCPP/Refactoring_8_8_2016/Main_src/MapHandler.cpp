#include "Project_Path.h"
#include RELATIVE_PATH(MapHandler.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Robot.h)
#include RELATIVE_PATH(Main_Func_1.h)
#undef PROJECT_PATH_H

#ifdef ENABLE_SIMULATION
using namespace std;
#endif

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
			if ((Map::ReadPointFromMap(i,j) != CLEANED) && (Map::ReadPointFromMap(i,j) != BUSY))
			//Map::ReadPointFromMap(x_offset - i][y_offset - j] = EMPTY;
			Map::ReadPointFromMap(i,j) = EMPTY;
			else if (Map::ReadPointFromMap(i,j) == CLEANED)
			{

			}
			else if (Map::ReadPointFromMap(i,j) != BUSY)
			{

			}
		}
	}
}
#endif

void Map::addCleanedOnMap(uint8 y, uint8 x)
{
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		room[y][x] = CLEANED;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}

void Map::addBusyOnMap(uint8 y, uint8 x)
{
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		room[y][x] = BUSY;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}

void Map::addEmptyOnMap(uint8 y, uint8 x)
{
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		room[y][x] = EMPTY;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}

void Map::addRobotOnMap(uint8 y, uint8 x)
{
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		room[y][x] = ROBOT;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}

void Map::addUnCoveredOnMap(uint8 y, uint8 x)
{
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		room[y][x] = UNCOVERED;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}
#ifdef POINT_LIST_ENABLE
void Map::addPointOnMap(Point newpoint, Robot rob, Heading heading)
#else
void Map::addPointOnMap(PointPos PointPosition, Robot rob, Heading heading)
#endif
{	
	RobotPos RobPosition;
	uint8 EmptyDistance;
	uint8 StartSwipe;
#ifdef POINT_LIST_ENABLE
	PointPos PointPosition;
	PointPosition = newpoint.getPointPos();
#endif
	addBusyOnMap(PointPosition.Y_Row, PointPosition.X_Column);

	/*clearing area between robot and obstical*/
	RobPosition = rob.GetRobotPosition();

	if ((heading == NORTH) || (heading == SOUTH))
	{
		if ((RobPosition.X_pos - PointPosition.X_Column) < 0)
		{
			StartSwipe = RobPosition.X_pos + 1;
			EmptyDistance = (((RobPosition.X_pos - PointPosition.X_Column) * -1)) + RobPosition.X_pos;
		}
		else
		{
			StartSwipe = PointPosition.X_Column + 1;
			EmptyDistance = ((RobPosition.X_pos - PointPosition.X_Column)) + PointPosition.X_Column;
		}

		for (uint8 i = StartSwipe; i < EmptyDistance; i++)
		{
			if ((ReadPointFromMap(PointPosition.Y_Row, i) != CLEANED) && (ReadPointFromMap(PointPosition.Y_Row, i) != BUSY))
			{
				addEmptyOnMap(PointPosition.Y_Row, i);
			}
		}
	}
	else if ((heading == WEST) || (heading == EAST))
	{
		if ((RobPosition.Y_pos - PointPosition.Y_Row) < 0)
		{
			StartSwipe = RobPosition.Y_pos + 1;
			EmptyDistance = (((RobPosition.Y_pos - PointPosition.Y_Row) * -1)) + RobPosition.Y_pos;
		}
		else
		{
			StartSwipe = PointPosition.Y_Row + 1;
			EmptyDistance = ((RobPosition.Y_pos - PointPosition.Y_Row)) + PointPosition.Y_Row;
		}

		for (uint8 i = StartSwipe; i < EmptyDistance; i++)
		{
			if ((i <= MAP_ROW) && (PointPosition.X_Column <= MAP_COLUMN))
			{
				if ((ReadPointFromMap(i, PointPosition.X_Column) != CLEANED) && (ReadPointFromMap(i, PointPosition.X_Column) != BUSY))
				{
					addEmptyOnMap(i, PointPosition.X_Column);
				}
			}
			else
			{
				ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
			}
		}
	}
}

void Map::UpdateRobotPosition(Robot& rob)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			if ((i <= MAP_ROW) && (j <= MAP_COLUMN))
			{
				if ((rob.GetRobotPosition().X_pos == i) && (rob.GetRobotPosition().Y_pos == j))
				{
					addRobotOnMap(j, i);
				}
				else if (ReadPointFromMap(j,i) == ROBOT)
				{
					if (ToStartPoint == FALSE)
					{
						addCleanedOnMap(j, i);
					}
					else
					{
						addEmptyOnMap(j, i);
					}

				}
			}
			else
			{
				ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
			}
		}
	}
}

PointStatus Map::ReadPointFromMap(uint8 y, uint8 x)
{
	PointStatus tempPointStatus = 0x00;
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
		tempPointStatus = room[y][x];
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
	return tempPointStatus;
}

void Map::MergePointsOnMap(PointPos newPointPos, PointPos oldPointPos)
{
	addUnCoveredOnMap(oldPointPos.Y_Row, oldPointPos.X_Column);
	addBusyOnMap(newPointPos.Y_Row, newPointPos.X_Column);
}
#ifdef WORKING_WITH_ANGLES
uint16 Map::ScanEmptyArea(Robot& cleaner)
#else
Coordinates Map::ScanEmptyArea(Robot& cleaner)
#endif
{
	Coordinates Empty_Coordinate;
	Empty_Coordinate.X_Column = 0;
	Empty_Coordinate.Y_Row = 0;
#ifdef WORKING_WITH_ANGLES
	RobotPos tempRobotPosition;
	uint8 delta_X;
	uint8 delta_Y;
	Required_Empty_Goal goalheading;
	uint16 Theta_Temp;
	uint16 Theta_Goal;
#endif
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			if (ReadPointFromMap(j,i) == EMPTY)
			{
				Empty_Coordinate.X_Column = i;
				Empty_Coordinate.Y_Row = j;
				i = MAP_ROW;
				j = MAP_COLUMN;
#ifdef WORKING_WITH_ANGLES
				tempRobotPosition = cleaner.GetRobotPosition();
				delta_X = tempRobotPosition.X_pos - i;
				delta_Y = tempRobotPosition.Y_pos - j;
				if (delta_X < 0)
				{
					delta_X *= -1;
				}

				if (delta_Y < 0)
				{
					delta_Y *= -1;
				}
#endif

			}
		}
	}
	return Empty_Coordinate;
}
