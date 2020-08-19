#ifndef I_O_WRAPPER_H
#define I_O_WRAPPER_H

#define NVM_ANGLE_STORE_FLG_ADDRESS 0
#define NVM_NORTH_ADDRESS 1
#define NVM_SOUTH_ADDRESS 3
#define NVM_EAST_ADDRESS 5
#define NVM_WEST_ADDRESS 7
#define CLEAR_UINT16 0

#ifndef MATLAB_MEX_FILE
void HMC5883L_CompassRead(int16_t *Temp_angle);

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm);

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm);

void EEPROM_Read_Wrapper(boolean_T* NVM_AngleStoreFlg, uint16_t* NVM_NORTH, uint16_t* NVM_SOUTH, uint16_t* NVM_EAST, uint16_t* NVM_WEST);

void EEPROM_Update_Wrapper(uint16_t angleCalib_NORTH, uint16_t angleCalib_SOUTH, uint16_t angleCalib_EAST, uint16_t angleCalib_WEST);

#else

//IO pin Handle
#define	digitalWrite(x, value) 
#define digitalRead(pin) 0
#define analogWrite(pin, value)
#define analogRead(pin) 0

#define true 1
#define false 0

//Custom Stubs
//CompassStub
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned char boolean_T;

typedef struct EEPROM_S{
	boolean_T flagAddress1;
	uint16_t northAddress2;
    uint16_t southAddress3;
	uint16_t eastAddress4;
    uint16_t westAddress5;
}EEPROM_t;

void EEPROM_Read_Wrapper(boolean_T* NVM_AngleStoreFlg, uint16_t* NVM_NORTH_, uint16_t* NVM_SOUTH, uint16_t* NVM_EAST, uint16_t* NVM_WEST);

void EEPROM_Update_Wrapper(uint16_t angleCalib_NORTH, uint16_t angleCalib_SOUTH, uint16_t angleCalib_EAST, uint16_t angleCalib_WEST);

void HMC5883L_CompassRead(int16_t *Temp_angle);

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm);

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm);

#endif

#endif