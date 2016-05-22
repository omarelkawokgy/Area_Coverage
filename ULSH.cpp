#include "ULSH.h"

using namespace std;

ULSH::ULSH()
{

}

static uint16 Read_distance()
{
#define RADOM_NUM 30
	return RADOM_NUM;
}

uint16 ULSH::ULS_getLeftDist(void)
{
	uint16 left = 0;
#ifdef ENABLE_SIMULATION
	cout << "Left distance:" << endl;
	cin >> left;
#else
	/*take about 3 readings evrytime and return the average*/
	left = Read_distance();
	left += Read_distance();
	left += Read_distance();

	left = (uint16)(left / 3);
#endif
	if (left < ROBOT_SIZE)
	{
		left = ROBOT_SIZE;
	}
	left = (uint16)(left / ROBOT_SIZE);
	return left;
}

uint16 ULSH::ULS_getRightDist(void)
{
	uint16 right = 0;
#ifdef ENABLE_SIMULATION
	cout << "right distance:" << endl;
	cin >> right;
#else
	/*take about 3 readings evrytime and return the average*/
	right = Read_distance();
	right += Read_distance();
	right += Read_distance();

	right = (uint16)(right / 3);
#endif
	if (right < ROBOT_SIZE)
	{
		right = ROBOT_SIZE;
	}
	right = (uint16)(right / ROBOT_SIZE);
	return right;
}

L_R_Dist ULSH::ULS_getDistanceboth(void)
{
	L_R_Dist both;
	both.L_Distance = ULSH::ULS_getLeftDist();
	both.R_Distance = ULSH::ULS_getRightDist();
	return both;
}
