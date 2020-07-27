/*
 * Code generation for system system '<S16>/DIAG_Cont'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "DIAG_Cont.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S40>/MotorMoveMonitor' */
#define RobotCo_CONST_ENCOD_TIMER_FAULT ((uint8_T)10U)
#define RobotContr_IN_NO_ACTIVE_CHILD_h ((uint8_T)0U)
#define RobotControl_IN_moveFault      ((uint8_T)1U)
#define RobotControl_IN_moveRefresh    ((uint8_T)2U)
#define RobotControl_IN_moveStart      ((uint8_T)3U)

/* System initialize for function-call system: '<S16>/DIAG_Cont' */
void RobotControl_DIAG_Cont_Init(void)
{
  /* SystemInitialize for Chart: '<S40>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_in = 0U;
  RobotControl_DW.is_active_c34_RobotControlLib = 0U;
  RobotControl_DW.is_c34_RobotControlLib = RobotContr_IN_NO_ACTIVE_CHILD_h;
  RobotControl_DW.tempDist_j = 0.0F;
  RobotControl_B.motorFaultFlag_k = false;

  /* SystemInitialize for Chart: '<S42>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_d = 0U;
  RobotControl_DW.is_active_c12_RobotControlLib = 0U;
  RobotControl_DW.is_c12_RobotControlLib = RobotContr_IN_NO_ACTIVE_CHILD_h;
  RobotControl_DW.tempDist = 0.0F;
  RobotControl_B.motorFaultFlag = false;

  /* SystemInitialize for Outport: '<S18>/failFlag' */
  RobotControl_B.failFlag = false;

  /* SystemInitialize for Outport: '<S18>/ULSL_NotConnectedFlag_BOOL' */
  RobotControl_B.ULS_NotConnectedFlag_BOOL = false;

  /* SystemInitialize for Outport: '<S18>/ULSR_NotConnectedFlag_BOOL' */
  RobotControl_B.ULS_NotConnectedFlag_BOOL_j = false;

  /* SystemInitialize for Outport: '<S18>/redLED_BOOL' */
  RobotControl_B.redLED_BOOL = false;

  /* SystemInitialize for Outport: '<S18>/greenLED_BOOL' */
  RobotControl_B.greenLED_BOOL = false;
}

/* Output and update for function-call system: '<S16>/DIAG_Cont' */
void RobotControl_DIAG_Cont(void)
{
  int16_T rtb_Data_Type_Conversion_f;
  boolean_T rtb_moveFlag;
  boolean_T rtb_redLED_BOOL;

  /* RelationalOperator: '<S44>/Relational_Operator' incorporates:
   *  Constant: '<S44>/CONST_Zero'
   *  DataTypeConversion: '<S44>/Data_Type_Conversion'
   */
  RobotControl_B.ULS_NotConnectedFlag_BOOL = (RobotControl_B.ULSL_D8R_D7L ==
    (uint16_T)RobotControl_P.CONST_Zero);

  /* RelationalOperator: '<S45>/Relational_Operator' incorporates:
   *  Constant: '<S45>/CONST_Zero'
   *  DataTypeConversion: '<S45>/Data_Type_Conversion'
   */
  RobotControl_B.ULS_NotConnectedFlag_BOOL_j = (RobotControl_B.ULSR_D8R_D7L1 ==
    (uint16_T)RobotControl_P.CONST_Zero);

  /* Sum: '<S38>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.leftPosPin -
    RobotControl_B.leftNegPin;

  /* Abs: '<S38>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S38>/Abs' */

  /* RelationalOperator: '<S38>/Relational_Operator2' incorporates:
   *  Constant: '<S38>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S38>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > RobotControl_P.CAL_PwmMoveThd_mm);

  /* Chart: '<S40>/MotorMoveMonitor' */
  /* Gateway: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_in < 15U) {
    RobotControl_DW.temporalCounter_i1_in++;
  }

  /* During: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.is_active_c34_RobotControlLib == 0U) {
    /* Entry: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c34_RobotControlLib = 1U;

    /* Entry Internal: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S41>:2' */
    RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c34_RobotControlLib) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S41>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S41>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S41>:8' */
        RobotControl_DW.tempDist_j = RobotControl_B.Data_Type_Conversion;
        RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_in = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S41>:1' */
      if ((RobotControl_DW.temporalCounter_i1_in >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S41>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion ==
                             RobotControl_DW.tempDist_j)) {
          /* Transition: '<S41>:9' */
          RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S41>:5' */
          RobotControl_B.motorFaultFlag_k = true;
        } else {
          /* Transition: '<S41>:7' */
          RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S40>/MotorMoveMonitor' */

  /* Sum: '<S39>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.rightPosPin -
    RobotControl_B.rightNegPin;

  /* Abs: '<S39>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S39>/Abs' */

  /* RelationalOperator: '<S39>/Relational_Operator2' incorporates:
   *  Constant: '<S39>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S39>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > RobotControl_P.CAL_PwmMoveThd_mm);

  /* Chart: '<S42>/MotorMoveMonitor' */
  /* Gateway: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_d < 15U) {
    RobotControl_DW.temporalCounter_i1_d++;
  }

  /* During: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.is_active_c12_RobotControlLib == 0U) {
    /* Entry: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c12_RobotControlLib = 1U;

    /* Entry Internal: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S43>:2' */
    RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c12_RobotControlLib) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S43>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S43>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S43>:8' */
        RobotControl_DW.tempDist = RobotControl_B.Data_Type_Conversion_m;
        RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_d = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S43>:1' */
      if ((RobotControl_DW.temporalCounter_i1_d >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S43>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion_m ==
                             RobotControl_DW.tempDist)) {
          /* Transition: '<S43>:9' */
          RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S43>:5' */
          RobotControl_B.motorFaultFlag = true;
        } else {
          /* Transition: '<S43>:7' */
          RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S42>/MotorMoveMonitor' */

  /* Logic: '<S18>/Logical_Operator' */
  rtb_moveFlag = (RobotControl_B.motorFaultFlag_k ||
                  RobotControl_B.motorFaultFlag);

  /* Logic: '<S18>/Logical Operator' */
  rtb_redLED_BOOL = (RobotControl_B.ULS_NotConnectedFlag_BOOL ||
                     RobotControl_B.ULS_NotConnectedFlag_BOOL_j || rtb_moveFlag);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/ENU_DIAG'
   *  Logic: '<S18>/Logical_Operator1'
   *  RelationalOperator: '<S18>/Relational Operator'
   */
  if (RobotControl_B.currentRoutine != RobotControl_P.ENU_DIAG) {
    rtb_moveFlag = (RobotControl_B.motorFaultFlag_k &&
                    RobotControl_B.motorFaultFlag);
  }

  /* End of Switch: '<S18>/Switch' */

  /* Logic: '<S18>/Logical_Operator4' incorporates:
   *  Logic: '<S18>/Logical_Operator3'
   */
  RobotControl_B.failFlag = (rtb_moveFlag || (RobotControl_B.stuckHitFlg ||
    RobotControl_B.diagSensorFailure));

  /* Logic: '<S18>/Logical Operator2' */
  RobotControl_B.greenLED_BOOL = !RobotControl_B.failFlag;

  /* Logic: '<S18>/Logical_Operator2' */
  RobotControl_B.redLED_BOOL = (rtb_redLED_BOOL || RobotControl_B.failFlag);
}
