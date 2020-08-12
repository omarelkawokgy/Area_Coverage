/*
 * File: RobotControl.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.568
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Aug 13 00:06:06 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RobotControl_h_
#define RTW_HEADER_RobotControl_h_
#include <stddef.h>
#include <string.h>
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Child system includes */
#include "COM_A4SCA_A5SCL.h"
#include "DIAG_Cont.h"
#include "DSCA.h"
#include "HeadingCalculator.h"
#include "HeadingsDirectionHandler.h"
#include "HighLevelRoutines.h"
#include "MovementHandler.h"
#include "ScanHandler.h"
#include "StopRoutine.h"
#include "motorHandler.h"
#include "thetaFilter.h"

/* Includes for objects with custom storage classes. */
#include "Params.h"
#include "Constant.h"
#include "Enums.h"
#include "MISC.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#ifndef MATLAB_MEX_FILE
#include "../Wire.h"
#include "../Wire.cpp"
#include "../HMC5883L.h"
#include "../HMC5883L.cpp"
#include "../twi.h"
#include "../twi.c"
#include "../EEPROM.h"
#include "../EEPROM.cpp"

HMC5883L Compass;

#include "../I_O_Wrapper.h"
#include "../I_O_Wrapper.c"
#else
#include "I_O_Wrapper.h"
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add1;                         /* '<S54>/Add1' */
  real_T deg;                          /* '<S64>/Product' */
  real_T Add5;                         /* '<S66>/Add5' */
  real32_T thetaError;                 /* '<S28>/Switch' */
  real32_T theta_Deg;                  /* '<S36>/Saturation' */
  real32_T theta_mDeg;                 /* '<S36>/Gain' */
  real32_T Data_Type_Conversion;       /* '<S60>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion_m;     /* '<S61>/Data_Type_Conversion' */
  real32_T rightVel1ms_mmPerSec;       /* '<S86>/Data_Type_Conversion3' */
  real32_T leftVel1ms_mmPerSec;        /* '<S77>/Data_Type_Conversion2' */
  real32_T EOL_pwm;                    /* '<S69>/EOL_TickStateMachine' */
  real32_T Data_Type_Conversion_a;     /* '<S66>/Data_Type_Conversion' */
  real32_T motorDistance;              /* '<S58>/Gain1' */
  int16_T DataTypeConversion_p;        /* '<S7>/Data Type Conversion' */
  int16_T DataTypeConversion1_b;       /* '<S7>/Data Type Conversion1' */
  int16_T DataTypeConversion2_g;       /* '<S7>/Data Type Conversion2' */
  int16_T DataTypeConversion3_j;       /* '<S7>/Data Type Conversion3' */
  int16_T NVM_NORTH;                   /* '<S7>/EEPROM_IO_Handler_Chart' */
  int16_T NVM_SOUTH;                   /* '<S7>/EEPROM_IO_Handler_Chart' */
  int16_T NVM_EAST;                    /* '<S7>/EEPROM_IO_Handler_Chart' */
  int16_T NVM_WEST;                    /* '<S7>/EEPROM_IO_Handler_Chart' */
  int16_T ROB_NORTH;                   /* '<S26>/Signal Conversion' */
  int16_T ROB_SOUTH;                   /* '<S26>/Signal Conversion1' */
  int16_T ROB_EAST;                    /* '<S26>/Signal Conversion2' */
  int16_T ROB_WEST;                    /* '<S26>/Signal Conversion3' */
  int16_T rawCompassValue;             /* '<S5>/COM_A4SCA_A5SCL_Chart' */
  uint16_T UnitDelay;                  /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  uint16_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  uint16_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  uint16_T OutportBufferForangleCalib_EAST;/* '<S27>/DIAG_Routine' */
  uint16_T OutportBufferForangleCalib_NORT;/* '<S27>/DIAG_Routine' */
  uint16_T OutportBufferForangleCalib_SOUT;/* '<S27>/DIAG_Routine' */
  uint16_T OutportBufferForangleCalib_WEST;/* '<S27>/DIAG_Routine' */
  uint16_T OutportBufferForangleCalib_EA_j;/* '<S96>/Angle_Calibration' */
  uint16_T OutportBufferForangleCalib_NO_f;/* '<S96>/Angle_Calibration' */
  uint16_T OutportBufferForangleCalib_SO_i;/* '<S96>/Angle_Calibration' */
  uint16_T OutportBufferForangleCalib_WE_n;/* '<S96>/Angle_Calibration' */
  uint16_T OutportBufferForangleCalib_E_jq;/* '<S105>/Angle_CalibrationUponReq' */
  uint16_T OutportBufferForangleCalib_N_fy;/* '<S105>/Angle_CalibrationUponReq' */
  uint16_T OutportBufferForangleCalib_S_im;/* '<S105>/Angle_CalibrationUponReq' */
  uint16_T OutportBufferForangleCalib_W_nf;/* '<S105>/Angle_CalibrationUponReq' */
  uint16_T OutportBufferForangleCalib__jq3;/* '<S112>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib__fyn;/* '<S112>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib__im4;/* '<S112>/CompassSelfDiagTestChart' */
  uint16_T OutportBufferForangleCalib__nfn;/* '<S112>/CompassSelfDiagTestChart' */
  uint16_T NORTH;                      /* '<S112>/CompassSelfDiagTestChart' */
  uint16_T SOUTH;                      /* '<S112>/CompassSelfDiagTestChart' */
  uint16_T EAST;                       /* '<S112>/CompassSelfDiagTestChart' */
  uint16_T WEST;                       /* '<S112>/CompassSelfDiagTestChart' */
  uint16_T headingRequest;             /* '<S133>/HighLevelMoves' */
  uint16_T leftBlocks;                 /* '<S146>/Data_Type_Conversion' */
  uint16_T rightBlocks;                /* '<S146>/Data_Type_Conversion1' */
  uint16_T ULSR_cm;                    /* '<S9>/ULSR_D8R_D7L_Chart' */
  uint16_T ULSL_cm;                    /* '<S9>/ULSL_D8R_D7L_Chart' */
  uint16_T currentHeading;             /* '<S32>/HeadingCalculation' */
  uint16_T encoderCounter;             /* '<S70>/Data_Type_Conversion' */
  uint16_T rightEncoderTicks_uint16;   /* '<S8>/rightEncoderTicks_uint16_chart' */
  uint16_T leftEncoderTicks_uint16;    /* '<S8>/leftEncoderTicks_uint16_chart' */
  uint8_T UnitDelay4;                  /* '<S2>/Unit Delay4' */
  uint8_T leftPosPin;                  /* '<S151>/Switch' */
  uint8_T leftNegPin;                  /* '<S151>/Switch' */
  uint8_T rightPosPin;                 /* '<S152>/Switch' */
  uint8_T rightNegPin;                 /* '<S152>/Switch' */
  uint8_T Merge;                       /* '<S27>/Merge' */
  uint8_T moveRequest;                 /* '<S27>/Switch' */
  uint8_T OutportBufferForDIAG_StatusFlg;/* '<S96>/HighLevelTestRoutine' */
  uint8_T OutportBufferForangleCalibStatu;/* '<S105>/Angle_CalibrationUponReq' */
  uint8_T OutportBufferForangleCalibSta_a;/* '<S112>/CompassSelfDiagTestChart' */
  uint8_T OutportBufferFormoveRequest; /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T moveReq;                     /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T angleCalibStatus;            /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T encoderTstStatus;            /* '<S108>/Switch' */
  uint8_T moveReq_k;                   /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T comTstStatus;                /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T diagEnableReq;               /* '<S124>/HighLevelDiagTestControl' */
  uint8_T DIAG_StatusFlg;              /* '<S124>/HighLevelDiagTestControl' */
  uint8_T moveRequest_a;               /* '<S101>/GTSP_Chart' */
  uint8_T OutportBufferForswLaneCnt_uint8;/* '<S104>/ZgZgChart' */
  uint8_T moveRequest_c;               /* '<S104>/ZgZgChart' */
  uint8_T swLaneCnt_uint8;             /* '<S104>/ZgZgChart' */
  uint8_T currentRoutine;              /* '<S100>/MainStateMachine' */
  uint8_T sensorView;                  /* '<S99>/pumperHitSensorView' */
  uint8_T turnRequestFiltered;         /* '<S135>/Switch' */
  uint8_T rightMotorRequest;           /* '<S132>/Switch' */
  uint8_T leftMotorRequest;            /* '<S132>/Switch' */
  uint8_T turnRequest;                 /* '<S133>/HighLevelMoves' */
  uint8_T encoderStep;                 /* '<S136>/singleStepCalc' */
  uint8_T moveRequest_p;               /* '<S149>/stopRoutine' */
  uint8_T EOL_leftMoveReq;             /* '<S69>/EOL_TickStateMachine' */
  uint8_T EOL_rightMoveReq;            /* '<S69>/EOL_TickStateMachine' */
  boolean_T ULS_NotConnectedFlag_BOOL; /* '<S50>/Relational_Operator' */
  boolean_T ULS_NotConnectedFlag_BOOL_j;/* '<S51>/Relational_Operator' */
  boolean_T failFlag;                  /* '<S24>/Logical_Operator4' */
  boolean_T greenLED_BOOL;             /* '<S24>/Logical Operator2' */
  boolean_T redLED_BOOL;               /* '<S24>/Logical_Operator2' */
  boolean_T motorFaultFlag;            /* '<S48>/MotorMoveMonitor' */
  boolean_T motorFaultFlag_k;          /* '<S46>/MotorMoveMonitor' */
  boolean_T NVM_AngleStoreFlg;         /* '<S7>/EEPROM_IO_Handler_Chart' */
  boolean_T diagSensorFailure;         /* '<S27>/Data Type Conversion' */
  boolean_T OutportBufferForswitchLaneFlg_B;/* '<S27>/zigzagRoutine' */
  boolean_T hardwareFaultFlg;          /* '<S96>/Logical_Operator' */
  boolean_T OutportBufferForenableAngleCali;/* '<S96>/HighLevelTestRoutine' */
  boolean_T encoderDistErrorFlg_BOOL;  /* '<S118>/Logical_Operator' */
  boolean_T encoderDistErrorFlg_BOOL_m;/* '<S119>/Logical_Operator' */
  boolean_T compFaultFlag;             /* '<S114>/CompassSelfDiagTestChart' */
  boolean_T enableAngleCalib_BOOL;     /* '<S124>/HighLevelDiagTestControl' */
  boolean_T OutportBufferForGT_active; /* '<S101>/GTSP_Chart' */
  boolean_T GT_active;                 /* '<S101>/GTSP_Chart' */
  boolean_T OutportBufferForswitchLaneFlg_k;/* '<S104>/ZgZgChart' */
  boolean_T OutportBufferForzgzgActive;/* '<S104>/ZgZgChart' */
  boolean_T zgzgActive;                /* '<S104>/ZgZgChart' */
  boolean_T switchLaneFlg_BOOL;        /* '<S104>/ZgZgChart' */
  boolean_T OutportBufferFortargetReached;/* '<S28>/TargetReachedConfirmTime' */
  boolean_T targetReached;             /* '<S134>/TargetReachedConfirmTime' */
  boolean_T switchLaneStep;            /* '<S136>/singleStepCalc' */
  boolean_T hitRoutineRun;             /* '<S149>/stopRoutine' */
  boolean_T stuckHitFlg;               /* '<S149>/stopRoutine' */
  boolean_T refreshEvent;              /* '<S149>/stopRoutine' */
  boolean_T stopEvent;                 /* '<S149>/stopRoutine' */
  boolean_T counterReset;              /* '<S69>/EOL_TickStateMachine' */
  boolean_T pumperHit_BOOL;            /* '<S1>/Digital_IN_bool' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator_d;/* '<S122>/DeltaDistCalculator' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator;/* '<S120>/DeltaDistCalculator' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector;/* '<S88>/SpdTickDetector' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector_o;/* '<S79>/SpdTickDetector' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement_i;/* '<S59>/EncoderIncrement' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement;/* '<S58>/EncoderIncrement' */
} B_RobotControl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Unit_Delay_DSTATE;            /* '<S54>/Unit_Delay' */
  real_T Delay_DSTATE[5];              /* '<S66>/Delay' */
  real_T Delay1_DSTATE;                /* '<S66>/Delay1' */
  real_T initHeading;                  /* '<S104>/ZgZgChart' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S153>/FixPt Unit Delay1' */
  real32_T Unit_Delay5_DSTATE;         /* '<S27>/Unit_Delay5' */
  real32_T FixPtUnitDelay1_DSTATE_l;   /* '<S143>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_p;   /* '<S142>/FixPt Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S131>/Unit Delay' */
  real32_T Unit_Delay4_DSTATE;         /* '<S28>/Unit_Delay4' */
  real32_T Resettable_Delay_DSTATE;    /* '<S37>/Resettable_Delay' */
  real32_T Resettable_Delay1_DSTATE;   /* '<S37>/Resettable_Delay1' */
  real32_T Delay_DSTATE_a[5];          /* '<S60>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S60>/Delay1' */
  real32_T Delay_DSTATE_l[5];          /* '<S61>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S61>/Delay1' */
  real32_T MotorTransferFunction_states[2];/* '<S91>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_n;   /* '<S90>/FixPt Unit Delay1' */
  real32_T MotorTransferFunction_states_j[2];/* '<S82>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_b;   /* '<S81>/FixPt Unit Delay1' */
  real32_T Unit_Delay_DSTATE_i;        /* '<S70>/Unit_Delay' */
  real32_T tempDist;                   /* '<S48>/MotorMoveMonitor' */
  real32_T tempDist_c;                 /* '<S46>/MotorMoveMonitor' */
  real32_T tempDist_d;                 /* '<S101>/GTSP_Chart' */
  real32_T completeStep_prev;          /* '<S133>/HighLevelMoves' */
  real32_T completeStep_start;         /* '<S133>/HighLevelMoves' */
  real32_T tempDistance_mm;            /* '<S136>/singleStepCalc' */
  real32_T hitDistance;                /* '<S149>/stopRoutine' */
  int32_T sfEvent;                     /* '<S101>/GTSP_Chart' */
  int32_T sfEvent_e;                   /* '<S104>/ZgZgChart' */
  int32_T sfEvent_d;                   /* '<S133>/HighLevelMoves' */
  uint32_T refreshEventEventCounter;   /* '<S149>/stopRoutine' */
  uint32_T stopEventEventCounter;      /* '<S149>/stopRoutine' */
  int16_T Delay_DSTATE_k[4];           /* '<S148>/Delay' */
  int16_T Delay1_DSTATE_p;             /* '<S148>/Delay1' */
  int16_T Delay_DSTATE_f[4];           /* '<S147>/Delay' */
  int16_T Delay1_DSTATE_pw;            /* '<S147>/Delay1' */
  int16_T Unit_Delay_DSTATE_c;         /* '<S37>/Unit_Delay' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  uint16_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  uint16_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  uint16_T startHeading;               /* '<S114>/CompassSelfDiagTestChart' */
  uint16_T headingRequest;             /* '<S104>/ZgZgChart' */
  uint16_T temporalCounter_i1;         /* '<S100>/MainStateMachine' */
  uint16_T temporalCounter_i2;         /* '<S149>/stopRoutine' */
  uint16_T temporalCounter_i3;         /* '<S149>/stopRoutine' */
  uint16_T temporalCounter_i1_p;       /* '<S69>/EOL_TickStateMachine' */
  uint8_T UnitDelay4_DSTATE;           /* '<S2>/Unit Delay4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S153>/FixPt Unit Delay2' */
  uint8_T Unit_Delay4_DSTATE_b;        /* '<S27>/Unit_Delay4' */
  uint8_T Unit_Delay1_DSTATE;          /* '<S96>/Unit_Delay1' */
  uint8_T Unit_Delay_DSTATE_j;         /* '<S96>/Unit_Delay' */
  uint8_T Unit_Delay2_DSTATE_h;        /* '<S96>/Unit_Delay2' */
  uint8_T Unit_Delay5_DSTATE_n;        /* '<S28>/Unit_Delay5' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S143>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_jc;   /* '<S142>/FixPt Unit Delay2' */
  uint8_T Unit_Delay_DSTATE_b;         /* '<S26>/Unit_Delay' */
  uint8_T Unit_Delay5_DSTATE_p;        /* '<S25>/Unit_Delay5' */
  uint8_T Unit_Delay6_DSTATE;          /* '<S25>/Unit_Delay6' */
  uint8_T Unit_Delay7_DSTATE;          /* '<S25>/Unit_Delay7' */
  uint8_T Unit_Delay8_DSTATE;          /* '<S25>/Unit_Delay8' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S90>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S81>/FixPt Unit Delay2' */
  uint8_T Unit_Delay2_DSTATE_b;        /* '<S25>/Unit_Delay2' */
  boolean_T Unit_Delay_DSTATE_h;       /* '<S27>/Unit_Delay' */
  boolean_T Unit_Delay1_DSTATE_c;      /* '<S27>/Unit_Delay1' */
  boolean_T Unit_Delay1_DSTATE_p;      /* '<S28>/Unit_Delay1' */
  boolean_T Unit_Delay2_DSTATE_o;      /* '<S28>/Unit_Delay2' */
  boolean_T Unit_Delay3_DSTATE_c;      /* '<S28>/Unit_Delay3' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S95>/Unit Delay' */
  boolean_T Unit_Delay3_DSTATE_d;      /* '<S33>/Unit_Delay3' */
  boolean_T Unit_Delay4_DSTATE_m;      /* '<S25>/Unit_Delay4' */
  boolean_T Unit_Delay_DSTATE_ja;      /* '<S68>/Unit_Delay' */
  int8_T Switch_Case_ActiveSubsystem;  /* '<S103>/Switch_Case' */
  int8_T Switch_Case_ActiveSubsystem_j;/* '<S109>/Switch_Case' */
  uint8_T is_active_c21_RobotControl;  /* '<S4>/Scheduler' */
  uint8_T is_c21_RobotControl;         /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i1_k;        /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i2_p;        /* '<S4>/Scheduler' */
  uint8_T is_active_c12_RobotControlLib;/* '<S48>/MotorMoveMonitor' */
  uint8_T is_c12_RobotControlLib;      /* '<S48>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_i;        /* '<S48>/MotorMoveMonitor' */
  uint8_T is_active_c34_RobotControlLib;/* '<S46>/MotorMoveMonitor' */
  uint8_T is_c34_RobotControlLib;      /* '<S46>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_a;        /* '<S46>/MotorMoveMonitor' */
  uint8_T is_active_c13_RobotControl;  /* '<S7>/EEPROM_IO_Handler_Chart' */
  uint8_T is_c13_RobotControl;         /* '<S7>/EEPROM_IO_Handler_Chart' */
  uint8_T is_active_c27_ROTH;          /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T is_c27_ROTH;                 /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T temporalCounter_i1_j;        /* '<S112>/CompassSelfDiagTestChart' */
  uint8_T is_active_c31_ROTH;          /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T is_c31_ROTH;                 /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T is_turnHandler;              /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T steps;                       /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T filterToleranceCnt;          /* '<S114>/CompassSelfDiagTestChart' */
  uint8_T is_active_c26_ROTH;          /* '<S124>/HighLevelDiagTestControl' */
  uint8_T is_c26_ROTH;                 /* '<S124>/HighLevelDiagTestControl' */
  uint8_T is_SelfDiag;                 /* '<S124>/HighLevelDiagTestControl' */
  uint8_T temporalCounter_i1_o;        /* '<S124>/HighLevelDiagTestControl' */
  uint8_T is_active_c24_ROTH;          /* '<S101>/GTSP_Chart' */
  uint8_T is_c24_ROTH;                 /* '<S101>/GTSP_Chart' */
  uint8_T is_GTSP_Active;              /* '<S101>/GTSP_Chart' */
  uint8_T is_faceWest;                 /* '<S101>/GTSP_Chart' */
  uint8_T is_MostSouthLeft;            /* '<S101>/GTSP_Chart' */
  uint8_T is_facingSouth;              /* '<S101>/GTSP_Chart' */
  uint8_T is_GTSPsearch;               /* '<S101>/GTSP_Chart' */
  uint8_T counter;                     /* '<S101>/GTSP_Chart' */
  uint8_T round;                       /* '<S101>/GTSP_Chart' */
  uint8_T step1Flag;                   /* '<S101>/GTSP_Chart' */
  uint8_T is_active_c25_ROTH;          /* '<S104>/ZgZgChart' */
  uint8_T is_c25_ROTH;                 /* '<S104>/ZgZgChart' */
  uint8_T is_faceWest_f;               /* '<S104>/ZgZgChart' */
  uint8_T finishCounter;               /* '<S104>/ZgZgChart' */
  uint8_T is_active_c23_ROTH;          /* '<S100>/MainStateMachine' */
  uint8_T is_c23_ROTH;                 /* '<S100>/MainStateMachine' */
  uint8_T is_Running;                  /* '<S100>/MainStateMachine' */
  uint8_T zgzgCounter;                 /* '<S100>/MainStateMachine' */
  uint8_T encoderStep_prev;            /* '<S99>/pumperHitSensorView' */
  uint8_T encoderStep_start;           /* '<S99>/pumperHitSensorView' */
  uint8_T counter_f;                   /* '<S134>/TargetReachedConfirmTime' */
  uint8_T is_active_c37_MOVH;          /* '<S133>/HighLevelMoves' */
  uint8_T is_c37_MOVH;                 /* '<S133>/HighLevelMoves' */
  uint8_T is_forward;                  /* '<S133>/HighLevelMoves' */
  uint8_T is_TurnLeft;                 /* '<S133>/HighLevelMoves' */
  uint8_T is_UturnLeft;                /* '<S133>/HighLevelMoves' */
  uint8_T is_TurnLeft_o;               /* '<S133>/HighLevelMoves' */
  uint8_T is_Uturn;                    /* '<S133>/HighLevelMoves' */
  uint8_T is_TurnRight;                /* '<S133>/HighLevelMoves' */
  uint8_T is_TurnRight_n;              /* '<S133>/HighLevelMoves' */
  uint8_T is_UturnRight;               /* '<S133>/HighLevelMoves' */
  uint8_T is_TurnRight_k;              /* '<S133>/HighLevelMoves' */
  uint8_T uTurnCounter;                /* '<S133>/HighLevelMoves' */
  uint8_T stableCounter;               /* '<S133>/HighLevelMoves' */
  uint8_T uTurnCounter_prev;           /* '<S133>/HighLevelMoves' */
  uint8_T uTurnCounter_start;          /* '<S133>/HighLevelMoves' */
  uint8_T moveRequest_prev;            /* '<S133>/HighLevelMoves' */
  uint8_T moveRequest_start;           /* '<S133>/HighLevelMoves' */
  uint8_T is_active_c36_MOVH;          /* '<S136>/singleStepCalc' */
  uint8_T is_c36_MOVH;                 /* '<S136>/singleStepCalc' */
  uint8_T is_active_c19_RobotControlLib;/* '<S149>/stopRoutine' */
  uint8_T is_c19_RobotControlLib;      /* '<S149>/stopRoutine' */
  uint8_T is_stopRoutine;              /* '<S149>/stopRoutine' */
  uint8_T is_sideStuck;                /* '<S149>/stopRoutine' */
  uint8_T temporalCounter_i1_m;        /* '<S149>/stopRoutine' */
  uint8_T icLoad;                      /* '<S37>/Resettable_Delay' */
  uint8_T icLoad_o;                    /* '<S37>/Resettable_Delay1' */
  uint8_T is_active_c33_DSCA;          /* '<S69>/EOL_TickStateMachine' */
  uint8_T is_c33_DSCA;                 /* '<S69>/EOL_TickStateMachine' */
  boolean_T angleFinishFlg;            /* '<S112>/CompassSelfDiagTestChart' */
  boolean_T initHeading_d;             /* '<S101>/GTSP_Chart' */
  boolean_T activeFlag;                /* '<S101>/GTSP_Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<S99>/pumperHitSensorView' */
  boolean_T turnActive;                /* '<S133>/HighLevelMoves' */
  boolean_T escapeFlg;                 /* '<S149>/stopRoutine' */
  boolean_T Angle_CalibrationUponReq_MODE;/* '<S105>/Angle_CalibrationUponReq' */
  boolean_T endofLineTest_MODE;        /* '<S55>/endofLineTest' */
  boolean_T LeftMotorEncoderCounter_MODE;/* '<S68>/LeftMotorEncoderCounter' */
  boolean_T RightMotorEncoderCounter1_MODE;/* '<S68>/RightMotorEncoderCounter1' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator_d;/* '<S122>/DeltaDistCalculator' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator;/* '<S120>/DeltaDistCalculator' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector;/* '<S88>/SpdTickDetector' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector_o;/* '<S79>/SpdTickDetector' */
} DW_RobotControl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState GTSP_Chart_Trig_ZCE[2];   /* '<S101>/GTSP_Chart' */
  ZCSigState ZgZgChart_Trig_ZCE[2];    /* '<S104>/ZgZgChart' */
  ZCSigState HighLevelMoves_Trig_ZCE[2];/* '<S133>/HighLevelMoves' */
  ZCSigState Resettable_Delay_Reset_ZCE;/* '<S37>/Resettable_Delay' */
  ZCSigState Resettable_Delay1_Reset_ZCE;/* '<S37>/Resettable_Delay1' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement_i;/* '<S59>/EncoderIncrement' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement;/* '<S58>/EncoderIncrement' */
} PrevZCX_RobotControl_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Divide;                 /* '<S39>/Divide' */
  const real_T Divide_k;               /* '<S64>/Divide' */
  const real32_T Gain;                 /* '<S139>/Gain' */
} ConstB_RobotControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_RobotControl_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_RobotControl_T RobotControl_B;

