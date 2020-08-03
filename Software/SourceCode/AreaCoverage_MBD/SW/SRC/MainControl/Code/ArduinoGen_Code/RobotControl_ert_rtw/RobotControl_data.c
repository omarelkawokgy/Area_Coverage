/*
 * RobotControl_data.c
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
  0,                                   /* Variable: CONST_FALSE
                                        * Referenced by:
                                        *   '<S71>/CONST_FALSE'
                                        *   '<S80>/CONST_FALSE'
                                        */
  1.0F,                                /* Mask Parameter: Unit_Delay_Enabled_Resettable1_
                                        * Referenced by:
                                        *   '<S75>/Initial Condition'
                                        *   '<S75>/FixPt Unit Delay1'
                                        */
  1.0F,                                /* Mask Parameter: Unit_Delay_Enabled_Resettable_h
                                        * Referenced by:
                                        *   '<S84>/Initial Condition'
                                        *   '<S84>/FixPt Unit Delay1'
                                        */
  0.0F,                                /* Mask Parameter: Unit_Delay_Enabled_Resettable_v
                                        * Referenced by:
                                        *   '<S136>/Initial Condition'
                                        *   '<S136>/FixPt Unit Delay1'
                                        */
  0.0F,                                /* Mask Parameter: Unit_Delay_Enabled_Resettabl_hd
                                        * Referenced by:
                                        *   '<S137>/Initial Condition'
                                        *   '<S137>/FixPt Unit Delay1'
                                        */
  0.001F,                              /* Mask Parameter: Unit_Delay_Resettable_vinit
                                        * Referenced by:
                                        *   '<S147>/Initial Condition'
                                        *   '<S147>/FixPt Unit Delay1'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber_b
                                        * Referenced by: '<S13>/PWM'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber_d
                                        * Referenced by: '<S14>/PWM'
                                        */
  10U,                                 /* Mask Parameter: PWM_pinNumber_bq
                                        * Referenced by: '<S15>/PWM'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/Digital Input'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S33>/Constant2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S33>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S61>/Constant2'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S61>/Constant1'
                                        */
  0.0,                                 /* Computed Parameter: thetaEncodUnfiltered_Y0
                                        * Referenced by: '<S48>/thetaEncodUnfiltered'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S48>/Constant'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S58>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S58>/Constant2'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S61>/Constant3'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S60>/Delay'
                                        */
  0.0,                                 /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S60>/Delay1'
                                        */
  0.20000000298023224,                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S60>/Gain3'
                                        */
  7.0,                                 /* Expression: 7
                                        * Referenced by: '<S9>/DigitalPin7'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S9>/DigitalPin8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S133>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: theta_Deg_Y0
                                        * Referenced by: '<S27>/theta_Deg'
                                        */
  0.0F,                                /* Computed Parameter: theta_mDeg_Y0
                                        * Referenced by: '<S27>/theta_mDeg'
                                        */
  360.0F,                              /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S31>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S31>/Saturation'
                                        */
  1.0F,                                /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S31>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: thetaEncod_Y0
                                        * Referenced by: '<S48>/thetaEncod'
                                        */
  0.0F,                                /* Computed Parameter: Unit_Delay_InitialCondition
                                        * Referenced by: '<S64>/Unit_Delay'
                                        */
  -1.0F,                               /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S69>/Gain2'
                                        */
  -1.0F,                               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S78>/Gain2'
                                        */
  0.0F,                                /* Computed Parameter: leftVel_mmPerSec_Y0
                                        * Referenced by: '<S19>/leftVel_mmPerSec'
                                        */
  0.0F,                                /* Computed Parameter: leftDistTravelled_mm_Y0
                                        * Referenced by: '<S19>/leftDistTravelled_mm'
                                        */
  0.0F,                                /* Computed Parameter: rightVel_mmPerSec_Y0
                                        * Referenced by: '<S19>/rightVel_mmPerSec'
                                        */
  0.0F,                                /* Computed Parameter: rightDistTravelled_mm_Y0
                                        * Referenced by: '<S19>/rightDistTravelled_mm'
                                        */

  /*  Computed Parameter: MotorTransferFunction_NumCoef
   * Referenced by: '<S76>/MotorTransferFunction'
   */
  { 78125.0F, 156250.0F, 78125.0F },

  /*  Expression: [Z2, Z1, Z0]
   * Referenced by: '<S76>/MotorTransferFunction'
   */
  { 951906.25F, -237187.5F, -549093.75F },
  0.0F,                                /* Computed Parameter: MotorTransferFunction_InitialSt
                                        * Referenced by: '<S76>/MotorTransferFunction'
                                        */

  /*  Computed Parameter: MotorTransferFunction_NumCoef_d
   * Referenced by: '<S85>/MotorTransferFunction'
   */
  { 78125.0F, 156250.0F, 78125.0F },

  /*  Expression: [Z2, Z1, Z0]
   * Referenced by: '<S85>/MotorTransferFunction'
   */
  { 951906.25F, -237187.5F, -549093.75F },
  0.0F,                                /* Computed Parameter: MotorTransferFunction_Initial_m
                                        * Referenced by: '<S85>/MotorTransferFunction'
                                        */
  0.0F,                                /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S54>/Delay'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S54>/Delay1'
                                        */
  0.2F,                                /* Expression: single(1/5)
                                        * Referenced by: '<S54>/Gain3'
                                        */
  0.0F,                                /* Computed Parameter: Delay_InitialCondition_l
                                        * Referenced by: '<S55>/Delay'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S55>/Delay1'
                                        */
  0.2F,                                /* Expression: single(1/5)
                                        * Referenced by: '<S55>/Gain3'
                                        */
  -1.0F,                               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S133>/Gain'
                                        */
  0.0F,                                /* Computed Parameter: thetaError_Y0
                                        * Referenced by: '<S22>/thetaError'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S125>/Unit Delay'
                                        */
  2.5F,                                /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S125>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S25>/Saturation'
                                        */
  0U,                                  /* Computed Parameter: A0_p1
                                        * Referenced by: '<S7>/A0'
                                        */
  1U,                                  /* Computed Parameter: A1_p1
                                        * Referenced by: '<S7>/A1'
                                        */
  CAL_FilterResetThd,                  /* Expression: Calib.CAL_FilterResetThd
                                        * Referenced by: '<S31>/CAL_FilterResetThd'
                                        */
  0,                                   /* Computed Parameter: NORTH_Y0
                                        * Referenced by: '<S20>/NORTH'
                                        */
  0,                                   /* Computed Parameter: SOUTH_Y0
                                        * Referenced by: '<S20>/SOUTH'
                                        */
  0,                                   /* Computed Parameter: EAST_Y0
                                        * Referenced by: '<S20>/EAST'
                                        */
  0,                                   /* Computed Parameter: WEST_Y0
                                        * Referenced by: '<S20>/WEST'
                                        */
  0,                                   /* Computed Parameter: thetaCompass_Y0
                                        * Referenced by: '<S5>/thetaCompass'
                                        */
  0,                                   /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S142>/Delay'
                                        */
  0,                                   /* Computed Parameter: Delay1_InitialCondition_m
                                        * Referenced by: '<S142>/Delay1'
                                        */
  0,                                   /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S141>/Delay'
                                        */
  0,                                   /* Computed Parameter: Delay1_InitialCondition_f
                                        * Referenced by: '<S141>/Delay1'
                                        */
  0,                                   /* Computed Parameter: OP_Vl_Y0
                                        * Referenced by: '<S25>/OP_Vl'
                                        */
  0,                                   /* Computed Parameter: OP_Vr_Y0
                                        * Referenced by: '<S25>/OP_Vr'
                                        */
  1U,                                  /* Computed Parameter: Resettable_Delay_DelayLength
                                        * Referenced by: '<S31>/Resettable_Delay'
                                        */
  1U,                                  /* Computed Parameter: Resettable_Delay1_DelayLength
                                        * Referenced by: '<S31>/Resettable_Delay1'
                                        */
  0U,                                  /* Computed Parameter: rightEncoderTicks_BOOL_Y0
                                        * Referenced by: '<S7>/rightEncoderTicks_BOOL'
                                        */
  0U,                                  /* Computed Parameter: leftEncoderTicks_BOOL_Y0
                                        * Referenced by: '<S7>/leftEncoderTicks_BOOL'
                                        */
  5U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S60>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S60>/Delay1'
                                        */
  0U,                                  /* Computed Parameter: encoderCounter_Y0
                                        * Referenced by: '<S64>/encoderCounter'
                                        */
  0U,                                  /* Computed Parameter: encoderCounter_Y0_b
                                        * Referenced by: '<S65>/encoderCounter'
                                        */
  5U,                                  /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S54>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_h
                                        * Referenced by: '<S54>/Delay1'
                                        */
  5U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S55>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_n
                                        * Referenced by: '<S55>/Delay1'
                                        */
  0U,                                  /* Computed Parameter: ULSL_cm_Y0
                                        * Referenced by: '<S9>/ULSL_cm'
                                        */
  0U,                                  /* Computed Parameter: ULSR_cm_Y0
                                        * Referenced by: '<S9>/ULSR_cm'
                                        */
  0U,                                  /* Computed Parameter: leftBlocks_Y0
                                        * Referenced by: '<S23>/leftBlocks'
                                        */
  0U,                                  /* Computed Parameter: rightBlocks_Y0
                                        * Referenced by: '<S23>/rightBlocks'
                                        */
  4U,                                  /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S142>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_j
                                        * Referenced by: '<S142>/Delay1'
                                        */
  4U,                                  /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S141>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_h4
                                        * Referenced by: '<S141>/Delay1'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_NORTH_Y0
                                        * Referenced by: '<S106>/angleCalib_NORTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_SOUTH_Y0
                                        * Referenced by: '<S106>/angleCalib_SOUTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_EAST_Y0
                                        * Referenced by: '<S106>/angleCalib_EAST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_WEST_Y0
                                        * Referenced by: '<S106>/angleCalib_WEST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_NORTH_Y0_g
                                        * Referenced by: '<S99>/angleCalib_NORTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_SOUTH_Y0_j
                                        * Referenced by: '<S99>/angleCalib_SOUTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_EAST_Y0_h
                                        * Referenced by: '<S99>/angleCalib_EAST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_WEST_Y0_o
                                        * Referenced by: '<S99>/angleCalib_WEST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_NORTH_Y0_e
                                        * Referenced by: '<S90>/angleCalib_NORTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_SOUTH_Y0_g
                                        * Referenced by: '<S90>/angleCalib_SOUTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_EAST_Y0_e
                                        * Referenced by: '<S90>/angleCalib_EAST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_WEST_Y0_m
                                        * Referenced by: '<S90>/angleCalib_WEST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_NORTH_Y0_p
                                        * Referenced by: '<S21>/angleCalib_NORTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_SOUTH_Y0_d
                                        * Referenced by: '<S21>/angleCalib_SOUTH'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_EAST_Y0_l
                                        * Referenced by: '<S21>/angleCalib_EAST'
                                        */
  0U,                                  /* Computed Parameter: angleCalib_WEST_Y0_f
                                        * Referenced by: '<S21>/angleCalib_WEST'
                                        */
  24672,                               /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S72>/Gain'
                                        */
  24672,                               /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S81>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain3_Gain_i
                                        * Referenced by: '<S142>/Gain3'
                                        */
  16384,                               /* Computed Parameter: Gain3_Gain_e3
                                        * Referenced by: '<S141>/Gain3'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay5_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay5'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay6_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay6'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay7_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay7'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay8_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay8'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                        * Referenced by: '<S75>/FixPt Unit Delay2'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialCondit_i
                                        * Referenced by: '<S84>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay2_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay2'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S75>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value_b
                                        * Referenced by: '<S84>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: rightMotorRequest_Y0
                                        * Referenced by: '<S22>/rightMotorRequest'
                                        */
  0U,                                  /* Computed Parameter: leftMotorRequest_Y0
                                        * Referenced by: '<S22>/leftMotorRequest'
                                        */
  0U,                                  /* Computed Parameter: turnRequest1_Y0
                                        * Referenced by: '<S22>/turnRequest1'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay5_InitialCondition_c
                                        * Referenced by: '<S22>/Unit_Delay5'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialCondit_j
                                        * Referenced by: '<S136>/FixPt Unit Delay2'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialCondit_k
                                        * Referenced by: '<S137>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S136>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value_f
                                        * Referenced by: '<S137>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: swLaneCnt_uint8_Y0
                                        * Referenced by: '<S98>/swLaneCnt_uint8'
                                        */
  0U,                                  /* Computed Parameter: encoderTstStatus_Y0
                                        * Referenced by: '<S102>/encoderTstStatus'
                                        */
  0U,                                  /* Computed Parameter: moveRequest_Y0
                                        * Referenced by: '<S21>/moveRequest'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay3_InitialCondition
                                        * Referenced by: '<S21>/Unit_Delay3'
                                        */
  0U,                                  /* Computed Parameter: Unit_Delay2_InitialCondition_e
                                        * Referenced by: '<S21>/Unit_Delay2'
                                        */
  5U,                                  /* Expression: ENU_STOP
                                        * Referenced by: '<S21>/Merge'
                                        */
  0U,                                  /* Computed Parameter: leftPosPin_Y0
                                        * Referenced by: '<S25>/leftPosPin'
                                        */
  0U,                                  /* Computed Parameter: leftNegPin_Y0
                                        * Referenced by: '<S25>/leftNegPin'
                                        */
  0U,                                  /* Computed Parameter: rightPosPin_Y0
                                        * Referenced by: '<S25>/rightPosPin'
                                        */
  0U,                                  /* Computed Parameter: rightNegPin_Y0
                                        * Referenced by: '<S25>/rightNegPin'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialCondit_m
                                        * Referenced by: '<S147>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value_m
                                        * Referenced by: '<S147>/FixPt Constant'
                                        */
  0,                                   /* Computed Parameter: Unit_Delay3_InitialCondition_b
                                        * Referenced by: '<S27>/Unit_Delay3'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S47>/false1'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<S47>/true1'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S47>/false'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<S47>/true'
                                        */
  1,                                   /* Computed Parameter: Unit_Delay_InitialCondition_c
                                        * Referenced by: '<S62>/Unit_Delay'
                                        */
  0,                                   /* Computed Parameter: Unit_Delay4_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay4'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S89>/Constant1'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<S89>/Constant'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_g
                                        * Referenced by: '<S89>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: posStopReq_Y0
                                        * Referenced by: '<S23>/posStopReq'
                                        */
  0,                                   /* Computed Parameter: targetReached_Y0
                                        * Referenced by: '<S22>/targetReached'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S22>/Unit_Delay1'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S22>/Unit_Delay2'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S22>/Unit_Delay3'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<S98>/zgzgActive'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S98>/switchLaneFlg_BOOL'
                                        */
  0,                                   /* Computed Parameter: GT_active_Y0
                                        * Referenced by: '<S95>/GT_active'
                                        */
  0,                                   /* Computed Parameter: rightEncodDistErrorFlg_BOOL_Y0
                                        * Referenced by: '<S102>/rightEncodDistErrorFlg_BOOL'
                                        */
  0,                                   /* Computed Parameter: leftEncodDistErrorFlg_BOOL_Y0
                                        * Referenced by: '<S102>/leftEncodDistErrorFlg_BOOL'
                                        */
  0,                                   /* Computed Parameter: hardwareFaultFlg_Y0
                                        * Referenced by: '<S90>/hardwareFaultFlg'
                                        */
  0,                                   /* Computed Parameter: enableAngleCalib_BOOL_Y0
                                        * Referenced by: '<S90>/enableAngleCalib_BOOL'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S21>/switchLaneFlg_BOOL'
                                        */
  0,                                   /* Computed Parameter: diagSensorFailure_Y0
                                        * Referenced by: '<S21>/diagSensorFailure'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<S21>/Unit_Delay'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<S21>/Unit_Delay1'
                                        */
  0,                                   /* Computed Parameter: failFlag_Y0
                                        * Referenced by: '<S18>/failFlag'
                                        */
  0,                                   /* Computed Parameter: ULSL_NotConnectedFlag_BOOL_Y0
                                        * Referenced by: '<S18>/ULSL_NotConnectedFlag_BOOL'
                                        */
  0,                                   /* Computed Parameter: ULSR_NotConnectedFlag_BOOL_Y0
                                        * Referenced by: '<S18>/ULSR_NotConnectedFlag_BOOL'
                                        */
  0,                                   /* Computed Parameter: redLED_BOOL_Y0
                                        * Referenced by: '<S18>/redLED_BOOL'
                                        */
  0,                                   /* Computed Parameter: greenLED_BOOL_Y0
                                        * Referenced by: '<S18>/greenLED_BOOL'
                                        */
  160U,                                /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S72>/Gain1'
                                        */
  160U,                                /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S81>/Gain1'
                                        */

  /* Start of '<S53>/EncoderIncrement' */
  {
    0,                                 /* Computed Parameter: distCounter_Y0
                                        * Referenced by: '<S57>/distCounter'
                                        */
    0                                  /* Computed Parameter: Unit_Delay_InitialCondition
                                        * Referenced by: '<S57>/Unit_Delay'
                                        */
  }
  /* End of '<S53>/EncoderIncrement' */
  ,

  /* Start of '<S52>/EncoderIncrement' */
  {
    0,                                 /* Computed Parameter: distCounter_Y0
                                        * Referenced by: '<S56>/distCounter'
                                        */
    0                                  /* Computed Parameter: Unit_Delay_InitialCondition
                                        * Referenced by: '<S56>/Unit_Delay'
                                        */
  }
  /* End of '<S52>/EncoderIncrement' */
};
