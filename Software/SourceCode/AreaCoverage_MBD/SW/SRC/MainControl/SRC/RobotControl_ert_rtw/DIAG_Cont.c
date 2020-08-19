/*
 * File: DIAG_Cont.c
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

#include "DIAG_Cont.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S48>/MotorMoveMonitor' */
#define RobotCo_CONST_ENCOD_TIMER_FAULT ((uint8_T)10U)
#define RobotCon_IN_NO_ACTIVE_CHILD_cir ((uint8_T)0U)
#define RobotControl_IN_moveFault      ((uint8_T)1U)
#define RobotControl_IN_moveRefresh    ((uint8_T)2U)
#define RobotControl_IN_moveStart      ((uint8_T)3U)

/* System initialize for function-call system: '<S22>/DIAG_Cont' */
void RobotControl_DIAG_Cont_Init(void)
{
  /* SystemInitialize for Chart: '<S48>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_g = 0U;
  RobotControl_DW.is_active_c34_RobotControl = 0U;
  RobotControl_DW.is_c34_RobotControl = RobotCon_IN_NO_ACTIVE_CHILD_cir;
  RobotControl_DW.tempDist_f = 0.0F;
  RobotControl_B.leftMotorFaultFlag_j = false;

  /* SystemInitialize for Chart: '<S50>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_i = 0U;
  RobotControl_DW.is_active_c14_RobotControl = 0U;
  RobotControl_DW.is_c14_RobotControl = RobotCon_IN_NO_ACTIVE_CHILD_cir;
  RobotControl_DW.tempDist = 0.0F;
  RobotControl_B.rightMotorFaultFlag_k = false;
}

/* Output and update for function-call system: '<S22>/DIAG_Cont' */
void RobotControl_DIAG_Cont(void)
{
  int16_T rtb_Data_Type_Conversion_f;
  boolean_T rtb_moveFlag;
  boolean_T rtb_redLED_BOOL;

  /* DataStoreWrite: '<S43>/Data Store Write' */
#if debuggingFlag_variant

  stuckHitFlg = RobotControl_B.stuckHitFlg_c;

#endif                                 /* debuggingFlag_variant */

  /* End of DataStoreWrite: '<S43>/Data Store Write' */

  /* Sum: '<S46>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.leftPosPin -
    RobotControl_B.leftNegPin;

  /* Abs: '<S46>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S46>/Abs' */

  /* RelationalOperator: '<S46>/Relational_Operator2' incorporates:
   *  Constant: '<S46>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S46>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > ((uint8_T)CAL_PwmMoveThd_mm));

  /* Chart: '<S48>/MotorMoveMonitor' */
  /* Gateway: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_g < 15U) {
    RobotControl_DW.temporalCounter_i1_g++;
  }

  /* During: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  /* chart that monitor motor movement. detects if voltage is given to the mode however not encoder indication that the motor is rotating. this means motor is either stuck (high current) or encoder signal has stopped. */
  if (RobotControl_DW.is_active_c34_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c34_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S49>:2' */
    RobotControl_DW.is_c34_RobotControl = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c34_RobotControl) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S49>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S49>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S49>:8' */
        RobotControl_DW.tempDist_f = RobotControl_B.Data_Type_Conversion;
        RobotControl_DW.is_c34_RobotControl = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_g = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S49>:1' */
      if ((RobotControl_DW.temporalCounter_i1_g >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S49>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion ==
                             RobotControl_DW.tempDist_f)) {
          /* Transition: '<S49>:9' */
          RobotControl_DW.is_c34_RobotControl = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S49>:5' */
          RobotControl_B.leftMotorFaultFlag_j = true;
        } else {
          /* Transition: '<S49>:7' */
          RobotControl_DW.is_c34_RobotControl = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S48>/MotorMoveMonitor' */

  /* DataStoreWrite: '<S43>/Data Store Write1' */
#if debuggingFlag_variant

  leftMotorFaultFlag = RobotControl_B.leftMotorFaultFlag_j;

#endif                                 /* debuggingFlag_variant */

  /* End of DataStoreWrite: '<S43>/Data Store Write1' */

  /* Sum: '<S47>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.rightPosPin -
    RobotControl_B.rightNegPin;

  /* Abs: '<S47>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S47>/Abs' */

  /* RelationalOperator: '<S47>/Relational_Operator2' incorporates:
   *  Constant: '<S47>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S47>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > ((uint8_T)CAL_PwmMoveThd_mm));

  /* Chart: '<S50>/MotorMoveMonitor' */
  /* Gateway: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_i < 15U) {
    RobotControl_DW.temporalCounter_i1_i++;
  }

  /* During: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  /* chart that monitor motor movement. detects if voltage is given to the mode however not encoder indication that the motor is rotating. this means motor is either stuck (high current) or encoder signal has stopped. */
  if (RobotControl_DW.is_active_c14_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c14_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S51>:2' */
    RobotControl_DW.is_c14_RobotControl = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c14_RobotControl) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S51>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S51>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S51>:8' */
        RobotControl_DW.tempDist = RobotControl_B.Data_Type_Conversion_m;
        RobotControl_DW.is_c14_RobotControl = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_i = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S51>:1' */
      if ((RobotControl_DW.temporalCounter_i1_i >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S51>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion_m ==
                             RobotControl_DW.tempDist)) {
          /* Transition: '<S51>:9' */
          RobotControl_DW.is_c14_RobotControl = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S51>:5' */
          RobotControl_B.rightMotorFaultFlag_k = true;
        } else {
          /* Transition: '<S51>:7' */
          RobotControl_DW.is_c14_RobotControl = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S50>/MotorMoveMonitor' */

  /* RelationalOperator: '<S52>/Relational_Operator' incorporates:
   *  Constant: '<S52>/CONST_Zero'
   *  DataTypeConversion: '<S52>/Data_Type_Conversion'
   */
  RobotControl_B.ULSL_NotConnectedFlag_BOOL_h = (RobotControl_B.ULSL_cm ==
    (uint16_T)CONST_Zero);

  /* DataStoreWrite: '<S43>/Data Store Write3' */
#if debuggingFlag_variant

  rightMotorFaultFlag = RobotControl_B.rightMotorFaultFlag_k;

#endif                                 /* debuggingFlag_variant */

  /* End of DataStoreWrite: '<S43>/Data Store Write3' */

  /* RelationalOperator: '<S53>/Relational_Operator' incorporates:
   *  Constant: '<S53>/CONST_Zero'
   *  DataTypeConversion: '<S53>/Data_Type_Conversion'
   */
  RobotControl_B.ULSR_NotConnectedFlag_BOOL_a = (RobotControl_B.ULSR_cm ==
    (uint16_T)CONST_Zero);

  /* DataStoreWrite: '<S43>/Data Store Write4' incorporates:
   *  DataStoreWrite: '<S43>/Data Store Write2'
   *  DataStoreWrite: '<S43>/Data Store Write5'
   *  DataStoreWrite: '<S43>/Data Store Write6'
   *  DataStoreWrite: '<S43>/Data Store Write7'
   */
#if debuggingFlag_variant

  ULSL_NotConnectedFlag_BOOL = RobotControl_B.ULSL_NotConnectedFlag_BOOL_h;
  ULSR_NotConnectedFlag_BOOL = RobotControl_B.ULSR_NotConnectedFlag_BOOL_a;
  compFaultFlag = RobotControl_B.OutportBufferForcompFaultFlag;
  rightEncoderDistErrorFlg = RobotControl_B.VariantMergeForOutportrightEnco;
  leftEncoderDistErrorFlg = RobotControl_B.VariantMergeForOutportleftEncod;

#endif                                 /* debuggingFlag_variant */

  /* End of DataStoreWrite: '<S43>/Data Store Write4' */

  /* Logic: '<S42>/Logical_Operator' */
  rtb_moveFlag = (RobotControl_B.leftMotorFaultFlag_j ||
                  RobotControl_B.rightMotorFaultFlag_k);

  /* Logic: '<S42>/Logical Operator' */
  rtb_redLED_BOOL = (RobotControl_B.ULSL_NotConnectedFlag_BOOL_h ||
                     RobotControl_B.ULSR_NotConnectedFlag_BOOL_a || rtb_moveFlag);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/ENU_DIAG'
   *  Logic: '<S42>/Logical_Operator1'
   *  RelationalOperator: '<S42>/Relational Operator'
   */
  if (RobotControl_B.currentRoutine != ((uint8_T)ENU_DIAG)) {
    rtb_moveFlag = (RobotControl_B.leftMotorFaultFlag_j &&
                    RobotControl_B.rightMotorFaultFlag_k);
  }

  /* End of Switch: '<S42>/Switch' */

  /* Logic: '<S42>/Logical_Operator4' incorporates:
   *  Logic: '<S42>/Logical_Operator3'
   *  Logic: '<S42>/Logical_Operator5'
   */
  RobotControl_B.failFlag = (rtb_moveFlag || (RobotControl_B.stuckHitFlg_c ||
    (RobotControl_B.OutportBufferForcompFaultFlag ||
     RobotControl_B.VariantMergeForOutportrightEnco ||
     RobotControl_B.VariantMergeForOutportleftEncod)));

  /* Logic: '<S42>/Logical Operator2' */
  RobotControl_B.greenLED_BOOL = !RobotControl_B.failFlag;

  /* Logic: '<S42>/Logical_Operator2' */
  RobotControl_B.redLED_BOOL = (rtb_redLED_BOOL || RobotControl_B.failFlag);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
