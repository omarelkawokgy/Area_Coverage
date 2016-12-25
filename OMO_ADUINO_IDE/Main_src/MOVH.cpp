#include "Project_Path.h"
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(Main_Func_1.h)
#undef PROJECT_PATH_H
#ifdef ENABLE_SIMULATION
using namespace std;
#endif


MOVE::MOVE()
{
	leftMotor.assignMotorID(LEFT_MOTOR);
	rightMotor.assignMotorID(RIGHT_MOTOR);
}

MOVE& MOVE::getInstance(void)
{
	static MOVE movementHandler;
	return movementHandler;
}

positionHeadingHandler& MOVE::getPosition(void)
{
	return position;
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
				ERRH::Error_logErrorClass(ERROR_MOVE_MOVEFORWARD_FAIL);
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
				ERRH::Error_logErrorClass(ERROR_MOVE_MOVEBACKWARD_FAIL);
			}
		}
	}
	return ret;
}

return_type MOVE::MoveForward(Heading heading)
{
	return_type Error_Check = RET_NOT_OK;
	if (BumperHit == FALSE)
	{
		MOVE::MoveForwardStep(MOVE::getPosition(), heading);
		Error_Check = RET_OK;
	}
	else
	{
		MOVE::stop();
		ERRH::Error_logErrorClass(ERROR_MOVE_MOVEFORWARD_FAIL);
	}
#ifdef ENABLE_SIMULATION

#else

#endif
	return Error_Check;
}

return_type MOVE::MoveBackward(Heading heading)
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
Serial.println("movebackward");
#endif

	rightMotor.backward();
	leftMotor.backward();
	return Error_Check = RET_OK;
#endif
	
}

void MOVE::MoveStop(positionHeadingHandler& rob)
{
#ifdef ENABLE_SIMULATION

#else
	leftMotor.stop();
	rightMotor.stop();
#endif
}

void MOVE::MoveTurn_CW(positionHeadingHandler& rob, const uint16 TargetAngle)
{
	RobotPos robPosition = rob.GetRobotPosition();
	uint64 timer = UINT_SNA;
	uint64 timer_comparator = UINT_SNA;
#ifdef ENABLE_SIMULATION
	
	robPosition.theta = TargetAngle;
	rob.SetPosition(robPosition);
#else
	rightMotor.backward();
	leftMotor.forward();

	timer = millis();
	while ((robPosition.theta < (TargetAngle - ALLOWED_ANGLE_ERROR)) || (robPosition.theta >(TargetAngle + ALLOWED_ANGLE_ERROR)))
	{
		timer_comparator = millis();
		if (timer_comparator >= (timer + (MS_SCALE * TIME_OF_TURN_SECONDS)))
		{
			Serial.println("too much time spent in spinning");
			break;
		}

		robPosition.theta = rob.ReadRawData();
	}
	rob.SetPosition(robPosition);
#endif
}

