#include <iostream>
#include "MOVH.h"
#ifdef ENABLE_SIMULATION
#include "SIMU.h"
#endif
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
	return_type Error_Check = RET_NOT_OK; 
#ifdef ENABLE_SIMULATION
	static uint8 Stepcounter = 0;

	RobotPos robposition = rob.GetRobotPosition();
	Stepcounter++;
	if((Stepcounter % STEP_LINEAR_SCAN) == 0)
	{
		Error_Check = UpdatePosition(&robposition, heading, FORWARD);
		if (Error_Check == RET_OK)
		{
			rob.SetPosition(robposition);
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
	return_type Error_Check = RET_NOT_OK; 
#ifdef ENABLE_SIMULATION
	
	RobotPos robposition = rob.GetRobotPosition();

		Error_Check = UpdatePosition(&robposition, heading, BACKWARD);
		if (Error_Check == RET_OK)
		{
			rob.SetPosition(robposition);
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

#if 0
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
#endif

void MOVE::MoveTurn_CW(Robot& rob, const uint16 TargetAngle)
{
#ifdef ENABLE_SIMULATION
	RobotPos robPosition = rob.GetRobotPosition();
	robPosition.theta = TargetAngle;
	rob.SetPosition(robPosition);
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
	rob.SetPosition(robPosition);
#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}

void MOVE::MoveForwardStep(Robot& rob, Heading heading)
{
	/*TODO: handle crashing before continuing this step*/
	/*the robot will stop as it hits an object to need to handle it here*/
#ifdef ENABLE_SIMULATION

#else

#endif
	MoveForward(rob, heading);
}

void MOVE::UTurnRight(Robot& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		RobCurrentHeading = EAST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
		RobCurrentHeading = NORTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
		RobCurrentHeading = WEST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
		RobCurrentHeading = SOUTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		MOVE::MoveStop(cleaner);
		break;
	}
}

void MOVE::UTurnLeft(Robot& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
		RobCurrentHeading = WEST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
		RobCurrentHeading = SOUTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		RobCurrentHeading = EAST;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
		RobCurrentHeading = NORTH;
		MOVE::MoveForwardStep(cleaner, RobCurrentHeading);
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		MOVE::MoveStop(cleaner);
		break;
	}
}

void MOVE::UTurn(Robot& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(cleaner, NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(cleaner, WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		MOVE::MoveStop(cleaner);
		break;
	}
}
