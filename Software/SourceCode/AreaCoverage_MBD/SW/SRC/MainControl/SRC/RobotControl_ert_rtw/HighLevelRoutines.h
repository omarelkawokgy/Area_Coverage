/*
 * File: HighLevelRoutines.h
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

#ifndef RTW_HEADER_HighLevelRoutines_h_
#define RTW_HEADER_HighLevelRoutines_h_
#include <math.h>
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Block signals for system '<S132>/DeltaDistCalculator' */
#if MotorsEOL_DisabledVariant

typedef struct {
  real32_T deltaDistTrav;              /* '<S132>/DeltaDistCalculator' */
} B_DeltaDistCalculator_RobotCo_T;

#endif                                 /* MotorsEOL_DisabledVariant */

/* Block states (auto storage) for system '<S132>/DeltaDistCalculator' */
#if MotorsEOL_DisabledVariant

typedef struct {
  real32_T tempDist;                   /* '<S132>/DeltaDistCalculator' */
  uint8_T is_active_c42_RobotControl;  /* '<S132>/DeltaDistCalculator' */
  uint8_T is_c42_RobotControl;         /* '<S132>/DeltaDistCalculator' */
} DW_DeltaDistCalculator_RobotC_T;

#endif                                 /* MotorsEOL_DisabledVariant */

/* Block signals for system '<S114>/Diag_Routine_Enabled' */
#if MotorsEOL_DisabledVariant

typedef struct {
  uint16_T OutportBufferForangleCalib_EAST;/* '<S124>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib_NORT;/* '<S124>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib_SOUT;/* '<S124>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib_WEST;/* '<S124>/CompassSelfDiagTestChart' */
  uint16_T NORTH;                      /* '<S124>/CompassSelfDiagTestChart' */
  uint16_T SOUTH;                      /* '<S124>/CompassSelfDiagTestChart' */
  uint16_T EAST;                       /* '<S124>/CompassSelfDiagTestChart' */
  uint16_T WEST;                       /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T OutportBufferForangleCalibStatu;/* '<S124>/CompassSelfDiagTestChart' */
  uint8_T OutportBufferFormoveRequest; /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T moveReq;                     /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T angleCalibStatus;            /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T encoderTstStatus;            /* '<S120>/Switch' */
  uint8_T moveReq_p;                   /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T diagEnableReq;               /* '<S136>/HighLevelDiagTestControl' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator_c;/* '<S134>/DeltaDistCalculator' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator;/* '<S132>/DeltaDistCalculator' */
} B_Diag_Routine_Enabled_RobotC_T;

#endif                                 /* MotorsEOL_DisabledVariant */

/* Block states (auto storage) for system '<S114>/Diag_Routine_Enabled' */
#if MotorsEOL_DisabledVariant

typedef struct {
  uint16_T startHeading;               /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T Unit_Delay1_DSTATE;          /* '<S116>/Unit_Delay1' */
  uint8_T Unit_Delay_DSTATE;           /* '<S116>/Unit_Delay' */
  uint8_T Unit_Delay2_DSTATE;          /* '<S116>/Unit_Delay2' */
  int8_T Switch_Case_ActiveSubsystem;  /* '<S121>/Switch_Case' */
  uint8_T is_active_c39_RobotControl;  /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T is_c39_RobotControl;         /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T temporalCounter_i1;          /* '<S124>/CompassSelfDiagTestChart' */
  uint8_T is_active_c40_RobotControl;  /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T is_c40_RobotControl;         /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T is_turnHandler;              /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T steps;                       /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T filterToleranceCnt;          /* '<S126>/CompassSelfDiagTestChart' */
  uint8_T is_active_c44_RobotControl;  /* '<S136>/HighLevelDiagTestControl' */
  uint8_T is_c44_RobotControl;         /* '<S136>/HighLevelDiagTestControl' */
  uint8_T is_SelfDiag;                 /* '<S136>/HighLevelDiagTestControl' */
  uint8_T temporalCounter_i1_k;        /* '<S136>/HighLevelDiagTestControl' */
  boolean_T angleFinishFlg;            /* '<S124>/CompassSelfDiagTestChart' */
  boolean_T Angle_CalibrationUponReq_MODE;/* '<S117>/Angle_CalibrationUponReq' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator_c;/* '<S134>/DeltaDistCalculator' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator;/* '<S132>/DeltaDistCalculator' */
} DW_Diag_Routine_Enabled_Robot_T;

#endif                                 /* MotorsEOL_DisabledVariant */

#if MotorsEOL_DisabledVariant

extern void RobotC_DeltaDistCalculator_Init(B_DeltaDistCalculator_RobotCo_T
  *localB, DW_DeltaDistCalculator_RobotC_T *localDW);

#endif                                 /* MotorsEOL_DisabledVariant */

#if MotorsEOL_DisabledVariant

extern void RobotContro_DeltaDistCalculator(boolean_T rtu_targetReached,
  real32_T rtu_rightDistTravelled_mm, B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW);

#endif                                 /* MotorsEOL_DisabledVariant */

extern void RobotCon_HighLevelRoutines_Init(void);
extern void RobotCo_HighLevelRoutines_Start(void);
extern void RobotControl_HighLevelRoutines(void);

#endif                                 /* RTW_HEADER_HighLevelRoutines_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
