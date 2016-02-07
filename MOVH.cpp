#include <iostream>
#include "MOVH.h"

using namespace std;


MOVE::MOVE()
{

}

void MOVE::MoveForward(Robot* rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif

}

void MOVE::MoveBackward(Robot* rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}

void MOVE::MoveStop(Robot* rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
}

void MOVE::MoveInitAngle(Robot* rob)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, );
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, );
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, );
	digitalWrite(LEFT_MOTOR_GROUND_PIN, );
#endif
}

void MOVE::MoveTurn_CW(Robot* rob, uint8 TargetAngle)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, LOW);
#endif
}

void MOVE::MoveTurn_CCW(Robot* rob, uint8 TargetAngle)
{
#ifdef ENABLE_SIMULATION

#else
	digitalWrite(RIGHT_MOTOR_POSITIVE_PIN, HIGH);
	digitalWrite(RIGHT_MOTOR_GROUND_PIN, LOW);
	digitalWrite(LEFT_MOTOR_POSITIVE_PIN, LOW);
	digitalWrite(LEFT_MOTOR_GROUND_PIN, HIGH);
#endif
}
