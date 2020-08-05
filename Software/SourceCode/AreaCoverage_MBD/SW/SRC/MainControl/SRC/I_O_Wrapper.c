#include "I_O_Wrapper.h"

#ifndef MATLAB_MEX_FILE

#define MICRO_SECONDS_TO_CM(X) X / 29.4118 / 2
#define PULSEIN_TIMEOUT 100000 //100ms

void HMC5883L_CompassRead(int16_t *Temp_angle)
{
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
  *Temp_angle = (int16_T)(heading * 180 / M_PI);
}

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm)
{
  pinMode(ULSL_Pin, OUTPUT);
  
  digitalWrite(ULSL_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(ULSL_Pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ULSL_Pin, LOW);

  /* read the signal from the sensor*/
  pinMode(ULSL_Pin, INPUT);

  uint32_t duration = pulseIn(ULSL_Pin, HIGH, PULSEIN_TIMEOUT);

  /* convert micro-seconds to centimeters*/
  *ULSL_cm = (uint16_t)MICRO_SECONDS_TO_CM(duration);
}

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm)
{
  pinMode(ULSR_Pin, OUTPUT);
  
  digitalWrite(ULSR_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(ULSR_Pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ULSR_Pin, LOW);

  /* read the signal from the sensor*/
  pinMode(ULSR_Pin, INPUT);

  uint32_t duration = pulseIn(ULSR_Pin, HIGH, PULSEIN_TIMEOUT);

  /* convert micro-seconds to centimeters*/
  *ULSR_cm = (uint16_t)MICRO_SECONDS_TO_CM(duration);
}

#else
	
void HMC5883L_CompassRead(int16_t *Temp_angle)
{
*Temp_angle = 10;
}

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm)
{
  *ULSL_cm = 2;
}

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm)
{
  *ULSR_cm = 1;
}

#endif