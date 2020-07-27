/*
 * Code generation for system system '<S16>/HighLevelRoutines'
 * For more details, see corresponding source file HighLevelRoutines.c
 *
 */

#ifndef RTW_HEADER_HighLevelRoutines_h_
#define RTW_HEADER_HighLevelRoutines_h_
#include <math.h>
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "MW_digitalio.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<S114>/DeltaDistCalculator' */
typedef struct {
  real32_T deltaDistTrav;              /* '<S114>/DeltaDistCalculator' */
} B_DeltaDistCalculator_RobotCo_T;

/* Block states (auto storage) for system '<S114>/DeltaDistCalculator' */
typedef struct {
  real32_T tempDist;                   /* '<S114>/DeltaDistCalculator' */
  uint8_T is_active_c30_ROTH;          /* '<S114>/DeltaDistCalculator' */
  uint8_T is_c30_ROTH;                 /* '<S114>/DeltaDistCalculator' */
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
