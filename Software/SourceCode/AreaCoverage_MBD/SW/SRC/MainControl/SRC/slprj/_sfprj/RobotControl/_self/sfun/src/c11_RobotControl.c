/* Include files */

#include "RobotControl_sfun.h"
#include "c11_RobotControl.h"
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
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void initialize_params_c11_RobotControl(SFc11_RobotControlInstanceStruct *
  chartInstance);
static void enable_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void disable_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance);
static void set_sim_state_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance);
static void finalize_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void sf_gateway_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void mdl_start_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void initSimStructsc11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_b_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_RobotControl, const char_T *
  c11_identifier);
static uint8_T c11_c_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *c11_d_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier);
static const mxArray *c11_e_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc11_RobotControlInstanceStruct
  *chartInstance, int32_T c11_ssid);
static void c11_init_sf_message_store_memory(SFc11_RobotControlInstanceStruct
  *chartInstance);
static int16_T c11__s16_s32_(SFc11_RobotControlInstanceStruct *chartInstance,
  int32_T c11_b, uint32_T c11_ssid_src_loc, int32_T c11_offset_src_loc, int32_T
  c11_length_src_loc);
static void init_dsm_address_info(SFc11_RobotControlInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc11_RobotControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc11_RobotControl(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_is_active_c11_RobotControl = 0U;
}

static void initialize_params_c11_RobotControl(SFc11_RobotControlInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  uint8_T c11_hoistedGlobal;
  const mxArray *c11_b_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(1, 1), false);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_RobotControl;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  chartInstance->c11_is_active_c11_RobotControl = c11_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c11_RobotControl",
       c11_u, 0)), "is_active_c11_RobotControl");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c11_u, 1)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_RobotControl(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_RobotControl
  (SFc11_RobotControlInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  c11_set_sim_state_side_effects_c11_RobotControl(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c11_value, 1U, 1U, 0U,
                        c11__s16_s32_(chartInstance, chartInstance->c11_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c11_pin, 0U, 1U, 0U,
                        c11__s16_s32_(chartInstance, chartInstance->c11_sfEvent,
    0U, 0U, 0U), false);
  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  digitalWrite(*chartInstance->c11_pin, *chartInstance->c11_value);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RobotControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  c11_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc11_RobotControl(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

const mxArray *sf_c11_RobotControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc11_RobotControlInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i0, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc11_RobotControlInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc11_RobotControlInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc11_RobotControlInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_b_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_RobotControl, const char_T *
  c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_RobotControl), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_RobotControl);
  return c11_y;
}

static uint8_T c11_c_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static const mxArray *c11_d_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  sf_mex_assign(&c11_y, c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_e_emlrt_marshallIn(SFc11_RobotControlInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc11_RobotControlInstanceStruct
  *chartInstance, int32_T c11_ssid)
{
  const mxArray *c11_msgInfo;
  (void)chartInstance;
  (void)c11_ssid;
  c11_msgInfo = NULL;
  return NULL;
}

static void c11_init_sf_message_store_memory(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static int16_T c11__s16_s32_(SFc11_RobotControlInstanceStruct *chartInstance,
  int32_T c11_b, uint32_T c11_ssid_src_loc, int32_T c11_offset_src_loc, int32_T
  c11_length_src_loc)
{
  int16_T c11_a;
  c11_a = (int16_T)c11_b;
  if (c11_a != c11_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, 1U, c11_ssid_src_loc,
      c11_offset_src_loc, c11_length_src_loc, 0U, chartInstance->c11_sfEvent,
      false);
  }

  return c11_a;
}

static void init_dsm_address_info(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc11_RobotControlInstanceStruct
  *chartInstance)
{
  chartInstance->c11_pin = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_value = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c11_RobotControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2132403771U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3677859283U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(816158511U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4032794491U);
}

mxArray* sf_c11_RobotControl_get_post_codegen_info(void);
mxArray *sf_c11_RobotControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xZsoRweLLcEngpqr1Zs9KE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c11_RobotControl_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_RobotControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_RobotControl_jit_fallback_info(void)
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

mxArray *sf_c11_RobotControl_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_RobotControl_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_RobotControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c11_RobotControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_RobotControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc11_RobotControlInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_RobotControlInstanceStruct *chartInstance =
      (SFc11_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RobotControlMachineNumber_,
           11,
           0,
           2,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"pin");
          _SFD_SET_DATA_PROPS(1,1,1,0,"value");
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
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
    SFc11_RobotControlInstanceStruct *chartInstance =
      (SFc11_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c11_pin);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_value);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "szKMI2mjbkz737ciECFk46F";
}

static void sf_opaque_initialize_c11_RobotControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_RobotControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
    chartInstanceVar);
  initialize_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_RobotControl(void *chartInstanceVar)
{
  enable_c11_RobotControl((SFc11_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_RobotControl(void *chartInstanceVar)
{
  disable_c11_RobotControl((SFc11_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_RobotControl(void *chartInstanceVar)
{
  sf_gateway_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_RobotControl(SimStruct* S)
{
  return get_sim_state_c11_RobotControl((SFc11_RobotControlInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_RobotControl(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c11_RobotControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_RobotControlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RobotControl_optimization_info();
    }

    finalize_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
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
  initSimStructsc11_RobotControl((SFc11_RobotControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_RobotControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_RobotControl((SFc11_RobotControlInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c11_RobotControl(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RobotControl_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 11);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2910060979U));
  ssSetChecksum1(S,(3542098911U));
  ssSetChecksum2(S,(1740031337U));
  ssSetChecksum3(S,(536516174U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_RobotControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_RobotControl(SimStruct *S)
{
  SFc11_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc11_RobotControlInstanceStruct *)utMalloc(sizeof
    (SFc11_RobotControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc11_RobotControlInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_RobotControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_RobotControl;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_RobotControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_RobotControl;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_RobotControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_RobotControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_RobotControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_RobotControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_RobotControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_RobotControl;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_RobotControl;
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
  mdl_start_c11_RobotControl(chartInstance);
}

void c11_RobotControl_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_RobotControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_RobotControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_RobotControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_RobotControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
