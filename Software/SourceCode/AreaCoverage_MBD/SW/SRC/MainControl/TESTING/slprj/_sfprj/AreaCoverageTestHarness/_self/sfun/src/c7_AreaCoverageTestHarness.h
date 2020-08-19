#ifndef __c7_AreaCoverageTestHarness_h__
#define __c7_AreaCoverageTestHarness_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_AreaCoverageTestHarnessInstanceStruct
#define typedef_SFc7_AreaCoverageTestHarnessInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  uint8_T c7_tp_ReadEEPROM;
  uint8_T c7_tp_UpdateEEPROM;
  uint8_T c7_is_active_c7_AreaCoverageTestHarness;
  uint8_T c7_is_c7_AreaCoverageTestHarness;
  uint8_T c7_ENU_FINISHED;
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
  uint8_T *c7_angleCalibStatus;
  uint16_T *c7_angleCalib_NORTH;
  uint16_T *c7_angleCalib_SOUTH;
  uint16_T *c7_angleCalib_EAST;
  uint16_T *c7_angleCalib_WEST;
  boolean_T *c7_NVM_AngleStoreFlg;
  int16_T *c7_NVM_NORTH;
  int16_T *c7_NVM_SOUTH;
  int16_T *c7_NVM_EAST;
  int16_T *c7_NVM_WEST;
} SFc7_AreaCoverageTestHarnessInstanceStruct;

#endif                                 /*typedef_SFc7_AreaCoverageTestHarnessInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_AreaCoverageTestHarness_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_AreaCoverageTestHarness_get_check_sum(mxArray *plhs[]);
extern void c7_AreaCoverageTestHarness_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
