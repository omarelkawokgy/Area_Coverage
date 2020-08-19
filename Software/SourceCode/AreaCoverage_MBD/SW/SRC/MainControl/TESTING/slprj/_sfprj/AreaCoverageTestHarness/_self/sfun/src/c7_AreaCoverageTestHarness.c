/* Include files */

#include "AreaCoverageTestHarness_sfun.h"
#include "c7_AreaCoverageTestHarness.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AreaCoverageTestHarness_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_ReadEEPROM               ((uint8_T)1U)
#define c7_IN_UpdateEEPROM             ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void initialize_params_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void enable_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void disable_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void set_sim_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_st);
static void c7_set_sim_state_side_effects_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void finalize_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void sf_gateway_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void mdl_start_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void initSimStructsc7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static int32_T c7_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_b_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_b_tp_ReadEEPROM, const char_T *c7_identifier);
static uint8_T c7_c_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static boolean_T c7_d_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_b_NVM_AngleStoreFlg, const char_T *c7_identifier);
static boolean_T c7_e_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int16_T c7_f_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_b_NVM_NORTH, const char_T *c7_identifier);
static int16_T c7_g_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_h_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier);
static const mxArray *c7_i_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, int32_T c7_ssid);
static void c7_init_sf_message_store_memory
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc7_AreaCoverageTestHarnessInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_AreaCoverageTestHarness(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  chartInstance->c7_tp_ReadEEPROM = 0U;
  chartInstance->c7_tp_UpdateEEPROM = 0U;
  chartInstance->c7_is_active_c7_AreaCoverageTestHarness = 0U;
  chartInstance->c7_is_c7_AreaCoverageTestHarness = c7_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c7_NVM_AngleStoreFlg = false;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c7_NVM_AngleStoreFlg,
      5U, 1U, 6U, chartInstance->c7_sfEvent, false, 0.0, 1.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c7_NVM_NORTH = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c7_NVM_NORTH, 6U, 1U,
      6U, chartInstance->c7_sfEvent, false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c7_NVM_SOUTH = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c7_NVM_SOUTH, 7U, 1U,
      6U, chartInstance->c7_sfEvent, false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c7_NVM_EAST = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c7_NVM_EAST, 8U, 1U,
      6U, chartInstance->c7_sfEvent, false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c7_NVM_WEST = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c7_NVM_WEST, 9U, 1U,
      6U, chartInstance->c7_sfEvent, false, -20.0, 360.0, 0U, 0, 0);
  }
}

static void initialize_params_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  real_T c7_d0;
  sf_mex_import_named("ENU_FINISHED", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c7_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_ENU_FINISHED = (uint8_T)c7_d0;
}

