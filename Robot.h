#ifndef ROBOT_H
#define ROBOT_H

#include "types.h"

#define INTIAL_X 0
#define INTIAL_Y 0
#define INTIAL_THETA 0

class Robot
{
private:
	uint8 X_Robot;
	uint8 Y_Robot;
	uint16 theta_Robot;

	//default constructor
	Robot(){}

	//robot constructor singleton
	Robot(RobotPos position);
public:

	//initial position where the robot starts its corrdinate and bearing
	static Robot& initRobotPosition(RobotPos position);

	//getting position of the robot
	RobotPos GetRobotPosition(void);

	//updating the position of the robot
	void UpdateRobotPosition(RobotPos* position);

};

#endif
