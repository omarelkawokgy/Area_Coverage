/*
 * File: HeadingsDirectionHandler.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.555
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 02:48:56 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HeadingsDirectionHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S21>/HeadingsDirectionHandler' */
void R_HeadingsDirectionHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S25>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = ((uint8_T)ENU_END);
}

/* Output and update for function-call system: '<S21>/HeadingsDirectionHandler' */
void RobotC_HeadingsDirectionHandler(void)
{
  boolean_T rtb_Switch2;

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S94>/ENU_SHIFT_HEADING'
   *  Logic: '<S94>/Logical Operator'
   *  RelationalOperator: '<S94>/Relational_Operator6'
   *  UnitDelay: '<S25>/Unit_Delay'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  rtb_Switch2 = ((RobotControl_DW.Unit_Delay_DSTATE_b == ((uint8_T)
    ENU_SHIFT_HEADING)) || RobotControl_DW.UnitDelay_DSTATE_d);

  /* Switch: '<S25>/Switch1' */
  if (rtb_Switch2) {
    /* SignalConversion: '<S25>/Signal Conversion' incorporates:
     *  Constant: '<S25>/CAL_WEST'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_NORTH = CAL_WEST;

    /* SignalConversion: '<S25>/Signal Conversion1' incorporates:
     *  Constant: '<S25>/CAL_EAST'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_SOUTH = CAL_EAST;

    /* SignalConversion: '<S25>/Signal Conversion2' incorporates:
     *  Constant: '<S25>/CAL_NORTH'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_EAST = CAL_NORTH;

    /* SignalConversion: '<S25>/Signal Conversion3' incorporates:
     *  Constant: '<S25>/CAL_SOUTH'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_WEST = CAL_SOUTH;
  } else {
    /* SignalConversion: '<S25>/Signal Conversion' incorporates:
     *  Constant: '<S25>/CAL_NORTH'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_NORTH = CAL_NORTH;

    /* SignalConversion: '<S25>/Signal Conversion1' incorporates:
     *  Constant: '<S25>/CAL_SOUTH'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_SOUTH = CAL_SOUTH;

    /* SignalConversion: '<S25>/Signal Conversion2' incorporates:
     *  Constant: '<S25>/CAL_EAST'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_EAST = CAL_EAST;

    /* SignalConversion: '<S25>/Signal Conversion3' incorporates:
     *  Constant: '<S25>/CAL_WEST'
     *  Switch: '<S25>/Switch'
     */
    RobotControl_B.ROB_WEST = CAL_WEST;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* Update for UnitDelay: '<S25>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d = rtb_Switch2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
