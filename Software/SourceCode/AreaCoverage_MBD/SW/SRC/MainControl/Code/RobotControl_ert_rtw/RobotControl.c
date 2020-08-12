/*
 * File: RobotControl.c
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

#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S7>/EEPROM_IO_Handler_Chart' */
#define RobotControl_IN_ReadEEPROM     ((uint8_T)1U)
#define RobotControl_IN_UpdateEEPROM   ((uint8_T)2U)

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
  /* Transition: '<S16>:2' */
  /* Transition: '<S16>:4' */
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
  /* Transition: '<S20>:2' */
  /* Transition: '<S20>:4' */
  digitalWrite(rtu_pin, rtu_value);
}

/* Model step function */
void RobotControl_step(void)
{
  /* Chart: '<S1>/Digital_IN_bool' incorporates:
   *  Constant: '<S1>/DigitalPin2'
   */
  RobotControl_Digital_IN_bool(((uint8_T)PIN_D2));

  /* UnitDelay: '<S2>/Unit Delay' */
  RobotControl_B.UnitDelay = RobotControl_DW.UnitDelay_DSTATE_p;

  /* UnitDelay: '<S2>/Unit Delay1' */
  RobotControl_B.UnitDelay1 = RobotControl_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay2' */
  RobotControl_B.UnitDelay2 = RobotControl_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay3' */
  RobotControl_B.UnitDelay3 = RobotControl_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay4' */
  RobotControl_B.UnitDelay4 = RobotControl_DW.UnitDelay4_DSTATE;

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

    /* During 'Scheduler': '<S154>:4' */
    /* every 1ms */
    /* Event: '<S154>:10' */
    RobotControl_EncoderAnalogIn();

    /* End of Outputs for SubSystem: '<S1>/EncoderAnalogIn' */

    /* Outputs for Function Call SubSystem: '<S1>/COM_A4SCA_A5SCL' */
    RobotControl_COM_A4SCA_A5SCL();

    /* End of Outputs for SubSystem: '<S1>/COM_A4SCA_A5SCL' */

    /* Outputs for Function Call SubSystem: '<S22>/DSCA' */
    RobotControl_DSCA();

    /* End of Outputs for SubSystem: '<S22>/DSCA' */

    /* Outputs for Function Call SubSystem: '<S23>/thetaFilter' */
    RobotControl_thetaFilter();

    /* End of Outputs for SubSystem: '<S23>/thetaFilter' */

    /* every 5ms */
    if (RobotControl_DW.temporalCounter_i1_k == RobotControl_CAL_APP_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S22>/HeadingsDirectionHandler' */

      /* Event: '<S154>:6' */
      RobotC_HeadingsDirectionHandler();

      /* End of Outputs for SubSystem: '<S22>/HeadingsDirectionHandler' */

      /* Outputs for Function Call SubSystem: '<S23>/HeadingCalculator' */
      RobotControl_HeadingCalculator();

      /* End of Outputs for SubSystem: '<S23>/HeadingCalculator' */

      /* Outputs for Function Call SubSystem: '<S1>/ULS_AnalogIn' */
      /* Chart: '<S9>/ULSL_D8R_D7L_Chart' incorporates:
       *  Constant: '<S9>/DigitalPin7'
       */
      /* Gateway: InputHandler/ULS_AnalogIn/ULSL_D8R_D7L_Chart */
      /* During: InputHandler/ULS_AnalogIn/ULSL_D8R_D7L_Chart */
      /* Entry Internal: InputHandler/ULS_AnalogIn/ULSL_D8R_D7L_Chart */
      /* Transition: '<S14>:2' */
      /* Transition: '<S14>:4' */
      ULSL_Hndler_Outputs_wrapper(((uint8_T)PIN_D7), &RobotControl_B.ULSL_cm);

      /* Chart: '<S9>/ULSR_D8R_D7L_Chart' incorporates:
       *  Constant: '<S9>/DigitalPin8'
       */
      /* Gateway: InputHandler/ULS_AnalogIn/ULSR_D8R_D7L_Chart */
      /* During: InputHandler/ULS_AnalogIn/ULSR_D8R_D7L_Chart */
      /* Entry Internal: InputHandler/ULS_AnalogIn/ULSR_D8R_D7L_Chart */
      /* Transition: '<S15>:2' */
      /* Transition: '<S15>:4' */
      ULSR_Hndler_Outputs_wrapper(((uint8_T)PIN_D8), &RobotControl_B.ULSR_cm);

      /* End of Outputs for SubSystem: '<S1>/ULS_AnalogIn' */

      /* Outputs for Function Call SubSystem: '<S22>/ScanHandler' */
      RobotControl_ScanHandler();

      /* End of Outputs for SubSystem: '<S22>/ScanHandler' */

      /* Outputs for Function Call SubSystem: '<S22>/StopRoutine' */
      RobotControl_StopRoutine();

      /* End of Outputs for SubSystem: '<S22>/StopRoutine' */

      /* Outputs for Function Call SubSystem: '<S22>/MovementHandler' */
      RobotControl_MovementHandler();

      /* End of Outputs for SubSystem: '<S22>/MovementHandler' */

      /* Outputs for Function Call SubSystem: '<S22>/HighLevelRoutines' */
      RobotControl_HighLevelRoutines();

      /* End of Outputs for SubSystem: '<S22>/HighLevelRoutines' */

      /* Outputs for Function Call SubSystem: '<S22>/motorHandler' */
      RobotControl_motorHandler();

      /* End of Outputs for SubSystem: '<S22>/motorHandler' */

      /* Outputs for Function Call SubSystem: '<S1>/EEPROM_IO_Handler' */
      /* Chart: '<S7>/EEPROM_IO_Handler_Chart' */
      /* Gateway: InputHandler/EEPROM_IO_Handler/EEPROM_IO_Handler_Chart */
      /* During: InputHandler/EEPROM_IO_Handler/EEPROM_IO_Handler_Chart */
      if (RobotControl_DW.is_active_c13_RobotControl == 0U) {
        /* Entry: InputHandler/EEPROM_IO_Handler/EEPROM_IO_Handler_Chart */
        RobotControl_DW.is_active_c13_RobotControl = 1U;

        /* Entry Internal: InputHandler/EEPROM_IO_Handler/EEPROM_IO_Handler_Chart */
        /* Transition: '<S11>:2' */
        RobotControl_DW.is_c13_RobotControl = RobotControl_IN_ReadEEPROM;

        /* Entry 'ReadEEPROM': '<S11>:1' */
        EEPROM_Read_Wrapper(&RobotControl_B.NVM_AngleStoreFlg,
                            &RobotControl_B.NVM_NORTH, &RobotControl_B.NVM_SOUTH,
                            &RobotControl_B.NVM_EAST, &RobotControl_B.NVM_WEST);
      } else if (RobotControl_DW.is_c13_RobotControl ==
                 RobotControl_IN_ReadEEPROM) {
        /* During 'ReadEEPROM': '<S11>:1' */
        if (RobotControl_B.UnitDelay4 == ((uint8_T)ENU_FINISHED)) {
          /* Transition: '<S11>:6' */
          RobotControl_DW.is_c13_RobotControl = RobotControl_IN_UpdateEEPROM;

          /* Entry 'UpdateEEPROM': '<S11>:5' */
          EEPROM_Update_Wrapper(RobotControl_B.UnitDelay,
                                RobotControl_B.UnitDelay1,
                                RobotControl_B.UnitDelay2,
                                RobotControl_B.UnitDelay3);
        }
      } else {
        /* During 'UpdateEEPROM': '<S11>:5' */
        /* Transition: '<S11>:7' */
        RobotControl_DW.is_c13_RobotControl = RobotControl_IN_ReadEEPROM;

        /* Entry 'ReadEEPROM': '<S11>:1' */
        EEPROM_Read_Wrapper(&RobotControl_B.NVM_AngleStoreFlg,
                            &RobotControl_B.NVM_NORTH, &RobotControl_B.NVM_SOUTH,
                            &RobotControl_B.NVM_EAST, &RobotControl_B.NVM_WEST);
      }

      /* End of Chart: '<S7>/EEPROM_IO_Handler_Chart' */

      /* DataTypeConversion: '<S7>/Data Type Conversion' */
      RobotControl_B.DataTypeConversion_p = (int16_T)RobotControl_B.NVM_NORTH;

      /* DataTypeConversion: '<S7>/Data Type Conversion1' */
      RobotControl_B.DataTypeConversion1_b = (int16_T)RobotControl_B.NVM_SOUTH;

      /* DataTypeConversion: '<S7>/Data Type Conversion2' */
      RobotControl_B.DataTypeConversion2_g = (int16_T)RobotControl_B.NVM_EAST;

      /* DataTypeConversion: '<S7>/Data Type Conversion3' */
      RobotControl_B.DataTypeConversion3_j = (int16_T)RobotControl_B.NVM_WEST;

      /* End of Outputs for SubSystem: '<S1>/EEPROM_IO_Handler' */
    }

    /* every 50ms */
    if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S22>/DIAG_Cont' */

      /* Event: '<S154>:8' */
      RobotControl_DIAG_Cont();

      /* End of Outputs for SubSystem: '<S22>/DIAG_Cont' */
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

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_p =
    RobotControl_B.OutportBufferForangleCalib_NORT;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  RobotControl_DW.UnitDelay1_DSTATE =
    RobotControl_B.OutportBufferForangleCalib_SOUT;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  RobotControl_DW.UnitDelay2_DSTATE =
    RobotControl_B.OutportBufferForangleCalib_EAST;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  RobotControl_DW.UnitDelay3_DSTATE =
    RobotControl_B.OutportBufferForangleCalib_WEST;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  RobotControl_DW.UnitDelay4_DSTATE =
    RobotControl_B.OutportBufferForangleCalibStatu;
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
   *  Start for SubSystem: '<S22>/HighLevelRoutines'
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
  RobotContr_Digital_IN_bool_Init();
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
   *  SystemInitialize for SubSystem: '<S22>/DSCA'
   */
  RobotControl_DSCA_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S23>/thetaFilter'
   */
  RobotControl_thetaFilter_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/HeadingsDirectionHandler'
   */
  R_HeadingsDirectionHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S23>/HeadingCalculator'
   */
  RobotCon_HeadingCalculator_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/ULS_AnalogIn'
   */
  /* SystemInitialize for Chart: '<S9>/ULSL_D8R_D7L_Chart' */
  RobotControl_B.ULSL_cm = 0U;

  /* SystemInitialize for Chart: '<S9>/ULSR_D8R_D7L_Chart' */
  RobotControl_B.ULSR_cm = 0U;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/StopRoutine'
   */
  RobotControl_StopRoutine_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/MovementHandler'
   */
  RobotContr_MovementHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/HighLevelRoutines'
   */
  RobotCon_HighLevelRoutines_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/motorHandler'
   */
  RobotControl_motorHandler_Init();

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/EEPROM_IO_Handler'
   */
  /* SystemInitialize for Chart: '<S7>/EEPROM_IO_Handler_Chart' */
  RobotControl_DW.is_active_c13_RobotControl = 0U;
  RobotControl_DW.is_c13_RobotControl = 0U;
  RobotControl_B.NVM_AngleStoreFlg = false;
  RobotControl_B.NVM_NORTH = 0U;
  RobotControl_B.NVM_SOUTH = 0U;
  RobotControl_B.NVM_EAST = 0U;
  RobotControl_B.NVM_WEST = 0U;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/DIAG_Cont'
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
