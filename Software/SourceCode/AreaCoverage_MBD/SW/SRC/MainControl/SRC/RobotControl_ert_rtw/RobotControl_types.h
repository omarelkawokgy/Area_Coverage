/*
 * File: RobotControl_types.h
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

#ifndef RTW_HEADER_RobotControl_types_h_
#define RTW_HEADER_RobotControl_types_h_

/* Includes for objects with custom storage classes. */
#include "../Variant.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef VARIANT_DEBUGGING_ENABLE
#error The variable for the parameter "VARIANT_DEBUGGING_ENABLE" is not defined
#endif

#ifndef VARIANT_LEFT_MOTOR_EOL_ENABLE
#error The variable for the parameter "VARIANT_LEFT_MOTOR_EOL_ENABLE" is not defined
#endif

#ifndef VARIANT_RIGHT_MOTOR_EOL_ENABLE
#error The variable for the parameter "VARIANT_RIGHT_MOTOR_EOL_ENABLE" is not defined
#endif

/* Model Code Variants */
#ifndef MotorsEOL_DisabledVariant
#define MotorsEOL_DisabledVariant      ((VARIANT_LEFT_MOTOR_EOL_ENABLE == 0) && (VARIANT_RIGHT_MOTOR_EOL_ENABLE == 0))
#endif

#ifndef debuggingFlag_variant
#define debuggingFlag_variant          (VARIANT_DEBUGGING_ENABLE == 1)
#endif

#ifndef leftMotorEOL_DisabledVariant
#define leftMotorEOL_DisabledVariant   (VARIANT_LEFT_MOTOR_EOL_ENABLE == 0)
#endif

#ifndef leftMotorEOL_variant
#define leftMotorEOL_variant           ((VARIANT_LEFT_MOTOR_EOL_ENABLE == 1) && (VARIANT_RIGHT_MOTOR_EOL_ENABLE == 0))
#endif

#ifndef motorsHandleEOL_Variant
#define motorsHandleEOL_Variant        ((VARIANT_RIGHT_MOTOR_EOL_ENABLE == 1) || (VARIANT_LEFT_MOTOR_EOL_ENABLE == 1))
#endif

#ifndef rightMotorEOL_DisabledVariant
#define rightMotorEOL_DisabledVariant  (VARIANT_RIGHT_MOTOR_EOL_ENABLE == 0)
#endif

#ifndef rightMotorEOL_variant
#define rightMotorEOL_variant          ((VARIANT_RIGHT_MOTOR_EOL_ENABLE == 1) && (VARIANT_LEFT_MOTOR_EOL_ENABLE == 0))
#endif

#if ((motorsHandleEOL_Variant) ? 1 : 0) + ((MotorsEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for 'RobotControl/RobotControl/RobotControlLib/motorHandler/Variant Source1' should be active
#endif

#if ((motorsHandleEOL_Variant) ? 1 : 0) + ((MotorsEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for 'RobotControl/RobotControl/RobotControlLib/motorHandler/Variant Source2' should be active
#endif

#if ((motorsHandleEOL_Variant) ? 1 : 0) + ((MotorsEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for 'RobotControl/RobotControl/RobotControlLib/motorHandler/Variant Source3' should be active
#endif

#if ((motorsHandleEOL_Variant) ? 1 : 0) + ((MotorsEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for 'RobotControl/RobotControl/RobotControlLib/motorHandler/Variant Source4' should be active
#endif

/* Exactly one variant for '<S57>/LeftEndofLineTest' should be active */
#if ((leftMotorEOL_variant) ? 1 : 0) + ((leftMotorEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for '<S57>/LeftEndofLineTest' should be active
#endif

/* Exactly one variant for '<S57>/rightEndofLineTest1' should be active */
#if ((rightMotorEOL_variant) ? 1 : 0) + ((rightMotorEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for '<S57>/rightEndofLineTest1' should be active
#endif

/* Exactly one variant for '<S105>/Diag_Routine_Variant' should be active */
#if ((motorsHandleEOL_Variant) ? 1 : 0) + ((MotorsEOL_DisabledVariant) ? 1 : 0) != 1
#error Exactly one variant for '<S105>/Diag_Routine_Variant' should be active
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_RobotControl_T RT_MODEL_RobotControl_T;

#endif                                 /* RTW_HEADER_RobotControl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
