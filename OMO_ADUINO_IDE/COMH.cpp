#include "Project_Path.h"
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(ERRH.h)
#undef PROJECT_PATH_H

#ifdef ENABLE_SIMULATION
#include<iostream>
using namespace std;
#else
static HMC5883L Compass;

#endif

 /*values of directions*/
uint16 NORTH_VALUE = 0;
uint16 WEST_VALUE = 0;
uint16 SOUTH_VALUE = 0;
uint16 EAST_VALUE = 0;

Comp::Comp()
{
	Compass = HMC5883L();

	Serial.println("setting scale to +/- 2.0 Ga");
	int error = Compass.SetScale(0.88);

	error = Compass.SetMeasurementMode(Measurement_Continuous);
	if (error != 0)
	{
		Serial.println(Compass.GetErrorText(error));
		ERRH::Error_logErrorClass(ERROR_COMH_MEASURE_FAIL);
	}
}

void Comp::InitializeDirections(void)
{
  NORTH_VALUE = Comp::ReadRawData();

  WEST_VALUE = NORTH_VALUE + 90;
  if(WEST_VALUE > 360)
  {
    /*Handle plus 90 greater than 360*/
    WEST_VALUE -= 360;
  }

  SOUTH_VALUE = WEST_VALUE + 90;
  if(SOUTH_VALUE > 360)
  {
    /*Handle plus 90 greater than 360*/
    SOUTH_VALUE -= 360; 
  }

  EAST_VALUE = SOUTH_VALUE + 90;
  if(EAST_VALUE > 360)
  {
    /*Handle plus 90 greater than 360*/
    EAST_VALUE -= 360;     
  }
  
}

uint16 Comp::ReadRawData(void)
{
  uint16 Temp_angle;
#ifdef ENABLE_SIMULATION
  cout << "Angle from compass:" << endl;
  cin >> Temp_angle;
#else
/* CONNECTION PINS FOR THIS ARE A5 PIN (I2C PIN) >> SCL ..... A4 PIN (I2C PIN) >> SCA */
    //raw data so its not scaled
  MagnetometerRaw raw = Compass.ReadRawAxis();
  
  MagnetometerScaled scaled = Compass.ReadScaledAxis();

  float heading = atan2(raw.YAxis, raw.XAxis);

  if (heading < 0)
  {
    heading += 2 * PI;
  }

  //convert radians to degrees
  Temp_angle = (uint16)(heading * 180 / M_PI);
  
  
#endif
#ifdef DEBUG
Serial.print("read compass: ");
Serial.println(Temp_angle);
#endif

  return Temp_angle;
}

Heading Comp::ReadComp(void)
{

  Heading Angle;
  uint16 Temp_angle;

  Temp_angle = ReadRawData();

  if ((Temp_angle > (NORTH_VALUE - ALLOWED_ANGLE_ERROR)) && (Temp_angle < (NORTH_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = NORTH;
  }
  else if ((Temp_angle >(WEST_VALUE - ALLOWED_ANGLE_ERROR)) && (Temp_angle < (WEST_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = WEST;
  }
  else if ((Temp_angle >(SOUTH_VALUE - ALLOWED_ANGLE_ERROR)) && (Temp_angle < (SOUTH_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = SOUTH;
  }
  else if ((Temp_angle >(EAST_VALUE - ALLOWED_ANGLE_ERROR)) && (Temp_angle < (EAST_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = EAST;
  }
  else
  {
    /*TODO handling wrong calling while not being in 4 directions*/
    Angle = INVALID_DIRECTION;
	ERRH::Error_logErrorClass(ERROR_COMH_INVALID_HEADING);
  }
  return Angle;
}

