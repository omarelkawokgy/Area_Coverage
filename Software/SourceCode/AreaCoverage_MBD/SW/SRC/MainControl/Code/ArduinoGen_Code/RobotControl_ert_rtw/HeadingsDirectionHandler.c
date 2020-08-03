/*
 * Code generation for system system '<S16>/HeadingsDirectionHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.503
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 29 10:39:32 2020
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
  RobotControl_DW.Unit_Delay_DSTATE_b = RobotControl_P.ENU_END;

  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d =
    RobotControl_P.UnitDelay_InitialCondition_g;

  /* SystemInitialize for Outport: '<S20>/NORTH' */
  RobotControl_B.ROB_NORTH = RobotControl_P.NORTH_Y0;

  /* SystemInitialize for Outport: '<S20>/SOUTH' */
  RobotControl_B.ROB_SOUTH = RobotControl_P.SOUTH_Y0;

  /* SystemInitialize for Outport: '<S20>/EAST' */
  RobotControl_B.ROB_EAST = RobotControl_P.EAST_Y0;

  /* SystemInitialize for Outport: '<S20>/WEST' */
  RobotControl_B.ROB_WEST = RobotControl_P.WEST_Y0;
}

/* Output and update for function-call system: '<S16>/HeadingsDirectionHandler' */
void RobotC_HeadingsDirectionHandler(void)
{
  boolean_T rtb_Switch2;

  /* Switch: '<S89>/Switch2' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S89>/Constant1'
   *  Constant: '<S89>/ENU_SHIFT_HEADING'
   *  Logic: '<S89>/Logical Operator'
   *  RelationalOperator: '<S89>/Relational_Operator6'
   *  UnitDelay: '<S20>/Unit_Delay'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  if ((RobotControl_DW.Unit_Delay_DSTATE_b == RobotControl_P.ENU_SHIFT_HEADING) ||
      RobotControl_DW.UnitDelay_DSTATE_d) {
    rtb_Switch2 = RobotControl_P.Constant_Value_i;
  } else {
    rtb_Switch2 = RobotControl_P.Constant1_Value_n;
  }

  /* End of Switch: '<S89>/Switch2' */

  /* Switch: '<S20>/Switch1' */
  if (rtb_Switch2) {
    /* SignalConversion: '<S20>/Signal Conversion' incorporates:
     *  Constant: '<S20>/CAL_WEST'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_NORTH = RobotControl_P.CAL_WEST;

    /* SignalConversion: '<S20>/Signal Conversion1' incorporates:
     *  Constant: '<S20>/CAL_EAST'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_SOUTH = RobotControl_P.CAL_EAST;

    /* SignalConversion: '<S20>/Signal Conversion2' incorporates:
     *  Constant: '<S20>/CAL_NORTH'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_EAST = RobotControl_P.CAL_NORTH;

    /* SignalConversion: '<S20>/Signal Conversion3' incorporates:
     *  Constant: '<S20>/CAL_SOUTH'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_WEST = RobotControl_P.CAL_SOUTH;
  } else {
    /* SignalConversion: '<S20>/Signal Conversion' incorporates:
     *  Constant: '<S20>/CAL_NORTH'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_NORTH = RobotControl_P.CAL_NORTH;

    /* SignalConversion: '<S20>/Signal Conversion1' incorporates:
     *  Constant: '<S20>/CAL_SOUTH'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_SOUTH = RobotControl_P.CAL_SOUTH;

    /* SignalConversion: '<S20>/Signal Conversion2' incorporates:
     *  Constant: '<S20>/CAL_EAST'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_EAST = RobotControl_P.CAL_EAST;

    /* SignalConversion: '<S20>/Signal Conversion3' incorporates:
     *  Constant: '<S20>/CAL_WEST'
     *  Switch: '<S20>/Switch'
     */
    RobotControl_B.ROB_WEST = RobotControl_P.CAL_WEST;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Update for UnitDelay: '<S20>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S89>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d = rtb_Switch2;
}
