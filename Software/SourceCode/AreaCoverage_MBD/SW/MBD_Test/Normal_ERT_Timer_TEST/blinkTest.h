/*
 * File: blinkTest.h
 *
 * Code generated for Simulink model 'blinkTest'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 03 12:57:51 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blinkTest_h_
#define RTW_HEADER_blinkTest_h_
#ifndef blinkTest_COMMON_INCLUDES_
# define blinkTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* blinkTest_COMMON_INCLUDES_ */

#include "blinkTest_types.h"

/* Child system includes */
#include "Blink.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "I_O_Wrapper.h"

/* Block signals (auto storage) */
typedef struct {
  boolean_T flag;                      /* '<S1>/Chart' */
} B_blinkTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_blinkTest;      /* '<S1>/Chart' */
  uint8_T is_c3_blinkTest;             /* '<S1>/Chart' */
} DW_blinkTest_T;

/* Real-time Model Data Structure */
struct tag_RTM_blinkTest_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_blinkTest_T blinkTest_B;

/* Block states (auto storage) */
extern DW_blinkTest_T blinkTest_DW;

/* Model entry point functions */
extern void blinkTest_initialize(void);
extern void blinkTest_step(void);

/* Real-time Model object */
extern RT_MODEL_blinkTest_T *const blinkTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'blinkTest'
 * '<S1>'   : 'blinkTest/Blink'
 * '<S2>'   : 'blinkTest/Chart'
 * '<S3>'   : 'blinkTest/Blink/Chart'
 */
#endif                                 /* RTW_HEADER_blinkTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
