#include "Project_Path.h"
#include RELATIVE_PATH(MapHandler.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(positionHandler.h)
#include RELATIVE_PATH(Main_Func_1.h)
#undef PROJECT_PATH_H

#ifdef ENABLE_SIMULATION
using namespace std;
#endif

Map::Map()
{
	//Rectangle R1(20, 30);
}

#ifdef USING_STRUCT_MAP
void Map::getPointOnMapStruct(uint8 i, uint8 j, CELL_STATE* state)
{
	switch(j)
	{
	case 0:
		*state = room[i].point_0;
		 break;
	case 1:
		 *state = room[i].point_1;
		 break;
	case 2:
		*state = room[i].point_2 ;
		 break;
	case 3:
		*state = room[i].point_3 ;
		 break;
	case 4:
		*state = room[i].point_4 ;
		 break;
	case 5:
		*state = room[i].point_5 ;
		 break;
	case 6:
		*state = room[i].point_6 ;
		 break;
	case 7:
		*state = room[i].point_7 ;
		 break;
	case 8:
		*state = room[i].point_8 ;
		 break;
	case 9:
		*state = room[i].point_9 ;
		 break;
	case 10:
		*state = room[i].point_10 ;
		 break;
	case 11:
		*state = room[i].point_11 ;
		 break;
	case 12:
		*state = room[i].point_12 ;
		 break;
	case 13:
		*state = room[i].point_13 ;
		 break;
	case 14:
		*state = room[i].point_14 ;
		 break;
	case 15:
		*state = room[i].point_15 ;
		 break;
	case 16:
		*state = room[i].point_16 ;
		 break;
	case 17:
		*state = room[i].point_17 ;
		 break;
	case 18:
		*state = room[i].point_18 ;
		 break;
	default:
		*state = room[i].point_19 ;
		 break;
	}

}

void Map::setPointOnMapStruct(uint8 i, uint8 j, CELL_STATE state)
{
	switch(j)
	{
	case 0:
		 room[i].point_0 = state;
		 break;
	case 1:
		 room[i].point_1 = state;
		 break;
	case 2:
		 room[i].point_2 = state;
		 break;
	case 3:
		 room[i].point_3 = state;
		 break;
	case 4:
		 room[i].point_4 = state;
		 break;
	case 5:
		 room[i].point_5 = state;
		 break;
	case 6:
		 room[i].point_6 = state;
		 break;
	case 7:
		 room[i].point_7 = state;
		 break;
	case 8:
		 room[i].point_8 = state;
		 break;
	case 9:
		 room[i].point_9 = state;
		 break;
	case 10:
		 room[i].point_10 = state;
		 break;
	case 11:
		 room[i].point_11 = state;
		 break;
	case 12:
		 room[i].point_12 = state;
		 break;
	case 13:
		 room[i].point_13 = state;
		 break;
	case 14:
		 room[i].point_14 = state;
		 break;
	case 15:
		 room[i].point_15 = state;
		 break;
	case 16:
		 room[i].point_16 = state;
		 break;
	case 17:
		 room[i].point_17 = state;
		 break;
	case 18:
		 room[i].point_18 = state;
		 break;
	default:
		 room[i].point_19 = state;
		 break;
	}

}
#endif

void Map::initMap(void)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
#ifdef USING_STRUCT_MAP
			Map::setPointOnMapStruct(i, j, UNCOVERED);
#else
			room[i][j] = UNCOVERED;
#endif
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
#ifdef USING_STRUCT_MAP
		Map::setPointOnMapStruct( y, x, CLEANED);
#else
		room[y][x] = CLEANED;
#endif
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
#ifdef USING_STRUCT_MAP
		Map::setPointOnMapStruct( y, x, BUSY);
#else
		room[y][x] = BUSY;
#endif
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
#ifdef USING_STRUCT_MAP
		Map::setPointOnMapStruct( y, x, EMPTY);
#else
		room[y][x] = EMPTY;
#endif
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
#ifdef USING_STRUCT_MAP
		Map::setPointOnMapStruct( y, x, ROBOT);
#else
		room[y][x] = ROBOT;
#endif
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
#ifdef USING_STRUCT_MAP
		Map::setPointOnMapStruct( y, x, UNCOVERED);
#else
		room[y][x] = UNCOVERED;
#endif
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
}
#ifdef POINT_LIST_ENABLE
void Map::addPointOnMap(Point newpoint, positionHeadingHandler rob, Heading heading)
#else
void Map::addPointOnMap(PointPos PointPosition, positionHeadingHandler& rob, Heading heading)
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

void Map::UpdateRobotPosition(positionHeadingHandler& rob)
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
	CELL_STATE tempPointStatus = 0x00;
	if ((y <= MAP_ROW) && (x <= MAP_COLUMN))
	{
#ifdef USING_STRUCT_MAP
		Map::getPointOnMapStruct( y, x, &tempPointStatus);
#else
		tempPointStatus = room[y][x];
#endif
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MAP_ACCESS_OUT_OF_BOUND);
	}
	return (PointStatus)tempPointStatus;
}

void Map::MergePointsOnMap(PointPos newPointPos, PointPos oldPointPos)
{
	addUnCoveredOnMap(oldPointPos.Y_Row, oldPointPos.X_Column);
	addBusyOnMap(newPointPos.Y_Row, newPointPos.X_Column);
}
#ifdef WORKING_WITH_ANGLES
uint16 Map::ScanEmptyArea(positionHeadingHandler& cleaner)
#else
Coordinates Map::ScanEmptyArea(positionHeadingHandler& cleaner)
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

Map& Map::getInstance(void)
{
	static Map room;
	return room;
}
