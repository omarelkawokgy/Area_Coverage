/*
 * File: thetaFilter.c
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

#include "thetaFilter.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S22>/thetaFilter' */
void RobotControl_thetaFilter_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S36>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_c = CAL_NORTH;

  /* InitializeConditions for Delay: '<S36>/Resettable_Delay' */
  RobotControl_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S36>/Resettable_Delay1' */
  RobotControl_DW.icLoad_o = 1U;
}

/* Output and update for function-call system: '<S22>/thetaFilter' */
void RobotControl_thetaFilter(void)
{
  boolean_T rtb_Relational_Operator_j;
  int16_T rtb_Subtract;
  real32_T rtb_PT_p;
  real32_T rtb_Switch_d;
  real32_T rtb_KT;
  uint16_T rtb_Switch_le;
  real32_T rtb_XT;
  int16_T rtb_Subtract_0;

  /* Sum: '<S36>/Subtract' incorporates:
   *  UnitDelay: '<S36>/Unit_Delay'
   */
  rtb_Subtract = RobotControl_B.rawCompassValue -
    RobotControl_DW.Unit_Delay_DSTATE_c;

  /* Abs: '<S36>/Abs' */
  if (rtb_Subtract < 0) {
    if (rtb_Subtract <= MIN_int16_T) {
      rtb_Subtract_0 = MAX_int16_T;
    } else {
      rtb_Subtract_0 = -rtb_Subtract;
    }
  } else {
    rtb_Subtract_0 = rtb_Subtract;
  }

  /* End of Abs: '<S36>/Abs' */

  /* RelationalOperator: '<S36>/Relational_Operator' incorporates:
   *  Constant: '<S36>/CAL_FilterResetThd'
   */
  rtb_Relational_Operator_j = (rtb_Subtract_0 > CAL_FilterResetThd);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/CAL_fullCircle_DEG'
   *  Constant: '<S36>/CONST_ONE_UINT16'
   *  Constant: '<S36>/CONST_ZeroDeg1'
   *  Logic: '<S36>/Logical_Operator'
   *  RelationalOperator: '<S36>/Relational_Operator1'
   */
  if (rtb_Relational_Operator_j && (rtb_Subtract < CONST_ZeroDeg)) {
    rtb_Switch_le = CONST_ONE_UINT16;
  } else {
    rtb_Switch_le = CAL_fullCircle_DEG;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Delay: '<S36>/Resettable_Delay' */
  if (rtb_Relational_Operator_j &&
      (RobotControl_PrevZCX.Resettable_Delay_Reset_ZCE != POS_ZCSIG)) {
    RobotControl_DW.icLoad = 1U;
  }

  RobotControl_PrevZCX.Resettable_Delay_Reset_ZCE = rtb_Relational_Operator_j;
  if (RobotControl_DW.icLoad != 0) {
    RobotControl_DW.Resettable_Delay_DSTATE = rtb_Switch_le;
  }

  /* Sum: '<S36>/Add2' incorporates:
   *  Constant: '<S36>/CAL_EncoderSampleTime'
   *  Constant: '<S39>/CAL_ROBO_LENG_mm'
   *  Delay: '<S36>/Resettable_Delay'
   *  Product: '<S36>/Product'
   *  Product: '<S38>/Product'
   *  Product: '<S39>/Divide1'
   *  Sum: '<S39>/Add'
   */
  rtb_Switch_d = (real32_T)((RobotControl_B.leftVel1ms_mmPerSec -
    RobotControl_B.rightVel1ms_mmPerSec) / (real32_T)CAL_ROBO_LENG_mm *
    CAL_EncoderSampleTime * RobotControl_ConstB.Divide +
    RobotControl_DW.Resettable_Delay_DSTATE);

  /* Delay: '<S36>/Resettable_Delay1' incorporates:
   *  DataTypeConversion: '<S36>/Data Type Conversion'
   */
  if (rtb_Relational_Operator_j &&
      (RobotControl_PrevZCX.Resettable_Delay1_Reset_ZCE != POS_ZCSIG)) {
    RobotControl_DW.icLoad_o = 1U;
  }

  RobotControl_PrevZCX.Resettable_Delay1_Reset_ZCE = rtb_Relational_Operator_j;
  if (RobotControl_DW.icLoad_o != 0) {
    RobotControl_DW.Resettable_Delay1_DSTATE = rtb_Switch_le;
  }

  /* Product: '<S36>/Product4' incorporates:
   *  Constant: '<S36>/CAL_ProcessNoise'
   *  Delay: '<S36>/Resettable_Delay1'
   */
  rtb_PT_p = CAL_ProcessNoise * RobotControl_DW.Resettable_Delay1_DSTATE;

  /* Product: '<S36>/Divide1' incorporates:
   *  Constant: '<S36>/CAL_MeasureNoise'
   *  Sum: '<S36>/Add3'
   */
  rtb_KT = (CAL_MeasureNoise + rtb_PT_p) / rtb_PT_p;

  /* Sum: '<S36>/Add4' incorporates:
   *  Product: '<S36>/Product5'
   *  Sum: '<S36>/Subtract2'
   */
  rtb_XT = ((real32_T)RobotControl_B.rawCompassValue - rtb_Switch_d) * rtb_KT +
    rtb_Switch_d;

  /* DataTypeConversion: '<S40>/Data_Type_Conversion2' incorporates:
   *  Constant: '<S40>/CAL_fullCircle_DEG'
   */
  rtb_Subtract = (int16_T)CAL_fullCircle_DEG;

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/CAL_fullCircle_DEG1'
   *  Constant: '<S40>/CONST_OVERFLOW_THD_UINT16'
   *  Constant: '<S40>/CONST_OVERFLOW_THD_UINT161'
   *  Constant: '<S40>/CONST_ZERO_UINT16'
   *  DataTypeConversion: '<S40>/Data_Type_Conversion'
   *  DataTypeConversion: '<S40>/Data_Type_Conversion1'
   *  DataTypeConversion: '<S40>/Data_Type_Conversion3'
   *  RelationalOperator: '<S40>/Relational_Operator'
   *  RelationalOperator: '<S40>/Relational_Operator1'
   *  Sum: '<S40>/Add'
   *  Sum: '<S40>/Add2'
   *  Sum: '<S40>/Add3'
   *  Switch: '<S40>/Switch1'
   */
  if ((int16_T)(real32_T)floor(rtb_XT - (real32_T)CONST_OVERFLOW_THD_UINT16) >
      rtb_Subtract) {
    rtb_XT -= (real32_T)CAL_fullCircle_DEG;
  } else {
    if ((int16_T)(real32_T)floor(rtb_XT + (real32_T)CONST_OVERFLOW_THD_UINT16) <
        (int16_T)CONST_ZERO_UINT16) {
      /* Switch: '<S40>/Switch1' incorporates:
       *  Sum: '<S40>/Add1'
       */
      rtb_XT += (real32_T)rtb_Subtract;
    }
  }

  /* End of Switch: '<S40>/Switch' */

  /* Switch: '<S35>/Switch' incorporates:
   *  Saturate: '<S36>/Saturation'
   *  UnitDelay: '<S32>/Unit_Delay3'
   */
  if (RobotControl_DW.Unit_Delay3_DSTATE_d) {
    rtb_Switch_d = RobotControl_B.Data_Type_Conversion_a;
  } else if (rtb_XT > 360.0F) {
    /* Saturate: '<S36>/Saturation' */
    rtb_Switch_d = 360.0F;
  } else if (rtb_XT < 0.0F) {
    /* Saturate: '<S36>/Saturation' */
    rtb_Switch_d = 0.0F;
  } else {
    /* Saturate: '<S36>/Saturation' */
    rtb_Switch_d = rtb_XT;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Switch_d > CAL_fullCircle_DEG) {
    RobotControl_B.theta_Deg = CAL_fullCircle_DEG;
  } else if (rtb_Switch_d < CONST_ZERO_UINT16) {
    RobotControl_B.theta_Deg = CONST_ZERO_UINT16;
  } else {
    RobotControl_B.theta_Deg = rtb_Switch_d;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Gain: '<S35>/Gain' */
  RobotControl_B.theta_mDeg = (real32_T)((uint8_T)CAL_thetaGain) *
    RobotControl_B.theta_Deg;

  /* Update for UnitDelay: '<S32>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_d =
    RobotControl_B.OutportBufferForenableAngleCali;

  /* Update for UnitDelay: '<S36>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_c = RobotControl_B.rawCompassValue;

  /* Update for Delay: '<S36>/Resettable_Delay' */
  RobotControl_DW.icLoad = 0U;
  RobotControl_DW.Resettable_Delay_DSTATE = rtb_XT;

  /* Update for Delay: '<S36>/Resettable_Delay1' incorporates:
   *  Constant: '<S36>/Constant'
   *  Product: '<S36>/Product6'
   *  Sum: '<S36>/Subtract3'
   */
  RobotControl_DW.icLoad_o = 0U;
  RobotControl_DW.Resettable_Delay1_DSTATE = (1.0F - rtb_KT) * rtb_PT_p;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
