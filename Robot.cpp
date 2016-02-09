#include <iostream>
#include "Robot.h"
#include "MapHandler.h"
#include "SIMU.h"


using namespace std;

//initial position where the robot starts its corrdinate and bearing
Robot& Robot::initRobotPosition(RobotPos position)
{
	static Robot cleaner;
	cleaner.X_Robot = position.X_pos;
	cleaner.Y_Robot = position.Y_pos;
	cleaner.theta_Robot = position.theta;
	return cleaner;
}

//getting position of the robot
RobotPos Robot::GetRobotPosition(void)
{
	RobotPos position;
	position.X_pos = X_Robot;
	position.Y_pos = Y_Robot;
	position.theta = theta_Robot;
	return position;
}

//updating the position of the robot
void Robot::UpdateRobotPosition(RobotPos position)
{
	X_Robot = position.X_pos;
	Y_Robot = position.Y_pos;
	theta_Robot = position.theta;
}



