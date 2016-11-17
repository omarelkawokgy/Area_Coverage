/*
 * RobotDevice.h
 *
 *  Created on: Oct 27, 2016
 *      Author: Omar Elkawokgy
 */

#ifndef MAIN_SRC_ROBOTDEVICE_H_
#define MAIN_SRC_ROBOTDEVICE_H_
#include "positionHandler.h"
#include "MOVH.h"
#include "ENCOD.h"
#include "COMH.h"
#include "ULSH.h"
#include "ERRH.h"

class RobotDevice : public positionHeadingHandler, public MOVE,
public ULSH
{
private:

	MOVE movementHandler = MOVE::getInstance();
	ULSH leftUltraSonic = ULSH::getInstanceLeft();
	ULSH rightUltraSonic = ULSH::getInstanceRight();
//	RobotDevice();
public:

	RobotDevice();
	static RobotDevice& getInstance();

	ULSH& rightDistSensor(void);

	ULSH& leftDistSensor(void);

	MOVE& getTheMove(void);

	return_type checkConnection(void);
};

#endif /* MAIN_SRC_ROBOTDEVICE_H_ */
