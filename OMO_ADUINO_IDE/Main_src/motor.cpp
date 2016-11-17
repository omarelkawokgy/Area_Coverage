/*
 * motor.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Omar Elkawokgy
 */
#include "Project_Path.h"
#include RELATIVE_PATH(motor.h)

motor::motor()
{

}

void motor::assignMotorID(motorIds_T _motorId)
{
	if(_motorId == LEFT_MOTOR)
	{
		motorPins.motorPositivePin = 10;
		motorPins.motorGroundPin = 9;
	}
	else
	{
		motorPins.motorPositivePin = 6;
		motorPins.motorGroundPin = 5;
	}
}


void motor::stop()
{
	analogWrite(motorPins.motorPositivePin, LOW_PWM);
	analogWrite(motorPins.motorGroundPin, LOW_PWM);
}

void motor::forward()
{
	analogWrite(motorPins.motorPositivePin, HIGH_PWM);
	analogWrite(motorPins.motorGroundPin, LOW_PWM);
}

void motor::backward()
{
	analogWrite(motorPins.motorPositivePin, LOW_PWM);
	analogWrite(motorPins.motorGroundPin, HIGH_PWM);
}
