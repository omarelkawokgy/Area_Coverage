/*
 * RobotControl.c
 *
 * Code generation for model "RobotControl".
 *
 * Model version              : 1.503
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 29 10:39:32 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S4>/Scheduler' */
#define RobotContr_IN_NO_ACTIVE_CHILD_f ((uint8_T)0U)
#define RobotControl_CAL_APP_Ticks_Sec ((uint8_T)5U)
#define RobotControl_CAL_DIAG_Ticks_Sec ((uint8_T)50U)
#define RobotControl_IN_Scheduler      ((uint8_T)1U)
#define RobotControl_PinNumber         (2.0)
#define RobotControl_PinNumber_i       (3.0)
#define RobotControl_PinNumber_iz      (11.0)

/* Block signals (auto storage) */
B_RobotControl_T RobotControl_B;

/* Block states (auto storage) */
DW_RobotControl_T RobotControl_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_RobotControl_T RobotControl_PrevZCX;

/* Real-time model */
RT_MODEL_RobotControl_T RobotControl_M_;
RT_MODEL_RobotControl_T *const RobotControl_M = &RobotControl_M_;

/* Model step function */
void RobotControl_step(void)
{
  /* Start for MATLABSystem: '<S6>/Digital Input' incorporates:
   *  MATLABSystem: '<S6>/Digital Input'
   */
  RobotControl_B.p = false;
  RobotControl_B.p_m = true;
  if (!(RobotControl_DW.obj.SampleTime == RobotControl_P.DigitalInput_SampleTime))
  {
    RobotControl_B.p_m = false;
  }

  if (RobotControl_B.p_m) {
    RobotControl_B.p = true;
  }

  if (!RobotControl_B.p) {
    if (((!rtIsInf(RobotControl_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (RobotControl_P.DigitalInput_SampleTime))) || rtIsInf
        (RobotControl_P.DigitalInput_SampleTime)) {
      RobotControl_B.sampleTime = RobotControl_P.DigitalInput_SampleTime;
    }

    RobotControl_DW.obj.SampleTime = RobotControl_B.sampleTime;
  }

  /* MATLABSystem: '<S6>/Digital Input' incorporates:
   *  Start for MATLABSystem: '<S6>/Digital Input'
   */
  RobotControl_B.DigitalInput = readDigitalPin((uint8_T)RobotControl_PinNumber);

  /* Chart: '<S4>/Scheduler' */
  /* Gateway: Scheduler/Scheduler */
  if (RobotControl_DW.temporalCounter_i1_k < RobotControl_CAL_APP_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i1_k++;
  }

  if (RobotControl_DW.temporalCounter_i2_p < RobotControl_CAL_DIAG_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i2_p++;
  }

  /* During: Scheduler/Scheduler */
  if (RobotControl_DW.is_active_c21_RobotControl == 0U) {
    /* Entry: Scheduler/Scheduler */
    RobotControl_DW.is_active_c21_RobotControl = 1U;

    /* Entry Internal: Scheduler/Scheduler */
    RobotControl_DW.is_c21_RobotControl = RobotControl_IN_Scheduler;
    RobotControl_DW.temporalCounter_i1_k = 0U;
    RobotControl_DW.temporalCounter_i2_p = 0U;
  } else {
    /* Outputs for Function Call SubSystem: '<S17>/thetaFilter' */

    /* During 'Scheduler': '<S148>:4' */
    /* every 1ms */
    /* Event: '<S148>:10' */
    RobotControl_thetaFilter();

    /* End of Outputs for SubSystem: '<S17>/thetaFilter' */

    /* Outputs for Function Call SubSystem: '<S1>/EncoderAnalogIn' */
    RobotControl_EncoderAnalogIn();

    /* End of Outputs for SubSystem: '<S1>/EncoderAnalogIn' */

    /* Outputs for Function Call SubSystem: '<S16>/DSCA' */
    RobotControl_DSCA();

    /* End of Outputs for SubSystem: '<S16>/DSCA' */

    /* every 5ms */
    if (RobotControl_DW.temporalCounter_i1_k == RobotControl_CAL_APP_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S16>/HeadingsDirectionHandler' */

      /* Event: '<S148>:6' */
      RobotC_HeadingsDirectionHandler();

      /* End of Outputs for SubSystem: '<S16>/HeadingsDirectionHandler' */

      /* Outputs for Function Call SubSystem: '<S1>/COM_A4SCA_A5SCL' */
      RobotControl_COM_A4SCA_A5SCL();

      /* End of Outputs for SubSystem: '<S1>/COM_A4SCA_A5SCL' */

      /* Outputs for Function Call SubSystem: '<S17>/HeadingCalculator' */
      RobotControl_HeadingCalculator();

      /* End of Outputs for SubSystem: '<S17>/HeadingCalculator' */

      /* Outputs for Function Call SubSystem: '<S1>/ULS_AnalogIn' */
      RobotControl_ULS_AnalogIn();

      /* End of Outputs for SubSystem: '<S1>/ULS_AnalogIn' */

      /* Outputs for Function Call SubSystem: '<S16>/ScanHandler' */
      RobotControl_ScanHandler();

      /* End of Outputs for SubSystem: '<S16>/ScanHandler' */

      /* Outputs for Function Call SubSystem: '<S16>/StopRoutine' */
      RobotControl_StopRoutine();

      /* End of Outputs for SubSystem: '<S16>/StopRoutine' */

      /* Outputs for Function Call SubSystem: '<S16>/MovementHandler' */
      RobotControl_MovementHandler();

      /* End of Outputs for SubSystem: '<S16>/MovementHandler' */

      /* Outputs for Function Call SubSystem: '<S16>/HighLevelRoutines' */
      RobotControl_HighLevelRoutines();

      /* End of Outputs for SubSystem: '<S16>/HighLevelRoutines' */

      /* Outputs for Function Call SubSystem: '<S16>/motorHandler' */
      RobotControl_motorHandler();

      /* End of Outputs for SubSystem: '<S16>/motorHandler' */
    }

    /* every 50ms */
    if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S16>/DIAG_Cont' */

      /* Event: '<S148>:8' */
      RobotControl_DIAG_Cont();

      /* End of Outputs for SubSystem: '<S16>/DIAG_Cont' */
    }
  }

  if (RobotControl_DW.temporalCounter_i1_k == RobotControl_CAL_APP_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i1_k = 0U;
  }

  if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec) {
    RobotControl_DW.temporalCounter_i2_p = 0U;
  }

  /* End of Chart: '<S4>/Scheduler' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_analogWrite(RobotControl_P.PWM_pinNumber, RobotControl_B.leftPosPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_analogWrite(RobotControl_P.PWM_pinNumber_b, RobotControl_B.leftNegPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
  MW_analogWrite(RobotControl_P.PWM_pinNumber_d, RobotControl_B.rightPosPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(RobotControl_P.PWM_pinNumber_bq, RobotControl_B.rightNegPin);

  /* Start for MATLABSystem: '<S10>/Digital Output' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  MATLABSystem: '<S10>/Digital Output'
   */
  writeDigitalPin((uint8_T)RobotControl_PinNumber_i, (uint8_T)
                  RobotControl_B.redLED_BOOL);

  /* Start for MATLABSystem: '<S11>/Digital Output' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   *  MATLABSystem: '<S11>/Digital Output'
   */
  writeDigitalPin((uint8_T)RobotControl_PinNumber_iz, (uint8_T)
                  RobotControl_B.greenLED_BOOL);
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

  {
    real_T sampleTime;

    /* Start for MATLABSystem: '<S6>/Digital Input' */
    RobotControl_DW.obj.isInitialized = 0L;
    RobotControl_DW.objisempty_c = true;
    if (((!rtIsInf(RobotControl_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (RobotControl_P.DigitalInput_SampleTime))) || rtIsInf
        (RobotControl_P.DigitalInput_SampleTime)) {
      sampleTime = RobotControl_P.DigitalInput_SampleTime;
    }

    RobotControl_DW.obj.SampleTime = sampleTime;
    RobotControl_DW.obj.isInitialized = 1L;
    digitalIOSetup((uint8_T)RobotControl_PinNumber, false);

    /* End of Start for MATLABSystem: '<S6>/Digital Input' */

    /* Start for Chart: '<S4>/Scheduler' incorporates:
     *  Start for SubSystem: '<S1>/EncoderAnalogIn'
     */
    RobotCont_EncoderAnalogIn_Start();

    /* Start for Chart: '<S4>/Scheduler' incorporates:
     *  Start for SubSystem: '<S16>/DSCA'
     */
    RobotControl_DSCA_Start();

    /* Start for Chart: '<S4>/Scheduler' incorporates:
     *  Start for SubSystem: '<S16>/HighLevelRoutines'
     */
    RobotCo_HighLevelRoutines_Start();

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
    MW_pinModeOutput(RobotControl_P.PWM_pinNumber);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
    MW_pinModeOutput(RobotControl_P.PWM_pinNumber_b);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
    MW_pinModeOutput(RobotControl_P.PWM_pinNumber_d);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
    MW_pinModeOutput(RobotControl_P.PWM_pinNumber_bq);

    /* Start for MATLABSystem: '<S10>/Digital Output' */
    RobotControl_DW.obj_e.isInitialized = 0L;
    RobotControl_DW.objisempty_i = true;
    RobotControl_DW.obj_e.isInitialized = 1L;
    digitalIOSetup((uint8_T)RobotControl_PinNumber_i, true);

    /* Start for MATLABSystem: '<S11>/Digital Output' */
    RobotControl_DW.obj_n.isInitialized = 0L;
    RobotControl_DW.objisempty = true;
    RobotControl_DW.obj_n.isInitialized = 1L;
    digitalIOSetup((uint8_T)RobotControl_PinNumber_iz, true);
  }

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
  RobotControl_DW.temporalCounter_i1_k = 0U;
  RobotControl_DW.temporalCounter_i2_p = 0U;
  RobotControl_DW.is_active_c21_RobotControl = 0U;
  RobotControl_DW.is_c21_RobotControl = RobotContr_IN_NO_ACTIVE_CHILD_f;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S17>/thetaFilter'
   */
  RobotControl_thetaFilter_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/EncoderAnalogIn'
   */
  RobotContr_EncoderAnalogIn_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/DSCA'
   */
  RobotControl_DSCA_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/HeadingsDirectionHandler'
   */
  R_HeadingsDirectionHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/COM_A4SCA_A5SCL'
   */
  RobotContr_COM_A4SCA_A5SCL_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S17>/HeadingCalculator'
   */
  RobotCon_HeadingCalculator_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/ULS_AnalogIn'
   */
  RobotControl_ULS_AnalogIn_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/ScanHandler'
   */
  RobotControl_ScanHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/StopRoutine'
   */
  RobotControl_StopRoutine_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/MovementHandler'
   */
  RobotContr_MovementHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/HighLevelRoutines'
   */
  RobotCon_HighLevelRoutines_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/motorHandler'
   */
  RobotControl_motorHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S16>/DIAG_Cont'
   */
  RobotControl_DIAG_Cont_Init();
}

/* Model terminate function */
void RobotControl_terminate(void)
{
  /* Start for MATLABSystem: '<S6>/Digital Input' incorporates:
   *  Terminate for MATLABSystem: '<S6>/Digital Input'
   */
  if (RobotControl_DW.obj.isInitialized == 1L) {
    RobotControl_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S6>/Digital Input' */

  /* Start for MATLABSystem: '<S10>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S10>/Digital Output'
   */
  if (RobotControl_DW.obj_e.isInitialized == 1L) {
    RobotControl_DW.obj_e.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S10>/Digital Output' */

  /* Start for MATLABSystem: '<S11>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S11>/Digital Output'
   */
  if (RobotControl_DW.obj_n.isInitialized == 1L) {
    RobotControl_DW.obj_n.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S11>/Digital Output' */
}
