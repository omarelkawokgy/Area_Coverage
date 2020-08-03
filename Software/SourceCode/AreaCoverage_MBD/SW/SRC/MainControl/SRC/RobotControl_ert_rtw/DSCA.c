/*
 * Code generation for system system '<S16>/DSCA'
 *
 * Model                      : RobotControl
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "DSCA.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S73>/SpdTickDetector' */
#define RobotControl_CAL_mmPerTickPerTs (802.108704F)
#define RobotControl_CONST_VEL_TIMEOUT ((uint8_T)100U)
#define RobotControl_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define RobotControl_IN_counting       ((uint8_T)1U)
#define RobotControl_IN_stop           ((uint8_T)2U)

/* Named constants for Chart: '<S63>/EOL_TickStateMachine' */
#define RobotContr_IN_NO_ACTIVE_CHILD_p ((uint8_T)0U)

/* System initialize for function-call system: '<S1>/EncoderAnalogIn' */
void RobotContr_EncoderAnalogIn_Init(void)
{
  /* SystemInitialize for Outport: '<S7>/rightEncoderTicks_uint16' */
  RobotControl_B.A0 = 0U;

  /* SystemInitialize for Outport: '<S7>/leftEncoderTicks_uint16' */
  RobotControl_B.A1 = 0U;
}

/* Start for function-call system: '<S1>/EncoderAnalogIn' */
void RobotCont_EncoderAnalogIn_Start(void)
{
  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/A0' */
  MW_pinModeAnalogInput(0UL);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/A1' */
  MW_pinModeAnalogInput(1UL);
}

/* Output and update for function-call system: '<S1>/EncoderAnalogIn' */
void RobotControl_EncoderAnalogIn(void)
{
  /* S-Function (arduinoanaloginput_sfcn): '<S7>/A0' */
  RobotControl_B.A0 = MW_analogRead(0UL);

  /* S-Function (arduinoanaloginput_sfcn): '<S7>/A1' */
  RobotControl_B.A1 = MW_analogRead(1UL);
}

/*
 * System initialize for trigger system:
 *    '<S52>/EncoderIncrement'
 *    '<S53>/EncoderIncrement'
 */
void RobotCont_EncoderIncrement_Init(B_EncoderIncrement_RobotContr_T *localB)
{
  /* SystemInitialize for Outport: '<S56>/distCounter' */
  localB->distCounter = 0L;
}

/*
 * Output and update for trigger system:
 *    '<S52>/EncoderIncrement'
 *    '<S53>/EncoderIncrement'
 */
void RobotControl_EncoderIncrement(boolean_T rtu_EncoderTicks_Bool, uint8_T
  rtu_motorDirection, B_EncoderIncrement_RobotContr_T *localB,
  ZCE_EncoderIncrement_RobotCon_T *localZCE)
{
  int16_T rtu_motorDirection_0;

  /* Outputs for Triggered SubSystem: '<S52>/EncoderIncrement' incorporates:
   *  TriggerPort: '<S56>/EncoderTicks_Bool'
   */
  if (rtu_EncoderTicks_Bool && (localZCE->EncoderIncrement_Trig_ZCE != POS_ZCSIG))
  {
    /* Switch: '<S56>/Switch1' incorporates:
     *  Constant: '<S56>/CONST_NEG_ONE_INT32'
     *  Constant: '<S56>/CONST_ONE_INT32'
     *  Constant: '<S56>/ENU_FORWARD'
     *  RelationalOperator: '<S56>/Relational_Operator'
     */
    if (rtu_motorDirection == 1) {
      rtu_motorDirection_0 = 1;
    } else {
      rtu_motorDirection_0 = -1;
    }

    /* End of Switch: '<S56>/Switch1' */

    /* Sum: '<S56>/Add' incorporates:
     *  UnitDelay: '<S56>/Unit_Delay'
     */
    localB->distCounter += rtu_motorDirection_0;
  }

  localZCE->EncoderIncrement_Trig_ZCE = rtu_EncoderTicks_Bool;

  /* End of Outputs for SubSystem: '<S52>/EncoderIncrement' */
}

