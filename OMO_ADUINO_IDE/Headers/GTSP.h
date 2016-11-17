#ifndef GTSP_H
#define GTSP_H
#include "types.h"
#include "CONF.h"
#include "positionHandler.h"
#include "MapHandler.h"
#include "RobotDevice.h"

class GTSP
{
private:

protected:
	/*Bumper hit sensor view tell me when i hit an object the left and right situations on the map*/
	static SensorsReadings BumperHitSensorsView(positionHeadingHandler& rob, Map& RoomMap, enu_Direction_req RobHeadingReq);
public:
	static void GoToStartPoint(RobotDevice& theCleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq);
};

#endif
