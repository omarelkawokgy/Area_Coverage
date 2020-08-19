#ifndef __c13_RobotControl_h__
#define __c13_RobotControl_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_RobotControlInstanceStruct
#define typedef_SFc13_RobotControlInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  uint8_T c13_tp_ReadEEPROM;
  uint8_T c13_tp_UpdateEEPROM;
  uint8_T c13_is_active_c13_RobotControl;
  uint8_T c13_is_c13_RobotControl;
  uint8_T c13_ENU_FINISHED;
  uint8_T c13_doSetSimStateSideEffects;
  const mxArray *c13_setSimStateSideEffectsInfo;
  uint8_T *c13_angleCalibStatus;
  uint16_T *c13_angleCalib_NORTH;
  uint16_T *c13_angleCalib_SOUTH;
  uint16_T *c13_angleCalib_EAST;
  uint16_T *c13_angleCalib_WEST;
  boolean_T *c13_NVM_AngleStoreFlg;
  int16_T *c13_NVM_NORTH;
  int16_T *c13_NVM_SOUTH;
  int16_T *c13_NVM_EAST;
  int16_T *c13_NVM_WEST;
} SFc13_RobotControlInstanceStruct;

#endif                                 /*typedef_SFc13_RobotControlInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_RobotControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_RobotControl_get_check_sum(mxArray *plhs[]);
extern void c13_RobotControl_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
