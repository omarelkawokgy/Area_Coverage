/*
 * File: RobotControl.c
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

#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S7>/EEPROM_IO_Handler_Chart' */
#define RobotContr_IN_NO_ACTIVE_CHILD_g ((uint8_T)0U)
#define RobotControl_IN_ReadEEPROM     ((uint8_T)1U)
#define RobotControl_IN_UpdateEEPROM   ((uint8_T)2U)

/* Named constants for Chart: '<S4>/Scheduler' */
#define RobotControl_CAL_APP_Ticks_Sec ((uint8_T)5U)
#define RobotControl_CAL_DIAG_Ticks_Sec ((uint8_T)50U)
#define RobotControl_IN_Scheduler      ((uint8_T)1U)

/* Exported block states */
#if debuggingFlag_variant

boolean_T leftEncoderDistErrorFlg;     /* Simulink.Signal object 'leftEncoderDistErrorFlg' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T rightEncoderDistErrorFlg;    /* Simulink.Signal object 'rightEncoderDistErrorFlg' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T ULSR_NotConnectedFlag_BOOL;  /* Simulink.Signal object 'ULSR_NotConnectedFlag_BOOL' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T ULSL_NotConnectedFlag_BOOL;  /* Simulink.Signal object 'ULSL_NotConnectedFlag_BOOL' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T rightMotorFaultFlag;         /* Simulink.Signal object 'rightMotorFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T compFaultFlag;               /* Simulink.Signal object 'compFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T leftMotorFaultFlag;          /* Simulink.Signal object 'leftMotorFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

boolean_T stuckHitFlg;                 /* Simulink.Signal object 'stuckHitFlg' */

#endif                                 /* debuggingFlag_variant */

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
  RobotControl_Digital_IN_bool(((uint8_T)CONST_PIN_D2));

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

    /* During 'Scheduler': '<S166>:4' */
    /* every 1ms */
    /* Event: '<S166>:10' */
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

      /* Event: '<S166>:6' */
      RobotC_HeadingsDirectionHandler();

      /* End of Outputs for SubSystem: '<S22>/HeadingsDirectionHandler' */

      /* Outputs for Function Call SubSystem: '<S23>/HeadingCalculator' */
      RobotControl_HeadingCalculator();

      /* End of Outputs for SubSystem: '<S23>/HeadingCalculator' */

      /* Outputs for Function Call SubSystem: '<S1>/ULS_AnalogIn' */
      RobotControl_ULS_AnalogIn();

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
      /* Abs: '<S31>/Abs' */
      RobotControl_B.Abs_g = (real32_T)fabs(RobotControl_B.thetaError);

      /* Logic: '<S31>/Logical Operator' incorporates:
       *  Constant: '<S31>/ENU_FORWARD'
       *  Constant: '<S31>/ENU_FORWARD1'
       *  RelationalOperator: '<S31>/Relational_Operator'
       *  RelationalOperator: '<S31>/Relational_Operator1'
       */
      RobotControl_B.Relational_Operator_b =
        ((RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_FORWARD)) ||
         (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_BACKWARD)));

      /* Logic: '<S31>/Logical_Operator' */
      RobotControl_B.Logical_Operator_o = !RobotControl_B.Relational_Operator_b;

      /* Switch: '<S165>/Init' incorporates:
       *  Constant: '<S165>/Initial Condition'
       *  Logic: '<S165>/FixPt Logical Operator'
       *  UnitDelay: '<S165>/FixPt Unit Delay1'
       *  UnitDelay: '<S165>/FixPt Unit Delay2'
       */
      if (RobotControl_B.Logical_Operator_o ||
          (RobotControl_DW.FixPtUnitDelay2_DSTATE != 0)) {
        RobotControl_B.Switch_c = 0.001F;
      } else {
        RobotControl_B.Switch_c = RobotControl_DW.FixPtUnitDelay1_DSTATE;
      }

      /* End of Switch: '<S165>/Init' */

      /* Sum: '<S31>/Add' incorporates:
       *  Constant: '<S31>/CAL_forwardStartIncr'
       */
      RobotControl_B.Add_a5 = (CAL_forwardStartIncr + RobotControl_B.Abs_g) +
        RobotControl_B.Switch_c;

      /* Product: '<S31>/Divide' incorporates:
       *  Constant: '<S31>/CAL_MOTOR_HIGH'
       *  Constant: '<S31>/CAL_MOTOR_HIGH1'
       *  Product: '<S31>/Divide1'
       */
