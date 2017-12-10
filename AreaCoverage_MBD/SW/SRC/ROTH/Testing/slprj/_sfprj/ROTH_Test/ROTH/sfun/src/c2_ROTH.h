#ifndef __c2_ROTH_h__
#define __c2_ROTH_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_ROTHInstanceStruct
#define typedef_SFc2_ROTHInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_SensorViewState;
  uint8_T c2_tp_Init;
  uint8_T c2_tp_NoHit;
  uint8_T c2_is_active_c2_ROTH;
  uint8_T c2_is_c2_ROTH;
  uint8_T c2_currentX;
  uint8_T c2_currentY;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  real_T *c2_c_X;
  real_T *c2_c_Y;
  real_T *c2_pumperHit_BOOL;
  uint8_T *c2_sensorView;
  uint8_T (*c2_map)[361];
  real_T *c2_currentHeading;
  real_T *c2_BUSY;
  real_T *c2_EMPTY;
  real_T *c2_CLEANED;
  real_T *c2_UNCOVERED;
  real_T *c2_LEFT_BUSY_RIGHT_EMPTY;
  real_T *c2_LEFT_CLEANED_RIGHT_EMPTY;
  real_T *c2_LEFT_EMPTY_RIGHT_BUSY;
  real_T *c2_LEFT_EMPTY_RIGHT_CLEANED;
  real_T *c2_LEFT_EMPTY_RIGHT_EMPTY;
  real_T *c2_LEFT_BUSY_RIGHT_BUSY;
  real_T *c2_LEFT_CLEANED_RIGHT_CLEANED;
  real_T *c2_LEFT_BUSY_RIGHT_CLEANED;
  real_T *c2_LEFT_CLEANED_RIGHT_BUSY;
  real_T *c2_ROB_NORTH;
  real_T *c2_ROB_SOUTH;
  real_T *c2_ROB_WEST;
  real_T *c2_ROB_EAST;
} SFc2_ROTHInstanceStruct;

#endif                                 /*typedef_SFc2_ROTHInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_ROTH_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_ROTH_get_check_sum(mxArray *plhs[]);
extern void c2_ROTH_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
