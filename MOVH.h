#ifndef MOVH_H
#define MOVH_H

#include "CONF.h"
#include "Robot.h"

class MOVE
{
private:
	static return_type UpdatePosition(RobotPos* robposition);
public:
	MOVE();

	static void MoveForward(Robot& rob);

	static void MoveBackward(Robot& rob);

	static void MoveStop(Robot& rob);

	static void MoveInitAngle(Robot& rob);

	static void MoveTurn_CW(Robot& rob, uint8 TargetAngle);

	static void MoveTurn_CCW(Robot& rob, uint8 TargetAngle);

};
#endif
