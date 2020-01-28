/* Include files */

#include "ROTH_sfun.h"
#include "c2_ROTH.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ROTH_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_Init                     ((uint8_T)1U)
#define c2_IN_NoHit                    ((uint8_T)2U)
#define c2_IN_SensorViewState          ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void initialize_params_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void enable_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void disable_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance);
static void set_sim_state_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance, const
  mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance);
static void finalize_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void sf_gateway_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void mdl_start_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void initSimStructsc2_ROTH(SFc2_ROTHInstanceStruct *chartInstance);
static void c2_NoHit(SFc2_ROTHInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance,
  const mxArray *c2_b_tp_SensorViewState, const char_T *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_emlrt_marshallIn(SFc2_ROTHInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_e_emlrt_marshallIn(SFc2_ROTHInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc2_ROTHInstanceStruct
  *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory(SFc2_ROTHInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc2_ROTHInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_ROTHInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_ROTH(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_Init = 0U;
  chartInstance->c2_tp_NoHit = 0U;
  chartInstance->c2_tp_SensorViewState = 0U;
  chartInstance->c2_is_active_c2_ROTH = 0U;
  chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_currentX = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentX, 0U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_currentY = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentY, 1U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c2_sensorView = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void initialize_params_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_ROTH == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_ROTH == c2_IN_SensorViewState) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_ROTH == c2_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_ROTH == c2_IN_NoHit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_sensorView;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_currentX;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_currentY;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_ROTH;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_c2_ROTH;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_sensorView = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("sensorView", c2_u, 0)), "sensorView");
  chartInstance->c2_currentX = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("currentX", c2_u, 1)), "currentX");
  chartInstance->c2_currentY = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("currentY", c2_u, 2)), "currentY");
  chartInstance->c2_is_active_c2_ROTH = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c2_ROTH", c2_u, 3)),
    "is_active_c2_ROTH");
  chartInstance->c2_is_c2_ROTH = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_c2_ROTH", c2_u, 4)), "is_c2_ROTH");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c2_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_ROTH(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_ROTH(SFc2_ROTHInstanceStruct
  *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_tp_Init = (uint8_T)(chartInstance->c2_is_c2_ROTH ==
      c2_IN_Init);
    chartInstance->c2_tp_NoHit = (uint8_T)(chartInstance->c2_is_c2_ROTH ==
      c2_IN_NoHit);
    chartInstance->c2_tp_SensorViewState = (uint8_T)
      (chartInstance->c2_is_c2_ROTH == c2_IN_SensorViewState);
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  real_T c2_d0;
  real_T c2_d1;
  uint8_T c2_u0;
  uint8_T c2_u1;
  real_T c2_d2;
  real_T c2_d3;
  uint8_T c2_u2;
  uint8_T c2_u3;
  c2_set_sim_state_side_effects_c2_ROTH(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ROB_EAST, 23U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ROB_WEST, 22U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ROB_SOUTH, 21U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ROB_NORTH, 20U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_CLEANED_RIGHT_BUSY, 19U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_BUSY_RIGHT_CLEANED, 18U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_CLEANED_RIGHT_CLEANED, 17U, 1U,
                        0U, chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_BUSY_RIGHT_BUSY, 16U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_EMPTY_RIGHT_EMPTY, 15U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_EMPTY_RIGHT_CLEANED, 14U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_EMPTY_RIGHT_BUSY, 13U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_CLEANED_RIGHT_EMPTY, 12U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LEFT_BUSY_RIGHT_EMPTY, 11U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_UNCOVERED, 10U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_CLEANED, 9U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EMPTY, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_BUSY, 7U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_currentHeading, 6U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  for (c2_i0 = 0; c2_i0 < 361; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_map)[c2_i0], 5U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_pumperHit_BOOL, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_c_Y, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_c_X, 2U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_ROTH == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_ROTH = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_ROTH = c2_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Init = 1U;
    *chartInstance->c2_sensorView = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 4U, 0U,
                          chartInstance->c2_sfEvent, false);
  } else {
    switch (chartInstance->c2_is_c2_ROTH) {
     case c2_IN_Init:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_Init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_ROTH = c2_IN_NoHit;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_NoHit = 1U;
      c2_d0 = *chartInstance->c2_c_Y - 1.0;
      if (c2_d0 < 256.0) {
        if (CV_SATURATION_EVAL(4, 1, 0, 1, c2_d0 >= 0.0)) {
          c2_u0 = (uint8_T)c2_d0;
        } else {
          c2_u0 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 1, 0, 0, c2_d0 >= 256.0)) {
        c2_u0 = MAX_uint8_T;
      } else {
        c2_u0 = 0U;
      }

      chartInstance->c2_currentY = c2_u0;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentY, 1U, 4U, 1U,
                            chartInstance->c2_sfEvent, false);
      c2_d2 = *chartInstance->c2_c_X - 1.0;
      if (c2_d2 < 256.0) {
        if (CV_SATURATION_EVAL(4, 1, 1, 1, c2_d2 >= 0.0)) {
          c2_u2 = (uint8_T)c2_d2;
        } else {
          c2_u2 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 1, 1, 0, c2_d2 >= 256.0)) {
        c2_u2 = MAX_uint8_T;
      } else {
        c2_u2 = 0U;
      }

      chartInstance->c2_currentX = c2_u2;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentX, 0U, 4U, 1U,
                            chartInstance->c2_sfEvent, false);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_NoHit:
      CV_CHART_EVAL(0, 0, 2);
      c2_NoHit(chartInstance);
      break;

     case c2_IN_SensorViewState:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_SensorViewState = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_ROTH = c2_IN_NoHit;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_NoHit = 1U;
      c2_d1 = *chartInstance->c2_c_Y - 1.0;
      if (c2_d1 < 256.0) {
        if (CV_SATURATION_EVAL(4, 1, 0, 1, c2_d1 >= 0.0)) {
          c2_u1 = (uint8_T)c2_d1;
        } else {
          c2_u1 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 1, 0, 0, c2_d1 >= 256.0)) {
        c2_u1 = MAX_uint8_T;
      } else {
        c2_u1 = 0U;
      }

      chartInstance->c2_currentY = c2_u1;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentY, 1U, 4U, 1U,
                            chartInstance->c2_sfEvent, false);
      c2_d3 = *chartInstance->c2_c_X - 1.0;
      if (c2_d3 < 256.0) {
        if (CV_SATURATION_EVAL(4, 1, 1, 1, c2_d3 >= 0.0)) {
          c2_u3 = (uint8_T)c2_d3;
        } else {
          c2_u3 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 1, 1, 0, c2_d3 >= 256.0)) {
        c2_u3 = MAX_uint8_T;
      } else {
        c2_u3 = 0U;
      }

      chartInstance->c2_currentX = c2_u3;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_currentX, 0U, 4U, 1U,
                            chartInstance->c2_sfEvent, false);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ROTHMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  c2_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc2_ROTH(SFc2_ROTHInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_NoHit(SFc2_ROTHInstanceStruct *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  real_T c2_d4;
  boolean_T c2_temp;
  real_T c2_d5;
  boolean_T c2_d_out;
  real_T c2_d6;
  boolean_T c2_e_out;
  boolean_T c2_b_temp;
  boolean_T c2_c_temp;
  real_T c2_d7;
  boolean_T c2_f_out;
  real_T c2_d8;
  real_T c2_d9;
  boolean_T c2_g_out;
  boolean_T c2_d_temp;
  boolean_T c2_e_temp;
  real_T c2_d10;
  real_T c2_d11;
  real_T c2_d12;
  boolean_T c2_h_out;
  boolean_T c2_f_temp;
  real_T c2_d13;
  boolean_T c2_g_temp;
  real_T c2_d14;
  real_T c2_d15;
  real_T c2_d16;
  uint8_T c2_u4;
  boolean_T c2_i_out;
  boolean_T c2_h_temp;
  real_T c2_d17;
  boolean_T c2_i_temp;
  real_T c2_d18;
  real_T c2_d19;
  real_T c2_d20;
  uint8_T c2_u5;
  boolean_T c2_j_temp;
  real_T c2_d21;
  boolean_T c2_k_temp;
  real_T c2_d22;
  real_T c2_d23;
  boolean_T c2_j_out;
  uint8_T c2_u6;
  boolean_T c2_k_out;
  real_T c2_d24;
  real_T c2_d25;
  real_T c2_d26;
  uint8_T c2_u7;
  boolean_T c2_l_temp;
  boolean_T c2_m_temp;
  real_T c2_d27;
  real_T c2_d28;
  boolean_T c2_l_out;
  boolean_T c2_n_temp;
  real_T c2_d29;
  boolean_T c2_o_temp;
  real_T c2_d30;
  real_T c2_d31;
  real_T c2_d32;
  real_T c2_d33;
  uint8_T c2_u8;
  boolean_T c2_m_out;
  boolean_T c2_p_temp;
  uint8_T c2_u9;
  boolean_T c2_q_temp;
  real_T c2_d34;
  real_T c2_d35;
  real_T c2_d36;
  boolean_T c2_r_temp;
  real_T c2_d37;
  boolean_T c2_s_temp;
  real_T c2_d38;
  real_T c2_d39;
  boolean_T c2_n_out;
  boolean_T c2_t_temp;
  uint8_T c2_u10;
  boolean_T c2_u_temp;
  real_T c2_d40;
  real_T c2_d41;
  real_T c2_d42;
  real_T c2_d43;
  boolean_T c2_o_out;
  uint8_T c2_u11;
  boolean_T c2_v_temp;
  real_T c2_d44;
  real_T c2_d45;
  boolean_T c2_p_out;
  real_T c2_d46;
  boolean_T c2_w_temp;
  real_T c2_d47;
  real_T c2_d48;
  uint8_T c2_u12;
  boolean_T c2_q_out;
  boolean_T c2_x_temp;
  real_T c2_d49;
  boolean_T c2_y_temp;
  real_T c2_d50;
  real_T c2_d51;
  real_T c2_d52;
  uint8_T c2_u13;
  boolean_T c2_r_out;
  real_T c2_d53;
  boolean_T c2_ab_temp;
  real_T c2_d54;
  real_T c2_d55;
  uint8_T c2_u14;
  boolean_T c2_s_out;
  real_T c2_d56;
  boolean_T c2_bb_temp;
  real_T c2_d57;
  real_T c2_d58;
  uint8_T c2_u15;
  boolean_T c2_t_out;
  real_T c2_d59;
  boolean_T c2_cb_temp;
  real_T c2_d60;
  real_T c2_d61;
  uint8_T c2_u16;
  boolean_T c2_u_out;
  real_T c2_d62;
  boolean_T c2_db_temp;
  real_T c2_d63;
  real_T c2_d64;
  uint8_T c2_u17;
  boolean_T c2_v_out;
  real_T c2_d65;
  boolean_T c2_eb_temp;
  real_T c2_d66;
  uint8_T c2_u18;
  boolean_T c2_w_out;
  real_T c2_d67;
  uint8_T c2_u19;
  real_T c2_d68;
  uint8_T c2_u20;
  real_T c2_d69;
  uint8_T c2_u21;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
              *chartInstance->c2_pumperHit_BOOL != 0U, chartInstance->c2_sfEvent))
            != 0);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c2_sfEvent);
    c2_b_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
      CV_RELATIONAL_EVAL(5U, 2U, 0, *chartInstance->c2_currentHeading,
                         *chartInstance->c2_ROB_NORTH, -1, 0U,
                         *chartInstance->c2_currentHeading ==
                         *chartInstance->c2_ROB_NORTH) != 0U,
      chartInstance->c2_sfEvent)) != 0);
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c2_sfEvent);
      c2_d4 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 17U, 2, 3, 5U, (int32_T)
         chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 17U, 2, 3, 5U,
         chartInstance->c2_currentX - 1, 0, 18)];
      c2_temp = (_SFD_CCP_CALL(6U, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, c2_d4,
        *chartInstance->c2_BUSY, -1, 0U, c2_d4 == *chartInstance->c2_BUSY) != 0U,
                  chartInstance->c2_sfEvent) != 0);
      if (c2_temp) {
        c2_d5 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 17U, 49, 3, 5U,
           (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
          sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
          17U, 49, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
        c2_b_temp = (_SFD_CCP_CALL(6U, 1, CV_RELATIONAL_EVAL(5U, 6U, 1, c2_d5,
          *chartInstance->c2_EMPTY, -1, 0U, c2_d5 == *chartInstance->c2_EMPTY)
          != 0U, chartInstance->c2_sfEvent) != 0);
        if (!c2_b_temp) {
          c2_d7 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            17U, 95, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            17U, 95, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
          c2_b_temp = (_SFD_CCP_CALL(6U, 2, CV_RELATIONAL_EVAL(5U, 6U, 2, c2_d7,
            *chartInstance->c2_UNCOVERED, -1, 0U, c2_d7 ==
            *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_temp = c2_b_temp;
      }

      c2_e_out = (CV_TRANSITION_EVAL(6U, (int32_T)c2_temp) != 0);
      if (c2_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_NoHit = 0U;
        chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 6U,
                     chartInstance->c2_sfEvent);
        c2_d13 = *chartInstance->c2_LEFT_BUSY_RIGHT_EMPTY;
        if (c2_d13 < 256.0) {
          if (CV_SATURATION_EVAL(5, 6, 0, 1, c2_d13 >= 0.0)) {
            c2_u4 = (uint8_T)c2_d13;
          } else {
            c2_u4 = 0U;
          }
        } else if (CV_SATURATION_EVAL(5, 6, 0, 0, c2_d13 >= 256.0)) {
          c2_u4 = MAX_uint8_T;
        } else {
          c2_u4 = 0U;
        }

        *chartInstance->c2_sensorView = c2_u4;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U, 6U,
                              chartInstance->c2_sfEvent, false);
        chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_SensorViewState = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c2_sfEvent);
        c2_d9 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 18U, 2, 3, 5U,
           (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
          sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
          18U, 2, 3, 5U, chartInstance->c2_currentX - 1, 0, 18)];
        c2_e_temp = (_SFD_CCP_CALL(7U, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, c2_d9,
          *chartInstance->c2_CLEANED, -1, 0U, c2_d9 ==
          *chartInstance->c2_CLEANED) != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_e_temp) {
          c2_d11 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            18U, 51, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            18U, 51, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
          c2_f_temp = (_SFD_CCP_CALL(7U, 1, CV_RELATIONAL_EVAL(5U, 7U, 1, c2_d11,
            *chartInstance->c2_EMPTY, -1, 0U, c2_d11 == *chartInstance->c2_EMPTY)
            != 0U, chartInstance->c2_sfEvent) != 0);
          if (!c2_f_temp) {
            c2_d14 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 18U, 96, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 18U, 96, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_f_temp = (_SFD_CCP_CALL(7U, 2, CV_RELATIONAL_EVAL(5U, 7U, 2,
              c2_d14, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d14 ==
              *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent) !=
                         0);
          }

          c2_e_temp = c2_f_temp;
        }

        c2_h_out = (CV_TRANSITION_EVAL(7U, (int32_T)c2_e_temp) != 0);
        if (c2_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_NoHit = 0U;
          chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 7U,
                       chartInstance->c2_sfEvent);
          c2_d21 = *chartInstance->c2_LEFT_CLEANED_RIGHT_EMPTY;
          if (c2_d21 < 256.0) {
            if (CV_SATURATION_EVAL(5, 7, 0, 1, c2_d21 >= 0.0)) {
              c2_u6 = (uint8_T)c2_d21;
            } else {
              c2_u6 = 0U;
            }
          } else if (CV_SATURATION_EVAL(5, 7, 0, 0, c2_d21 >= 256.0)) {
            c2_u6 = MAX_uint8_T;
          } else {
            c2_u6 = 0U;
          }

          *chartInstance->c2_sensorView = c2_u6;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U,
                                7U, chartInstance->c2_sfEvent, false);
          chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_SensorViewState = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       chartInstance->c2_sfEvent);
          c2_d16 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            19U, 3, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            19U, 3, 3, 5U, chartInstance->c2_currentX - 1, 0, 18)];
          c2_i_temp = (_SFD_CCP_CALL(8U, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, c2_d16,
            *chartInstance->c2_EMPTY, -1, 0U, c2_d16 == *chartInstance->c2_EMPTY)
            != 0U, chartInstance->c2_sfEvent) != 0);
          if (!c2_i_temp) {
            c2_d19 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 19U, 49, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 19U, 49, 3, 5U,
               chartInstance->c2_currentX - 1, 0, 18)];
            c2_i_temp = (_SFD_CCP_CALL(8U, 1, CV_RELATIONAL_EVAL(5U, 8U, 1,
              c2_d19, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d19 ==
              *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent) !=
                         0);
          }

          c2_j_temp = c2_i_temp;
          if (c2_j_temp) {
            c2_d22 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 19U, 99, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 19U, 99, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_j_temp = (_SFD_CCP_CALL(8U, 2, CV_RELATIONAL_EVAL(5U, 8U, 2,
              c2_d22, *chartInstance->c2_BUSY, -1, 0U, c2_d22 ==
              *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent) != 0);
          }

          c2_j_out = (CV_TRANSITION_EVAL(8U, (int32_T)c2_j_temp) != 0);
          if (c2_j_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_NoHit = 0U;
            chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 8U,
                         chartInstance->c2_sfEvent);
            c2_d29 = *chartInstance->c2_LEFT_EMPTY_RIGHT_BUSY;
            if (c2_d29 < 256.0) {
              if (CV_SATURATION_EVAL(5, 8, 0, 1, c2_d29 >= 0.0)) {
                c2_u8 = (uint8_T)c2_d29;
              } else {
                c2_u8 = 0U;
              }
            } else if (CV_SATURATION_EVAL(5, 8, 0, 0, c2_d29 >= 256.0)) {
              c2_u8 = MAX_uint8_T;
            } else {
              c2_u8 = 0U;
            }

            *chartInstance->c2_sensorView = c2_u8;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U,
                                  8U, chartInstance->c2_sfEvent, false);
            chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_SensorViewState = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                         chartInstance->c2_sfEvent);
            c2_d25 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 20U, 2, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 20U, 2, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_l_temp = (_SFD_CCP_CALL(9U, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              c2_d25, *chartInstance->c2_CLEANED, -1, 0U, c2_d25 ==
              *chartInstance->c2_CLEANED) != 0U, chartInstance->c2_sfEvent) != 0);
            if (c2_l_temp) {
              c2_d27 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 20U, 51, 3, 5U, (int32_T)
                chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 20U, 51, 3, 5U,
                 chartInstance->c2_currentX - 1, 0, 18)];
              c2_n_temp = (_SFD_CCP_CALL(9U, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
                c2_d27, *chartInstance->c2_EMPTY, -1, 0U, c2_d27 ==
                *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
              if (!c2_n_temp) {
                c2_d31 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 20U, 96, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 20U, 96, 3, 5U, chartInstance->c2_currentX -
                  1, 0, 18)];
                c2_n_temp = (_SFD_CCP_CALL(9U, 2, CV_RELATIONAL_EVAL(5U, 9U, 2,
                  c2_d31, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d31 ==
                  *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent)
                             != 0);
              }

              c2_l_temp = c2_n_temp;
            }

            c2_l_out = (CV_TRANSITION_EVAL(9U, (int32_T)c2_l_temp) != 0);
            if (c2_l_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_NoHit = 0U;
              chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 9U,
                           chartInstance->c2_sfEvent);
              c2_d37 = *chartInstance->c2_LEFT_EMPTY_RIGHT_CLEANED;
              if (c2_d37 < 256.0) {
                if (CV_SATURATION_EVAL(5, 9, 0, 1, c2_d37 >= 0.0)) {
                  c2_u10 = (uint8_T)c2_d37;
                } else {
                  c2_u10 = 0U;
                }
              } else if (CV_SATURATION_EVAL(5, 9, 0, 0, c2_d37 >= 256.0)) {
                c2_u10 = MAX_uint8_T;
              } else {
                c2_u10 = 0U;
              }

              *chartInstance->c2_sensorView = c2_u10;
              _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U,
                                    5U, 9U, chartInstance->c2_sfEvent, false);
              chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_SensorViewState = 1U;
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                           chartInstance->c2_sfEvent);
              c2_d33 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 21U, 3, 3, 5U, (int32_T)
                chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 21U, 3, 3, 5U,
                 chartInstance->c2_currentX + 1, 0, 18)];
              c2_q_temp = (_SFD_CCP_CALL(10U, 0, CV_RELATIONAL_EVAL(5U, 10U, 0,
                c2_d33, *chartInstance->c2_EMPTY, -1, 0U, c2_d33 ==
                *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
              if (!c2_q_temp) {
                c2_d35 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 21U, 49, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 21U, 49, 3, 5U, chartInstance->c2_currentX +
                  1, 0, 18)];
                c2_q_temp = (_SFD_CCP_CALL(10U, 1, CV_RELATIONAL_EVAL(5U, 10U, 1,
                  c2_d35, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d35 ==
                  *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent)
                             != 0);
              }

              c2_r_temp = c2_q_temp;
              if (c2_r_temp) {
                c2_d38 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 21U, 100, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 21U, 100, 3, 5U, chartInstance->c2_currentX
                  - 1, 0, 18)];
                c2_t_temp = (_SFD_CCP_CALL(10U, 2, CV_RELATIONAL_EVAL(5U, 10U, 2,
                  c2_d38, *chartInstance->c2_EMPTY, -1, 0U, c2_d38 ==
                  *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) !=
                             0);
                if (!c2_t_temp) {
                  c2_d41 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 21U, 145, 3, 5U, (int32_T)
                    chartInstance->c2_currentY, 0, 18) + 19 *
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 21U, 145, 3, 5U,
                    chartInstance->c2_currentX - 1, 0, 18)];
                  c2_t_temp = (_SFD_CCP_CALL(10U, 3, CV_RELATIONAL_EVAL(5U, 10U,
                    3, c2_d41, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d41 ==
                    *chartInstance->c2_UNCOVERED) != 0U,
                    chartInstance->c2_sfEvent) != 0);
                }

                c2_r_temp = c2_t_temp;
              }

              c2_n_out = (CV_TRANSITION_EVAL(10U, (int32_T)c2_r_temp) != 0);
              if (c2_n_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U,
                             chartInstance->c2_sfEvent);
                chartInstance->c2_tp_NoHit = 0U;
                chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 10U,
                             chartInstance->c2_sfEvent);
                c2_d46 = *chartInstance->c2_LEFT_EMPTY_RIGHT_EMPTY;
                if (c2_d46 < 256.0) {
                  if (CV_SATURATION_EVAL(5, 10, 0, 1, c2_d46 >= 0.0)) {
                    c2_u12 = (uint8_T)c2_d46;
                  } else {
                    c2_u12 = 0U;
                  }
                } else if (CV_SATURATION_EVAL(5, 10, 0, 0, c2_d46 >= 256.0)) {
                  c2_u12 = MAX_uint8_T;
                } else {
                  c2_u12 = 0U;
                }

                *chartInstance->c2_sensorView = c2_u12;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U,
                                      5U, 10U, chartInstance->c2_sfEvent, false);
                chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                chartInstance->c2_tp_SensorViewState = 1U;
              } else {
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                             chartInstance->c2_sfEvent);
                c2_d43 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 22U, 2, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 22U, 2, 3, 5U, chartInstance->c2_currentX -
                  1, 0, 18)];
                c2_v_temp = (_SFD_CCP_CALL(11U, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
                  c2_d43, *chartInstance->c2_BUSY, -1, 0U, c2_d43 ==
                  *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent) !=
                             0);
                if (c2_v_temp) {
                  c2_d44 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 22U, 47, 3, 5U, (int32_T)
                    chartInstance->c2_currentY, 0, 18) + 19 *
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 22U, 47, 3, 5U, chartInstance->c2_currentX
                    + 1, 0, 18)];
                  c2_v_temp = (_SFD_CCP_CALL(11U, 1, CV_RELATIONAL_EVAL(5U, 11U,
                    1, c2_d44, *chartInstance->c2_BUSY, -1, 0U, c2_d44 ==
                    *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent)
                               != 0);
                }

                c2_p_out = (CV_TRANSITION_EVAL(11U, (int32_T)c2_v_temp) != 0);
                if (c2_p_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U,
                               chartInstance->c2_sfEvent);
                  chartInstance->c2_tp_NoHit = 0U;
                  chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                  _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
                  _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 11U,
                               chartInstance->c2_sfEvent);
                  c2_d53 = *chartInstance->c2_LEFT_BUSY_RIGHT_BUSY;
                  if (c2_d53 < 256.0) {
                    if (CV_SATURATION_EVAL(5, 11, 0, 1, c2_d53 >= 0.0)) {
                      c2_u14 = (uint8_T)c2_d53;
                    } else {
                      c2_u14 = 0U;
                    }
                  } else if (CV_SATURATION_EVAL(5, 11, 0, 0, c2_d53 >= 256.0)) {
                    c2_u14 = MAX_uint8_T;
                  } else {
                    c2_u14 = 0U;
                  }

                  *chartInstance->c2_sensorView = c2_u14;
                  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView,
                                        24U, 5U, 11U, chartInstance->c2_sfEvent,
                                        false);
                  chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                  chartInstance->c2_tp_SensorViewState = 1U;
                } else {
                  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                               chartInstance->c2_sfEvent);
                  c2_d48 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 23U, 2, 3, 5U, (int32_T)
                    chartInstance->c2_currentY, 0, 18) + 19 *
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 23U, 2, 3, 5U, chartInstance->c2_currentX
                    - 1, 0, 18)];
                  c2_y_temp = (_SFD_CCP_CALL(12U, 0, CV_RELATIONAL_EVAL(5U, 12U,
                    0, c2_d48, *chartInstance->c2_CLEANED, -1, 0U, c2_d48 ==
                    *chartInstance->c2_CLEANED) != 0U, chartInstance->c2_sfEvent)
                               != 0);
                  if (c2_y_temp) {
                    c2_d51 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 23U, 50, 3, 5U, (int32_T)
                      chartInstance->c2_currentY, 0, 18) + 19 *
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 23U, 50, 3, 5U,
                      chartInstance->c2_currentX + 1, 0, 18)];
                    c2_y_temp = (_SFD_CCP_CALL(12U, 1, CV_RELATIONAL_EVAL(5U,
                      12U, 1, c2_d51, *chartInstance->c2_CLEANED, -1, 0U, c2_d51
                      == *chartInstance->c2_CLEANED) != 0U,
                      chartInstance->c2_sfEvent) != 0);
                  }

                  c2_r_out = (CV_TRANSITION_EVAL(12U, (int32_T)c2_y_temp) != 0);
                  if (c2_r_out) {
                    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U,
                                 chartInstance->c2_sfEvent);
                    chartInstance->c2_tp_NoHit = 0U;
                    chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                 chartInstance->c2_sfEvent);
                    _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 12U,
                                 chartInstance->c2_sfEvent);
                    c2_d59 = *chartInstance->c2_LEFT_CLEANED_RIGHT_CLEANED;
                    if (c2_d59 < 256.0) {
                      if (CV_SATURATION_EVAL(5, 12, 0, 1, c2_d59 >= 0.0)) {
                        c2_u16 = (uint8_T)c2_d59;
                      } else {
                        c2_u16 = 0U;
                      }
                    } else if (CV_SATURATION_EVAL(5, 12, 0, 0, c2_d59 >= 256.0))
                    {
                      c2_u16 = MAX_uint8_T;
                    } else {
                      c2_u16 = 0U;
                    }

                    *chartInstance->c2_sensorView = c2_u16;
                    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView,
                                          24U, 5U, 12U,
                                          chartInstance->c2_sfEvent, false);
                    chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                    chartInstance->c2_tp_SensorViewState = 1U;
                  } else {
                    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                                 chartInstance->c2_sfEvent);
                    c2_d55 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 24U, 2, 3, 5U, (int32_T)
                      chartInstance->c2_currentY, 0, 18) + 19 *
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 24U, 2, 3, 5U,
                      chartInstance->c2_currentX - 1, 0, 18)];
                    c2_bb_temp = (_SFD_CCP_CALL(13U, 0, CV_RELATIONAL_EVAL(5U,
                      13U, 0, c2_d55, *chartInstance->c2_BUSY, -1, 0U, c2_d55 ==
                      *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent)
                                  != 0);
                    if (c2_bb_temp) {
                      c2_d57 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 24U, 47, 3, 5U, (int32_T)
                        chartInstance->c2_currentY, 0, 18) + 19 *
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 24U, 47, 3, 5U,
                        chartInstance->c2_currentX + 1, 0, 18)];
                      c2_bb_temp = (_SFD_CCP_CALL(13U, 1, CV_RELATIONAL_EVAL(5U,
                        13U, 1, c2_d57, *chartInstance->c2_CLEANED, -1, 0U,
                        c2_d57 == *chartInstance->c2_CLEANED) != 0U,
                        chartInstance->c2_sfEvent) != 0);
                    }

                    c2_t_out = (CV_TRANSITION_EVAL(13U, (int32_T)c2_bb_temp) !=
                                0);
                    if (c2_t_out) {
                      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U,
                                   chartInstance->c2_sfEvent);
                      chartInstance->c2_tp_NoHit = 0U;
                      chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                   chartInstance->c2_sfEvent);
                      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 13U,
                                   chartInstance->c2_sfEvent);
                      c2_d65 = *chartInstance->c2_LEFT_BUSY_RIGHT_CLEANED;
                      if (c2_d65 < 256.0) {
                        if (CV_SATURATION_EVAL(5, 13, 0, 1, c2_d65 >= 0.0)) {
                          c2_u18 = (uint8_T)c2_d65;
                        } else {
                          c2_u18 = 0U;
                        }
                      } else if (CV_SATURATION_EVAL(5, 13, 0, 0, c2_d65 >= 256.0))
                      {
                        c2_u18 = MAX_uint8_T;
                      } else {
                        c2_u18 = 0U;
                      }

                      *chartInstance->c2_sensorView = c2_u18;
                      _SFD_DATA_RANGE_CHECK((real_T)
                                            *chartInstance->c2_sensorView, 24U,
                                            5U, 13U, chartInstance->c2_sfEvent,
                                            false);
                      chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U,
                                   chartInstance->c2_sfEvent);
                      chartInstance->c2_tp_SensorViewState = 1U;
                    } else {
                      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                                   chartInstance->c2_sfEvent);
                      c2_d61 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 26U, 2, 3, 5U, (int32_T)
                        chartInstance->c2_currentY, 0, 18) + 19 *
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 26U, 2, 3, 5U,
                        chartInstance->c2_currentX - 1, 0, 18)];
                      c2_db_temp = (_SFD_CCP_CALL(14U, 0, CV_RELATIONAL_EVAL(5U,
                        14U, 0, c2_d61, *chartInstance->c2_CLEANED, -1, 0U,
                        c2_d61 == *chartInstance->c2_CLEANED) != 0U,
                        chartInstance->c2_sfEvent) != 0);
                      if (c2_db_temp) {
                        c2_d63 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                          sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                          chartInstance->S, 26U, 50, 3, 5U, (int32_T)
                          chartInstance->c2_currentY, 0, 18) + 19 *
                          sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                          chartInstance->S, 26U, 50, 3, 5U,
                          chartInstance->c2_currentX + 1, 0, 18)];
                        c2_db_temp = (_SFD_CCP_CALL(14U, 1, CV_RELATIONAL_EVAL
                          (5U, 14U, 1, c2_d63, *chartInstance->c2_BUSY, -1, 0U,
                           c2_d63 == *chartInstance->c2_BUSY) != 0U,
                          chartInstance->c2_sfEvent) != 0);
                      }

                      c2_v_out = (CV_TRANSITION_EVAL(14U, (int32_T)c2_db_temp)
                                  != 0);
                      if (c2_v_out) {
                        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U,
                                     chartInstance->c2_sfEvent);
                        chartInstance->c2_tp_NoHit = 0U;
                        chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                     chartInstance->c2_sfEvent);
                        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 14U,
                                     chartInstance->c2_sfEvent);
                        c2_d68 = *chartInstance->c2_LEFT_CLEANED_RIGHT_BUSY;
                        if (c2_d68 < 256.0) {
                          if (CV_SATURATION_EVAL(5, 14, 0, 1, c2_d68 >= 0.0)) {
                            c2_u20 = (uint8_T)c2_d68;
                          } else {
                            c2_u20 = 0U;
                          }
                        } else if (CV_SATURATION_EVAL(5, 14, 0, 0, c2_d68 >=
                                    256.0)) {
                          c2_u20 = MAX_uint8_T;
                        } else {
                          c2_u20 = 0U;
                        }

                        *chartInstance->c2_sensorView = c2_u20;
                        _SFD_DATA_RANGE_CHECK((real_T)
                                              *chartInstance->c2_sensorView, 24U,
                                              5U, 14U, chartInstance->c2_sfEvent,
                                              false);
                        chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U,
                                     chartInstance->c2_sfEvent);
                        chartInstance->c2_tp_SensorViewState = 1U;
                      } else {
                        guard3 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      guard3 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard3 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
      CV_RELATIONAL_EVAL(5U, 3U, 0, *chartInstance->c2_currentHeading,
                         *chartInstance->c2_ROB_SOUTH, -1, 0U,
                         *chartInstance->c2_currentHeading ==
                         *chartInstance->c2_ROB_SOUTH) != 0U,
      chartInstance->c2_sfEvent)) != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                   chartInstance->c2_sfEvent);
      c2_d6 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 56U, 2, 3, 5U, (int32_T)
         chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 56U, 2, 3, 5U,
         chartInstance->c2_currentX - 1, 0, 18)];
      c2_c_temp = (_SFD_CCP_CALL(20U, 0, CV_RELATIONAL_EVAL(5U, 20U, 0, c2_d6,
        *chartInstance->c2_CLEANED, -1, 0U, c2_d6 == *chartInstance->c2_CLEANED)
        != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_c_temp) {
        c2_d8 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 56U, 51, 3, 5U,
           (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
          sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
          56U, 51, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
        c2_d_temp = (_SFD_CCP_CALL(20U, 1, CV_RELATIONAL_EVAL(5U, 20U, 1, c2_d8,
          *chartInstance->c2_EMPTY, -1, 0U, c2_d8 == *chartInstance->c2_EMPTY)
          != 0U, chartInstance->c2_sfEvent) != 0);
        if (!c2_d_temp) {
          c2_d10 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            56U, 96, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            56U, 96, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
          c2_d_temp = (_SFD_CCP_CALL(20U, 2, CV_RELATIONAL_EVAL(5U, 20U, 2,
            c2_d10, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d10 ==
            *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_c_temp = c2_d_temp;
      }

      c2_g_out = (CV_TRANSITION_EVAL(20U, (int32_T)c2_c_temp) != 0);
      if (c2_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_NoHit = 0U;
        chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 20U,
                     chartInstance->c2_sfEvent);
        c2_d17 = *chartInstance->c2_LEFT_EMPTY_RIGHT_CLEANED;
        if (c2_d17 < 256.0) {
          if (CV_SATURATION_EVAL(5, 20, 0, 1, c2_d17 >= 0.0)) {
            c2_u5 = (uint8_T)c2_d17;
          } else {
            c2_u5 = 0U;
          }
        } else if (CV_SATURATION_EVAL(5, 20, 0, 0, c2_d17 >= 256.0)) {
          c2_u5 = MAX_uint8_T;
        } else {
          c2_u5 = 0U;
        }

        *chartInstance->c2_sensorView = c2_u5;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U,
                              20U, chartInstance->c2_sfEvent, false);
        chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_SensorViewState = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c2_sfEvent);
        c2_d12 = (real_T)(*chartInstance->c2_map)[(uint8_T)sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 55U, 2, 3, 5U,
           (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
          sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
          55U, 2, 3, 5U, chartInstance->c2_currentX - 1, 0, 18)];
        c2_g_temp = (_SFD_CCP_CALL(19U, 0, CV_RELATIONAL_EVAL(5U, 19U, 0, c2_d12,
          *chartInstance->c2_BUSY, -1, 0U, c2_d12 == *chartInstance->c2_BUSY) !=
          0U, chartInstance->c2_sfEvent) != 0);
        if (c2_g_temp) {
          c2_d15 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            55U, 49, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            55U, 49, 3, 5U, chartInstance->c2_currentX + 1, 0, 18)];
          c2_h_temp = (_SFD_CCP_CALL(19U, 1, CV_RELATIONAL_EVAL(5U, 19U, 1,
            c2_d15, *chartInstance->c2_EMPTY, -1, 0U, c2_d15 ==
            *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
          if (!c2_h_temp) {
            c2_d18 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 55U, 95, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 55U, 95, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_h_temp = (_SFD_CCP_CALL(19U, 2, CV_RELATIONAL_EVAL(5U, 19U, 2,
              c2_d18, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d18 ==
              *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent) !=
                         0);
          }

          c2_g_temp = c2_h_temp;
        }

        c2_i_out = (CV_TRANSITION_EVAL(19U, (int32_T)c2_g_temp) != 0);
        if (c2_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_NoHit = 0U;
          chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 19U,
                       chartInstance->c2_sfEvent);
          c2_d24 = *chartInstance->c2_LEFT_EMPTY_RIGHT_BUSY;
          if (c2_d24 < 256.0) {
            if (CV_SATURATION_EVAL(5, 19, 0, 1, c2_d24 >= 0.0)) {
              c2_u7 = (uint8_T)c2_d24;
            } else {
              c2_u7 = 0U;
            }
          } else if (CV_SATURATION_EVAL(5, 19, 0, 0, c2_d24 >= 256.0)) {
            c2_u7 = MAX_uint8_T;
          } else {
            c2_u7 = 0U;
          }

          *chartInstance->c2_sensorView = c2_u7;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U,
                                19U, chartInstance->c2_sfEvent, false);
          chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_SensorViewState = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                       chartInstance->c2_sfEvent);
          c2_d20 = (real_T)(*chartInstance->c2_map)[(uint8_T)
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            59U, 2, 3, 5U, (int32_T)chartInstance->c2_currentY, 0, 18) + 19 *
            sf_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
            59U, 2, 3, 5U, chartInstance->c2_currentX - 1, 0, 18)];
          c2_k_temp = (_SFD_CCP_CALL(23U, 0, CV_RELATIONAL_EVAL(5U, 23U, 0,
            c2_d20, *chartInstance->c2_BUSY, -1, 0U, c2_d20 ==
            *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent) != 0);
          if (c2_k_temp) {
            c2_d23 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 59U, 47, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 59U, 47, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_k_temp = (_SFD_CCP_CALL(23U, 1, CV_RELATIONAL_EVAL(5U, 23U, 1,
              c2_d23, *chartInstance->c2_BUSY, -1, 0U, c2_d23 ==
              *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent) != 0);
          }

          c2_k_out = (CV_TRANSITION_EVAL(23U, (int32_T)c2_k_temp) != 0);
          if (c2_k_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_NoHit = 0U;
            chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 23U,
                         chartInstance->c2_sfEvent);
            c2_d30 = *chartInstance->c2_LEFT_BUSY_RIGHT_BUSY;
            if (c2_d30 < 256.0) {
              if (CV_SATURATION_EVAL(5, 23, 0, 1, c2_d30 >= 0.0)) {
                c2_u9 = (uint8_T)c2_d30;
              } else {
                c2_u9 = 0U;
              }
            } else if (CV_SATURATION_EVAL(5, 23, 0, 0, c2_d30 >= 256.0)) {
              c2_u9 = MAX_uint8_T;
            } else {
              c2_u9 = 0U;
            }

            *chartInstance->c2_sensorView = c2_u9;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U, 5U,
                                  23U, chartInstance->c2_sfEvent, false);
            chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_SensorViewState = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                         chartInstance->c2_sfEvent);
            c2_d26 = (real_T)(*chartInstance->c2_map)[(uint8_T)
              sf_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 60U, 3, 3, 5U, (int32_T)
              chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 60U, 3, 3, 5U,
               chartInstance->c2_currentX + 1, 0, 18)];
            c2_m_temp = (_SFD_CCP_CALL(24U, 0, CV_RELATIONAL_EVAL(5U, 24U, 0,
              c2_d26, *chartInstance->c2_EMPTY, -1, 0U, c2_d26 ==
              *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
            if (!c2_m_temp) {
              c2_d28 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 60U, 49, 3, 5U, (int32_T)
                chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 60U, 49, 3, 5U,
                 chartInstance->c2_currentX + 1, 0, 18)];
              c2_m_temp = (_SFD_CCP_CALL(24U, 1, CV_RELATIONAL_EVAL(5U, 24U, 1,
                c2_d28, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d28 ==
                *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent)
                           != 0);
            }

            c2_o_temp = c2_m_temp;
            if (c2_o_temp) {
              c2_d32 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 60U, 100, 3, 5U, (int32_T)
                chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 60U, 100, 3, 5U,
                 chartInstance->c2_currentX - 1, 0, 18)];
              c2_p_temp = (_SFD_CCP_CALL(24U, 2, CV_RELATIONAL_EVAL(5U, 24U, 2,
                c2_d32, *chartInstance->c2_EMPTY, -1, 0U, c2_d32 ==
                *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
              if (!c2_p_temp) {
                c2_d34 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 60U, 145, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 60U, 145, 3, 5U, chartInstance->c2_currentX
                  - 1, 0, 18)];
                c2_p_temp = (_SFD_CCP_CALL(24U, 3, CV_RELATIONAL_EVAL(5U, 24U, 3,
                  c2_d34, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d34 ==
                  *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent)
                             != 0);
              }

              c2_o_temp = c2_p_temp;
            }

            c2_m_out = (CV_TRANSITION_EVAL(24U, (int32_T)c2_o_temp) != 0);
            if (c2_m_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_NoHit = 0U;
              chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 24U,
                           chartInstance->c2_sfEvent);
              c2_d40 = *chartInstance->c2_LEFT_EMPTY_RIGHT_EMPTY;
              if (c2_d40 < 256.0) {
                if (CV_SATURATION_EVAL(5, 24, 0, 1, c2_d40 >= 0.0)) {
                  c2_u11 = (uint8_T)c2_d40;
                } else {
                  c2_u11 = 0U;
                }
              } else if (CV_SATURATION_EVAL(5, 24, 0, 0, c2_d40 >= 256.0)) {
                c2_u11 = MAX_uint8_T;
              } else {
                c2_u11 = 0U;
              }

              *chartInstance->c2_sensorView = c2_u11;
              _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U,
                                    5U, 24U, chartInstance->c2_sfEvent, false);
              chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_SensorViewState = 1U;
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                           chartInstance->c2_sfEvent);
              c2_d36 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 58U, 3, 3, 5U, (int32_T)
                chartInstance->c2_currentY, 0, 18) + 19 * sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 58U, 3, 3, 5U,
                 chartInstance->c2_currentX - 1, 0, 18)];
              c2_s_temp = (_SFD_CCP_CALL(22U, 0, CV_RELATIONAL_EVAL(5U, 22U, 0,
                c2_d36, *chartInstance->c2_EMPTY, -1, 0U, c2_d36 ==
                *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent) != 0);
              if (!c2_s_temp) {
                c2_d39 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 58U, 49, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 58U, 49, 3, 5U, chartInstance->c2_currentX -
                  1, 0, 18)];
                c2_s_temp = (_SFD_CCP_CALL(22U, 1, CV_RELATIONAL_EVAL(5U, 22U, 1,
                  c2_d39, *chartInstance->c2_UNCOVERED, -1, 0U, c2_d39 ==
                  *chartInstance->c2_UNCOVERED) != 0U, chartInstance->c2_sfEvent)
                             != 0);
              }

              c2_u_temp = c2_s_temp;
              if (c2_u_temp) {
                c2_d42 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 58U, 99, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 58U, 99, 3, 5U, chartInstance->c2_currentX +
                  1, 0, 18)];
                c2_u_temp = (_SFD_CCP_CALL(22U, 2, CV_RELATIONAL_EVAL(5U, 22U, 2,
                  c2_d42, *chartInstance->c2_BUSY, -1, 0U, c2_d42 ==
                  *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent) !=
                             0);
              }

              c2_o_out = (CV_TRANSITION_EVAL(22U, (int32_T)c2_u_temp) != 0);
              if (c2_o_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U,
                             chartInstance->c2_sfEvent);
                chartInstance->c2_tp_NoHit = 0U;
                chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 22U,
                             chartInstance->c2_sfEvent);
                c2_d49 = *chartInstance->c2_LEFT_BUSY_RIGHT_EMPTY;
                if (c2_d49 < 256.0) {
                  if (CV_SATURATION_EVAL(5, 22, 0, 1, c2_d49 >= 0.0)) {
                    c2_u13 = (uint8_T)c2_d49;
                  } else {
                    c2_u13 = 0U;
                  }
                } else if (CV_SATURATION_EVAL(5, 22, 0, 0, c2_d49 >= 256.0)) {
                  c2_u13 = MAX_uint8_T;
                } else {
                  c2_u13 = 0U;
                }

                *chartInstance->c2_sensorView = c2_u13;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView, 24U,
                                      5U, 22U, chartInstance->c2_sfEvent, false);
                chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                chartInstance->c2_tp_SensorViewState = 1U;
              } else {
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                             chartInstance->c2_sfEvent);
                c2_d45 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 54U, 2, 3, 5U, (int32_T)
                  chartInstance->c2_currentY, 0, 18) + 19 *
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 54U, 2, 3, 5U, chartInstance->c2_currentX +
                  1, 0, 18)];
                c2_w_temp = (_SFD_CCP_CALL(18U, 0, CV_RELATIONAL_EVAL(5U, 18U, 0,
                  c2_d45, *chartInstance->c2_CLEANED, -1, 0U, c2_d45 ==
                  *chartInstance->c2_CLEANED) != 0U, chartInstance->c2_sfEvent)
                             != 0);
                if (c2_w_temp) {
                  c2_d47 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 54U, 51, 3, 5U, (int32_T)
                    chartInstance->c2_currentY, 0, 18) + 19 *
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 54U, 51, 3, 5U, chartInstance->c2_currentX
                    - 1, 0, 18)];
                  c2_x_temp = (_SFD_CCP_CALL(18U, 1, CV_RELATIONAL_EVAL(5U, 18U,
                    1, c2_d47, *chartInstance->c2_EMPTY, -1, 0U, c2_d47 ==
                    *chartInstance->c2_EMPTY) != 0U, chartInstance->c2_sfEvent)
                               != 0);
                  if (!c2_x_temp) {
                    c2_d50 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 54U, 96, 3, 5U, (int32_T)
                      chartInstance->c2_currentY, 0, 18) + 19 *
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 54U, 96, 3, 5U,
                      chartInstance->c2_currentX - 1, 0, 18)];
                    c2_x_temp = (_SFD_CCP_CALL(18U, 2, CV_RELATIONAL_EVAL(5U,
                      18U, 2, c2_d50, *chartInstance->c2_UNCOVERED, -1, 0U,
                      c2_d50 == *chartInstance->c2_UNCOVERED) != 0U,
                      chartInstance->c2_sfEvent) != 0);
                  }

                  c2_w_temp = c2_x_temp;
                }

                c2_q_out = (CV_TRANSITION_EVAL(18U, (int32_T)c2_w_temp) != 0);
                if (c2_q_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U,
                               chartInstance->c2_sfEvent);
                  chartInstance->c2_tp_NoHit = 0U;
                  chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                  _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
                  _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 18U,
                               chartInstance->c2_sfEvent);
                  c2_d56 = *chartInstance->c2_LEFT_CLEANED_RIGHT_EMPTY;
                  if (c2_d56 < 256.0) {
                    if (CV_SATURATION_EVAL(5, 18, 0, 1, c2_d56 >= 0.0)) {
                      c2_u15 = (uint8_T)c2_d56;
                    } else {
                      c2_u15 = 0U;
                    }
                  } else if (CV_SATURATION_EVAL(5, 18, 0, 0, c2_d56 >= 256.0)) {
                    c2_u15 = MAX_uint8_T;
                  } else {
                    c2_u15 = 0U;
                  }

                  *chartInstance->c2_sensorView = c2_u15;
                  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView,
                                        24U, 5U, 18U, chartInstance->c2_sfEvent,
                                        false);
                  chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                  chartInstance->c2_tp_SensorViewState = 1U;
                } else {
                  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                               chartInstance->c2_sfEvent);
                  c2_d52 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 57U, 2, 3, 5U, (int32_T)
                    chartInstance->c2_currentY, 0, 18) + 19 *
                    sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 57U, 2, 3, 5U, chartInstance->c2_currentX
                    - 1, 0, 18)];
                  c2_ab_temp = (_SFD_CCP_CALL(21U, 0, CV_RELATIONAL_EVAL(5U, 21U,
                    0, c2_d52, *chartInstance->c2_CLEANED, -1, 0U, c2_d52 ==
                    *chartInstance->c2_CLEANED) != 0U, chartInstance->c2_sfEvent)
                                != 0);
                  if (c2_ab_temp) {
                    c2_d54 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 57U, 50, 3, 5U, (int32_T)
                      chartInstance->c2_currentY, 0, 18) + 19 *
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 57U, 50, 3, 5U,
                      chartInstance->c2_currentX + 1, 0, 18)];
                    c2_ab_temp = (_SFD_CCP_CALL(21U, 1, CV_RELATIONAL_EVAL(5U,
                      21U, 1, c2_d54, *chartInstance->c2_CLEANED, -1, 0U, c2_d54
                      == *chartInstance->c2_CLEANED) != 0U,
                      chartInstance->c2_sfEvent) != 0);
                  }

                  c2_s_out = (CV_TRANSITION_EVAL(21U, (int32_T)c2_ab_temp) != 0);
                  if (c2_s_out) {
                    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U,
                                 chartInstance->c2_sfEvent);
                    chartInstance->c2_tp_NoHit = 0U;
                    chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                 chartInstance->c2_sfEvent);
                    _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 21U,
                                 chartInstance->c2_sfEvent);
                    c2_d62 = *chartInstance->c2_LEFT_CLEANED_RIGHT_CLEANED;
                    if (c2_d62 < 256.0) {
                      if (CV_SATURATION_EVAL(5, 21, 0, 1, c2_d62 >= 0.0)) {
                        c2_u17 = (uint8_T)c2_d62;
                      } else {
                        c2_u17 = 0U;
                      }
                    } else if (CV_SATURATION_EVAL(5, 21, 0, 0, c2_d62 >= 256.0))
                    {
                      c2_u17 = MAX_uint8_T;
                    } else {
                      c2_u17 = 0U;
                    }

                    *chartInstance->c2_sensorView = c2_u17;
                    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sensorView,
                                          24U, 5U, 21U,
                                          chartInstance->c2_sfEvent, false);
                    chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
                    chartInstance->c2_tp_SensorViewState = 1U;
                  } else {
                    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                                 chartInstance->c2_sfEvent);
                    c2_d58 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 53U, 2, 3, 5U, (int32_T)
                      chartInstance->c2_currentY, 0, 18) + 19 *
                      sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 53U, 2, 3, 5U,
                      chartInstance->c2_currentX - 1, 0, 18)];
                    c2_cb_temp = (_SFD_CCP_CALL(17U, 0, CV_RELATIONAL_EVAL(5U,
                      17U, 0, c2_d58, *chartInstance->c2_BUSY, -1, 0U, c2_d58 ==
                      *chartInstance->c2_BUSY) != 0U, chartInstance->c2_sfEvent)
                                  != 0);
                    if (c2_cb_temp) {
                      c2_d60 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 53U, 47, 3, 5U, (int32_T)
                        chartInstance->c2_currentY, 0, 18) + 19 *
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 53U, 47, 3, 5U,
                        chartInstance->c2_currentX + 1, 0, 18)];
                      c2_cb_temp = (_SFD_CCP_CALL(17U, 1, CV_RELATIONAL_EVAL(5U,
                        17U, 1, c2_d60, *chartInstance->c2_CLEANED, -1, 0U,
                        c2_d60 == *chartInstance->c2_CLEANED) != 0U,
                        chartInstance->c2_sfEvent) != 0);
                    }

                    c2_u_out = (CV_TRANSITION_EVAL(17U, (int32_T)c2_cb_temp) !=
                                0);
                    if (c2_u_out) {
                      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U,
                                   chartInstance->c2_sfEvent);
                      chartInstance->c2_tp_NoHit = 0U;
                      chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                   chartInstance->c2_sfEvent);
                      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 17U,
                                   chartInstance->c2_sfEvent);
                      c2_d67 = *chartInstance->c2_LEFT_CLEANED_RIGHT_BUSY;
                      if (c2_d67 < 256.0) {
                        if (CV_SATURATION_EVAL(5, 17, 0, 1, c2_d67 >= 0.0)) {
                          c2_u19 = (uint8_T)c2_d67;
                        } else {
                          c2_u19 = 0U;
                        }
                      } else if (CV_SATURATION_EVAL(5, 17, 0, 0, c2_d67 >= 256.0))
                      {
                        c2_u19 = MAX_uint8_T;
                      } else {
                        c2_u19 = 0U;
                      }

                      *chartInstance->c2_sensorView = c2_u19;
                      _SFD_DATA_RANGE_CHECK((real_T)
                                            *chartInstance->c2_sensorView, 24U,
                                            5U, 17U, chartInstance->c2_sfEvent,
                                            false);
                      chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U,
                                   chartInstance->c2_sfEvent);
                      chartInstance->c2_tp_SensorViewState = 1U;
                    } else {
                      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                                   chartInstance->c2_sfEvent);
                      c2_d64 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 52U, 2, 3, 5U, (int32_T)
                        chartInstance->c2_currentY, 0, 18) + 19 *
                        sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                        chartInstance->S, 52U, 2, 3, 5U,
                        chartInstance->c2_currentX - 1, 0, 18)];
                      c2_eb_temp = (_SFD_CCP_CALL(16U, 0, CV_RELATIONAL_EVAL(5U,
                        16U, 0, c2_d64, *chartInstance->c2_CLEANED, -1, 0U,
                        c2_d64 == *chartInstance->c2_CLEANED) != 0U,
                        chartInstance->c2_sfEvent) != 0);
                      if (c2_eb_temp) {
                        c2_d66 = (real_T)(*chartInstance->c2_map)[(uint8_T)
                          sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                          chartInstance->S, 52U, 50, 3, 5U, (int32_T)
                          chartInstance->c2_currentY, 0, 18) + 19 *
                          sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                          chartInstance->S, 52U, 50, 3, 5U,
                          chartInstance->c2_currentX + 1, 0, 18)];
                        c2_eb_temp = (_SFD_CCP_CALL(16U, 1, CV_RELATIONAL_EVAL
                          (5U, 16U, 1, c2_d66, *chartInstance->c2_BUSY, -1, 0U,
                           c2_d66 == *chartInstance->c2_BUSY) != 0U,
                          chartInstance->c2_sfEvent) != 0);
                      }

                      c2_w_out = (CV_TRANSITION_EVAL(16U, (int32_T)c2_eb_temp)
                                  != 0);
                      if (c2_w_out) {
                        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U,
                                     chartInstance->c2_sfEvent);
                        chartInstance->c2_tp_NoHit = 0U;
                        chartInstance->c2_is_c2_ROTH = c2_IN_NO_ACTIVE_CHILD;
                        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U,
                                     chartInstance->c2_sfEvent);
                        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 16U,
                                     chartInstance->c2_sfEvent);
                        c2_d69 = *chartInstance->c2_LEFT_BUSY_RIGHT_CLEANED;
                        if (c2_d69 < 256.0) {
                          if (CV_SATURATION_EVAL(5, 16, 0, 1, c2_d69 >= 0.0)) {
                            c2_u21 = (uint8_T)c2_d69;
                          } else {
                            c2_u21 = 0U;
                          }
                        } else if (CV_SATURATION_EVAL(5, 16, 0, 0, c2_d69 >=
                                    256.0)) {
                          c2_u21 = MAX_uint8_T;
                        } else {
                          c2_u21 = 0U;
                        }

                        *chartInstance->c2_sensorView = c2_u21;
                        _SFD_DATA_RANGE_CHECK((real_T)
                                              *chartInstance->c2_sensorView, 24U,
                                              5U, 16U, chartInstance->c2_sfEvent,
                                              false);
                        chartInstance->c2_is_c2_ROTH = c2_IN_SensorViewState;
                        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U,
                                     chartInstance->c2_sfEvent);
                        chartInstance->c2_tp_SensorViewState = 1U;
                      } else {
                        guard2 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      guard2 = true;
    }
  }

  if (guard2 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c2_sfEvent);
    c2_d_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
      CV_RELATIONAL_EVAL(5U, 4U, 0, *chartInstance->c2_currentHeading,
                         *chartInstance->c2_ROB_WEST, -1, 0U,
                         *chartInstance->c2_currentHeading ==
                         *chartInstance->c2_ROB_WEST) != 0U,
      chartInstance->c2_sfEvent)) != 0);
    if (c2_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c2_sfEvent);
      c2_f_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
        CV_RELATIONAL_EVAL(5U, 5U, 0, *chartInstance->c2_currentHeading,
                           *chartInstance->c2_ROB_EAST, -1, 0U,
                           *chartInstance->c2_currentHeading ==
                           *chartInstance->c2_ROB_EAST) != 0U,
        chartInstance->c2_sfEvent)) != 0);
      if (c2_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      }
    }

    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

