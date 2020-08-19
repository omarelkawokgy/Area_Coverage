/* Include files */

#include "RobotControl_sfun.h"
#include "c13_RobotControl.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "RobotControl_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c13_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c13_IN_ReadEEPROM              ((uint8_T)1U)
#define c13_IN_UpdateEEPROM            ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void initialize_params_c13_RobotControl(SFc13_RobotControlInstanceStruct *
  chartInstance);
static void enable_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void disable_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void c13_update_debugger_state_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance);
static void set_sim_state_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_st);
static void c13_set_sim_state_side_effects_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance);
static void finalize_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void sf_gateway_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void mdl_start_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void initSimStructsc13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static uint8_T c13_b_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_ReadEEPROM, const char_T
  *c13_identifier);
static uint8_T c13_c_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static boolean_T c13_d_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_NVM_AngleStoreFlg, const char_T
  *c13_identifier);
static boolean_T c13_e_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int16_T c13_f_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_NVM_NORTH, const char_T *c13_identifier);
static int16_T c13_g_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_h_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_setSimStateSideEffectsInfo, const char_T *
  c13_identifier);
static const mxArray *c13_i_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc13_RobotControlInstanceStruct
  *chartInstance, int32_T c13_ssid);
static void c13_init_sf_message_store_memory(SFc13_RobotControlInstanceStruct
  *chartInstance);
static int16_T c13__s16_s32_(SFc13_RobotControlInstanceStruct *chartInstance,
  int32_T c13_b, uint32_T c13_ssid_src_loc, int32_T c13_offset_src_loc, int32_T
  c13_length_src_loc);
static void init_dsm_address_info(SFc13_RobotControlInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc13_RobotControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc13_RobotControl(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_doSetSimStateSideEffects = 0U;
  chartInstance->c13_setSimStateSideEffectsInfo = NULL;
  chartInstance->c13_tp_ReadEEPROM = 0U;
  chartInstance->c13_tp_UpdateEEPROM = 0U;
  chartInstance->c13_is_active_c13_RobotControl = 0U;
  chartInstance->c13_is_c13_RobotControl = c13_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c13_NVM_AngleStoreFlg = false;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c13_NVM_AngleStoreFlg,
      5U, 1U, 12U, c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent, 0U,
      0U, 0U), false, 0.0, 1.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c13_NVM_NORTH = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c13_NVM_NORTH, 6U, 1U,
      12U, c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent, 0U, 0U, 0U),
      false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c13_NVM_SOUTH = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c13_NVM_SOUTH, 7U, 1U,
      12U, c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent, 0U, 0U, 0U),
      false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c13_NVM_EAST = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c13_NVM_EAST, 8U, 1U,
      12U, c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent, 0U, 0U, 0U),
      false, -20.0, 360.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c13_NVM_WEST = 0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c13_NVM_WEST, 9U, 1U,
      12U, c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent, 0U, 0U, 0U),
      false, -20.0, 360.0, 0U, 0, 0);
  }
}

