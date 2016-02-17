#ifndef MOVH_H
#define MOVH_H

#include "CONF.h"
#include "Robot.h"

class MOVE
{
private:
	static return_type UpdatePosition(RobotPos* robposition, Heading heading);
public:
	MOVE();

	static return_type MoveForward(Robot& rob, Heading heading);

	static void MoveBackward(Robot& rob);

	static void MoveStop(Robot& rob);

	static void MoveInitAngle(Robot& rob);

	static void MoveTurn_CW(Robot& rob, const uint16 TargetAngle);

	static void MoveTurn_CCW(Robot& rob, const uint16 TargetAngle);

	static void MoveForwardStep(Robot& rob, Heading heading);
};
#endif
