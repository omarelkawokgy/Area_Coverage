/*
 * File: RobotControl.c
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

#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S4>/Scheduler' */
#define RobotControl_CAL_APP_Ticks_Sec ((uint8_T)5U)
#define RobotControl_CAL_DIAG_Ticks_Sec ((uint8_T)50U)
#define RobotControl_IN_Scheduler      ((uint8_T)1U)

/* Block signals (auto storage) */
B_RobotControl_T RobotControl_B;

/* Block states (auto storage) */
DW_RobotControl_T RobotControl_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_RobotControl_T RobotControl_PrevZCX;

/* Real-time model */
RT_MODEL_RobotControl_T RobotControl_M_;
RT_MODEL_RobotControl_T *const RobotControl_M = &RobotControl_M_;

/*
 * Output and update for atomic system:
 *    '<S2>/Digital_OUT_PWM'
 *    '<S2>/Digital_OUT_PWM1'
 *    '<S2>/Digital_OUT_PWM2'
 *    '<S2>/Digital_OUT_PWM3'
 */
void RobotControl_Digital_OUT_PWM(uint8_T rtu_pin, uint8_T rtu_value)
{
  /* Gateway: OutputHandler/Digital_OUT_PWM */
  /* During: OutputHandler/Digital_OUT_PWM */
  /* Entry Internal: OutputHandler/Digital_OUT_PWM */
  /* Transition: '<S15>:2' */
  /* Transition: '<S15>:4' */
  digitalWrite(rtu_pin, rtu_value);
}

/*
 * Output and update for atomic system:
 *    '<S2>/Digital_OUT_bool'
 *    '<S2>/Digital_OUT_bool1'
 */
void RobotControl_Digital_OUT_bool(uint8_T rtu_pin, boolean_T rtu_value)
{
  /* Gateway: OutputHandler/Digital_OUT_bool */
  /* During: OutputHandler/Digital_OUT_bool */
  /* Entry Internal: OutputHandler/Digital_OUT_bool */
  /* Transition: '<S19>:2' */
  /* Transition: '<S19>:4' */
  digitalWrite(rtu_pin, rtu_value);
}

/* Model step function */
void RobotControl_step(void)
{
  /* Chart: '<S1>/Digital_IN_bool' incorporates:
   *  Constant: '<S1>/DigitalPin2'
   */
  /* Gateway: InputHandler/Digital_IN_bool */
  /* During: InputHandler/Digital_IN_bool */
  /* Entry Internal: InputHandler/Digital_IN_bool */
  /* Transition: '<S6>:2' */
  /* Transition: '<S6>:4' */
  RobotControl_B.value = (digitalRead(((uint8_T)PIN_D2)) != 0);

  /* Chart: '<S4>/Scheduler' */
  /* Gateway: Scheduler/Scheduler */
  if (RobotControl_DW.temporalCounter_i1_k < RobotControl_CAL_APP_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i1_k++;
  }

  if (RobotControl_DW.temporalCounter_i2_p < RobotControl_CAL_DIAG_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i2_p++;
  }

  /* During: Scheduler/Scheduler */
  /* scheduler for the SWCs */
  if (RobotControl_DW.is_active_c21_RobotControl == 0U) {
    /* Entry: Scheduler/Scheduler */
    RobotControl_DW.is_active_c21_RobotControl = 1U;

    /* Entry Internal: Scheduler/Scheduler */
    RobotControl_DW.is_c21_RobotControl = RobotControl_IN_Scheduler;
    RobotControl_DW.temporalCounter_i1_k = 0U;
    RobotControl_DW.temporalCounter_i2_p = 0U;
  } else {
    /* Outputs for Function Call SubSystem: '<S1>/EncoderAnalogIn' */

    /* During 'Scheduler': '<S153>:4' */
    /* every 1ms */
    /* Event: '<S153>:10' */
    RobotControl_EncoderAnalogIn();

    /* End of Outputs for SubSystem: '<S1>/EncoderAnalogIn' */

    /* Outputs for Function Call SubSystem: '<S1>/COM_A4SCA_A5SCL' */
    RobotControl_COM_A4SCA_A5SCL();

    /* End of Outputs for SubSystem: '<S1>/COM_A4SCA_A5SCL' */

    /* Outputs for Function Call SubSystem: '<S21>/DSCA' */
    RobotControl_DSCA();

    /* End of Outputs for SubSystem: '<S21>/DSCA' */

    /* Outputs for Function Call SubSystem: '<S22>/thetaFilter' */
    RobotControl_thetaFilter();

    /* End of Outputs for SubSystem: '<S22>/thetaFilter' */

    /* every 5ms */
    if (RobotControl_DW.temporalCounter_i1_k == RobotControl_CAL_APP_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S21>/HeadingsDirectionHandler' */

      /* Event: '<S153>:6' */
      RobotC_HeadingsDirectionHandler();

      /* End of Outputs for SubSystem: '<S21>/HeadingsDirectionHandler' */

      /* Outputs for Function Call SubSystem: '<S22>/HeadingCalculator' */
      RobotControl_HeadingCalculator();

      /* End of Outputs for SubSystem: '<S22>/HeadingCalculator' */

      /* Outputs for Function Call SubSystem: '<S1>/ULS_AnalogIn' */
      RobotControl_ULS_AnalogIn();

      /* End of Outputs for SubSystem: '<S1>/ULS_AnalogIn' */

      /* Outputs for Function Call SubSystem: '<S21>/ScanHandler' */
      RobotControl_ScanHandler();

      /* End of Outputs for SubSystem: '<S21>/ScanHandler' */

      /* Outputs for Function Call SubSystem: '<S21>/StopRoutine' */
      RobotControl_StopRoutine();

      /* End of Outputs for SubSystem: '<S21>/StopRoutine' */

      /* Outputs for Function Call SubSystem: '<S21>/MovementHandler' */
      RobotControl_MovementHandler();

      /* End of Outputs for SubSystem: '<S21>/MovementHandler' */

      /* Outputs for Function Call SubSystem: '<S21>/HighLevelRoutines' */
      RobotControl_HighLevelRoutines();

      /* End of Outputs for SubSystem: '<S21>/HighLevelRoutines' */

      /* Outputs for Function Call SubSystem: '<S21>/motorHandler' */
      RobotControl_motorHandler();

      /* End of Outputs for SubSystem: '<S21>/motorHandler' */
    }

    /* every 50ms */
    if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S21>/DIAG_Cont' */

      /* Event: '<S153>:8' */
      RobotControl_DIAG_Cont();

      /* End of Outputs for SubSystem: '<S21>/DIAG_Cont' */
    }
  }

  if (RobotControl_DW.temporalCounter_i1_k == RobotControl_CAL_APP_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i1_k = 0U;
  }

  if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i2_p = 0U;
  }

  /* End of Chart: '<S4>/Scheduler' */

  /* Chart: '<S2>/Digital_OUT_PWM' incorporates:
   *  Constant: '<S2>/PWMPin5'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)PIN_D5), RobotControl_B.leftPosPin);

  /* Chart: '<S2>/Digital_OUT_PWM1' incorporates:
   *  Constant: '<S2>/PWMPin6'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)PIN_D6), RobotControl_B.leftNegPin);

  /* Chart: '<S2>/Digital_OUT_PWM2' incorporates:
   *  Constant: '<S2>/PWMPin9'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)PIN_D9), RobotControl_B.rightPosPin);

  /* Chart: '<S2>/Digital_OUT_PWM3' incorporates:
   *  Constant: '<S2>/PWMPin10'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)PIN_D10), RobotControl_B.rightNegPin);

  /* Chart: '<S2>/Digital_OUT_bool' incorporates:
   *  Constant: '<S2>/DigitalPin3'
   */
  RobotControl_Digital_OUT_bool(((uint8_T)PIN_D3), RobotControl_B.redLED_BOOL);

  /* Chart: '<S2>/Digital_OUT_bool1' incorporates:
   *  Constant: '<S2>/DigitalPin11'
   */
  RobotControl_Digital_OUT_bool(((uint8_T)PIN_D11), RobotControl_B.greenLED_BOOL);
}

