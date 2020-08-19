/*
 * File: DSCA.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.581
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 17 10:27:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DSCA.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S88>/SpdTickDetector' */
#define RobotCont_IN_NO_ACTIVE_CHILD_cm ((uint8_T)0U)
#define RobotControl_CAL_mmPerTickPerTs (802.108704F)
#define RobotControl_CONST_VEL_TIMEOUT ((uint8_T)100U)
#define RobotControl_IN_counting       ((uint8_T)1U)
#define RobotControl_IN_stop           ((uint8_T)2U)

/* Named constants for Chart: '<S74>/EOL_TickStateMachine' */
#define RobotContr_IN_NO_ACTIVE_CHILD_i ((uint8_T)0U)
#define RobotControl_CONST_EOL_ME_Ticks (150U)
#define RobotControl_CONST_EnDelay     (10000U)
#define RobotControl_ENU_FORWARD       ((uint8_T)1U)
#define RobotControl_ENU_STOP          ((uint8_T)5U)
#define RobotControl_IN_FastPwm        ((uint8_T)1U)
#define RobotControl_IN_InitializeTest ((uint8_T)2U)
#define RobotControl_IN_MediumPwm      ((uint8_T)3U)
#define RobotControl_IN_SlowPwm        ((uint8_T)4U)
#define RobotControl_IN_SuperFastPwm   ((uint8_T)5U)

/* Named constants for Chart: '<S79>/EOL_TickStateMachine' */
#define RobotContr_CONST_EOL_ME_Ticks_m (150U)
#define RobotContr_IN_NO_ACTIVE_CHILD_o ((uint8_T)0U)
#define RobotContro_IN_InitializeTest_j ((uint8_T)2U)
#define RobotControl_CONST_EnDelay_b   (10000U)
#define RobotControl_ENU_FORWARD_o     ((uint8_T)1U)
#define RobotControl_ENU_STOP_n        ((uint8_T)5U)
#define RobotControl_IN_FastPwm_c      ((uint8_T)1U)
#define RobotControl_IN_MediumPwm_o    ((uint8_T)3U)
#define RobotControl_IN_SlowPwm_m      ((uint8_T)4U)
#define RobotControl_IN_SuperFastPwm_h ((uint8_T)5U)

/* System initialize for function-call system: '<S1>/EncoderAnalogIn' */
void RobotContr_EncoderAnalogIn_Init(void)
{
  /* SystemInitialize for Chart: '<S8>/rightEncoderTicks_uint16_chart' */
  RobotControl_B.rightEncoderTicks_uint16 = 0U;

  /* SystemInitialize for Chart: '<S8>/leftEncoderTicks_uint16_chart' */
  RobotControl_B.leftEncoderTicks_uint16 = 0U;
}

/* Output and update for function-call system: '<S1>/EncoderAnalogIn' */
void RobotControl_EncoderAnalogIn(void)
{
  /* Chart: '<S8>/rightEncoderTicks_uint16_chart' incorporates:
   *  Constant: '<S8>/AnalogPINA0'
   */
  /* Gateway: InputHandler/EncoderAnalogIn/rightEncoderTicks_uint16_chart */
  /* During: InputHandler/EncoderAnalogIn/rightEncoderTicks_uint16_chart */
  /* Entry Internal: InputHandler/EncoderAnalogIn/rightEncoderTicks_uint16_chart */
  /* Transition: '<S13>:2' */
  /* Transition: '<S13>:4' */
  RobotControl_B.rightEncoderTicks_uint16 = (uint16_T)analogRead(((uint8_T)
    CONST_PIN_A0));

  /* Chart: '<S8>/leftEncoderTicks_uint16_chart' incorporates:
   *  Constant: '<S8>/AnalogPinA1'
   */
  /* Gateway: InputHandler/EncoderAnalogIn/leftEncoderTicks_uint16_chart */
  /* During: InputHandler/EncoderAnalogIn/leftEncoderTicks_uint16_chart */
  /* Entry Internal: InputHandler/EncoderAnalogIn/leftEncoderTicks_uint16_chart */
  /* Transition: '<S12>:2' */
  /* Transition: '<S12>:4' */
  RobotControl_B.leftEncoderTicks_uint16 = (uint16_T)analogRead(((uint8_T)
    CONST_PIN_A1));
}

/*
 * Output and update for trigger system:
 *    '<S60>/EncoderIncrement'
 *    '<S61>/EncoderIncrement'
 */
void RobotControl_EncoderIncrement(boolean_T rtu_EncoderTicks_Bool, uint8_T
  rtu_motorDirection, B_EncoderIncrement_RobotContr_T *localB,
  ZCE_EncoderIncrement_RobotCon_T *localZCE)
{
  int32_T rtu_motorDirection_0;

  /* Outputs for Triggered SubSystem: '<S60>/EncoderIncrement' incorporates:
   *  TriggerPort: '<S64>/EncoderTicks_Bool'
   */
  if (rtu_EncoderTicks_Bool && (localZCE->EncoderIncrement_Trig_ZCE != POS_ZCSIG))
  {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S64>/CONST_NEG_ONE_INT32'
     *  Constant: '<S64>/CONST_ONE_INT32'
     *  Constant: '<S64>/ENU_FORWARD'
     *  RelationalOperator: '<S64>/Relational_Operator'
     */
    if (rtu_motorDirection == ((uint8_T)ENU_FORWARD)) {
      rtu_motorDirection_0 = ((int32_T)CONST_ONE_INT32);
    } else {
      rtu_motorDirection_0 = ((int32_T)CONST_NEG_ONE_INT32);
    }

    /* End of Switch: '<S64>/Switch1' */

    /* Sum: '<S64>/Add' incorporates:
     *  UnitDelay: '<S64>/Unit_Delay'
     */
    localB->distCounter += rtu_motorDirection_0;
  }

  localZCE->EncoderIncrement_Trig_ZCE = rtu_EncoderTicks_Bool;

  /* End of Outputs for SubSystem: '<S60>/EncoderIncrement' */
}

/*
 * System initialize for atomic system:
 *    '<S88>/SpdTickDetector'
 *    '<S97>/SpdTickDetector'
 */
