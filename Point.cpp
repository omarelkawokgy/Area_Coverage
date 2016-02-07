#include "OBJD.h"
#include "ULSH.h"
#include "COMH.h"


Point::Point(SensorSide side, RobotPos robPos, L_R_Dist distance)
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

void Point::CalPointPos(SensorSide side, RobotPos robPos, L_R_Dist distance)
{
	Heading heading = Comp::ReadComp(robPos.theta);

	switch (side)
	{
	case LEFT_SENSOR:
		if (heading == NORTH)
		{
			pointPos.X_Column = robPos.X_pos - distance.L_Distance;
		}
		else if (heading == WEST)
		{
			pointPos.Y_Row = robPos.Y_pos + distance.L_Distance;
		}
		else if (heading == SOUTH)
		{
			pointPos.X_Column = robPos.X_pos + distance.L_Distance;
		}
		else if (heading == EAST)
		{
			pointPos.Y_Row = robPos.Y_pos - distance.L_Distance;
		}
		break;
	case RIGHT_SENSOR:
		if (heading == NORTH)
		{
			pointPos.X_Column = robPos.X_pos + distance.R_Distance;
		}
		else if (heading == WEST)
		{
			pointPos.Y_Row = robPos.Y_pos - distance.R_Distance;
		}
		else if (heading == SOUTH)
		{
			pointPos.X_Column = robPos.X_pos - distance.R_Distance;
		}
		else if (heading == EAST)
		{
			pointPos.Y_Row = robPos.Y_pos + distance.R_Distance;
		}
		break;
	}
}

/*filtering using average between the position of 2 points*/
void Point::FilteredPointReading(SensorSide side, RobotPos robPos, L_R_Dist newdistance)
{
	Point oldPoint(side, robPos, newdistance);
	PointPos oldPointPos = oldPoint.getPointPos();
	pointPos.X_Column = (uint8)((oldPointPos.X_Column + pointPos.X_Column) / 2);
	pointPos.Y_Row = (uint8)((oldPointPos.Y_Row + pointPos.Y_Row) / 2);
}
