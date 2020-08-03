/*
 * File: Blink.c
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

#include "Blink.h"

/* Include model header file for global data */
#include "blinkTest.h"
#include "blinkTest_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define blinkTest_IN_off               ((uint8_T)1U)
#define blinkTest_IN_on                ((uint8_T)2U)

/* Output and update for atomic system: '<Root>/Blink' */
void blinkTest_Blink(void)
{
  /* Chart: '<S1>/Chart' */
  /* Gateway: Blink/Chart */
  if (blinkTest_DW.temporalCounter_i1 < 16777215UL) {
    blinkTest_DW.temporalCounter_i1++;
  }

  /* During: Blink/Chart */
  if (blinkTest_DW.is_active_c3_blinkTest == 0U) {
    /* Entry: Blink/Chart */
    blinkTest_DW.is_active_c3_blinkTest = 1U;

    /* Entry Internal: Blink/Chart */
    /* Transition: '<S3>:6' */
    blinkTest_DW.is_c3_blinkTest = blinkTest_IN_off;
    blinkTest_DW.temporalCounter_i1 = 0UL;

    /* Entry 'off': '<S3>:2' */
    blinkTest_B.flag = false;
  } else if (blinkTest_DW.is_c3_blinkTest == blinkTest_IN_off) {
    /* During 'off': '<S3>:2' */
    if (blinkTest_DW.temporalCounter_i1 >= 1000UL) {
      /* Transition: '<S3>:4' */
      blinkTest_DW.is_c3_blinkTest = blinkTest_IN_on;
      blinkTest_DW.temporalCounter_i1 = 0UL;

      /* Entry 'on': '<S3>:1' */
      blinkTest_B.flag = true;
    }
  } else {
    /* During 'on': '<S3>:1' */
    if (blinkTest_DW.temporalCounter_i1 >= 1000UL) {
      /* Transition: '<S3>:3' */
      blinkTest_DW.is_c3_blinkTest = blinkTest_IN_off;
      blinkTest_DW.temporalCounter_i1 = 0UL;

      /* Entry 'off': '<S3>:2' */
      blinkTest_B.flag = false;
    }
  }

  /* End of Chart: '<S1>/Chart' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
