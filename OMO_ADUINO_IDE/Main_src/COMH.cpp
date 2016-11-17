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

Comp& Comp::getInstance(void)
{
	static Comp compass;
	return compass;
}

void Comp::InitializeDirections(void)
{
  NORTH_VALUE = Comp::ReadRawData();
  NORTH_VALUE += Comp::ReadRawData();
  delay(INIT_COMPASS_ANGLE_DELAY_TIME);
  NORTH_VALUE += Comp::ReadRawData();
  NORTH_VALUE += Comp::ReadRawData();
  delay(INIT_COMPASS_ANGLE_DELAY_TIME);
  NORTH_VALUE += Comp::ReadRawData();
  NORTH_VALUE += Comp::ReadRawData();
  NORTH_VALUE /= 5;

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
  uint16 tempAngle;
#ifdef ENABLE_SIMULATION
  cout << "Angle from compass:" << endl;
  cin >> tempAngle;
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
  tempAngle = (uint16)(heading * 180 / M_PI);
  
  
#endif
  return tempAngle;
}

Heading Comp::ReadComp(void)
{

  Heading Angle;
  uint16 tempAngle;

  tempAngle = ReadRawData();

  if(tempAngle < ALLOWED_ANGLE_ERROR)
  {
	  tempAngle = ALLOWED_ANGLE_ERROR;
  }

  if(NORTH_VALUE < ALLOWED_ANGLE_ERROR)
  {
	  NORTH_VALUE = ALLOWED_ANGLE_ERROR;
  }
  else if (WEST_VALUE < ALLOWED_ANGLE_ERROR)
  {
	  WEST_VALUE = ALLOWED_ANGLE_ERROR;
  }
  else if (SOUTH_VALUE < ALLOWED_ANGLE_ERROR)
  {
	  SOUTH_VALUE = ALLOWED_ANGLE_ERROR;
  }
  else if (EAST_VALUE < ALLOWED_ANGLE_ERROR)
  {
	  EAST_VALUE = ALLOWED_ANGLE_ERROR;
  }
  else
  {
	  /* do nothing */
  }



  if ((tempAngle > (NORTH_VALUE - ALLOWED_ANGLE_ERROR)) && (tempAngle < (NORTH_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = NORTH;
  }
  else if ((tempAngle >(WEST_VALUE - ALLOWED_ANGLE_ERROR)) && (tempAngle < (WEST_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = WEST;
  }
  else if ((tempAngle >(SOUTH_VALUE - ALLOWED_ANGLE_ERROR)) && (tempAngle < (SOUTH_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = SOUTH;
  }
  else if ((tempAngle >(EAST_VALUE - ALLOWED_ANGLE_ERROR)) && (tempAngle < (EAST_VALUE + ALLOWED_ANGLE_ERROR)))
  {
    Angle = EAST;
  }
  else
  {
	  Serial.print("the compass reading: ");
	  Serial.println(tempAngle);
    /*TODO handling wrong calling while not being in 4 directions*/
    Angle = INVALID_DIRECTION;
	ERRH::Error_logErrorClass(ERROR_COMH_INVALID_HEADING);
  }
  return Angle;
}

return_type Comp::CheckConnection(void)
{
	return_type ret = RET_NOT_OK;
	uint16 TempAngle = UINT_SNA;
	uint16 CurrentAngle = UINT_SNA;

	TempAngle = Comp::ReadRawData();
	delay(COMPASS_CONNECTION_CHECK_DELAY_TIME);
	CurrentAngle = Comp::ReadRawData();

	if (TempAngle != CurrentAngle)
	{
		ret = RET_OK;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_COMH_COMPASS_NC);
	}
	return ret;
}
