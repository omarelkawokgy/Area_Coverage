#include "Project_Path.h"
#include RELATIVE_PATH(Robot.h)
#include RELATIVE_PATH(COMH.h)
#undef PROJECT_PATH_H
#ifdef ENABLE_SIMULATION
#include <iostream>
#include "Headers\SIMU.h"
using namespace std;
#endif

//initial position where the robot starts its corrdinate and bearing
Robot& Robot::initRobotPosition(void)
{
	static Robot cleaner;
	cleaner.X_Robot = ROBOT_INIT_X;
	cleaner.Y_Robot = ROBOT_INIT_Y;
	cleaner.theta_Robot = ROBOT_INIT_THETA;
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

Heading Robot::GetRobotHeading(void)
{
	Heading heading;
	heading = Comp::ReadComp();
	return heading;
}

//updating the position of the robot
void Robot::SetPosition(RobotPos position)
{
	X_Robot = position.X_pos;
	Y_Robot = position.Y_pos;
	theta_Robot = position.theta;
}