static void enable_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c7_is_active_c7_AreaCoverageTestHarness == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_AreaCoverageTestHarness == c7_IN_ReadEEPROM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_AreaCoverageTestHarness == c7_IN_UpdateEEPROM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  }

  _SFD_SET_ANIMATION(c7_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  boolean_T c7_hoistedGlobal;
  const mxArray *c7_b_y = NULL;
  int16_T c7_b_hoistedGlobal;
  const mxArray *c7_c_y = NULL;
  int16_T c7_c_hoistedGlobal;
  const mxArray *c7_d_y = NULL;
  int16_T c7_d_hoistedGlobal;
  const mxArray *c7_e_y = NULL;
  int16_T c7_e_hoistedGlobal;
  const mxArray *c7_f_y = NULL;
  uint8_T c7_f_hoistedGlobal;
  const mxArray *c7_g_y = NULL;
  uint8_T c7_g_hoistedGlobal;
  const mxArray *c7_h_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(7, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_NVM_AngleStoreFlg;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *chartInstance->c7_NVM_EAST;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *chartInstance->c7_NVM_NORTH;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *chartInstance->c7_NVM_SOUTH;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = *chartInstance->c7_NVM_WEST;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = chartInstance->c7_is_active_c7_AreaCoverageTestHarness;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = chartInstance->c7_is_c7_AreaCoverageTestHarness;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_u;
  c7_u = sf_mex_dup(c7_st);
  *chartInstance->c7_NVM_AngleStoreFlg = c7_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_AngleStoreFlg", c7_u, 0)),
    "NVM_AngleStoreFlg");
  *chartInstance->c7_NVM_EAST = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("NVM_EAST", c7_u, 1)), "NVM_EAST");
  *chartInstance->c7_NVM_NORTH = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("NVM_NORTH", c7_u, 2)), "NVM_NORTH");
  *chartInstance->c7_NVM_SOUTH = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("NVM_SOUTH", c7_u, 3)), "NVM_SOUTH");
  *chartInstance->c7_NVM_WEST = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("NVM_WEST", c7_u, 4)), "NVM_WEST");
  chartInstance->c7_is_active_c7_AreaCoverageTestHarness = c7_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c7_AreaCoverageTestHarness", c7_u, 5)),
     "is_active_c7_AreaCoverageTestHarness");
  chartInstance->c7_is_c7_AreaCoverageTestHarness = c7_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c7_AreaCoverageTestHarness",
       c7_u, 6)), "is_c7_AreaCoverageTestHarness");
  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c7_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_AreaCoverageTestHarness(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    chartInstance->c7_tp_ReadEEPROM = (uint8_T)
      (chartInstance->c7_is_c7_AreaCoverageTestHarness == c7_IN_ReadEEPROM);
    chartInstance->c7_tp_UpdateEEPROM = (uint8_T)
      (chartInstance->c7_is_c7_AreaCoverageTestHarness == c7_IN_UpdateEEPROM);
    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_gateway_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  boolean_T c7_out;
  c7_set_sim_state_side_effects_c7_AreaCoverageTestHarness(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_angleCalib_WEST, 4U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_angleCalib_EAST, 3U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_angleCalib_SOUTH, 2U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_angleCalib_NORTH, 1U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_angleCalibStatus, 0U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  if (chartInstance->c7_is_active_c7_AreaCoverageTestHarness == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_active_c7_AreaCoverageTestHarness = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_c7_AreaCoverageTestHarness = c7_IN_ReadEEPROM;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_ReadEEPROM = 1U;
    EEPROM_Read_Wrapper(chartInstance->c7_NVM_AngleStoreFlg,
                        chartInstance->c7_NVM_NORTH, chartInstance->c7_NVM_SOUTH,
                        chartInstance->c7_NVM_EAST, chartInstance->c7_NVM_WEST);
  } else {
    switch (chartInstance->c7_is_c7_AreaCoverageTestHarness) {
     case c7_IN_ReadEEPROM:
      CV_CHART_EVAL(6, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c7_sfEvent);
      c7_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
        *chartInstance->c7_angleCalibStatus, (real_T)
        chartInstance->c7_ENU_FINISHED, 0, 0U,
        *chartInstance->c7_angleCalibStatus == chartInstance->c7_ENU_FINISHED)
                  != 0U, chartInstance->c7_sfEvent)) != 0);
      if (c7_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_ReadEEPROM = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_c7_AreaCoverageTestHarness = c7_IN_UpdateEEPROM;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_UpdateEEPROM = 1U;
        EEPROM_Update_Wrapper(*chartInstance->c7_angleCalib_NORTH,
                              *chartInstance->c7_angleCalib_SOUTH,
                              *chartInstance->c7_angleCalib_EAST,
                              *chartInstance->c7_angleCalib_WEST);
        EEPROM_Read_Wrapper(chartInstance->c7_NVM_AngleStoreFlg,
                            chartInstance->c7_NVM_NORTH,
                            chartInstance->c7_NVM_SOUTH,
                            chartInstance->c7_NVM_EAST,
                            chartInstance->c7_NVM_WEST);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_UpdateEEPROM:
      CV_CHART_EVAL(6, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c7_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_CHART_EVAL(6, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c7_is_c7_AreaCoverageTestHarness = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AreaCoverageTestHarnessMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  c7_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc7_AreaCoverageTestHarness
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

const mxArray *sf_c7_AreaCoverageTestHarness_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i0, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent), &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static uint8_T c7_b_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_b_tp_ReadEEPROM, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_ReadEEPROM),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_ReadEEPROM);
  return c7_y;
}