/* Block states (auto storage) */
extern DW_RobotControl_T RobotControl_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_RobotControl_T RobotControl_PrevZCX;
extern const ConstB_RobotControl_T RobotControl_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void RobotControl_initialize(void);
extern void RobotControl_step(void);
extern void RobotControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RobotControl_T *const RobotControl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S36>/Scope' : Unused code path elimination
 * Block '<S24>/Scope' : Unused code path elimination
 * Block '<S71>/Add' : Unused code path elimination
 * Block '<S71>/CONST_ONE_UINT16' : Unused code path elimination
 * Block '<S71>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S71>/Relational_Operator' : Unused code path elimination
 * Block '<S71>/Switch' : Unused code path elimination
 * Block '<S71>/Unit_Delay' : Unused code path elimination
 * Block '<S25>/Scope' : Unused code path elimination
 * Block '<S25>/Scope4' : Unused code path elimination
 * Block '<S25>/Scope5' : Unused code path elimination
 * Block '<S25>/Unit_Delay1' : Unused code path elimination
 * Block '<S80>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S76>/Add4' : Unused code path elimination
 * Block '<S76>/Add5' : Unused code path elimination
 * Block '<S76>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S76>/Delay' : Unused code path elimination
 * Block '<S76>/Delay1' : Unused code path elimination
 * Block '<S76>/Gain3' : Unused code path elimination
 * Block '<S89>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S90>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S85>/Add4' : Unused code path elimination
 * Block '<S85>/Add5' : Unused code path elimination
 * Block '<S85>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S85>/Delay' : Unused code path elimination
 * Block '<S85>/Delay1' : Unused code path elimination
 * Block '<S85>/Gain3' : Unused code path elimination
 * Block '<S106>/CONST_FALSE' : Unused code path elimination
 * Block '<S107>/Data Type Conversion' : Unused code path elimination
 * Block '<S107>/Scope' : Unused code path elimination
 * Block '<S27>/Scope' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S28>/ENU_TEST_INIT1' : Unused code path elimination
 * Block '<S131>/Data Type Conversion' : Unused code path elimination
 * Block '<S140>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S142>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S141>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S143>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S131>/Scope' : Unused code path elimination
 * Block '<S131>/Scope1' : Unused code path elimination
 * Block '<S131>/Scope2' : Unused code path elimination
 * Block '<S131>/Scope3' : Unused code path elimination
 * Block '<S28>/Gain4' : Unused code path elimination
 * Block '<S28>/Relational_Operator5' : Unused code path elimination
 * Block '<S28>/Scope' : Unused code path elimination
 * Block '<S28>/Scope1' : Unused code path elimination
 * Block '<S28>/Scope2' : Unused code path elimination
 * Block '<S29>/CAL_ROBO_LENG' : Unused code path elimination
 * Block '<S29>/CAL_ROBO_LENG1' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S29>/Constant1' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion2' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion3' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion4' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion5' : Unused code path elimination
 * Block '<S29>/Data_Type_Conversion6' : Unused code path elimination
 * Block '<S29>/Divide' : Unused code path elimination
 * Block '<S29>/Divide1' : Unused code path elimination
 * Block '<S29>/Logical_Operator1' : Unused code path elimination
 * Block '<S29>/Relational_Operator' : Unused code path elimination
 * Block '<S29>/Relational_Operator1' : Unused code path elimination
 * Block '<S146>/Scope' : Unused code path elimination
 * Block '<S146>/Scope1' : Unused code path elimination
 * Block '<S22>/Scope' : Unused code path elimination
 * Block '<S22>/Scope1' : Unused code path elimination
 * Block '<S22>/Scope3' : Unused code path elimination
 * Block '<S22>/Scope4' : Unused code path elimination
 * Block '<S151>/CONST_noVelocity' : Unused code path elimination
 * Block '<S151>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S151>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S151>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S151>/Gain1' : Unused code path elimination
 * Block '<S152>/CONST_noVelocity' : Unused code path elimination
 * Block '<S152>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S152>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S152>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S152>/Gain1' : Unused code path elimination
 * Block '<S153>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S77>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S86>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S86>/Data_Type_Conversion2' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S122>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RobotControl'
 * '<S1>'   : 'RobotControl/InputHandler'
 * '<S2>'   : 'RobotControl/OutputHandler'
 * '<S3>'   : 'RobotControl/RobotControl'
 * '<S4>'   : 'RobotControl/Scheduler'
 * '<S5>'   : 'RobotControl/InputHandler/COM_A4SCA_A5SCL'
 * '<S6>'   : 'RobotControl/InputHandler/Digital_IN_bool'
 * '<S7>'   : 'RobotControl/InputHandler/EEPROM_IO_Handler'
 * '<S8>'   : 'RobotControl/InputHandler/EncoderAnalogIn'
 * '<S9>'   : 'RobotControl/InputHandler/ULS_AnalogIn'
 * '<S10>'  : 'RobotControl/InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL_Chart'
 * '<S11>'  : 'RobotControl/InputHandler/EEPROM_IO_Handler/EEPROM_IO_Handler_Chart'
 * '<S12>'  : 'RobotControl/InputHandler/EncoderAnalogIn/leftEncoderTicks_uint16_chart'
 * '<S13>'  : 'RobotControl/InputHandler/EncoderAnalogIn/rightEncoderTicks_uint16_chart'
 * '<S14>'  : 'RobotControl/InputHandler/ULS_AnalogIn/ULSL_D8R_D7L_Chart'
 * '<S15>'  : 'RobotControl/InputHandler/ULS_AnalogIn/ULSR_D8R_D7L_Chart'
 * '<S16>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM'
 * '<S17>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM1'
 * '<S18>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM2'
 * '<S19>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM3'
 * '<S20>'  : 'RobotControl/OutputHandler/Digital_OUT_bool'
 * '<S21>'  : 'RobotControl/OutputHandler/Digital_OUT_bool1'
 * '<S22>'  : 'RobotControl/RobotControl/RobotControlLib'
 * '<S23>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler'
 * '<S24>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont'
 * '<S25>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA'
 * '<S26>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler'
 * '<S27>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines'
 * '<S28>'  : 'RobotControl/RobotControl/RobotControlLib/MovementHandler'
 * '<S29>'  : 'RobotControl/RobotControl/RobotControlLib/ScanHandler'
 * '<S30>'  : 'RobotControl/RobotControl/RobotControlLib/StopRoutine'
 * '<S31>'  : 'RobotControl/RobotControl/RobotControlLib/motorHandler'
 * '<S32>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator'
 * '<S33>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter'
 * '<S34>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation'
 * '<S35>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation1'
 * '<S36>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter'
 * '<S37>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter'
 * '<S38>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/movingAverage_1ms_to_5ms2'
 * '<S39>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/FromDegreeToRad2'
 * '<S40>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/OMEGA_Calc'
 * '<S41>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/thetaOverFlowFilter_Deg'
 * '<S42>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper'
 * '<S43>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected'
 * '<S44>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor'
 * '<S45>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1'
 * '<S46>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor'
 * '<S47>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor'
 * '<S48>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor'
 * '<S49>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor'
 * '<S50>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL'
 * '<S51>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL1'
 * '<S52>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator'
 * '<S53>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderAdaptation'
 * '<S54>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation'
 * '<S55>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest'
 * '<S56>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator'
 * '<S57>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator'
 * '<S58>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor'
 * '<S59>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor'
 * '<S60>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms'
 * '<S61>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms1'
 * '<S62>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor/EncoderIncrement'
 * '<S63>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor/EncoderIncrement'
 * '<S64>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/FromDegreeToRad2'
 * '<S65>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/OMEGA_Calc'
 * '<S66>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/movingAverage_1ms_to_5ms'
 * '<S67>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/thetaOverFlowFilter_Rad'
 * '<S68>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest'
 * '<S69>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine'
 * '<S70>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/LeftMotorEncoderCounter'
 * '<S71>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/RightMotorEncoderCounter1'
 * '<S72>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine'
 * '<S73>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator'
 * '<S74>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator'
 * '<S75>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor'
 * '<S76>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S77>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter'
 * '<S78>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator'
 * '<S79>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector'
 * '<S80>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S81>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S82>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator/motorModelTfDis'
 * '<S83>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector'
 * '<S84>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor'
 * '<S85>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S86>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter'
 * '<S87>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator'
 * '<S88>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector'
 * '<S89>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S90>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S91>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator/motorModelTfDis'
 * '<S92>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector/SpdTickDetector'
 * '<S93>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/LeftMotor'
 * '<S94>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/RightMotor'
 * '<S95>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler/Set_Reset'
 * '<S96>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine'
 * '<S97>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DistanceCalculator'
 * '<S98>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/End'
 * '<S99>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation'
 * '<S100>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl'
 * '<S101>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine'
 * '<S102>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/ULS_FaultHandler'
 * '<S103>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/routineEnableSwitch'
 * '<S104>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine'
 * '<S105>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration'
 * '<S106>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Bluetooth'
 * '<S107>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest'
 * '<S108>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest'
 * '<S109>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine'
 * '<S110>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/None'
 * '<S111>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/QuaterTurnTargetDist'
 * '<S112>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq'
 * '<S113>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart'
 * '<S114>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem'
 * '<S115>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading'
 * '<S116>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart'
 * '<S117>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler'
 * '<S118>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest'
 * '<S119>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest'
 * '<S120>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator'
 * '<S121>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S122>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator'
 * '<S123>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S124>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl'
 * '<S125>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl'
 * '<S126>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView'
 * '<S127>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine'
 * '<S128>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart'
 * '<S129>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart'
 * '<S130>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc'
 * '<S131>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc'
 * '<S132>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MaxSpeedsOnly'
 * '<S133>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine'
 * '<S134>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime'
 * '<S135>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TurnHandler'
 * '<S136>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler'
 * '<S137>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc'
 * '<S138>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID'
 * '<S139>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/rateLimiter'
 * '<S140>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable'
 * '<S141>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1'
 * '<S142>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable/Unit Delay Resettable'
 * '<S143>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S144>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves'
 * '<S145>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime'
 * '<S146>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler'
 * '<S147>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff1'
 * '<S148>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff4'
 * '<S149>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine'
 * '<S150>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine'
 * '<S151>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/LeftMotorPin'
 * '<S152>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/RightMotorPin'
 * '<S153>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/Unit_Delay_Resettable'
 * '<S154>' : 'RobotControl/Scheduler/Scheduler'
 */
#endif                                 /* RTW_HEADER_RobotControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