/*
 * System initialize for atomic system:
 *    '<S73>/SpdTickDetector'
 *    '<S82>/SpdTickDetector'
 */
void RobotContr_SpdTickDetector_Init(B_SpdTickDetector_RobotContro_T *localB,
  DW_SpdTickDetector_RobotContr_T *localDW)
{
  localDW->is_active_c9_DSCA = 0U;
  localDW->is_c9_DSCA = RobotControl_IN_NO_ACTIVE_CHILD;
  localDW->cycleCnt = 0U;
  localB->spd = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S73>/SpdTickDetector'
 *    '<S82>/SpdTickDetector'
 */
void RobotControl_SpdTickDetector(real32_T rtu_encoderTick,
  B_SpdTickDetector_RobotContro_T *localB, DW_SpdTickDetector_RobotContr_T
  *localDW)
{
  /* Gateway: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  localDW->encoderTick_prev = localDW->encoderTick_start;
  localDW->encoderTick_start = rtu_encoderTick;

  /* During: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  if (localDW->is_active_c9_DSCA == 0U) {
    localDW->encoderTick_prev = rtu_encoderTick;

    /* Entry: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    localDW->is_active_c9_DSCA = 1U;

    /* Entry Internal: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    /* Transition: '<S77>:2' */
    localDW->is_c9_DSCA = RobotControl_IN_counting;

    /* Entry 'counting': '<S77>:3' */
    localDW->cycleCnt = 1U;
  } else if (localDW->is_c9_DSCA == RobotControl_IN_counting) {
    /* During 'counting': '<S77>:3' */
    if ((localDW->encoderTick_prev != localDW->encoderTick_start) &&
        (localDW->encoderTick_start == 1.0F)) {
      /* Transition: '<S77>:7' */
      localB->spd = RobotControl_CAL_mmPerTickPerTs / (real32_T)
        localDW->cycleCnt;
      localDW->is_c9_DSCA = RobotControl_IN_counting;

      /* Entry 'counting': '<S77>:3' */
      localDW->cycleCnt = 1U;
    } else if (localDW->cycleCnt > RobotControl_CONST_VEL_TIMEOUT) {
      /* Transition: '<S77>:9' */
      localDW->is_c9_DSCA = RobotControl_IN_stop;

      /* Entry 'stop': '<S77>:8' */
      localB->spd = 0.0F;
    } else {
      localDW->cycleCnt++;
    }
  } else {
    /* During 'stop': '<S77>:8' */
    if (localDW->encoderTick_prev != localDW->encoderTick_start) {
      /* Transition: '<S77>:10' */
      localDW->is_c9_DSCA = RobotControl_IN_counting;

      /* Entry 'counting': '<S77>:3' */
      localDW->cycleCnt = 1U;
    }
  }
}

