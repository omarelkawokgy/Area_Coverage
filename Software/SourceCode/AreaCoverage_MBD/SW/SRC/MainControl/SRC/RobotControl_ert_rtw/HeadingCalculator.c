/*
 * File: HeadingCalculator.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.553
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Aug 05 14:53:55 2020
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

/* Named constants for Chart: '<S31>/HeadingCalculation' */
#define RobotControl_CAL_fullCircle_DEG (360U)

/* Forward declaration for local functions */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta);

/* Function for Chart: '<S31>/HeadingCalculation' */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta)
{
  real_T rangeFlg;
  int16_T thdUpper;
  int16_T thdLower;
  boolean_T guard1 = false;

  /* Constant: '<S31>/CAL_ROB_ERRVAL' */
  /* Graphical Function 'thdOverflowRangeFlg': '<S33>:195' */
  /* Transition: '<S33>:180' */
  guard1 = false;
  if (direction - (real_T)((uint8_T)CAL_ROB_ERRVAL) < 0.0) {
    /* Transition: '<S33>:196' */
    /* Transition: '<S33>:189' */
    thdUpper = (int16_T)(direction + (real_T)((uint8_T)CAL_ROB_ERRVAL));
    thdLower = (int16_T)((direction - (real_T)((uint8_T)CAL_ROB_ERRVAL)) +
                         (real_T)RobotControl_CAL_fullCircle_DEG);
    guard1 = true;
  } else {
    /* Transition: '<S33>:192' */
    if (direction + (real_T)((uint8_T)CAL_ROB_ERRVAL) >
        RobotControl_CAL_fullCircle_DEG) {
      /* Transition: '<S33>:197' */
      /* Transition: '<S33>:200' */
      thdUpper = (int16_T)((direction + (real_T)((uint8_T)CAL_ROB_ERRVAL)) -
                           (real_T)RobotControl_CAL_fullCircle_DEG);
      thdLower = (int16_T)(direction - (real_T)((uint8_T)CAL_ROB_ERRVAL));

      /* Transition: '<S33>:214' */
      guard1 = true;
    } else {
      /* Transition: '<S33>:201' */
      if ((theta >= (int16_T)(direction - (real_T)((uint8_T)CAL_ROB_ERRVAL))) &&
          (theta <= (int16_T)(direction + (real_T)((uint8_T)CAL_ROB_ERRVAL)))) {
        /* Transition: '<S33>:215' */
        /* Transition: '<S33>:217' */
        rangeFlg = 1.0;

        /* Transition: '<S33>:219' */
      } else {
        /* Transition: '<S33>:218' */
        rangeFlg = 0.0;
      }
    }
  }

  if (guard1) {
    if ((theta >= thdLower) || (theta <= thdUpper)) {
      /* Transition: '<S33>:178' */
      /* Transition: '<S33>:209' */
      rangeFlg = 1.0;

      /* Transition: '<S33>:212' */
    } else {
      /* Transition: '<S33>:211' */
      rangeFlg = 0.0;
    }
  }

  /* End of Constant: '<S31>/CAL_ROB_ERRVAL' */
  return rangeFlg;
}

/* System initialize for function-call system: '<S22>/HeadingCalculator' */
void RobotCon_HeadingCalculator_Init(void)
{
  /* SystemInitialize for Chart: '<S31>/HeadingCalculation' */
  RobotControl_B.currentHeading = 0U;
}

/* Output and update for function-call system: '<S22>/HeadingCalculator' */
void RobotControl_HeadingCalculator(void)
{
  /* Chart: '<S31>/HeadingCalculation' incorporates:
   *  Constant: '<S31>/ENU_ROB_NONE'
   */
  /* Gateway: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* During: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Chart for calculation of heading. Could be used as state but not used */
  /* Entry Internal: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Transition: '<S33>:173' */
  if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_NORTH, (real_T)
       RobotControl_B.theta_Deg) != 0.0) {
    /* Transition: '<S33>:118' */
    /* Transition: '<S33>:122' */
    RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_NORTH;

    /* Transition: '<S33>:111' */
    /* Transition: '<S33>:133' */
    /* Transition: '<S33>:132' */
    /* Transition: '<S33>:130' */
  } else {
    /* Transition: '<S33>:121' */
    if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_SOUTH,
         (real_T)RobotControl_B.theta_Deg) != 0.0) {
      /* Transition: '<S33>:131' */
      /* Transition: '<S33>:112' */
      RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_SOUTH;

      /* Transition: '<S33>:133' */
      /* Transition: '<S33>:132' */
      /* Transition: '<S33>:130' */
    } else {
      /* Transition: '<S33>:123' */
      if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_EAST,
           (real_T)RobotControl_B.theta_Deg) != 0.0) {
        /* Transition: '<S33>:124' */
        /* Transition: '<S33>:126' */
        RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_EAST;

        /* Transition: '<S33>:132' */
        /* Transition: '<S33>:130' */
      } else {
        /* Transition: '<S33>:125' */
        if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_WEST,
             (real_T)RobotControl_B.theta_Deg) != 0.0) {
          /* Transition: '<S33>:127' */
          /* Transition: '<S33>:129' */
          RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_WEST;

          /* Transition: '<S33>:130' */
        } else {
          /* Transition: '<S33>:128' */
          RobotControl_B.currentHeading = ENU_ROB_NONE;
        }
      }
    }
  }

  /* End of Chart: '<S31>/HeadingCalculation' */
  /* Transition: '<S33>:134' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
