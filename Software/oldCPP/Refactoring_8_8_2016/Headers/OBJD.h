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
	PointPos ClasspointPos;

public:
	Point();

	Point(PointPos pointpos);

	return_type CalPointPos(SensorID side, RobotPos robPos, uint16 distance);

	PointPos getPointPos(void);

	void SetPosition(PointPos pos);

	PointPos FilteredPointReading(PointPos* newPointPosList, const uint8 PointListSize);

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
