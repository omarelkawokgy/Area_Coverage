/*
 * Code generation for system system '<S16>/DSCA'
 *
 * Model                      : RobotControl
 * Model version              : 1.503
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 29 10:39:32 2020
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
#define RobotControl_CONST_EOL_ME_Ticks (150U)
#define RobotControl_CONST_EnDelay     (10000U)
#define RobotControl_ENU_FORWARD       ((uint8_T)1U)
#define RobotControl_ENU_STOP          ((uint8_T)5U)
#define RobotControl_IN_FastPwm        ((uint8_T)1U)
#define RobotControl_IN_InitializeTest ((uint8_T)2U)
#define RobotControl_IN_MediumPwm      ((uint8_T)3U)
#define RobotControl_IN_SlowPwm        ((uint8_T)4U)
#define RobotControl_IN_SuperFastPwm   ((uint8_T)5U)

/* System initialize for function-call system: '<S1>/EncoderAnalogIn' */
void RobotContr_EncoderAnalogIn_Init(void)
{
  /* SystemInitialize for Outport: '<S7>/rightEncoderTicks_BOOL' */
  RobotControl_B.A0 = RobotControl_P.rightEncoderTicks_BOOL_Y0;

  /* SystemInitialize for Outport: '<S7>/leftEncoderTicks_BOOL' */
  RobotControl_B.A1 = RobotControl_P.leftEncoderTicks_BOOL_Y0;
}

