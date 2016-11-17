#include "Project_Path.h"
#include RELATIVE_PATH(positionHandler.h)
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(MOVH.h)
#undef PROJECT_PATH_H
#ifdef ENABLE_SIMULATION
#include <iostream>
#include "Headers\SIMU.h"
using namespace std;
#endif


positionHeadingHandler::positionHeadingHandler(uint8 _X_Robot, uint8  _Y_Robot, uint16 _theta_Robot)
{
	X_Robot = _X_Robot;
	Y_Robot = _Y_Robot;
	theta_Robot = _theta_Robot;
}

//initial position where the robot starts its corrdinate and bearing
positionHeadingHandler& positionHeadingHandler::getInstance(void)
{
	static positionHeadingHandler cleaner;
	return cleaner;
}

right_encoder& positionHeadingHandler::getRightEncoder()
{
	return encoder;
}

Comp& positionHeadingHandler::getCompass()
{
	return compass;
}

//getting position of the robot
RobotPos positionHeadingHandler::GetRobotPosition(void)
{
	RobotPos position;
	position.X_pos = X_Robot;
	position.Y_pos = Y_Robot;
	position.theta = theta_Robot;
	return position;
}

Heading positionHeadingHandler::GetRobotHeading(void)
{
	Heading heading;
	heading = Comp::ReadComp();
	return heading;
}

//updating the position of the robot
void positionHeadingHandler::SetPosition(RobotPos _position)
{
	X_Robot = _position.X_pos;
	Y_Robot = _position.Y_pos;
	theta_Robot = _position.theta;
}