void MOVE::MoveTurn_CCW(positionHeadingHandler& rob, const uint16 TargetAngle)
{
#define USING_PID_CONTROLLER
#ifdef USING_PID_CONTROLLER
#define TAWO_P 0.2
#define TAWO_D 2.5
#define TAWO_I 0.004
	Serial.print("CCW");
	Serial.println(callFunction);
	RobotPos robPosition = rob.GetRobotPosition();
	uint64 timer = UINT_SNA;
	uint64 timer_comparator = UINT_SNA;

	double PID_error = 1000;
	double PWM_input = 0;
	double PID_error_difference = 0;
	double PID_error_sum = 0;

	//30% of power in turning


	robPosition.theta = rob.getCompass().ReadRawData();
	timer = millis();
	while (((int)robPosition.theta < ((int)TargetAngle - ALLOWED_ANGLE_ERROR)) || (robPosition.theta > (TargetAngle + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: timer in case angle didnt reach*/
		timer_comparator = millis();
		if (timer_comparator >= (timer + (MS_SCALE * TIME_OF_TURN_SECONDS)))
		{
			Serial.println("too much time spent in spinning");
			break;
		}
		robPosition.theta = rob.getCompass().ReadRawData();
		PID_error_difference -= PID_error;
		PID_error_sum += PID_error;

		PID_error = robPosition.theta - TargetAngle;
		if(PID_error < 0)
		{
			PID_error = (robPosition.theta + 360) - TargetAngle;
		}
		PWM_input = TAWO_P * PID_error + TAWO_D * PID_error_difference + TAWO_I * PID_error_sum;	
		rightMotor.forward(40);
		leftMotor.backward(40);
	}
	rob.SetPosition(robPosition);
#else
	Serial.print("CCW");
	Serial.println(callFunction);
	RobotPos robPosition = rob.GetRobotPosition();
	uint64 timer = UINT_SNA;
	uint64 timer_comparator = UINT_SNA;

	//30% of power in turning
	rightMotor.forward(40);
	leftMotor.backward(40);

	robPosition.theta = rob.getCompass().ReadRawData();
	timer = millis();
	while (((int)robPosition.theta < ((int)TargetAngle - ALLOWED_ANGLE_ERROR)) || (robPosition.theta > (TargetAngle + ALLOWED_ANGLE_ERROR)))
	{
		/*TODO: timer in case angle didnt reach*/
		timer_comparator = millis();
		if (timer_comparator >= (timer + (MS_SCALE * TIME_OF_TURN_SECONDS)))
		{
			Serial.println("too much time spent in spinning");
			break;
		}
		robPosition.theta = rob.getCompass().ReadRawData();
		Serial.print("current angle: ");
		Serial.println(robPosition.theta);
		Serial.print("Target angle: ");
		Serial.println(TargetAngle);
		Serial.print("Error: ");
		Serial.println(ALLOWED_ANGLE_ERROR);
	}
	rob.SetPosition(robPosition);
#endif
}

void MOVE::CalcSingleStep(positionHeadingHandler& positionOfRobot, Heading headingRequest)
{
	uint16 current_encoder_status = UINT_SNA;
	uint16 counter_ticks = UINT_SNA;
	uint64 currentTime = UINT_SNA;
	uint8 numberOfFixes = UINT_SNA;

	currentTime = millis();
	while (((counter_ticks < ROBOT_SINGLE_STEP) && (BumperHit == FALSE))
			&& ((millis() - currentTime) < FORWARD_SINGLE_STEP_TIMEOUT_VALUE))
	{
		current_encoder_status = positionOfRobot.getRightEncoder().read_right_encoder_ticks();

		while ((CHECK_IF_HIGH(current_encoder_status)) && (BumperHit == FALSE)
				&& ((millis() - currentTime) < FORWARD_SINGLE_STEP_TIMEOUT_VALUE))
		{
			current_encoder_status = positionOfRobot.getRightEncoder().read_right_encoder_ticks();
			if (CHECK_IF_LOW(current_encoder_status))
			{
				counter_ticks++;
			}
		}

		if(MOVE::fixCurrentHeading(positionOfRobot, headingRequest))
		{
			numberOfFixes++;
			currentTime = millis();
		}

		if(numberOfFixes >= MAX_NUMBER_OF_DIRECTION_FIXES)
		{
			break;
		}
	}

	if (counter_ticks < ROBOT_SINGLE_STEP)
	{
		ERRH::Error_logErrorClass(WARNING_ENCOD_NOT_COMPLETE_STEP);
	}
}

void MOVE::MoveForwardStep(positionHeadingHandler& positionOfRobot, Heading headingRequest)
{
	/*TODO: handle crashing before continuing this step*/
	/*the robot will stop as it hits an object to need to handle it here*/


	RobotPos robposition = positionOfRobot.GetRobotPosition();
	return_type Error_Check = RET_NOT_OK;

#ifdef ENABLE_SIMULATION
	
	Stepcounter++;
	if ((Stepcounter % STEP_LINEAR_SCAN) == 0)
	{
#else
	  rightMotor.forward();
	  leftMotor.forward();

	  MOVE::CalcSingleStep(positionOfRobot, headingRequest);
		/*TODO: timer in case counter didnt reach*/
#endif
	Error_Check = UpdatePosition(&robposition, headingRequest, FORWARD);
	if (Error_Check == RET_OK)
	{
			positionOfRobot.SetPosition(robposition);
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_MOVE_UPDATE_POSITION);
	}
#ifdef ENABLE_SIMULATION
}
#endif


}

void MOVE::UTurnRight(positionHeadingHandler& cleaner, Heading HeadingRequest)
{
	switch (HeadingRequest)
	{
	case NORTH:
		MOVE::MoveTurn_CW(cleaner, EAST_VALUE);
		HeadingRequest = EAST;
		MOVE::MoveForwardStep(getPosition(), HeadingRequest);
		MOVE::MoveTurn_CW(getPosition(), SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(getPosition(), NORTH_VALUE);
		HeadingRequest = NORTH;
		MOVE::MoveForwardStep(getPosition(), HeadingRequest);
		MOVE::MoveTurn_CW(getPosition(), EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(getPosition(), WEST_VALUE);
		HeadingRequest = WEST;
		MOVE::MoveForwardStep(getPosition(), HeadingRequest);
		MOVE::MoveTurn_CW(getPosition(), NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(getPosition(), SOUTH_VALUE);
		HeadingRequest = SOUTH;
		MOVE::MoveForwardStep(getPosition(), HeadingRequest);
		MOVE::MoveTurn_CW(getPosition(), WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnRight >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		ERRH::Error_logErrorClass(ERROR_MOVE_UT_RIGHT_DEFAULT_CASE);
		MOVE::MoveStop(getPosition());
		break;
	}
}

void MOVE::UTurnLeft(positionHeadingHandler& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(getPosition(), WEST_VALUE);
		RobCurrentHeading = WEST;
		MOVE::MoveForwardStep(getPosition(), RobCurrentHeading);
		MOVE::MoveTurn_CW(getPosition(), SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(getPosition(), SOUTH_VALUE);
		RobCurrentHeading = SOUTH;
		MOVE::MoveForwardStep(getPosition(), RobCurrentHeading);
		MOVE::MoveTurn_CW(getPosition(), EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(getPosition(), EAST_VALUE);
		RobCurrentHeading = EAST;
		MOVE::MoveForwardStep(getPosition(), RobCurrentHeading);
		MOVE::MoveTurn_CW(getPosition(), NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(getPosition(), NORTH_VALUE);
		RobCurrentHeading = NORTH;
		MOVE::MoveForwardStep(getPosition(), RobCurrentHeading);
		MOVE::MoveTurn_CW(getPosition(), WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurnLeft >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		ERRH::Error_logErrorClass(ERROR_MOVE_UT_LEFT_DEFAULT_CASE);
		MOVE::MoveStop(getPosition());
		break;
	}
}

void MOVE::UTurn(positionHeadingHandler& cleaner, Heading RobCurrentHeading)
{
	switch (RobCurrentHeading)
	{
	case NORTH:
		MOVE::MoveTurn_CW(getPosition(), SOUTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> SOUTH" << endl;
#endif
		break;
	case WEST:
		MOVE::MoveTurn_CW(getPosition(), EAST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> EAST" << endl;
#endif
		break;
	case SOUTH:
		MOVE::MoveTurn_CW(getPosition(), NORTH_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> NORTH" << endl;
#endif
		break;
	case EAST:
		MOVE::MoveTurn_CW(getPosition(), WEST_VALUE);
#ifdef ENABLE_SIMULATION
		cout << "UTurn >> WEST" << endl;
#endif
		break;
	default:
		/*TODO: heading is invalid*/
		ERRH::Error_logErrorClass(ERROR_MOVE_UT_DEFAULT_CASE);
		MOVE::MoveStop();
		break;
	}
}

void MOVE::MoveTurn_CW(void)
{
	leftMotor.forward();
	rightMotor.backward();
}

void MOVE::MoveTurn_CCW(void)
{
	leftMotor.backward();
	rightMotor.forward();
}

void MOVE::MoveStop(void)
{
	leftMotor.stop();
	rightMotor.stop();
}

void MOVE::MoveBackward(void)
{
	leftMotor.backward();
	rightMotor.backward();
}

bool MOVE::fixCurrentHeading(positionHeadingHandler& cleaner, Heading headingRequest)
{
	Heading robotCurrentHeading = INVALID_DIRECTION;
	robotCurrentHeading = cleaner.GetRobotHeading();
	uint16 tempRequestedAngle = UINT_SNA;
	bool validDirectionHeadingFlag = FALSE;

	if(headingRequest != robotCurrentHeading)
	{
		if(headingRequest == NORTH)
		{
			tempRequestedAngle = NORTH_VALUE;
		}
		else if(headingRequest == SOUTH)
		{
			tempRequestedAngle = SOUTH_VALUE;
		}
		else if(headingRequest == SOUTH)
		{
			tempRequestedAngle = SOUTH_VALUE;
		}
		else if(headingRequest == SOUTH)
		{
			tempRequestedAngle = SOUTH_VALUE;
		}
		/* TODO: go for the shortest turn instead of always CCW*/
		MOVE::MoveTurn_CCW(cleaner, tempRequestedAngle);
		validDirectionHeadingFlag = TRUE;
	}
return validDirectionHeadingFlag;
}
