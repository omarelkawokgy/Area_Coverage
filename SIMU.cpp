#include <iostream>

#include "SIMU.h"
#include "MapHandler.h"
#include "CONF.h"

using namespace std;



void simu::printMap(Map m)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			cout << (int)m.room[i][j] << " ";
		}
		cout << endl;
	}
}

void simu::wheelTurn(Robot r)
{
	RobotPos position;

	position = r.GetRobotPosition();

	if ((position.theta >= (NORTH_VALUE - ALLOWED_ANGLE_ERROR)) || (position.theta <= (NORTH_VALUE + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: increment according to orientation*/
	}
	else if ((position.theta >= (WEST_VALUE - ALLOWED_ANGLE_ERROR)) || (position.theta <= (WEST_VALUE + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: increment according to orientation*/
	}
	else if ((position.theta >= (SOUTH_VALUE - ALLOWED_ANGLE_ERROR)) || (position.theta <= (SOUTH_VALUE + ALLOWED_ANGLE_ERROR)))
	{

	}
	else if ((position.theta >= (EAST_VALUE - ALLOWED_ANGLE_ERROR)) || (position.theta <= (EAST_VALUE + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: increment according to orientation*/
	}
	else
	{
		/*no increment or angle not right..... TODO: print angle recommended*/
	}

	r.UpdateRobotPosition(position);
}

void simu::robotTurn(Robot r)
{
	RobotPos position;

	position = r.GetRobotPosition();

	position.theta++;

	r.UpdateRobotPosition(position);
}
