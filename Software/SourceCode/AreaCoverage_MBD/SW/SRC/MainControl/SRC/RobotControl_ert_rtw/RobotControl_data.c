/*
 * RobotControl_data.c
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

/* Invariant block signals (auto storage) */
const ConstB_RobotControl_T RobotControl_ConstB = {
  57.295779513082323,                  /* '<S58>/Divide' */
  57.295779513082323,                  /* '<S33>/Divide' */
  -2.5F,                               /* '<S133>/Gain' */
  7U,                                  /* '<S9>/Data Type Conversion' */
  8U,                                  /* '<S9>/Data Type Conversion1' */
  1,                                   /* '<S99>/Logical_Operator' */
  1                                    /* '<S19>/Logical_Operator' */
};

/* Block parameters (auto storage) */
P_RobotControl_T RobotControl_P = {
  12.0,                                /* Variable: gearRatio
                                        * Referenced by:
                                        *   '<S72>/gearRatio'
                                        *   '<S81>/gearRatio'
                                        */
  0.001F,                              /* Variable: CAL_EncoderSampleTime
                                        * Referenced by: '<S31>/CAL_EncoderSampleTime'
                                        */
  -2.0F,                               /* Variable: CAL_ErrorLowerLimit
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  2.0F,                                /* Variable: CAL_ErrorUpperLimit
                                        * Referenced by:
                                        *   '<S25>/Saturation'
                                        *   '<S25>/Saturation1'
                                        */
  0.005F,                              /* Variable: CAL_Kd
                                        * Referenced by: '<S132>/Kd'
                                        */
  0.003F,                              /* Variable: CAL_Ki
                                        * Referenced by: '<S132>/Ki'
                                        */
  3.0F,                                /* Variable: CAL_Kp
                                        * Referenced by: '<S132>/Kp'
                                        */
  0.8F,                                /* Variable: CAL_MeasNoiseVelKF
                                        * Referenced by:
                                        *   '<S71>/CAL_MeasNoiseVelKF'
                                        *   '<S80>/CAL_MeasNoiseVelKF'
                                        */
  1.2F,                                /* Variable: CAL_MeasureNoise
                                        * Referenced by: '<S31>/CAL_MeasureNoise'
                                        */
  4.7124F,                             /* Variable: CAL_NORTH_rad
                                        * Referenced by: '<S48>/Unit_Delay'
                                        */
  1.5F,                                /* Variable: CAL_ProcessNoise
                                        * Referenced by: '<S31>/CAL_ProcessNoise'
                                        */
  0.001F,                              /* Variable: CAL_forwardStartIncr
                                        * Referenced by: '<S25>/CAL_forwardStartIncr'
                                        */
  150.0F,                              /* Variable: CAL_hitBackwardDist_mm
                                        * Referenced by: '<S24>/CAL_hitBackwardDist_mm1'
                                        */
  0.80211F,                            /* Variable: CAL_mm_PER_tick
                                        * Referenced by:
                                        *   '<S52>/Gain1'
                                        *   '<S53>/Gain1'
                                        */
  2.5F,                                /* Variable: CAL_procNoiseVelKF
                                        * Referenced by:
                                        *   '<S71>/CAL_procNoiseVelKF'
                                        *   '<S80>/CAL_procNoiseVelKF'
                                        */
  1.0F,                                /* Variable: CONST_ONE_F32
                                        * Referenced by:
                                        *   '<S71>/CONST_ONE_F32'
                                        *   '<S80>/CONST_ONE_F32'
                                        */
  3.1416F,                             /* Variable: CONST_PI_F32
                                        * Referenced by: '<S105>/CONST_PI_F32'
                                        */
  2.0F,                                /* Variable: CONST_TWO_F32
                                        * Referenced by:
                                        *   '<S91>/CONST_TWO_F32'
                                        *   '<S124>/CONST_TWO_F32'
                                        *   '<S105>/CONST_TWO_F32'
                                        *   '<S105>/CONST_TWO_F321'
                                        *   '<S72>/CONST_TWO_F32'
                                        *   '<S81>/CONST_TWO_F32'
                                        */
  0.0F,                                /* Variable: CONST_ZERO_F32
                                        * Referenced by:
                                        *   '<S91>/CONST_ZERO_F32'
                                        *   '<S125>/CONST_ZERO_F32'
                                        *   '<S129>/CONST_ZERO_F32'
                                        */
  -1,                                  /* Variable: CONST_NEG_ONE_INT32
                                        * Referenced by:
                                        *   '<S56>/CONST_NEG_ONE_INT32'
                                        *   '<S57>/CONST_NEG_ONE_INT32'
                                        */
  1,                                   /* Variable: CONST_ONE_INT32
                                        * Referenced by:
                                        *   '<S56>/CONST_ONE_INT32'
                                        *   '<S57>/CONST_ONE_INT32'
                                        */
  0,                                   /* Variable: CAL_EAST
                                        * Referenced by: '<S20>/CAL_EAST'
                                        */
  100,                                 /* Variable: CAL_FilterResetThd
                                        * Referenced by: '<S31>/CAL_FilterResetThd'
                                        */
  270,                                 /* Variable: CAL_NORTH
                                        * Referenced by:
                                        *   '<S20>/CAL_NORTH'
                                        *   '<S21>/Unit_Delay5'
                                        *   '<S31>/Unit_Delay'
                                        */
  90,                                  /* Variable: CAL_SOUTH
                                        * Referenced by: '<S20>/CAL_SOUTH'
                                        */
  180,                                 /* Variable: CAL_WEST
                                        * Referenced by: '<S20>/CAL_WEST'
                                        */
  -1,                                  /* Variable: CONST_NegOne
                                        * Referenced by:
                                        *   '<S125>/Gain7'
                                        *   '<S125>/Gain8'
                                        */
  0,                                   /* Variable: CONST_Zero
                                        * Referenced by:
                                        *   '<S44>/CONST_Zero'
                                        *   '<S45>/CONST_Zero'
                                        */
  0,                                   /* Variable: CONST_ZeroDeg
                                        * Referenced by: '<S31>/CONST_ZeroDeg1'
                                        */
  100U,                                /* Variable: CAL_EncoderAnaThd
                                        * Referenced by:
                                        *   '<S47>/CAL_EncoderAnaThd'
                                        *   '<S47>/CAL_EncoderAnaThd1'
                                        */
  250U,                                /* Variable: CAL_ROBO_LENG_mm
                                        * Referenced by:
                                        *   '<S59>/CAL_ROBO_LENG_mm'
                                        *   '<S34>/CAL_ROBO_LENG_mm'
                                        */
  250U,                                /* Variable: CAL_Wheel2WheelDist_mm
                                        * Referenced by: '<S105>/CAL_Wheel2WheelDist_mm'
                                        */
  360U,                                /* Variable: CAL_fullCircle_DEG
                                        * Referenced by:
                                        *   '<S125>/CAL_fullCircle_DEG'
                                        *   '<S125>/CAL_fullCircle_DEG1'
                                        *   '<S30>/Saturation'
                                        *   '<S31>/CAL_fullCircle_DEG'
                                        *   '<S35>/CAL_fullCircle_DEG'
                                        *   '<S35>/CAL_fullCircle_DEG1'
                                        */
  180U,                                /* Variable: CAL_halfCircle_DEG
                                        * Referenced by:
                                        *   '<S125>/CAL_halfCircle_DEG'
                                        *   '<S125>/CAL_halfCircle_DEG1'
                                        *   '<S125>/CAL_halfCircle_DEG2'
                                        */
  5U,                                  /* Variable: CONST_MinDistError_mm
                                        * Referenced by:
                                        *   '<S112>/CONST_MinDistError_mm'
                                        *   '<S113>/CONST_MinDistError_mm'
                                        */
  1U,                                  /* Variable: CONST_ONE_UINT16
                                        * Referenced by:
                                        *   '<S31>/CONST_ONE_UINT16'
                                        *   '<S64>/CONST_ONE_UINT16'
                                        */
  5U,                                  /* Variable: CONST_OVERFLOW_THD_UINT16
                                        * Referenced by:
                                        *   '<S35>/CONST_OVERFLOW_THD_UINT16'
                                        *   '<S35>/CONST_OVERFLOW_THD_UINT161'
                                        */
  0U,                                  /* Variable: CONST_ZERO_UINT16
                                        * Referenced by:
                                        *   '<S30>/Saturation'
                                        *   '<S35>/CONST_ZERO_UINT16'
                                        */
  400U,                                /* Variable: ENU_ROB_NONE
                                        * Referenced by:
                                        *   '<S26>/ENU_ROB_NONE'
                                        *   '<S127>/ENU_ROB_NONE'
                                        */
  126U,                                /* Variable: CAL_MOTOR_HIGH
                                        * Referenced by:
                                        *   '<S25>/CAL_MOTOR_HIGH'
                                        *   '<S145>/CAL_MOTOR_HIGH'
                                        *   '<S146>/CAL_MOTOR_HIGH'
                                        */
  0U,                                  /* Variable: CAL_MOTOR_LOW
                                        * Referenced by:
                                        *   '<S145>/CAL_MOTOR_LOW'
                                        *   '<S145>/CAL_MOTOR_LOW1'
                                        *   '<S145>/CAL_MOTOR_LOW2'
                                        *   '<S145>/CAL_MOTOR_LOW3'
                                        *   '<S146>/CAL_MOTOR_LOW'
                                        *   '<S146>/CAL_MOTOR_LOW1'
                                        *   '<S146>/CAL_MOTOR_LOW2'
                                        *   '<S146>/CAL_MOTOR_LOW3'
                                        */
  0U,                                  /* Variable: CAL_NO_ERROR
                                        * Referenced by:
                                        *   '<S22>/CAL_NO_ERROR'
                                        *   '<S22>/CAL_NO_ERROR1'
                                        *   '<S22>/Unit_Delay4'
                                        */
  180U,                                /* Variable: CAL_PwmMoveThd_mm
                                        * Referenced by:
                                        *   '<S38>/CAL_PwmMoveThd_mm'
                                        *   '<S39>/CAL_PwmMoveThd_mm'
                                        */
  25U,                                 /* Variable: CAL_ROBO_LENG
                                        * Referenced by:
                                        *   '<S140>/CAL_ROBO_LENG'
                                        *   '<S140>/CAL_ROBO_LENG1'
                                        */
  5U,                                  /* Variable: CAL_ROB_ERRVAL
                                        * Referenced by: '<S26>/CAL_ROB_ERRVAL'
                                        */
  10U,                                 /* Variable: CAL_ULS_UnconnectedBlks
                                        * Referenced by:
                                        *   '<S96>/CAL_ULS_UnconnectedBlks'
                                        *   '<S96>/CAL_ULS_UnconnectedBlks1'
                                        */
  12U,                                 /* Variable: CAL_WheelDiameter_cm
                                        * Referenced by:
                                        *   '<S72>/CAL_WheelDiameter_cm'
                                        *   '<S81>/CAL_WheelDiameter_cm'
                                        */
  100U,                                /* Variable: CAL_thetaGain
                                        * Referenced by:
                                        *   '<S22>/Gain4'
                                        *   '<S125>/Gain'
                                        *   '<S125>/Gain1'
                                        *   '<S125>/Gain2'
                                        *   '<S125>/Gain3'
                                        *   '<S125>/Gain4'
                                        *   '<S125>/Gain5'
                                        *   '<S30>/Gain'
                                        */
  8U,                                  /* Variable: CONST_DIAG_FINISH_FLG
                                        * Referenced by: '<S104>/CONST_DIAG_FINISH_FLG'
                                        */
  9U,                                  /* Variable: CONST_DIAG_UNCONFIRM
                                        * Referenced by:
                                        *   '<S21>/Unit_Delay4'
                                        *   '<S90>/DIAG_StatusFlg'
                                        *   '<S104>/None'
                                        */
  2U,                                  /* Variable: ENU_BACKWARD
                                        * Referenced by:
                                        *   '<S22>/ENU_BACKWARD'
                                        *   '<S25>/ENU_FORWARD1'
                                        *   '<S126>/ENU_BACKWARD'
                                        *   '<S126>/ENU_BACKWARD1'
                                        *   '<S126>/ENU_BACKWARD2'
                                        *   '<S126>/ENU_BACKWARD3'
                                        *   '<S126>/ENU_BACKWARD4'
                                        *   '<S127>/ENU_BACKWARD'
                                        *   '<S145>/ENU_BACKWARD'
                                        *   '<S146>/ENU_BACKWARD'
                                        *   '<S87>/ENU_BACKWARD'
                                        *   '<S88>/ENU_BACKWARD'
                                        */
  4U,                                  /* Variable: ENU_CCW
                                        * Referenced by:
                                        *   '<S126>/ENU_CCW'
                                        *   '<S127>/ENU_CCW'
                                        *   '<S129>/ENU_CCW'
                                        */
  3U,                                  /* Variable: ENU_CW
                                        * Referenced by:
                                        *   '<S126>/ENU_CW'
                                        *   '<S127>/ENU_CW'
                                        *   '<S129>/ENU_CW'
                                        */
  28U,                                 /* Variable: ENU_DIAG
                                        * Referenced by:
                                        *   '<S18>/ENU_DIAG'
                                        *   '<S19>/ENU_DIAG'
                                        */
  27U,                                 /* Variable: ENU_END
                                        * Referenced by: '<S20>/Unit_Delay'
                                        */
  2U,                                  /* Variable: ENU_FAILED
                                        * Referenced by: '<S102>/ENU_FAILED'
                                        */
  1U,                                  /* Variable: ENU_FORWARD
                                        * Referenced by:
                                        *   '<S22>/ENU_FORWARD'
                                        *   '<S25>/ENU_FORWARD'
                                        *   '<S91>/ENU_FORWARD'
                                        *   '<S95>/ENU_FORWARD'
                                        *   '<S98>/ENU_FORWARD'
                                        *   '<S124>/ENU_FORWARD'
                                        *   '<S126>/ENU_FORWARD'
                                        *   '<S126>/ENU_FORWARD1'
                                        *   '<S126>/ENU_FORWARD2'
                                        *   '<S126>/ENU_FORWARD3'
                                        *   '<S126>/ENU_FORWARD4'
                                        *   '<S127>/ENU_FORWARD'
                                        *   '<S145>/ENU_FORWARD'
                                        *   '<S146>/ENU_FORWARD'
                                        *   '<S87>/ENU_FORWARD'
                                        *   '<S88>/ENU_FORWARD'
                                        *   '<S56>/ENU_FORWARD'
                                        *   '<S57>/ENU_FORWARD'
                                        *   '<S69>/ENU_FORWARD'
                                        *   '<S78>/ENU_FORWARD'
                                        */
  25U,                                 /* Variable: ENU_GTSP
                                        * Referenced by: '<S95>/ENU_GTSP'
                                        */
  9U,                                  /* Variable: ENU_LEFT_BUSY_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        */
  14U,                                 /* Variable: ENU_LEFT_BUSY_RIGHT_CLEANED
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_CLEANED'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_CLEANED'
                                        */
  7U,                                  /* Variable: ENU_LEFT_BUSY_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        */
  13U,                                 /* Variable: ENU_LEFT_CLEANED_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_CLEANED_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_CLEANED_RIGHT_BUSY'
                                        */
  12U,                                 /* Variable: ENU_LEFT_CLEANED_RIGHT_CLEANED
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
                                        *   '<S98>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
                                        */
  10U,                                 /* Variable: ENU_LEFT_CLEANED_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_CLEANED_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_CLEANED_RIGHT_EMPTY'
                                        */
  8U,                                  /* Variable: ENU_LEFT_EMPTY_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        */
  11U,                                 /* Variable: ENU_LEFT_EMPTY_RIGHT_CLEANED
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_CLEANED'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_CLEANED'
                                        */
  15U,                                 /* Variable: ENU_LEFT_EMPTY_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        */
  20U,                                 /* Variable: ENU_MOVE_TURN_LEFT
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_TURN_LEFT'
                                        *   '<S127>/ENU_MOVE_TURN_LEFT'
                                        *   '<S102>/ENU_MOVE_TURN_LEFT'
                                        */
  21U,                                 /* Variable: ENU_MOVE_TURN_RIGHT
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_TURN_RIGHT'
                                        *   '<S127>/ENU_MOVE_TURN_RIGHT'
                                        */
  24U,                                 /* Variable: ENU_MOVE_U_TURN
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_U_TURN'
                                        *   '<S98>/ENU_MOVE_U_TURN'
                                        *   '<S127>/ENU_MOVE_U_TURN'
                                        */
  23U,                                 /* Variable: ENU_MOVE_U_TURN_LEFT
                                        * Referenced by:
                                        *   '<S98>/ENU_MOVE_U_TURN_LEFT'
                                        *   '<S127>/ENU_MOVE_U_TURN_LEFT'
                                        */
  22U,                                 /* Variable: ENU_MOVE_U_TURN_RIGHT
                                        * Referenced by:
                                        *   '<S98>/ENU_MOVE_U_TURN_RIGHT'
                                        *   '<S127>/ENU_MOVE_U_TURN_RIGHT'
                                        */
  1U,                                  /* Variable: ENU_PASSED
                                        * Referenced by:
                                        *   '<S90>/ENU_PASSED'
                                        *   '<S102>/ENU_PASSED'
                                        */
  29U,                                 /* Variable: ENU_SHIFT_HEADING
                                        * Referenced by:
                                        *   '<S22>/ENU_SHIFT_HEADING'
                                        *   '<S89>/ENU_SHIFT_HEADING'
                                        */
  5U,                                  /* Variable: ENU_STOP
                                        * Referenced by:
                                        *   '<S22>/ENU_STOP'
                                        *   '<S92>/ENU_STOP'
                                        *   '<S95>/ENU_STOP'
                                        *   '<S98>/ENU_STOP'
                                        *   '<S126>/ENU_STOP'
                                        *   '<S126>/ENU_STOP1'
                                        *   '<S127>/ENU_STOP'
                                        *   '<S145>/ENU_STOP'
                                        *   '<S146>/ENU_STOP'
                                        *   '<S87>/ENU_STOP'
                                        *   '<S88>/ENU_STOP'
                                        *   '<S100>/ENU_STOP'
                                        *   '<S104>/ENU_STOP'
                                        *   '<S106>/moveRequest'
                                        */
  5U,                                  /* Variable: ENU_TEST_INIT
                                        * Referenced by: '<S22>/ENU_TEST_INIT'
                                        */
  3U,                                  /* Variable: ENU_TEST_NOT_CONFIRMED
                                        * Referenced by:
                                        *   '<S90>/Unit_Delay'
                                        *   '<S90>/Unit_Delay1'
                                        *   '<S90>/Unit_Delay2'
                                        *   '<S99>/angleCalibStatus'
                                        *   '<S102>/ENU_TEST_NOT_CONFIRMED'
                                        *   '<S106>/angleCalibStatus'
                                        */
  1,                                   /* Variable: CONST_EnableDelay
                                        * Referenced by:
                                        *   '<S132>/CONST_EnableDelay'
                                        *   '<S132>/CONST_EnableDelay1'
                                        *   '<S71>/CONST_EnableDelay'
                                        *   '<S80>/CONST_EnableDelay'
                                        */
  0,                                   /* Variable: CONST_EndOfLineEnableFlg
                                        * Referenced by:
                                        *   '<S25>/CONST_EndOfLineEnableFlg'
                                        *   '<S25>/CONST_EndOfLineEnableFlg1'
                                        *   '<S25>/CONST_EndOfLineEnableFlg2'
                                        *   '<S49>/CONST_EndOfLineEnableFlg'
                                        */
  0                                    /* Variable: CONST_FALSE
                                        * Referenced by:
                                        *   '<S71>/CONST_FALSE'
                                        *   '<S80>/CONST_FALSE'
                                        */
};
