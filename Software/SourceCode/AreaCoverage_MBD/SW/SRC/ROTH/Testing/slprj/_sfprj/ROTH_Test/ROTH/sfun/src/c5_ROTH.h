#ifndef __c5_ROTH_h__
#define __c5_ROTH_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_ROTHInstanceStruct
#define typedef_SFc5_ROTHInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_GTSP;
  uint8_T c5_tp_init;
  uint8_T c5_tp_ZIGZAG;
  uint8_T c5_tp_End;
  uint8_T c5_is_active_c5_ROTH;
  uint8_T c5_is_c5_ROTH;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  uint8_T *c5_currentRoutine;
  boolean_T *c5_GT_active;
  real_T *c5_ZG_active;
  real_T *c5_GTSP;
  real_T *c5_ZIGZAG;
} SFc5_ROTHInstanceStruct;

#endif                                 /*typedef_SFc5_ROTHInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_ROTH_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_ROTH_get_check_sum(mxArray *plhs[]);
extern void c5_ROTH_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