void RobotContr_SpdTickDetector_Init(B_SpdTickDetector_RobotContro_T *localB,
  DW_SpdTickDetector_RobotContr_T *localDW)
{
  localDW->is_active_c18_RobotControl = 0U;
  localDW->is_c18_RobotControl = RobotCont_IN_NO_ACTIVE_CHILD_cm;
  localDW->cycleCnt = 0U;
  localB->spd = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S88>/SpdTickDetector'
 *    '<S97>/SpdTickDetector'
 */
void RobotControl_SpdTickDetector(real32_T rtu_encoderTick,
  B_SpdTickDetector_RobotContro_T *localB, DW_SpdTickDetector_RobotContr_T
  *localDW)
{
  /* Gateway: RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  localDW->encoderTick_prev = localDW->encoderTick_start;
  localDW->encoderTick_start = rtu_encoderTick;

  /* During: RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  /* calculates speed of motor from ticks of encoder. it is not the best technique so it need some kind of filtration for the output spd data. */
  if (localDW->is_active_c18_RobotControl == 0U) {
    localDW->encoderTick_prev = rtu_encoderTick;

    /* Entry: RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    localDW->is_active_c18_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    /* Transition: '<S92>:2' */
    localDW->is_c18_RobotControl = RobotControl_IN_counting;

    /* Entry 'counting': '<S92>:3' */
    localDW->cycleCnt = 1U;
  } else if (localDW->is_c18_RobotControl == RobotControl_IN_counting) {
    /* During 'counting': '<S92>:3' */
    if ((localDW->encoderTick_prev != localDW->encoderTick_start) &&
        (localDW->encoderTick_start == 1.0F)) {
      /* Transition: '<S92>:7' */
      localB->spd = RobotControl_CAL_mmPerTickPerTs / (real32_T)
        localDW->cycleCnt;
      localDW->is_c18_RobotControl = RobotControl_IN_counting;

      /* Entry 'counting': '<S92>:3' */
      localDW->cycleCnt = 1U;
    } else if (localDW->cycleCnt > RobotControl_CONST_VEL_TIMEOUT) {
      /* Transition: '<S92>:9' */
      localDW->is_c18_RobotControl = RobotControl_IN_stop;

      /* Entry 'stop': '<S92>:8' */
      localB->spd = 0.0F;
    } else {
      localDW->cycleCnt++;
    }
  } else {
    /* During 'stop': '<S92>:8' */
    if (localDW->encoderTick_prev != localDW->encoderTick_start) {
      /* Transition: '<S92>:10' */
      localDW->is_c18_RobotControl = RobotControl_IN_counting;

      /* Entry 'counting': '<S92>:3' */
      localDW->cycleCnt = 1U;
    }
  }
}

/* System initialize for function-call system: '<S22>/DSCA' */
void RobotControl_DSCA_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S99>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 1U;

  /* InitializeConditions for UnitDelay: '<S99>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = 1.0F;

  /* InitializeConditions for UnitDelay: '<S90>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* InitializeConditions for UnitDelay: '<S90>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = 1.0F;

  /* SystemInitialize for Chart: '<S97>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector,
    &RobotControl_DW.sf_SpdTickDetector);

  /* SystemInitialize for Chart: '<S88>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector_o,
    &RobotControl_DW.sf_SpdTickDetector_o);

  /* SystemInitialize for Enabled SubSystem: '<S25>/EncoderThetaCalculation' */
  /* InitializeConditions for UnitDelay: '<S56>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = CAL_NORTH_rad;

  /* End of SystemInitialize for SubSystem: '<S25>/EncoderThetaCalculation' */

  /* SystemInitialize for Atomic SubSystem: '<S57>/LeftEndofLineTest' */
#if motorsHandleEOL_Variant
#if leftMotorEOL_variant

  /* System initialize for atomic system: '<S70>/LeftEndofLineTest' */

  /* InitializeConditions for UnitDelay: '<S72>/Unit_Delay' */
  RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE_k = true;

  /* SystemInitialize for Enabled SubSystem: '<S72>/LeftMotorEncoderCounter' */
  /* InitializeConditions for UnitDelay: '<S75>/Unit_Delay' */
  RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S72>/LeftMotorEncoderCounter' */

  /* SystemInitialize for Chart: '<S74>/EOL_TickStateMachine' */
  RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;
  RobotControl_DW.LeftEndofLineTest_g.is_active_c15_RobotControl = 0U;
  RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
    RobotContr_IN_NO_ACTIVE_CHILD_i;
  RobotControl_B.VariantMergeForOutportleft_EOL_ = 0.0F;
  RobotControl_B.VariantMerge_For_Variant_Source = 0U;
  RobotControl_B.LeftEndofLineTest_g.counterReset = false;

#endif                                 /* leftMotorEOL_variant */
#endif                                 /* motorsHandleEOL_Variant */

  /* End of SystemInitialize for SubSystem: '<S57>/LeftEndofLineTest' */

  /* SystemInitialize for Atomic SubSystem: '<S57>/rightEndofLineTest1' */
#if motorsHandleEOL_Variant
#if rightMotorEOL_variant

  /* System initialize for atomic system: '<S71>/RightEndofLineTest' */

  /* InitializeConditions for UnitDelay: '<S77>/Unit_Delay' */
  RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE_l = true;

  /* SystemInitialize for Enabled SubSystem: '<S77>/RightMotorEncoderCounter1' */
  /* InitializeConditions for UnitDelay: '<S80>/Unit_Delay' */
  RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S77>/RightMotorEncoderCounter1' */

  /* SystemInitialize for Chart: '<S79>/EOL_TickStateMachine' */
  RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;
  RobotControl_DW.RightEndofLineTest.is_active_c16_RobotControl = 0U;
  RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
    RobotContr_IN_NO_ACTIVE_CHILD_o;
  RobotControl_B.VariantMergeForOutportright_EOL = 0.0F;
  RobotControl_B.VariantMerge_For_Variant_Sour_b = 0U;
  RobotControl_B.RightEndofLineTest.counterReset = false;

#endif                                 /* rightMotorEOL_variant */
#endif                                 /* motorsHandleEOL_Variant */

  /* End of SystemInitialize for SubSystem: '<S57>/rightEndofLineTest1' */
}

