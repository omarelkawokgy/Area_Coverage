/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "RobotControl_sfun.h"
#include "RobotControl_sfun_debug_macros.h"
#include "c1_RobotControl.h"
#include "c2_RobotControl.h"
#include "c3_RobotControl.h"
#include "c4_RobotControl.h"
#include "c5_RobotControl.h"
#include "c6_RobotControl.h"
#include "c7_RobotControl.h"
#include "c8_RobotControl.h"
#include "c9_RobotControl.h"
#include "c10_RobotControl.h"
#include "c11_RobotControl.h"
#include "c12_RobotControl.h"
#include "c13_RobotControl.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _RobotControlMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void RobotControl_initializer(void)
{
}

void RobotControl_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_RobotControl_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_RobotControl_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_RobotControl_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3786055092U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2905121894U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(707328548U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(195702758U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c1_RobotControl_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c2_RobotControl_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c3_RobotControl_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c4_RobotControl_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c5_RobotControl_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c6_RobotControl_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c7_RobotControl_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c8_RobotControl_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c9_RobotControl_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c10_RobotControl_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c11_RobotControl_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c12_RobotControl_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_RobotControl_get_check_sum(mxArray *plhs[]);
          sf_c13_RobotControl_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2790825387U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3851109458U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(98292063U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1087473928U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2623064999U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1139033878U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(669470925U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1013644180U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RobotControl_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "DUHQXVl7Q7KZobrkdkWCuC") == 0) {
          extern mxArray *sf_c1_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c1_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "3u2Q3DI3BLMR8qzdoX1PiE") == 0) {
          extern mxArray *sf_c2_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c2_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "lYwPInO3hvNu0Pu8z823L") == 0) {
          extern mxArray *sf_c3_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c3_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "3u2Q3DI3BLMR8qzdoX1PiE") == 0) {
          extern mxArray *sf_c4_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c4_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "1oLOqZl62B2t9QVESXPflF") == 0) {
          extern mxArray *sf_c5_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c5_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "5dLmKswmulcCDkVpJI4tL") == 0) {
          extern mxArray *sf_c6_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c6_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c7_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c7_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c8_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c8_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c9_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c9_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c10_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c10_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c11_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c11_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "xZsoRweLLcEngpqr1Zs9KE") == 0) {
          extern mxArray *sf_c12_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c12_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "Azl0qxpNVQU3B1eYLda7hH") == 0) {
          extern mxArray *sf_c13_RobotControl_get_autoinheritance_info(void);
          plhs[0] = sf_c13_RobotControl_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RobotControl_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_RobotControl_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_RobotControl_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_RobotControl_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_RobotControl_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_RobotControl_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_RobotControl_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RobotControl_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "s6ApVLlTwTzn93P9BTmEd5F") == 0) {
          extern mxArray *sf_c1_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c1_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c2_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c2_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sfJm9vj84ZU5HzO6TQzBe") == 0) {
          extern mxArray *sf_c3_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c3_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c4_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c4_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sXUxiGRXkeDnbtGCwmMgx6C") == 0) {
          extern mxArray *sf_c5_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c5_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "s2Q8MPFv0pT5LPQxDljj5pH") == 0) {
          extern mxArray *sf_c6_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c6_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c7_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c7_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c8_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c8_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c9_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c9_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c10_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c10_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c11_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c11_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c12_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c12_RobotControl_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "s4SonXTrAceyIQmJGfnSDkH") == 0) {
          extern mxArray *sf_c13_RobotControl_third_party_uses_info(void);
          plhs[0] = sf_c13_RobotControl_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_RobotControl_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "s6ApVLlTwTzn93P9BTmEd5F") == 0) {
          extern mxArray *sf_c1_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c1_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c2_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c2_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sfJm9vj84ZU5HzO6TQzBe") == 0) {
          extern mxArray *sf_c3_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c3_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c4_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c4_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sXUxiGRXkeDnbtGCwmMgx6C") == 0) {
          extern mxArray *sf_c5_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c5_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "s2Q8MPFv0pT5LPQxDljj5pH") == 0) {
          extern mxArray *sf_c6_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c6_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c7_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c7_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c8_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c8_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c9_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c9_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c10_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c10_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c11_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c11_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c12_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c12_RobotControl_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "s4SonXTrAceyIQmJGfnSDkH") == 0) {
          extern mxArray *sf_c13_RobotControl_jit_fallback_info(void);
          plhs[0] = sf_c13_RobotControl_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_RobotControl_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "s6ApVLlTwTzn93P9BTmEd5F") == 0) {
          extern mxArray *sf_c1_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c2_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sfJm9vj84ZU5HzO6TQzBe") == 0) {
          extern mxArray *sf_c3_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sPG440WmGnlooYnOtfG2WqF") == 0) {
          extern mxArray *sf_c4_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sXUxiGRXkeDnbtGCwmMgx6C") == 0) {
          extern mxArray *sf_c5_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "s2Q8MPFv0pT5LPQxDljj5pH") == 0) {
          extern mxArray *sf_c6_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c7_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c8_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c9_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "s3ZYg70EROfYfvwiis6cCdE") == 0) {
          extern mxArray *sf_c10_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c11_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "szKMI2mjbkz737ciECFk46F") == 0) {
          extern mxArray *sf_c12_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "s4SonXTrAceyIQmJGfnSDkH") == 0) {
          extern mxArray *sf_c13_RobotControl_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_RobotControl_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void RobotControl_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _RobotControlMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "RobotControl","sfun",0,14,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _RobotControlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_RobotControlMachineNumber_,
    0);
}

void RobotControl_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_RobotControl_optimization_info(void);
mxArray* load_RobotControl_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_RobotControl_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("RobotControl",
      "RobotControl");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_RobotControl_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
