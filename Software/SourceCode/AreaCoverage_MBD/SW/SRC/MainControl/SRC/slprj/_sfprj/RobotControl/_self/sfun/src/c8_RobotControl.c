/* Include files */

#include "RobotControl_sfun.h"
#include "c8_RobotControl.h"
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
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void initialize_params_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void enable_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void disable_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance);
static void set_sim_state_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void c8_set_sim_state_side_effects_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance);
static void finalize_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void sf_gateway_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void mdl_start_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void initSimStructsc8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static int32_T c8_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_b_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_RobotControl, const char_T
  *c8_identifier);
static uint8_T c8_c_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *c8_d_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier);
static const mxArray *c8_e_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc8_RobotControlInstanceStruct *
  chartInstance, int32_T c8_ssid);
static void c8_init_sf_message_store_memory(SFc8_RobotControlInstanceStruct
  *chartInstance);
static int16_T c8__s16_s32_(SFc8_RobotControlInstanceStruct *chartInstance,
  int32_T c8_b, uint32_T c8_ssid_src_loc, int32_T c8_offset_src_loc, int32_T
  c8_length_src_loc);
static void init_dsm_address_info(SFc8_RobotControlInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc8_RobotControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_RobotControl(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_is_active_c8_RobotControl = 0U;
}

static void initialize_params_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  uint8_T c8_hoistedGlobal;
  const mxArray *c8_b_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(1, 1), false);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_RobotControl;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  chartInstance->c8_is_active_c8_RobotControl = c8_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c8_RobotControl", c8_u,
       0)), "is_active_c8_RobotControl");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c8_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_RobotControl(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_RobotControl
  (SFc8_RobotControlInstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  c8_set_sim_state_side_effects_c8_RobotControl(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_value, 1U, 1U, 0U,
                        c8__s16_s32_(chartInstance, chartInstance->c8_sfEvent,
    0U, 0U, 0U), false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_pin, 0U, 1U, 0U, c8__s16_s32_
                        (chartInstance, chartInstance->c8_sfEvent, 0U, 0U, 0U),
                        false);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  digitalWrite(*chartInstance->c8_pin, *chartInstance->c8_value);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RobotControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  c8_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc8_RobotControl(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

const mxArray *sf_c8_RobotControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_RobotControlInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i0, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_RobotControlInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent), &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_RobotControlInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_b_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_RobotControl, const char_T
  *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_RobotControl), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_RobotControl);
  return c8_y;
}

static uint8_T c8_c_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *c8_d_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  sf_mex_assign(&c8_y, c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_e_emlrt_marshallIn(SFc8_RobotControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc8_RobotControlInstanceStruct *
  chartInstance, int32_T c8_ssid)
{
  const mxArray *c8_msgInfo;
  (void)chartInstance;
  (void)c8_ssid;
  c8_msgInfo = NULL;
  return NULL;
}

static void c8_init_sf_message_store_memory(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static int16_T c8__s16_s32_(SFc8_RobotControlInstanceStruct *chartInstance,
  int32_T c8_b, uint32_T c8_ssid_src_loc, int32_T c8_offset_src_loc, int32_T
  c8_length_src_loc)
{
  int16_T c8_a;
  c8_a = (int16_T)c8_b;
  if (c8_a != c8_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, 1U, c8_ssid_src_loc,
      c8_offset_src_loc, c8_length_src_loc, 0U, chartInstance->c8_sfEvent, false);
  }

  return c8_a;
}

static void init_dsm_address_info(SFc8_RobotControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_RobotControlInstanceStruct
  *chartInstance)
{
  chartInstance->c8_pin = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_value = (uint8_T *)ssGetInputPortSignal_wrapper
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

void sf_c8_RobotControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1634119066U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(173470900U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3267524122U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4075131573U);
}

mxArray* sf_c8_RobotControl_get_post_codegen_info(void);
mxArray *sf_c8_RobotControl_get_autoinheritance_info(void)
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
    mxArray* mxPostCodegenInfo = sf_c8_RobotControl_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_RobotControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_RobotControl_jit_fallback_info(void)
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

mxArray *sf_c8_RobotControl_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_RobotControl_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c8_RobotControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c8_RobotControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_RobotControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc8_RobotControlInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_RobotControlInstanceStruct *chartInstance =
      (SFc8_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RobotControlMachineNumber_,
           8,
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
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
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
    SFc8_RobotControlInstanceStruct *chartInstance =
      (SFc8_RobotControlInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c8_pin);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_value);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s3ZYg70EROfYfvwiis6cCdE";
}

static void sf_opaque_initialize_c8_RobotControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_RobotControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_RobotControl((SFc8_RobotControlInstanceStruct*)
    chartInstanceVar);
  initialize_c8_RobotControl((SFc8_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_RobotControl(void *chartInstanceVar)
{
  enable_c8_RobotControl((SFc8_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_RobotControl(void *chartInstanceVar)
{
  disable_c8_RobotControl((SFc8_RobotControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_RobotControl(void *chartInstanceVar)
{
  sf_gateway_c8_RobotControl((SFc8_RobotControlInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_RobotControl(SimStruct* S)
{
  return get_sim_state_c8_RobotControl((SFc8_RobotControlInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_RobotControl(SimStruct* S, const mxArray *
  st)
{
  set_sim_state_c8_RobotControl((SFc8_RobotControlInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_RobotControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_RobotControlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RobotControl_optimization_info();
    }

    finalize_c8_RobotControl((SFc8_RobotControlInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_RobotControl((SFc8_RobotControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_RobotControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_RobotControl((SFc8_RobotControlInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_RobotControl(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RobotControl_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 8);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1704445925U));
  ssSetChecksum1(S,(4174940780U));
  ssSetChecksum2(S,(3305723205U));
  ssSetChecksum3(S,(4173745260U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_RobotControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_RobotControl(SimStruct *S)
{
  SFc8_RobotControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_RobotControlInstanceStruct *)utMalloc(sizeof
    (SFc8_RobotControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_RobotControlInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_RobotControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_RobotControl;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_RobotControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_RobotControl;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_RobotControl;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_RobotControl;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_RobotControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_RobotControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_RobotControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_RobotControl;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_RobotControl;
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
  mdl_start_c8_RobotControl(chartInstance);
}

void c8_RobotControl_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_RobotControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_RobotControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_RobotControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_RobotControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