/* System initialize for function-call system: '<S16>/DSCA' */
void RobotControl_DSCA_Init(void)
{
  int16_T i;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_p = 0U;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay6' */
  RobotControl_DW.Unit_Delay6_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay7' */
  RobotControl_DW.Unit_Delay7_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay8' */
  RobotControl_DW.Unit_Delay8_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S75>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* InitializeConditions for UnitDelay: '<S75>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = 1.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S76>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[0] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[0] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S76>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[1] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[1] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 1U;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = 1.0F;

  /* InitializeConditions for Delay: '<S54>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = 0.0F;
  for (i = 0; i < 5; i++) {
    /* InitializeConditions for Delay: '<S54>/Delay' */
    RobotControl_DW.Delay_DSTATE_a[i] = 0.0F;

    /* InitializeConditions for Delay: '<S55>/Delay' */
    RobotControl_DW.Delay_DSTATE_l[i] = 0.0F;
  }

  /* InitializeConditions for Delay: '<S55>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = 0.0F;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b = 0U;

  /* SystemInitialize for Triggered SubSystem: '<S52>/EncoderIncrement' */
  RobotCont_EncoderIncrement_Init(&RobotControl_B.EncoderIncrement);

  /* End of SystemInitialize for SubSystem: '<S52>/EncoderIncrement' */

  /* SystemInitialize for Triggered SubSystem: '<S53>/EncoderIncrement' */
  RobotCont_EncoderIncrement_Init(&RobotControl_B.EncoderIncrement_i);

  /* End of SystemInitialize for SubSystem: '<S53>/EncoderIncrement' */

  /* SystemInitialize for Chart: '<S73>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector,
    &RobotControl_DW.sf_SpdTickDetector);

  /* SystemInitialize for Chart: '<S82>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector_e,
    &RobotControl_DW.sf_SpdTickDetector_e);

  /* SystemInitialize for Enabled SubSystem: '<S19>/EncoderThetaCalculation' */
  /* InitializeConditions for UnitDelay: '<S48>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = 4.71238899230957;

  /* InitializeConditions for Delay: '<S60>/Delay' */
  for (i = 0; i < 5; i++) {
    RobotControl_DW.Delay_DSTATE[i] = 0.0;
  }

  /* End of InitializeConditions for Delay: '<S60>/Delay' */

  /* InitializeConditions for Delay: '<S60>/Delay1' */
  RobotControl_DW.Delay1_DSTATE = 0.0;

  /* SystemInitialize for Outport: '<S48>/thetaEncod' */
  RobotControl_B.Data_Type_Conversion_a = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S19>/EncoderThetaCalculation' */

  /* SystemInitialize for Enabled SubSystem: '<S49>/endofLineTest' */
  /* SystemInitialize for Chart: '<S63>/EOL_TickStateMachine' */
  RobotControl_DW.temporalCounter_i1_i = 0U;
  RobotControl_DW.is_active_c33_DSCA = 0U;
  RobotControl_DW.is_c33_DSCA = RobotContr_IN_NO_ACTIVE_CHILD_p;

  /* End of SystemInitialize for SubSystem: '<S49>/endofLineTest' */

  /* SystemInitialize for Outport: '<S19>/leftVel_mmPerSec' */
  RobotControl_B.leftVel1ms_mmPerSec = 0.0F;

  /* SystemInitialize for Outport: '<S19>/leftDistTravelled_mm' */
  RobotControl_B.Data_Type_Conversion = 0.0F;

  /* SystemInitialize for Outport: '<S19>/rightVel_mmPerSec' */
  RobotControl_B.rightVel1ms_mmPerSec = 0.0F;

  /* SystemInitialize for Outport: '<S19>/rightDistTravelled_mm' */
  RobotControl_B.Data_Type_Conversion_m = 0.0F;
}

/* Start for function-call system: '<S16>/DSCA' */
void RobotControl_DSCA_Start(void)
{
  /* Start for Enabled SubSystem: '<S49>/endofLineTest' */
  RobotControl_DW.endofLineTest_MODE = false;

  /* Start for Enabled SubSystem: '<S62>/LeftMotorEncoderCounter' */
  RobotControl_DW.LeftMotorEncoderCounter_MODE = false;

  /* End of Start for SubSystem: '<S62>/LeftMotorEncoderCounter' */

  /* Start for Enabled SubSystem: '<S62>/RightMotorEncoderCounter1' */
  RobotControl_DW.RightMotorEncoderCounter1_MODE = false;

  /* End of Start for SubSystem: '<S62>/RightMotorEncoderCounter1' */
  /* End of Start for SubSystem: '<S49>/endofLineTest' */
}

