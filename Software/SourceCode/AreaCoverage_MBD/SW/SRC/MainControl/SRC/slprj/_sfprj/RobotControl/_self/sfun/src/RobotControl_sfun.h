#ifndef __RobotControl_sfun_h__
#define __RobotControl_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "sf_runtime/sf_runtime_errors.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtClientServerAPIBridge.h"
#include "sf_runtime/sfc_sdi.h"
#include "sf_runtime/sf_test_language.h"
#include "multiword_types.h"
#include "sf_runtime/sfc_messages.h"
#include "sf_runtime/sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

struct SfDebugInstanceStruct;
extern struct SfDebugInstanceStruct* sfGlobalDebugInstanceStruct;

/* Custom Code from Simulation Target dialog*/
#ifndef MATLAB_MEX_FILE
#include "../Wire.h"
#include "../Wire.cpp"
#include "../HMC5883L.h"
#include "../HMC5883L.cpp"
#include "../twi.h"
#include "../twi.c"

HMC5883L Compass;

#include "../I_O_Wrapper.h"
#include "../I_O_Wrapper.c"
#else
#include "I_O_Wrapper.h"
#endif

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */
extern uint32_T _RobotControlMachineNumber_;

/* Variable Definitions */

/* Function Declarations */
extern void RobotControl_initializer(void);
extern void RobotControl_terminator(void);

/* Function Definitions */

/* We load infoStruct for rtw_optimation_info on demand in mdlSetWorkWidths and
   free it immediately in mdlStart. Given that this is machine-wide as
   opposed to chart specific, we use NULL check to make sure it gets loaded
   and unloaded once per machine even though the  methods mdlSetWorkWidths/mdlStart
   are chart/instance specific. The following methods abstract this out. */
extern mxArray* load_RobotControl_optimization_info(boolean_T isRtwGen,
  boolean_T isModelRef, boolean_T isExternal);
extern void unload_RobotControl_optimization_info(void);

#endif
