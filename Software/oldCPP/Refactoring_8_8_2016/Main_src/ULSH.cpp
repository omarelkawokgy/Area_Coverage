#include "Project_Path.h"
#include RELATIVE_PATH(ULSH.h)
#undef PROJECT_PATH_H
#ifdef ENABLE_SIMULATION
#include <iostream>
using namespace std;
#endif

/*Declaration of static funtions*/
static uint16 initSensor (uint8 pin);
static uint16 Read_distance(uint8 Pin);

/*Implementation of macro functions*/
#define MICRO_SECONDS_TO_CM(X) X / 29.4118 / 2

ULSH::ULSH()
{

}

static uint16 Read_distance(uint8 Pin)
{
	return initSensor(Pin);
}

static uint16 initSensor (uint8 pin)
{
  /* the ultrasonic is triggered by a HIGH pulse of 2 or more microseconds 
   so give a short LOW pulse beforehand to ensure a clean HIGH pulse*/
  pinMode(pin, OUTPUT);
  
  digitalWrite(pin, LOW);
  delayMicroseconds(3);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);

  /* read the signal from the sensor*/
  pinMode(pin, INPUT);

  uint32 duration = pulseIn(pin, HIGH);

  /* convert micro-seconds to centimeters*/
  return MICRO_SECONDS_TO_CM(duration);
}

uint16 ULSH::ULS_getLeftDist(void)
{
	uint16 left = 0;
#ifdef ENABLE_SIMULATION
	cout << "Left distance:" << endl;
	cin >> left;
#else
	/*take about 3 readings evrytime and return the average*/
	left = Read_distance(LEFT_SENSOR_PIN);
	left += Read_distance(LEFT_SENSOR_PIN);
	left += Read_distance(LEFT_SENSOR_PIN);

	left = (uint16)(left / 3);
#endif
	if (left < ROBOT_SIZE)
	{
		left = ROBOT_SIZE;
	}
	left = (uint16)(left / ROBOT_SIZE);
	return left;
}

uint16 ULSH::ULS_getRightDist(void)
{
	uint16 right = 0;
#ifdef ENABLE_SIMULATION
	cout << "right distance:" << endl;
	cin >> right;
#else
	/*take about 3 readings evrytime and return the average*/
	right = Read_distance(RIGHT_SENSOR_PIN);
	right += Read_distance(RIGHT_SENSOR_PIN);
	right += Read_distance(RIGHT_SENSOR_PIN);

	right = (uint16)(right / 3);
#endif
	if (right < ROBOT_SIZE)
	{
		right = ROBOT_SIZE;
	}
	right = (uint16)(right / ROBOT_SIZE);
	return right;
}

L_R_Dist ULSH::ULS_getDistanceboth(void)
{
	L_R_Dist both;
	both.L_Distance = ULSH::ULS_getLeftDist();
	both.R_Distance = ULSH::ULS_getRightDist();
	return both;
}
