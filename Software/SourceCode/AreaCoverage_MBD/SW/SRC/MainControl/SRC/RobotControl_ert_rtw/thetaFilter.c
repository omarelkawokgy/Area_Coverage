/*
 * Code generation for system system '<S17>/thetaFilter'
 *
 * Model                      : RobotControl
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "thetaFilter.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S17>/thetaFilter' */
void RobotControl_thetaFilter_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S27>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_d = false;

  /* InitializeConditions for UnitDelay: '<S31>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_c = 270;

  /* InitializeConditions for Delay: '<S31>/Resettable_Delay' */
  RobotControl_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S31>/Resettable_Delay1' */
  RobotControl_DW.icLoad_o = 1U;

  /* SystemInitialize for Outport: '<S27>/theta_Deg' */
  RobotControl_B.theta_mDeg = 0.0F;

  /* SystemInitialize for Outport: '<S27>/theta_mDeg' */
  RobotControl_B.theta_Deg = 0.0F;
}

/* Output and update for function-call system: '<S17>/thetaFilter' */
void RobotControl_thetaFilter(void)
{
  /* local block i/o variables */
  real32_T rtb_Switch;
  boolean_T rtb_enableAngleCalib_BOOL_z;
  boolean_T rtb_Relational_Operator;
  int16_T rtb_Subtract;
  real32_T rtb_PT_p;
  real32_T rtb_KT;
  uint16_T rtb_Switch_f;
  real32_T rtb_XT;
  int16_T rtb_Subtract_0;

  /* UnitDelay: '<S27>/Unit_Delay3' */
  rtb_enableAngleCalib_BOOL_z = RobotControl_DW.Unit_Delay3_DSTATE_d;

  /* Sum: '<S31>/Subtract' incorporates:
   *  UnitDelay: '<S31>/Unit_Delay'
   */
  rtb_Subtract = RobotControl_B.COM_A4SCA_A5SCL -
    RobotControl_DW.Unit_Delay_DSTATE_c;

  /* Abs: '<S31>/Abs' */
  if (rtb_Subtract < 0) {
    if (rtb_Subtract <= MIN_int16_T) {
      rtb_Subtract_0 = MAX_int16_T;
    } else {
      rtb_Subtract_0 = -rtb_Subtract;
    }
  } else {
    rtb_Subtract_0 = rtb_Subtract;
  }

  /* End of Abs: '<S31>/Abs' */

  /* RelationalOperator: '<S31>/Relational_Operator' incorporates:
   *  Constant: '<S31>/CAL_FilterResetThd'
   */
  rtb_Relational_Operator = (rtb_Subtract_0 > 100);

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/CAL_fullCircle_DEG'
   *  Constant: '<S31>/CONST_ONE_UINT16'
   *  Constant: '<S31>/CONST_ZeroDeg1'
   *  Logic: '<S31>/Logical_Operator'
   *  RelationalOperator: '<S31>/Relational_Operator1'
   */
  if (rtb_Relational_Operator && (rtb_Subtract < 0)) {
    rtb_Switch_f = 1U;
  } else {
    rtb_Switch_f = 360U;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Delay: '<S31>/Resettable_Delay' */
  if (rtb_Relational_Operator &&
      (RobotControl_PrevZCX.Resettable_Delay_Reset_ZCE != POS_ZCSIG)) {
    RobotControl_DW.icLoad = 1U;
  }

  RobotControl_PrevZCX.Resettable_Delay_Reset_ZCE = rtb_Relational_Operator;
  if (RobotControl_DW.icLoad != 0) {
    RobotControl_DW.Resettable_Delay_DSTATE = rtb_Switch_f;
  }

  /* Product: '<S34>/Divide1' incorporates:
   *  Sum: '<S34>/Add'
   */
  rtb_Switch = (RobotControl_B.leftVel1ms_mmPerSec -
                RobotControl_B.rightVel1ms_mmPerSec) / 250.0F;

  /* Product: '<S31>/Product' incorporates:
   *  Constant: '<S31>/CAL_EncoderSampleTime'
   */
  rtb_Switch *= 0.001F;

  /* Sum: '<S31>/Add2' incorporates:
   *  Delay: '<S31>/Resettable_Delay'
   *  Product: '<S33>/Product'
   */
  rtb_Switch = (real32_T)(57.295779513082323 * rtb_Switch +
    RobotControl_DW.Resettable_Delay_DSTATE);

  /* Delay: '<S31>/Resettable_Delay1' incorporates:
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   */
  if (rtb_Relational_Operator &&
      (RobotControl_PrevZCX.Resettable_Delay1_Reset_ZCE != POS_ZCSIG)) {
    RobotControl_DW.icLoad_o = 1U;
  }

  RobotControl_PrevZCX.Resettable_Delay1_Reset_ZCE = rtb_Relational_Operator;
  if (RobotControl_DW.icLoad_o != 0) {
    RobotControl_DW.Resettable_Delay1_DSTATE = rtb_Switch_f;
  }

  /* Product: '<S31>/Product4' incorporates:
   *  Constant: '<S31>/CAL_ProcessNoise'
   *  Delay: '<S31>/Resettable_Delay1'
   */
  rtb_PT_p = 1.5F * RobotControl_DW.Resettable_Delay1_DSTATE;

  /* Product: '<S31>/Divide1' incorporates:
   *  Constant: '<S31>/CAL_MeasureNoise'
   *  Sum: '<S31>/Add3'
   */
  rtb_KT = (1.2F + rtb_PT_p) / rtb_PT_p;

  /* Sum: '<S31>/Add4' incorporates:
   *  Product: '<S31>/Product5'
   *  Sum: '<S31>/Subtract2'
   */
  rtb_XT = ((real32_T)RobotControl_B.COM_A4SCA_A5SCL - rtb_Switch) * rtb_KT +
    rtb_Switch;

  /* Sum: '<S35>/Add2' incorporates:
   *  Constant: '<S35>/CONST_OVERFLOW_THD_UINT16'
   */
  rtb_Switch = rtb_XT - 5.0F;

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/CAL_fullCircle_DEG1'
   *  Constant: '<S35>/CONST_OVERFLOW_THD_UINT161'
   *  DataTypeConversion: '<S35>/Data_Type_Conversion'
   *  DataTypeConversion: '<S35>/Data_Type_Conversion1'
   *  RelationalOperator: '<S35>/Relational_Operator'
   *  RelationalOperator: '<S35>/Relational_Operator1'
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Add3'
   *  Switch: '<S35>/Switch1'
   */
  if ((int16_T)(real32_T)floor(rtb_Switch) > 360) {
    rtb_XT -= 360.0F;
  } else {
    if ((int16_T)(real32_T)floor(rtb_XT + 5.0F) < 0) {
      /* Switch: '<S35>/Switch1' incorporates:
       *  Sum: '<S35>/Add1'
       */
      rtb_XT += 360.0F;
    }
  }

  /* End of Switch: '<S35>/Switch' */

  /* Saturate: '<S31>/Saturation' */
  if (rtb_XT > 360.0F) {
    rtb_Switch = 360.0F;
  } else if (rtb_XT < 0.0F) {
    rtb_Switch = 0.0F;
  } else {
    rtb_Switch = rtb_XT;
  }

  /* End of Saturate: '<S31>/Saturation' */

  /* Switch: '<S30>/Switch' */
  if (rtb_enableAngleCalib_BOOL_z) {
    rtb_Switch = RobotControl_B.Data_Type_Conversion_a;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Saturate: '<S30>/Saturation' */
  if (rtb_Switch > 360.0F) {
    RobotControl_B.theta_Deg = 360.0F;
  } else if (rtb_Switch < 0.0F) {
    RobotControl_B.theta_Deg = 0.0F;
  } else {
    RobotControl_B.theta_Deg = rtb_Switch;
  }

  /* End of Saturate: '<S30>/Saturation' */

  /* Gain: '<S30>/Gain' */
  RobotControl_B.theta_mDeg = 100.0F * RobotControl_B.theta_Deg;

  /* Update for UnitDelay: '<S27>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_d =
    RobotControl_B.OutportBufferForenableAngleCali;

  /* Update for UnitDelay: '<S31>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_c = RobotControl_B.COM_A4SCA_A5SCL;

  /* Update for Delay: '<S31>/Resettable_Delay' */
  RobotControl_DW.icLoad = 0U;
  RobotControl_DW.Resettable_Delay_DSTATE = rtb_XT;

  /* Update for Delay: '<S31>/Resettable_Delay1' incorporates:
   *  Constant: '<S31>/Constant'
   *  Product: '<S31>/Product6'
   *  Sum: '<S31>/Subtract3'
   */
  RobotControl_DW.icLoad_o = 0U;
  RobotControl_DW.Resettable_Delay1_DSTATE = (1.0F - rtb_KT) * rtb_PT_p;
}