/* Start for function-call system: '<S1>/EncoderAnalogIn' */
void RobotCont_EncoderAnalogIn_Start(void)
{
  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/A0' */
  MW_pinModeAnalogInput(RobotControl_P.A0_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/A1' */
  MW_pinModeAnalogInput(RobotControl_P.A1_p1);
}

/* Output and update for function-call system: '<S1>/EncoderAnalogIn' */
void RobotControl_EncoderAnalogIn(void)
{
  /* S-Function (arduinoanaloginput_sfcn): '<S7>/A0' */
  RobotControl_B.A0 = MW_analogRead(RobotControl_P.A0_p1);

  /* S-Function (arduinoanaloginput_sfcn): '<S7>/A1' */
  RobotControl_B.A1 = MW_analogRead(RobotControl_P.A1_p1);
}

/*
 * System initialize for trigger system:
 *    '<S52>/EncoderIncrement'
 *    '<S53>/EncoderIncrement'
 */
void RobotCont_EncoderIncrement_Init(B_EncoderIncrement_RobotContr_T *localB,
  P_EncoderIncrement_RobotContr_T *localP)
{
  /* SystemInitialize for Outport: '<S56>/distCounter' */
  localB->distCounter = localP->distCounter_Y0;
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
  int32_T rtu_motorDirection_0;

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
    if (rtu_motorDirection == RobotControl_P.ENU_FORWARD) {
      rtu_motorDirection_0 = RobotControl_P.CONST_ONE_INT32;
    } else {
      rtu_motorDirection_0 = RobotControl_P.CONST_NEG_ONE_INT32;
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
  RobotControl_DW.Unit_Delay5_DSTATE_p =
    RobotControl_P.Unit_Delay5_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay6' */
  RobotControl_DW.Unit_Delay6_DSTATE =
    RobotControl_P.Unit_Delay6_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay7' */
  RobotControl_DW.Unit_Delay7_DSTATE =
    RobotControl_P.Unit_Delay7_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay8' */
  RobotControl_DW.Unit_Delay8_DSTATE =
    RobotControl_P.Unit_Delay8_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S75>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a =
    RobotControl_P.FixPtUnitDelay2_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S75>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b =
    RobotControl_P.Unit_Delay_Enabled_Resettable1_;

  /* InitializeConditions for DiscreteTransferFcn: '<S76>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[0] =
    RobotControl_P.MotorTransferFunction_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[0] =
    RobotControl_P.MotorTransferFunction_Initial_m;

  /* InitializeConditions for DiscreteTransferFcn: '<S76>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[1] =
    RobotControl_P.MotorTransferFunction_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[1] =
    RobotControl_P.MotorTransferFunction_Initial_m;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l =
    RobotControl_P.FixPtUnitDelay2_InitialCondit_i;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n =
    RobotControl_P.Unit_Delay_Enabled_Resettable_h;

  /* InitializeConditions for Delay: '<S54>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = RobotControl_P.Delay1_InitialCondition_i;
  for (i = 0; i < 5; i++) {
    /* InitializeConditions for Delay: '<S54>/Delay' */
    RobotControl_DW.Delay_DSTATE_a[i] = RobotControl_P.Delay_InitialCondition_g;

    /* InitializeConditions for Delay: '<S55>/Delay' */
    RobotControl_DW.Delay_DSTATE_l[i] = RobotControl_P.Delay_InitialCondition_l;
  }

  /* InitializeConditions for Delay: '<S55>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = RobotControl_P.Delay1_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b =
    RobotControl_P.Unit_Delay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S19>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_m =
    RobotControl_P.Unit_Delay4_InitialCondition;

  /* SystemInitialize for Triggered SubSystem: '<S52>/EncoderIncrement' */
  RobotCont_EncoderIncrement_Init(&RobotControl_B.EncoderIncrement,
    (P_EncoderIncrement_RobotContr_T *)&RobotControl_P.EncoderIncrement);

  /* End of SystemInitialize for SubSystem: '<S52>/EncoderIncrement' */

  /* SystemInitialize for Triggered SubSystem: '<S53>/EncoderIncrement' */
  RobotCont_EncoderIncrement_Init(&RobotControl_B.EncoderIncrement_i,
    (P_EncoderIncrement_RobotContr_T *)&RobotControl_P.EncoderIncrement_i);

  /* End of SystemInitialize for SubSystem: '<S53>/EncoderIncrement' */

  /* SystemInitialize for Chart: '<S73>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector,
    &RobotControl_DW.sf_SpdTickDetector);

  /* SystemInitialize for Chart: '<S82>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector_e,
    &RobotControl_DW.sf_SpdTickDetector_e);

  /* SystemInitialize for Enabled SubSystem: '<S19>/EncoderThetaCalculation' */
  /* InitializeConditions for UnitDelay: '<S48>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = RobotControl_P.CAL_NORTH_rad;

  /* InitializeConditions for Delay: '<S60>/Delay' */
  for (i = 0; i < 5; i++) {
    RobotControl_DW.Delay_DSTATE[i] = RobotControl_P.Delay_InitialCondition;
  }

  /* End of InitializeConditions for Delay: '<S60>/Delay' */

  /* InitializeConditions for Delay: '<S60>/Delay1' */
  RobotControl_DW.Delay1_DSTATE = RobotControl_P.Delay1_InitialCondition;

  /* SystemInitialize for Outport: '<S48>/thetaEncod' */
  RobotControl_B.Data_Type_Conversion_a = RobotControl_P.thetaEncod_Y0;

  /* End of SystemInitialize for SubSystem: '<S19>/EncoderThetaCalculation' */

  /* SystemInitialize for Enabled SubSystem: '<S49>/endofLineTest' */
  /* InitializeConditions for UnitDelay: '<S62>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_ja =
    RobotControl_P.Unit_Delay_InitialCondition_c;

  /* SystemInitialize for Enabled SubSystem: '<S62>/LeftMotorEncoderCounter' */
  /* InitializeConditions for UnitDelay: '<S64>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_i =
    RobotControl_P.Unit_Delay_InitialCondition;

  /* SystemInitialize for Outport: '<S64>/encoderCounter' */
  RobotControl_B.encoderCounter = RobotControl_P.encoderCounter_Y0;

  /* End of SystemInitialize for SubSystem: '<S62>/LeftMotorEncoderCounter' */

  /* SystemInitialize for Chart: '<S63>/EOL_TickStateMachine' */
  RobotControl_DW.temporalCounter_i1_i = 0U;
  RobotControl_DW.is_active_c33_DSCA = 0U;
  RobotControl_DW.is_c33_DSCA = RobotContr_IN_NO_ACTIVE_CHILD_p;
  RobotControl_B.EOL_pwm = 0.0F;
  RobotControl_B.EOL_leftMoveReq = 0U;
  RobotControl_B.EOL_rightMoveReq = 0U;
  RobotControl_B.counterReset = false;

  /* End of SystemInitialize for SubSystem: '<S49>/endofLineTest' */

  /* SystemInitialize for Outport: '<S19>/leftVel_mmPerSec' */
  RobotControl_B.leftVel1ms_mmPerSec = RobotControl_P.leftVel_mmPerSec_Y0;

  /* SystemInitialize for Outport: '<S19>/leftDistTravelled_mm' */
  RobotControl_B.Data_Type_Conversion = RobotControl_P.leftDistTravelled_mm_Y0;

  /* SystemInitialize for Outport: '<S19>/rightVel_mmPerSec' */
  RobotControl_B.rightVel1ms_mmPerSec = RobotControl_P.rightVel_mmPerSec_Y0;

  /* SystemInitialize for Outport: '<S19>/rightDistTravelled_mm' */
  RobotControl_B.Data_Type_Conversion_m =
    RobotControl_P.rightDistTravelled_mm_Y0;
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
  real32_T rtb_Switch_i;
  uint8_T rtb_rightNegPin;
  uint8_T rtb_rightPosPin_z;
  real32_T rtb_Gain;
  real32_T rtb_Gain3_b;
  boolean_T rtb_Switch_j;
  uint8_T rtb_MotorDirection;
  real32_T rtb_Product4;
  real32_T rtb_KT;
  real32_T rtb_inputVoltage_V;
  boolean_T rtb_Switch1_k;
  uint8_T rtb_MotorDirection_m;
  real32_T rtb_Product4_l;
  real32_T rtb_KT_i;
  real32_T rtb_Switch_h;
  real32_T MotorTransferFunction_tmp;
  real32_T MotorTransferFunction_tmp_i;

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
    rtb_MotorDirection = RobotControl_P.ENU_FORWARD;
  } else if (rtb_leftPosPin_z < rtb_leftNegPin_z) {
    /* Switch: '<S87>/Switch6' incorporates:
     *  Constant: '<S87>/ENU_BACKWARD'
     */
    rtb_MotorDirection = RobotControl_P.ENU_BACKWARD;
  } else {
    rtb_MotorDirection = RobotControl_P.ENU_STOP;
  }

  /* End of Switch: '<S87>/Switch5' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/CAL_EncoderAnaThd'
   *  Constant: '<S47>/false'
   *  Constant: '<S47>/true'
   *  RelationalOperator: '<S47>/Relational Operator'
   */
  if (RobotControl_B.A1 > RobotControl_P.CAL_EncoderAnaThd) {
    rtb_Switch_j = RobotControl_P.true_Value;
  } else {
    rtb_Switch_j = RobotControl_P.false_Value;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Outputs for Triggered SubSystem: '<S52>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch_j, rtb_MotorDirection,
    &RobotControl_B.EncoderIncrement, &RobotControl_PrevZCX.EncoderIncrement);

  /* End of Outputs for SubSystem: '<S52>/EncoderIncrement' */

  /* Gain: '<S52>/Gain1' incorporates:
   *  DataTypeConversion: '<S52>/Data_Type_Conversion'
   */
  rtb_motorDistance = RobotControl_P.CAL_mm_PER_tick * (real32_T)
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
    rtb_MotorDirection_m = RobotControl_P.ENU_FORWARD;
  } else if (rtb_rightPosPin_z < rtb_rightNegPin) {
    /* Switch: '<S88>/Switch6' incorporates:
     *  Constant: '<S88>/ENU_BACKWARD'
     */
    rtb_MotorDirection_m = RobotControl_P.ENU_BACKWARD;
  } else {
    rtb_MotorDirection_m = RobotControl_P.ENU_STOP;
  }

  /* End of Switch: '<S88>/Switch5' */

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/CAL_EncoderAnaThd1'
   *  Constant: '<S47>/false1'
   *  Constant: '<S47>/true1'
   *  RelationalOperator: '<S47>/Relational Operator1'
   */
  if (RobotControl_B.A0 > RobotControl_P.CAL_EncoderAnaThd) {
    rtb_Switch1_k = RobotControl_P.true1_Value;
  } else {
    rtb_Switch1_k = RobotControl_P.false1_Value;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Outputs for Triggered SubSystem: '<S53>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch1_k, rtb_MotorDirection_m,
    &RobotControl_B.EncoderIncrement_i, &RobotControl_PrevZCX.EncoderIncrement_i);

  /* End of Outputs for SubSystem: '<S53>/EncoderIncrement' */

  /* Gain: '<S53>/Gain1' incorporates:
   *  DataTypeConversion: '<S53>/Data_Type_Conversion'
   */
  rtb_motorDistance_b = RobotControl_P.CAL_mm_PER_tick * (real32_T)
    RobotControl_B.EncoderIncrement_i.distCounter;

  /* DiscreteTransferFcn: '<S76>/MotorTransferFunction' incorporates:
   *  Gain: '<S72>/Gain'
   *  Sum: '<S72>/Add2'
   */
  MotorTransferFunction_tmp = (((real32_T)RobotControl_P.Gain_Gain_h *
    1.90734863E-6F * (real32_T)(rtb_leftPosPin_z - rtb_leftNegPin_z) -
    RobotControl_P.MotorTransferFunction_DenCoef[1L] *
    RobotControl_DW.MotorTransferFunction_states[0L]) -
    RobotControl_P.MotorTransferFunction_DenCoef[2L] *
    RobotControl_DW.MotorTransferFunction_states[1L]) /
    RobotControl_P.MotorTransferFunction_DenCoef[0];

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/CAL_WheelDiameter_cm'
   *  Constant: '<S72>/CONST_TWO_F32'
   *  Constant: '<S72>/gearRatio'
   *  DataTypeConversion: '<S72>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S76>/MotorTransferFunction'
   *  Gain: '<S72>/Gain1'
   *  Product: '<S72>/Divide'
   *  Product: '<S72>/Divide1'
   */
  rtb_Gain3_b = ((RobotControl_P.MotorTransferFunction_NumCoef[0] *
                  MotorTransferFunction_tmp +
                  RobotControl_P.MotorTransferFunction_NumCoef[1L] *
                  RobotControl_DW.MotorTransferFunction_states[0L]) +
                 RobotControl_P.MotorTransferFunction_NumCoef[2L] *
                 RobotControl_DW.MotorTransferFunction_states[1L]) / (real32_T)
    RobotControl_P.gearRatio * ((real32_T)(uint8_T)((uint16_T)
    RobotControl_P.Gain1_Gain * RobotControl_P.CAL_WheelDiameter_cm >> 4) /
    RobotControl_P.CONST_TWO_F32);

  /* Chart: '<S73>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S73>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch_j,
    &RobotControl_B.sf_SpdTickDetector, &RobotControl_DW.sf_SpdTickDetector);

  /* Switch: '<S75>/Init' incorporates:
   *  Constant: '<S71>/CONST_FALSE'
   *  Constant: '<S75>/Initial Condition'
   *  Logic: '<S75>/FixPt Logical Operator'
   *  UnitDelay: '<S75>/FixPt Unit Delay1'
   *  UnitDelay: '<S75>/FixPt Unit Delay2'
   */
  if (RobotControl_P.CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_a !=
       0)) {
    rtb_Gain = RobotControl_P.Unit_Delay_Enabled_Resettable1_;
  } else {
    rtb_Gain = RobotControl_DW.FixPtUnitDelay1_DSTATE_b;
  }

  /* End of Switch: '<S75>/Init' */

  /* Product: '<S71>/Product4' incorporates:
   *  Constant: '<S71>/CAL_procNoiseVelKF'
   */
  rtb_Product4 = RobotControl_P.CAL_procNoiseVelKF * rtb_Gain;

  /* Product: '<S71>/Divide1' incorporates:
   *  Constant: '<S71>/CAL_MeasNoiseVelKF'
   *  Sum: '<S71>/Add3'
   */
  rtb_KT = (RobotControl_P.CAL_MeasNoiseVelKF + rtb_Product4) / rtb_Product4;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/ENU_FORWARD'
   *  Gain: '<S69>/Gain2'
   *  RelationalOperator: '<S69>/Relational_Operator'
   */
  if (rtb_MotorDirection == RobotControl_P.ENU_FORWARD) {
    MotorTransferFunction_tmp_i = RobotControl_B.sf_SpdTickDetector.spd;
  } else {
    MotorTransferFunction_tmp_i = RobotControl_P.Gain2_Gain *
      RobotControl_B.sf_SpdTickDetector.spd;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S71>/Add4' incorporates:
   *  Product: '<S71>/Product5'
   *  Sum: '<S71>/Subtract2'
   */
  rtb_Gain3_b += (MotorTransferFunction_tmp_i - rtb_Gain3_b) * rtb_KT;

  /* DataTypeConversion: '<S71>/Data_Type_Conversion2' */
  RobotControl_B.leftVel1ms_mmPerSec = rtb_Gain3_b;

  /* DiscreteTransferFcn: '<S85>/MotorTransferFunction' incorporates:
   *  Gain: '<S81>/Gain'
   *  Sum: '<S81>/Add2'
   */
  MotorTransferFunction_tmp_i = (((real32_T)RobotControl_P.Gain_Gain_d *
    1.90734863E-6F * (real32_T)(rtb_rightPosPin_z - rtb_rightNegPin) -
    RobotControl_P.MotorTransferFunction_DenCoef_h[1L] *
    RobotControl_DW.MotorTransferFunction_states_n[0L]) -
    RobotControl_P.MotorTransferFunction_DenCoef_h[2L] *
    RobotControl_DW.MotorTransferFunction_states_n[1L]) /
    RobotControl_P.MotorTransferFunction_DenCoef_h[0];

  /* Product: '<S81>/Product' incorporates:
   *  Constant: '<S81>/CAL_WheelDiameter_cm'
   *  Constant: '<S81>/CONST_TWO_F32'
   *  Constant: '<S81>/gearRatio'
   *  DataTypeConversion: '<S81>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S85>/MotorTransferFunction'
   *  Gain: '<S81>/Gain1'
   *  Product: '<S81>/Divide'
   *  Product: '<S81>/Divide1'
   */
  rtb_Gain3_b = ((RobotControl_P.MotorTransferFunction_NumCoef_d[0] *
                  MotorTransferFunction_tmp_i +
                  RobotControl_P.MotorTransferFunction_NumCoef_d[1L] *
                  RobotControl_DW.MotorTransferFunction_states_n[0L]) +
                 RobotControl_P.MotorTransferFunction_NumCoef_d[2L] *
                 RobotControl_DW.MotorTransferFunction_states_n[1L]) / (real32_T)
    RobotControl_P.gearRatio * ((real32_T)(uint8_T)((uint16_T)
    RobotControl_P.Gain1_Gain_k * RobotControl_P.CAL_WheelDiameter_cm >> 4) /
    RobotControl_P.CONST_TWO_F32);

  /* Chart: '<S82>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S82>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch1_k,
    &RobotControl_B.sf_SpdTickDetector_e, &RobotControl_DW.sf_SpdTickDetector_e);

  /* Switch: '<S84>/Init' incorporates:
   *  Constant: '<S80>/CONST_FALSE'
   *  Constant: '<S84>/Initial Condition'
   *  Logic: '<S84>/FixPt Logical Operator'
   *  UnitDelay: '<S84>/FixPt Unit Delay1'
   *  UnitDelay: '<S84>/FixPt Unit Delay2'
   */
  if (RobotControl_P.CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_l !=
       0)) {
    rtb_inputVoltage_V = RobotControl_P.Unit_Delay_Enabled_Resettable_h;
  } else {
    rtb_inputVoltage_V = RobotControl_DW.FixPtUnitDelay1_DSTATE_n;
  }

  /* End of Switch: '<S84>/Init' */

  /* Product: '<S80>/Product4' incorporates:
   *  Constant: '<S80>/CAL_procNoiseVelKF'
   */
  rtb_Product4_l = RobotControl_P.CAL_procNoiseVelKF * rtb_inputVoltage_V;

  /* Product: '<S80>/Divide1' incorporates:
   *  Constant: '<S80>/CAL_MeasNoiseVelKF'
   *  Sum: '<S80>/Add3'
   */
  rtb_KT_i = (RobotControl_P.CAL_MeasNoiseVelKF + rtb_Product4_l) /
    rtb_Product4_l;

  /* Switch: '<S78>/Switch' incorporates:
   *  Constant: '<S78>/ENU_FORWARD'
   *  Gain: '<S78>/Gain2'
   *  RelationalOperator: '<S78>/Relational_Operator'
   */
  if (rtb_MotorDirection_m == RobotControl_P.ENU_FORWARD) {
    rtb_Switch_i = RobotControl_B.sf_SpdTickDetector_e.spd;
  } else {
    rtb_Switch_i = RobotControl_P.Gain2_Gain_b *
      RobotControl_B.sf_SpdTickDetector_e.spd;
  }

  /* End of Switch: '<S78>/Switch' */

  /* DataTypeConversion: '<S80>/Data_Type_Conversion3' incorporates:
   *  Product: '<S80>/Product5'
   *  Sum: '<S80>/Add4'
   *  Sum: '<S80>/Subtract2'
   */
  RobotControl_B.rightVel1ms_mmPerSec = (rtb_Switch_i - rtb_Gain3_b) * rtb_KT_i
    + rtb_Gain3_b;

  /* Sum: '<S54>/Add5' incorporates:
   *  Delay: '<S54>/Delay'
   *  Delay: '<S54>/Delay1'
   *  Sum: '<S54>/Add4'
   */
  rtb_Switch_i = (rtb_motorDistance - RobotControl_DW.Delay_DSTATE_a[0]) +
    RobotControl_DW.Delay1_DSTATE_e;

  /* DataTypeConversion: '<S54>/Data_Type_Conversion' incorporates:
   *  Gain: '<S54>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion = RobotControl_P.Gain3_Gain_c *
    rtb_Switch_i;

  /* Sum: '<S55>/Add5' incorporates:
   *  Delay: '<S55>/Delay'
   *  Delay: '<S55>/Delay1'
   *  Sum: '<S55>/Add4'
   */
  rtb_Gain3_b = (rtb_motorDistance_b - RobotControl_DW.Delay_DSTATE_l[0]) +
    RobotControl_DW.Delay1_DSTATE_i;

  /* DataTypeConversion: '<S55>/Data_Type_Conversion' incorporates:
   *  Gain: '<S55>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_m = RobotControl_P.Gain3_Gain_e *
    rtb_Gain3_b;

  /* Outputs for Enabled SubSystem: '<S19>/EncoderThetaCalculation' incorporates:
   *  EnablePort: '<S48>/EncoderThetaEnable'
   */
  /* Sum: '<S48>/Add1' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S59>/CAL_ROBO_LENG_mm'
   *  Product: '<S48>/Product'
   *  Product: '<S59>/Divide1'
   *  Sum: '<S59>/Add'
   *  UnitDelay: '<S48>/Unit_Delay'
   */
  RobotControl_B.Add1_l = (RobotControl_B.leftVel1ms_mmPerSec -
    RobotControl_B.rightVel1ms_mmPerSec) / (real32_T)
    RobotControl_P.CAL_ROBO_LENG_mm * RobotControl_P.Constant_Value +
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
  if (RobotControl_B.Add1_l > RobotControl_P.Constant3_Value) {
    RobotControl_B.Add1_l -= RobotControl_P.Constant1_Value_b;
  } else {
    if (RobotControl_B.Add1_l < RobotControl_P.Constant2_Value_k) {
      /* Switch: '<S61>/Switch1' incorporates:
       *  Sum: '<S61>/Add1'
       */
      RobotControl_B.Add1_l += RobotControl_P.Constant3_Value;
    }
  }

  /* End of Switch: '<S61>/Switch' */

  /* Product: '<S58>/Product' incorporates:
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant2'
   *  Product: '<S58>/Divide'
   */
  RobotControl_B.deg_m = RobotControl_P.Constant2_Value_i /
    RobotControl_P.Constant1_Value_p * RobotControl_B.Add1_l;

  /* Sum: '<S60>/Add5' incorporates:
   *  Delay: '<S60>/Delay'
   *  Delay: '<S60>/Delay1'
   *  Sum: '<S60>/Add4'
   */
  RobotControl_B.Add5 = (RobotControl_B.deg_m - RobotControl_DW.Delay_DSTATE[0])
    + RobotControl_DW.Delay1_DSTATE;

  /* DataTypeConversion: '<S60>/Data_Type_Conversion' incorporates:
   *  Gain: '<S60>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_a = (real32_T)(RobotControl_P.Gain3_Gain *
    RobotControl_B.Add5);

  /* Update for UnitDelay: '<S48>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = RobotControl_B.Add1_l;

  /* Update for Delay: '<S60>/Delay' */
  RobotControl_DW.Delay_DSTATE[0] = RobotControl_DW.Delay_DSTATE[1];
  RobotControl_DW.Delay_DSTATE[1] = RobotControl_DW.Delay_DSTATE[2];
  RobotControl_DW.Delay_DSTATE[2] = RobotControl_DW.Delay_DSTATE[3];
  RobotControl_DW.Delay_DSTATE[3] = RobotControl_DW.Delay_DSTATE[4];
  RobotControl_DW.Delay_DSTATE[4] = RobotControl_B.deg_m;

  /* Update for Delay: '<S60>/Delay1' */
  RobotControl_DW.Delay1_DSTATE = RobotControl_B.Add5;

  /* End of Outputs for SubSystem: '<S19>/EncoderThetaCalculation' */

  /* Outputs for Enabled SubSystem: '<S49>/endofLineTest' incorporates:
   *  EnablePort: '<S62>/CONST_EndOfLineEnableFlg'
   */
  /* Constant: '<S49>/CONST_EndOfLineEnableFlg' */
  if (RobotControl_P.CONST_EndOfLineEnableFlg) {
    if (!RobotControl_DW.endofLineTest_MODE) {
      RobotControl_DW.endofLineTest_MODE = true;
    }

    /* Outputs for Enabled SubSystem: '<S62>/LeftMotorEncoderCounter' incorporates:
     *  EnablePort: '<S64>/counterReset'
     */
    /* UnitDelay: '<S62>/Unit_Delay' */
    if (RobotControl_DW.Unit_Delay_DSTATE_ja) {
      if (!RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* InitializeConditions for UnitDelay: '<S64>/Unit_Delay' */
        RobotControl_DW.Unit_Delay_DSTATE_i =
          RobotControl_P.Unit_Delay_InitialCondition;
        RobotControl_DW.LeftMotorEncoderCounter_MODE = true;
      }

      /* Switch: '<S64>/Switch' incorporates:
       *  Constant: '<S64>/CONST_ONE_UINT16'
       *  RelationalOperator: '<S64>/Relational_Operator'
       *  Sum: '<S64>/Add'
       *  UnitDelay: '<S19>/Unit_Delay4'
       *  UnitDelay: '<S64>/Unit_Delay'
       */
      if (rtb_Switch_j != RobotControl_DW.Unit_Delay4_DSTATE_m) {
        rtb_Switch_h = RobotControl_DW.Unit_Delay_DSTATE_i + (real32_T)
          RobotControl_P.CONST_ONE_UINT16;
      } else {
        rtb_Switch_h = RobotControl_DW.Unit_Delay_DSTATE_i;
      }

      /* End of Switch: '<S64>/Switch' */

      /* DataTypeConversion: '<S64>/Data_Type_Conversion' */
      RobotControl_B.encoderCounter = (uint16_T)rtb_Switch_h;

      /* Update for UnitDelay: '<S64>/Unit_Delay' */
      RobotControl_DW.Unit_Delay_DSTATE_i = rtb_Switch_h;
    } else {
      if (RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* Disable for Outport: '<S64>/encoderCounter' */
        RobotControl_B.encoderCounter = RobotControl_P.encoderCounter_Y0;
        RobotControl_DW.LeftMotorEncoderCounter_MODE = false;
      }
    }

    /* End of UnitDelay: '<S62>/Unit_Delay' */
    /* End of Outputs for SubSystem: '<S62>/LeftMotorEncoderCounter' */

    /* Chart: '<S63>/EOL_TickStateMachine' incorporates:
     *  DataTypeConversion: '<S63>/Data Type Conversion2'
     */
    /* Gateway: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    if (RobotControl_DW.temporalCounter_i1_i < 16383U) {
      RobotControl_DW.temporalCounter_i1_i++;
    }

    /* During: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    if (RobotControl_DW.is_active_c33_DSCA == 0U) {
      /* Entry: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      RobotControl_DW.is_active_c33_DSCA = 1U;

      /* Entry Internal: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      /* Transition: '<S66>:12' */
      RobotControl_DW.is_c33_DSCA = RobotControl_IN_InitializeTest;
      RobotControl_DW.temporalCounter_i1_i = 0U;

      /* Entry 'InitializeTest': '<S66>:11' */
      RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
      RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
      RobotControl_B.counterReset = true;
    } else {
      switch (RobotControl_DW.is_c33_DSCA) {
       case RobotControl_IN_FastPwm:
        /* During 'FastPwm': '<S66>:14' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S66>:20' */
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.counterReset = true;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_SuperFastPwm;
          RobotControl_DW.temporalCounter_i1_i = 0U;
        } else {
          if (RobotControl_DW.temporalCounter_i1_i >= RobotControl_CONST_EnDelay)
          {
            RobotControl_B.counterReset = false;
            RobotControl_B.EOL_pwm = 200.0F;
            RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_FORWARD;
            RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_FORWARD;
          }
        }
        break;

       case RobotControl_IN_InitializeTest:
        /* During 'InitializeTest': '<S66>:11' */
        if (RobotControl_DW.temporalCounter_i1_i >= RobotControl_CONST_EnDelay)
        {
          /* Transition: '<S66>:16' */
          RobotControl_B.counterReset = false;
          RobotControl_B.EOL_pwm = 100.0F;
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_FORWARD;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_FORWARD;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_SlowPwm;
        }
        break;

       case RobotControl_IN_MediumPwm:
        /* During 'MediumPwm': '<S66>:15' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S66>:18' */
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.counterReset = true;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_FastPwm;
          RobotControl_DW.temporalCounter_i1_i = 0U;
        } else {
          if (RobotControl_DW.temporalCounter_i1_i >= RobotControl_CONST_EnDelay)
          {
            RobotControl_B.counterReset = false;
            RobotControl_B.EOL_pwm = 150.0F;
            RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_FORWARD;
            RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_FORWARD;
          }
        }
        break;

       case RobotControl_IN_SlowPwm:
        /* During 'SlowPwm': '<S66>:13' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S66>:17' */
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.counterReset = true;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_MediumPwm;
          RobotControl_DW.temporalCounter_i1_i = 0U;
        }
        break;

       default:
        /* During 'SuperFastPwm': '<S66>:19' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S66>:21' */
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_InitializeTest;
          RobotControl_DW.temporalCounter_i1_i = 0U;

          /* Entry 'InitializeTest': '<S66>:11' */
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.counterReset = true;
        } else {
          if (RobotControl_DW.temporalCounter_i1_i >= RobotControl_CONST_EnDelay)
          {
            RobotControl_B.counterReset = false;
            RobotControl_B.EOL_pwm = 250.0F;
            RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_FORWARD;
            RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_FORWARD;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S63>/EOL_TickStateMachine' */

    /* Update for UnitDelay: '<S62>/Unit_Delay' incorporates:
     *  Logic: '<S62>/Logical_Operator'
     */
    RobotControl_DW.Unit_Delay_DSTATE_ja = !RobotControl_B.counterReset;
  } else {
    if (RobotControl_DW.endofLineTest_MODE) {
      /* Disable for Enabled SubSystem: '<S62>/LeftMotorEncoderCounter' */
      if (RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* Disable for Outport: '<S64>/encoderCounter' */
        RobotControl_B.encoderCounter = RobotControl_P.encoderCounter_Y0;
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
  }

  /* End of Constant: '<S49>/CONST_EndOfLineEnableFlg' */
  /* End of Outputs for SubSystem: '<S49>/endofLineTest' */

  /* Switch: '<S75>/Reset' incorporates:
   *  Constant: '<S71>/CONST_EnableDelay'
   *  Constant: '<S71>/CONST_FALSE'
   *  Constant: '<S75>/Initial Condition'
   *  Constant: '<S84>/Initial Condition'
   *  Switch: '<S74>/Enable'
   *  Switch: '<S83>/Enable'
   *  Switch: '<S84>/Reset'
   */
  if (RobotControl_P.CONST_FALSE) {
    rtb_Gain = RobotControl_P.Unit_Delay_Enabled_Resettable1_;
    rtb_inputVoltage_V = RobotControl_P.Unit_Delay_Enabled_Resettable_h;
  } else {
    if (RobotControl_P.CONST_EnableDelay) {
      /* Switch: '<S74>/Enable' incorporates:
       *  Constant: '<S71>/CONST_ONE_F32'
       *  Product: '<S71>/Product6'
       *  Sum: '<S71>/Subtract3'
       */
      rtb_Gain = (RobotControl_P.CONST_ONE_F32 - rtb_KT) * rtb_Product4;

      /* Switch: '<S83>/Enable' incorporates:
       *  Constant: '<S80>/CONST_ONE_F32'
       *  Product: '<S80>/Product6'
       *  Sum: '<S80>/Subtract3'
       */
      rtb_inputVoltage_V = (RobotControl_P.CONST_ONE_F32 - rtb_KT_i) *
        rtb_Product4_l;
    }
  }

  /* End of Switch: '<S75>/Reset' */

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
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = RobotControl_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S75>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = rtb_Gain;

  /* Update for DiscreteTransferFcn: '<S85>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_n[1L] =
    RobotControl_DW.MotorTransferFunction_states_n[0L];
  RobotControl_DW.MotorTransferFunction_states_n[0L] =
    MotorTransferFunction_tmp_i;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S84>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l =
    RobotControl_P.FixPtConstant_Value_b;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = rtb_inputVoltage_V;

  /* Update for Delay: '<S54>/Delay' */
  RobotControl_DW.Delay_DSTATE_a[0] = RobotControl_DW.Delay_DSTATE_a[1];
  RobotControl_DW.Delay_DSTATE_a[1] = RobotControl_DW.Delay_DSTATE_a[2];
  RobotControl_DW.Delay_DSTATE_a[2] = RobotControl_DW.Delay_DSTATE_a[3];
  RobotControl_DW.Delay_DSTATE_a[3] = RobotControl_DW.Delay_DSTATE_a[4];
  RobotControl_DW.Delay_DSTATE_a[4] = rtb_motorDistance;

  /* Update for Delay: '<S54>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = rtb_Switch_i;

  /* Update for Delay: '<S55>/Delay' */
  RobotControl_DW.Delay_DSTATE_l[0] = RobotControl_DW.Delay_DSTATE_l[1];
  RobotControl_DW.Delay_DSTATE_l[1] = RobotControl_DW.Delay_DSTATE_l[2];
  RobotControl_DW.Delay_DSTATE_l[2] = RobotControl_DW.Delay_DSTATE_l[3];
  RobotControl_DW.Delay_DSTATE_l[3] = RobotControl_DW.Delay_DSTATE_l[4];
  RobotControl_DW.Delay_DSTATE_l[4] = rtb_motorDistance_b;

  /* Update for Delay: '<S55>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = rtb_Gain3_b;

  /* Update for UnitDelay: '<S19>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S19>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_m = rtb_Switch_j;
}
