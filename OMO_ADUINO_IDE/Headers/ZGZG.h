#ifndef ZGZG_H
#define ZGZG_H
#include "types.h"
#include "CONF.h"
#include "positionHandler.h"
#include "MapHandler.h"
#include "GTSP.h"

class ZGZG : public GTSP
{
private:
	static void fixRobotHeading(RobotDevice& theCleaner, enu_Direction_req RobHeadingReq);
public:
	static void ZigZagRoutine(RobotDevice& theCleaner, Map& RoomMap, enu_Direction_req* RobHeadingReq);
};

#endif
