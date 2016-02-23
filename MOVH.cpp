#include <iostream>
#include "MOVH.h"
#include "SIMU.h"
#include "COMH.h"

using namespace std;


MOVE::MOVE()
{

}

return_type MOVE::UpdatePosition(RobotPos* robposition, Heading heading, uint8 Direction)
{
	return_type ret = RET_NOT_OK;
	if (heading != INVALID_DIRECTION)
	{
		if (Direction == FORWARD)
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
		else if (Direction == BACKWARD)
		{
			if (heading == NORTH)
			{
				robposition->Y_pos++;
				ret = RET_OK;
			}
			else if (heading == SOUTH)
			{
				robposition->Y_pos--;
				ret = RET_OK;
			}
			else if (heading == WEST)
			{
				robposition->X_pos++;
				ret = RET_OK;
			}
			else if (heading == EAST)
			{
				robposition->X_pos--;
				ret = RET_OK;
			}
			else
			{
				ret = RET_NOT_OK;
			}
		}
	}
	return ret;
}

return_type MOVE::MoveForward(Robot& rob, Heading heading)
{
#ifdef ENABLE_SIMULATION
	static uint8 Stepcounter = 0;
	return_type Error_Check = RET_NOT_OK; 
	RobotPos robposition = rob.GetRobotPosition();
	Stepcounter++;
	if((Stepcounter % STEP_LINEAR_SCAN) == 0)
	{
		Error_Check = UpdatePosition(&robposition, heading, FORWARD);
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

return_type MOVE::MoveBackward(Robot& rob, Heading heading)
{
#ifdef ENABLE_SIMULATION
	return_type Error_Check = RET_NOT_OK; 
	RobotPos robposition = rob.GetRobotPosition();

		Error_Check = UpdatePosition(&robposition, heading, BACKWARD);
		if (Error_Check == RET_OK)
		{
			rob.UpdateRobotPosition(robposition);
		}
#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
	return Error_Check;
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

void MOVE::MoveTurn_CW(Robot& rob, const uint16 TargetAngle)
{
#ifdef ENABLE_SIMULATION
	RobotPos robPosition = rob.GetRobotPosition();
	robPosition.theta = TargetAngle;
	rob.UpdateRobotPosition(robPosition);
#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
}

void MOVE::MoveTurn_CCW(Robot& rob, const uint16 TargetAngle)
{
#ifdef ENABLE_SIMULATION
	RobotPos robPosition = rob.GetRobotPosition();
	robPosition.theta = TargetAngle;
	rob.UpdateRobotPosition(robPosition);
#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}

void MOVE::MoveForwardStep(Robot& rob, Heading heading)
{
	MoveForward(rob, heading);
}
