/*
 * File: HighLevelRoutines.h
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

#ifndef RTW_HEADER_HighLevelRoutines_h_
#define RTW_HEADER_HighLevelRoutines_h_
#include <math.h>
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Block signals for system '<S119>/DeltaDistCalculator' */
typedef struct {
  real32_T deltaDistTrav;              /* '<S119>/DeltaDistCalculator' */
} B_DeltaDistCalculator_RobotCo_T;

/* Block states (auto storage) for system '<S119>/DeltaDistCalculator' */
typedef struct {
  real32_T tempDist;                   /* '<S119>/DeltaDistCalculator' */
  uint8_T is_active_c30_ROTH;          /* '<S119>/DeltaDistCalculator' */
  uint8_T is_c30_ROTH;                 /* '<S119>/DeltaDistCalculator' */
} DW_DeltaDistCalculator_RobotC_T;

extern void RobotC_DeltaDistCalculator_Init(B_DeltaDistCalculator_RobotCo_T
  *localB, DW_DeltaDistCalculator_RobotC_T *localDW);
extern void RobotContro_DeltaDistCalculator(boolean_T rtu_targetReached,
  real32_T rtu_rightDistTravelled_mm, B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW);
extern void RobotCon_HighLevelRoutines_Init(void);
extern void RobotCo_HighLevelRoutines_Start(void);
extern void RobotControl_HighLevelRoutines(void);

#endif                                 /* RTW_HEADER_HighLevelRoutines_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
