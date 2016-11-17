#ifndef MAIN_H
#define MAIN_H
#include "Project_Path.h"
#include RELATIVE_PATH(RobotDevice.h)
#include RELATIVE_PATH(MapHandler.h)

 void Init(RobotDevice& theCleaner, Map& RoomMap);

 void Main_CodeCyclic(RobotDevice& theCleaner, Map& RoomMapid);

#endif
