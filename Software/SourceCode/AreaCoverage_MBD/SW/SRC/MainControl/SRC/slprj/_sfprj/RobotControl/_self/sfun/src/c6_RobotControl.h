#ifndef __c6_RobotControl_h__
#define __c6_RobotControl_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_RobotControlInstanceStruct
#define typedef_SFc6_RobotControlInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_RobotControl;
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  uint16_T *c6_ULSL_cm;
  uint8_T *c6_ULSL_Pin;
} SFc6_RobotControlInstanceStruct;

#endif                                 /*typedef_SFc6_RobotControlInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_RobotControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_RobotControl_get_check_sum(mxArray *plhs[]);
extern void c6_RobotControl_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
