/*
 * File: Params.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.559
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 13:50:23 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Params_h_
#define RTW_HEADER_Params_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "RobotControl_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CAL_EAST                       0
#define CAL_EncoderAnaThd              100U
#define CAL_EncoderSampleTime          0.001F
#define CAL_ErrorLowerLimit            -2.0F
#define CAL_ErrorUpperLimit            2.0F
#define CAL_FilterResetThd             100
#define CAL_Kd                         0.005F
#define CAL_Ki                         0.003F
#define CAL_Kp                         3.0F
#define CAL_MOTOR_HIGH                 126U
#define CAL_MOTOR_LOW                  0U
#define CAL_MeasNoiseVelKF             0.8F
#define CAL_MeasureNoise               1.2F
#define CAL_NORTH                      270
#define CAL_NORTH_rad                  4.7124F
#define CAL_NO_ERROR                   0U
#define CAL_ProcessNoise               1.5F
#define CAL_PwmMoveThd_mm              180U
#define CAL_ROBO_LENG                  25U
#define CAL_ROBO_LENG_mm               250U
#define CAL_ROB_ERRVAL                 5U
#define CAL_SOUTH                      90
#define CAL_ULS_UnconnectedBlks        10U
#define CAL_WEST                       180
#define CAL_Wheel2WheelDist_mm         250U
#define CAL_WheelDiameter_cm           12U
#define CAL_forwardStartIncr           0.001F
#define CAL_fullCircle_DEG             360U
#define CAL_halfCircle_DEG             180U
#define CAL_hitBackwardDist_mm         150.0F
#define CAL_mm_PER_tick                0.80211F
#define CAL_procNoiseVelKF             2.5F
#define CAL_thetaGain                  100U
#endif                                 /* RTW_HEADER_Params_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
