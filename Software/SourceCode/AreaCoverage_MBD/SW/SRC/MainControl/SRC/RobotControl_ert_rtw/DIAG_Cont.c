/*
 * File: DIAG_Cont.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.553
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Aug 05 14:53:55 2020
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

/* Named constants for Chart: '<S45>/MotorMoveMonitor' */
#define RobotCo_CONST_ENCOD_TIMER_FAULT ((uint8_T)10U)
#define RobotContr_IN_NO_ACTIVE_CHILD_h ((uint8_T)0U)
#define RobotControl_IN_moveFault      ((uint8_T)1U)
#define RobotControl_IN_moveRefresh    ((uint8_T)2U)
#define RobotControl_IN_moveStart      ((uint8_T)3U)

/* System initialize for function-call system: '<S21>/DIAG_Cont' */
void RobotControl_DIAG_Cont_Init(void)
{
  /* SystemInitialize for Chart: '<S45>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_in = 0U;
  RobotControl_DW.is_active_c34_RobotControlLib = 0U;
  RobotControl_DW.is_c34_RobotControlLib = RobotContr_IN_NO_ACTIVE_CHILD_h;
  RobotControl_DW.tempDist_j = 0.0F;
  RobotControl_B.motorFaultFlag_k = false;

  /* SystemInitialize for Chart: '<S47>/MotorMoveMonitor' */
  RobotControl_DW.temporalCounter_i1_d = 0U;
  RobotControl_DW.is_active_c12_RobotControlLib = 0U;
  RobotControl_DW.is_c12_RobotControlLib = RobotContr_IN_NO_ACTIVE_CHILD_h;
  RobotControl_DW.tempDist = 0.0F;
  RobotControl_B.motorFaultFlag = false;
}

