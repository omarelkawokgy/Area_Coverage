/*
 * RobotControl.h
 *
 * Code generation for model "RobotControl".
 *
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalio.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add1_l;                       /* '<S48>/Add1' */
  real_T deg_m;                        /* '<S58>/Product' */
  real32_T forwardDist;                /* '<S91>/Switch1' */
  real32_T DataTypeConversion1;        /* '<S108>/Data Type Conversion1' */
  real32_T DataTypeConversion3;        /* '<S108>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S108>/Data Type Conversion4' */
  real32_T DataTypeConversion5;        /* '<S108>/Data Type Conversion5' */
  real32_T DataTypeConversion;         /* '<S95>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S95>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S95>/Data Type Conversion2' */
  real32_T DataTypeConversion3_l;      /* '<S95>/Data Type Conversion3' */
  real32_T DataTypeConversion1_e;      /* '<S98>/Data Type Conversion1' */
  real32_T DataTypeConversion2_m;      /* '<S98>/Data Type Conversion2' */
  real32_T DataTypeConversion3_g;      /* '<S98>/Data Type Conversion3' */
  real32_T DataTypeConversion4_m;      /* '<S98>/Data Type Conversion4' */
  real32_T DataTypeConversion1_n;      /* '<S127>/Data Type Conversion1' */
  real32_T thetaError;                 /* '<S22>/Switch' */
  real32_T leftVel1ms_mmPerSec;        /* '<S71>/Data_Type_Conversion2' */
  real32_T rightVel1ms_mmPerSec;       /* '<S80>/Data_Type_Conversion3' */
  real32_T Data_Type_Conversion;       /* '<S54>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion_m;     /* '<S55>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion_a;     /* '<S60>/Data_Type_Conversion' */
  real32_T theta_Deg;                  /* '<S30>/Saturation' */
  real32_T theta_mDeg;                 /* '<S30>/Gain' */
  int16_T COM_A4SCA_A5SCL;             /* '<S5>/COM_A4SCA_A5SCL' */
  int16_T ROB_NORTH;                   /* '<S20>/Signal Conversion' */
  int16_T ROB_SOUTH;                   /* '<S20>/Signal Conversion1' */
  int16_T ROB_EAST;                    /* '<S20>/Signal Conversion2' */
  int16_T ROB_WEST;                    /* '<S20>/Signal Conversion3' */
  uint16_T headingRequest;             /* '<S127>/HighLevelMoves' */
  uint16_T leftBlocks;                 /* '<S140>/Data_Type_Conversion' */
  uint16_T rightBlocks;                /* '<S140>/Data_Type_Conversion1' */
  uint16_T ULSL_D8R_D7L;               /* '<S9>/ULSL_D8R_D7L' */
  uint16_T ULSR_D8R_D7L1;              /* '<S9>/ULSR_D8R_D7L1' */
  uint16_T currentHeading;             /* '<S26>/HeadingCalculation' */
  uint16_T A0;                         /* '<S7>/A0' */
  uint16_T A1;                         /* '<S7>/A1' */
  uint8_T leftPosPin;                  /* '<S145>/Switch' */
  uint8_T leftNegPin;                  /* '<S145>/Switch' */
  uint8_T rightPosPin;                 /* '<S146>/Switch' */
  uint8_T rightNegPin;                 /* '<S146>/Switch' */
  uint8_T Merge;                       /* '<S21>/Merge' */
  uint8_T moveRequest;                 /* '<S21>/Switch' */
  uint8_T OutportBufferForDIAG_StatusFlg;/* '<S90>/None' */
  uint8_T DIAG_StatusFlg;              /* '<S104>/CONST_DIAG_FINISH_FLG' */
  uint8_T OutportBufferForangleCalibStatu;/* '<S99>/Angle_CalibrationUponReq' */
  uint8_T moveReq;                     /* '<S106>/CompassSelfDiagTestChart' */
  uint8_T angleCalibStatus;            /* '<S106>/CompassSelfDiagTestChart' */
  uint8_T encoderTstStatus;            /* '<S102>/Switch' */
  uint8_T moveReq_p;                   /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T comTstStatus;                /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T diagEnableReq;               /* '<S118>/HighLevelDiagTestControl' */
  uint8_T moveRequest_p;               /* '<S95>/GTSP_Chart' */
  uint8_T OutportBufferForswLaneCnt_uint8;/* '<S98>/ZgZgChart' */
  uint8_T moveRequest_i;               /* '<S98>/ZgZgChart' */
  uint8_T swLaneCnt_uint8;             /* '<S98>/ZgZgChart' */
  uint8_T currentRoutine;              /* '<S94>/MainStateMachine' */
  uint8_T sensorView;                  /* '<S93>/pumperHitSensorView' */
  uint8_T turnRequestFiltered;         /* '<S129>/Switch' */
  uint8_T rightMotorRequest;           /* '<S126>/Switch' */
  uint8_T leftMotorRequest;            /* '<S126>/Switch' */
  uint8_T turnRequest;                 /* '<S127>/HighLevelMoves' */
  uint8_T encoderStep;                 /* '<S130>/singleStepCalc' */
  uint8_T moveRequest_n;               /* '<S143>/stopRoutine' */
  boolean_T ULS_NotConnectedFlag_BOOL; /* '<S44>/Relational_Operator' */
  boolean_T ULS_NotConnectedFlag_BOOL_j;/* '<S45>/Relational_Operator' */
  boolean_T failFlag;                  /* '<S18>/Logical_Operator4' */
  boolean_T greenLED_BOOL;             /* '<S18>/Logical Operator2' */
  boolean_T redLED_BOOL;               /* '<S18>/Logical_Operator2' */
  boolean_T motorFaultFlag;            /* '<S42>/MotorMoveMonitor' */
  boolean_T motorFaultFlag_k;          /* '<S40>/MotorMoveMonitor' */
  boolean_T diagSensorFailure;         /* '<S21>/Data Type Conversion' */
  boolean_T OutportBufferForswitchLaneFlg_B;/* '<S21>/zigzagRoutine' */
  boolean_T hardwareFaultFlg;          /* '<S90>/Logical_Operator' */
  boolean_T OutportBufferForenableAngleCali;/* '<S90>/HighLevelTestRoutine' */
  boolean_T encoderDistErrorFlg_BOOL;  /* '<S112>/Logical_Operator' */
  boolean_T encoderDistErrorFlg_BOOL_m;/* '<S113>/Logical_Operator' */
  boolean_T compFaultFlag;             /* '<S108>/CompassSelfDiagTestChart' */
  boolean_T enableAngleCalib_BOOL;     /* '<S118>/HighLevelDiagTestControl' */
  boolean_T OutportBufferForGT_active; /* '<S95>/GTSP_Chart' */
  boolean_T GT_active;                 /* '<S95>/GTSP_Chart' */
  boolean_T OutportBufferForswitchLaneFlg_k;/* '<S98>/ZgZgChart' */
  boolean_T OutportBufferForzgzgActive;/* '<S98>/ZgZgChart' */
  boolean_T zgzgActive;                /* '<S98>/ZgZgChart' */
  boolean_T switchLaneFlg_BOOL;        /* '<S98>/ZgZgChart' */
  boolean_T Unit_Delay1;               /* '<S22>/Unit_Delay1' */
  boolean_T OutportBufferFortargetReached;/* '<S22>/TargetReachedConfirmTime' */
  boolean_T targetReached;             /* '<S128>/TargetReachedConfirmTime' */
  boolean_T switchLaneStep;            /* '<S130>/singleStepCalc' */
  boolean_T hitRoutineRun;             /* '<S143>/stopRoutine' */
  boolean_T stuckHitFlg;               /* '<S143>/stopRoutine' */
  boolean_T refreshEvent;              /* '<S143>/stopRoutine' */
  boolean_T stopEvent;                 /* '<S143>/stopRoutine' */
  boolean_T DigitalInput;              /* '<S6>/Digital Input' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator_d;/* '<S116>/DeltaDistCalculator' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator;/* '<S114>/DeltaDistCalculator' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector_e;/* '<S82>/SpdTickDetector' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector;/* '<S73>/SpdTickDetector' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement_i;/* '<S53>/EncoderIncrement' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement;/* '<S52>/EncoderIncrement' */
} B_RobotControl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S6>/Digital Input' */
  real_T Unit_Delay_DSTATE;            /* '<S48>/Unit_Delay' */
  real_T Delay_DSTATE[5];              /* '<S60>/Delay' */
  real_T Delay1_DSTATE;                /* '<S60>/Delay1' */
  real_T initHeading;                  /* '<S98>/ZgZgChart' */
  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<S16>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<S16>/Scope3' */

  struct {
    void *LoggedData[3];
  } Scope4_PWORK;                      /* '<S16>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S21>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_d;                     /* '<S101>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK_o;                     /* '<S22>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_j;                    /* '<S22>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK;                      /* '<S22>/Scope2' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_c;                     /* '<S125>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_ju;                   /* '<S125>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_f;                    /* '<S125>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK_m;                    /* '<S125>/Scope3' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_g;                     /* '<S140>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_d;                    /* '<S140>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK_c;                    /* '<S19>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      /* '<S19>/Scope5' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_dv;                    /* '<S30>/Scope' */

  void *DigitalOutput_PWORK;           /* '<S11>/Digital Output' */
  void *DigitalOutput_PWORK_f;         /* '<S10>/Digital Output' */
  void *DigitalInput_PWORK;            /* '<S6>/Digital Input' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S147>/FixPt Unit Delay1' */
  real32_T Unit_Delay5_DSTATE;         /* '<S21>/Unit_Delay5' */
  real32_T UnitDelay_DSTATE;           /* '<S125>/Unit Delay' */
  real32_T FixPtUnitDelay1_DSTATE_p;   /* '<S136>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_l;   /* '<S137>/FixPt Unit Delay1' */
  real32_T Unit_Delay4_DSTATE;         /* '<S22>/Unit_Delay4' */
  real32_T MotorTransferFunction_states[2];/* '<S76>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_b;   /* '<S75>/FixPt Unit Delay1' */
  real32_T MotorTransferFunction_states_n[2];/* '<S85>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_n;   /* '<S84>/FixPt Unit Delay1' */
  real32_T Delay_DSTATE_a[5];          /* '<S54>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S54>/Delay1' */
  real32_T Delay_DSTATE_l[5];          /* '<S55>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S55>/Delay1' */
  real32_T Resettable_Delay_DSTATE;    /* '<S31>/Resettable_Delay' */
  real32_T Resettable_Delay1_DSTATE;   /* '<S31>/Resettable_Delay1' */
  real32_T tempDist;                   /* '<S42>/MotorMoveMonitor' */
  real32_T tempDist_j;                 /* '<S40>/MotorMoveMonitor' */
  real32_T tempDist_f;                 /* '<S95>/GTSP_Chart' */
  real32_T completeStep_prev;          /* '<S127>/HighLevelMoves' */
  real32_T completeStep_start;         /* '<S127>/HighLevelMoves' */
  real32_T tempDistance_mm;            /* '<S130>/singleStepCalc' */
  real32_T hitDistance;                /* '<S143>/stopRoutine' */
  int32_T sfEvent;                     /* '<S95>/GTSP_Chart' */
  int32_T sfEvent_j;                   /* '<S98>/ZgZgChart' */
  int32_T sfEvent_p;                   /* '<S127>/HighLevelMoves' */
  uint32_T refreshEventEventCounter;   /* '<S143>/stopRoutine' */
  uint32_T stopEventEventCounter;      /* '<S143>/stopRoutine' */
  codertarget_arduinobase_blo_i_T obj_n;/* '<S11>/Digital Output' */
  codertarget_arduinobase_blo_i_T obj_e;/* '<S10>/Digital Output' */
  int16_T Delay_DSTATE_k[4];           /* '<S142>/Delay' */
  int16_T Delay1_DSTATE_p;             /* '<S142>/Delay1' */
  int16_T Delay_DSTATE_f[4];           /* '<S141>/Delay' */
  int16_T Delay1_DSTATE_pw;            /* '<S141>/Delay1' */
  int16_T Unit_Delay_DSTATE_c;         /* '<S31>/Unit_Delay' */
  uint16_T startHeading;               /* '<S108>/CompassSelfDiagTestChart' */
  uint16_T headingRequest;             /* '<S98>/ZgZgChart' */
  uint16_T temporalCounter_i1;         /* '<S94>/MainStateMachine' */
  uint16_T temporalCounter_i2;         /* '<S143>/stopRoutine' */
  uint16_T temporalCounter_i3;         /* '<S143>/stopRoutine' */
  uint16_T temporalCounter_i1_i;       /* '<S63>/EOL_TickStateMachine' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S147>/FixPt Unit Delay2' */
  uint8_T Unit_Delay4_DSTATE_b;        /* '<S21>/Unit_Delay4' */
  uint8_T Unit_Delay1_DSTATE;          /* '<S90>/Unit_Delay1' */
  uint8_T Unit_Delay_DSTATE_j;         /* '<S90>/Unit_Delay' */
  uint8_T Unit_Delay2_DSTATE_h;        /* '<S90>/Unit_Delay2' */
  uint8_T Unit_Delay5_DSTATE_n;        /* '<S22>/Unit_Delay5' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S136>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_jh;   /* '<S137>/FixPt Unit Delay2' */
  uint8_T Unit_Delay_DSTATE_b;         /* '<S20>/Unit_Delay' */
  uint8_T Unit_Delay5_DSTATE_p;        /* '<S19>/Unit_Delay5' */
  uint8_T Unit_Delay6_DSTATE;          /* '<S19>/Unit_Delay6' */
  uint8_T Unit_Delay7_DSTATE;          /* '<S19>/Unit_Delay7' */
  uint8_T Unit_Delay8_DSTATE;          /* '<S19>/Unit_Delay8' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S75>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S84>/FixPt Unit Delay2' */
  uint8_T Unit_Delay2_DSTATE_b;        /* '<S19>/Unit_Delay2' */
  boolean_T Unit_Delay_DSTATE_h;       /* '<S21>/Unit_Delay' */
  boolean_T Unit_Delay1_DSTATE_c;      /* '<S21>/Unit_Delay1' */
  boolean_T Unit_Delay1_DSTATE_p;      /* '<S22>/Unit_Delay1' */
  boolean_T Unit_Delay2_DSTATE_o;      /* '<S22>/Unit_Delay2' */
  boolean_T Unit_Delay3_DSTATE_c;      /* '<S22>/Unit_Delay3' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S89>/Unit Delay' */
  boolean_T Unit_Delay3_DSTATE_d;      /* '<S27>/Unit_Delay3' */
  int8_T Switch_Case_ActiveSubsystem;  /* '<S97>/Switch_Case' */
  int8_T Switch_Case_ActiveSubsystem_j;/* '<S103>/Switch_Case' */
  uint8_T is_active_c21_RobotControl;  /* '<S4>/Scheduler' */
  uint8_T is_c21_RobotControl;         /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i1_k;        /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i2_p;        /* '<S4>/Scheduler' */
  uint8_T is_active_c12_RobotControlLib;/* '<S42>/MotorMoveMonitor' */
  uint8_T is_c12_RobotControlLib;      /* '<S42>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_d;        /* '<S42>/MotorMoveMonitor' */
  uint8_T is_active_c34_RobotControlLib;/* '<S40>/MotorMoveMonitor' */
  uint8_T is_c34_RobotControlLib;      /* '<S40>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_in;       /* '<S40>/MotorMoveMonitor' */
  uint8_T is_active_c27_ROTH;          /* '<S106>/CompassSelfDiagTestChart' */
  uint8_T is_c27_ROTH;                 /* '<S106>/CompassSelfDiagTestChart' */
  uint8_T temporalCounter_i1_k3;       /* '<S106>/CompassSelfDiagTestChart' */
  uint8_T is_active_c31_ROTH;          /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T is_c31_ROTH;                 /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T is_turnHandler;              /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T steps;                       /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T filterToleranceCnt;          /* '<S108>/CompassSelfDiagTestChart' */
  uint8_T is_active_c26_ROTH;          /* '<S118>/HighLevelDiagTestControl' */
  uint8_T is_c26_ROTH;                 /* '<S118>/HighLevelDiagTestControl' */
  uint8_T is_SelfDiag;                 /* '<S118>/HighLevelDiagTestControl' */
  uint8_T temporalCounter_i1_c;        /* '<S118>/HighLevelDiagTestControl' */
  uint8_T is_active_c24_ROTH;          /* '<S95>/GTSP_Chart' */
  uint8_T is_c24_ROTH;                 /* '<S95>/GTSP_Chart' */
  uint8_T is_GTSP_Active;              /* '<S95>/GTSP_Chart' */
  uint8_T is_faceWest;                 /* '<S95>/GTSP_Chart' */
  uint8_T is_MostSouthLeft;            /* '<S95>/GTSP_Chart' */
  uint8_T is_facingSouth;              /* '<S95>/GTSP_Chart' */
  uint8_T is_GTSPsearch;               /* '<S95>/GTSP_Chart' */
  uint8_T counter;                     /* '<S95>/GTSP_Chart' */
  uint8_T round;                       /* '<S95>/GTSP_Chart' */
  uint8_T step1Flag;                   /* '<S95>/GTSP_Chart' */
  uint8_T is_active_c25_ROTH;          /* '<S98>/ZgZgChart' */
  uint8_T is_c25_ROTH;                 /* '<S98>/ZgZgChart' */
  uint8_T is_faceWest_h;               /* '<S98>/ZgZgChart' */
  uint8_T finishCounter;               /* '<S98>/ZgZgChart' */
  uint8_T is_active_c23_ROTH;          /* '<S94>/MainStateMachine' */
  uint8_T is_c23_ROTH;                 /* '<S94>/MainStateMachine' */
  uint8_T is_Running;                  /* '<S94>/MainStateMachine' */
  uint8_T zgzgCounter;                 /* '<S94>/MainStateMachine' */
  uint8_T encoderStep_prev;            /* '<S93>/pumperHitSensorView' */
  uint8_T encoderStep_start;           /* '<S93>/pumperHitSensorView' */
  uint8_T counter_j;                   /* '<S128>/TargetReachedConfirmTime' */
  uint8_T is_active_c37_MOVH;          /* '<S127>/HighLevelMoves' */
  uint8_T is_c37_MOVH;                 /* '<S127>/HighLevelMoves' */
  uint8_T is_forward;                  /* '<S127>/HighLevelMoves' */
  uint8_T is_TurnLeft;                 /* '<S127>/HighLevelMoves' */
  uint8_T is_UturnLeft;                /* '<S127>/HighLevelMoves' */
  uint8_T is_TurnLeft_f;               /* '<S127>/HighLevelMoves' */
  uint8_T is_Uturn;                    /* '<S127>/HighLevelMoves' */
  uint8_T is_TurnRight;                /* '<S127>/HighLevelMoves' */
  uint8_T is_TurnRight_c;              /* '<S127>/HighLevelMoves' */
  uint8_T is_UturnRight;               /* '<S127>/HighLevelMoves' */
  uint8_T is_TurnRight_b;              /* '<S127>/HighLevelMoves' */
  uint8_T uTurnCounter;                /* '<S127>/HighLevelMoves' */
  uint8_T stableCounter;               /* '<S127>/HighLevelMoves' */
  uint8_T uTurnCounter_prev;           /* '<S127>/HighLevelMoves' */
  uint8_T uTurnCounter_start;          /* '<S127>/HighLevelMoves' */
  uint8_T moveRequest_prev;            /* '<S127>/HighLevelMoves' */
  uint8_T moveRequest_start;           /* '<S127>/HighLevelMoves' */
  uint8_T is_active_c36_MOVH;          /* '<S130>/singleStepCalc' */
  uint8_T is_c36_MOVH;                 /* '<S130>/singleStepCalc' */
  uint8_T is_active_c19_RobotControlLib;/* '<S143>/stopRoutine' */
  uint8_T is_c19_RobotControlLib;      /* '<S143>/stopRoutine' */
  uint8_T is_stopRoutine;              /* '<S143>/stopRoutine' */
  uint8_T is_sideStuck;                /* '<S143>/stopRoutine' */
  uint8_T temporalCounter_i1_a;        /* '<S143>/stopRoutine' */
  uint8_T is_active_c33_DSCA;          /* '<S63>/EOL_TickStateMachine' */
  uint8_T is_c33_DSCA;                 /* '<S63>/EOL_TickStateMachine' */
  uint8_T icLoad;                      /* '<S31>/Resettable_Delay' */
  uint8_T icLoad_o;                    /* '<S31>/Resettable_Delay1' */
  boolean_T angleFinishFlg;            /* '<S106>/CompassSelfDiagTestChart' */
  boolean_T initHeading_p;             /* '<S95>/GTSP_Chart' */
  boolean_T activeFlag;                /* '<S95>/GTSP_Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<S93>/pumperHitSensorView' */
  boolean_T turnActive;                /* '<S127>/HighLevelMoves' */
  boolean_T escapeFlg;                 /* '<S143>/stopRoutine' */
  boolean_T objisempty;                /* '<S11>/Digital Output' */
  boolean_T objisempty_i;              /* '<S10>/Digital Output' */
  boolean_T objisempty_c;              /* '<S6>/Digital Input' */
  boolean_T Angle_CalibrationUponReq_MODE;/* '<S99>/Angle_CalibrationUponReq' */
  boolean_T endofLineTest_MODE;        /* '<S49>/endofLineTest' */
  boolean_T LeftMotorEncoderCounter_MODE;/* '<S62>/LeftMotorEncoderCounter' */
  boolean_T RightMotorEncoderCounter1_MODE;/* '<S62>/RightMotorEncoderCounter1' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator_d;/* '<S116>/DeltaDistCalculator' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator;/* '<S114>/DeltaDistCalculator' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector_e;/* '<S82>/SpdTickDetector' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector;/* '<S73>/SpdTickDetector' */
} DW_RobotControl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState GTSP_Chart_Trig_ZCE[2];   /* '<S95>/GTSP_Chart' */
  ZCSigState ZgZgChart_Trig_ZCE[2];    /* '<S98>/ZgZgChart' */
  ZCSigState HighLevelMoves_Trig_ZCE[2];/* '<S127>/HighLevelMoves' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement_i;/* '<S53>/EncoderIncrement' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement;/* '<S52>/EncoderIncrement' */
  ZCSigState Resettable_Delay_Reset_ZCE;/* '<S31>/Resettable_Delay' */
  ZCSigState Resettable_Delay1_Reset_ZCE;/* '<S31>/Resettable_Delay1' */
} PrevZCX_RobotControl_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S9>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S9>/Data Type Conversion1' */
} ConstB_RobotControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_RobotControl_T {
  const char_T *errorStatus;
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
 * Block '<S2>/Unit Delay' : Unused code path elimination
 * Block '<S2>/Unit Delay1' : Unused code path elimination
 * Block '<S2>/Unit Delay2' : Unused code path elimination
 * Block '<S2>/Unit Delay3' : Unused code path elimination
 * Block '<S2>/Unit Delay4' : Unused code path elimination
 * Block '<S65>/Add' : Unused code path elimination
 * Block '<S65>/CONST_ONE_UINT16' : Unused code path elimination
 * Block '<S65>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S65>/Relational_Operator' : Unused code path elimination
 * Block '<S65>/Switch' : Unused code path elimination
 * Block '<S65>/Unit_Delay' : Unused code path elimination
 * Block '<S19>/Unit_Delay1' : Unused code path elimination
 * Block '<S74>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S75>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S70>/Add4' : Unused code path elimination
 * Block '<S70>/Add5' : Unused code path elimination
 * Block '<S70>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S70>/Delay' : Unused code path elimination
 * Block '<S70>/Delay1' : Unused code path elimination
 * Block '<S70>/Gain3' : Unused code path elimination
 * Block '<S83>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S84>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S79>/Add4' : Unused code path elimination
 * Block '<S79>/Add5' : Unused code path elimination
 * Block '<S79>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S79>/Delay' : Unused code path elimination
 * Block '<S79>/Delay1' : Unused code path elimination
 * Block '<S79>/Gain3' : Unused code path elimination
 * Block '<S100>/CONST_FALSE' : Unused code path elimination
 * Block '<S22>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S22>/ENU_TEST_INIT1' : Unused code path elimination
 * Block '<S134>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S136>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S135>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S137>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Relational_Operator5' : Unused code path elimination
 * Block '<S23>/CAL_ROBO_LENG' : Unused code path elimination
 * Block '<S23>/CAL_ROBO_LENG1' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S23>/Constant1' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion2' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion3' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion4' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion5' : Unused code path elimination
 * Block '<S23>/Data_Type_Conversion6' : Unused code path elimination
 * Block '<S23>/Divide' : Unused code path elimination
 * Block '<S23>/Divide1' : Unused code path elimination
 * Block '<S23>/Logical_Operator1' : Unused code path elimination
 * Block '<S23>/Relational_Operator' : Unused code path elimination
 * Block '<S23>/Relational_Operator1' : Unused code path elimination
 * Block '<S145>/CONST_noVelocity' : Unused code path elimination
 * Block '<S145>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S145>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S145>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S145>/Gain1' : Unused code path elimination
 * Block '<S146>/CONST_noVelocity' : Unused code path elimination
 * Block '<S146>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S146>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S146>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S146>/Gain1' : Unused code path elimination
 * Block '<S147>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S71>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S74>/Enable' : Eliminated due to constant selection input
 * Block '<S75>/Reset' : Eliminated due to constant selection input
 * Block '<S80>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S80>/Data_Type_Conversion2' : Eliminate redundant data type conversion
 * Block '<S83>/Enable' : Eliminated due to constant selection input
 * Block '<S84>/Reset' : Eliminated due to constant selection input
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S95>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S134>/Enable' : Eliminated due to constant selection input
 * Block '<S135>/Enable' : Eliminated due to constant selection input
 * Block '<S127>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S24>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S25>/Switch2' : Eliminated due to constant selection input
 * Block '<S25>/Switch3' : Eliminated due to constant selection input
 * Block '<S25>/Switch4' : Eliminated due to constant selection input
 * Block '<S71>/CONST_EnableDelay' : Unused code path elimination
 * Block '<S80>/CONST_EnableDelay' : Unused code path elimination
 * Block '<S132>/CONST_EnableDelay' : Unused code path elimination
 * Block '<S132>/CONST_EnableDelay1' : Unused code path elimination
 * Block '<S25>/CAL_MOTOR_HIGH' : Unused code path elimination
 * Block '<S25>/CONST_EndOfLineEnableFlg' : Unused code path elimination
 * Block '<S25>/CONST_EndOfLineEnableFlg1' : Unused code path elimination
 * Block '<S25>/CONST_EndOfLineEnableFlg2' : Unused code path elimination
 * Block '<S25>/Divide' : Unused code path elimination
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
 * '<S6>'   : 'RobotControl/InputHandler/D2'
 * '<S7>'   : 'RobotControl/InputHandler/EncoderAnalogIn'
 * '<S8>'   : 'RobotControl/InputHandler/Subsystem'
 * '<S9>'   : 'RobotControl/InputHandler/ULS_AnalogIn'
 * '<S10>'  : 'RobotControl/OutputHandler/Digital Output'
 * '<S11>'  : 'RobotControl/OutputHandler/Digital Output1'
 * '<S12>'  : 'RobotControl/OutputHandler/PWM'
 * '<S13>'  : 'RobotControl/OutputHandler/PWM1'
 * '<S14>'  : 'RobotControl/OutputHandler/PWM2'
 * '<S15>'  : 'RobotControl/OutputHandler/PWM3'
 * '<S16>'  : 'RobotControl/RobotControl/RobotControlLib'
 * '<S17>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler'
 * '<S18>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont'
 * '<S19>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA'
 * '<S20>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler'
 * '<S21>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines'
 * '<S22>'  : 'RobotControl/RobotControl/RobotControlLib/MovementHandler'
 * '<S23>'  : 'RobotControl/RobotControl/RobotControlLib/ScanHandler'
 * '<S24>'  : 'RobotControl/RobotControl/RobotControlLib/StopRoutine'
 * '<S25>'  : 'RobotControl/RobotControl/RobotControlLib/motorHandler'
 * '<S26>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator'
 * '<S27>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter'
 * '<S28>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation'
 * '<S29>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation1'
 * '<S30>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter'
 * '<S31>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter'
 * '<S32>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/movingAverage_1ms_to_5ms2'
 * '<S33>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/FromDegreeToRad2'
 * '<S34>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/OMEGA_Calc'
 * '<S35>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/thetaOverFlowFilter_Deg'
 * '<S36>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper'
 * '<S37>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected'
 * '<S38>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor'
 * '<S39>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1'
 * '<S40>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor'
 * '<S41>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor'
 * '<S42>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor'
 * '<S43>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor'
 * '<S44>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL'
 * '<S45>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL1'
 * '<S46>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator'
 * '<S47>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderAdaptation'
 * '<S48>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation'
 * '<S49>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest'
 * '<S50>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator'
 * '<S51>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator'
 * '<S52>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor'
 * '<S53>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor'
 * '<S54>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms'
 * '<S55>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms1'
 * '<S56>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor/EncoderIncrement'
 * '<S57>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor/EncoderIncrement'
 * '<S58>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/FromDegreeToRad2'
 * '<S59>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/OMEGA_Calc'
 * '<S60>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/movingAverage_1ms_to_5ms'
 * '<S61>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/thetaOverFlowFilter_Rad'
 * '<S62>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest'
 * '<S63>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine'
 * '<S64>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/LeftMotorEncoderCounter'
 * '<S65>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/RightMotorEncoderCounter1'
 * '<S66>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine'
 * '<S67>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator'
 * '<S68>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator'
 * '<S69>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor'
 * '<S70>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S71>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter'
 * '<S72>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator'
 * '<S73>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector'
 * '<S74>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S75>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S76>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator/motorModelTfDis'
 * '<S77>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector'
 * '<S78>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor'
 * '<S79>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S80>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter'
 * '<S81>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator'
 * '<S82>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector'
 * '<S83>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S84>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S85>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator/motorModelTfDis'
 * '<S86>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector/SpdTickDetector'
 * '<S87>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/LeftMotor'
 * '<S88>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/RightMotor'
 * '<S89>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler/Set_Reset'
 * '<S90>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine'
 * '<S91>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DistanceCalculator'
 * '<S92>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/End'
 * '<S93>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation'
 * '<S94>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl'
 * '<S95>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine'
 * '<S96>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/ULS_FaultHandler'
 * '<S97>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/routineEnableSwitch'
 * '<S98>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine'
 * '<S99>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration'
 * '<S100>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Bluetooth'
 * '<S101>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest'
 * '<S102>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest'
 * '<S103>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine'
 * '<S104>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/None'
 * '<S105>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/QuaterTurnTargetDist'
 * '<S106>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq'
 * '<S107>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart'
 * '<S108>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem'
 * '<S109>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading'
 * '<S110>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart'
 * '<S111>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler'
 * '<S112>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest'
 * '<S113>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest'
 * '<S114>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator'
 * '<S115>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S116>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator'
 * '<S117>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S118>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl'
 * '<S119>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl'
 * '<S120>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView'
 * '<S121>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine'
 * '<S122>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart'
 * '<S123>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart'
 * '<S124>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc'
 * '<S125>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc'
 * '<S126>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MaxSpeedsOnly'
 * '<S127>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine'
 * '<S128>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime'
 * '<S129>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TurnHandler'
 * '<S130>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler'
 * '<S131>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc'
 * '<S132>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID'
 * '<S133>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/rateLimiter'
 * '<S134>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable'
 * '<S135>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1'
 * '<S136>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable/Unit Delay Resettable'
 * '<S137>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S138>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves'
 * '<S139>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime'
 * '<S140>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler'
 * '<S141>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff1'
 * '<S142>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff4'
 * '<S143>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine'
 * '<S144>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine'
 * '<S145>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/LeftMotorPin'
 * '<S146>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/RightMotorPin'
 * '<S147>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/Unit_Delay_Resettable'
 * '<S148>' : 'RobotControl/Scheduler/Scheduler'
 */
#endif                                 /* RTW_HEADER_RobotControl_h_ */