static void initialize_params_c13_RobotControl(SFc13_RobotControlInstanceStruct *
  chartInstance)
{
  real_T c13_d0;
  sf_mex_import_named("ENU_FINISHED", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c13_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c13_ENU_FINISHED = (uint8_T)c13_d0;
}

static void enable_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance)
{
  uint32_T c13_prevAniVal;
  c13_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c13_is_active_c13_RobotControl == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 12U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_c13_RobotControl == c13_IN_ReadEEPROM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_c13_RobotControl == c13_IN_UpdateEEPROM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  }

  _SFD_SET_ANIMATION(c13_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  boolean_T c13_hoistedGlobal;
  const mxArray *c13_b_y = NULL;
  int16_T c13_b_hoistedGlobal;
  const mxArray *c13_c_y = NULL;
  int16_T c13_c_hoistedGlobal;
  const mxArray *c13_d_y = NULL;
  int16_T c13_d_hoistedGlobal;
  const mxArray *c13_e_y = NULL;
  int16_T c13_e_hoistedGlobal;
  const mxArray *c13_f_y = NULL;
  uint8_T c13_f_hoistedGlobal;
  const mxArray *c13_g_y = NULL;
  uint8_T c13_g_hoistedGlobal;
  const mxArray *c13_h_y = NULL;
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(7, 1), false);
  c13_hoistedGlobal = *chartInstance->c13_NVM_AngleStoreFlg;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = *chartInstance->c13_NVM_EAST;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = *chartInstance->c13_NVM_NORTH;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = *chartInstance->c13_NVM_SOUTH;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_hoistedGlobal = *chartInstance->c13_NVM_WEST;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 4, c13_f_y);
  c13_f_hoistedGlobal = chartInstance->c13_is_active_c13_RobotControl;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 5, c13_g_y);
  c13_g_hoistedGlobal = chartInstance->c13_is_c13_RobotControl;
  c13_h_y = NULL;
  sf_mex_assign(&c13_h_y, sf_mex_create("y", &c13_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c13_y, 6, c13_h_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  c13_u = sf_mex_dup(c13_st);
  *chartInstance->c13_NVM_AngleStoreFlg = c13_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_AngleStoreFlg", c13_u, 0)),
    "NVM_AngleStoreFlg");
  *chartInstance->c13_NVM_EAST = c13_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_EAST", c13_u, 1)), "NVM_EAST");
  *chartInstance->c13_NVM_NORTH = c13_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_NORTH", c13_u, 2)), "NVM_NORTH");
  *chartInstance->c13_NVM_SOUTH = c13_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_SOUTH", c13_u, 3)), "NVM_SOUTH");
  *chartInstance->c13_NVM_WEST = c13_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("NVM_WEST", c13_u, 4)), "NVM_WEST");
  chartInstance->c13_is_active_c13_RobotControl = c13_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c13_RobotControl",
       c13_u, 5)), "is_active_c13_RobotControl");
  chartInstance->c13_is_c13_RobotControl = c13_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c13_RobotControl", c13_u, 6)),
    "is_c13_RobotControl");
  sf_mex_assign(&chartInstance->c13_setSimStateSideEffectsInfo,
                c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c13_u, 7)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c13_u);
  chartInstance->c13_doSetSimStateSideEffects = 1U;
  c13_update_debugger_state_c13_RobotControl(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void c13_set_sim_state_side_effects_c13_RobotControl
  (SFc13_RobotControlInstanceStruct *chartInstance)
{
  if (chartInstance->c13_doSetSimStateSideEffects != 0) {
    chartInstance->c13_tp_ReadEEPROM = (uint8_T)
      (chartInstance->c13_is_c13_RobotControl == c13_IN_ReadEEPROM);
    chartInstance->c13_tp_UpdateEEPROM = (uint8_T)
      (chartInstance->c13_is_c13_RobotControl == c13_IN_UpdateEEPROM);
    chartInstance->c13_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c13_setSimStateSideEffectsInfo);
}

static void sf_gateway_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  boolean_T c13_out;
  c13_set_sim_state_side_effects_c13_RobotControl(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_angleCalib_WEST, 4U, 1U, 0U,
                        c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_angleCalib_EAST, 3U, 1U, 0U,
                        c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_angleCalib_SOUTH, 2U, 1U, 0U,
                        c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_angleCalib_NORTH, 1U, 1U, 0U,
                        c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_angleCalibStatus, 0U, 1U, 0U,
                        c13__s16_s32_(chartInstance, chartInstance->c13_sfEvent,
    0U, 0U, 0U), false);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  if (chartInstance->c13_is_active_c13_RobotControl == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
    chartInstance->c13_is_active_c13_RobotControl = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
    chartInstance->c13_is_c13_RobotControl = c13_IN_ReadEEPROM;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
    chartInstance->c13_tp_ReadEEPROM = 1U;
    EEPROM_Read_Wrapper(chartInstance->c13_NVM_AngleStoreFlg,
                        chartInstance->c13_NVM_NORTH,
                        chartInstance->c13_NVM_SOUTH,
                        chartInstance->c13_NVM_EAST, chartInstance->c13_NVM_WEST);
  } else {
    switch (chartInstance->c13_is_c13_RobotControl) {
     case c13_IN_ReadEEPROM:
      CV_CHART_EVAL(12, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c13_sfEvent);
      c13_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
                           *chartInstance->c13_angleCalibStatus, (real_T)
                           chartInstance->c13_ENU_FINISHED, 0, 0U,
                           *chartInstance->c13_angleCalibStatus ==
                           chartInstance->c13_ENU_FINISHED) != 0U,
        chartInstance->c13_sfEvent)) != 0);
      if (c13_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
        chartInstance->c13_tp_ReadEEPROM = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
        chartInstance->c13_is_c13_RobotControl = c13_IN_UpdateEEPROM;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
        chartInstance->c13_tp_UpdateEEPROM = 1U;
        EEPROM_Update_Wrapper(*chartInstance->c13_angleCalib_NORTH,
                              *chartInstance->c13_angleCalib_SOUTH,
                              *chartInstance->c13_angleCalib_EAST,
                              *chartInstance->c13_angleCalib_WEST);
        EEPROM_Read_Wrapper(chartInstance->c13_NVM_AngleStoreFlg,
                            chartInstance->c13_NVM_NORTH,
                            chartInstance->c13_NVM_SOUTH,
                            chartInstance->c13_NVM_EAST,
                            chartInstance->c13_NVM_WEST);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c13_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
      break;

     case c13_IN_UpdateEEPROM:
      CV_CHART_EVAL(12, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c13_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c13_sfEvent);
      break;

     default:
      CV_CHART_EVAL(12, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c13_is_c13_RobotControl = c13_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RobotControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  c13_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc13_RobotControl(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

const mxArray *sf_c13_RobotControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  uint8_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint8_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static uint8_T c13_b_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_ReadEEPROM, const char_T
  *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_ReadEEPROM),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_ReadEEPROM);
  return c13_y;
}

