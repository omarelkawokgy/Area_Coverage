
#include "Main.h"
#include "Project_Path.h"
#include RELATIVE_PATH(RobotDevice.h)
#include RELATIVE_PATH(MapHandler.h)

void setup()
{
          Wire.begin();
        Serial.begin(9600);

  /*=============================Intialize project==============================*/
        
        /*input and output pins*/
        pinMode (RIGHT_MOTOR_POSITIVE_PIN, OUTPUT);
        pinMode (RIGHT_MOTOR_GROUND_PIN, OUTPUT);
        pinMode (LEFT_MOTOR_POSITIVE_PIN, OUTPUT);
        pinMode (LEFT_MOTOR_GROUND_PIN, OUTPUT);
        pinMode (RED_LED_CONNECTION_CHECK_PIN, OUTPUT);
        pinMode (GREEN_LED_RUNNING_PIN, OUTPUT);
        pinMode (BLUE_LED_BLUETOOTH_PIN, OUTPUT);

        pinMode (ENCODER_INTERRUPT_NUMBER, INPUT);

        pinMode(RIGHT_MOTOR_ENABLE_PIN, OUTPUT);
        pinMode(LEFT_MOTOR_ENABLE_PIN,OUTPUT);
}

void loop()
{
  RobotDevice theCleaner = RobotDevice::getInstance();
  Map RoomMap;

  Init(theCleaner, RoomMap);
  while(1)
  {
	  Main_CodeCyclic(theCleaner, RoomMap);
  }
}
