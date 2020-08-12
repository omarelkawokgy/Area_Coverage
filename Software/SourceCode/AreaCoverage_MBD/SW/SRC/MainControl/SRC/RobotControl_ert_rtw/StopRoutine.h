/*
 * File: StopRoutine.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.568
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Aug 13 00:06:06 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StopRoutine_h_
#define RTW_HEADER_StopRoutine_h_
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"
#include "rt_nonfinite.h"

extern void RobotContr_Digital_IN_bool_Init(void);
extern void RobotControl_Digital_IN_bool(uint8_T rtu_pin);
extern void RobotControl_StopRoutine_Init(void);
extern void RobotControl_StopRoutine(void);

#endif                                 /* RTW_HEADER_StopRoutine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
