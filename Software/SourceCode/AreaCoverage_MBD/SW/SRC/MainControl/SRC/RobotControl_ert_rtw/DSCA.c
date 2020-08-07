/*
 * File: DSCA.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.555
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 02:48:56 2020
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

/* Named constants for Chart: '<S78>/SpdTickDetector' */
#define RobotContr_IN_NO_ACTIVE_CHILD_a ((uint8_T)0U)
#define RobotControl_CAL_mmPerTickPerTs (802.108704F)
#define RobotControl_CONST_VEL_TIMEOUT ((uint8_T)100U)
#define RobotControl_IN_counting       ((uint8_T)1U)
#define RobotControl_IN_stop           ((uint8_T)2U)

/* Named constants for Chart: '<S68>/EOL_TickStateMachine' */
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

/*
 * System initialize for atomic system:
 *    '<S7>/Analog_uint16_IN'
 *    '<S7>/Analog_uint16_IN1'
 */
void RobotCont_Analog_uint16_IN_Init(B_Analog_uint16_IN_RobotContr_T *localB)
{
  localB->value = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S7>/Analog_uint16_IN'
 *    '<S7>/Analog_uint16_IN1'
 */
void RobotControl_Analog_uint16_IN(uint8_T rtu_pin,
  B_Analog_uint16_IN_RobotContr_T *localB)
{
  /* Gateway: InputHandler/EncoderAnalogIn/Analog_uint16_IN */
  /* During: InputHandler/EncoderAnalogIn/Analog_uint16_IN */
  /* Entry Internal: InputHandler/EncoderAnalogIn/Analog_uint16_IN */
  /* Transition: '<S11>:2' */
  /* Transition: '<S11>:4' */
  localB->value = (uint16_T)analogRead(rtu_pin);
}

/* System initialize for function-call system: '<S1>/EncoderAnalogIn' */
void RobotContr_EncoderAnalogIn_Init(void)
{
  /* SystemInitialize for Chart: '<S7>/Analog_uint16_IN1' */
  RobotCont_Analog_uint16_IN_Init(&RobotControl_B.sf_Analog_uint16_IN1);

  /* SystemInitialize for Chart: '<S7>/Analog_uint16_IN' */
  RobotCont_Analog_uint16_IN_Init(&RobotControl_B.sf_Analog_uint16_IN);
}

/* Output and update for function-call system: '<S1>/EncoderAnalogIn' */
void RobotControl_EncoderAnalogIn(void)
{
  /* Chart: '<S7>/Analog_uint16_IN1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  RobotControl_Analog_uint16_IN(((uint8_T)PIN_A0),
    &RobotControl_B.sf_Analog_uint16_IN1);

  /* Chart: '<S7>/Analog_uint16_IN' incorporates:
   *  Constant: '<S7>/Constant'
   */
  RobotControl_Analog_uint16_IN(((uint8_T)PIN_A1),
    &RobotControl_B.sf_Analog_uint16_IN);
}

/*
 * Output and update for trigger system:
 *    '<S57>/EncoderIncrement'
 *    '<S58>/EncoderIncrement'
 */
void RobotControl_EncoderIncrement(boolean_T rtu_EncoderTicks_Bool, uint8_T
  rtu_motorDirection, B_EncoderIncrement_RobotContr_T *localB,
  ZCE_EncoderIncrement_RobotCon_T *localZCE)
{
  int32_T rtu_motorDirection_0;

  /* Outputs for Triggered SubSystem: '<S57>/EncoderIncrement' incorporates:
   *  TriggerPort: '<S61>/EncoderTicks_Bool'
   */
  if (rtu_EncoderTicks_Bool && (localZCE->EncoderIncrement_Trig_ZCE != POS_ZCSIG))
  {
    /* Switch: '<S61>/Switch1' incorporates:
     *  Constant: '<S61>/CONST_NEG_ONE_INT32'
     *  Constant: '<S61>/CONST_ONE_INT32'
     *  Constant: '<S61>/ENU_FORWARD'
     *  RelationalOperator: '<S61>/Relational_Operator'
     */
    if (rtu_motorDirection == ((uint8_T)ENU_FORWARD)) {
      rtu_motorDirection_0 = ((int32_T)CONST_ONE_INT32);
    } else {
      rtu_motorDirection_0 = ((int32_T)CONST_NEG_ONE_INT32);
    }

    /* End of Switch: '<S61>/Switch1' */

    /* Sum: '<S61>/Add' incorporates:
     *  UnitDelay: '<S61>/Unit_Delay'
     */
    localB->distCounter += rtu_motorDirection_0;
  }

  localZCE->EncoderIncrement_Trig_ZCE = rtu_EncoderTicks_Bool;

  /* End of Outputs for SubSystem: '<S57>/EncoderIncrement' */
}

/*
 * System initialize for atomic system:
 *    '<S78>/SpdTickDetector'
 *    '<S87>/SpdTickDetector'
 */
void RobotContr_SpdTickDetector_Init(B_SpdTickDetector_RobotContro_T *localB,
  DW_SpdTickDetector_RobotContr_T *localDW)
{
  localDW->is_active_c9_DSCA = 0U;
  localDW->is_c9_DSCA = RobotContr_IN_NO_ACTIVE_CHILD_a;
  localDW->cycleCnt = 0U;
  localB->spd = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S78>/SpdTickDetector'
 *    '<S87>/SpdTickDetector'
 */
void RobotControl_SpdTickDetector(real32_T rtu_encoderTick,
  B_SpdTickDetector_RobotContro_T *localB, DW_SpdTickDetector_RobotContr_T
  *localDW)
{
  /* Gateway: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  localDW->encoderTick_prev = localDW->encoderTick_start;
  localDW->encoderTick_start = rtu_encoderTick;

  /* During: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
  /* calculates speed of motor from ticks of encoder. it is not the best technique so it need some kind of filtration for the output spd data. */
  if (localDW->is_active_c9_DSCA == 0U) {
    localDW->encoderTick_prev = rtu_encoderTick;

    /* Entry: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    localDW->is_active_c9_DSCA = 1U;

    /* Entry Internal: DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector */
    /* Transition: '<S82>:2' */
    localDW->is_c9_DSCA = RobotControl_IN_counting;

    /* Entry 'counting': '<S82>:3' */
    localDW->cycleCnt = 1U;
  } else if (localDW->is_c9_DSCA == RobotControl_IN_counting) {
    /* During 'counting': '<S82>:3' */
    if ((localDW->encoderTick_prev != localDW->encoderTick_start) &&
        (localDW->encoderTick_start == 1.0F)) {
      /* Transition: '<S82>:7' */
      localB->spd = RobotControl_CAL_mmPerTickPerTs / (real32_T)
        localDW->cycleCnt;
      localDW->is_c9_DSCA = RobotControl_IN_counting;

      /* Entry 'counting': '<S82>:3' */
      localDW->cycleCnt = 1U;
    } else if (localDW->cycleCnt > RobotControl_CONST_VEL_TIMEOUT) {
      /* Transition: '<S82>:9' */
      localDW->is_c9_DSCA = RobotControl_IN_stop;

      /* Entry 'stop': '<S82>:8' */
      localB->spd = 0.0F;
    } else {
      localDW->cycleCnt++;
    }
  } else {
    /* During 'stop': '<S82>:8' */
    if (localDW->encoderTick_prev != localDW->encoderTick_start) {
      /* Transition: '<S82>:10' */
      localDW->is_c9_DSCA = RobotControl_IN_counting;

      /* Entry 'counting': '<S82>:3' */
      localDW->cycleCnt = 1U;
    }
  }
}

/* System initialize for function-call system: '<S21>/DSCA' */
void RobotControl_DSCA_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S89>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 1U;

  /* InitializeConditions for UnitDelay: '<S89>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = 1.0F;

  /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = 1.0F;

  /* SystemInitialize for Chart: '<S87>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector,
    &RobotControl_DW.sf_SpdTickDetector);

  /* SystemInitialize for Chart: '<S78>/SpdTickDetector' */
  RobotContr_SpdTickDetector_Init(&RobotControl_B.sf_SpdTickDetector_o,
    &RobotControl_DW.sf_SpdTickDetector_o);

  /* SystemInitialize for Enabled SubSystem: '<S24>/EncoderThetaCalculation' */
  /* InitializeConditions for UnitDelay: '<S53>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE = CAL_NORTH_rad;

  /* End of SystemInitialize for SubSystem: '<S24>/EncoderThetaCalculation' */

  /* SystemInitialize for Enabled SubSystem: '<S54>/endofLineTest' */
  /* InitializeConditions for UnitDelay: '<S67>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_ja = true;

  /* SystemInitialize for Enabled SubSystem: '<S67>/LeftMotorEncoderCounter' */
  /* InitializeConditions for UnitDelay: '<S69>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S67>/LeftMotorEncoderCounter' */

  /* SystemInitialize for Chart: '<S68>/EOL_TickStateMachine' */
  RobotControl_DW.temporalCounter_i1_i = 0U;
  RobotControl_DW.is_active_c33_DSCA = 0U;
  RobotControl_DW.is_c33_DSCA = RobotContr_IN_NO_ACTIVE_CHILD_p;
  RobotControl_B.EOL_pwm = 0.0F;
  RobotControl_B.EOL_leftMoveReq = 0U;
  RobotControl_B.EOL_rightMoveReq = 0U;
  RobotControl_B.counterReset = false;

  /* End of SystemInitialize for SubSystem: '<S54>/endofLineTest' */
}

/* Output and update for function-call system: '<S21>/DSCA' */
void RobotControl_DSCA(void)
{
  uint8_T rtb_leftNegPin_z;
  uint8_T rtb_leftPosPin_z;
  real32_T rtb_Add5_b;
  uint8_T rtb_rightNegPin;
  uint8_T rtb_rightPosPin_z;
  real32_T rtb_motorDistance_f;
  real32_T rtb_Add5_n;
  real32_T rtb_inputVoltage_V;
  real32_T rtb_XT;
  boolean_T rtb_Switch1_k;
  uint8_T rtb_MotorDirection_m;
  real32_T rtb_Product4;
  real32_T rtb_KT;
  boolean_T rtb_Switch_l;
  uint8_T rtb_MotorDirection;
  real32_T rtb_Init_j;
  real32_T rtb_Product4_p;
  real32_T rtb_KT_e2;
  real32_T MotorTransferFunction_tmp;
  real32_T MotorTransferFunction_tmp_b;
  real32_T rtb_MotorDirection_0;

  /* UnitDelay: '<S24>/Unit_Delay5' */
  rtb_leftPosPin_z = RobotControl_DW.Unit_Delay5_DSTATE_p;

  /* UnitDelay: '<S24>/Unit_Delay6' */
  rtb_leftNegPin_z = RobotControl_DW.Unit_Delay6_DSTATE;

  /* Switch: '<S92>/Switch5' incorporates:
   *  Constant: '<S92>/ENU_FORWARD'
   *  Constant: '<S92>/ENU_STOP'
   *  RelationalOperator: '<S92>/Relational_Operator5'
   *  RelationalOperator: '<S92>/Relational_Operator6'
   *  Switch: '<S92>/Switch6'
   */
  if (rtb_leftPosPin_z > rtb_leftNegPin_z) {
    rtb_MotorDirection = ((uint8_T)ENU_FORWARD);
  } else if (rtb_leftPosPin_z < rtb_leftNegPin_z) {
    /* Switch: '<S92>/Switch6' incorporates:
     *  Constant: '<S92>/ENU_BACKWARD'
     */
    rtb_MotorDirection = ((uint8_T)ENU_BACKWARD);
  } else {
    rtb_MotorDirection = ((uint8_T)ENU_STOP);
  }

  /* End of Switch: '<S92>/Switch5' */

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/CAL_EncoderAnaThd'
   *  RelationalOperator: '<S52>/Relational Operator'
   */
  rtb_Switch_l = (RobotControl_B.sf_Analog_uint16_IN.value > CAL_EncoderAnaThd);

  /* Outputs for Triggered SubSystem: '<S57>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch_l, rtb_MotorDirection,
    &RobotControl_B.EncoderIncrement, &RobotControl_PrevZCX.EncoderIncrement);

  /* End of Outputs for SubSystem: '<S57>/EncoderIncrement' */

  /* Gain: '<S57>/Gain1' incorporates:
   *  DataTypeConversion: '<S57>/Data_Type_Conversion'
   */
  RobotControl_B.motorDistance = CAL_mm_PER_tick * (real32_T)
    RobotControl_B.EncoderIncrement.distCounter;

  /* Sum: '<S59>/Add5' incorporates:
   *  Delay: '<S59>/Delay'
   *  Delay: '<S59>/Delay1'
   *  Sum: '<S59>/Add4'
   */
  rtb_Add5_b = (RobotControl_B.motorDistance - RobotControl_DW.Delay_DSTATE_a[0])
    + RobotControl_DW.Delay1_DSTATE_e;

  /* DataTypeConversion: '<S59>/Data_Type_Conversion' incorporates:
   *  Gain: '<S59>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion = 0.2F * rtb_Add5_b;

  /* UnitDelay: '<S24>/Unit_Delay7' */
  rtb_rightPosPin_z = RobotControl_DW.Unit_Delay7_DSTATE;

  /* UnitDelay: '<S24>/Unit_Delay8' */
  rtb_rightNegPin = RobotControl_DW.Unit_Delay8_DSTATE;

  /* Switch: '<S93>/Switch5' incorporates:
   *  Constant: '<S93>/ENU_FORWARD'
   *  Constant: '<S93>/ENU_STOP'
   *  RelationalOperator: '<S93>/Relational_Operator5'
   *  RelationalOperator: '<S93>/Relational_Operator6'
   *  Switch: '<S93>/Switch6'
   */
  if (rtb_rightPosPin_z > rtb_rightNegPin) {
    rtb_MotorDirection_m = ((uint8_T)ENU_FORWARD);
  } else if (rtb_rightPosPin_z < rtb_rightNegPin) {
    /* Switch: '<S93>/Switch6' incorporates:
     *  Constant: '<S93>/ENU_BACKWARD'
     */
    rtb_MotorDirection_m = ((uint8_T)ENU_BACKWARD);
  } else {
    rtb_MotorDirection_m = ((uint8_T)ENU_STOP);
  }

  /* End of Switch: '<S93>/Switch5' */

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S52>/CAL_EncoderAnaThd1'
   *  RelationalOperator: '<S52>/Relational Operator1'
   */
  rtb_Switch1_k = (RobotControl_B.sf_Analog_uint16_IN1.value > CAL_EncoderAnaThd);

  /* Outputs for Triggered SubSystem: '<S58>/EncoderIncrement' */
  RobotControl_EncoderIncrement(rtb_Switch1_k, rtb_MotorDirection_m,
    &RobotControl_B.EncoderIncrement_i, &RobotControl_PrevZCX.EncoderIncrement_i);

  /* End of Outputs for SubSystem: '<S58>/EncoderIncrement' */

  /* Gain: '<S58>/Gain1' incorporates:
   *  DataTypeConversion: '<S58>/Data_Type_Conversion'
   */
  rtb_motorDistance_f = CAL_mm_PER_tick * (real32_T)
    RobotControl_B.EncoderIncrement_i.distCounter;

  /* Sum: '<S60>/Add5' incorporates:
   *  Delay: '<S60>/Delay'
   *  Delay: '<S60>/Delay1'
   *  Sum: '<S60>/Add4'
   */
  rtb_Add5_n = (rtb_motorDistance_f - RobotControl_DW.Delay_DSTATE_l[0]) +
    RobotControl_DW.Delay1_DSTATE_i;

  /* DataTypeConversion: '<S60>/Data_Type_Conversion' incorporates:
   *  Gain: '<S60>/Gain3'
   */
  RobotControl_B.Data_Type_Conversion_m = 0.2F * rtb_Add5_n;

  /* DiscreteTransferFcn: '<S90>/MotorTransferFunction' incorporates:
   *  Gain: '<S86>/Gain'
   *  Sum: '<S86>/Add2'
   */
  MotorTransferFunction_tmp = (((real32_T)(rtb_rightPosPin_z - rtb_rightNegPin) *
    0.0470581055F - -237187.5F * RobotControl_DW.MotorTransferFunction_states[0L])
    - -549093.75F * RobotControl_DW.MotorTransferFunction_states[1L]) /
    951906.25F;

  /* Product: '<S86>/Product' incorporates:
   *  Constant: '<S86>/CAL_WheelDiameter_cm'
   *  Constant: '<S86>/CONST_TWO_F32'
   *  Constant: '<S86>/gearRatio'
   *  DataTypeConversion: '<S86>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S90>/MotorTransferFunction'
   *  Gain: '<S86>/Gain1'
   *  Product: '<S86>/Divide'
   *  Product: '<S86>/Divide1'
   */
  rtb_XT = ((78125.0F * MotorTransferFunction_tmp + 156250.0F *
             RobotControl_DW.MotorTransferFunction_states[0L]) + 78125.0F *
            RobotControl_DW.MotorTransferFunction_states[1L]) / (real32_T)
    gearRatio * ((real32_T)(uint8_T)(10U * ((uint8_T)CAL_WheelDiameter_cm)) /
                 CONST_TWO_F32);

  /* Chart: '<S87>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S87>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch1_k,
    &RobotControl_B.sf_SpdTickDetector, &RobotControl_DW.sf_SpdTickDetector);

  /* Switch: '<S89>/Init' incorporates:
   *  Constant: '<S85>/CONST_FALSE'
   *  Constant: '<S89>/Initial Condition'
   *  Logic: '<S89>/FixPt Logical Operator'
   *  UnitDelay: '<S89>/FixPt Unit Delay1'
   *  UnitDelay: '<S89>/FixPt Unit Delay2'
   */
  if (CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_l != 0)) {
    rtb_inputVoltage_V = 1.0F;
  } else {
    rtb_inputVoltage_V = RobotControl_DW.FixPtUnitDelay1_DSTATE_n;
  }

  /* End of Switch: '<S89>/Init' */

  /* Product: '<S85>/Product4' incorporates:
   *  Constant: '<S85>/CAL_procNoiseVelKF'
   */
  rtb_Product4 = CAL_procNoiseVelKF * rtb_inputVoltage_V;

  /* Product: '<S85>/Divide1' incorporates:
   *  Constant: '<S85>/CAL_MeasNoiseVelKF'
   *  Sum: '<S85>/Add3'
   */
  rtb_KT = (CAL_MeasNoiseVelKF + rtb_Product4) / rtb_Product4;

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/ENU_FORWARD'
   *  Gain: '<S83>/Gain2'
   *  RelationalOperator: '<S83>/Relational_Operator'
   */
  if (rtb_MotorDirection_m == ((uint8_T)ENU_FORWARD)) {
    MotorTransferFunction_tmp_b = RobotControl_B.sf_SpdTickDetector.spd;
  } else {
    MotorTransferFunction_tmp_b = -RobotControl_B.sf_SpdTickDetector.spd;
  }

  /* End of Switch: '<S83>/Switch' */

  /* Sum: '<S85>/Add4' incorporates:
   *  Product: '<S85>/Product5'
   *  Sum: '<S85>/Subtract2'
   */
  rtb_XT += (MotorTransferFunction_tmp_b - rtb_XT) * rtb_KT;

  /* DataTypeConversion: '<S85>/Data_Type_Conversion3' */
  RobotControl_B.rightVel1ms_mmPerSec = rtb_XT;

  /* DiscreteTransferFcn: '<S81>/MotorTransferFunction' incorporates:
   *  Gain: '<S77>/Gain'
   *  Sum: '<S77>/Add2'
   */
  MotorTransferFunction_tmp_b = (((real32_T)(rtb_leftPosPin_z - rtb_leftNegPin_z)
    * 0.0470581055F - -237187.5F *
    RobotControl_DW.MotorTransferFunction_states_j[0L]) - -549093.75F *
    RobotControl_DW.MotorTransferFunction_states_j[1L]) / 951906.25F;

  /* Product: '<S77>/Product' incorporates:
   *  Constant: '<S77>/CAL_WheelDiameter_cm'
   *  Constant: '<S77>/CONST_TWO_F32'
   *  Constant: '<S77>/gearRatio'
   *  DataTypeConversion: '<S77>/Data_Type_Conversion1'
   *  DiscreteTransferFcn: '<S81>/MotorTransferFunction'
   *  Gain: '<S77>/Gain1'
   *  Product: '<S77>/Divide'
   *  Product: '<S77>/Divide1'
   */
  rtb_XT = ((78125.0F * MotorTransferFunction_tmp_b + 156250.0F *
             RobotControl_DW.MotorTransferFunction_states_j[0L]) + 78125.0F *
            RobotControl_DW.MotorTransferFunction_states_j[1L]) / (real32_T)
    gearRatio * ((real32_T)(uint8_T)(10U * ((uint8_T)CAL_WheelDiameter_cm)) /
                 CONST_TWO_F32);

  /* Chart: '<S78>/SpdTickDetector' incorporates:
   *  DataTypeConversion: '<S78>/Data Type Conversion2'
   */
  RobotControl_SpdTickDetector((real32_T)rtb_Switch_l,
    &RobotControl_B.sf_SpdTickDetector_o, &RobotControl_DW.sf_SpdTickDetector_o);

  /* Switch: '<S80>/Init' incorporates:
   *  Constant: '<S76>/CONST_FALSE'
   *  Constant: '<S80>/Initial Condition'
   *  Logic: '<S80>/FixPt Logical Operator'
   *  UnitDelay: '<S80>/FixPt Unit Delay1'
   *  UnitDelay: '<S80>/FixPt Unit Delay2'
   */
  if (CONST_FALSE || (RobotControl_DW.FixPtUnitDelay2_DSTATE_a != 0)) {
    rtb_Init_j = 1.0F;
  } else {
    rtb_Init_j = RobotControl_DW.FixPtUnitDelay1_DSTATE_b;
  }

  /* End of Switch: '<S80>/Init' */

  /* Product: '<S76>/Product4' incorporates:
   *  Constant: '<S76>/CAL_procNoiseVelKF'
   */
  rtb_Product4_p = CAL_procNoiseVelKF * rtb_Init_j;

  /* Product: '<S76>/Divide1' incorporates:
   *  Constant: '<S76>/CAL_MeasNoiseVelKF'
   *  Sum: '<S76>/Add3'
   */
  rtb_KT_e2 = (CAL_MeasNoiseVelKF + rtb_Product4_p) / rtb_Product4_p;

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/ENU_FORWARD'
   *  Gain: '<S74>/Gain2'
   *  RelationalOperator: '<S74>/Relational_Operator'
   */
  if (rtb_MotorDirection == ((uint8_T)ENU_FORWARD)) {
    rtb_MotorDirection_0 = RobotControl_B.sf_SpdTickDetector_o.spd;
  } else {
    rtb_MotorDirection_0 = -RobotControl_B.sf_SpdTickDetector_o.spd;
  }

  /* End of Switch: '<S74>/Switch' */

  /* DataTypeConversion: '<S76>/Data_Type_Conversion2' incorporates:
   *  Product: '<S76>/Product5'
   *  Sum: '<S76>/Add4'
   *  Sum: '<S76>/Subtract2'
   */
  RobotControl_B.leftVel1ms_mmPerSec = (rtb_MotorDirection_0 - rtb_XT) *
    rtb_KT_e2 + rtb_XT;

  /* Outputs for Enabled SubSystem: '<S24>/EncoderThetaCalculation' incorporates:
   *  EnablePort: '<S53>/EncoderThetaEnable'
   */
  /* Logic: '<S24>/Logical_Operator1' incorporates:
   *  Constant: '<S24>/ENU_DIAG'
   *  RelationalOperator: '<S24>/Relational_Operator'
   *  UnitDelay: '<S24>/Unit_Delay2'
   */
  if ((RobotControl_DW.Unit_Delay2_DSTATE_b == ((uint8_T)ENU_DIAG)) ||
      RobotControl_ConstB.Logical_Operator_j) {
    /* Sum: '<S53>/Add1' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S64>/CAL_ROBO_LENG_mm'
     *  Product: '<S53>/Product'
     *  Product: '<S64>/Divide1'
     *  Sum: '<S64>/Add'
     *  UnitDelay: '<S53>/Unit_Delay'
     */
    RobotControl_B.Add1 = (RobotControl_B.leftVel1ms_mmPerSec -
      RobotControl_B.rightVel1ms_mmPerSec) / (real32_T)CAL_ROBO_LENG_mm * 0.001
      + RobotControl_DW.Unit_Delay_DSTATE;

    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/Constant1'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/Constant3'
     *  RelationalOperator: '<S66>/Relational Operator'
     *  RelationalOperator: '<S66>/Relational Operator1'
     *  Sum: '<S66>/Add'
     *  Switch: '<S66>/Switch1'
     */
    if (RobotControl_B.Add1 > 6.2831853071795862) {
      RobotControl_B.Add1 -= 6.2831853071795862;
    } else {
      if (RobotControl_B.Add1 < 0.0) {
        /* Switch: '<S66>/Switch1' incorporates:
         *  Sum: '<S66>/Add1'
         */
        RobotControl_B.Add1 += 6.2831853071795862;
      }
    }

    /* End of Switch: '<S66>/Switch' */

    /* Product: '<S63>/Product' */
    RobotControl_B.deg = RobotControl_ConstB.Divide_k * RobotControl_B.Add1;

    /* Sum: '<S65>/Add5' incorporates:
     *  Delay: '<S65>/Delay'
     *  Delay: '<S65>/Delay1'
     *  Sum: '<S65>/Add4'
     */
    RobotControl_B.Add5 = (RobotControl_B.deg - RobotControl_DW.Delay_DSTATE[0])
      + RobotControl_DW.Delay1_DSTATE;

    /* DataTypeConversion: '<S65>/Data_Type_Conversion' incorporates:
     *  Gain: '<S65>/Gain3'
     */
    RobotControl_B.Data_Type_Conversion_a = (real32_T)(0.20000000298023224 *
      RobotControl_B.Add5);

    /* Update for UnitDelay: '<S53>/Unit_Delay' */
    RobotControl_DW.Unit_Delay_DSTATE = RobotControl_B.Add1;

    /* Update for Delay: '<S65>/Delay' */
    RobotControl_DW.Delay_DSTATE[0] = RobotControl_DW.Delay_DSTATE[1];
    RobotControl_DW.Delay_DSTATE[1] = RobotControl_DW.Delay_DSTATE[2];
    RobotControl_DW.Delay_DSTATE[2] = RobotControl_DW.Delay_DSTATE[3];
    RobotControl_DW.Delay_DSTATE[3] = RobotControl_DW.Delay_DSTATE[4];
    RobotControl_DW.Delay_DSTATE[4] = RobotControl_B.deg;

    /* Update for Delay: '<S65>/Delay1' */
    RobotControl_DW.Delay1_DSTATE = RobotControl_B.Add5;
  }

  /* End of Logic: '<S24>/Logical_Operator1' */
  /* End of Outputs for SubSystem: '<S24>/EncoderThetaCalculation' */

  /* Outputs for Enabled SubSystem: '<S54>/endofLineTest' incorporates:
   *  EnablePort: '<S67>/CONST_EndOfLineEnableFlg'
   */
  /* Constant: '<S54>/CONST_EndOfLineEnableFlg' */
  if (CONST_EndOfLineEnableFlg) {
    if (!RobotControl_DW.endofLineTest_MODE) {
      RobotControl_DW.endofLineTest_MODE = true;
    }

    /* Outputs for Enabled SubSystem: '<S67>/LeftMotorEncoderCounter' incorporates:
     *  EnablePort: '<S69>/counterReset'
     */
    /* UnitDelay: '<S67>/Unit_Delay' */
    if (RobotControl_DW.Unit_Delay_DSTATE_ja) {
      if (!RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* InitializeConditions for UnitDelay: '<S69>/Unit_Delay' */
        RobotControl_DW.Unit_Delay_DSTATE_i = 0.0F;
        RobotControl_DW.LeftMotorEncoderCounter_MODE = true;
      }

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S69>/CONST_ONE_UINT16'
       *  RelationalOperator: '<S69>/Relational_Operator'
       *  Sum: '<S69>/Add'
       *  UnitDelay: '<S24>/Unit_Delay4'
       *  UnitDelay: '<S69>/Unit_Delay'
       */
      if (rtb_Switch_l != RobotControl_DW.Unit_Delay4_DSTATE_m) {
        rtb_XT = RobotControl_DW.Unit_Delay_DSTATE_i + (real32_T)
          CONST_ONE_UINT16;
      } else {
        rtb_XT = RobotControl_DW.Unit_Delay_DSTATE_i;
      }

      /* End of Switch: '<S69>/Switch' */

      /* DataTypeConversion: '<S69>/Data_Type_Conversion' */
      RobotControl_B.encoderCounter = (uint16_T)rtb_XT;

      /* Update for UnitDelay: '<S69>/Unit_Delay' */
      RobotControl_DW.Unit_Delay_DSTATE_i = rtb_XT;
    } else {
      if (RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* Disable for Outport: '<S69>/encoderCounter' */
        RobotControl_B.encoderCounter = 0U;
        RobotControl_DW.LeftMotorEncoderCounter_MODE = false;
      }
    }

    /* End of UnitDelay: '<S67>/Unit_Delay' */
    /* End of Outputs for SubSystem: '<S67>/LeftMotorEncoderCounter' */

    /* Chart: '<S68>/EOL_TickStateMachine' incorporates:
     *  DataTypeConversion: '<S68>/Data Type Conversion2'
     */
    /* Gateway: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    if (RobotControl_DW.temporalCounter_i1_i < 16383U) {
      RobotControl_DW.temporalCounter_i1_i++;
    }

    /* During: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
    /* generates scenario to test the motor encoder. it needs Serial print to get the data and detect the calibration which we are looking for which is; ticks_PER_mm or mm_Per_tick */
    if (RobotControl_DW.is_active_c33_DSCA == 0U) {
      /* Entry: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      RobotControl_DW.is_active_c33_DSCA = 1U;

      /* Entry Internal: DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine */
      /* Transition: '<S71>:12' */
      RobotControl_DW.is_c33_DSCA = RobotControl_IN_InitializeTest;
      RobotControl_DW.temporalCounter_i1_i = 0U;

      /* Entry 'InitializeTest': '<S71>:11' */
      RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
      RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
      RobotControl_B.counterReset = true;
    } else {
      switch (RobotControl_DW.is_c33_DSCA) {
       case RobotControl_IN_FastPwm:
        /* During 'FastPwm': '<S71>:14' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S71>:20' */
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
        /* During 'InitializeTest': '<S71>:11' */
        if (RobotControl_DW.temporalCounter_i1_i >= RobotControl_CONST_EnDelay)
        {
          /* Transition: '<S71>:16' */
          RobotControl_B.counterReset = false;
          RobotControl_B.EOL_pwm = 100.0F;
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_FORWARD;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_FORWARD;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_SlowPwm;
        }
        break;

       case RobotControl_IN_MediumPwm:
        /* During 'MediumPwm': '<S71>:15' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S71>:18' */
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
        /* During 'SlowPwm': '<S71>:13' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S71>:17' */
          RobotControl_B.EOL_leftMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.EOL_rightMoveReq = RobotControl_ENU_STOP;
          RobotControl_B.counterReset = true;
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_MediumPwm;
          RobotControl_DW.temporalCounter_i1_i = 0U;
        }
        break;

       default:
        /* During 'SuperFastPwm': '<S71>:19' */
        if (RobotControl_B.encoderCounter >= RobotControl_CONST_EOL_ME_Ticks) {
          /* Transition: '<S71>:21' */
          RobotControl_DW.is_c33_DSCA = RobotControl_IN_InitializeTest;
          RobotControl_DW.temporalCounter_i1_i = 0U;

          /* Entry 'InitializeTest': '<S71>:11' */
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

    /* End of Chart: '<S68>/EOL_TickStateMachine' */

    /* Update for UnitDelay: '<S67>/Unit_Delay' incorporates:
     *  Logic: '<S67>/Logical_Operator'
     */
    RobotControl_DW.Unit_Delay_DSTATE_ja = !RobotControl_B.counterReset;
  } else {
    if (RobotControl_DW.endofLineTest_MODE) {
      /* Disable for Enabled SubSystem: '<S67>/LeftMotorEncoderCounter' */
      if (RobotControl_DW.LeftMotorEncoderCounter_MODE) {
        /* Disable for Outport: '<S69>/encoderCounter' */
        RobotControl_B.encoderCounter = 0U;
        RobotControl_DW.LeftMotorEncoderCounter_MODE = false;
      }

      /* End of Disable for SubSystem: '<S67>/LeftMotorEncoderCounter' */

      /* Disable for Enabled SubSystem: '<S67>/RightMotorEncoderCounter1' */
      if (RobotControl_DW.RightMotorEncoderCounter1_MODE) {
        RobotControl_DW.RightMotorEncoderCounter1_MODE = false;
      }

      /* End of Disable for SubSystem: '<S67>/RightMotorEncoderCounter1' */
      RobotControl_DW.endofLineTest_MODE = false;
    }
  }

  /* End of Constant: '<S54>/CONST_EndOfLineEnableFlg' */
  /* End of Outputs for SubSystem: '<S54>/endofLineTest' */

  /* Switch: '<S80>/Reset' incorporates:
   *  Constant: '<S76>/CONST_EnableDelay'
   *  Constant: '<S76>/CONST_FALSE'
   *  Constant: '<S80>/Initial Condition'
   *  Constant: '<S89>/Initial Condition'
   *  Switch: '<S79>/Enable'
   *  Switch: '<S88>/Enable'
   *  Switch: '<S89>/Reset'
   */
  if (CONST_FALSE) {
    rtb_Init_j = 1.0F;
    rtb_inputVoltage_V = 1.0F;
  } else {
    if (CONST_EnableDelay) {
      /* Switch: '<S79>/Enable' incorporates:
       *  Constant: '<S76>/CONST_ONE_F32'
       *  Product: '<S76>/Product6'
       *  Sum: '<S76>/Subtract3'
       */
      rtb_Init_j = (CONST_ONE_F32 - rtb_KT_e2) * rtb_Product4_p;

      /* Switch: '<S88>/Enable' incorporates:
       *  Constant: '<S85>/CONST_ONE_F32'
       *  Product: '<S85>/Product6'
       *  Sum: '<S85>/Subtract3'
       */
      rtb_inputVoltage_V = (CONST_ONE_F32 - rtb_KT) * rtb_Product4;
    }
  }

  /* End of Switch: '<S80>/Reset' */

  /* Update for UnitDelay: '<S24>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_p = RobotControl_B.leftPosPin;

  /* Update for UnitDelay: '<S24>/Unit_Delay6' */
  RobotControl_DW.Unit_Delay6_DSTATE = RobotControl_B.leftNegPin;

  /* Update for Delay: '<S59>/Delay' */
  RobotControl_DW.Delay_DSTATE_a[0] = RobotControl_DW.Delay_DSTATE_a[1];
  RobotControl_DW.Delay_DSTATE_a[1] = RobotControl_DW.Delay_DSTATE_a[2];
  RobotControl_DW.Delay_DSTATE_a[2] = RobotControl_DW.Delay_DSTATE_a[3];
  RobotControl_DW.Delay_DSTATE_a[3] = RobotControl_DW.Delay_DSTATE_a[4];
  RobotControl_DW.Delay_DSTATE_a[4] = RobotControl_B.motorDistance;

  /* Update for Delay: '<S59>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_e = rtb_Add5_b;

  /* Update for UnitDelay: '<S24>/Unit_Delay7' */
  RobotControl_DW.Unit_Delay7_DSTATE = RobotControl_B.rightPosPin;

  /* Update for UnitDelay: '<S24>/Unit_Delay8' */
  RobotControl_DW.Unit_Delay8_DSTATE = RobotControl_B.rightNegPin;

  /* Update for Delay: '<S60>/Delay' */
  RobotControl_DW.Delay_DSTATE_l[0] = RobotControl_DW.Delay_DSTATE_l[1];
  RobotControl_DW.Delay_DSTATE_l[1] = RobotControl_DW.Delay_DSTATE_l[2];
  RobotControl_DW.Delay_DSTATE_l[2] = RobotControl_DW.Delay_DSTATE_l[3];
  RobotControl_DW.Delay_DSTATE_l[3] = RobotControl_DW.Delay_DSTATE_l[4];
  RobotControl_DW.Delay_DSTATE_l[4] = rtb_motorDistance_f;

  /* Update for Delay: '<S60>/Delay1' */
  RobotControl_DW.Delay1_DSTATE_i = rtb_Add5_n;

  /* Update for DiscreteTransferFcn: '<S90>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states[1L] =
    RobotControl_DW.MotorTransferFunction_states[0L];
  RobotControl_DW.MotorTransferFunction_states[0L] = MotorTransferFunction_tmp;

  /* Update for UnitDelay: '<S89>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S89>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_l = 0U;

  /* Update for UnitDelay: '<S89>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_n = rtb_inputVoltage_V;

  /* Update for DiscreteTransferFcn: '<S81>/MotorTransferFunction' */
  RobotControl_DW.MotorTransferFunction_states_j[1L] =
    RobotControl_DW.MotorTransferFunction_states_j[0L];
  RobotControl_DW.MotorTransferFunction_states_j[0L] =
    MotorTransferFunction_tmp_b;

  /* Update for UnitDelay: '<S80>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S80>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_a = 0U;

  /* Update for UnitDelay: '<S80>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_b = rtb_Init_j;

  /* Update for UnitDelay: '<S24>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S24>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_m = rtb_Switch_l;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
