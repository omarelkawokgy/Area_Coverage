/*
 * Code generation for system system '<S17>/HeadingCalculator'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "HeadingCalculator.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S26>/HeadingCalculation' */
#define RobotControl_CAL_fullCircle_DEG (360U)

/* Forward declaration for local functions */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta);

/* Function for Chart: '<S26>/HeadingCalculation' */
static real_T RobotContro_thdOverflowRangeFlg(real_T direction, real_T theta)
{
  real_T rangeFlg;
  int16_T thdUpper;
  int16_T thdLower;
  boolean_T guard1 = false;

  /* Constant: '<S26>/CAL_ROB_ERRVAL' */
  /* Graphical Function 'thdOverflowRangeFlg': '<S28>:195' */
  /* Transition: '<S28>:180' */
  guard1 = false;
  if (direction - (real_T)RobotControl_P.CAL_ROB_ERRVAL < 0.0) {
    /* Transition: '<S28>:196' */
    /* Transition: '<S28>:189' */
    thdUpper = (int16_T)(direction + (real_T)RobotControl_P.CAL_ROB_ERRVAL);
    thdLower = (int16_T)((direction - (real_T)RobotControl_P.CAL_ROB_ERRVAL) +
                         (real_T)RobotControl_CAL_fullCircle_DEG);
    guard1 = true;
  } else {
    /* Transition: '<S28>:192' */
    if (direction + (real_T)RobotControl_P.CAL_ROB_ERRVAL >
        RobotControl_CAL_fullCircle_DEG) {
      /* Transition: '<S28>:197' */
      /* Transition: '<S28>:200' */
      thdUpper = (int16_T)((direction + (real_T)RobotControl_P.CAL_ROB_ERRVAL) -
                           (real_T)RobotControl_CAL_fullCircle_DEG);
      thdLower = (int16_T)(direction - (real_T)RobotControl_P.CAL_ROB_ERRVAL);

      /* Transition: '<S28>:214' */
      guard1 = true;
    } else {
      /* Transition: '<S28>:201' */
      if ((theta >= (int16_T)(direction - (real_T)RobotControl_P.CAL_ROB_ERRVAL))
          && (theta <= (int16_T)(direction + (real_T)
            RobotControl_P.CAL_ROB_ERRVAL))) {
        /* Transition: '<S28>:215' */
        /* Transition: '<S28>:217' */
        rangeFlg = 1.0;

        /* Transition: '<S28>:219' */
      } else {
        /* Transition: '<S28>:218' */
        rangeFlg = 0.0;
      }
    }
  }

  if (guard1) {
    if ((theta >= thdLower) || (theta <= thdUpper)) {
      /* Transition: '<S28>:178' */
      /* Transition: '<S28>:209' */
      rangeFlg = 1.0;

      /* Transition: '<S28>:212' */
    } else {
      /* Transition: '<S28>:211' */
      rangeFlg = 0.0;
    }
  }

  /* End of Constant: '<S26>/CAL_ROB_ERRVAL' */
  return rangeFlg;
}

/* System initialize for function-call system: '<S17>/HeadingCalculator' */
void RobotCon_HeadingCalculator_Init(void)
{
  /* SystemInitialize for Chart: '<S26>/HeadingCalculation' */
  RobotControl_B.currentHeading = 0U;
}

/* Output and update for function-call system: '<S17>/HeadingCalculator' */
void RobotControl_HeadingCalculator(void)
{
  /* Chart: '<S26>/HeadingCalculation' incorporates:
   *  Constant: '<S26>/ENU_ROB_NONE'
   */
  /* Gateway: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* During: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Entry Internal: Compass_Handler/HeadingCalculator/HeadingCalculation */
  /* Transition: '<S28>:173' */
  if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_NORTH, (real_T)
       RobotControl_B.theta_Deg) != 0.0) {
    /* Transition: '<S28>:118' */
    /* Transition: '<S28>:122' */
    RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_NORTH;

    /* Transition: '<S28>:111' */
    /* Transition: '<S28>:133' */
    /* Transition: '<S28>:132' */
    /* Transition: '<S28>:130' */
  } else {
    /* Transition: '<S28>:121' */
    if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_SOUTH,
         (real_T)RobotControl_B.theta_Deg) != 0.0) {
      /* Transition: '<S28>:131' */
      /* Transition: '<S28>:112' */
      RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_SOUTH;

      /* Transition: '<S28>:133' */
      /* Transition: '<S28>:132' */
      /* Transition: '<S28>:130' */
    } else {
      /* Transition: '<S28>:123' */
      if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_EAST,
           (real_T)RobotControl_B.theta_Deg) != 0.0) {
        /* Transition: '<S28>:124' */
        /* Transition: '<S28>:126' */
        RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_EAST;

        /* Transition: '<S28>:132' */
        /* Transition: '<S28>:130' */
      } else {
        /* Transition: '<S28>:125' */
        if (RobotContro_thdOverflowRangeFlg((real_T)RobotControl_B.ROB_WEST,
             (real_T)RobotControl_B.theta_Deg) != 0.0) {
          /* Transition: '<S28>:127' */
          /* Transition: '<S28>:129' */
          RobotControl_B.currentHeading = (uint16_T)RobotControl_B.ROB_WEST;

          /* Transition: '<S28>:130' */
        } else {
          /* Transition: '<S28>:128' */
          RobotControl_B.currentHeading = RobotControl_P.ENU_ROB_NONE;
        }
      }
    }
  }

  /* End of Chart: '<S26>/HeadingCalculation' */
  /* Transition: '<S28>:134' */
}