/* Model initialize function */
void RobotControl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(RobotControl_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &RobotControl_B), 0,
                sizeof(B_RobotControl_T));

  /* states (dwork) */
  (void) memset((void *)&RobotControl_DW, 0,
                sizeof(DW_RobotControl_T));

  /* Start for Chart: '<S4>/Scheduler' incorporates:
   *  Start for SubSystem: '<S21>/HighLevelRoutines'
   */
  RobotCo_HighLevelRoutines_Start();
  RobotControl_PrevZCX.Resettable_Delay_Reset_ZCE = POS_ZCSIG;
  RobotControl_PrevZCX.Resettable_Delay1_Reset_ZCE = POS_ZCSIG;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  RobotControl_PrevZCX.EncoderIncrement_i.EncoderIncrement_Trig_ZCE = POS_ZCSIG;
  RobotControl_PrevZCX.EncoderIncrement.EncoderIncrement_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<S1>/Digital_IN_bool' */
  RobotControl_B.value = false;
  RobotControl_DW.temporalCounter_i1_k = 0U;
  RobotControl_DW.temporalCounter_i2_p = 0U;
  RobotControl_DW.is_active_c21_RobotControl = 0U;
  RobotControl_DW.is_c21_RobotControl = 0U;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/EncoderAnalogIn'
   */
  RobotContr_EncoderAnalogIn_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/COM_A4SCA_A5SCL'
   */
  RobotContr_COM_A4SCA_A5SCL_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/DSCA'
   */
  RobotControl_DSCA_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/thetaFilter'
   */
  RobotControl_thetaFilter_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/HeadingsDirectionHandler'
   */
  R_HeadingsDirectionHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/HeadingCalculator'
   */
  RobotCon_HeadingCalculator_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/ULS_AnalogIn'
   */
  RobotControl_ULS_AnalogIn_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/StopRoutine'
   */
  RobotControl_StopRoutine_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/MovementHandler'
   */
  RobotContr_MovementHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/HighLevelRoutines'
   */
  RobotCon_HighLevelRoutines_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/motorHandler'
   */
  RobotControl_motorHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S21>/DIAG_Cont'
   */
  RobotControl_DIAG_Cont_Init();
}

/* Model terminate function */
void RobotControl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
