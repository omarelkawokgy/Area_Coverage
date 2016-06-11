#include <HMC5883L.h>



#include "COMH.h"
#ifdef ENABLE_SIMULATION
#include<iostream>
using namespace std;
#else
HMC5883L Compass;
#endif

Comp::Comp()
{

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
  Temp_angle = heading * 180 / M_PI;
  //Serial.println(headingDegrees);

  return Temp_angle;
  //  Serial.println(" Degrees   \t");
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
  }
  return Angle;
}

