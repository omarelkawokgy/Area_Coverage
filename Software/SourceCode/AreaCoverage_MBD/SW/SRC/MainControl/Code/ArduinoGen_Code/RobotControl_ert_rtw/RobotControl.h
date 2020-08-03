/*
 * RobotControl.h
 *
 * Code generation for model "RobotControl".
 *
 * Model version              : 1.503
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 29 10:39:32 2020
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
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T Add5;                         /* '<S60>/Add5' */
  real_T sampleTime;
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
  real32_T EOL_pwm;                    /* '<S63>/EOL_TickStateMachine' */
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
  uint16_T encoderCounter;             /* '<S64>/Data_Type_Conversion' */
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
  uint8_T OutportBufferForangleCalibSta_a;/* '<S106>/CompassSelfDiagTestChart' */
  uint8_T OutportBufferFormoveRequest; /* '<S106>/CompassSelfDiagTestChart' */
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
  uint8_T DataTypeConversion_f;        /* '<S9>/Data Type Conversion' */
  uint8_T DataTypeConversion1_c;       /* '<S9>/Data Type Conversion1' */
  uint8_T EOL_leftMoveReq;             /* '<S63>/EOL_TickStateMachine' */
  uint8_T EOL_rightMoveReq;            /* '<S63>/EOL_TickStateMachine' */
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
  boolean_T counterReset;              /* '<S63>/EOL_TickStateMachine' */
  boolean_T DigitalInput;              /* '<S6>/Digital Input' */
  boolean_T p;
  boolean_T p_m;
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
  real32_T Unit_Delay_DSTATE_i;        /* '<S64>/Unit_Delay' */
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
  boolean_T Unit_Delay4_DSTATE_m;      /* '<S19>/Unit_Delay4' */
  boolean_T Unit_Delay_DSTATE_ja;      /* '<S62>/Unit_Delay' */
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

