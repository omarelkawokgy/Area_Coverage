#include "Project_Path.h"
#include RELATIVE_PATH(positionHandler.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(ZGZG.h)
#include RELATIVE_PATH(GTSP.h)
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(RobotDevice.h)
#include RELATIVE_PATH(Bluetooth.h)
#undef PROJECT_PATH_H

/*-----------------------------global variable declaration---------------------------------*/
/*_________FLAGS____________*/
volatile Boolean BumperHit = FALSE;

Boolean ZigZagFlag = FALSE;

Boolean ToStartPoint = TRUE;
/*_________OBJECTS__________*/
enu_Direction_req Direction_req = REQUEST_NORTH;


#if 0
RobotDevice theCleaner = RobotDevice::getInstance();
#endif;

/*-----------------static functions declaration------------------*/
static void ISR_BumperHit(void);

#ifdef DEBUG
static void Map_Print(Map& room);
#endif

//Map& getMap()
//{
//	static Map RoomMap;
//	return RoomMap;
//}
//
//RobotDevice& getRobotDevice()
//{
//	Serial.println("FDBDFDF");
//	static RobotDevice theCleaner;
//	return theCleaner;
//}

void Init(RobotDevice& theCleaner, Map& RoomMap)
{
		digitalWrite(RIGHT_MOTOR_ENABLE_PIN, HIGH);
		digitalWrite(LEFT_MOTOR_ENABLE_PIN, HIGH);

		theCleaner.getCompass();
        theCleaner.InitializeDirections();
        
        Serial.print("NORTH initial value: ");
        Serial.println(NORTH_VALUE);

        Serial.print("WEST initial value: ");
        Serial.println(WEST_VALUE);

        Serial.print("SOUTH initial value: ");
        Serial.println(SOUTH_VALUE);

        Serial.print("EAST initial value: ");
        Serial.println(EAST_VALUE);

        delay(SHOW_4_DIRECTION_VALUES_TIME);
  
	/*pin 0 in interrupt is pin 2 in arduino*/
		attachInterrupt(FRONT_SENSOR_INTERRUPT_NUMBER, ISR_BumperHit, FALLING);

	/*------------------Map Init Data-------------------*/
	
	RoomMap.initMap();

	/*----------------Robot Init Data------------------*/
	RobotPos RobTempPosition = theCleaner.GetRobotPosition();

	if(theCleaner.checkConnection())
	{
		digitalWrite(RED_LED_CONNECTION_CHECK_PIN, HIGH);
	}

	/*=========================Start Implementation=======================*/

	RobTempPosition = theCleaner.GetRobotPosition();
	RoomMap.addRobotOnMap(RobTempPosition.Y_pos, RobTempPosition.X_pos);

	digitalWrite(GREEN_LED_RUNNING_PIN, HIGH);
}

void Main_CodeCyclic(RobotDevice& theCleaner, Map& RoomMap)
{


		/*go to extreme left of map to scan room*/
		GTSP::GoToStartPoint(theCleaner, RoomMap, &Direction_req);

		ZGZG::ZigZagRoutine(theCleaner, RoomMap, &Direction_req);

#ifdef DEBUG
		Map_Print(RoomMap);
#endif

}


void ISR_BumperHit(void)
{
  #ifdef DEBUG
  Serial.println("interrupt hit");
  #endif
  MOVE moveit = MOVE::getInstance();
  moveit.MoveStop();
  BumperHit = TRUE;
  delay(HIT_OBSTICAL_DELAY_TIME);
  moveit.MoveBackward();
  delay(HIT_OBSTICAL_DELAY_TIME);
  moveit.MoveStop();
#ifndef ENABLE_SIMULATION
	/*Stop Robot*/
//	theCleaner.getTheMove().MoveStop();

#endif
}



#ifdef DEBUG
static void Map_Print(Map& map)
{
	for (uint8 i = 0; i < MAP_ROW; i++)
	{
		for (uint8 j = 0; j < MAP_COLUMN; j++)
		{
			Serial.print((int)map.ReadPointFromMap(i,j));
		}
		Serial.println();
	}
	Serial.println();
}
#endif
