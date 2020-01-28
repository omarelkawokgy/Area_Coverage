#ifndef ROBOT_H
#define ROBOT_H

#include "types.h"
#include "CONF.h"

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
	static Robot& initRobotPosition(void);

	//getting position of the robot
	RobotPos GetRobotPosition(void);

	//getting robot heading from compass
	Heading GetRobotHeading(void);

	//updating the position of the robot
	void SetPosition(RobotPos position);

};

#endif
