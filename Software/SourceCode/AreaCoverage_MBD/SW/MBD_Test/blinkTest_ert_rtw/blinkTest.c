/*
 * File: blinkTest.c
 *
 * Code generated for Simulink model 'blinkTest'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 03 20:17:04 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blinkTest.h"
#include "blinkTest_private.h"

/* Block signals (auto storage) */
B_blinkTest_T blinkTest_B;

/* Block states (auto storage) */
DW_blinkTest_T blinkTest_DW;

/* Real-time model */
RT_MODEL_blinkTest_T blinkTest_M_;
RT_MODEL_blinkTest_T *const blinkTest_M = &blinkTest_M_;

/* Model step function */
void blinkTest_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Blink' */
  blinkTest_Blink();

  /* End of Outputs for SubSystem: '<Root>/Blink' */

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Pin'
   */
  /* Gateway: Chart */
  /* During: Chart */
  /* Entry Internal: Chart */
  /* Transition: '<S2>:2' */
  /* Transition: '<S2>:4' */
  digitalWrite(13U, blinkTest_B.flag);
}

/* Model initialize function */
void blinkTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(blinkTest_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &blinkTest_B), 0,
                sizeof(B_blinkTest_T));

  /* states (dwork) */
  (void) memset((void *)&blinkTest_DW, 0,
                sizeof(DW_blinkTest_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Blink' */
  blinkTest_Blink_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Blink' */
}

/* Model terminate function */
void blinkTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */