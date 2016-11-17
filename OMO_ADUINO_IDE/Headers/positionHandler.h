#ifndef ROBOT_H
#define ROBOT_H

#include "types.h"
#include "CONF.h"
#include "ENCOD.h"
#include "COMH.h"

class positionHeadingHandler : public Comp, public right_encoder
{
private:
	uint8 X_Robot;
	uint8 Y_Robot;
	uint16 theta_Robot;
	friend class MOVH;
	Comp compass = Comp::getInstance();
	right_encoder encoder = right_encoder::getInstance();
protected:
	//default constructor
	positionHeadingHandler(uint8 _X_Robot = ROBOT_INIT_X,uint8  _Y_Robot = ROBOT_INIT_Y,uint16 _theta_Robot = ROBOT_INIT_THETA);

	//robot constructor singleton
	positionHeadingHandler(RobotPos position);
public:
	right_encoder& getRightEncoder();

	Comp& getCompass();
	//initial position where the robot starts its corrdinate and bearing
	static positionHeadingHandler& getInstance(void);

	//getting position of the robot
	RobotPos GetRobotPosition(void);

	//getting robot heading from compass
	Heading GetRobotHeading(void);

	//updating the position of the robot
	void SetPosition(RobotPos position);

};

#endif
