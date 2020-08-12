/*
 * File: DSCA.h
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

#ifndef RTW_HEADER_DSCA_h_
#define RTW_HEADER_DSCA_h_
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Block signals for system '<S58>/EncoderIncrement' */
typedef struct {
  int32_T distCounter;                 /* '<S62>/Add' */
} B_EncoderIncrement_RobotContr_T;

/* Zero-crossing (trigger) state for system '<S58>/EncoderIncrement' */
typedef struct {
  ZCSigState EncoderIncrement_Trig_ZCE;/* '<S58>/EncoderIncrement' */
} ZCE_EncoderIncrement_RobotCon_T;

/* Block signals for system '<S79>/SpdTickDetector' */
typedef struct {
  real32_T spd;                        /* '<S79>/SpdTickDetector' */
} B_SpdTickDetector_RobotContro_T;

/* Block states (auto storage) for system '<S79>/SpdTickDetector' */
typedef struct {
  real32_T encoderTick_prev;           /* '<S79>/SpdTickDetector' */
  real32_T encoderTick_start;          /* '<S79>/SpdTickDetector' */
  uint8_T is_active_c9_DSCA;           /* '<S79>/SpdTickDetector' */
  uint8_T is_c9_DSCA;                  /* '<S79>/SpdTickDetector' */
  uint8_T cycleCnt;                    /* '<S79>/SpdTickDetector' */
} DW_SpdTickDetector_RobotContr_T;

extern void RobotControl_EncoderIncrement(boolean_T rtu_EncoderTicks_Bool,
  uint8_T rtu_motorDirection, B_EncoderIncrement_RobotContr_T *localB,
  ZCE_EncoderIncrement_RobotCon_T *localZCE);
extern void RobotContr_SpdTickDetector_Init(B_SpdTickDetector_RobotContro_T
  *localB, DW_SpdTickDetector_RobotContr_T *localDW);
extern void RobotControl_SpdTickDetector(real32_T rtu_encoderTick,
  B_SpdTickDetector_RobotContro_T *localB, DW_SpdTickDetector_RobotContr_T
  *localDW);
extern void RobotContr_EncoderAnalogIn_Init(void);
extern void RobotControl_EncoderAnalogIn(void);
extern void RobotControl_DSCA_Init(void);
extern void RobotControl_DSCA(void);

#endif                                 /* RTW_HEADER_DSCA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