const mxArray *sf_c2_ROTH_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance,
  const mxArray *c2_b_tp_SensorViewState, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_SensorViewState),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_SensorViewState);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_ROTHInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u22;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u22, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u22;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_SensorViewState;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_b_tp_SensorViewState = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_SensorViewState),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_SensorViewState);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  int32_T c2_i3;
  const mxArray *c2_y = NULL;
  int32_T c2_i4;
  uint8_T c2_u[361];
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i2 = 0;
  for (c2_i3 = 0; c2_i3 < 19; c2_i3++) {
    for (c2_i4 = 0; c2_i4 < 19; c2_i4++) {
      c2_u[c2_i4 + c2_i2] = (*(uint8_T (*)[361])c2_inData)[c2_i4 + c2_i2];
    }

    c2_i2 += 19;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 2, 19, 19), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_emlrt_marshallIn(SFc2_ROTHInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_e_emlrt_marshallIn(SFc2_ROTHInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc2_ROTHInstanceStruct
  *chartInstance, int32_T c2_ssid)
{
  (void)chartInstance;
  (void)c2_ssid;
  return NULL;
}

static void c2_init_sf_message_store_memory(SFc2_ROTHInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc2_ROTHInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_ROTHInstanceStruct *chartInstance)
{
  chartInstance->c2_c_X = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_c_Y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_pumperHit_BOOL = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_sensorView = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_map = (uint8_T (*)[361])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_currentHeading = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_BUSY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_EMPTY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_CLEANED = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_UNCOVERED = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c2_LEFT_BUSY_RIGHT_EMPTY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 9);
  chartInstance->c2_LEFT_CLEANED_RIGHT_EMPTY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 10);
  chartInstance->c2_LEFT_EMPTY_RIGHT_BUSY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 11);
  chartInstance->c2_LEFT_EMPTY_RIGHT_CLEANED = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 12);
  chartInstance->c2_LEFT_EMPTY_RIGHT_EMPTY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 13);
  chartInstance->c2_LEFT_BUSY_RIGHT_BUSY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 14);
  chartInstance->c2_LEFT_CLEANED_RIGHT_CLEANED = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 15);
  chartInstance->c2_LEFT_BUSY_RIGHT_CLEANED = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 16);
  chartInstance->c2_LEFT_CLEANED_RIGHT_BUSY = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 17);
  chartInstance->c2_ROB_NORTH = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c2_ROB_SOUTH = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 19);
  chartInstance->c2_ROB_WEST = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 20);
  chartInstance->c2_ROB_EAST = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 21);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_ROTH_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(463284423U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(31556473U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4239283937U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1790154618U);
}