#if motorsHandleEOL_Variant

      RobotControl_B.VariantMerge_For_Variant_So =
        RobotControl_B.VariantMergeForOutportleft_EOL_ / (real32_T)((uint8_T)
        CAL_MOTOR_HIGH);
      RobotControl_B.VariantMerge_For_Variant__i =
        RobotControl_B.VariantMergeForOutportright_EOL / (real32_T)((uint8_T)
        CAL_MOTOR_HIGH);

#endif                                 /* motorsHandleEOL_Variant */

      /* End of Product: '<S31>/Divide' */

      /* Switch: '<S31>/Switch' incorporates:
       *  Saturate: '<S31>/Saturation1'
       */
#if MotorsEOL_DisabledVariant

      if (RobotControl_B.Relational_Operator_b) {
        /* Saturate: '<S31>/Saturation' */
#if MotorsEOL_DisabledVariant

        if (RobotControl_B.Add_a5 > CAL_ErrorUpperLimit) {
          RobotControl_B.Saturation1 = CAL_ErrorUpperLimit;
        } else if (RobotControl_B.Add_a5 < 0.0F) {
          RobotControl_B.Saturation1 = 0.0F;
        } else {
          RobotControl_B.Saturation1 = RobotControl_B.Add_a5;
        }

#endif                                 /* MotorsEOL_DisabledVariant */

        /* End of Saturate: '<S31>/Saturation' */
        RobotControl_B.Switch_c = RobotControl_B.Saturation1;
      } else {

#if MotorsEOL_DisabledVariant

        /* Saturate: '<S31>/Saturation1' */
        if (RobotControl_B.Abs_g > CAL_ErrorUpperLimit) {
          RobotControl_B.Saturation1 = CAL_ErrorUpperLimit;
        } else if (RobotControl_B.Abs_g < CAL_ErrorLowerLimit) {
          RobotControl_B.Saturation1 = CAL_ErrorLowerLimit;
        } else {
          RobotControl_B.Saturation1 = RobotControl_B.Abs_g;
        }

#endif                                 /* MotorsEOL_DisabledVariant */

        RobotControl_B.Switch_c = RobotControl_B.Saturation1;
      }

#endif                                 /* MotorsEOL_DisabledVariant */

      /* End of Switch: '<S31>/Switch' */

      /* SignalConversion: '<S31>/TmpVariantMergeBufferAtVariantMerge_For_Variant_Source_Variant_Source4Inport2' */
#if MotorsEOL_DisabledVariant

      RobotControl_B.VariantMerge_For_Variant_So = RobotControl_B.Switch_c;