/* Output and update for function-call system: '<S16>/DSCA' */
void RobotControl_DSCA(void)
{
  /* local block i/o variables */
  real32_T rtb_motorDistance;
  real32_T rtb_motorDistance_b;
  uint8_T rtb_leftNegPin_z;
  uint8_T rtb_leftPosPin_z;
  real32_T rtb_Gain3_b;
  uint8_T rtb_rightNegPin;
  uint8_T rtb_rightPosPin_z;
  real32_T rtb_Gain;
  boolean_T rtb_Switch_l;
  uint8_T rtb_MotorDirection;
  real32_T rtb_KT;
  real32_T rtb_Subtract2_l;
  real32_T rtb_inputVoltage_V;
  boolean_T rtb_Switch1_k;
  uint8_T rtb_MotorDirection_m;
  real32_T rtb_KT_i;
  real32_T rtb_Subtract2_p;
  real_T rtb_Add5;
  real32_T MotorTransferFunction_tmp;

  /* UnitDelay: '<S19>/Unit_Delay5' */
  rtb_leftPosPin_z = RobotControl_DW.Unit_Delay5_DSTATE_p;

  /* UnitDelay: '<S19>/Unit_Delay6' */
  rtb_leftNegPin_z = RobotControl_DW.Unit_Delay6_DSTATE;

  /* Switch: '<S87>/Switch5' incorporates:
   *  Constant: '<S87>/ENU_FORWARD'
   *  Constant: '<S87>/ENU_STOP'
   *  RelationalOperator: '<S87>/Relational_Operator5'
   *  RelationalOperator: '<S87>/Relational_Operator6'
   *  Switch: '<S87>/Switch6'
   */
  if (rtb_leftPosPin_z > rtb_leftNegPin_z) {
    rtb_MotorDirection = 1U;
  } else if (rtb_leftPosPin_z < rtb_leftNegPin_z) {
    /* Switch: '<S87>/Switch6' incorporates:
     *  Constant: '<S87>/ENU_BACKWARD'
     */
    rtb_MotorDirection = 2U;
  } else {
    rtb_MotorDirection = 5U;
  }

  /* End of Switch: '<S87>/Switch5' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/CAL_EncoderAnaThd'
   *  RelationalOperator: '<S47>/Relational Operator'
   */
  rtb_Switch_l = (RobotControl_B.A1 > 100U);

  /* Outputs for Triggered SubSystem: '<S52>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch_l, rtb_MotorDirection,
    &RobotControl_B.EncoderIncrement, &RobotControl_PrevZCX.EncoderIncrement);

  /* End of Outputs for SubSystem: '<S52>/EncoderIncrement' */

  /* Gain: '<S52>/Gain1' incorporates:
   *  DataTypeConversion: '<S52>/Data_Type_Conversion'
   */
  rtb_motorDistance = 0.802108765F * (real32_T)
    RobotControl_B.EncoderIncrement.distCounter;

  /* UnitDelay: '<S19>/Unit_Delay7' */
  rtb_rightPosPin_z = RobotControl_DW.Unit_Delay7_DSTATE;

  /* UnitDelay: '<S19>/Unit_Delay8' */
  rtb_rightNegPin = RobotControl_DW.Unit_Delay8_DSTATE;

  /* Switch: '<S88>/Switch5' incorporates:
   *  Constant: '<S88>/ENU_FORWARD'
   *  Constant: '<S88>/ENU_STOP'
   *  RelationalOperator: '<S88>/Relational_Operator5'
   *  RelationalOperator: '<S88>/Relational_Operator6'
   *  Switch: '<S88>/Switch6'
   */
  if (rtb_rightPosPin_z > rtb_rightNegPin) {
    rtb_MotorDirection_m = 1U;
  } else if (rtb_rightPosPin_z < rtb_rightNegPin) {
    /* Switch: '<S88>/Switch6' incorporates:
     *  Constant: '<S88>/ENU_BACKWARD'
     */
    rtb_MotorDirection_m = 2U;
  } else {
    rtb_MotorDirection_m = 5U;
  }

  /* End of Switch: '<S88>/Switch5' */

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/CAL_EncoderAnaThd1'
   *  RelationalOperator: '<S47>/Relational Operator1'
   */
  rtb_Switch1_k = (RobotControl_B.A0 > 100U);

  /* Outputs for Triggered SubSystem: '<S53>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch1_k, rtb_MotorDirection_m,
    &RobotControl_B.EncoderIncrement_i, &RobotControl_PrevZCX.EncoderIncrement_i);

  /* End of Outputs for SubSystem: '<S53>/EncoderIncrement' */

  /* Gain: '<S53>/Gain1' incorporates:
   *  DataTypeConversion: '<S53>/Data_Type_Conversion'
   */
  rtb_motorDistance_b = 0.802108765F * (real32_T)
    RobotControl_B.EncoderIncrement_i.distCounter;

  /* DiscreteTransferFcn: '<S76>/MotorTransferFunction' incorporates:
   *  Gain: '<S72>/Gain'
   *  Sum: '<S72>/Add2'
   */
  MotorTransferFunction_tmp = (((real32_T)(rtb_leftPosPin_z - rtb_leftNegPin_z) *
    0.0470581055F - -237187.5F * RobotControl_DW.MotorTransferFunction_states[0L])
    - -549093.75F * RobotControl_DW.MotorTransferFunction_states[1L]) /
    951906.25F;

  /* Product: '<S72>/Product' incorporates:
   *  DiscreteTransferFcn: '<S76>/MotorTransferFunction'
   *  Product: '<S72>/Divide'
   */
  rtb_Gain3_b = ((78125.0F * MotorTransferFunction_tmp + 156250.0F *
                  RobotControl_DW.MotorTransferFunction_states[0L]) + 78125.0F *
                 RobotControl_DW.MotorTransferFunction_states[1L]) / 12.0F *
    60.0F;

  /* Chart: '<S73>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S73>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch_l,
    &RobotControl_B.sf_SpdTickDetector, &RobotControl_DW.sf_SpdTickDetector);

  /* Switch: '<S75>/Init' incorporates:
   *  Constant: '<S75>/Initial Condition'
   *  Logic: '<S75>/FixPt Logical Operator'
   *  UnitDelay: '<S75>/FixPt Unit Delay1'
   *  UnitDelay: '<S75>/FixPt Unit Delay2'
   */
  if (RobotControl_DW.FixPtUnitDelay2_DSTATE_a != 0) {
    rtb_inputVoltage_V = 1.0F;
  } else {
    rtb_inputVoltage_V = RobotControl_DW.FixPtUnitDelay1_DSTATE_b;
  }

  /* End of Switch: '<S75>/Init' */

  /* Product: '<S71>/Product4' incorporates:
   *  Constant: '<S71>/CAL_procNoiseVelKF'
   */
  rtb_Gain = 2.5F * rtb_inputVoltage_V;

  /* Product: '<S71>/Divide1' incorporates:
   *  Constant: '<S71>/CAL_MeasNoiseVelKF'
   *  Sum: '<S71>/Add3'
   */
  rtb_KT = (0.8F + rtb_Gain) / rtb_Gain;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/ENU_FORWARD'
   *  Gain: '<S69>/Gain2'
   *  RelationalOperator: '<S69>/Relational_Operator'
   */
  if (rtb_MotorDirection == 1) {
    rtb_Subtract2_l = RobotControl_B.sf_SpdTickDetector.spd;
  } else {
    rtb_Subtract2_l = -RobotControl_B.sf_SpdTickDetector.spd;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S71>/Add4' incorporates:
   *  Product: '<S71>/Product5'
   *  Sum: '<S71>/Subtract2'
   */
  rtb_Gain3_b += (rtb_Subtract2_l - rtb_Gain3_b) * rtb_KT;

  /* DataTypeConversion: '<S71>/Data_Type_Conversion2' */
  RobotControl_B.leftVel1ms_mmPerSec = rtb_Gain3_b;

  /* DiscreteTransferFcn: '<S85>/MotorTransferFunction' incorporates:
   *  Gain: '<S81>/Gain'
   *  Sum: '<S81>/Add2'
   */
  rtb_Subtract2_l = (((real32_T)(rtb_rightPosPin_z - rtb_rightNegPin) *
                      0.0470581055F - -237187.5F *
                      RobotControl_DW.MotorTransferFunction_states_n[0L]) -
                     -549093.75F *
                     RobotControl_DW.MotorTransferFunction_states_n[1L]) /
    951906.25F;

  /* Product: '<S81>/Product' incorporates:
   *  DiscreteTransferFcn: '<S85>/MotorTransferFunction'
   *  Product: '<S81>/Divide'
   */
  rtb_Gain3_b = ((78125.0F * rtb_Subtract2_l + 156250.0F *
                  RobotControl_DW.MotorTransferFunction_states_n[0L]) + 78125.0F
                 * RobotControl_DW.MotorTransferFunction_states_n[1L]) / 12.0F *
    60.0F;

  /* Chart: '<S82>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S82>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch1_k,
    &RobotControl_B.sf_SpdTickDetector_e, &RobotControl_DW.sf_SpdTickDetector_e);

  /* Switch: '<S84>/Init' incorporates:
   *  Constant: '<S84>/Initial Condition'
   *  Logic: '<S84>/FixPt Logical Operator'
   *  UnitDelay: '<S84>/FixPt Unit Delay1'
   *  UnitDelay: '<S84>/FixPt Unit Delay2'
   */
  if (RobotControl_DW.FixPtUnitDelay2_DSTATE_l != 0) {
    rtb_inputVoltage_V = 1.0F;
  } else {
    rtb_inputVoltage_V = RobotControl_DW.FixPtUnitDelay1_DSTATE_n;
  }

  /* End of Switch: '<S84>/Init' */

  /* Product: '<S80>/Product4' incorporates:
   *  Constant: '<S80>/CAL_procNoiseVelKF'
   */
  rtb_inputVoltage_V *= 2.5F;

  /* Product: '<S80>/Divide1' incorporates:
   *  Constant: '<S80>/CAL_MeasNoiseVelKF'
   *  Sum: '<S80>/Add3'
   */
  rtb_KT_i = (0.8F + rtb_inputVoltage_V) / rtb_inputVoltage_V;

  /* Switch: '<S78>/Switch' incorporates:
   *  Constant: '<S78>/ENU_FORWARD'
   *  Gain: '<S78>/Gain2'
   *  RelationalOperator: '<S78>/Relational_Operator'
   */
  if (rtb_MotorDirection_m == 1) {
    rtb_Subtract2_p = RobotControl_B.sf_SpdTickDetector_e.spd;
  } else {
    rtb_Subtract2_p = -RobotControl_B.sf_SpdTickDetector_e.spd;
  }

  /* End of Switch: '<S78>/Switch' */

  /* DataTypeConversion: '<S80>/Data_Type_Conversion3' incorporates:
   *  Product: '<S80>/Product5'
   *  Sum: '<S80>/Add4'
   *  Sum: '<S80>/Subtract2'
   */
  RobotControl_B.rightVel1ms_mmPerSec = (rtb_Subtract2_p - rtb_Gain3_b) *
    rtb_KT_i + rtb_Gain3_b;

  /* Sum: '<S54>/Add5' incorporates:
   *  Delay: '<S54>/Delay'
   *  Delay: '<S54>/Delay1'
   *  Sum: '<S54>/Add4'
   */
  rtb_Gain3_b = (rtb_motorDistance - RobotControl_DW.Delay_DSTATE_a[0]) +
    RobotControl_DW.Delay1_DSTATE_e;

  /* DataTypeConversion: '<S54>/Data_Type_Conversion' incorporates:
   *  Gain: '<S54>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion = 0.2F * rtb_Gain3_b;

  /* Sum: '<S55>/Add5' incorporates:
   *  Delay: '<S55>/Delay'
   *  Delay: '<S55>/Delay1'
   *  Sum: '<S55>/Add4'
   */
  rtb_Subtract2_p = (rtb_motorDistance_b - RobotControl_DW.Delay_DSTATE_l[0]) +
    RobotControl_DW.Delay1_DSTATE_i;

  /* DataTypeConversion: '<S55>/Data_Type_Conversion' incorporates:
   *  Gain: '<S55>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_m = 0.2F * rtb_Subtract2_p;

  /* Outputs for Enabled SubSystem: '<S19>/EncoderThetaCalculation' incorporates:
   *  EnablePort: '<S48>/EncoderThetaEnable'
   */
  /* Sum: '<S48>/Add1' incorporates:
   *  Constant: '<S48>/Constant'
   *  Product: '<S48>/Product'
   *  Product: '<S59>/Divide1'
   *  Sum: '<S59>/Add'
   *  UnitDelay: '<S48>/Unit_Delay'
   */
  RobotControl_B.Add1_l = (RobotControl_B.leftVel1ms_mmPerSec -
    RobotControl_B.rightVel1ms_mmPerSec) / 250.0F * 0.001 +
    RobotControl_DW.Unit_Delay_DSTATE;

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S61>/Constant2'
   *  Constant: '<S61>/Constant3'
   *  RelationalOperator: '<S61>/Relational Operator'
   *  RelationalOperator: '<S61>/Relational Operator1'
   *  Sum: '<S61>/Add'
   *  Switch: '<S61>/Switch1'
   */
  if (RobotControl_B.Add1_l > 6.2831853071795862) {
    RobotControl_B.Add1_l -= 6.2831853071795862;
  } else {
    if (RobotControl_B.Add1_l < 0.0) {
      /* Switch: '<S61>/Switch1' incorporates:
       *  Sum: '<S61>/Add1'
       */
      RobotControl_B.Add1_l += 6.2831853071795862;
    }
  }

  /* End of Switch: '<S61>/Switch' */

  /* Product: '<S58>/Product' */
  RobotControl_B.deg_m = 57.295779513082323 * RobotControl_B.Add1_l;

  /* Sum: '<S60>/Add5' incorporates:
   *  Delay: '<S60>/Delay'
   *  Delay: '<S60>/Delay1'
   *  Sum: '<S60>/Add4'
   */
  rtb_Add5 = (RobotControl_B.deg_m - RobotControl_DW.Delay_DSTATE[0]) +
    RobotControl_DW.Delay1_DSTATE;

  /* DataTypeConversion: '<S60>/Data_Type_Conversion' incorporates:
   *  Gain: '<S60>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_a = (real32_T)(0.20000000298023224 *
    rtb_Add5);

  /* Update for UnitDelay: '<S48>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = RobotControl_B.Add1_l;

  /* Update for Delay: '<S60>/Delay' */
  RobotControl_DW.Delay_DSTATE[0] = RobotControl_DW.Delay_DSTATE[1];
  RobotControl_DW.Delay_DSTATE[1] = RobotControl_DW.Delay_DSTATE[2];
  RobotControl_DW.Delay_DSTATE[2] = RobotControl_DW.Delay_DSTATE[3];
  RobotControl_DW.Delay_DSTATE[3] = RobotControl_DW.Delay_DSTATE[4];
  RobotControl_DW.Delay_DSTATE[4] = RobotControl_B.deg_m;

  /* Update for Delay: '<S60>/Delay1' */
  RobotControl_DW.Delay1_DSTATE = rtb_Add5;

  /* End of Outputs for SubSystem: '<S19>/EncoderThetaCalculation' */

  /* Outputs for Enabled SubSystem: '<S49>/endofLineTest' incorporates:
   *  EnablePort: '<S62>/CONST_EndOfLineEnableFlg'
   */
  if (RobotControl_DW.endofLineTest_MODE) {
    /* Disable for Enabled SubSystem: '<S62>/LeftMotorEncoderCounter' */
    if (RobotControl_DW.LeftMotorEncoderCounter_MODE) {
      RobotControl_DW.LeftMotorEncoderCounter_MODE = false;
    }

    /* End of Disable for SubSystem: '<S62>/LeftMotorEncoderCounter' */

    /* Disable for Enabled SubSystem: '<S62>/RightMotorEncoderCounter1' */
    if (RobotControl_DW.RightMotorEncoderCounter1_MODE) {
      RobotControl_DW.RightMotorEncoderCounter1_MODE = false;
    }

    /* End of Disable for SubSystem: '<S62>/RightMotorEncoderCounter1' */
    RobotControl_DW.endofLineTest_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S49>/endofLineTest' */

  /* Update for UnitDelay: '<S19>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_p = RobotControl_B.leftPosPin;

  /* Update for UnitDelay: '<S19>/Unit_Delay6' */
  RobotControl_DW.Unit_Delay6_DSTATE = RobotControl_B.leftNegPin;

  /* Update for UnitDelay: '<S19>/Unit_Delay7' */
  RobotControl_DW.Unit_Delay7_DSTATE = RobotControl_B.rightPosPin;

  /* Update for UnitDelay: '<S19>/Unit_Delay8' */
  RobotControl_DW.Unit_Delay8_DSTATE = RobotControl_B.rightNegPin;

  /* Update for DiscreteTransferFcn: '<S76>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[1L] =
    RobotControl_DW.MotorTransferFunction_states[0L];
  RobotControl_DW.MotorTransferFunction_states[0L] = MotorTransferFunction_tmp;

  /* Update for UnitDelay: '<S75>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S75>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 0U;

  /* Update for UnitDelay: '<S75>/FixPt Unit Delay1' incorporates:
   *  Constant: '<S71>/CONST_ONE_F32'
   *  Product: '<S71>/Product6'
   *  Sum: '<S71>/Subtract3'
   */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = (1.0F - rtb_KT) * rtb_Gain;

  /* Update for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[1L] =
    RobotControl_DW.MotorTransferFunction_states_n[0L];
  RobotControl_DW.MotorTransferFunction_states_n[0L] = rtb_Subtract2_l;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S84>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 0U;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay1' incorporates:
   *  Constant: '<S80>/CONST_ONE_F32'
   *  Product: '<S80>/Product6'
   *  Sum: '<S80>/Subtract3'
   */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = (1.0F - rtb_KT_i) *
    rtb_inputVoltage_V;

  /* Update for Delay: '<S54>/Delay' */
  RobotControl_DW.Delay_DSTATE_a[0] = RobotControl_DW.Delay_DSTATE_a[1];
  RobotControl_DW.Delay_DSTATE_a[1] = RobotControl_DW.Delay_DSTATE_a[2];
  RobotControl_DW.Delay_DSTATE_a[2] = RobotControl_DW.Delay_DSTATE_a[3];
  RobotControl_DW.Delay_DSTATE_a[3] = RobotControl_DW.Delay_DSTATE_a[4];
  RobotControl_DW.Delay_DSTATE_a[4] = rtb_motorDistance;

  /* Update for Delay: '<S54>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = rtb_Gain3_b;

  /* Update for Delay: '<S55>/Delay' */
  RobotControl_DW.Delay_DSTATE_l[0] = RobotControl_DW.Delay_DSTATE_l[1];
  RobotControl_DW.Delay_DSTATE_l[1] = RobotControl_DW.Delay_DSTATE_l[2];
  RobotControl_DW.Delay_DSTATE_l[2] = RobotControl_DW.Delay_DSTATE_l[3];
  RobotControl_DW.Delay_DSTATE_l[3] = RobotControl_DW.Delay_DSTATE_l[4];
  RobotControl_DW.Delay_DSTATE_l[4] = rtb_motorDistance_b;

  /* Update for Delay: '<S55>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = rtb_Subtract2_p;

  /* Update for UnitDelay: '<S19>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b = RobotControl_B.currentRoutine;
}