/* Output and update for function-call system: '<S22>/DSCA' */
void RobotControl_DSCA(void)
{
  /* local block i/o variables */
  boolean_T rtb_Switch_b;
  boolean_T rtb_Switch1_l;
  boolean_T rtb_leftOldEncoderTicks_Bool_z;
  boolean_T rtb_rightOldEncoderTicks_Bool_z;
  uint8_T rtb_leftNegPin_z;
  uint8_T rtb_leftPosPin_z;
  real32_T rtb_Add5_b;
  uint8_T rtb_rightNegPin;
  uint8_T rtb_rightPosPin_z;
  real32_T rtb_motorDistance_f;
  real32_T rtb_Add5_n;
  real32_T rtb_inputVoltage_V;
  uint8_T rtb_MotorDirection_m;
  real32_T rtb_Init;
  real32_T rtb_Product4;
  real32_T rtb_KT;
  uint8_T rtb_MotorDirection;
  real32_T rtb_Init_j;
  real32_T rtb_Product4_p;
  real32_T rtb_KT_e2;
  real32_T MotorTransferFunction_tmp;
  real32_T MotorTransferFunction_tmp_b;
  real32_T rtb_MotorDirection_0;

  /* UnitDelay: '<S25>/Unit_Delay5' */
  rtb_leftPosPin_z = RobotControl_DW.Unit_Delay5_DSTATE_p;

  /* UnitDelay: '<S25>/Unit_Delay6' */
  rtb_leftNegPin_z = RobotControl_DW.Unit_Delay6_DSTATE;

  /* Switch: '<S102>/Switch5' incorporates:
   *  Constant: '<S102>/ENU_FORWARD'
   *  Constant: '<S102>/ENU_STOP'
   *  RelationalOperator: '<S102>/Relational_Operator5'
   *  RelationalOperator: '<S102>/Relational_Operator6'
   *  Switch: '<S102>/Switch6'
   */
  if (rtb_leftPosPin_z > rtb_leftNegPin_z) {
    rtb_MotorDirection = ((uint8_T)ENU_FORWARD);
  } else if (rtb_leftPosPin_z < rtb_leftNegPin_z) {
    /* Switch: '<S102>/Switch6' incorporates:
     *  Constant: '<S102>/ENU_BACKWARD'
     */
    rtb_MotorDirection = ((uint8_T)ENU_BACKWARD);
  } else {
    rtb_MotorDirection = ((uint8_T)ENU_STOP);
  }

  /* End of Switch: '<S102>/Switch5' */

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/CAL_EncoderAnaThd'
   *  RelationalOperator: '<S55>/Relational Operator'
   */
  rtb_Switch_b = (RobotControl_B.leftEncoderTicks_uint16 > CAL_EncoderAnaThd);

  /* Outputs for Triggered SubSystem: '<S60>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch_b, rtb_MotorDirection,
    &RobotControl_B.EncoderIncrement, &RobotControl_PrevZCX.EncoderIncrement);

  /* End of Outputs for SubSystem: '<S60>/EncoderIncrement' */

  /* Gain: '<S60>/Gain1' incorporates:
   *  DataTypeConversion: '<S60>/Data_Type_Conversion'
   */
  RobotControl_B.motorDistance = CAL_mm_PER_tick * (real32_T)
    RobotControl_B.EncoderIncrement.distCounter;

  /* Sum: '<S62>/Add5' incorporates:
   *  Delay: '<S62>/Delay'
   *  Delay: '<S62>/Delay1'
   *  Sum: '<S62>/Add4'
   */
  rtb_Add5_b = (RobotControl_B.motorDistance - RobotControl_DW.Delay_DSTATE_a[0])
    + RobotControl_DW.Delay1_DSTATE_e;

  /* DataTypeConversion: '<S62>/Data_Type_Conversion' incorporates:
   *  Gain: '<S62>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion = 0.2F * rtb_Add5_b;

  /* UnitDelay: '<S25>/Unit_Delay7' */
  rtb_rightPosPin_z = RobotControl_DW.Unit_Delay7_DSTATE;

  /* UnitDelay: '<S25>/Unit_Delay8' */
  rtb_rightNegPin = RobotControl_DW.Unit_Delay8_DSTATE;

  /* Switch: '<S103>/Switch5' incorporates:
   *  Constant: '<S103>/ENU_FORWARD'
   *  Constant: '<S103>/ENU_STOP'
   *  RelationalOperator: '<S103>/Relational_Operator5'
   *  RelationalOperator: '<S103>/Relational_Operator6'
   *  Switch: '<S103>/Switch6'
   */
  if (rtb_rightPosPin_z > rtb_rightNegPin) {
    rtb_MotorDirection_m = ((uint8_T)ENU_FORWARD);
  } else if (rtb_rightPosPin_z < rtb_rightNegPin) {
    /* Switch: '<S103>/Switch6' incorporates:
     *  Constant: '<S103>/ENU_BACKWARD'
     */
    rtb_MotorDirection_m = ((uint8_T)ENU_BACKWARD);
  } else {
    rtb_MotorDirection_m = ((uint8_T)ENU_STOP);
  }

  /* End of Switch: '<S103>/Switch5' */

  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S55>/CAL_EncoderAnaThd1'
   *  RelationalOperator: '<S55>/Relational Operator1'
   */
  rtb_Switch1_l = (RobotControl_B.rightEncoderTicks_uint16 > CAL_EncoderAnaThd);

  /* Outputs for Triggered SubSystem: '<S61>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch1_l, rtb_MotorDirection_m,
    &RobotControl_B.EncoderIncrement_i, &RobotControl_PrevZCX.EncoderIncrement_i);

  /* End of Outputs for SubSystem: '<S61>/EncoderIncrement' */

  /* Gain: '<S61>/Gain1' incorporates:
   *  DataTypeConversion: '<S61>/Data_Type_Conversion'
   */
  rtb_motorDistance_f = CAL_mm_PER_tick * (real32_T)
    RobotControl_B.EncoderIncrement_i.distCounter;

  /* Sum: '<S63>/Add5' incorporates:
   *  Delay: '<S63>/Delay'
   *  Delay: '<S63>/Delay1'
   *  Sum: '<S63>/Add4'
   */
  rtb_Add5_n = (rtb_motorDistance_f - RobotControl_DW.Delay_DSTATE_l[0]) +
    RobotControl_DW.Delay1_DSTATE_i;

  /* DataTypeConversion: '<S63>/Data_Type_Conversion' incorporates:
   *  Gain: '<S63>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_m = 0.2F * rtb_Add5_n;

  /* DiscreteTransferFcn: '<S100>/MotorTransferFunction' incorporates:
   *  Gain: '<S96>/Gain'
   *  Sum: '<S96>/Add2'
   */
  MotorTransferFunction_tmp = (((real32_T)(rtb_rightPosPin_z - rtb_rightNegPin) *
    0.0470581055F - -237187.5F * RobotControl_DW.MotorTransferFunction_states[0L])
    - -549093.75F * RobotControl_DW.MotorTransferFunction_states[1L]) /
    951906.25F;

  /* Product: '<S96>/Product' incorporates:
   *  Constant: '<S96>/CAL_WheelDiameter_cm'
   *  Constant: '<S96>/CAL_gearRatio'
   *  Constant: '<S96>/CONST_TWO_F32'
   *  DataTypeConversion: '<S96>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S100>/MotorTransferFunction'
   *  Gain: '<S96>/Gain1'
   *  Product: '<S96>/Divide'
   *  Product: '<S96>/Divide1'
   */
  rtb_inputVoltage_V = ((78125.0F * MotorTransferFunction_tmp + 156250.0F *
    RobotControl_DW.MotorTransferFunction_states[0L]) + 78125.0F *
                        RobotControl_DW.MotorTransferFunction_states[1L]) /
    (real32_T)CAL_gearRatio * ((real32_T)(uint8_T)(10U * ((uint8_T)
    CAL_WheelDiameter_cm)) / CONST_TWO_F32);

  /* Chart: '<S97>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S97>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch1_l,
    &RobotControl_B.sf_SpdTickDetector, &RobotControl_DW.sf_SpdTickDetector);

  /* Switch: '<S99>/Init' incorporates:
   *  Constant: '<S95>/CONST_FALSE'
   *  Constant: '<S99>/Initial Condition'
   *  Logic: '<S99>/FixPt Logical Operator'
   *  UnitDelay: '<S99>/FixPt Unit Delay1'
   *  UnitDelay: '<S99>/FixPt Unit Delay2'
   */
  if (CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_l != 0)) {
    rtb_Init = 1.0F;
  } else {
    rtb_Init = RobotControl_DW.FixPtUnitDelay1_DSTATE_n;
  }

  /* End of Switch: '<S99>/Init' */

  /* Product: '<S95>/Product4' incorporates:
   *  Constant: '<S95>/CAL_procNoiseVelKF'
   */
  rtb_Product4 = CAL_procNoiseVelKF * rtb_Init;

  /* Product: '<S95>/Divide1' incorporates:
   *  Constant: '<S95>/CAL_MeasNoiseVelKF'
   *  Sum: '<S95>/Add3'
   */
  rtb_KT = (CAL_MeasNoiseVelKF + rtb_Product4) / rtb_Product4;

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/ENU_FORWARD'
   *  Gain: '<S93>/Gain2'
   *  RelationalOperator: '<S93>/Relational_Operator'
   */
  if (rtb_MotorDirection_m == ((uint8_T)ENU_FORWARD)) {
    MotorTransferFunction_tmp_b = RobotControl_B.sf_SpdTickDetector.spd;
  } else {
    MotorTransferFunction_tmp_b = -RobotControl_B.sf_SpdTickDetector.spd;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Sum: '<S95>/Add4' incorporates:
   *  Product: '<S95>/Product5'
   *  Sum: '<S95>/Subtract2'
   */
  rtb_inputVoltage_V += (MotorTransferFunction_tmp_b - rtb_inputVoltage_V) *
    rtb_KT;

  /* DataTypeConversion: '<S95>/Data_Type_Conversion3' */
  RobotControl_B.rightVel1ms_mmPerSec = rtb_inputVoltage_V;

  /* DiscreteTransferFcn: '<S91>/MotorTransferFunction' incorporates:
   *  Gain: '<S87>/Gain'
   *  Sum: '<S87>/Add2'
   */
  MotorTransferFunction_tmp_b = (((real32_T)(rtb_leftPosPin_z - rtb_leftNegPin_z)
    * 0.0470581055F - -237187.5F *
    RobotControl_DW.MotorTransferFunction_states_j[0L]) - -549093.75F *
    RobotControl_DW.MotorTransferFunction_states_j[1L]) / 951906.25F;

  /* Product: '<S87>/Product' incorporates:
   *  Constant: '<S87>/CAL_WheelDiameter_cm'
   *  Constant: '<S87>/CAL_gearRatio'
   *  Constant: '<S87>/CONST_TWO_F32'
   *  DataTypeConversion: '<S87>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S91>/MotorTransferFunction'
   *  Gain: '<S87>/Gain1'
   *  Product: '<S87>/Divide'
   *  Product: '<S87>/Divide1'
   */
  rtb_inputVoltage_V = ((78125.0F * MotorTransferFunction_tmp_b + 156250.0F *
    RobotControl_DW.MotorTransferFunction_states_j[0L]) + 78125.0F *
                        RobotControl_DW.MotorTransferFunction_states_j[1L]) /
    (real32_T)CAL_gearRatio * ((real32_T)(uint8_T)(10U * ((uint8_T)
    CAL_WheelDiameter_cm)) / CONST_TWO_F32);

  /* Chart: '<S88>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S88>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch_b,
    &RobotControl_B.sf_SpdTickDetector_o, &RobotControl_DW.sf_SpdTickDetector_o);

  /* Switch: '<S90>/Init' incorporates:
   *  Constant: '<S86>/CONST_FALSE'
   *  Constant: '<S90>/Initial Condition'
   *  Logic: '<S90>/FixPt Logical Operator'
   *  UnitDelay: '<S90>/FixPt Unit Delay1'
   *  UnitDelay: '<S90>/FixPt Unit Delay2'
   */
  if (CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_a != 0)) {
    rtb_Init_j = 1.0F;
  } else {
    rtb_Init_j = RobotControl_DW.FixPtUnitDelay1_DSTATE_b;
  }

  /* End of Switch: '<S90>/Init' */

  /* Product: '<S86>/Product4' incorporates:
   *  Constant: '<S86>/CAL_procNoiseVelKF'
   */
  rtb_Product4_p = CAL_procNoiseVelKF * rtb_Init_j;

  /* Product: '<S86>/Divide1' incorporates:
   *  Constant: '<S86>/CAL_MeasNoiseVelKF'
   *  Sum: '<S86>/Add3'
   */
  rtb_KT_e2 = (CAL_MeasNoiseVelKF + rtb_Product4_p) / rtb_Product4_p;

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/ENU_FORWARD'
   *  Gain: '<S84>/Gain2'
   *  RelationalOperator: '<S84>/Relational_Operator'
   */
  if (rtb_MotorDirection == ((uint8_T)ENU_FORWARD)) {
    rtb_MotorDirection_0 = RobotControl_B.sf_SpdTickDetector_o.spd;
  } else {
    rtb_MotorDirection_0 = -RobotControl_B.sf_SpdTickDetector_o.spd;
  }

  /* End of Switch: '<S84>/Switch' */

  /* DataTypeConversion: '<S86>/Data_Type_Conversion2' incorporates:
   *  Product: '<S86>/Product5'
   *  Sum: '<S86>/Add4'
   *  Sum: '<S86>/Subtract2'
   */
  RobotControl_B.leftVel1ms_mmPerSec = (rtb_MotorDirection_0 -
    rtb_inputVoltage_V) * rtb_KT_e2 + rtb_inputVoltage_V;

  /* Outputs for Enabled SubSystem: '<S25>/EncoderThetaCalculation' incorporates:
   *  EnablePort: '<S56>/EncoderThetaEnable'
   */
  /* Logic: '<S25>/Logical_Operator1' incorporates:
   *  Constant: '<S25>/ENU_DIAG'
   *  Logic: '<S25>/Logical_Operator'
   *  RelationalOperator: '<S25>/Relational_Operator'
   *  UnitDelay: '<S25>/Unit_Delay2'
   */
  if ((RobotControl_DW.Unit_Delay2_DSTATE_b == ((uint8_T)ENU_DIAG)) ||
      (!RobotControl_B.NVM_AngleStoreFlg)) {
    /* Sum: '<S56>/Add1' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S67>/CAL_ROBO_LENG_mm'
     *  Product: '<S56>/Product'
     *  Product: '<S67>/Divide1'
     *  Sum: '<S67>/Add'
     *  UnitDelay: '<S56>/Unit_Delay'
     */
    RobotControl_B.Add1 = (RobotControl_B.leftVel1ms_mmPerSec -
      RobotControl_B.rightVel1ms_mmPerSec) / (real32_T)CAL_ROBO_LENG_mm * 0.001
      + RobotControl_DW.Unit_Delay_DSTATE;

    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S69>/Constant1'
     *  Constant: '<S69>/Constant2'
     *  Constant: '<S69>/Constant3'
     *  RelationalOperator: '<S69>/Relational Operator'
     *  RelationalOperator: '<S69>/Relational Operator1'
     *  Sum: '<S69>/Add'
     *  Switch: '<S69>/Switch1'
     */
    if (RobotControl_B.Add1 > 6.2831853071795862) {
      RobotControl_B.Add1 -= 6.2831853071795862;
    } else {
      if (RobotControl_B.Add1 < 0.0) {
        /* Switch: '<S69>/Switch1' incorporates:
         *  Sum: '<S69>/Add1'
         */
        RobotControl_B.Add1 += 6.2831853071795862;
      }
    }

    /* End of Switch: '<S69>/Switch' */

    /* Product: '<S66>/Product' */
    RobotControl_B.deg = RobotControl_ConstB.Divide_k * RobotControl_B.Add1;

    /* Sum: '<S68>/Add5' incorporates:
     *  Delay: '<S68>/Delay'
     *  Delay: '<S68>/Delay1'
     *  Sum: '<S68>/Add4'
     */
    RobotControl_B.Add5 = (RobotControl_B.deg - RobotControl_DW.Delay_DSTATE[0])
      + RobotControl_DW.Delay1_DSTATE;

    /* DataTypeConversion: '<S68>/Data_Type_Conversion' incorporates:
     *  Gain: '<S68>/Gain3'
     */
    RobotControl_B.Data_Type_Conversion_a = (real32_T)(0.20000000298023224 *
      RobotControl_B.Add5);

    /* Update for UnitDelay: '<S56>/Unit_Delay' */
    RobotControl_DW.Unit_Delay_DSTATE = RobotControl_B.Add1;

    /* Update for Delay: '<S68>/Delay' */
    RobotControl_DW.Delay_DSTATE[0] = RobotControl_DW.Delay_DSTATE[1];
    RobotControl_DW.Delay_DSTATE[1] = RobotControl_DW.Delay_DSTATE[2];
    RobotControl_DW.Delay_DSTATE[2] = RobotControl_DW.Delay_DSTATE[3];
    RobotControl_DW.Delay_DSTATE[3] = RobotControl_DW.Delay_DSTATE[4];
    RobotControl_DW.Delay_DSTATE[4] = RobotControl_B.deg;

    /* Update for Delay: '<S68>/Delay1' */
    RobotControl_DW.Delay1_DSTATE = RobotControl_B.Add5;
  }

  /* End of Logic: '<S25>/Logical_Operator1' */
  /* End of Outputs for SubSystem: '<S25>/EncoderThetaCalculation' */

  /* Outputs for Atomic SubSystem: '<S57>/LeftEndofLineTest' */
  /* UnitDelay: '<S25>/Unit_Delay4' */
