/*
 * File: motorHandler.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.559
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 13:50:23 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S22>/motorHandler' */
void RobotControl_motorHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S153>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S153>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;
}

/* Output and update for function-call system: '<S22>/motorHandler' */
void RobotControl_motorHandler(void)
{
  real32_T rtb_Abs_i;
  boolean_T rtb_LogicalOperator_l;
  boolean_T rtb_Logical_Operator_pe;
  uint8_T rtb_Product;
  uint8_T rtb_Switch4;
  real32_T rtb_Add_p;

  /* Abs: '<S31>/Abs' */
  rtb_Abs_i = (real32_T)fabs(RobotControl_B.thetaError);

  /* Logic: '<S31>/Logical Operator' incorporates:
   *  Constant: '<S31>/ENU_FORWARD'
   *  Constant: '<S31>/ENU_FORWARD1'
   *  RelationalOperator: '<S31>/Relational_Operator'
   *  RelationalOperator: '<S31>/Relational_Operator1'
   */
  rtb_LogicalOperator_l = ((RobotControl_B.turnRequestFiltered == ((uint8_T)
    ENU_FORWARD)) || (RobotControl_B.turnRequestFiltered == ((uint8_T)
    ENU_BACKWARD)));

  /* Logic: '<S31>/Logical_Operator' */
  rtb_Logical_Operator_pe = !rtb_LogicalOperator_l;

  /* Switch: '<S153>/Init' incorporates:
   *  Constant: '<S153>/Initial Condition'
   *  Logic: '<S153>/FixPt Logical Operator'
   *  UnitDelay: '<S153>/FixPt Unit Delay1'
   *  UnitDelay: '<S153>/FixPt Unit Delay2'
   */
  if (rtb_Logical_Operator_pe || (RobotControl_DW.FixPtUnitDelay2_DSTATE != 0))
  {
    rtb_Add_p = 0.001F;
  } else {
    rtb_Add_p = RobotControl_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S153>/Init' */

  /* Sum: '<S31>/Add' incorporates:
   *  Constant: '<S31>/CAL_forwardStartIncr'
   */
  rtb_Add_p += CAL_forwardStartIncr + rtb_Abs_i;

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S31>/CAL_MOTOR_HIGH'
   *  Constant: '<S31>/CONST_EndOfLineEnableFlg'
   *  Product: '<S31>/Divide'
   *  Saturate: '<S31>/Saturation1'
   *  Switch: '<S31>/Switch'
   *  Switch: '<S31>/Switch3'
   */
  if (CONST_EndOfLineEnableFlg) {
    rtb_Abs_i = RobotControl_B.EOL_pwm / (real32_T)((uint8_T)CAL_MOTOR_HIGH);
    rtb_Switch4 = RobotControl_B.EOL_leftMoveReq;
  } else {
    if (rtb_LogicalOperator_l) {
      /* Saturate: '<S31>/Saturation' incorporates:
       *  Switch: '<S31>/Switch'
       */
      if (rtb_Add_p > CAL_ErrorUpperLimit) {
        rtb_Abs_i = CAL_ErrorUpperLimit;
      } else if (rtb_Add_p < 0.0F) {
        rtb_Abs_i = 0.0F;
      } else {
        rtb_Abs_i = rtb_Add_p;
      }

      /* End of Saturate: '<S31>/Saturation' */
    } else if (rtb_Abs_i > CAL_ErrorUpperLimit) {
      /* Saturate: '<S31>/Saturation1' incorporates:
       *  Switch: '<S31>/Switch'
       */
      rtb_Abs_i = CAL_ErrorUpperLimit;
    } else {
      if (rtb_Abs_i < CAL_ErrorLowerLimit) {
        /* Saturate: '<S31>/Saturation1' incorporates:
         *  Switch: '<S31>/Switch'
         */
        rtb_Abs_i = CAL_ErrorLowerLimit;
      }
    }

    rtb_Switch4 = RobotControl_B.leftMotorRequest;
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Product: '<S151>/Product' incorporates:
   *  Constant: '<S151>/CAL_MOTOR_HIGH'
   */
  rtb_Product = (uint8_T)(rtb_Abs_i * (real32_T)((uint8_T)CAL_MOTOR_HIGH));

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/CAL_MOTOR_LOW1'
   *  Constant: '<S151>/ENU_BACKWARD'
   *  Constant: '<S151>/ENU_FORWARD'
   *  Constant: '<S151>/ENU_STOP'
   *  RelationalOperator: '<S151>/Relational_Operator'
   *  RelationalOperator: '<S151>/Relational_Operator1'
   *  RelationalOperator: '<S151>/Relational_Operator2'
   *  Switch: '<S151>/Switch'
   *  Switch: '<S151>/Switch1'
   *  Switch: '<S151>/Switch2'
   */
  if (rtb_Switch4 == ((uint8_T)ENU_BACKWARD)) {
    RobotControl_B.leftPosPin = ((uint8_T)CAL_MOTOR_LOW);
    RobotControl_B.leftNegPin = rtb_Product;
  } else if (rtb_Switch4 == ((uint8_T)ENU_FORWARD)) {
    /* Switch: '<S151>/Switch1' */
    RobotControl_B.leftPosPin = rtb_Product;

    /* Switch: '<S151>/Switch1' incorporates:
     *  Constant: '<S151>/CAL_MOTOR_LOW'
     */
    RobotControl_B.leftNegPin = ((uint8_T)CAL_MOTOR_LOW);
  } else if (rtb_Switch4 == ((uint8_T)ENU_STOP)) {
    /* Switch: '<S151>/Switch2' incorporates:
     *  Constant: '<S151>/CAL_MOTOR_LOW2'
     *  Switch: '<S151>/Switch1'
     */
    RobotControl_B.leftPosPin = ((uint8_T)CAL_MOTOR_LOW);

    /* Switch: '<S151>/Switch2' incorporates:
     *  Constant: '<S151>/CAL_MOTOR_LOW3'
     *  Switch: '<S151>/Switch1'
     */
    RobotControl_B.leftNegPin = ((uint8_T)CAL_MOTOR_LOW);
  } else {
    /* Switch: '<S151>/Switch1' incorporates:
     *  Switch: '<S151>/Switch2'
     */
    RobotControl_B.leftPosPin = rtb_Product;

    /* Switch: '<S151>/Switch1' incorporates:
     *  Switch: '<S151>/Switch2'
     */
    RobotControl_B.leftNegPin = rtb_Product;
  }

  /* End of Switch: '<S151>/Switch' */

  /* Product: '<S152>/Product' incorporates:
   *  Constant: '<S152>/CAL_MOTOR_HIGH'
   */
  rtb_Product = (uint8_T)(rtb_Abs_i * (real32_T)((uint8_T)CAL_MOTOR_HIGH));

  /* Switch: '<S31>/Switch4' incorporates:
   *  Constant: '<S31>/CONST_EndOfLineEnableFlg2'
   */
  if (CONST_EndOfLineEnableFlg) {
    rtb_Switch4 = RobotControl_B.EOL_rightMoveReq;
  } else {
    rtb_Switch4 = RobotControl_B.rightMotorRequest;
  }

  /* End of Switch: '<S31>/Switch4' */

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/CAL_MOTOR_LOW1'
   *  Constant: '<S152>/ENU_BACKWARD'
   *  Constant: '<S152>/ENU_FORWARD'
   *  Constant: '<S152>/ENU_STOP'
   *  RelationalOperator: '<S152>/Relational_Operator'
   *  RelationalOperator: '<S152>/Relational_Operator1'
   *  RelationalOperator: '<S152>/Relational_Operator2'
   *  Switch: '<S152>/Switch'
   *  Switch: '<S152>/Switch1'
   *  Switch: '<S152>/Switch2'
   */
  if (rtb_Switch4 == ((uint8_T)ENU_BACKWARD)) {
    RobotControl_B.rightPosPin = ((uint8_T)CAL_MOTOR_LOW);
    RobotControl_B.rightNegPin = rtb_Product;
  } else if (rtb_Switch4 == ((uint8_T)ENU_FORWARD)) {
    /* Switch: '<S152>/Switch1' */
    RobotControl_B.rightPosPin = rtb_Product;

    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S152>/CAL_MOTOR_LOW'
     */
    RobotControl_B.rightNegPin = ((uint8_T)CAL_MOTOR_LOW);
  } else if (rtb_Switch4 == ((uint8_T)ENU_STOP)) {
    /* Switch: '<S152>/Switch2' incorporates:
     *  Constant: '<S152>/CAL_MOTOR_LOW2'
     *  Switch: '<S152>/Switch1'
     */
    RobotControl_B.rightPosPin = ((uint8_T)CAL_MOTOR_LOW);

    /* Switch: '<S152>/Switch2' incorporates:
     *  Constant: '<S152>/CAL_MOTOR_LOW3'
     *  Switch: '<S152>/Switch1'
     */
    RobotControl_B.rightNegPin = ((uint8_T)CAL_MOTOR_LOW);
  } else {
    /* Switch: '<S152>/Switch1' incorporates:
     *  Switch: '<S152>/Switch2'
     */
    RobotControl_B.rightPosPin = rtb_Product;

    /* Switch: '<S152>/Switch1' incorporates:
     *  Switch: '<S152>/Switch2'
     */
    RobotControl_B.rightNegPin = rtb_Product;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Update for UnitDelay: '<S153>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S153>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Switch: '<S153>/Reset' */
  if (rtb_Logical_Operator_pe) {
    /* Update for UnitDelay: '<S153>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S153>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;
  } else {
    /* Update for UnitDelay: '<S153>/FixPt Unit Delay1' */
    RobotControl_DW.FixPtUnitDelay1_DSTATE = rtb_Add_p;
  }

  /* End of Switch: '<S153>/Reset' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
