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
public:
	Point(SensorSide side, RobotPos robPos);

	PointPos getPointPos(void);

	void setPointPos(PointPos pos);

	void FilteredPointReading(Point point);

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
