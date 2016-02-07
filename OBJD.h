#ifndef OBJD_H
#define OBJD_H

#include "CONF.h"
#include "types.h"

class OBJD
{
private:

public:

};

class Point
{
private:
	PointPos pointPos;

	void CalPointPos(SensorSide side, RobotPos robPos, L_R_Dist distance);
public:
	Point(SensorSide side, RobotPos robPos, L_R_Dist distance);

	PointPos getPointPos(void);

	void setPointPos(PointPos pos);

	void FilteredPointReading(SensorSide side, RobotPos robPos, L_R_Dist newdistance);

};

#ifdef USING_SHAPES
class StraightLine
{
private:

public:
	StraightLine(StraightLinePos Line);
};
#endif
#endif
