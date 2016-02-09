#include <iostream>
#include "MOVH.h"
#include "SIMU.h"
#include "COMH.h"

using namespace std;


MOVE::MOVE()
{

}

return_type MOVE::UpdatePosition(RobotPos* robposition)
{
	return_type ret = RET_NOT_OK;
	Heading heading = Comp::ReadComp(robposition->theta);
	if (heading != INVALID_DIRECTION)
	{
		if (heading == NORTH)
		{
			robposition->Y_pos--;
			ret = RET_OK;
		}
		else if (heading == SOUTH)
		{
			robposition->Y_pos++;
			ret = RET_OK;
		}
		else if (heading == WEST)
		{
			robposition->X_pos--;
			ret = RET_OK;
		}
		else if (heading == EAST)
		{
			robposition->X_pos++;
			ret = RET_OK;
		}
		else
		{
			ret = RET_NOT_OK;
		}
	}
	return ret;
}

return_type MOVE::MoveForward(Robot& rob)
{
#ifdef ENABLE_SIMULATION
	static uint8 Stepcounter = 0;
	return_type Error_Check = RET_NOT_OK; 
	RobotPos robposition = rob.GetRobotPosition();
	Stepcounter++;
	if((Stepcounter % 3) == 0)
	{
		Error_Check = UpdatePosition(&robposition);
		if (Error_Check == RET_OK)
		{
			rob.UpdateRobotPosition(robposition);
		}
	}
#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
	return Error_Check;
}

void MOVE::MoveBackward(Robot& rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}

void MOVE::MoveStop(Robot& rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
}

void MOVE::MoveInitAngle(Robot& rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, );
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, );
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, );
	digitalWrite(LEFT_MOTOR_GROUND_PIN, );
#endif
}

void MOVE::MoveTurn_CW(Robot& rob, uint8 TargetAngle)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
}

void MOVE::MoveTurn_CCW(Robot& rob, uint8 TargetAngle)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}
