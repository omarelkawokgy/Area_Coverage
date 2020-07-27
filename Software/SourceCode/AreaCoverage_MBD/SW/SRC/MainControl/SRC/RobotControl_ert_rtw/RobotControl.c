/*
 * RobotControl.c
 *
 * Code generation for model "RobotControl".
 *
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
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
  if (!(RobotControl_DW.obj.SampleTime == -1.0)) {
    RobotControl_B.p_m = false;
  }

  if (RobotControl_B.p_m) {
    RobotControl_B.p = true;
  }

  if (!RobotControl_B.p) {
    RobotControl_DW.obj.SampleTime = -1.0;
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
  MW_analogWrite(5UL, RobotControl_B.leftPosPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_analogWrite(6UL, RobotControl_B.leftNegPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
  MW_analogWrite(9UL, RobotControl_B.rightPosPin);

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(10UL, RobotControl_B.rightNegPin);

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

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RobotControl_M->Timing.clockTick0)) {
    ++RobotControl_M->Timing.clockTickH0;
  }

  RobotControl_M->Timing.t[0] = RobotControl_M->Timing.clockTick0 *
    RobotControl_M->Timing.stepSize0 + RobotControl_M->Timing.clockTickH0 *
    RobotControl_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void RobotControl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RobotControl_M, 0,
                sizeof(RT_MODEL_RobotControl_T));
  rtsiSetSolverName(&RobotControl_M->solverInfo,"FixedStepDiscrete");
  RobotControl_M->solverInfoPtr = (&RobotControl_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RobotControl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    RobotControl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RobotControl_M->Timing.sampleTimes =
      (&RobotControl_M->Timing.sampleTimesArray[0]);
    RobotControl_M->Timing.offsetTimes =
      (&RobotControl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RobotControl_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    RobotControl_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(RobotControl_M, &RobotControl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RobotControl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    RobotControl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RobotControl_M, -1);
  RobotControl_M->Timing.stepSize0 = 0.001;
  RobotControl_M->solverInfoPtr = (&RobotControl_M->solverInfo);
  RobotControl_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&RobotControl_M->solverInfo, 0.001);
  rtsiSetSolverMode(&RobotControl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &RobotControl_B), 0,
                sizeof(B_RobotControl_T));

  /* states (dwork) */
  (void) memset((void *)&RobotControl_DW, 0,
                sizeof(DW_RobotControl_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &RobotControl_M->NonInlinedSFcns.sfcnInfo;
    RobotControl_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RobotControl_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RobotControl_M->Sizes.numSampTimes);
    RobotControl_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (RobotControl_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,RobotControl_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RobotControl_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RobotControl_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(RobotControl_M));
    rtssSetStepSizePtr(sfcnInfo, &RobotControl_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RobotControl_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RobotControl_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &RobotControl_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &RobotControl_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &RobotControl_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &RobotControl_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RobotControl_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RobotControl_M->solverInfoPtr);
  }

  RobotControl_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&RobotControl_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    RobotControl_M->childSfunctions =
      (&RobotControl_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    RobotControl_M->childSfunctions[0] =
      (&RobotControl_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: RobotControl/<S5>/COM_A4SCA_A5SCL (CompassSFunc) */
    {
      SimStruct *rts = RobotControl_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = RobotControl_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RobotControl_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RobotControl_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RobotControl_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, RobotControl_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RobotControl_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RobotControl_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RobotControl_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RobotControl_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &RobotControl_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RobotControl_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int16_T *)
            &RobotControl_B.COM_A4SCA_A5SCL));
        }
      }

      /* path info */
      ssSetModelName(rts, "COM_A4SCA_A5SCL");
      ssSetPath(rts, "RobotControl/InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL");
      ssSetRTModel(rts,RobotControl_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      CompassSFunc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Start for MATLABSystem: '<S6>/Digital Input' */
  RobotControl_DW.obj.isInitialized = 0L;
  RobotControl_DW.objisempty_c = true;
  RobotControl_DW.obj.SampleTime = -1.0;
  RobotControl_DW.obj.isInitialized = 1L;
  digitalIOSetup((uint8_T)RobotControl_PinNumber, false);

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
  MW_pinModeOutput(5UL);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_pinModeOutput(6UL);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
  MW_pinModeOutput(9UL);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_pinModeOutput(10UL);

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

  /* Terminate for Chart: '<S4>/Scheduler' incorporates:
   *  Terminate for SubSystem: '<S1>/COM_A4SCA_A5SCL'
   */
  RobotContr_COM_A4SCA_A5SCL_Term();

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
