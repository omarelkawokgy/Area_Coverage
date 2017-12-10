#ifndef __c4_ROTH_h__
#define __c4_ROTH_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_ROTHInstanceStruct
#define typedef_SFc4_ROTHInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_GTSP_Active;
  uint8_T c4_tp_Forward;
  uint8_T c4_tp_TurnLeft;
  uint8_T c4_tp_preFinishLeftBlockedN;
  uint8_T c4_tp_preFinishLeftBlockedW;
  uint8_T c4_tp_preFinishNormal;
  uint8_T c4_tp_preFinishBlockedW;
  uint8_T c4_tp_preFinishBlockedN;
  uint8_T c4_tp_finishedGTSP;
  uint8_T c4_tp_Idle;
  uint8_T c4_is_active_c4_ROTH;
  uint8_T c4_is_c4_ROTH;
  uint8_T c4_is_GTSP_Active;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  real_T *c4_pumperInterrupt_BOOL;
  uint8_T *c4_currentRoutine;
  real_T *c4_currentHeading;
  real_T *c4_GTSP;
  real_T *c4_FORWARD;
  real_T *c4_LEFT_BUSY_RIGHT_EMPTY;
  real_T *c4_LEFT_CLEANED_RIGHT_EMPTY;
  real_T *c4_LEFT_EMPTY_RIGHT_BUSY;
  real_T *c4_LEFT_EMPTY_RIGHT_CLEANED;
  real_T *c4_LEFT_EMPTY_RIGHT_EMPTY;
  real_T *c4_LEFT_BUSY_RIGHT_BUSY;
  real_T *c4_LEFT_CLEANED_RIGHT_CLEANED;
  real_T *c4_LEFT_BUSY_RIGHT_CLEANED;
  real_T *c4_LEFT_CLEANED_RIGHT_BUSY;
  real_T *c4_ROB_NORTH;
  real_T *c4_ROB_SOUTH;
  real_T *c4_ROB_WEST;
  real_T *c4_ROB_EAST;
  uint8_T *c4_sensorView;
  uint8_T *c4_moveRequest;
  real_T *c4_MOVE_TURN_LEFT;
  real_T *c4_MOVE_TURN_RIGHT;
  real_T *c4_MOVE_U_TURN;
  boolean_T *c4_GT_active;
  real_T *c4_STOP;
} SFc4_ROTHInstanceStruct;

#endif                                 /*typedef_SFc4_ROTHInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_ROTH_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_ROTH_get_check_sum(mxArray *plhs[]);
extern void c4_ROTH_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
