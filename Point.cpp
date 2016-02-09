#include "OBJD.h"
#include "ULSH.h"
#include "COMH.h"

Point::Point()
{
	pointPos.X_Column = 0;
	pointPos.Y_Row = 0;
}

Point::Point(SensorID side, RobotPos robPos, uint16 distance)
{
	CalPointPos(side, robPos, distance);
}

PointPos Point::getPointPos(void)
{
	return pointPos;
}

void Point::setPointPos(PointPos pos)
{
	pointPos.X_Column = pos.X_Column;
	pointPos.Y_Row = pos.Y_Row;
}

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
				pointPos.X_Column = robPos.X_pos - distance;
				pointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				pointPos.X_Column = robPos.X_pos;
				pointPos.Y_Row = robPos.Y_pos + distance;
			}
			else if (heading == SOUTH)
			{
				pointPos.X_Column = robPos.X_pos + distance;
				pointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				pointPos.X_Column = robPos.X_pos;
				pointPos.Y_Row = robPos.Y_pos - distance;
			}
			break;
		case RIGHT_SENSOR:
			if (heading == NORTH)
			{
				pointPos.X_Column = robPos.X_pos + distance;
				pointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == WEST)
			{
				pointPos.X_Column = robPos.X_pos;
				pointPos.Y_Row = robPos.Y_pos - distance;
			}
			else if (heading == SOUTH)
			{
				pointPos.X_Column = robPos.X_pos - distance;
				pointPos.Y_Row = robPos.Y_pos;
			}
			else if (heading == EAST)
			{
				pointPos.X_Column = robPos.X_pos;
				pointPos.Y_Row = robPos.Y_pos + distance;
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

/*filtering is done in ULSH itself taking many readings and finding the average*/
#if 0
/*filtering using average between the position of 2 points*/
void Point::FilteredPointReading(SensorID side, RobotPos robPos, uint16 newdistance)
{
	Point oldPoint(side, robPos, newdistance);
	PointPos oldPointPos = oldPoint.getPointPos();
	pointPos.X_Column = (uint8)((oldPointPos.X_Column + pointPos.X_Column) / 2);
	pointPos.Y_Row = (uint8)((oldPointPos.Y_Row + pointPos.Y_Row) / 2);
}
#endif
