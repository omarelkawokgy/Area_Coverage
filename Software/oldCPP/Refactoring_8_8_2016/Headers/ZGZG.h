#ifndef ZGZG_H
#define ZGZG_H
#include "types.h"
#include "CONF.h"
#include "Robot.h"
#include "MapHandler.h"
#include "GTSP.h"

class ZGZG:GTSP
{
private:
	static void fixRobotHeading(Robot& cleaner, enu_Direction_req RobHeadingReq);
public:
	static void ZigZagRoutine(Robot& cleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq);
};

#endif
