/*
 * File: Enums.h
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

#ifndef RTW_HEADER_Enums_h_
#define RTW_HEADER_Enums_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "RobotControl_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define ENU_BACKWARD                   2U
#define ENU_CCW                        4U
#define ENU_CW                         3U
#define ENU_DIAG                       28U
#define ENU_END                        27U
#if MotorsEOL_DisabledVariant
#define ENU_FAILED                     2U
#endif                                 /* MotorsEOL_DisabledVariant */

#define ENU_FINISHED                   4U
#define ENU_FORWARD                    1U
#define ENU_GTSP                       25U
#define ENU_LEFT_BUSY_RIGHT_BUSY       9U
#define ENU_LEFT_BUSY_RIGHT_CLEANED    14U
#define ENU_LEFT_BUSY_RIGHT_EMPTY      7U
#define ENU_LEFT_CLEANED_RIGHT_BUSY    13U
#define ENU_LEFT_CLEANED_RIGHT_CLEANED 12U
#define ENU_LEFT_CLEANED_RIGHT_EMPTY   10U
#define ENU_LEFT_EMPTY_RIGHT_BUSY      8U
#define ENU_LEFT_EMPTY_RIGHT_CLEANED   11U
#define ENU_LEFT_EMPTY_RIGHT_EMPTY     15U
#define ENU_MOVE_TURN_LEFT             20U
#define ENU_MOVE_TURN_RIGHT            21U
#define ENU_MOVE_U_TURN                24U
#define ENU_MOVE_U_TURN_LEFT           23U
#define ENU_MOVE_U_TURN_RIGHT          22U
#if MotorsEOL_DisabledVariant
#define ENU_PASSED                     1U
#endif                                 /* MotorsEOL_DisabledVariant */

#define ENU_ROB_NONE                   400U
#define ENU_SHIFT_HEADING              29U
#define ENU_STOP                       5U
#define ENU_TEST_INIT                  5U
#if (motorsHandleEOL_Variant) || (MotorsEOL_DisabledVariant)
#define ENU_TEST_NOT_CONFIRMED         3U
#endif                                 /* (motorsHandleEOL_Variant) || (MotorsEOL_DisabledVariant) */

#define ENU_ZIGZAG                     26U
#endif                                 /* RTW_HEADER_Enums_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