static uint8_T c7_c_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_tp_ReadEEPROM;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_b_tp_ReadEEPROM = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_ReadEEPROM),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_ReadEEPROM);
  *(uint8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  uint16_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint16_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  boolean_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(boolean_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static boolean_T c7_d_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_b_NVM_AngleStoreFlg, const char_T *c7_identifier)
{
  boolean_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_NVM_AngleStoreFlg),
    &c7_thisId);
  sf_mex_destroy(&c7_b_NVM_AngleStoreFlg);
  return c7_y;
}

static boolean_T c7_e_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  boolean_T c7_y;
  boolean_T c7_b0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_b0, 1, 11, 0U, 0, 0U, 0);
  c7_y = c7_b0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_NVM_AngleStoreFlg;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  boolean_T c7_y;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_b_NVM_AngleStoreFlg = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_NVM_AngleStoreFlg),
    &c7_thisId);
  sf_mex_destroy(&c7_b_NVM_AngleStoreFlg);
  *(boolean_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  int16_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(int16_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 4, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int16_T c7_f_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_b_NVM_NORTH, const char_T *c7_identifier)
{
  int16_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_NVM_NORTH),
    &c7_thisId);
  sf_mex_destroy(&c7_b_NVM_NORTH);
  return c7_y;
}

static int16_T c7_g_emlrt_marshallIn(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int16_T c7_y;
  int16_T c7_i1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i1, 1, 4, 0U, 0, 0U, 0);
  c7_y = c7_i1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_NVM_NORTH;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int16_T c7_y;
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstanceVoid;
  c7_b_NVM_NORTH = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_NVM_NORTH),
    &c7_thisId);
  sf_mex_destroy(&c7_b_NVM_NORTH);
  *(int16_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_h_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  sf_mex_assign(&c7_y, c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), false);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_i_emlrt_marshallIn
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  (void)c7_parentId;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), false);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance, int32_T c7_ssid)
{
  const mxArray *c7_msgInfo;
  (void)chartInstance;
  (void)c7_ssid;
  c7_msgInfo = NULL;
  return NULL;
}

static void c7_init_sf_message_store_memory
  (SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc7_AreaCoverageTestHarnessInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_AreaCoverageTestHarnessInstanceStruct *
  chartInstance)
{
  chartInstance->c7_angleCalibStatus = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_angleCalib_NORTH = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_angleCalib_SOUTH = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_angleCalib_EAST = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_angleCalib_WEST = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c7_NVM_AngleStoreFlg = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c7_NVM_NORTH = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_NVM_SOUTH = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_NVM_EAST = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c7_NVM_WEST = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c7_AreaCoverageTestHarness_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3593082702U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3647569146U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3888809169U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3193874949U);
}

