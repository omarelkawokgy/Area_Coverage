#include "I_O_Wrapper.h"

#ifdef MATLAB_MEX_FILE
//Calibrated
EEPROM_t EEPROM = {true, 300, 205, 30, 252};

//NotCalibrated
//EEPROM_t EEPROM = {false, 0, 205, 0, 0};
#endif

void EEPROM_Update_Wrapper(uint16_t angleCalib_NORTH, uint16_t angleCalib_SOUTH, uint16_t angleCalib_EAST, uint16_t angleCalib_WEST)
{
	#ifdef MATLAB_MEX_FILE
    #define write1(z, v) flagAddress1 = v
	EEPROM.write1(NVM_ANGLE_STORE_FLG_ADDRESS, CLEAR_UINT16);
	#else
	EEPROM.write(NVM_ANGLE_STORE_FLG_ADDRESS, CLEAR_UINT16);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define write2(z, v) northAddress2 = v
	EEPROM.write2(NVM_NORTH_ADDRESS, CLEAR_UINT16);
	#else
	EEPROM.write(NVM_NORTH_ADDRESS, CLEAR_UINT16);
	#endif 
	
	#ifdef MATLAB_MEX_FILE
    #define write3(z, v) southAddress3 = v
	EEPROM.write3(NVM_SOUTH_ADDRESS, CLEAR_UINT16);
	#else
	EEPROM.write(NVM_SOUTH_ADDRESS, CLEAR_UINT16);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define write4(z, v) eastAddress4 = v
	EEPROM.write4(NVM_EAST_ADDRESS, CLEAR_UINT16);
	#else
	EEPROM.write(NVM_EAST_ADDRESS, CLEAR_UINT16);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define write5(z, v) westAddress5 = v
	EEPROM.write5(NVM_WEST_ADDRESS, CLEAR_UINT16);
	#else
	EEPROM.write(NVM_WEST_ADDRESS, CLEAR_UINT16);
	#endif

	#ifdef MATLAB_MEX_FILE
    EEPROM.write1(NVM_ANGLE_STORE_FLG_ADDRESS, true);
	#else
	EEPROM.write(NVM_ANGLE_STORE_FLG_ADDRESS, true);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    EEPROM.write2(NVM_NORTH_ADDRESS, angleCalib_NORTH);
	#else
	EEPROM.write(NVM_NORTH_ADDRESS, angleCalib_NORTH);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    EEPROM.write3(NVM_SOUTH_ADDRESS, angleCalib_SOUTH);
	#else
	EEPROM.write(NVM_SOUTH_ADDRESS, angleCalib_SOUTH);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    EEPROM.write4(NVM_EAST_ADDRESS, angleCalib_EAST);
	#else
	EEPROM.write(NVM_EAST_ADDRESS, angleCalib_EAST);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    EEPROM.write5(NVM_WEST_ADDRESS, angleCalib_WEST);
	#else
	EEPROM.write(NVM_WEST_ADDRESS, angleCalib_WEST);
	#endif
}

void EEPROM_Read_Wrapper(boolean_T* NVM_AngleStoreFlg, uint16_t* NVM_NORTH, uint16_t* NVM_SOUTH, uint16_t* NVM_EAST, uint16_t* NVM_WEST)
{

	#ifdef MATLAB_MEX_FILE
    #define read1(z)  flagAddress1
	*NVM_AngleStoreFlg = EEPROM.read1(NVM_ANGLE_STORE_FLG_ADDRESS);
	#else
    *NVM_AngleStoreFlg = EEPROM.read(NVM_ANGLE_STORE_FLG_ADDRESS);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define read2(z)  northAddress2
	*NVM_NORTH = EEPROM.read2(NVM_NORTH_ADDRESS);
	#else
    *NVM_NORTH = EEPROM.read(NVM_NORTH_ADDRESS);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define read3(z)  southAddress3
	*NVM_SOUTH = EEPROM.read3(NVM_SOUTH_ADDRESS);
	#else
    *NVM_SOUTH = EEPROM.read(NVM_SOUTH_ADDRESS);
	#endif

	#ifdef MATLAB_MEX_FILE
    #define read4(z)  eastAddress4
	*NVM_EAST = EEPROM.read4(NVM_EAST_ADDRESS);
	#else
    *NVM_EAST = EEPROM.read(NVM_EAST_ADDRESS);
	#endif
	
	#ifdef MATLAB_MEX_FILE
    #define read5(z)  westAddress5
	*NVM_WEST = EEPROM.read5(NVM_WEST_ADDRESS);
	#else
    *NVM_WEST = EEPROM.read(NVM_WEST_ADDRESS);
	#endif
}

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