static uint8_T c13_c_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_tp_ReadEEPROM;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  uint8_T c13_y;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_b_tp_ReadEEPROM = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_ReadEEPROM),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_ReadEEPROM);
  *(uint8_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  uint16_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint16_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static boolean_T c13_d_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_NVM_AngleStoreFlg, const char_T
  *c13_identifier)
{
  boolean_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_NVM_AngleStoreFlg), &c13_thisId);
  sf_mex_destroy(&c13_b_NVM_AngleStoreFlg);
  return c13_y;
}

static boolean_T c13_e_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  boolean_T c13_y;
  boolean_T c13_b0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_b0, 1, 11, 0U, 0, 0U, 0);
  c13_y = c13_b0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_NVM_AngleStoreFlg;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  boolean_T c13_y;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_b_NVM_AngleStoreFlg = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_NVM_AngleStoreFlg), &c13_thisId);
  sf_mex_destroy(&c13_b_NVM_AngleStoreFlg);
  *(boolean_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  int16_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(int16_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 4, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int16_T c13_f_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_NVM_NORTH, const char_T *c13_identifier)
{
  int16_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_NVM_NORTH),
    &c13_thisId);
  sf_mex_destroy(&c13_b_NVM_NORTH);
  return c13_y;
}

static int16_T c13_g_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int16_T c13_y;
  int16_T c13_i1;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i1, 1, 4, 0U, 0, 0U, 0);
  c13_y = c13_i1;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_NVM_NORTH;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int16_T c13_y;
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)chartInstanceVoid;
  c13_b_NVM_NORTH = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_NVM_NORTH),
    &c13_thisId);
  sf_mex_destroy(&c13_b_NVM_NORTH);
  *(int16_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_h_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_b_setSimStateSideEffectsInfo, const char_T *
  c13_identifier)
{
  const mxArray *c13_y = NULL;
  emlrtMsgIdentifier c13_thisId;
  c13_y = NULL;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  sf_mex_assign(&c13_y, c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_setSimStateSideEffectsInfo), &c13_thisId), false);
  sf_mex_destroy(&c13_b_setSimStateSideEffectsInfo);
  return c13_y;
}

static const mxArray *c13_i_emlrt_marshallIn(SFc13_RobotControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  const mxArray *c13_y = NULL;
  (void)chartInstance;
  (void)c13_parentId;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_duplicatearraysafe(&c13_u), false);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc13_RobotControlInstanceStruct
  *chartInstance, int32_T c13_ssid)
{
  const mxArray *c13_msgInfo;
  (void)chartInstance;
  (void)c13_ssid;
  c13_msgInfo = NULL;
  return NULL;
}

