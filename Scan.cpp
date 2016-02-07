#include <iostream>

#include "Scan.h"
#include "ULSH.h"
#include "MOVH.h"
using namespace std;

Scan& Scan::getInstanceScan()
{
	static Scan scan;
	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		scan.Distancelist[i].L_Distance = 0;
		scan.Distancelist[i].R_Distance = 0;
	}
	return scan;
}

void Scan::Init(void)
{
	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		Distancelist[i].L_Distance = 0;
		Distancelist[i].R_Distance = 0;
	}
}

void Scan::CirclScanRoutine(Robot rob, L_R_Dist* scanlist)
{
	MOVE::MoveInitAngle(&rob);

	for (uint8 i = 0; i < FULL_SCAN_NUM; i++)
	{
		MOVE::MoveTurn_CW(&rob, SCAN_ANGLE);
		scanlist[i] = ULSH::ULS_getDistanceboth();
	}
#ifdef DEBUG
	cout << "Distance list [0] in scanroutine:" << scanlist[4].L_Distance << endl;
#endif
}
