#ifndef __c8_RobotControl_h__
#define __c8_RobotControl_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_RobotControlInstanceStruct
#define typedef_SFc8_RobotControlInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_RobotControl;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
  uint8_T *c8_pin;
  uint8_T *c8_value;
} SFc8_RobotControlInstanceStruct;

#endif                                 /*typedef_SFc8_RobotControlInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_RobotControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_RobotControl_get_check_sum(mxArray *plhs[]);
extern void c8_RobotControl_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