/* Output and update for function-call system: '<S21>/DIAG_Cont' */
void RobotControl_DIAG_Cont(void)
{
  int16_T rtb_Data_Type_Conversion_f;
  boolean_T rtb_moveFlag;
  boolean_T rtb_redLED_BOOL;

  /* RelationalOperator: '<S49>/Relational_Operator' incorporates:
   *  Constant: '<S49>/CONST_Zero'
   *  DataTypeConversion: '<S49>/Data_Type_Conversion'
   */
  RobotControl_B.ULS_NotConnectedFlag_BOOL = (RobotControl_B.ULSL_cm ==
    (uint16_T)CONST_Zero);

  /* RelationalOperator: '<S50>/Relational_Operator' incorporates:
   *  Constant: '<S50>/CONST_Zero'
   *  DataTypeConversion: '<S50>/Data_Type_Conversion'
   */
  RobotControl_B.ULS_NotConnectedFlag_BOOL_j = (RobotControl_B.ULSR_cm ==
    (uint16_T)CONST_Zero);

  /* Sum: '<S43>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.leftPosPin -
    RobotControl_B.leftNegPin;

  /* Abs: '<S43>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S43>/Abs' */

  /* RelationalOperator: '<S43>/Relational_Operator2' incorporates:
   *  Constant: '<S43>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S43>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > ((uint8_T)CAL_PwmMoveThd_mm));

  /* Chart: '<S45>/MotorMoveMonitor' */
  /* Gateway: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_in < 15U) {
    RobotControl_DW.temporalCounter_i1_in++;
  }

  /* During: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
  /* chart that monitor motor movement. detects if voltage is given to the mode however not encoder indication that the motor is rotating. this means motor is either stuck (high current) or encoder signal has stopped. */
  if (RobotControl_DW.is_active_c34_RobotControlLib == 0U) {
    /* Entry: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c34_RobotControlLib = 1U;

    /* Entry Internal: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S46>:2' */
    RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c34_RobotControlLib) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S46>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S46>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S46>:8' */
        RobotControl_DW.tempDist_j = RobotControl_B.Data_Type_Conversion;
        RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_in = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S46>:1' */
      if ((RobotControl_DW.temporalCounter_i1_in >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S46>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion ==
                             RobotControl_DW.tempDist_j)) {
          /* Transition: '<S46>:9' */
          RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S46>:5' */
          RobotControl_B.motorFaultFlag_k = true;
        } else {
          /* Transition: '<S46>:7' */
          RobotControl_DW.is_c34_RobotControlLib = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S45>/MotorMoveMonitor' */

  /* Sum: '<S44>/Subtract1' */
  rtb_Data_Type_Conversion_f = RobotControl_B.rightPosPin -
    RobotControl_B.rightNegPin;

  /* Abs: '<S44>/Abs' */
  if (rtb_Data_Type_Conversion_f < 0) {
    rtb_Data_Type_Conversion_f = -rtb_Data_Type_Conversion_f;
  }

  /* End of Abs: '<S44>/Abs' */

  /* RelationalOperator: '<S44>/Relational_Operator2' incorporates:
   *  Constant: '<S44>/CAL_PwmMoveThd_mm'
   *  DataTypeConversion: '<S44>/Data_Type_Conversion'
   */
  rtb_moveFlag = (rtb_Data_Type_Conversion_f > ((uint8_T)CAL_PwmMoveThd_mm));

  /* Chart: '<S47>/MotorMoveMonitor' */
  /* Gateway: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  if (RobotControl_DW.temporalCounter_i1_d < 15U) {
    RobotControl_DW.temporalCounter_i1_d++;
  }

  /* During: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
  /* chart that monitor motor movement. detects if voltage is given to the mode however not encoder indication that the motor is rotating. this means motor is either stuck (high current) or encoder signal has stopped. */
  if (RobotControl_DW.is_active_c12_RobotControlLib == 0U) {
    /* Entry: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    RobotControl_DW.is_active_c12_RobotControlLib = 1U;

    /* Entry Internal: RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor */
    /* Transition: '<S48>:2' */
    RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveRefresh;
  } else {
    switch (RobotControl_DW.is_c12_RobotControlLib) {
     case RobotControl_IN_moveFault:
      /* During 'moveFault': '<S48>:5' */
      break;

     case RobotControl_IN_moveRefresh:
      /* During 'moveRefresh': '<S48>:3' */
      if (rtb_moveFlag) {
        /* Transition: '<S48>:8' */
        RobotControl_DW.tempDist = RobotControl_B.Data_Type_Conversion_m;
        RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveStart;
        RobotControl_DW.temporalCounter_i1_d = 0U;
      }
      break;

     default:
      /* During 'moveStart': '<S48>:1' */
      if ((RobotControl_DW.temporalCounter_i1_d >=
           RobotCo_CONST_ENCOD_TIMER_FAULT) || (!rtb_moveFlag)) {
        /* Transition: '<S48>:4' */
        if (rtb_moveFlag && (RobotControl_B.Data_Type_Conversion_m ==
                             RobotControl_DW.tempDist)) {
          /* Transition: '<S48>:9' */
          RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveFault;

          /* Entry 'moveFault': '<S48>:5' */
          RobotControl_B.motorFaultFlag = true;
        } else {
          /* Transition: '<S48>:7' */
          RobotControl_DW.is_c12_RobotControlLib = RobotControl_IN_moveRefresh;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S47>/MotorMoveMonitor' */

  /* Logic: '<S23>/Logical_Operator' */
  rtb_moveFlag = (RobotControl_B.motorFaultFlag_k ||
                  RobotControl_B.motorFaultFlag);

  /* Logic: '<S23>/Logical Operator' */
  rtb_redLED_BOOL = (RobotControl_B.ULS_NotConnectedFlag_BOOL ||
                     RobotControl_B.ULS_NotConnectedFlag_BOOL_j || rtb_moveFlag);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/ENU_DIAG'
   *  Logic: '<S23>/Logical_Operator1'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  if (RobotControl_B.currentRoutine != ((uint8_T)ENU_DIAG)) {
    rtb_moveFlag = (RobotControl_B.motorFaultFlag_k &&
                    RobotControl_B.motorFaultFlag);
  }

  /* End of Switch: '<S23>/Switch' */

  /* Logic: '<S23>/Logical_Operator4' incorporates:
   *  Logic: '<S23>/Logical_Operator3'
   */
  RobotControl_B.failFlag = (rtb_moveFlag || (RobotControl_B.stuckHitFlg ||
    RobotControl_B.diagSensorFailure));

  /* Logic: '<S23>/Logical Operator2' */
  RobotControl_B.greenLED_BOOL = !RobotControl_B.failFlag;

  /* Logic: '<S23>/Logical_Operator2' */
  RobotControl_B.redLED_BOOL = (rtb_redLED_BOOL || RobotControl_B.failFlag);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
