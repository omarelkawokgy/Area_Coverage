#ifndef I_O_WRAPPER_H
#define I_O_WRAPPER_H

#ifndef MATLAB_MEX_FILE
void HMC5883L_CompassRead(int16_t *Temp_angle);

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm);

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm);

#else
//IO pin Handle
#define	digitalWrite(x, value) 
#define digitalRead(pin) 0
#define analogWrite(pin, value)
#define analogRead(pin) 0

//Custom Stubs
//CompassStub
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

void HMC5883L_CompassRead(int16_t *Temp_angle);

void ULSL_Hndler_Outputs_wrapper(const uint8_t ULSL_Pin, uint16_t *ULSL_cm);

void ULSR_Hndler_Outputs_wrapper(const uint8_t ULSR_Pin, uint16_t *ULSR_cm);

#endif

#endif