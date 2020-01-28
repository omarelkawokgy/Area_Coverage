#ifndef MOVH_H
#define MOVH_H

#include "types.h"
#include "CONF.h"
#include "Robot.h"

#ifdef ENABLE_SIMULATION
#include "SIMU.h"
#include <iostream>
#else
#include "ENCOD.h"
#endif


#define FORWARD 1
#define BACKWARD 0

class MOVE
{
private:
	static return_type UpdatePosition(RobotPos* robposition, Heading heading, uint8 Direction);
public:
	MOVE();

	static return_type MoveForward(Robot& rob, Heading heading);

	static void  MoveBackward(Robot& rob);

	static return_type MoveBackward(Robot& rob, Heading heading);

	static void MoveStop(Robot& rob);
 
  static void MoveStop(void);

#if 0
	static void MoveInitAngle(Robot& rob);
#endif
	static void MoveTurn_CW(Robot& rob, const uint16 TargetAngle);

	static void MoveTurn_CCW(Robot& rob, const uint16 TargetAngle);

	static void MoveForwardStep(Robot& rob, Heading heading);

	static void UTurnLeft(Robot& cleaner, Heading RobCurrentHeading);

	static void UTurnRight(Robot& cleaner, Heading RobCurrentHeading);

	static void UTurn(Robot& cleaner, Heading RobCurrentHeading);
#ifndef ENABLE_SIMULATION

  static void SetMotorPins(const uint8 rightMotorPositivePin_value, const  uint8 rightMotorGroundPin_value,
	  const uint8 leftMotorPositivePin_value, const  uint8 leftMotorGroundPin_value);
#endif

};
#endif
