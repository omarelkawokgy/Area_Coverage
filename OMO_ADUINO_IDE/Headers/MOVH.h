#ifndef MOVH_H
#define MOVH_H

#include "types.h"
#include "CONF.h"
#include "positionHandler.h"

#ifdef ENABLE_SIMULATION
#include "SIMU.h"
#include <iostream>
#else
#include "motor.h"
#endif

#define FORWARD 1
#define BACKWARD 0

class MOVE : public motor//, public positionHeadingHandler
{
private:
	static return_type UpdatePosition(RobotPos* robposition, Heading heading, uint8 Direction);
	motor leftMotor;
	motor rightMotor;
	positionHeadingHandler& position = positionHeadingHandler::getInstance();
	friend class RobotDevice;
	MOVE();
public:
	positionHeadingHandler& getPosition();

	static MOVE& getInstance();

	return_type MoveForward(Heading heading);

	return_type MoveBackward(Heading heading);

	void MoveStop(positionHeadingHandler& rob);
 
	void MoveStop(void);

	void MoveTurn_CW(positionHeadingHandler& rob, const uint16 TargetAngle);

	void MoveTurn_CCW(positionHeadingHandler& rob, const uint16 TargetAngle);

	void MoveForwardStep(positionHeadingHandler& rob, Heading heading);

	void UTurnLeft(positionHeadingHandler& cleaner, Heading RobCurrentHeading);

	void UTurnRight(positionHeadingHandler& cleaner, Heading RobCurrentHeading);

	void UTurn(positionHeadingHandler& cleaner, Heading RobCurrentHeading);

	void MoveTurn_CCW(void);

	void MoveTurn_CW(void);

	void MoveBackward(void);

	bool fixCurrentHeading(positionHeadingHandler& cleaner, Heading headingRequest);

	void MOVE::CalcSingleStep(positionHeadingHandler& positionOfRobot, Heading headingRequest);

};
#endif
