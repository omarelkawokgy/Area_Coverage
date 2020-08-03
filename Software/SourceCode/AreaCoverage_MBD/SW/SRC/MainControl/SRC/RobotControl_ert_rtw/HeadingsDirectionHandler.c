/*
 * Code generation for system system '<S16>/HeadingsDirectionHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "HeadingsDirectionHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S16>/HeadingsDirectionHandler' */
void R_HeadingsDirectionHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S20>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = 27U;

  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d = false;

  /* SystemInitialize for Outport: '<S20>/NORTH' */
  RobotControl_B.ROB_NORTH = 0;

  /* SystemInitialize for Outport: '<S20>/SOUTH' */
  RobotControl_B.ROB_SOUTH = 0;

  /* SystemInitialize for Outport: '<S20>/EAST' */
  RobotControl_B.ROB_EAST = 0;

  /* SystemInitialize for Outport: '<S20>/WEST' */
  RobotControl_B.ROB_WEST = 0;
}

/* Output and update for function-call system: '<S16>/HeadingsDirectionHandler' */
void RobotC_HeadingsDirectionHandler(void)
{
  boolean_T rtb_Switch2;

  /* Switch: '<S89>/Switch2' incorporates:
   *  Constant: '<S89>/ENU_SHIFT_HEADING'
   *  Logic: '<S89>/Logical Operator'
   *  RelationalOperator: '<S89>/Relational_Operator6'
   *  UnitDelay: '<S20>/Unit_Delay'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  rtb_Switch2 = ((RobotControl_DW.Unit_Delay_DSTATE_b == 29) ||
                 RobotControl_DW.UnitDelay_DSTATE_d);

  /* Switch: '<S20>/Switch1' */
  if (rtb_Switch2) {
    /* SignalConversion: '<S20>/Signal Conversion' */
    RobotControl_B.ROB_NORTH = 180;

    /* SignalConversion: '<S20>/Signal Conversion1' */
    RobotControl_B.ROB_SOUTH = 0;

    /* SignalConversion: '<S20>/Signal Conversion2' */
    RobotControl_B.ROB_EAST = 270;

    /* SignalConversion: '<S20>/Signal Conversion3' */
    RobotControl_B.ROB_WEST = 90;
  } else {
    /* SignalConversion: '<S20>/Signal Conversion' */
    RobotControl_B.ROB_NORTH = 270;

    /* SignalConversion: '<S20>/Signal Conversion1' */
    RobotControl_B.ROB_SOUTH = 90;

    /* SignalConversion: '<S20>/Signal Conversion2' */
    RobotControl_B.ROB_EAST = 0;

    /* SignalConversion: '<S20>/Signal Conversion3' */
    RobotControl_B.ROB_WEST = 180;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Update for UnitDelay: '<S20>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S89>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d = rtb_Switch2;
}