#endif                                 /* MotorsEOL_DisabledVariant */

      /* End of SignalConversion: '<S31>/TmpVariantMergeBufferAtVariantMerge_For_Variant_Source_Variant_Source4Inport2' */

      /* Product: '<S163>/Product' incorporates:
       *  Constant: '<S163>/CAL_MOTOR_HIGH'
       */
      RobotControl_B.Product = (uint8_T)
        (RobotControl_B.VariantMerge_For_Variant_So * (real32_T)((uint8_T)
          CAL_MOTOR_HIGH));

      /* Switch: '<S163>/Switch' incorporates:
       *  Constant: '<S163>/CAL_MOTOR_LOW1'
       *  Constant: '<S163>/ENU_BACKWARD'
       *  Constant: '<S163>/ENU_FORWARD'
       *  Constant: '<S163>/ENU_STOP'
       *  RelationalOperator: '<S163>/Relational_Operator'
       *  RelationalOperator: '<S163>/Relational_Operator1'
       *  RelationalOperator: '<S163>/Relational_Operator2'
       *  Switch: '<S163>/Switch'
       *  Switch: '<S163>/Switch1'
       *  Switch: '<S163>/Switch2'
       */
      if (RobotControl_B.VariantMerge_For_Variant_Source == ((uint8_T)
           ENU_BACKWARD)) {
        RobotControl_B.leftPosPin = ((uint8_T)CAL_MOTOR_LOW);
        RobotControl_B.leftNegPin = RobotControl_B.Product;
      } else if (RobotControl_B.VariantMerge_For_Variant_Source == ((uint8_T)
                  ENU_FORWARD)) {
        /* Switch: '<S163>/Switch1' */
        RobotControl_B.leftPosPin = RobotControl_B.Product;

        /* Switch: '<S163>/Switch1' incorporates:
         *  Constant: '<S163>/CAL_MOTOR_LOW'
         */
        RobotControl_B.leftNegPin = ((uint8_T)CAL_MOTOR_LOW);
      } else if (RobotControl_B.VariantMerge_For_Variant_Source == ((uint8_T)
                  ENU_STOP)) {
        /* Switch: '<S163>/Switch2' incorporates:
         *  Constant: '<S163>/CAL_MOTOR_LOW2'
         *  Switch: '<S163>/Switch1'
         */
        RobotControl_B.leftPosPin = ((uint8_T)CAL_MOTOR_LOW);

        /* Switch: '<S163>/Switch2' incorporates:
         *  Constant: '<S163>/CAL_MOTOR_LOW3'
         *  Switch: '<S163>/Switch1'
         */
        RobotControl_B.leftNegPin = ((uint8_T)CAL_MOTOR_LOW);
      } else {
        /* Switch: '<S163>/Switch1' incorporates:
         *  Switch: '<S163>/Switch2'
         */
        RobotControl_B.leftPosPin = RobotControl_B.Product;

        /* Switch: '<S163>/Switch1' incorporates:
         *  Switch: '<S163>/Switch2'
         */
        RobotControl_B.leftNegPin = RobotControl_B.Product;
      }

      /* End of Switch: '<S163>/Switch' */

      /* SignalConversion: '<S31>/TmpVariantMergeBufferAtVariantMerge_For_Variant_Source_Variant_Source3Inport2' */
#if MotorsEOL_DisabledVariant

      RobotControl_B.VariantMerge_For_Variant__i = RobotControl_B.Switch_c;

