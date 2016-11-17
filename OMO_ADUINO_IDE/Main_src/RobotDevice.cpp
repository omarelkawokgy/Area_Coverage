/*
 * RobotDevice.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: Omar Elkawokgy
 */
#include "Project_Path.h"
#include RELATIVE_PATH(RobotDevice.h)

  RobotDevice::RobotDevice()
{

}

RobotDevice& RobotDevice::getInstance()
{
	static RobotDevice theCleaner;
	return theCleaner;
}

return_type RobotDevice::checkConnection()
{
	return_type ErrorCheck = RET_OK;

	getTheMove().MoveTurn_CW();
	ErrorCheck &= getRightEncoder().checkConnection();
	ErrorCheck &= Comp::CheckConnection();
	delay(MOTOR_CONNECTION_CHECK_DELAY_TIME - COMPASS_CONNECTION_CHECK_DELAY_TIME);
	getTheMove().MoveTurn_CCW();
	delay(MOTOR_CONNECTION_CHECK_DELAY_TIME);
	getTheMove().MoveStop();
	ErrorCheck &= ULSH::CheckConnnection();

	return ErrorCheck;
}

MOVE& RobotDevice::getTheMove(void)
{
	return movementHandler;
}

ULSH& RobotDevice::leftDistSensor(void)
{
	return leftUltraSonic;
}

ULSH& RobotDevice::rightDistSensor(void)
{
	return rightUltraSonic;
}