static void c13_init_sf_message_store_memory(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static int16_T c13__s16_s32_(SFc13_RobotControlInstanceStruct *chartInstance,
  int32_T c13_b, uint32_T c13_ssid_src_loc, int32_T c13_offset_src_loc, int32_T
  c13_length_src_loc)
{
  int16_T c13_a;
  c13_a = (int16_T)c13_b;
  if (c13_a != c13_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, 1U, c13_ssid_src_loc,
      c13_offset_src_loc, c13_length_src_loc, 0U, chartInstance->c13_sfEvent,
      false);
  }

  return c13_a;
}

static void init_dsm_address_info(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc13_RobotControlInstanceStruct
  *chartInstance)
{
  chartInstance->c13_angleCalibStatus = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c13_angleCalib_NORTH = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_angleCalib_SOUTH = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c13_angleCalib_EAST = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c13_angleCalib_WEST = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c13_NVM_AngleStoreFlg = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c13_NVM_NORTH = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c13_NVM_SOUTH = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c13_NVM_EAST = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c13_NVM_WEST = (int16_T *)ssGetOutputPortSignal_wrapper
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

void sf_c13_RobotControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4183247448U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(268782029U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2560315485U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1995307594U);
}

mxArray* sf_c13_RobotControl_get_post_codegen_info(void);
mxArray *sf_c13_RobotControl_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c13_RobotControl_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_RobotControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_RobotControl_jit_fallback_info(void)
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

mxArray *sf_c13_RobotControl_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c13_RobotControl_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c13_RobotControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[15],T\"NVM_AngleStoreFlg\",},{M[1],M[18],T\"NVM_EAST\",},{M[1],M[16],T\"NVM_NORTH\",},{M[1],M[17],T\"NVM_SOUTH\",},{M[1],M[19],T\"NVM_WEST\",},{M[8],M[0],T\"is_active_c13_RobotControl\",},{M[9],M[0],T\"is_c13_RobotControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_RobotControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc13_RobotControlInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_RobotControlInstanceStruct *chartInstance =
      (SFc13_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RobotControlMachineNumber_,
           13,
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
        init_script_number_translation(_RobotControlMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_RobotControlMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _RobotControlMachineNumber_,
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

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)
          c13_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)
          c13_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)
          c13_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)
          c13_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)
          c13_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)
          c13_b_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _RobotControlMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_RobotControlInstanceStruct *chartInstance =
      (SFc13_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c13_angleCalibStatus);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c13_ENU_FINISHED);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c13_angleCalib_NORTH);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c13_angleCalib_SOUTH);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c13_angleCalib_EAST);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c13_angleCalib_WEST);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c13_NVM_AngleStoreFlg);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c13_NVM_NORTH);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c13_NVM_SOUTH);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c13_NVM_EAST);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c13_NVM_WEST);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s4SonXTrAceyIQmJGfnSDkH";
}

static void sf_opaque_initialize_c13_RobotControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_RobotControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
    chartInstanceVar);
  initialize_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_RobotControl(void *chartInstanceVar)
{
  enable_c13_RobotControl((SFc13_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_RobotControl(void *chartInstanceVar)
{
  disable_c13_RobotControl((SFc13_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_RobotControl(void *chartInstanceVar)
{
  sf_gateway_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c13_RobotControl(SimStruct* S)
{
  return get_sim_state_c13_RobotControl((SFc13_RobotControlInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c13_RobotControl(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c13_RobotControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_RobotControlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RobotControl_optimization_info();
    }

    finalize_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_RobotControl((SFc13_RobotControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_RobotControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_RobotControl((SFc13_RobotControlInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c13_RobotControl(SimStruct *S)
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
    mxArray *infoStruct = load_RobotControl_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 13);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,5);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3260086412U));
  ssSetChecksum1(S,(4132580387U));
  ssSetChecksum2(S,(1262337285U));
  ssSetChecksum3(S,(3718248276U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_RobotControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c13_RobotControl(SimStruct *S)
{
  SFc13_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_RobotControlInstanceStruct *)utMalloc(sizeof
    (SFc13_RobotControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc13_RobotControlInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_RobotControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_RobotControl;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_RobotControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_RobotControl;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_RobotControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_RobotControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_RobotControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_RobotControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_RobotControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_RobotControl;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_RobotControl;
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
  mdl_start_c13_RobotControl(chartInstance);
}

void c13_RobotControl_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_RobotControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_RobotControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_RobotControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_RobotControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