#if motorsHandleEOL_Variant

  rtb_leftOldEncoderTicks_Bool_z = RobotControl_DW.Unit_Delay4_DSTATE_m;

#if leftMotorEOL_variant

  /* Output and update for atomic system: '<S70>/LeftEndofLineTest' */
  {
    real32_T rtb_Switch_bo;

    /* Outputs for Enabled SubSystem: '<S72>/LeftMotorEncoderCounter' incorporates:
     *  EnablePort: '<S75>/counterReset'
     */
    /* UnitDelay: '<S72>/Unit_Delay' */
    if (RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE_k) {
      if (!RobotControl_DW.LeftEndofLineTest_g.LeftMotorEncoderCounter_MODE) {
        /* InitializeConditions for UnitDelay: '<S75>/Unit_Delay' */
        RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE = 0.0F;
        RobotControl_DW.LeftEndofLineTest_g.LeftMotorEncoderCounter_MODE = true;
      }

      /* Switch: '<S75>/Switch' incorporates:
       *  Constant: '<S75>/CONST_ONE_UINT16'
       *  RelationalOperator: '<S75>/Relational_Operator'
       *  Sum: '<S75>/Add'
       *  UnitDelay: '<S75>/Unit_Delay'
       */
      if (rtb_Switch_b != rtb_leftOldEncoderTicks_Bool_z) {
        rtb_Switch_bo = RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE +
          (real32_T)CONST_ONE_UINT16;
      } else {
        rtb_Switch_bo = RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE;
      }

      /* End of Switch: '<S75>/Switch' */

      /* DataTypeConversion: '<S75>/Data_Type_Conversion' */
      RobotControl_B.LeftEndofLineTest_g.encoderCounter = (uint16_T)
        rtb_Switch_bo;

      /* Update for UnitDelay: '<S75>/Unit_Delay' */
      RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE = rtb_Switch_bo;
    } else {
      if (RobotControl_DW.LeftEndofLineTest_g.LeftMotorEncoderCounter_MODE) {
        /* Disable for Outport: '<S75>/encoderCounter' */
        RobotControl_B.LeftEndofLineTest_g.encoderCounter = 0U;
        RobotControl_DW.LeftEndofLineTest_g.LeftMotorEncoderCounter_MODE = false;
      }
    }

    /* End of UnitDelay: '<S72>/Unit_Delay' */
    /* End of Outputs for SubSystem: '<S72>/LeftMotorEncoderCounter' */

    /* Chart: '<S74>/EOL_TickStateMachine' incorporates:
     *  DataTypeConversion: '<S74>/Data Type Conversion2'
     */
    /* Gateway: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    if (RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 < 16383U) {
      RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1++;
    }

    /* During: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    /* generates scenario to test the motor encoder. it needs Serial print to get the data and detect the calibration which we are looking for which is; ticks_PER_mm or mm_Per_tick */
    if (RobotControl_DW.LeftEndofLineTest_g.is_active_c15_RobotControl == 0U) {
      /* Entry: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      RobotControl_DW.LeftEndofLineTest_g.is_active_c15_RobotControl = 1U;

      /* Entry Internal: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      /* Transition: '<S76>:12' */
      RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
        RobotControl_IN_InitializeTest;
      RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;

      /* Entry 'InitializeTest': '<S76>:11' */
      RobotControl_B.VariantMerge_For_Variant_Source = RobotControl_ENU_STOP;
      RobotControl_B.LeftEndofLineTest_g.counterReset = true;
    } else {
      switch (RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl) {
       case RobotControl_IN_FastPwm:
        /* During 'FastPwm': '<S76>:14' */
        if (RobotControl_B.LeftEndofLineTest_g.encoderCounter >=
            RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S76>:20' */
          RobotControl_B.VariantMerge_For_Variant_Source = RobotControl_ENU_STOP;
          RobotControl_B.LeftEndofLineTest_g.counterReset = true;
          RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
            RobotControl_IN_SuperFastPwm;
          RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;
        } else {
          if (RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay) {
            RobotControl_B.LeftEndofLineTest_g.counterReset = false;
            RobotControl_B.VariantMergeForOutportleft_EOL_ = 200.0F;
            RobotControl_B.VariantMerge_For_Variant_Source =
              RobotControl_ENU_FORWARD;
          }
        }
        break;

       case RobotControl_IN_InitializeTest:
        /* During 'InitializeTest': '<S76>:11' */
        if (RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 >=
            RobotControl_CONST_EnDelay) {
          /* Transition: '<S76>:16' */
          RobotControl_B.LeftEndofLineTest_g.counterReset = false;
          RobotControl_B.VariantMergeForOutportleft_EOL_ = 100.0F;
          RobotControl_B.VariantMerge_For_Variant_Source =
            RobotControl_ENU_FORWARD;
          RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
            RobotControl_IN_SlowPwm;
        }
        break;

       case RobotControl_IN_MediumPwm:
        /* During 'MediumPwm': '<S76>:15' */
        if (RobotControl_B.LeftEndofLineTest_g.encoderCounter >=
            RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S76>:18' */
          RobotControl_B.VariantMerge_For_Variant_Source = RobotControl_ENU_STOP;
          RobotControl_B.LeftEndofLineTest_g.counterReset = true;
          RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
            RobotControl_IN_FastPwm;
          RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;
        } else {
          if (RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay) {
            RobotControl_B.LeftEndofLineTest_g.counterReset = false;
            RobotControl_B.VariantMergeForOutportleft_EOL_ = 150.0F;
            RobotControl_B.VariantMerge_For_Variant_Source =
              RobotControl_ENU_FORWARD;
          }
        }
        break;

       case RobotControl_IN_SlowPwm:
        /* During 'SlowPwm': '<S76>:13' */
        if (RobotControl_B.LeftEndofLineTest_g.encoderCounter >=
            RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S76>:17' */
          RobotControl_B.VariantMerge_For_Variant_Source = RobotControl_ENU_STOP;
          RobotControl_B.LeftEndofLineTest_g.counterReset = true;
          RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
            RobotControl_IN_MediumPwm;
          RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;
        }
        break;

       default:
        /* During 'SuperFastPwm': '<S76>:19' */
        if (RobotControl_B.LeftEndofLineTest_g.encoderCounter >=
            RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S76>:21' */
          RobotControl_DW.LeftEndofLineTest_g.is_c15_RobotControl =
            RobotControl_IN_InitializeTest;
          RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 = 0U;

          /* Entry 'InitializeTest': '<S76>:11' */
          RobotControl_B.VariantMerge_For_Variant_Source = RobotControl_ENU_STOP;
          RobotControl_B.LeftEndofLineTest_g.counterReset = true;
        } else {
          if (RobotControl_DW.LeftEndofLineTest_g.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay) {
            RobotControl_B.LeftEndofLineTest_g.counterReset = false;
            RobotControl_B.VariantMergeForOutportleft_EOL_ = 250.0F;
            RobotControl_B.VariantMerge_For_Variant_Source =
              RobotControl_ENU_FORWARD;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S74>/EOL_TickStateMachine' */

    /* Update for UnitDelay: '<S72>/Unit_Delay' incorporates:
     *  Logic: '<S72>/Logical_Operator'
     */
    RobotControl_DW.LeftEndofLineTest_g.Unit_Delay_DSTATE_k =
      !RobotControl_B.LeftEndofLineTest_g.counterReset;
  }

#elif leftMotorEOL_DisabledVariant

  /* Output and update for atomic system: '<S70>/LeftEndofLineTest_disabled' */

  /* DataTypeConversion: '<S73>/Data Type Conversion' incorporates:
   *  Constant: '<S73>/Constant'
   */
  RobotControl_B.VariantMergeForOutportleft_EOL_ = 0.0F;

  /* Constant: '<S73>/ENU_STOP' */
  RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_STOP);

#endif                                 /* leftMotorEOL_variant */
#endif                                 /* motorsHandleEOL_Variant */

  /* End of UnitDelay: '<S25>/Unit_Delay4' */
  /* End of Outputs for SubSystem: '<S57>/LeftEndofLineTest' */

  /* Outputs for Atomic SubSystem: '<S57>/rightEndofLineTest1' */
  /* UnitDelay: '<S25>/Unit_Delay1' */
#if motorsHandleEOL_Variant

  rtb_rightOldEncoderTicks_Bool_z = RobotControl_DW.Unit_Delay1_DSTATE_c;

#if rightMotorEOL_variant

  /* Output and update for atomic system: '<S71>/RightEndofLineTest' */
  {
    real32_T rtb_Switch_e;

    /* Outputs for Enabled SubSystem: '<S77>/RightMotorEncoderCounter1' incorporates:
     *  EnablePort: '<S80>/counterReset'
     */
    /* UnitDelay: '<S77>/Unit_Delay' */
    if (RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE_l) {
      if (!RobotControl_DW.RightEndofLineTest.RightMotorEncoderCounter1_MODE) {
        /* InitializeConditions for UnitDelay: '<S80>/Unit_Delay' */
        RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE = 0.0F;
        RobotControl_DW.RightEndofLineTest.RightMotorEncoderCounter1_MODE = true;
      }

      /* Switch: '<S80>/Switch' incorporates:
       *  Constant: '<S80>/CONST_ONE_UINT16'
       *  RelationalOperator: '<S80>/Relational_Operator'
       *  Sum: '<S80>/Add'
       *  UnitDelay: '<S80>/Unit_Delay'
       */
      if (rtb_Switch1_l != rtb_rightOldEncoderTicks_Bool_z) {
        rtb_Switch_e = RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE +
          (real32_T)CONST_ONE_UINT16;
      } else {
        rtb_Switch_e = RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE;
      }

      /* End of Switch: '<S80>/Switch' */

      /* DataTypeConversion: '<S80>/Data_Type_Conversion' */
      RobotControl_B.RightEndofLineTest.encoderCounter = (uint16_T)rtb_Switch_e;

      /* Update for UnitDelay: '<S80>/Unit_Delay' */
      RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE = rtb_Switch_e;
    } else {
      if (RobotControl_DW.RightEndofLineTest.RightMotorEncoderCounter1_MODE) {
        /* Disable for Outport: '<S80>/encoderCounter' */
        RobotControl_B.RightEndofLineTest.encoderCounter = 0U;
        RobotControl_DW.RightEndofLineTest.RightMotorEncoderCounter1_MODE =
          false;
      }
    }

    /* End of UnitDelay: '<S77>/Unit_Delay' */
    /* End of Outputs for SubSystem: '<S77>/RightMotorEncoderCounter1' */

    /* Chart: '<S79>/EOL_TickStateMachine' incorporates:
     *  DataTypeConversion: '<S79>/Data Type Conversion2'
     */
    /* Gateway: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    if (RobotControl_DW.RightEndofLineTest.temporalCounter_i1 < 16383U) {
      RobotControl_DW.RightEndofLineTest.temporalCounter_i1++;
    }

    /* During: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    /* generates scenario to test the motor encoder. it needs Serial print to get the data and detect the calibration which we are looking for which is; ticks_PER_mm or mm_Per_tick */
    if (RobotControl_DW.RightEndofLineTest.is_active_c16_RobotControl == 0U) {
      /* Entry: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      RobotControl_DW.RightEndofLineTest.is_active_c16_RobotControl = 1U;

      /* Entry Internal: RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      /* Transition: '<S81>:12' */
      RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
        RobotContro_IN_InitializeTest_j;
      RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;

      /* Entry 'InitializeTest': '<S81>:11' */
      RobotControl_B.VariantMerge_For_Variant_Sour_b = RobotControl_ENU_STOP_n;
      RobotControl_B.RightEndofLineTest.counterReset = true;
    } else {
      switch (RobotControl_DW.RightEndofLineTest.is_c16_RobotControl) {
       case RobotControl_IN_FastPwm_c:
        /* During 'FastPwm': '<S81>:14' */
        if (RobotControl_B.RightEndofLineTest.encoderCounter >=
            RobotContr_CONST_EOL_ME_Ticks_m) {
          /* Transition: '<S81>:20' */
          RobotControl_B.VariantMerge_For_Variant_Sour_b =
            RobotControl_ENU_STOP_n;
          RobotControl_B.RightEndofLineTest.counterReset = true;
          RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
            RobotControl_IN_SuperFastPwm_h;
          RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;
        } else {
          if (RobotControl_DW.RightEndofLineTest.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay_b) {
            RobotControl_B.RightEndofLineTest.counterReset = false;
            RobotControl_B.VariantMergeForOutportright_EOL = 200.0F;
            RobotControl_B.VariantMerge_For_Variant_Sour_b =
              RobotControl_ENU_FORWARD_o;
          }
        }
        break;

       case RobotContro_IN_InitializeTest_j:
        /* During 'InitializeTest': '<S81>:11' */
        if (RobotControl_DW.RightEndofLineTest.temporalCounter_i1 >=
            RobotControl_CONST_EnDelay_b) {
          /* Transition: '<S81>:16' */
          RobotControl_B.RightEndofLineTest.counterReset = false;
          RobotControl_B.VariantMergeForOutportright_EOL = 100.0F;
          RobotControl_B.VariantMerge_For_Variant_Sour_b =
            RobotControl_ENU_FORWARD_o;
          RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
            RobotControl_IN_SlowPwm_m;
        }
        break;

       case RobotControl_IN_MediumPwm_o:
        /* During 'MediumPwm': '<S81>:15' */
        if (RobotControl_B.RightEndofLineTest.encoderCounter >=
            RobotContr_CONST_EOL_ME_Ticks_m) {
          /* Transition: '<S81>:18' */
          RobotControl_B.VariantMerge_For_Variant_Sour_b =
            RobotControl_ENU_STOP_n;
          RobotControl_B.RightEndofLineTest.counterReset = true;
          RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
            RobotControl_IN_FastPwm_c;
          RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;
        } else {
          if (RobotControl_DW.RightEndofLineTest.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay_b) {
            RobotControl_B.RightEndofLineTest.counterReset = false;
            RobotControl_B.VariantMergeForOutportright_EOL = 150.0F;
            RobotControl_B.VariantMerge_For_Variant_Sour_b =
              RobotControl_ENU_FORWARD_o;
          }
        }
        break;

       case RobotControl_IN_SlowPwm_m:
        /* During 'SlowPwm': '<S81>:13' */
        if (RobotControl_B.RightEndofLineTest.encoderCounter >=
            RobotContr_CONST_EOL_ME_Ticks_m) {
          /* Transition: '<S81>:17' */
          RobotControl_B.VariantMerge_For_Variant_Sour_b =
            RobotControl_ENU_STOP_n;
          RobotControl_B.RightEndofLineTest.counterReset = true;
          RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
            RobotControl_IN_MediumPwm_o;
          RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;
        }
        break;

       default:
        /* During 'SuperFastPwm': '<S81>:19' */
        if (RobotControl_B.RightEndofLineTest.encoderCounter >=
            RobotContr_CONST_EOL_ME_Ticks_m) {
          /* Transition: '<S81>:21' */
          RobotControl_DW.RightEndofLineTest.is_c16_RobotControl =
            RobotContro_IN_InitializeTest_j;
          RobotControl_DW.RightEndofLineTest.temporalCounter_i1 = 0U;

          /* Entry 'InitializeTest': '<S81>:11' */
          RobotControl_B.VariantMerge_For_Variant_Sour_b =
            RobotControl_ENU_STOP_n;
          RobotControl_B.RightEndofLineTest.counterReset = true;
        } else {
          if (RobotControl_DW.RightEndofLineTest.temporalCounter_i1 >=
              RobotControl_CONST_EnDelay_b) {
            RobotControl_B.RightEndofLineTest.counterReset = false;
            RobotControl_B.VariantMergeForOutportright_EOL = 250.0F;
            RobotControl_B.VariantMerge_For_Variant_Sour_b =
              RobotControl_ENU_FORWARD_o;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S79>/EOL_TickStateMachine' */

    /* Update for UnitDelay: '<S77>/Unit_Delay' incorporates:
     *  Logic: '<S77>/Logical_Operator'
     */
    RobotControl_DW.RightEndofLineTest.Unit_Delay_DSTATE_l =
      !RobotControl_B.RightEndofLineTest.counterReset;
  }

#elif rightMotorEOL_DisabledVariant

  /* Output and update for atomic system: '<S71>/RightEndofLineTest_disabled' */

  /* DataTypeConversion: '<S78>/Data Type Conversion' incorporates:
   *  Constant: '<S78>/Constant'
   */
  RobotControl_B.VariantMergeForOutportright_EOL = 0.0F;

  /* Constant: '<S78>/ENU_STOP' */
  RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_STOP);

#endif                                 /* rightMotorEOL_variant */
#endif                                 /* motorsHandleEOL_Variant */

  /* End of UnitDelay: '<S25>/Unit_Delay1' */
  /* End of Outputs for SubSystem: '<S57>/rightEndofLineTest1' */

  /* Switch: '<S90>/Reset' incorporates:
   *  Constant: '<S86>/CONST_EnableDelay'
   *  Constant: '<S86>/CONST_FALSE'
   *  Constant: '<S90>/Initial Condition'
   *  Constant: '<S99>/Initial Condition'
   *  Switch: '<S89>/Enable'
   *  Switch: '<S98>/Enable'
   *  Switch: '<S99>/Reset'
   */
  if (CONST_FALSE) {
    rtb_Init_j = 1.0F;
    rtb_Init = 1.0F;
  } else {
    if (CONST_EnableDelay) {
      /* Switch: '<S89>/Enable' incorporates:
       *  Constant: '<S86>/CONST_ONE_F32'
       *  Product: '<S86>/Product6'
       *  Sum: '<S86>/Subtract3'
       */
      rtb_Init_j = (CONST_ONE_F32 - rtb_KT_e2) * rtb_Product4_p;

      /* Switch: '<S98>/Enable' incorporates:
       *  Constant: '<S95>/CONST_ONE_F32'
       *  Product: '<S95>/Product6'
       *  Sum: '<S95>/Subtract3'
       */
      rtb_Init = (CONST_ONE_F32 - rtb_KT) * rtb_Product4;
    }
  }

  /* End of Switch: '<S90>/Reset' */

  /* Update for UnitDelay: '<S25>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_p = RobotControl_B.leftPosPin;

  /* Update for UnitDelay: '<S25>/Unit_Delay6' */
  RobotControl_DW.Unit_Delay6_DSTATE = RobotControl_B.leftNegPin;

  /* Update for Delay: '<S62>/Delay' */
  RobotControl_DW.Delay_DSTATE_a[0] = RobotControl_DW.Delay_DSTATE_a[1];
  RobotControl_DW.Delay_DSTATE_a[1] = RobotControl_DW.Delay_DSTATE_a[2];
  RobotControl_DW.Delay_DSTATE_a[2] = RobotControl_DW.Delay_DSTATE_a[3];
  RobotControl_DW.Delay_DSTATE_a[3] = RobotControl_DW.Delay_DSTATE_a[4];
  RobotControl_DW.Delay_DSTATE_a[4] = RobotControl_B.motorDistance;

  /* Update for Delay: '<S62>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = rtb_Add5_b;

  /* Update for UnitDelay: '<S25>/Unit_Delay7' */
  RobotControl_DW.Unit_Delay7_DSTATE = RobotControl_B.rightPosPin;

  /* Update for UnitDelay: '<S25>/Unit_Delay8' */
  RobotControl_DW.Unit_Delay8_DSTATE = RobotControl_B.rightNegPin;

  /* Update for Delay: '<S63>/Delay' */
  RobotControl_DW.Delay_DSTATE_l[0] = RobotControl_DW.Delay_DSTATE_l[1];
  RobotControl_DW.Delay_DSTATE_l[1] = RobotControl_DW.Delay_DSTATE_l[2];
  RobotControl_DW.Delay_DSTATE_l[2] = RobotControl_DW.Delay_DSTATE_l[3];
  RobotControl_DW.Delay_DSTATE_l[3] = RobotControl_DW.Delay_DSTATE_l[4];
  RobotControl_DW.Delay_DSTATE_l[4] = rtb_motorDistance_f;

  /* Update for Delay: '<S63>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = rtb_Add5_n;

  /* Update for DiscreteTransferFcn: '<S100>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[1L] =
    RobotControl_DW.MotorTransferFunction_states[0L];
  RobotControl_DW.MotorTransferFunction_states[0L] = MotorTransferFunction_tmp;

  /* Update for UnitDelay: '<S99>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S99>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 0U;

  /* Update for UnitDelay: '<S99>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = rtb_Init;

  /* Update for DiscreteTransferFcn: '<S91>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_j[1L] =
    RobotControl_DW.MotorTransferFunction_states_j[0L];
  RobotControl_DW.MotorTransferFunction_states_j[0L] =
    MotorTransferFunction_tmp_b;

  /* Update for UnitDelay: '<S90>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S90>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 0U;

  /* Update for UnitDelay: '<S90>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = rtb_Init_j;

  /* Update for UnitDelay: '<S25>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S25>/Unit_Delay4' incorporates:
   *  Update for UnitDelay: '<S25>/Unit_Delay1'
   */
#if motorsHandleEOL_Variant

  RobotControl_DW.Unit_Delay4_DSTATE_m = rtb_Switch_b;
  RobotControl_DW.Unit_Delay1_DSTATE_c = rtb_Switch1_l;

#endif                                 /* motorsHandleEOL_Variant */

  /* End of Update for UnitDelay: '<S25>/Unit_Delay4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
