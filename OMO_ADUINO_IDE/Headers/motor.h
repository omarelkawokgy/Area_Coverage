/*
 * motor.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Omar Elkawokgy
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "types.h"
#include "CONF.h"

typedef struct motorPins_S
{
	uint8 motorPositivePin:4;
	uint8 motorGroundPin:4;
}motorPins_T;

typedef enum motorIds_E
{
	LEFT_MOTOR,
	RIGHT_MOTOR
}motorIds_T;

class motor
{
private:
	motorPins_T motorPins;
public:
	motor();

	void assignMotorID(motorIds_T _motorId);

	void stop();
	void forward();
	void backward();
};

#endif /* MOTOR_H_ */
