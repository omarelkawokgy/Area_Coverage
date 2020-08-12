/*
 * File: HeadingCalculator.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.565
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Aug 08 11:48:30 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HeadingCalculator.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S32>/HeadingCalculation' */
#define RobotControl_CAL_fullCircle_DEG (360U)

/* Forward declaration for local functions */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta);

/* Function for Chart: '<S32>/HeadingCalculation' */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta)
{
  real_T rangeFlg;
  int16_T thdUpper;
  int16_T thdLower;
  boolean_T guard1 = false;

  /* Constant: '<S32>/CAL_ROB_ERRVAL' */
  /* Graphical Function 'thdOverflowRangeFlg': '<S34>:195' */
  /* Transition: '<S34>:180' */
  guard1 = false;
  if (direction - (real_T)((uint8_T)CAL_ROB_ERRVAL) < 0.0) {
    /* Transition: '<S34>:196' */
    /* Transition: '<S34>:189' */
    thdUpper = (int16_T)(direction + (real_T)((uint8_T)CAL_ROB_ERRVAL));
    thdLower = (int16_T)((direction - (real_T)((uint8_T)CAL_ROB_ERRVAL)) +
                         (real_T)RobotControl_CAL_fullCircle_DEG);
    guard1 = true;
  } else {
    /* Transition: '<S34>:192' */
    if (direction + (real_T)((uint8_T)CAL_ROB_ERRVAL) >
        RobotControl_CAL_fullCircle_DEG) {
      /* Transition: '<S34>:197' */
      /* Transition: '<S34>:200' */
      thdUpper = (int16_T)((direction + (real_T)((uint8_T)CAL_ROB_ERRVAL)) -
                           (real_T)RobotControl_CAL_fullCircle_DEG);
      thdLower = (int16_T)(direction - (real_T)((uint8_T)CAL_ROB_ERRVAL));

      /* Transition: '<S34>:214' */
      guard1 = true;
    } else {
      /* Transition: '<S34>:201' */
      if ((theta >= (int16_T)(direction - (real_T)((uint8_T)CAL_ROB_ERRVAL))) &&
          (theta <= (int16_T)(direction + (real_T)((uint8_T)CAL_ROB_ERRVAL)))) {
        /* Transition: '<S34>:215' */
        /* Transition: '<S34>:217' */
        rangeFlg = 1.0;

        /* Transition: '<S34>:219' */
      } else {
        /* Transition: '<S34>:218' */
        rangeFlg = 0.0;
      }
    }
  }

  if (guard1) {
    if ((theta >= thdLower) || (theta <= thdUpper)) {
      /* Transition: '<S34>:178' */
      /* Transition: '<S34>:209' */
      rangeFlg = 1.0;

      /* Transition: '<S34>:212' */
    } else {
      /* Transition: '<S34>:211' */
      rangeFlg = 0.0;
    }
  }

  /* End of Constant: '<S32>/CAL_ROB_ERRVAL' */
  return rangeFlg;
}

/* System initialize for function-call system: '<S23>/HeadingCalculator' */
void RobotCon_HeadingCalculator_Init(void)
{
  /* SystemInitialize for Chart: '<S32>/HeadingCalculation' */
  RobotControl_B.currentHeading = 0U;
}

/* Output and update for function-call system: '<S23>/HeadingCalculator' */
void RobotControl_HeadingCalculator(void)
{
  /* Chart: '<S32>/HeadingCalculation' incorporates:
   *  Constant: '<S32>/ENU_ROB_NONE'
   */
  /* Gateway: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* During: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Chart for calculation of heading. Could be used as state but not used */
  /* Entry Internal: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Transition: '<S34>:173' */
  if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_NORTH, (real_T)
       RobotControl_B.theta_Deg) != 0.0) {
    /* Transition: '<S34>:118' */
    /* Transition: '<S34>:122' */
    RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_NORTH;

    /* Transition: '<S34>:111' */
    /* Transition: '<S34>:133' */
    /* Transition: '<S34>:132' */
    /* Transition: '<S34>:130' */
  } else {
    /* Transition: '<S34>:121' */
    if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_SOUTH,
         (real_T)RobotControl_B.theta_Deg) != 0.0) {
      /* Transition: '<S34>:131' */
      /* Transition: '<S34>:112' */
      RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_SOUTH;

      /* Transition: '<S34>:133' */
      /* Transition: '<S34>:132' */
      /* Transition: '<S34>:130' */
    } else {
      /* Transition: '<S34>:123' */
      if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_EAST,
           (real_T)RobotControl_B.theta_Deg) != 0.0) {
        /* Transition: '<S34>:124' */
        /* Transition: '<S34>:126' */
        RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_EAST;

        /* Transition: '<S34>:132' */
        /* Transition: '<S34>:130' */
      } else {
        /* Transition: '<S34>:125' */
        if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_WEST,
             (real_T)RobotControl_B.theta_Deg) != 0.0) {
          /* Transition: '<S34>:127' */
          /* Transition: '<S34>:129' */
          RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_WEST;

          /* Transition: '<S34>:130' */
        } else {
          /* Transition: '<S34>:128' */
          RobotControl_B.currentHeading = ENU_ROB_NONE;
        }
      }
    }
  }

  /* End of Chart: '<S32>/HeadingCalculation' */
  /* Transition: '<S34>:134' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
