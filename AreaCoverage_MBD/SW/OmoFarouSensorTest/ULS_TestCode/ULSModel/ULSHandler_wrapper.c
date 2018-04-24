

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

/*Implementation of macro functions*/
#define MICRO_SECONDS_TO_CM(X) X / 29.4118 / 2
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
void ULSHandler_Outputs_wrapper(const uint8_T *inPin,
			real32_T *distance)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
#ifndef MATLAB_MEX_FILE
static bool flag = true;

if(flag)
{
  flag = false;
}

  /* the ultrasonic is triggered by a HIGH pulse of 2 or more microseconds 
   so give a short LOW pulse beforehand to ensure a clean HIGH pulse*/
  pinMode(*inPin, OUTPUT);
  
  digitalWrite(*inPin, LOW);
  delayMicroseconds(3);
  digitalWrite(*inPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(*inPin, LOW);

  /* read the signal from the sensor*/
  pinMode(*inPin, INPUT);

  uint32_T duration = pulseIn(*inPin, HIGH, 1000);

  /* convert micro-seconds to centimeters*/
  *distance = MICRO_SECONDS_TO_CM(duration);

#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
