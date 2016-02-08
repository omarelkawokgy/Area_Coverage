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
	Point();

	Point(SensorID side, RobotPos robPos, uint16 distance);

	return_type CalPointPos(SensorID side, RobotPos robPos, uint16 distance);

	PointPos getPointPos(void);

	void setPointPos(PointPos pos);

	void FilteredPointReading(SensorID side, RobotPos robPos, uint16 newdistance);

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
