

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

#define ARDUINO 100
#include <Arduino.h>
#define MICRO_SECONDS_TO_CM(X) X / 29.4118 / 2

#define PULSEIN_TIMEOUT 100000 //100ms
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
extern "C" void ULSR_Hndler_Outputs_wrapper(const uint8_T *ULSR_Pin,
			uint16_T *ULSR_cm)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
  pinMode(*ULSR_Pin, OUTPUT);
  
  digitalWrite(*ULSR_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(*ULSR_Pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(*ULSR_Pin, LOW);

  /* read the signal from the sensor*/
  pinMode(*ULSR_Pin, INPUT);

  uint32_T duration = pulseIn(*ULSR_Pin, HIGH, PULSEIN_TIMEOUT);

  /* convert micro-seconds to centimeters*/
  *ULSR_cm = (uint16_T)MICRO_SECONDS_TO_CM(duration);
  #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
