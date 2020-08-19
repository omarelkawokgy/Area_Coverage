/*
 * File: DSCA.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.581
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 17 10:27:18 2020
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

/* Block signals for system '<S60>/EncoderIncrement' */
typedef struct {
  int32_T distCounter;                 /* '<S64>/Add' */
} B_EncoderIncrement_RobotContr_T;

/* Zero-crossing (trigger) state for system '<S60>/EncoderIncrement' */
typedef struct {
  ZCSigState EncoderIncrement_Trig_ZCE;/* '<S60>/EncoderIncrement' */
} ZCE_EncoderIncrement_RobotCon_T;

/* Block signals for system '<S70>/LeftEndofLineTest' */
#if leftMotorEOL_variant

typedef struct {

#if motorsHandleEOL_Variant

  uint16_T encoderCounter;             /* '<S75>/Data_Type_Conversion' */

#define B_LEFTENDOFLINETEST_ROBOTCONT_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T counterReset;              /* '<S74>/EOL_TickStateMachine' */

#define B_LEFTENDOFLINETEST_ROBOTCONT_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#ifndef B_LEFTENDOFLINETEST_ROBOTCONT_T_VARIANT_EXISTS

  char _rt_unused;

#endif

} B_LeftEndofLineTest_RobotCont_T;

#endif                                 /* leftMotorEOL_variant */

/* Block states (auto storage) for system '<S70>/LeftEndofLineTest' */
#if leftMotorEOL_variant

typedef struct {

#if motorsHandleEOL_Variant

  real32_T Unit_Delay_DSTATE;          /* '<S75>/Unit_Delay' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint16_T temporalCounter_i1;         /* '<S74>/EOL_TickStateMachine' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T Unit_Delay_DSTATE_k;       /* '<S72>/Unit_Delay' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint8_T is_active_c15_RobotControl;  /* '<S74>/EOL_TickStateMachine' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint8_T is_c15_RobotControl;         /* '<S74>/EOL_TickStateMachine' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T LeftMotorEncoderCounter_MODE;/* '<S72>/LeftMotorEncoderCounter' */

#define DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#ifndef DW_LEFTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS

  char _rt_unused;

#endif

} DW_LeftEndofLineTest_RobotCon_T;

#endif                                 /* leftMotorEOL_variant */

/* Block signals for system '<S71>/RightEndofLineTest' */
#if rightMotorEOL_variant

typedef struct {

#if motorsHandleEOL_Variant

  uint16_T encoderCounter;             /* '<S80>/Data_Type_Conversion' */

#define B_RIGHTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T counterReset;              /* '<S79>/EOL_TickStateMachine' */

#define B_RIGHTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#ifndef B_RIGHTENDOFLINETEST_ROBOTCON_T_VARIANT_EXISTS

  char _rt_unused;

#endif

} B_RightEndofLineTest_RobotCon_T;

#endif                                 /* rightMotorEOL_variant */

/* Block states (auto storage) for system '<S71>/RightEndofLineTest' */
#if rightMotorEOL_variant

typedef struct {

#if motorsHandleEOL_Variant

  real32_T Unit_Delay_DSTATE;          /* '<S80>/Unit_Delay' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint16_T temporalCounter_i1;         /* '<S79>/EOL_TickStateMachine' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T Unit_Delay_DSTATE_l;       /* '<S77>/Unit_Delay' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint8_T is_active_c16_RobotControl;  /* '<S79>/EOL_TickStateMachine' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  uint8_T is_c16_RobotControl;         /* '<S79>/EOL_TickStateMachine' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T RightMotorEncoderCounter1_MODE;/* '<S77>/RightMotorEncoderCounter1' */

#define DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#ifndef DW_RIGHTENDOFLINETEST_ROBOTCO_T_VARIANT_EXISTS

  char _rt_unused;

#endif

} DW_RightEndofLineTest_RobotCo_T;

#endif                                 /* rightMotorEOL_variant */

/* Block signals for system '<S88>/SpdTickDetector' */
typedef struct {
  real32_T spd;                        /* '<S88>/SpdTickDetector' */
} B_SpdTickDetector_RobotContro_T;

/* Block states (auto storage) for system '<S88>/SpdTickDetector' */
typedef struct {
  real32_T encoderTick_prev;           /* '<S88>/SpdTickDetector' */
  real32_T encoderTick_start;          /* '<S88>/SpdTickDetector' */
  uint8_T is_active_c18_RobotControl;  /* '<S88>/SpdTickDetector' */
  uint8_T is_c18_RobotControl;         /* '<S88>/SpdTickDetector' */
  uint8_T cycleCnt;                    /* '<S88>/SpdTickDetector' */
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
