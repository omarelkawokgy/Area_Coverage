#include "OBJD.h"

Point::Point()
{
	ClasspointPos.X_Column = 0;
	ClasspointPos.Y_Row = 0;
}

Point::Point(PointPos pointpos)
{
	ClasspointPos.X_Column = pointpos.X_Column;
	ClasspointPos.Y_Row = pointpos.Y_Row;
}

PointPos Point::getPointPos(void)
{
	return ClasspointPos;
}

void Point::setPointPos(PointPos pos)
{
	ClasspointPos.X_Column = pos.X_Column;
	ClasspointPos.Y_Row = pos.Y_Row;
}
	
#ifdef DONE_IN_SCAN
return_type Point::CalPointPos(SensorID side, RobotPos robPos, uint16 distance)
{
	return_type ret = RET_NOT_OK;
	Heading heading = Comp::ReadComp(robPos.theta);

	if (heading != INVALID_DIRECTION)
	{
		switch (side)
		{
		case LEFT_SENSOR:
			if (heading == NORTH)
			{
				ClasspointPos.X_Column = robPos.X_pos - distance;
				ClasspointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				ClasspointPos.X_Column = robPos.X_pos;
				ClasspointPos.Y_Row = robPos.Y_pos + distance;
			}
			else if (heading == SOUTH)
			{
				ClasspointPos.X_Column = robPos.X_pos + distance;
				ClasspointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				ClasspointPos.X_Column = robPos.X_pos;
				ClasspointPos.Y_Row = robPos.Y_pos - distance;
			}
			break;
		case RIGHT_SENSOR:
			if (heading == NORTH)
			{
				ClasspointPos.X_Column = robPos.X_pos + distance;
				ClasspointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				ClasspointPos.X_Column = robPos.X_pos;
				ClasspointPos.Y_Row = robPos.Y_pos - distance;
			}
			else if (heading == SOUTH)
			{
				ClasspointPos.X_Column = robPos.X_pos - distance;
				ClasspointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				ClasspointPos.X_Column = robPos.X_pos;
				ClasspointPos.Y_Row = robPos.Y_pos + distance;
			}
			break;
		}
		ret = RET_OK;
	}
	else
	{
		ret = RET_NOT_OK;
	}
	return ret;
}
#endif
/*filtering is done in ULSH itself taking many readings and finding the average*/
#if 1
/*filtering using average between the position of 2 points*/
PointPos Point::FilteredPointReading(PointPos* newPointPosList, const uint8 PointListSize)
{
	PointPos filteredPointPos;
	uint8 i;

	filteredPointPos.X_Column = 0;
	filteredPointPos.Y_Row = 0;
	for(i = 0; i < PointListSize ; i++)
	{
		filteredPointPos.X_Column += newPointPosList[i].X_Column;
		filteredPointPos.Y_Row += newPointPosList[i].Y_Row;
	}

	filteredPointPos.X_Column = filteredPointPos.X_Column / PointListSize;
	filteredPointPos.Y_Row = filteredPointPos.Y_Row / PointListSize;

	return filteredPointPos;
}
#endif
