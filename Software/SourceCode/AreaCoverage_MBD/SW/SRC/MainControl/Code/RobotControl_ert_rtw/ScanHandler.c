/*
 * File: ScanHandler.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.565
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Aug 08 11:48:30 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScanHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Output and update for function-call system: '<S22>/ScanHandler' */
void RobotControl_ScanHandler(void)
{
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_Add5_m;
  int16_T rtb_DataTypeConversion_c;
  int16_T rtb_Add5_c;

  /* DataTypeConversion: '<S146>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (int16_T)RobotControl_B.ULSL_cm;

  /* Sum: '<S148>/Add5' incorporates:
   *  Delay: '<S148>/Delay'
   *  Delay: '<S148>/Delay1'
   *  Sum: '<S148>/Add4'
   */
  rtb_Add5_m = (rtb_DataTypeConversion1 - RobotControl_DW.Delay_DSTATE_k[0]) +
    RobotControl_DW.Delay1_DSTATE_p;

  /* DataTypeConversion: '<S146>/Data_Type_Conversion' incorporates:
   *  Constant: '<S146>/CAL_ROBO_LENG1'
   *  DataTypeConversion: '<S148>/Data_Type_Conversion'
   *  Gain: '<S148>/Gain3'
   *  Product: '<S146>/Divide1'
   */
  RobotControl_B.leftBlocks = (uint16_T)((real32_T)((int32_T)rtb_Add5_m << 14) *
    1.52587891E-5F / (real32_T)((uint8_T)CAL_ROBO_LENG));

  /* DataTypeConversion: '<S146>/Data Type Conversion' */
  rtb_DataTypeConversion_c = (int16_T)RobotControl_B.ULSR_cm;

  /* Sum: '<S147>/Add5' incorporates:
   *  Delay: '<S147>/Delay'
   *  Delay: '<S147>/Delay1'
   *  Sum: '<S147>/Add4'
   */
  rtb_Add5_c = (rtb_DataTypeConversion_c - RobotControl_DW.Delay_DSTATE_f[0]) +
    RobotControl_DW.Delay1_DSTATE_pw;

  /* DataTypeConversion: '<S146>/Data_Type_Conversion1' incorporates:
   *  Constant: '<S146>/CAL_ROBO_LENG'
   *  DataTypeConversion: '<S147>/Data_Type_Conversion'
   *  Gain: '<S147>/Gain3'
   *  Product: '<S146>/Divide'
   */
  RobotControl_B.rightBlocks = (uint16_T)((real32_T)((int32_T)rtb_Add5_c << 14) *
    1.52587891E-5F / (real32_T)((uint8_T)CAL_ROBO_LENG));

  /* Update for Delay: '<S148>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[0] = RobotControl_DW.Delay_DSTATE_k[1];
  RobotControl_DW.Delay_DSTATE_k[1] = RobotControl_DW.Delay_DSTATE_k[2];
  RobotControl_DW.Delay_DSTATE_k[2] = RobotControl_DW.Delay_DSTATE_k[3];
  RobotControl_DW.Delay_DSTATE_k[3] = rtb_DataTypeConversion1;

  /* Update for Delay: '<S148>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_p = rtb_Add5_m;

  /* Update for Delay: '<S147>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[0] = RobotControl_DW.Delay_DSTATE_f[1];
  RobotControl_DW.Delay_DSTATE_f[1] = RobotControl_DW.Delay_DSTATE_f[2];
  RobotControl_DW.Delay_DSTATE_f[2] = RobotControl_DW.Delay_DSTATE_f[3];
  RobotControl_DW.Delay_DSTATE_f[3] = rtb_DataTypeConversion_c;

  /* Update for Delay: '<S147>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_pw = rtb_Add5_c;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
