#ifndef MOVH_H
#define MOVH_H

#include "CONF.h"
#include "Robot.h"

#define FORWARD 1
#define BACKWARD 0

class MOVE
{
private:
	static return_type UpdatePosition(RobotPos* robposition, Heading heading, uint8 Direction);
public:
	MOVE();

	static return_type MoveForward(Robot& rob, Heading heading);

	static return_type MoveBackward(Robot& rob, Heading heading);

	static void MoveStop(Robot& rob);

	static void MoveInitAngle(Robot& rob);

	static void MoveTurn_CW(Robot& rob, const uint16 TargetAngle);

	static void MoveTurn_CCW(Robot& rob, const uint16 TargetAngle);

	static void MoveForwardStep(Robot& rob, Heading heading);

	static void UTurnLeft(Robot& cleaner, Heading RobCurrentHeading);

	static void UTurnRight(Robot& cleaner, Heading RobCurrentHeading);

	static void UTurn(Robot& cleaner, Heading RobCurrentHeading);
};
#endif
