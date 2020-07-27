/*
 * Code generation for system system '<S16>/motorHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
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
  boolean_T rtb_LogicalOperator_l;
  boolean_T rtb_Logical_Operator_pe;
  uint8_T rtb_Product;
  uint8_T rtb_Switch4;
  real32_T rtb_Add_b;

  /* Abs: '<S25>/Abs' */
  rtb_Abs_i = (real32_T)fabs(RobotControl_B.thetaError);

  /* Logic: '<S25>/Logical Operator' incorporates:
   *  Constant: '<S25>/ENU_FORWARD'
   *  Constant: '<S25>/ENU_FORWARD1'
   *  RelationalOperator: '<S25>/Relational_Operator'
   *  RelationalOperator: '<S25>/Relational_Operator1'
   */
  rtb_LogicalOperator_l = ((RobotControl_B.turnRequestFiltered ==
    RobotControl_P.ENU_FORWARD) || (RobotControl_B.turnRequestFiltered ==
    RobotControl_P.ENU_BACKWARD));

  /* Logic: '<S25>/Logical_Operator' */
  rtb_Logical_Operator_pe = !rtb_LogicalOperator_l;

  /* Switch: '<S147>/Init' incorporates:
   *  Constant: '<S147>/Initial Condition'
   *  Logic: '<S147>/FixPt Logical Operator'
   *  UnitDelay: '<S147>/FixPt Unit Delay1'
   *  UnitDelay: '<S147>/FixPt Unit Delay2'
   */
  if (rtb_Logical_Operator_pe || (RobotControl_DW.FixPtUnitDelay2_DSTATE != 0))
  {
    rtb_Add_b = 0.001F;
  } else {
    rtb_Add_b = RobotControl_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S147>/Init' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/CAL_forwardStartIncr'
   */
  rtb_Add_b += RobotControl_P.CAL_forwardStartIncr + rtb_Abs_i;

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S25>/CAL_MOTOR_HIGH'
   *  Constant: '<S25>/CONST_EndOfLineEnableFlg'
   *  Product: '<S25>/Divide'
   *  Saturate: '<S25>/Saturation1'
   *  Switch: '<S25>/Switch'
   *  Switch: '<S25>/Switch3'
   */
  if (RobotControl_P.CONST_EndOfLineEnableFlg) {
    rtb_Abs_i = RobotControl_B.EOL_pwm / (real32_T)RobotControl_P.CAL_MOTOR_HIGH;
    rtb_Switch4 = RobotControl_B.EOL_leftMoveReq;
  } else {
    if (rtb_LogicalOperator_l) {
      /* Saturate: '<S25>/Saturation' incorporates:
       *  Switch: '<S25>/Switch'
       */
      if (rtb_Add_b > RobotControl_P.CAL_ErrorUpperLimit) {
        rtb_Abs_i = RobotControl_P.CAL_ErrorUpperLimit;
      } else if (rtb_Add_b < 0.0F) {
        rtb_Abs_i = 0.0F;
      } else {
        rtb_Abs_i = rtb_Add_b;
      }

      /* End of Saturate: '<S25>/Saturation' */
    } else if (rtb_Abs_i > RobotControl_P.CAL_ErrorUpperLimit) {
      /* Saturate: '<S25>/Saturation1' incorporates:
       *  Switch: '<S25>/Switch'
       */
      rtb_Abs_i = RobotControl_P.CAL_ErrorUpperLimit;
    } else {
      if (rtb_Abs_i < RobotControl_P.CAL_ErrorLowerLimit) {
        /* Saturate: '<S25>/Saturation1' incorporates:
         *  Switch: '<S25>/Switch'
         */
        rtb_Abs_i = RobotControl_P.CAL_ErrorLowerLimit;
      }
    }

    rtb_Switch4 = RobotControl_B.leftMotorRequest;
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Product: '<S145>/Product' incorporates:
   *  Constant: '<S145>/CAL_MOTOR_HIGH'
   */
  rtb_Product = (uint8_T)(rtb_Abs_i * (real32_T)RobotControl_P.CAL_MOTOR_HIGH);

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
  if (rtb_Switch4 == RobotControl_P.ENU_BACKWARD) {
    RobotControl_B.leftPosPin = RobotControl_P.CAL_MOTOR_LOW;
    RobotControl_B.leftNegPin = rtb_Product;
  } else if (rtb_Switch4 == RobotControl_P.ENU_FORWARD) {
    /* Switch: '<S145>/Switch1' */
    RobotControl_B.leftPosPin = rtb_Product;

    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW'
     */
    RobotControl_B.leftNegPin = RobotControl_P.CAL_MOTOR_LOW;
  } else if (rtb_Switch4 == RobotControl_P.ENU_STOP) {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW2'
     *  Switch: '<S145>/Switch1'
     */
    RobotControl_B.leftPosPin = RobotControl_P.CAL_MOTOR_LOW;

    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/CAL_MOTOR_LOW3'
     *  Switch: '<S145>/Switch1'
     */
    RobotControl_B.leftNegPin = RobotControl_P.CAL_MOTOR_LOW;
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

  /* Product: '<S146>/Product' incorporates:
   *  Constant: '<S146>/CAL_MOTOR_HIGH'
   */
  rtb_Product = (uint8_T)(rtb_Abs_i * (real32_T)RobotControl_P.CAL_MOTOR_HIGH);

  /* Switch: '<S25>/Switch4' incorporates:
   *  Constant: '<S25>/CONST_EndOfLineEnableFlg2'
   */
  if (RobotControl_P.CONST_EndOfLineEnableFlg) {
    rtb_Switch4 = RobotControl_B.EOL_rightMoveReq;
  } else {
    rtb_Switch4 = RobotControl_B.rightMotorRequest;
  }

  /* End of Switch: '<S25>/Switch4' */

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
  if (rtb_Switch4 == RobotControl_P.ENU_BACKWARD) {
    RobotControl_B.rightPosPin = RobotControl_P.CAL_MOTOR_LOW;
    RobotControl_B.rightNegPin = rtb_Product;
  } else if (rtb_Switch4 == RobotControl_P.ENU_FORWARD) {
    /* Switch: '<S146>/Switch1' */
    RobotControl_B.rightPosPin = rtb_Product;

    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW'
     */
    RobotControl_B.rightNegPin = RobotControl_P.CAL_MOTOR_LOW;
  } else if (rtb_Switch4 == RobotControl_P.ENU_STOP) {
    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW2'
     *  Switch: '<S146>/Switch1'
     */
    RobotControl_B.rightPosPin = RobotControl_P.CAL_MOTOR_LOW;

    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S146>/CAL_MOTOR_LOW3'
     *  Switch: '<S146>/Switch1'
     */
    RobotControl_B.rightNegPin = RobotControl_P.CAL_MOTOR_LOW;
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
    RobotControl_DW.FixPtUnitDelay1_DSTATE = rtb_Add_b;
  }

  /* End of Switch: '<S147>/Reset' */
}
