#ifndef __c1_RobotControl_h__
#define __c1_RobotControl_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_RobotControlInstanceStruct
#define typedef_SFc1_RobotControlInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_RobotControl;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  uint16_T *c1_ULSR_cm;
  uint8_T *c1_ULSR_Pin;
} SFc1_RobotControlInstanceStruct;

#endif                                 /*typedef_SFc1_RobotControlInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_RobotControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_RobotControl_get_check_sum(mxArray *plhs[]);
extern void c1_RobotControl_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