mxArray* sf_c7_AreaCoverageTestHarness_get_post_codegen_info(void);
mxArray *sf_c7_AreaCoverageTestHarness_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Azl0qxpNVQU3B1eYLda7hH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c7_AreaCoverageTestHarness_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_AreaCoverageTestHarness_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_AreaCoverageTestHarness_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("custom_code");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_AreaCoverageTestHarness_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_AreaCoverageTestHarness_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c7_AreaCoverageTestHarness(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[15],T\"NVM_AngleStoreFlg\",},{M[1],M[18],T\"NVM_EAST\",},{M[1],M[16],T\"NVM_NORTH\",},{M[1],M[17],T\"NVM_SOUTH\",},{M[1],M[19],T\"NVM_WEST\",},{M[8],M[0],T\"is_active_c7_AreaCoverageTestHarness\",},{M[9],M[0],T\"is_c7_AreaCoverageTestHarness\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_AreaCoverageTestHarness_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc7_AreaCoverageTestHarnessInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance =
      (SFc7_AreaCoverageTestHarnessInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AreaCoverageTestHarnessMachineNumber_,
           7,
           2,
           2,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_AreaCoverageTestHarnessMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AreaCoverageTestHarnessMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AreaCoverageTestHarnessMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"angleCalibStatus");
          _SFD_SET_DATA_PROPS(1,1,1,0,"angleCalib_NORTH");
          _SFD_SET_DATA_PROPS(2,1,1,0,"angleCalib_SOUTH");
          _SFD_SET_DATA_PROPS(3,1,1,0,"angleCalib_EAST");
          _SFD_SET_DATA_PROPS(4,1,1,0,"angleCalib_WEST");
          _SFD_SET_DATA_PROPS(5,2,0,1,"NVM_AngleStoreFlg");
          _SFD_SET_DATA_PROPS(6,2,0,1,"NVM_NORTH");
          _SFD_SET_DATA_PROPS(7,2,0,1,"NVM_SOUTH");
          _SFD_SET_DATA_PROPS(8,2,0,1,"NVM_EAST");
          _SFD_SET_DATA_PROPS(9,2,0,1,"NVM_WEST");
          _SFD_SET_DATA_PROPS(10,10,0,0,"ENU_FINISHED");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 34 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2 };

          static unsigned int sEndRelationalopMap[] = { 34 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)c7_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)c7_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)c7_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)c7_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AreaCoverageTestHarnessMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance =
      (SFc7_AreaCoverageTestHarnessInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_angleCalibStatus);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c7_ENU_FINISHED);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_angleCalib_NORTH);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c7_angleCalib_SOUTH);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c7_angleCalib_EAST);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_angleCalib_WEST);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c7_NVM_AngleStoreFlg);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c7_NVM_NORTH);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c7_NVM_SOUTH);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c7_NVM_EAST);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c7_NVM_WEST);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sg4Js3vAuBNkfgiXXZiBCgG";
}

static void sf_opaque_initialize_c7_AreaCoverageTestHarness(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_AreaCoverageTestHarnessInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct*) chartInstanceVar);
  initialize_c7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_AreaCoverageTestHarness(void *chartInstanceVar)
{
  enable_c7_AreaCoverageTestHarness((SFc7_AreaCoverageTestHarnessInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_AreaCoverageTestHarness(void *chartInstanceVar)
{
  disable_c7_AreaCoverageTestHarness((SFc7_AreaCoverageTestHarnessInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_AreaCoverageTestHarness(void *chartInstanceVar)
{
  sf_gateway_c7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_AreaCoverageTestHarness
  (SimStruct* S)
{
  return get_sim_state_c7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_AreaCoverageTestHarness(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c7_AreaCoverageTestHarness(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_AreaCoverageTestHarnessInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AreaCoverageTestHarness_optimization_info();
    }

    finalize_c7_AreaCoverageTestHarness
      ((SFc7_AreaCoverageTestHarnessInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_AreaCoverageTestHarness
    ((SFc7_AreaCoverageTestHarnessInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_AreaCoverageTestHarness(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_AreaCoverageTestHarness
      ((SFc7_AreaCoverageTestHarnessInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c7_AreaCoverageTestHarness(SimStruct *S)
{
  /* Actual parameters from chart:
     ENU_FINISHED
   */
  const char_T *rtParamNames[] = { "ENU_FINISHED" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for ENU_FINISHED*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AreaCoverageTestHarness_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(790207519U));
  ssSetChecksum1(S,(3826965466U));
  ssSetChecksum2(S,(2415752099U));
  ssSetChecksum3(S,(4175461737U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_AreaCoverageTestHarness(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_AreaCoverageTestHarness(SimStruct *S)
{
  SFc7_AreaCoverageTestHarnessInstanceStruct *chartInstance;
  chartInstance = (SFc7_AreaCoverageTestHarnessInstanceStruct *)utMalloc(sizeof
    (SFc7_AreaCoverageTestHarnessInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_AreaCoverageTestHarnessInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_AreaCoverageTestHarness;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_AreaCoverageTestHarness;
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
  mdl_start_c7_AreaCoverageTestHarness(chartInstance);
}

void c7_AreaCoverageTestHarness_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_AreaCoverageTestHarness(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_AreaCoverageTestHarness(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_AreaCoverageTestHarness(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_AreaCoverageTestHarness_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
