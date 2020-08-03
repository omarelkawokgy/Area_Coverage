/*
 * Code generation for system system '<S16>/motorHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "motorHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S16>/motorHandler' */
void RobotControl_motorHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S147>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S147>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;

  /* SystemInitialize for Outport: '<S25>/leftPosPin' */
  RobotControl_B.leftPosPin = 0U;

  /* SystemInitialize for Outport: '<S25>/leftNegPin' */
  RobotControl_B.leftNegPin = 0U;

  /* SystemInitialize for Outport: '<S25>/rightPosPin' */
  RobotControl_B.rightPosPin = 0U;

  /* SystemInitialize for Outport: '<S25>/rightNegPin' */
  RobotControl_B.rightNegPin = 0U;
}

/* Output and update for function-call system: '<S16>/motorHandler' */
void RobotControl_motorHandler(void)
{
  real32_T rtb_Abs_i;
  boolean_T rtb_Relational_Operator;
  boolean_T rtb_Logical_Operator_pe;
  uint8_T rtb_Product;
  real32_T rtb_Add_p;

  /* Abs: '<S25>/Abs' */
  rtb_Abs_i = (real32_T)fabs(RobotControl_B.thetaError);

  /* Logic: '<S25>/Logical Operator' incorporates:
   *  Constant: '<S25>/ENU_FORWARD'
   *  Constant: '<S25>/ENU_FORWARD1'
   *  RelationalOperator: '<S25>/Relational_Operator'
   *  RelationalOperator: '<S25>/Relational_Operator1'
   */
  rtb_Relational_Operator = ((RobotControl_B.turnRequestFiltered == 1) ||
    (RobotControl_B.turnRequestFiltered == 2));

  /* Logic: '<S25>/Logical_Operator' */
  rtb_Logical_Operator_pe = !rtb_Relational_Operator;

  /* Switch: '<S147>/Init' incorporates:
   *  Constant: '<S147>/Initial Condition'
   *  Logic: '<S147>/FixPt Logical Operator'
   *  UnitDelay: '<S147>/FixPt Unit Delay1'
   *  UnitDelay: '<S147>/FixPt Unit Delay2'
   */
  if (rtb_Logical_Operator_pe || (RobotControl_DW.FixPtUnitDelay2_DSTATE != 0))
  {
    rtb_Add_p = 0.001F;
  } else {
    rtb_Add_p = RobotControl_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S147>/Init' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/CAL_forwardStartIncr'
   */
  rtb_Add_p += 0.001F + rtb_Abs_i;

  /* Switch: '<S25>/Switch' incorporates:
   *  Saturate: '<S25>/Saturation1'
   */
  if (rtb_Relational_Operator) {
    /* Saturate: '<S25>/Saturation' */
    if (rtb_Add_p > 2.0F) {
      rtb_Abs_i = 2.0F;
    } else if (rtb_Add_p < 0.0F) {
      rtb_Abs_i = 0.0F;
    } else {
      rtb_Abs_i = rtb_Add_p;
    }

    /* End of Saturate: '<S25>/Saturation' */
  } else {
    if (rtb_Abs_i > 2.0F) {
      /* Saturate: '<S25>/Saturation1' */
      rtb_Abs_i = 2.0F;
    }
  }

  /* End of Switch: '<S25>/Switch' */

  /* Product: '<S145>/Product' */
  rtb_Product = (uint8_T)(rtb_Abs_i * 126.0F);

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S145>/CAL_MOTOR_LOW1'
   *  Constant: '<S145>/ENU_BACKWARD'
   *  Constant: '<S145>/ENU_FORWARD'
   *  Constant: '<S145>/ENU_STOP'
   *  RelationalOperator: '<S145>/Relational_Operator'
   *  RelationalOperator: '<S145>/Relational_Operator1'
   *  RelationalOperator: '<S145>/Relational_Operator2'
   *  Switch: '<S145>/Switch'
   *  Switch: '<S145>/Switch1'
   *  Switch: '<S145>/Switch2'
   */
  if (RobotControl_B.leftMotorRequest == 2) {
    RobotControl_B.leftPosPin = 0U;
    RobotControl_B.leftNegPin = rtb_Product;
  } else if (RobotControl_B.leftMotorRequest == 1) {
    /* Switch: '<S145>/Switch1' */
    RobotControl_B.leftPosPin = rtb_Product;

    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW'
     */
    RobotControl_B.leftNegPin = 0U;
  } else if (RobotControl_B.leftMotorRequest == 5) {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW2'
     *  Switch: '<S145>/Switch1'
     */
    RobotControl_B.leftPosPin = 0U;

    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW3'
     *  Switch: '<S145>/Switch1'
     */
    RobotControl_B.leftNegPin = 0U;
  } else {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Switch: '<S145>/Switch2'
     */
    RobotControl_B.leftPosPin = rtb_Product;

    /* Switch: '<S145>/Switch1' incorporates:
     *  Switch: '<S145>/Switch2'
     */
    RobotControl_B.leftNegPin = rtb_Product;
  }

  /* End of Switch: '<S145>/Switch' */

  /* Product: '<S146>/Product' */
  rtb_Product = (uint8_T)(rtb_Abs_i * 126.0F);

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/CAL_MOTOR_LOW1'
   *  Constant: '<S146>/ENU_BACKWARD'
   *  Constant: '<S146>/ENU_FORWARD'
   *  Constant: '<S146>/ENU_STOP'
   *  RelationalOperator: '<S146>/Relational_Operator'
   *  RelationalOperator: '<S146>/Relational_Operator1'
   *  RelationalOperator: '<S146>/Relational_Operator2'
   *  Switch: '<S146>/Switch'
   *  Switch: '<S146>/Switch1'
   *  Switch: '<S146>/Switch2'
   */
  if (RobotControl_B.rightMotorRequest == 2) {
    RobotControl_B.rightPosPin = 0U;
    RobotControl_B.rightNegPin = rtb_Product;
  } else if (RobotControl_B.rightMotorRequest == 1) {
    /* Switch: '<S146>/Switch1' */
    RobotControl_B.rightPosPin = rtb_Product;

    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW'
     */
    RobotControl_B.rightNegPin = 0U;
  } else if (RobotControl_B.rightMotorRequest == 5) {
    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW2'
     *  Switch: '<S146>/Switch1'
     */
    RobotControl_B.rightPosPin = 0U;

    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW3'
     *  Switch: '<S146>/Switch1'
     */
    RobotControl_B.rightNegPin = 0U;
  } else {
    /* Switch: '<S146>/Switch1' incorporates:
     *  Switch: '<S146>/Switch2'
     */
    RobotControl_B.rightPosPin = rtb_Product;

    /* Switch: '<S146>/Switch1' incorporates:
     *  Switch: '<S146>/Switch2'
     */
    RobotControl_B.rightNegPin = rtb_Product;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Update for UnitDelay: '<S147>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S147>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Switch: '<S147>/Reset' */
  if (rtb_Logical_Operator_pe) {
    /* Update for UnitDelay: '<S147>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S147>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;
  } else {
    /* Update for UnitDelay: '<S147>/FixPt Unit Delay1' */
    RobotControl_DW.FixPtUnitDelay1_DSTATE = rtb_Add_p;
  }

  /* End of Switch: '<S147>/Reset' */
}
