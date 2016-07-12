#include "MOVH.h"
#ifdef ENABLE_SIMULATION
#include "SIMU.h"
#include <iostream>
#else
#include "Arduino.h"
#include "ENCOD.h"
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
	if (BumperHit == FALSE)
	{
		MoveForwardStep(rob, heading);
	}
#ifdef ENABLE_SIMULATION

#else

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
		return Error_Check;
#else
#ifdef DEBUG
Serial.print("movebackward");
#endif
	MOVE::SetMotorPins(LOW_PWM, HIGH_PWM, LOW_PWM, HIGH_PWM);
	return Error_Check = RET_OK;
#endif
	
}

void MOVE::MoveStop(Robot& rob)
{
#ifdef ENABLE_SIMULATION

#else
#ifdef DEBUG 
Serial.println("stop");
#endif
	MOVE::SetMotorPins(LOW_PWM, LOW_PWM, LOW_PWM, LOW_PWM);
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
	RobotPos robPosition = rob.GetRobotPosition();
#ifdef ENABLE_SIMULATION
	
	robPosition.theta = TargetAngle;
	rob.SetPosition(robPosition);
#else
	MOVE::SetMotorPins(LOW_PWM, HIGH_PWM, HIGH_PWM, LOW_PWM);

	while ((robPosition.theta < (TargetAngle - ALLOWED_ANGLE_ERROR)) || (robPosition.theta >(TargetAngle + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: timer in case angle didnt reach*/
		robPosition.theta = rob.GetRobotPosition().theta;
	}
	rob.SetPosition(robPosition);
#endif
}

void MOVE::MoveTurn_CCW(Robot& rob, const uint16 TargetAngle)
{
	RobotPos robPosition = rob.GetRobotPosition();
#ifdef ENABLE_SIMULATION

	robPosition.theta = TargetAngle;
	rob.SetPosition(robPosition);
#else
	MOVE::SetMotorPins(HIGH_PWM, LOW_PWM, LOW_PWM, HIGH_PWM);

	while ((robPosition.theta < (TargetAngle - ALLOWED_ANGLE_ERROR)) || (robPosition.theta >(TargetAngle + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: timer in case angle didnt reach*/
		robPosition.theta = rob.GetRobotPosition().theta;
	}
	rob.SetPosition(robPosition);
#endif
}

void MOVE::MoveForwardStep(Robot& rob, Heading heading)
{
	/*TODO: handle crashing before continuing this step*/
	/*the robot will stop as it hits an object to need to handle it here*/

	Boolean StepComplete = FALSE;
	RobotPos robposition = rob.GetRobotPosition();
	return_type Error_Check = RET_NOT_OK;
#ifdef ENABLE_SIMULATION
	
	Stepcounter++;
	if ((Stepcounter % STEP_LINEAR_SCAN) == 0)
	{
#else
#ifdef DEBUG
  Serial.println("move forward step");
#endif
	MOVE::SetMotorPins(HIGH_PWM, LOW_PWM, HIGH_PWM, LOW_PWM);

	StepComplete = right_encoder::read_right_encoder_ticks();

		/*TODO: timer in case counter didnt reach*/


#endif
	Error_Check = UpdatePosition(&robposition, heading, FORWARD);
	if (Error_Check == RET_OK)
	{
			rob.SetPosition(robposition);
	}
#ifdef ENABLE_SIMULATION
}
#endif


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

Boolean MOVE::CheckConnection(const Boolean CW_CHECK_VAR)
{
  Boolean ret = RET_NOT_OK;
  if(CW_CHECK_VAR == CW_CHECK)
  {
  MOVE::SetMotorPins(LOW_PWM, HIGH_PWM, HIGH_PWM, LOW_PWM);
  ret = RET_OK;
  }
  else
  {
  MOVE::SetMotorPins(HIGH_PWM, LOW_PWM, LOW_PWM, HIGH_PWM);
  ret = RET_OK;
  }
  
  return ret;
}

void MOVE::MoveStop(void)
{
  MOVE::SetMotorPins(LOW_PWM, LOW_PWM, LOW_PWM, LOW_PWM);
}


#ifndef ENABLE_SIMULATION
void MOVE::SetMotorPins(const uint8 rightMotorPositivePin_value, const uint8 rightMotorGroundPin_value,
	const uint8 leftMotorPositivePin_value, const uint8 leftMotorGroundPin_value)
{
	analogWrite(RIGHT_MOTOR_POSITIVE_PIN, rightMotorPositivePin_value);
	analogWrite(RIGHT_MOTOR_GROUND_PIN, rightMotorGroundPin_value);
	analogWrite(LEFT_MOTOR_POSITIVE_PIN, leftMotorPositivePin_value);
	analogWrite(LEFT_MOTOR_GROUND_PIN, leftMotorGroundPin_value);
}
#endif