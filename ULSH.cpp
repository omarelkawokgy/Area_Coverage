#include <iostream>
#include "ULSH.h"

using namespace std;

ULSH::ULSH()
{

}

uint16 ULSH::ULS_getLeftDist(void)
{
	uint16 left;
#ifdef ENABLE_SIMULATION
	cout << "Left distance:" << endl;
	cin >> left;
#else
	/*take about 3 readings evrytime and return the average*/
#endif
	return left;
}

uint16 ULSH::ULS_getRightDist(void)
{
	uint16 right;
#ifdef ENABLE_SIMULATION
	cout << "right distance:" << endl;
	cin >> right;
#else
	/*take about 3 readings evrytime and return the average*/
#endif
	return right;
}

L_R_Dist ULSH::ULS_getDistanceboth(void)
{
	L_R_Dist both;
#ifdef ENABLE_SIMULATION
	both.L_Distance = ULSH::ULS_getLeftDist();
	both.R_Distance = ULSH::ULS_getRightDist();
#else

#endif
	return both;
}