#endif                                 /* MotorsEOL_DisabledVariant */

      /* End of SignalConversion: '<S31>/TmpVariantMergeBufferAtVariantMerge_For_Variant_Source_Variant_Source3Inport2' */

      /* Product: '<S164>/Product' incorporates:
       *  Constant: '<S164>/CAL_MOTOR_HIGH'
       */
      RobotControl_B.Product = (uint8_T)
        (RobotControl_B.VariantMerge_For_Variant__i * (real32_T)((uint8_T)
          CAL_MOTOR_HIGH));

      /* Switch: '<S164>/Switch' incorporates:
       *  Constant: '<S164>/CAL_MOTOR_LOW1'
       *  Constant: '<S164>/ENU_BACKWARD'
       *  Constant: '<S164>/ENU_FORWARD'
       *  Constant: '<S164>/ENU_STOP'
       *  RelationalOperator: '<S164>/Relational_Operator'
       *  RelationalOperator: '<S164>/Relational_Operator1'
       *  RelationalOperator: '<S164>/Relational_Operator2'
       *  Switch: '<S164>/Switch'
       *  Switch: '<S164>/Switch1'
       *  Switch: '<S164>/Switch2'
       */
      if (RobotControl_B.VariantMerge_For_Variant_Sour_b == ((uint8_T)
           ENU_BACKWARD)) {
        RobotControl_B.rightPosPin = ((uint8_T)CAL_MOTOR_LOW);
        RobotControl_B.rightNegPin = RobotControl_B.Product;
      } else if (RobotControl_B.VariantMerge_For_Variant_Sour_b == ((uint8_T)
                  ENU_FORWARD)) {
        /* Switch: '<S164>/Switch1' */
        RobotControl_B.rightPosPin = RobotControl_B.Product;

        /* Switch: '<S164>/Switch1' incorporates:
         *  Constant: '<S164>/CAL_MOTOR_LOW'
         */
        RobotControl_B.rightNegPin = ((uint8_T)CAL_MOTOR_LOW);
      } else if (RobotControl_B.VariantMerge_For_Variant_Sour_b == ((uint8_T)
                  ENU_STOP)) {
        /* Switch: '<S164>/Switch2' incorporates:
         *  Constant: '<S164>/CAL_MOTOR_LOW2'
         *  Switch: '<S164>/Switch1'
         */
        RobotControl_B.rightPosPin = ((uint8_T)CAL_MOTOR_LOW);

        /* Switch: '<S164>/Switch2' incorporates:
         *  Constant: '<S164>/CAL_MOTOR_LOW3'
         *  Switch: '<S164>/Switch1'
         */
        RobotControl_B.rightNegPin = ((uint8_T)CAL_MOTOR_LOW);
      } else {
        /* Switch: '<S164>/Switch1' incorporates:
         *  Switch: '<S164>/Switch2'
         */
        RobotControl_B.rightPosPin = RobotControl_B.Product;

        /* Switch: '<S164>/Switch1' incorporates:
         *  Switch: '<S164>/Switch2'
         */
        RobotControl_B.rightNegPin = RobotControl_B.Product;
      }

      /* End of Switch: '<S164>/Switch' */

      /* Update for UnitDelay: '<S165>/FixPt Unit Delay2' incorporates:
       *  Constant: '<S165>/FixPt Constant'
       */
      RobotControl_DW.FixPtUnitDelay2_DSTATE = 0U;

      /* Switch: '<S165>/Reset' */
      if (RobotControl_B.Logical_Operator_o) {
        /* Update for UnitDelay: '<S165>/FixPt Unit Delay1' incorporates:
         *  Constant: '<S165>/Initial Condition'
         */
        RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;
      } else {
        /* Update for UnitDelay: '<S165>/FixPt Unit Delay1' */
        RobotControl_DW.FixPtUnitDelay1_DSTATE = RobotControl_B.Add_a5;
      }

      /* End of Switch: '<S165>/Reset' */
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
      } else if ((RobotControl_DW.is_c13_RobotControl ==
                  RobotControl_IN_ReadEEPROM) && (RobotControl_B.UnitDelay4 ==
                  ((uint8_T)ENU_FINISHED))) {
        /* During 'ReadEEPROM': '<S11>:1' */
        /* Transition: '<S11>:6' */
        RobotControl_DW.is_c13_RobotControl = RobotControl_IN_UpdateEEPROM;

        /* Entry 'UpdateEEPROM': '<S11>:5' */
        EEPROM_Update_Wrapper(RobotControl_B.UnitDelay,
                              RobotControl_B.UnitDelay1,
                              RobotControl_B.UnitDelay2,
                              RobotControl_B.UnitDelay3);
        EEPROM_Read_Wrapper(&RobotControl_B.NVM_AngleStoreFlg,
                            &RobotControl_B.NVM_NORTH, &RobotControl_B.NVM_SOUTH,
                            &RobotControl_B.NVM_EAST, &RobotControl_B.NVM_WEST);
      } else {
        /* During 'UpdateEEPROM': '<S11>:5' */
      }

      /* End of Chart: '<S7>/EEPROM_IO_Handler_Chart' */

      /* DataTypeConversion: '<S7>/Data Type Conversion' */
      RobotControl_B.DataTypeConversion_p = RobotControl_B.NVM_NORTH;

      /* DataTypeConversion: '<S7>/Data Type Conversion1' */
      RobotControl_B.DataTypeConversion1_b = RobotControl_B.NVM_SOUTH;

      /* DataTypeConversion: '<S7>/Data Type Conversion2' */
      RobotControl_B.DataTypeConversion2_g = RobotControl_B.NVM_EAST;

      /* DataTypeConversion: '<S7>/Data Type Conversion3' */
      RobotControl_B.DataTypeConversion3_j = RobotControl_B.NVM_WEST;

      /* End of Outputs for SubSystem: '<S1>/EEPROM_IO_Handler' */
    }

    /* every 50ms */
    if (RobotControl_DW.temporalCounter_i2_p == RobotControl_CAL_DIAG_Ticks_Sec)
    {
      /* Outputs for Function Call SubSystem: '<S22>/DIAG_Cont' */

      /* Event: '<S166>:8' */
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
  RobotControl_Digital_OUT_PWM(((uint8_T)CONST_PIN_D5),
    RobotControl_B.leftPosPin);

  /* Chart: '<S2>/Digital_OUT_PWM1' incorporates:
   *  Constant: '<S2>/PWMPin6'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)CONST_PIN_D6),
    RobotControl_B.leftNegPin);

  /* Chart: '<S2>/Digital_OUT_PWM2' incorporates:
   *  Constant: '<S2>/PWMPin9'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)CONST_PIN_D9),
    RobotControl_B.rightPosPin);

  /* Chart: '<S2>/Digital_OUT_PWM3' incorporates:
   *  Constant: '<S2>/PWMPin10'
   */
  RobotControl_Digital_OUT_PWM(((uint8_T)CONST_PIN_D10),
    RobotControl_B.rightNegPin);

  /* Chart: '<S2>/Digital_OUT_bool' incorporates:
   *  Constant: '<S2>/DigitalPin3'
   */
  RobotControl_Digital_OUT_bool(((uint8_T)CONST_PIN_D3),
    RobotControl_B.redLED_BOOL);

  /* Chart: '<S2>/Digital_OUT_bool1' incorporates:
   *  Constant: '<S2>/DigitalPin11'
   */
  RobotControl_Digital_OUT_bool(((uint8_T)CONST_PIN_D11),
    RobotControl_B.greenLED_BOOL);

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
    RobotControl_B.VariantMergeForOutportangleCa_h;
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

  /* exported global states */
#if debuggingFlag_variant

  leftEncoderDistErrorFlg = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  rightEncoderDistErrorFlg = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  ULSR_NotConnectedFlag_BOOL = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  ULSL_NotConnectedFlag_BOOL = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  rightMotorFaultFlag = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  compFaultFlag = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  leftMotorFaultFlag = false;

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

  stuckHitFlg = false;

#endif                                 /* debuggingFlag_variant */

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
  RobotControl_DW.is_c21_RobotControl = RobotContr_IN_NO_ACTIVE_CHILD_g;

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
  RobotControl_ULS_AnalogIn_Init();

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
  /* InitializeConditions for UnitDelay: '<S165>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S165>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE = 0.001F;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/EEPROM_IO_Handler'
   */
  /* SystemInitialize for Chart: '<S7>/EEPROM_IO_Handler_Chart' */
  RobotControl_DW.is_active_c13_RobotControl = 0U;
  RobotControl_DW.is_c13_RobotControl = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_B.NVM_AngleStoreFlg = false;
  RobotControl_B.NVM_NORTH = 0;
  RobotControl_B.NVM_SOUTH = 0;
  RobotControl_B.NVM_EAST = 0;
  RobotControl_B.NVM_WEST = 0;

  /* SystemInitialize for Chart: '<S4>/Scheduler' incorporates:
   *  SystemInitialize for SubSystem: '<S22>/DIAG_Cont'
   */
  RobotControl_DIAG_Cont_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