/* Parameters (auto storage) */
struct P_RobotControl_T_ {
  real_T gearRatio;                    /* Variable: gearRatio
                                        * Referenced by:
                                        *   '<S72>/gearRatio'
                                        *   '<S81>/gearRatio'
                                        */
  real32_T CAL_EncoderSampleTime;      /* Variable: CAL_EncoderSampleTime
                                        * Referenced by: '<S31>/CAL_EncoderSampleTime'
                                        */
  real32_T CAL_ErrorLowerLimit;        /* Variable: CAL_ErrorLowerLimit
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real32_T CAL_ErrorUpperLimit;        /* Variable: CAL_ErrorUpperLimit
                                        * Referenced by:
                                        *   '<S25>/Saturation'
                                        *   '<S25>/Saturation1'
                                        */
  real32_T CAL_Kd;                     /* Variable: CAL_Kd
                                        * Referenced by: '<S132>/Kd'
                                        */
  real32_T CAL_Ki;                     /* Variable: CAL_Ki
                                        * Referenced by: '<S132>/Ki'
                                        */
  real32_T CAL_Kp;                     /* Variable: CAL_Kp
                                        * Referenced by: '<S132>/Kp'
                                        */
  real32_T CAL_MeasNoiseVelKF;         /* Variable: CAL_MeasNoiseVelKF
                                        * Referenced by:
                                        *   '<S71>/CAL_MeasNoiseVelKF'
                                        *   '<S80>/CAL_MeasNoiseVelKF'
                                        */
  real32_T CAL_MeasureNoise;           /* Variable: CAL_MeasureNoise
                                        * Referenced by: '<S31>/CAL_MeasureNoise'
                                        */
  real32_T CAL_NORTH_rad;              /* Variable: CAL_NORTH_rad
                                        * Referenced by: '<S48>/Unit_Delay'
                                        */
  real32_T CAL_ProcessNoise;           /* Variable: CAL_ProcessNoise
                                        * Referenced by: '<S31>/CAL_ProcessNoise'
                                        */
  real32_T CAL_forwardStartIncr;       /* Variable: CAL_forwardStartIncr
                                        * Referenced by: '<S25>/CAL_forwardStartIncr'
                                        */
  real32_T CAL_hitBackwardDist_mm;     /* Variable: CAL_hitBackwardDist_mm
                                        * Referenced by: '<S24>/CAL_hitBackwardDist_mm1'
                                        */
  real32_T CAL_mm_PER_tick;            /* Variable: CAL_mm_PER_tick
                                        * Referenced by:
                                        *   '<S52>/Gain1'
                                        *   '<S53>/Gain1'
                                        */
  real32_T CAL_procNoiseVelKF;         /* Variable: CAL_procNoiseVelKF
                                        * Referenced by:
                                        *   '<S71>/CAL_procNoiseVelKF'
                                        *   '<S80>/CAL_procNoiseVelKF'
                                        */
  real32_T CONST_ONE_F32;              /* Variable: CONST_ONE_F32
                                        * Referenced by:
                                        *   '<S71>/CONST_ONE_F32'
                                        *   '<S80>/CONST_ONE_F32'
                                        */
  real32_T CONST_PI_F32;               /* Variable: CONST_PI_F32
                                        * Referenced by: '<S105>/CONST_PI_F32'
                                        */
  real32_T CONST_TWO_F32;              /* Variable: CONST_TWO_F32
                                        * Referenced by:
                                        *   '<S91>/CONST_TWO_F32'
                                        *   '<S124>/CONST_TWO_F32'
                                        *   '<S105>/CONST_TWO_F32'
                                        *   '<S105>/CONST_TWO_F321'
                                        *   '<S72>/CONST_TWO_F32'
                                        *   '<S81>/CONST_TWO_F32'
                                        */
  real32_T CONST_ZERO_F32;             /* Variable: CONST_ZERO_F32
                                        * Referenced by:
                                        *   '<S91>/CONST_ZERO_F32'
                                        *   '<S125>/CONST_ZERO_F32'
                                        *   '<S129>/CONST_ZERO_F32'
                                        */
  int32_T CONST_NEG_ONE_INT32;         /* Variable: CONST_NEG_ONE_INT32
                                        * Referenced by:
                                        *   '<S56>/CONST_NEG_ONE_INT32'
                                        *   '<S57>/CONST_NEG_ONE_INT32'
                                        */
  int32_T CONST_ONE_INT32;             /* Variable: CONST_ONE_INT32
                                        * Referenced by:
                                        *   '<S56>/CONST_ONE_INT32'
                                        *   '<S57>/CONST_ONE_INT32'
                                        */
  int16_T CAL_EAST;                    /* Variable: CAL_EAST
                                        * Referenced by: '<S20>/CAL_EAST'
                                        */
  int16_T CAL_NORTH;                   /* Variable: CAL_NORTH
                                        * Referenced by:
                                        *   '<S20>/CAL_NORTH'
                                        *   '<S21>/Unit_Delay5'
                                        *   '<S31>/Unit_Delay'
                                        */
  int16_T CAL_SOUTH;                   /* Variable: CAL_SOUTH
                                        * Referenced by: '<S20>/CAL_SOUTH'
                                        */
  int16_T CAL_WEST;                    /* Variable: CAL_WEST
                                        * Referenced by: '<S20>/CAL_WEST'
                                        */
  int16_T CONST_NegOne;                /* Variable: CONST_NegOne
                                        * Referenced by:
                                        *   '<S125>/Gain7'
                                        *   '<S125>/Gain8'
                                        */
  int16_T CONST_Zero;                  /* Variable: CONST_Zero
                                        * Referenced by:
                                        *   '<S44>/CONST_Zero'
                                        *   '<S45>/CONST_Zero'
                                        */
  int16_T CONST_ZeroDeg;               /* Variable: CONST_ZeroDeg
                                        * Referenced by: '<S31>/CONST_ZeroDeg1'
                                        */
  uint16_T CAL_EncoderAnaThd;          /* Variable: CAL_EncoderAnaThd
                                        * Referenced by:
                                        *   '<S47>/CAL_EncoderAnaThd'
                                        *   '<S47>/CAL_EncoderAnaThd1'
                                        */
  uint16_T CAL_ROBO_LENG_mm;           /* Variable: CAL_ROBO_LENG_mm
                                        * Referenced by:
                                        *   '<S59>/CAL_ROBO_LENG_mm'
                                        *   '<S34>/CAL_ROBO_LENG_mm'
                                        */
  uint16_T CAL_Wheel2WheelDist_mm;     /* Variable: CAL_Wheel2WheelDist_mm
                                        * Referenced by: '<S105>/CAL_Wheel2WheelDist_mm'
                                        */
  uint16_T CAL_fullCircle_DEG;         /* Variable: CAL_fullCircle_DEG
                                        * Referenced by:
                                        *   '<S125>/CAL_fullCircle_DEG'
                                        *   '<S125>/CAL_fullCircle_DEG1'
                                        *   '<S30>/Saturation'
                                        *   '<S31>/CAL_fullCircle_DEG'
                                        *   '<S35>/CAL_fullCircle_DEG'
                                        *   '<S35>/CAL_fullCircle_DEG1'
                                        */
  uint16_T CAL_halfCircle_DEG;         /* Variable: CAL_halfCircle_DEG
                                        * Referenced by:
                                        *   '<S125>/CAL_halfCircle_DEG'
                                        *   '<S125>/CAL_halfCircle_DEG1'
                                        *   '<S125>/CAL_halfCircle_DEG2'
                                        */
  uint16_T CONST_MinDistError_mm;      /* Variable: CONST_MinDistError_mm
                                        * Referenced by:
                                        *   '<S112>/CONST_MinDistError_mm'
                                        *   '<S113>/CONST_MinDistError_mm'
                                        */
  uint16_T CONST_ONE_UINT16;           /* Variable: CONST_ONE_UINT16
                                        * Referenced by:
                                        *   '<S31>/CONST_ONE_UINT16'
                                        *   '<S64>/CONST_ONE_UINT16'
                                        */
  uint16_T CONST_OVERFLOW_THD_UINT16;  /* Variable: CONST_OVERFLOW_THD_UINT16
                                        * Referenced by:
                                        *   '<S35>/CONST_OVERFLOW_THD_UINT16'
                                        *   '<S35>/CONST_OVERFLOW_THD_UINT161'
                                        */
  uint16_T CONST_ZERO_UINT16;          /* Variable: CONST_ZERO_UINT16
                                        * Referenced by:
                                        *   '<S30>/Saturation'
                                        *   '<S35>/CONST_ZERO_UINT16'
                                        */
  uint16_T ENU_ROB_NONE;               /* Variable: ENU_ROB_NONE
                                        * Referenced by:
                                        *   '<S26>/ENU_ROB_NONE'
                                        *   '<S127>/ENU_ROB_NONE'
                                        */
  uint8_T CAL_MOTOR_HIGH;              /* Variable: CAL_MOTOR_HIGH
                                        * Referenced by:
                                        *   '<S25>/CAL_MOTOR_HIGH'
                                        *   '<S145>/CAL_MOTOR_HIGH'
                                        *   '<S146>/CAL_MOTOR_HIGH'
                                        */
  uint8_T CAL_MOTOR_LOW;               /* Variable: CAL_MOTOR_LOW
                                        * Referenced by:
                                        *   '<S145>/CAL_MOTOR_LOW'
                                        *   '<S145>/CAL_MOTOR_LOW1'
                                        *   '<S145>/CAL_MOTOR_LOW2'
                                        *   '<S145>/CAL_MOTOR_LOW3'
                                        *   '<S146>/CAL_MOTOR_LOW'
                                        *   '<S146>/CAL_MOTOR_LOW1'
                                        *   '<S146>/CAL_MOTOR_LOW2'
                                        *   '<S146>/CAL_MOTOR_LOW3'
                                        */
  uint8_T CAL_NO_ERROR;                /* Variable: CAL_NO_ERROR
                                        * Referenced by:
                                        *   '<S22>/CAL_NO_ERROR'
                                        *   '<S22>/CAL_NO_ERROR1'
                                        *   '<S22>/Unit_Delay4'
                                        */
  uint8_T CAL_PwmMoveThd_mm;           /* Variable: CAL_PwmMoveThd_mm
                                        * Referenced by:
                                        *   '<S38>/CAL_PwmMoveThd_mm'
                                        *   '<S39>/CAL_PwmMoveThd_mm'
                                        */
  uint8_T CAL_ROBO_LENG;               /* Variable: CAL_ROBO_LENG
                                        * Referenced by:
                                        *   '<S140>/CAL_ROBO_LENG'
                                        *   '<S140>/CAL_ROBO_LENG1'
                                        */
  uint8_T CAL_ROB_ERRVAL;              /* Variable: CAL_ROB_ERRVAL
                                        * Referenced by: '<S26>/CAL_ROB_ERRVAL'
                                        */
  uint8_T CAL_ULS_UnconnectedBlks;     /* Variable: CAL_ULS_UnconnectedBlks
                                        * Referenced by:
                                        *   '<S96>/CAL_ULS_UnconnectedBlks'
                                        *   '<S96>/CAL_ULS_UnconnectedBlks1'
                                        */
  uint8_T CAL_WheelDiameter_cm;        /* Variable: CAL_WheelDiameter_cm
                                        * Referenced by:
                                        *   '<S72>/CAL_WheelDiameter_cm'
                                        *   '<S81>/CAL_WheelDiameter_cm'
                                        */
  uint8_T CAL_thetaGain;               /* Variable: CAL_thetaGain
                                        * Referenced by:
                                        *   '<S22>/Gain4'
                                        *   '<S125>/Gain'
                                        *   '<S125>/Gain1'
                                        *   '<S125>/Gain2'
                                        *   '<S125>/Gain3'
                                        *   '<S125>/Gain4'
                                        *   '<S125>/Gain5'
                                        *   '<S30>/Gain'
                                        */
  uint8_T CONST_DIAG_FINISH_FLG;       /* Variable: CONST_DIAG_FINISH_FLG
                                        * Referenced by: '<S104>/CONST_DIAG_FINISH_FLG'
                                        */
  uint8_T CONST_DIAG_UNCONFIRM;        /* Variable: CONST_DIAG_UNCONFIRM
                                        * Referenced by:
                                        *   '<S21>/Unit_Delay4'
                                        *   '<S90>/DIAG_StatusFlg'
                                        *   '<S104>/None'
                                        */
  uint8_T ENU_BACKWARD;                /* Variable: ENU_BACKWARD
                                        * Referenced by:
                                        *   '<S22>/ENU_BACKWARD'
                                        *   '<S25>/ENU_FORWARD1'
                                        *   '<S126>/ENU_BACKWARD'
                                        *   '<S126>/ENU_BACKWARD1'
                                        *   '<S126>/ENU_BACKWARD2'
                                        *   '<S126>/ENU_BACKWARD3'
                                        *   '<S126>/ENU_BACKWARD4'
                                        *   '<S127>/ENU_BACKWARD'
                                        *   '<S145>/ENU_BACKWARD'
                                        *   '<S146>/ENU_BACKWARD'
                                        *   '<S87>/ENU_BACKWARD'
                                        *   '<S88>/ENU_BACKWARD'
                                        */
  uint8_T ENU_CCW;                     /* Variable: ENU_CCW
                                        * Referenced by:
                                        *   '<S126>/ENU_CCW'
                                        *   '<S127>/ENU_CCW'
                                        *   '<S129>/ENU_CCW'
                                        */
  uint8_T ENU_CW;                      /* Variable: ENU_CW
                                        * Referenced by:
                                        *   '<S126>/ENU_CW'
                                        *   '<S127>/ENU_CW'
                                        *   '<S129>/ENU_CW'
                                        */
  uint8_T ENU_DIAG;                    /* Variable: ENU_DIAG
                                        * Referenced by:
                                        *   '<S18>/ENU_DIAG'
                                        *   '<S19>/ENU_DIAG'
                                        */
  uint8_T ENU_END;                     /* Variable: ENU_END
                                        * Referenced by: '<S20>/Unit_Delay'
                                        */
  uint8_T ENU_FAILED;                  /* Variable: ENU_FAILED
                                        * Referenced by: '<S102>/ENU_FAILED'
                                        */
  uint8_T ENU_FORWARD;                 /* Variable: ENU_FORWARD
                                        * Referenced by:
                                        *   '<S22>/ENU_FORWARD'
                                        *   '<S25>/ENU_FORWARD'
                                        *   '<S91>/ENU_FORWARD'
                                        *   '<S95>/ENU_FORWARD'
                                        *   '<S98>/ENU_FORWARD'
                                        *   '<S124>/ENU_FORWARD'
                                        *   '<S126>/ENU_FORWARD'
                                        *   '<S126>/ENU_FORWARD1'
                                        *   '<S126>/ENU_FORWARD2'
                                        *   '<S126>/ENU_FORWARD3'
                                        *   '<S126>/ENU_FORWARD4'
                                        *   '<S127>/ENU_FORWARD'
                                        *   '<S145>/ENU_FORWARD'
                                        *   '<S146>/ENU_FORWARD'
                                        *   '<S87>/ENU_FORWARD'
                                        *   '<S88>/ENU_FORWARD'
                                        *   '<S56>/ENU_FORWARD'
                                        *   '<S57>/ENU_FORWARD'
                                        *   '<S69>/ENU_FORWARD'
                                        *   '<S78>/ENU_FORWARD'
                                        */
  uint8_T ENU_GTSP;                    /* Variable: ENU_GTSP
                                        * Referenced by: '<S95>/ENU_GTSP'
                                        */
  uint8_T ENU_LEFT_BUSY_RIGHT_BUSY;    /* Variable: ENU_LEFT_BUSY_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_BUSY'
                                        */
  uint8_T ENU_LEFT_BUSY_RIGHT_CLEANED; /* Variable: ENU_LEFT_BUSY_RIGHT_CLEANED
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_CLEANED'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_CLEANED'
                                        */
  uint8_T ENU_LEFT_BUSY_RIGHT_EMPTY;   /* Variable: ENU_LEFT_BUSY_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        *   '<S95>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                                        */
  uint8_T ENU_LEFT_CLEANED_RIGHT_BUSY; /* Variable: ENU_LEFT_CLEANED_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_CLEANED_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_CLEANED_RIGHT_BUSY'
                                        */
  uint8_T ENU_LEFT_CLEANED_RIGHT_CLEANED;/* Variable: ENU_LEFT_CLEANED_RIGHT_CLEANED
                                          * Referenced by:
                                          *   '<S95>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
                                          *   '<S98>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
                                          */
  uint8_T ENU_LEFT_CLEANED_RIGHT_EMPTY;/* Variable: ENU_LEFT_CLEANED_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_CLEANED_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_CLEANED_RIGHT_EMPTY'
                                        */
  uint8_T ENU_LEFT_EMPTY_RIGHT_BUSY;   /* Variable: ENU_LEFT_EMPTY_RIGHT_BUSY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_BUSY'
                                        */
  uint8_T ENU_LEFT_EMPTY_RIGHT_CLEANED;/* Variable: ENU_LEFT_EMPTY_RIGHT_CLEANED
                                        * Referenced by:
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_CLEANED'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_CLEANED'
                                        */
  uint8_T ENU_LEFT_EMPTY_RIGHT_EMPTY;  /* Variable: ENU_LEFT_EMPTY_RIGHT_EMPTY
                                        * Referenced by:
                                        *   '<S93>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        *   '<S95>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        *   '<S98>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                                        */
  uint8_T ENU_MOVE_TURN_LEFT;          /* Variable: ENU_MOVE_TURN_LEFT
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_TURN_LEFT'
                                        *   '<S127>/ENU_MOVE_TURN_LEFT'
                                        *   '<S102>/ENU_MOVE_TURN_LEFT'
                                        */
  uint8_T ENU_MOVE_TURN_RIGHT;         /* Variable: ENU_MOVE_TURN_RIGHT
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_TURN_RIGHT'
                                        *   '<S127>/ENU_MOVE_TURN_RIGHT'
                                        */
  uint8_T ENU_MOVE_U_TURN;             /* Variable: ENU_MOVE_U_TURN
                                        * Referenced by:
                                        *   '<S95>/ENU_MOVE_U_TURN'
                                        *   '<S98>/ENU_MOVE_U_TURN'
                                        *   '<S127>/ENU_MOVE_U_TURN'
                                        */
  uint8_T ENU_MOVE_U_TURN_LEFT;        /* Variable: ENU_MOVE_U_TURN_LEFT
                                        * Referenced by:
                                        *   '<S98>/ENU_MOVE_U_TURN_LEFT'
                                        *   '<S127>/ENU_MOVE_U_TURN_LEFT'
                                        */
  uint8_T ENU_MOVE_U_TURN_RIGHT;       /* Variable: ENU_MOVE_U_TURN_RIGHT
                                        * Referenced by:
                                        *   '<S98>/ENU_MOVE_U_TURN_RIGHT'
                                        *   '<S127>/ENU_MOVE_U_TURN_RIGHT'
                                        */
  uint8_T ENU_PASSED;                  /* Variable: ENU_PASSED
                                        * Referenced by:
                                        *   '<S90>/ENU_PASSED'
                                        *   '<S102>/ENU_PASSED'
                                        */
  uint8_T ENU_SHIFT_HEADING;           /* Variable: ENU_SHIFT_HEADING
                                        * Referenced by:
                                        *   '<S22>/ENU_SHIFT_HEADING'
                                        *   '<S89>/ENU_SHIFT_HEADING'
                                        */
  uint8_T ENU_STOP;                    /* Variable: ENU_STOP
                                        * Referenced by:
                                        *   '<S22>/ENU_STOP'
                                        *   '<S92>/ENU_STOP'
                                        *   '<S95>/ENU_STOP'
                                        *   '<S98>/ENU_STOP'
                                        *   '<S126>/ENU_STOP'
                                        *   '<S126>/ENU_STOP1'
                                        *   '<S127>/ENU_STOP'
                                        *   '<S145>/ENU_STOP'
                                        *   '<S146>/ENU_STOP'
                                        *   '<S87>/ENU_STOP'
                                        *   '<S88>/ENU_STOP'
                                        *   '<S100>/ENU_STOP'
                                        *   '<S104>/ENU_STOP'
                                        *   '<S106>/moveRequest'
                                        */
  uint8_T ENU_TEST_INIT;               /* Variable: ENU_TEST_INIT
                                        * Referenced by: '<S22>/ENU_TEST_INIT'
                                        */
  uint8_T ENU_TEST_NOT_CONFIRMED;      /* Variable: ENU_TEST_NOT_CONFIRMED
                                        * Referenced by:
                                        *   '<S90>/Unit_Delay'
                                        *   '<S90>/Unit_Delay1'
                                        *   '<S90>/Unit_Delay2'
                                        *   '<S99>/angleCalibStatus'
                                        *   '<S102>/ENU_TEST_NOT_CONFIRMED'
                                        *   '<S106>/angleCalibStatus'
                                        */
  boolean_T CONST_EnableDelay;         /* Variable: CONST_EnableDelay
                                        * Referenced by:
                                        *   '<S132>/CONST_EnableDelay'
                                        *   '<S132>/CONST_EnableDelay1'
                                        *   '<S71>/CONST_EnableDelay'
                                        *   '<S80>/CONST_EnableDelay'
                                        */
  boolean_T CONST_EndOfLineEnableFlg;  /* Variable: CONST_EndOfLineEnableFlg
                                        * Referenced by:
                                        *   '<S25>/CONST_EndOfLineEnableFlg'
                                        *   '<S25>/CONST_EndOfLineEnableFlg1'
                                        *   '<S25>/CONST_EndOfLineEnableFlg2'
                                        *   '<S49>/CONST_EndOfLineEnableFlg'
                                        */
  boolean_T CONST_FALSE;               /* Variable: CONST_FALSE
                                        * Referenced by:
                                        *   '<S71>/CONST_FALSE'
                                        *   '<S80>/CONST_FALSE'
                                        */
  real32_T Unit_Delay_Enabled_Resettable1_;/* Mask Parameter: Unit_Delay_Enabled_Resettable1_
                                            * Referenced by:
                                            *   '<S75>/Initial Condition'
                                            *   '<S75>/FixPt Unit Delay1'
                                            */
  real32_T Unit_Delay_Enabled_Resettable_h;/* Mask Parameter: Unit_Delay_Enabled_Resettable_h
                                            * Referenced by:
                                            *   '<S84>/Initial Condition'
                                            *   '<S84>/FixPt Unit Delay1'
                                            */
  real32_T Unit_Delay_Enabled_Resettable_v;/* Mask Parameter: Unit_Delay_Enabled_Resettable_v
                                            * Referenced by:
                                            *   '<S136>/Initial Condition'
                                            *   '<S136>/FixPt Unit Delay1'
                                            */
  real32_T Unit_Delay_Enabled_Resettabl_hd;/* Mask Parameter: Unit_Delay_Enabled_Resettabl_hd
                                            * Referenced by:
                                            *   '<S137>/Initial Condition'
                                            *   '<S137>/FixPt Unit Delay1'
                                            */
  real32_T Unit_Delay_Resettable_vinit;/* Mask Parameter: Unit_Delay_Resettable_vinit
                                        * Referenced by:
                                        *   '<S147>/Initial Condition'
                                        *   '<S147>/FixPt Unit Delay1'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  uint32_T PWM_pinNumber_b;            /* Mask Parameter: PWM_pinNumber_b
                                        * Referenced by: '<S13>/PWM'
                                        */
  uint32_T PWM_pinNumber_d;            /* Mask Parameter: PWM_pinNumber_d
                                        * Referenced by: '<S14>/PWM'
                                        */
  uint32_T PWM_pinNumber_bq;           /* Mask Parameter: PWM_pinNumber_bq
                                        * Referenced by: '<S15>/PWM'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S6>/Digital Input'
                                        */
  real_T Constant2_Value;              /* Expression: 180
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: pi
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S61>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2*pi
                                        * Referenced by: '<S61>/Constant1'
                                        */
  real_T thetaEncodUnfiltered_Y0;      /* Computed Parameter: thetaEncodUnfiltered_Y0
                                        * Referenced by: '<S48>/thetaEncodUnfiltered'
                                        */
  real_T Constant_Value;               /* Expression: 0.001
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: pi
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 180
                                        * Referenced by: '<S58>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S61>/Constant3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S60>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S60>/Delay1'
                                        */
  real_T Gain3_Gain;                   /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S60>/Gain3'
                                        */
  real_T DigitalPin7_Value;            /* Expression: 7
                                        * Referenced by: '<S9>/DigitalPin7'
                                        */
  real_T DigitalPin8_Value;            /* Expression: 8
                                        * Referenced by: '<S9>/DigitalPin8'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S133>/Constant'
                                        */
  real32_T theta_Deg_Y0;               /* Computed Parameter: theta_Deg_Y0
                                        * Referenced by: '<S27>/theta_Deg'
                                        */
  real32_T theta_mDeg_Y0;              /* Computed Parameter: theta_mDeg_Y0
                                        * Referenced by: '<S27>/theta_mDeg'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S31>/Constant'
                                        */
  real32_T thetaEncod_Y0;              /* Computed Parameter: thetaEncod_Y0
                                        * Referenced by: '<S48>/thetaEncod'
                                        */
  real32_T Unit_Delay_InitialCondition;/* Computed Parameter: Unit_Delay_InitialCondition
                                        * Referenced by: '<S64>/Unit_Delay'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S69>/Gain2'
                                        */
  real32_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S78>/Gain2'
                                        */
  real32_T leftVel_mmPerSec_Y0;        /* Computed Parameter: leftVel_mmPerSec_Y0
                                        * Referenced by: '<S19>/leftVel_mmPerSec'
                                        */
  real32_T leftDistTravelled_mm_Y0;    /* Computed Parameter: leftDistTravelled_mm_Y0
                                        * Referenced by: '<S19>/leftDistTravelled_mm'
                                        */
  real32_T rightVel_mmPerSec_Y0;       /* Computed Parameter: rightVel_mmPerSec_Y0
                                        * Referenced by: '<S19>/rightVel_mmPerSec'
                                        */
  real32_T rightDistTravelled_mm_Y0;   /* Computed Parameter: rightDistTravelled_mm_Y0
                                        * Referenced by: '<S19>/rightDistTravelled_mm'
                                        */
  real32_T MotorTransferFunction_NumCoef[3];/* Computed Parameter: MotorTransferFunction_NumCoef
                                             * Referenced by: '<S76>/MotorTransferFunction'
                                             */
  real32_T MotorTransferFunction_DenCoef[3];/* Expression: [Z2, Z1, Z0]
                                             * Referenced by: '<S76>/MotorTransferFunction'
                                             */
  real32_T MotorTransferFunction_InitialSt;/* Computed Parameter: MotorTransferFunction_InitialSt
                                            * Referenced by: '<S76>/MotorTransferFunction'
                                            */
  real32_T MotorTransferFunction_NumCoef_d[3];/* Computed Parameter: MotorTransferFunction_NumCoef_d
                                               * Referenced by: '<S85>/MotorTransferFunction'
                                               */
  real32_T MotorTransferFunction_DenCoef_h[3];/* Expression: [Z2, Z1, Z0]
                                               * Referenced by: '<S85>/MotorTransferFunction'
                                               */
  real32_T MotorTransferFunction_Initial_m;/* Computed Parameter: MotorTransferFunction_Initial_m
                                            * Referenced by: '<S85>/MotorTransferFunction'
                                            */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S54>/Delay'
                                        */
  real32_T Delay1_InitialCondition_i;  /* Expression: single(0)
                                        * Referenced by: '<S54>/Delay1'
                                        */
  real32_T Gain3_Gain_c;               /* Expression: single(1/5)
                                        * Referenced by: '<S54>/Gain3'
                                        */
  real32_T Delay_InitialCondition_l;   /* Computed Parameter: Delay_InitialCondition_l
                                        * Referenced by: '<S55>/Delay'
                                        */
  real32_T Delay1_InitialCondition_l;  /* Expression: single(0)
                                        * Referenced by: '<S55>/Delay1'
                                        */
  real32_T Gain3_Gain_e;               /* Expression: single(1/5)
                                        * Referenced by: '<S55>/Gain3'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S133>/Gain'
                                        */
  real32_T thetaError_Y0;              /* Computed Parameter: thetaError_Y0
                                        * Referenced by: '<S22>/thetaError'
                                        */
  real32_T UnitDelay_InitialCondition; /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S125>/Unit Delay'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S125>/Constant'
                                        */
  real32_T Saturation_LowerSat_b;      /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S25>/Saturation'
                                        */
  uint32_T A0_p1;                      /* Computed Parameter: A0_p1
                                        * Referenced by: '<S7>/A0'
                                        */
  uint32_T A1_p1;                      /* Computed Parameter: A1_p1
                                        * Referenced by: '<S7>/A1'
                                        */
  Calib CAL_FilterResetThd_Value;      /* Expression: Calib.CAL_FilterResetThd
                                        * Referenced by: '<S31>/CAL_FilterResetThd'
                                        */
  int16_T NORTH_Y0;                    /* Computed Parameter: NORTH_Y0
                                        * Referenced by: '<S20>/NORTH'
                                        */
  int16_T SOUTH_Y0;                    /* Computed Parameter: SOUTH_Y0
                                        * Referenced by: '<S20>/SOUTH'
                                        */
  int16_T EAST_Y0;                     /* Computed Parameter: EAST_Y0
                                        * Referenced by: '<S20>/EAST'
                                        */
  int16_T WEST_Y0;                     /* Computed Parameter: WEST_Y0
                                        * Referenced by: '<S20>/WEST'
                                        */
  int16_T thetaCompass_Y0;             /* Computed Parameter: thetaCompass_Y0
                                        * Referenced by: '<S5>/thetaCompass'
                                        */
  int16_T Delay_InitialCondition_i;    /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S142>/Delay'
                                        */
  int16_T Delay1_InitialCondition_m;   /* Computed Parameter: Delay1_InitialCondition_m
                                        * Referenced by: '<S142>/Delay1'
                                        */
  int16_T Delay_InitialCondition_k;    /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S141>/Delay'
                                        */
  int16_T Delay1_InitialCondition_f;   /* Computed Parameter: Delay1_InitialCondition_f
                                        * Referenced by: '<S141>/Delay1'
                                        */
  int16_T OP_Vl_Y0;                    /* Computed Parameter: OP_Vl_Y0
                                        * Referenced by: '<S25>/OP_Vl'
                                        */
  int16_T OP_Vr_Y0;                    /* Computed Parameter: OP_Vr_Y0
                                        * Referenced by: '<S25>/OP_Vr'
                                        */
  uint16_T Resettable_Delay_DelayLength;/* Computed Parameter: Resettable_Delay_DelayLength
                                         * Referenced by: '<S31>/Resettable_Delay'
                                         */
  uint16_T Resettable_Delay1_DelayLength;/* Computed Parameter: Resettable_Delay1_DelayLength
                                          * Referenced by: '<S31>/Resettable_Delay1'
                                          */
  uint16_T rightEncoderTicks_BOOL_Y0;  /* Computed Parameter: rightEncoderTicks_BOOL_Y0
                                        * Referenced by: '<S7>/rightEncoderTicks_BOOL'
                                        */
  uint16_T leftEncoderTicks_BOOL_Y0;   /* Computed Parameter: leftEncoderTicks_BOOL_Y0
                                        * Referenced by: '<S7>/leftEncoderTicks_BOOL'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S60>/Delay'
                                        */
  uint16_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S60>/Delay1'
                                        */
  uint16_T encoderCounter_Y0;          /* Computed Parameter: encoderCounter_Y0
                                        * Referenced by: '<S64>/encoderCounter'
                                        */
  uint16_T encoderCounter_Y0_b;        /* Computed Parameter: encoderCounter_Y0_b
                                        * Referenced by: '<S65>/encoderCounter'
                                        */
  uint16_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S54>/Delay'
                                        */
  uint16_T Delay1_DelayLength_h;       /* Computed Parameter: Delay1_DelayLength_h
                                        * Referenced by: '<S54>/Delay1'
                                        */
  uint16_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S55>/Delay'
                                        */
  uint16_T Delay1_DelayLength_n;       /* Computed Parameter: Delay1_DelayLength_n
                                        * Referenced by: '<S55>/Delay1'
                                        */
  uint16_T ULSL_cm_Y0;                 /* Computed Parameter: ULSL_cm_Y0
                                        * Referenced by: '<S9>/ULSL_cm'
                                        */
  uint16_T ULSR_cm_Y0;                 /* Computed Parameter: ULSR_cm_Y0
                                        * Referenced by: '<S9>/ULSR_cm'
                                        */
  uint16_T leftBlocks_Y0;              /* Computed Parameter: leftBlocks_Y0
                                        * Referenced by: '<S23>/leftBlocks'
                                        */
  uint16_T rightBlocks_Y0;             /* Computed Parameter: rightBlocks_Y0
                                        * Referenced by: '<S23>/rightBlocks'
                                        */
  uint16_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S142>/Delay'
                                        */
  uint16_T Delay1_DelayLength_j;       /* Computed Parameter: Delay1_DelayLength_j
                                        * Referenced by: '<S142>/Delay1'
                                        */
  uint16_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S141>/Delay'
                                        */
  uint16_T Delay1_DelayLength_h4;      /* Computed Parameter: Delay1_DelayLength_h4
                                        * Referenced by: '<S141>/Delay1'
                                        */
  uint16_T angleCalib_NORTH_Y0;        /* Computed Parameter: angleCalib_NORTH_Y0
                                        * Referenced by: '<S106>/angleCalib_NORTH'
                                        */
  uint16_T angleCalib_SOUTH_Y0;        /* Computed Parameter: angleCalib_SOUTH_Y0
                                        * Referenced by: '<S106>/angleCalib_SOUTH'
                                        */
  uint16_T angleCalib_EAST_Y0;         /* Computed Parameter: angleCalib_EAST_Y0
                                        * Referenced by: '<S106>/angleCalib_EAST'
                                        */
  uint16_T angleCalib_WEST_Y0;         /* Computed Parameter: angleCalib_WEST_Y0
                                        * Referenced by: '<S106>/angleCalib_WEST'
                                        */
  uint16_T angleCalib_NORTH_Y0_g;      /* Computed Parameter: angleCalib_NORTH_Y0_g
                                        * Referenced by: '<S99>/angleCalib_NORTH'
                                        */
  uint16_T angleCalib_SOUTH_Y0_j;      /* Computed Parameter: angleCalib_SOUTH_Y0_j
                                        * Referenced by: '<S99>/angleCalib_SOUTH'
                                        */
  uint16_T angleCalib_EAST_Y0_h;       /* Computed Parameter: angleCalib_EAST_Y0_h
                                        * Referenced by: '<S99>/angleCalib_EAST'
                                        */
  uint16_T angleCalib_WEST_Y0_o;       /* Computed Parameter: angleCalib_WEST_Y0_o
                                        * Referenced by: '<S99>/angleCalib_WEST'
                                        */
  uint16_T angleCalib_NORTH_Y0_e;      /* Computed Parameter: angleCalib_NORTH_Y0_e
                                        * Referenced by: '<S90>/angleCalib_NORTH'
                                        */
  uint16_T angleCalib_SOUTH_Y0_g;      /* Computed Parameter: angleCalib_SOUTH_Y0_g
                                        * Referenced by: '<S90>/angleCalib_SOUTH'
                                        */
  uint16_T angleCalib_EAST_Y0_e;       /* Computed Parameter: angleCalib_EAST_Y0_e
                                        * Referenced by: '<S90>/angleCalib_EAST'
                                        */
  uint16_T angleCalib_WEST_Y0_m;       /* Computed Parameter: angleCalib_WEST_Y0_m
                                        * Referenced by: '<S90>/angleCalib_WEST'
                                        */
  uint16_T angleCalib_NORTH_Y0_p;      /* Computed Parameter: angleCalib_NORTH_Y0_p
                                        * Referenced by: '<S21>/angleCalib_NORTH'
                                        */
  uint16_T angleCalib_SOUTH_Y0_d;      /* Computed Parameter: angleCalib_SOUTH_Y0_d
                                        * Referenced by: '<S21>/angleCalib_SOUTH'
                                        */
  uint16_T angleCalib_EAST_Y0_l;       /* Computed Parameter: angleCalib_EAST_Y0_l
                                        * Referenced by: '<S21>/angleCalib_EAST'
                                        */
  uint16_T angleCalib_WEST_Y0_f;       /* Computed Parameter: angleCalib_WEST_Y0_f
                                        * Referenced by: '<S21>/angleCalib_WEST'
                                        */
  int16_T Gain_Gain_h;                 /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S72>/Gain'
                                        */
  int16_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S81>/Gain'
                                        */
  int16_T Gain3_Gain_i;                /* Computed Parameter: Gain3_Gain_i
                                        * Referenced by: '<S142>/Gain3'
                                        */
  int16_T Gain3_Gain_e3;               /* Computed Parameter: Gain3_Gain_e3
                                        * Referenced by: '<S141>/Gain3'
                                        */
  uint8_T Unit_Delay5_InitialCondition;/* Computed Parameter: Unit_Delay5_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay5'
                                        */
  uint8_T Unit_Delay6_InitialCondition;/* Computed Parameter: Unit_Delay6_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay6'
                                        */
  uint8_T Unit_Delay7_InitialCondition;/* Computed Parameter: Unit_Delay7_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay7'
                                        */
  uint8_T Unit_Delay8_InitialCondition;/* Computed Parameter: Unit_Delay8_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay8'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S75>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_i;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_i
                                           * Referenced by: '<S84>/FixPt Unit Delay2'
                                           */
  uint8_T Unit_Delay2_InitialCondition;/* Computed Parameter: Unit_Delay2_InitialCondition
                                        * Referenced by: '<S19>/Unit_Delay2'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S75>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_b;       /* Computed Parameter: FixPtConstant_Value_b
                                        * Referenced by: '<S84>/FixPt Constant'
                                        */
  uint8_T rightMotorRequest_Y0;        /* Computed Parameter: rightMotorRequest_Y0
                                        * Referenced by: '<S22>/rightMotorRequest'
                                        */
  uint8_T leftMotorRequest_Y0;         /* Computed Parameter: leftMotorRequest_Y0
                                        * Referenced by: '<S22>/leftMotorRequest'
                                        */
  uint8_T turnRequest1_Y0;             /* Computed Parameter: turnRequest1_Y0
                                        * Referenced by: '<S22>/turnRequest1'
                                        */
  uint8_T Unit_Delay5_InitialCondition_c;/* Computed Parameter: Unit_Delay5_InitialCondition_c
                                          * Referenced by: '<S22>/Unit_Delay5'
                                          */
  uint8_T FixPtUnitDelay2_InitialCondit_j;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_j
                                           * Referenced by: '<S136>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_k;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_k
                                           * Referenced by: '<S137>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S136>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_f;       /* Computed Parameter: FixPtConstant_Value_f
                                        * Referenced by: '<S137>/FixPt Constant'
                                        */
  uint8_T swLaneCnt_uint8_Y0;          /* Computed Parameter: swLaneCnt_uint8_Y0
                                        * Referenced by: '<S98>/swLaneCnt_uint8'
                                        */
  uint8_T encoderTstStatus_Y0;         /* Computed Parameter: encoderTstStatus_Y0
                                        * Referenced by: '<S102>/encoderTstStatus'
                                        */
  uint8_T moveRequest_Y0;              /* Computed Parameter: moveRequest_Y0
                                        * Referenced by: '<S21>/moveRequest'
                                        */
  uint8_T Unit_Delay3_InitialCondition;/* Computed Parameter: Unit_Delay3_InitialCondition
                                        * Referenced by: '<S21>/Unit_Delay3'
                                        */
  uint8_T Unit_Delay2_InitialCondition_e;/* Computed Parameter: Unit_Delay2_InitialCondition_e
                                          * Referenced by: '<S21>/Unit_Delay2'
                                          */
  uint8_T Merge_InitialOutput;         /* Expression: ENU_STOP
                                        * Referenced by: '<S21>/Merge'
                                        */
  uint8_T leftPosPin_Y0;               /* Computed Parameter: leftPosPin_Y0
                                        * Referenced by: '<S25>/leftPosPin'
                                        */
  uint8_T leftNegPin_Y0;               /* Computed Parameter: leftNegPin_Y0
                                        * Referenced by: '<S25>/leftNegPin'
                                        */
  uint8_T rightPosPin_Y0;              /* Computed Parameter: rightPosPin_Y0
                                        * Referenced by: '<S25>/rightPosPin'
                                        */
  uint8_T rightNegPin_Y0;              /* Computed Parameter: rightNegPin_Y0
                                        * Referenced by: '<S25>/rightNegPin'
                                        */
  uint8_T FixPtUnitDelay2_InitialCondit_m;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_m
                                           * Referenced by: '<S147>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value_m;       /* Computed Parameter: FixPtConstant_Value_m
                                        * Referenced by: '<S147>/FixPt Constant'
                                        */
  boolean_T Unit_Delay3_InitialCondition_b;/* Computed Parameter: Unit_Delay3_InitialCondition_b
                                            * Referenced by: '<S27>/Unit_Delay3'
                                            */
  boolean_T false1_Value;              /* Expression: false
                                        * Referenced by: '<S47>/false1'
                                        */
  boolean_T true1_Value;               /* Expression: true
                                        * Referenced by: '<S47>/true1'
                                        */
  boolean_T false_Value;               /* Expression: false
                                        * Referenced by: '<S47>/false'
                                        */
  boolean_T true_Value;                /* Expression: true
                                        * Referenced by: '<S47>/true'
                                        */
  boolean_T Unit_Delay_InitialCondition_c;/* Computed Parameter: Unit_Delay_InitialCondition_c
                                           * Referenced by: '<S62>/Unit_Delay'
                                           */
  boolean_T Unit_Delay4_InitialCondition;/* Computed Parameter: Unit_Delay4_InitialCondition
                                          * Referenced by: '<S19>/Unit_Delay4'
                                          */
  boolean_T Constant1_Value_n;         /* Expression: false
                                        * Referenced by: '<S89>/Constant1'
                                        */
  boolean_T Constant_Value_i;          /* Expression: true
                                        * Referenced by: '<S89>/Constant'
                                        */
  boolean_T UnitDelay_InitialCondition_g;/* Computed Parameter: UnitDelay_InitialCondition_g
                                          * Referenced by: '<S89>/Unit Delay'
                                          */
  boolean_T posStopReq_Y0;             /* Computed Parameter: posStopReq_Y0
                                        * Referenced by: '<S23>/posStopReq'
                                        */
  boolean_T targetReached_Y0;          /* Computed Parameter: targetReached_Y0
                                        * Referenced by: '<S22>/targetReached'
                                        */
  boolean_T Unit_Delay1_InitialCondition;/* Expression: false
                                          * Referenced by: '<S22>/Unit_Delay1'
                                          */
  boolean_T Unit_Delay2_InitialCondition_j;/* Expression: false
                                            * Referenced by: '<S22>/Unit_Delay2'
                                            */
  boolean_T Unit_Delay3_InitialCondition_p;/* Expression: false
                                            * Referenced by: '<S22>/Unit_Delay3'
                                            */
  boolean_T zgzgActive_Y0;             /* Expression: true
                                        * Referenced by: '<S98>/zgzgActive'
                                        */
  boolean_T switchLaneFlg_BOOL_Y0;     /* Expression: false
                                        * Referenced by: '<S98>/switchLaneFlg_BOOL'
                                        */
  boolean_T GT_active_Y0;              /* Computed Parameter: GT_active_Y0
                                        * Referenced by: '<S95>/GT_active'
                                        */
  boolean_T rightEncodDistErrorFlg_BOOL_Y0;/* Computed Parameter: rightEncodDistErrorFlg_BOOL_Y0
                                            * Referenced by: '<S102>/rightEncodDistErrorFlg_BOOL'
                                            */
  boolean_T leftEncodDistErrorFlg_BOOL_Y0;/* Computed Parameter: leftEncodDistErrorFlg_BOOL_Y0
                                           * Referenced by: '<S102>/leftEncodDistErrorFlg_BOOL'
                                           */
  boolean_T hardwareFaultFlg_Y0;       /* Computed Parameter: hardwareFaultFlg_Y0
                                        * Referenced by: '<S90>/hardwareFaultFlg'
                                        */
  boolean_T enableAngleCalib_BOOL_Y0;  /* Computed Parameter: enableAngleCalib_BOOL_Y0
                                        * Referenced by: '<S90>/enableAngleCalib_BOOL'
                                        */
  boolean_T switchLaneFlg_BOOL_Y0_k;   /* Expression: false
                                        * Referenced by: '<S21>/switchLaneFlg_BOOL'
                                        */
  boolean_T diagSensorFailure_Y0;      /* Computed Parameter: diagSensorFailure_Y0
                                        * Referenced by: '<S21>/diagSensorFailure'
                                        */
  boolean_T Unit_Delay_InitialCondition_n;/* Expression: true
                                           * Referenced by: '<S21>/Unit_Delay'
                                           */
  boolean_T Unit_Delay1_InitialCondition_a;/* Expression: false
                                            * Referenced by: '<S21>/Unit_Delay1'
                                            */
  boolean_T failFlag_Y0;               /* Computed Parameter: failFlag_Y0
                                        * Referenced by: '<S18>/failFlag'
                                        */
  boolean_T ULSL_NotConnectedFlag_BOOL_Y0;/* Computed Parameter: ULSL_NotConnectedFlag_BOOL_Y0
                                           * Referenced by: '<S18>/ULSL_NotConnectedFlag_BOOL'
                                           */
  boolean_T ULSR_NotConnectedFlag_BOOL_Y0;/* Computed Parameter: ULSR_NotConnectedFlag_BOOL_Y0
                                           * Referenced by: '<S18>/ULSR_NotConnectedFlag_BOOL'
                                           */
  boolean_T redLED_BOOL_Y0;            /* Computed Parameter: redLED_BOOL_Y0
                                        * Referenced by: '<S18>/redLED_BOOL'
                                        */
  boolean_T greenLED_BOOL_Y0;          /* Computed Parameter: greenLED_BOOL_Y0
                                        * Referenced by: '<S18>/greenLED_BOOL'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S72>/Gain1'
                                        */
  uint8_T Gain1_Gain_k;                /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S81>/Gain1'
                                        */
  P_EncoderIncrement_RobotContr_T EncoderIncrement_i;/* '<S53>/EncoderIncrement' */
  P_EncoderIncrement_RobotContr_T EncoderIncrement;/* '<S52>/EncoderIncrement' */
};

/* Real-time Model Data Structure */
struct tag_RTM_RobotControl_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_RobotControl_T RobotControl_P;

/* Block signals (auto storage) */
extern B_RobotControl_T RobotControl_B;

/* Block states (auto storage) */
extern DW_RobotControl_T RobotControl_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_RobotControl_T RobotControl_PrevZCX;

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
 * Block '<S80>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S80>/Data_Type_Conversion2' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S95>/Data_Type_Conversion' : Eliminate redundant data type conversion
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