mxArray* sf_c2_ROTH_get_post_codegen_info(void);
mxArray *sf_c2_ROTH_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0jMt0NPxCVhzSLqyn4FBtF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,22,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(19);
      pr[1] = (double)(19);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_ROTH_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_ROTH_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_ROTH_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_ROTH_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_ROTH_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_ROTH(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[25],T\"sensorView\",},{M[3],M[50],T\"currentX\",},{M[3],M[51],T\"currentY\",},{M[8],M[0],T\"is_active_c2_ROTH\",},{M[9],M[0],T\"is_c2_ROTH\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ROTH_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc2_ROTHInstanceStruct *) chartInstance,
    msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ROTHInstanceStruct *chartInstance = (SFc2_ROTHInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ROTHMachineNumber_,
           2,
           3,
           26,
           0,
           25,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ROTHMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ROTHMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ROTHMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"currentX");
          _SFD_SET_DATA_PROPS(1,0,0,0,"currentY");
          _SFD_SET_DATA_PROPS(2,1,1,0,"c_X");
          _SFD_SET_DATA_PROPS(3,1,1,0,"c_Y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"pumperHit_BOOL");
          _SFD_SET_DATA_PROPS(5,1,1,0,"map");
          _SFD_SET_DATA_PROPS(6,1,1,0,"currentHeading");
          _SFD_SET_DATA_PROPS(7,1,1,0,"BUSY");
          _SFD_SET_DATA_PROPS(8,1,1,0,"EMPTY");
          _SFD_SET_DATA_PROPS(9,1,1,0,"CLEANED");
          _SFD_SET_DATA_PROPS(10,1,1,0,"UNCOVERED");
          _SFD_SET_DATA_PROPS(11,1,1,0,"LEFT_BUSY_RIGHT_EMPTY");
          _SFD_SET_DATA_PROPS(12,1,1,0,"LEFT_CLEANED_RIGHT_EMPTY");
          _SFD_SET_DATA_PROPS(13,1,1,0,"LEFT_EMPTY_RIGHT_BUSY");
          _SFD_SET_DATA_PROPS(14,1,1,0,"LEFT_EMPTY_RIGHT_CLEANED");
          _SFD_SET_DATA_PROPS(15,1,1,0,"LEFT_EMPTY_RIGHT_EMPTY");
          _SFD_SET_DATA_PROPS(16,1,1,0,"LEFT_BUSY_RIGHT_BUSY");
          _SFD_SET_DATA_PROPS(17,1,1,0,"LEFT_CLEANED_RIGHT_CLEANED");
          _SFD_SET_DATA_PROPS(18,1,1,0,"LEFT_BUSY_RIGHT_CLEANED");
          _SFD_SET_DATA_PROPS(19,1,1,0,"LEFT_CLEANED_RIGHT_BUSY");
          _SFD_SET_DATA_PROPS(20,1,1,0,"ROB_NORTH");
          _SFD_SET_DATA_PROPS(21,1,1,0,"ROB_SOUTH");
          _SFD_SET_DATA_PROPS(22,1,1,0,"ROB_WEST");
          _SFD_SET_DATA_PROPS(23,1,1,0,"ROB_EAST");
          _SFD_SET_DATA_PROPS(24,2,0,1,"sensorView");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 28, 48 };

          static unsigned int sEndSaturateMap[] = { 29, 49 };

          _SFD_CV_INIT_STATE_SATURATION(1,2,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 49, 95 };

          static unsigned int sEndGuardMap[] = { 37, 85, 133 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(6,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 155 };

          static unsigned int sEndSaturateMap[] = { 176 };

          _SFD_CV_INIT_TRANSITION_SATURATION(6,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 49, 95 };

          static unsigned int sEndRelationalopMap[] = { 37, 85, 133 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 51, 96 };

          static unsigned int sEndGuardMap[] = { 40, 87, 134 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(7,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 154 };

          static unsigned int sEndSaturateMap[] = { 178 };

          _SFD_CV_INIT_TRANSITION_SATURATION(7,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 51, 96 };

          static unsigned int sEndRelationalopMap[] = { 40, 87, 134 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 49, 99 };

          static unsigned int sEndGuardMap[] = { 39, 89, 134 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, -3 };

          _SFD_CV_INIT_TRANS(8,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 152 };

          static unsigned int sEndSaturateMap[] = { 173 };

          _SFD_CV_INIT_TRANSITION_SATURATION(8,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 3, 49, 99 };

          static unsigned int sEndRelationalopMap[] = { 39, 89, 134 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(8,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 51, 96 };

          static unsigned int sEndGuardMap[] = { 40, 87, 136 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(9,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 156 };

          static unsigned int sEndSaturateMap[] = { 180 };

          _SFD_CV_INIT_TRANSITION_SATURATION(9,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 51, 96 };

          static unsigned int sEndRelationalopMap[] = { 40, 87, 136 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(9,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 49, 100, 145 };

          static unsigned int sEndGuardMap[] = { 39, 89, 136, 185 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, 3, -2, -3 };

          _SFD_CV_INIT_TRANS(10,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 204 };

          static unsigned int sEndSaturateMap[] = { 226 };

          _SFD_CV_INIT_TRANSITION_SATURATION(10,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 3, 49, 100, 145 };

          static unsigned int sEndRelationalopMap[] = { 39, 89, 136, 185 };

          static int sRelationalopEps[] = { -1, -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(10,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 47 };

          static unsigned int sEndGuardMap[] = { 37, 82 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(11,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 100 };

          static unsigned int sEndSaturateMap[] = { 120 };

          _SFD_CV_INIT_TRANSITION_SATURATION(11,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 47 };

          static unsigned int sEndRelationalopMap[] = { 37, 82 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(11,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 50 };

          static unsigned int sEndGuardMap[] = { 40, 88 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(12,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 106 };

          static unsigned int sEndSaturateMap[] = { 132 };

          _SFD_CV_INIT_TRANSITION_SATURATION(12,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 50 };

          static unsigned int sEndRelationalopMap[] = { 40, 88 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(12,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 47 };

          static unsigned int sEndGuardMap[] = { 37, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(13,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 103 };

          static unsigned int sEndSaturateMap[] = { 126 };

          _SFD_CV_INIT_TRANSITION_SATURATION(13,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 47 };

          static unsigned int sEndRelationalopMap[] = { 37, 85 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(13,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 50 };

          static unsigned int sEndGuardMap[] = { 40, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(14,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 103 };

          static unsigned int sEndSaturateMap[] = { 126 };

          _SFD_CV_INIT_TRANSITION_SATURATION(14,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 50 };

          static unsigned int sEndRelationalopMap[] = { 40, 85 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(14,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 28 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 28 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(2,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 49, 95 };

          static unsigned int sEndGuardMap[] = { 37, 85, 133 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(19,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 155 };

          static unsigned int sEndSaturateMap[] = { 176 };

          _SFD_CV_INIT_TRANSITION_SATURATION(19,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 49, 95 };

          static unsigned int sEndRelationalopMap[] = { 37, 85, 133 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(19,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 27 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(5,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 27 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(4,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 28 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 28 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(3,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 51, 96 };

          static unsigned int sEndGuardMap[] = { 40, 87, 134 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(20,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 154 };

          static unsigned int sEndSaturateMap[] = { 178 };

          _SFD_CV_INIT_TRANSITION_SATURATION(20,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 51, 96 };

          static unsigned int sEndRelationalopMap[] = { 40, 87, 134 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(20,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 49, 99 };

          static unsigned int sEndGuardMap[] = { 39, 89, 134 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, -3 };

          _SFD_CV_INIT_TRANS(22,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 152 };

          static unsigned int sEndSaturateMap[] = { 173 };

          _SFD_CV_INIT_TRANSITION_SATURATION(22,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 3, 49, 99 };

          static unsigned int sEndRelationalopMap[] = { 39, 89, 134 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(22,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 51, 96 };

          static unsigned int sEndGuardMap[] = { 40, 87, 136 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(18,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 156 };

          static unsigned int sEndSaturateMap[] = { 180 };

          _SFD_CV_INIT_TRANSITION_SATURATION(18,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 51, 96 };

          static unsigned int sEndRelationalopMap[] = { 40, 87, 136 };

          static int sRelationalopEps[] = { -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(18,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 49, 100, 145 };

          static unsigned int sEndGuardMap[] = { 39, 89, 136, 185 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, 3, -2, -3 };

          _SFD_CV_INIT_TRANS(24,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 204 };

          static unsigned int sEndSaturateMap[] = { 226 };

          _SFD_CV_INIT_TRANSITION_SATURATION(24,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 3, 49, 100, 145 };

          static unsigned int sEndRelationalopMap[] = { 39, 89, 136, 185 };

          static int sRelationalopEps[] = { -1, -1, -1, -1 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(24,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 47 };

          static unsigned int sEndGuardMap[] = { 37, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(17,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 103 };

          static unsigned int sEndSaturateMap[] = { 126 };

          _SFD_CV_INIT_TRANSITION_SATURATION(17,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 47 };

          static unsigned int sEndRelationalopMap[] = { 37, 85 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(17,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 47 };

          static unsigned int sEndGuardMap[] = { 37, 82 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(23,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 100 };

          static unsigned int sEndSaturateMap[] = { 120 };

          _SFD_CV_INIT_TRANSITION_SATURATION(23,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 47 };

          static unsigned int sEndRelationalopMap[] = { 37, 82 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(23,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 50 };

          static unsigned int sEndGuardMap[] = { 40, 88 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(21,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 106 };

          static unsigned int sEndSaturateMap[] = { 132 };

          _SFD_CV_INIT_TRANSITION_SATURATION(21,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 50 };

          static unsigned int sEndRelationalopMap[] = { 40, 88 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(21,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 50 };

          static unsigned int sEndGuardMap[] = { 40, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(16,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 103 };

          static unsigned int sEndSaturateMap[] = { 126 };

          _SFD_CV_INIT_TRANSITION_SATURATION(16,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 50 };

          static unsigned int sEndRelationalopMap[] = { 40, 85 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(16,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 19U;
          dimVector[1]= 19U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ROTHMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ROTHInstanceStruct *chartInstance = (SFc2_ROTHInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_c_X);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_c_Y);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_pumperHit_BOOL);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c2_sensorView);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_map);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_currentHeading);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c2_BUSY);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_EMPTY);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c2_CLEANED);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c2_UNCOVERED);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c2_LEFT_BUSY_RIGHT_EMPTY);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c2_LEFT_CLEANED_RIGHT_EMPTY);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c2_LEFT_EMPTY_RIGHT_BUSY);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c2_LEFT_EMPTY_RIGHT_CLEANED);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c2_LEFT_EMPTY_RIGHT_EMPTY);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c2_LEFT_BUSY_RIGHT_BUSY);
        _SFD_SET_DATA_VALUE_PTR(17U,
          chartInstance->c2_LEFT_CLEANED_RIGHT_CLEANED);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c2_LEFT_BUSY_RIGHT_CLEANED);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c2_LEFT_CLEANED_RIGHT_BUSY);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c2_ROB_NORTH);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c2_ROB_SOUTH);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c2_ROB_WEST);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c2_ROB_EAST);
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c2_currentX);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c2_currentY);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sX1e6OqUtHG3kNQENDecv3B";
}

static void sf_opaque_initialize_c2_ROTH(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ROTHInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
  initialize_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ROTH(void *chartInstanceVar)
{
  enable_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ROTH(void *chartInstanceVar)
{
  disable_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ROTH(void *chartInstanceVar)
{
  sf_gateway_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_ROTH(SimStruct* S)
{
  return get_sim_state_c2_ROTH((SFc2_ROTHInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_ROTH(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_ROTH((SFc2_ROTHInstanceStruct*)sf_get_chart_instance_ptr(S),
                        st);
}

static void sf_opaque_terminate_c2_ROTH(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ROTHInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ROTH_optimization_info();
    }

    finalize_c2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ROTH((SFc2_ROTHInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ROTH(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ROTH((SFc2_ROTHInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_ROTH(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ROTH_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,22);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 22; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(58683502U));
  ssSetChecksum1(S,(2687765306U));
  ssSetChecksum2(S,(2263130054U));
  ssSetChecksum3(S,(3177072735U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_ROTH(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_ROTH(SimStruct *S)
{
  SFc2_ROTHInstanceStruct *chartInstance;
  chartInstance = (SFc2_ROTHInstanceStruct *)utMalloc(sizeof
    (SFc2_ROTHInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_ROTHInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ROTH;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ROTH;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ROTH;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ROTH;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ROTH;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ROTH;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ROTH;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ROTH;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ROTH;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ROTH;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ROTH;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_ROTH(chartInstance);
}

void c2_ROTH_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ROTH(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ROTH(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ROTH(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ROTH_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
