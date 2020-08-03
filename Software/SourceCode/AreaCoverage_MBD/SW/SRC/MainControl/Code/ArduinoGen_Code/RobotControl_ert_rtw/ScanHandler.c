/*
 * Code generation for system system '<S16>/ScanHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.503
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 29 10:39:32 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "ScanHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S1>/ULS_AnalogIn' */
void RobotControl_ULS_AnalogIn_Init(void)
{
  /* SystemInitialize for Outport: '<S9>/ULSL_cm' */
  RobotControl_B.ULSL_D8R_D7L = RobotControl_P.ULSL_cm_Y0;

  /* SystemInitialize for Outport: '<S9>/ULSR_cm' */
  RobotControl_B.ULSR_D8R_D7L1 = RobotControl_P.ULSR_cm_Y0;
}

/* Output and update for function-call system: '<S1>/ULS_AnalogIn' */
void RobotControl_ULS_AnalogIn(void)
{
  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Constant: '<S9>/DigitalPin7'
   */
  RobotControl_B.DataTypeConversion_f = (uint8_T)
    RobotControl_P.DigitalPin7_Value;

  /* S-Function (ULSL_Hndler): '<S9>/ULSL_D8R_D7L' */
  ULSL_Hndler_Outputs_wrapper(&RobotControl_B.DataTypeConversion_f,
    &RobotControl_B.ULSL_D8R_D7L );

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Constant: '<S9>/DigitalPin8'
   */
  RobotControl_B.DataTypeConversion1_c = (uint8_T)
    RobotControl_P.DigitalPin8_Value;

  /* S-Function (ULSR_Hndler): '<S9>/ULSR_D8R_D7L1' */
  ULSR_Hndler_Outputs_wrapper(&RobotControl_B.DataTypeConversion1_c,
    &RobotControl_B.ULSR_D8R_D7L1 );
}

/* System initialize for function-call system: '<S16>/ScanHandler' */
void RobotControl_ScanHandler_Init(void)
{
  /* InitializeConditions for Delay: '<S142>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_p = RobotControl_P.Delay1_InitialCondition_m;

  /* InitializeConditions for Delay: '<S142>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[0] = RobotControl_P.Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S141>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[0] = RobotControl_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S142>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[1] = RobotControl_P.Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S141>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[1] = RobotControl_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S142>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[2] = RobotControl_P.Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S141>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[2] = RobotControl_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S142>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[3] = RobotControl_P.Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S141>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[3] = RobotControl_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S141>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_pw = RobotControl_P.Delay1_InitialCondition_f;

  /* SystemInitialize for Outport: '<S23>/leftBlocks' */
  RobotControl_B.leftBlocks = RobotControl_P.leftBlocks_Y0;

  /* SystemInitialize for Outport: '<S23>/rightBlocks' */
  RobotControl_B.rightBlocks = RobotControl_P.rightBlocks_Y0;
}

/* Output and update for function-call system: '<S16>/ScanHandler' */
void RobotControl_ScanHandler(void)
{
  /* local block i/o variables */
  real32_T rtb_Divide_kv;
  real32_T rtb_Data_Type_Conversion_c;
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_DataTypeConversion_l;
  int16_T rtb_Add5_c;
  int16_T rtb_Add5_a;

  /* DataTypeConversion: '<S140>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (int16_T)RobotControl_B.ULSL_D8R_D7L;

  /* Sum: '<S142>/Add5' incorporates:
   *  Delay: '<S142>/Delay'
   *  Delay: '<S142>/Delay1'
   *  Sum: '<S142>/Add4'
   */
  rtb_Add5_c = (rtb_DataTypeConversion1 - RobotControl_DW.Delay_DSTATE_k[0]) +
    RobotControl_DW.Delay1_DSTATE_p;

  /* DataTypeConversion: '<S142>/Data_Type_Conversion' incorporates:
   *  Gain: '<S142>/Gain3'
   */
  rtb_Divide_kv = (real32_T)((int32_T)RobotControl_P.Gain3_Gain_i * rtb_Add5_c) *
    1.52587891E-5F;

  /* Product: '<S140>/Divide1' incorporates:
   *  Constant: '<S140>/CAL_ROBO_LENG1'
   */
  rtb_Data_Type_Conversion_c = rtb_Divide_kv / (real32_T)
    RobotControl_P.CAL_ROBO_LENG;

  /* DataTypeConversion: '<S140>/Data_Type_Conversion' */
  RobotControl_B.leftBlocks = (uint16_T)rtb_Data_Type_Conversion_c;

  /* DataTypeConversion: '<S140>/Data Type Conversion' */
  rtb_DataTypeConversion_l = (int16_T)RobotControl_B.ULSR_D8R_D7L1;

  /* Sum: '<S141>/Add5' incorporates:
   *  Delay: '<S141>/Delay'
   *  Delay: '<S141>/Delay1'
   *  Sum: '<S141>/Add4'
   */
  rtb_Add5_a = (rtb_DataTypeConversion_l - RobotControl_DW.Delay_DSTATE_f[0]) +
    RobotControl_DW.Delay1_DSTATE_pw;

  /* DataTypeConversion: '<S141>/Data_Type_Conversion' incorporates:
   *  Gain: '<S141>/Gain3'
   */
  rtb_Data_Type_Conversion_c = (real32_T)((int32_T)RobotControl_P.Gain3_Gain_e3 *
    rtb_Add5_a) * 1.52587891E-5F;

  /* Product: '<S140>/Divide' incorporates:
   *  Constant: '<S140>/CAL_ROBO_LENG'
   */
  rtb_Divide_kv = rtb_Data_Type_Conversion_c / (real32_T)
    RobotControl_P.CAL_ROBO_LENG;

  /* DataTypeConversion: '<S140>/Data_Type_Conversion1' */
  RobotControl_B.rightBlocks = (uint16_T)rtb_Divide_kv;

  /* Update for Delay: '<S142>/Delay' */
  RobotControl_DW.Delay_DSTATE_k[0] = RobotControl_DW.Delay_DSTATE_k[1];
  RobotControl_DW.Delay_DSTATE_k[1] = RobotControl_DW.Delay_DSTATE_k[2];
  RobotControl_DW.Delay_DSTATE_k[2] = RobotControl_DW.Delay_DSTATE_k[3];
  RobotControl_DW.Delay_DSTATE_k[3] = rtb_DataTypeConversion1;

  /* Update for Delay: '<S142>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_p = rtb_Add5_c;

  /* Update for Delay: '<S141>/Delay' */
  RobotControl_DW.Delay_DSTATE_f[0] = RobotControl_DW.Delay_DSTATE_f[1];
  RobotControl_DW.Delay_DSTATE_f[1] = RobotControl_DW.Delay_DSTATE_f[2];
  RobotControl_DW.Delay_DSTATE_f[2] = RobotControl_DW.Delay_DSTATE_f[3];
  RobotControl_DW.Delay_DSTATE_f[3] = rtb_DataTypeConversion_l;

  /* Update for Delay: '<S141>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_pw = rtb_Add5_a;
}
