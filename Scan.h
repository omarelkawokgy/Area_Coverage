#ifndef SCAN_H
#define SCAN_H

#include "Robot.h"
#include "CONF.h"

class Scan
{
private:
	L_R_Dist Distancelist[FULL_SCAN_NUM];
public:
	Scan();

	void Init(void);
	/*Scan 360 degree while staying in the same coordinates*/
	void CirclScanRoutine(Robot rob, L_R_Dist* scanlist);
	/*taking the reading while moving linearly anf Calculating average*/
	void LinearScanRoutine(Robot rob, L_R_Dist* scanlist);
};

#endif
