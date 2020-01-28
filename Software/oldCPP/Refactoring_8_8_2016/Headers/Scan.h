#ifndef SCAN_H
#define SCAN_H

#include "types.h"
#include "CONF.h"
#include "Robot.h"

class Scan
{
private:
	L_R_Dist Distancelist[FULL_SCAN_NUM];

	return_type ValidatePointPos(PointPos* pointPos, SensorID side, RobotPos robPos, uint16 distance, Heading heading);

	Scan(){}
public:

	static Scan& getInstanceScan();

	void Init(void);
	/*Scan 360 degree while staying in the same coordinates*/
	void CirclScanRoutine(Robot rob, L_R_Dist* scanlist);
	/*taking the reading while moving linearly and Calculating average*/
	return_type LinearScan(PointPos* leftpoint, PointPos* rightpoint, Robot rob, Heading heading);
};

#endif
