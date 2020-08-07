/*
 * File: RobotControl.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.555
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 02:48:56 2020
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

HMC5883L Compass;

#include "../I_O_Wrapper.h"
#include "../I_O_Wrapper.c"
#else
#include "I_O_Wrapper.h"
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add1;                         /* '<S53>/Add1' */
  real_T deg;                          /* '<S63>/Product' */
  real_T Add5;                         /* '<S65>/Add5' */
  real32_T thetaError;                 /* '<S27>/Switch' */
  real32_T theta_Deg;                  /* '<S35>/Saturation' */
  real32_T theta_mDeg;                 /* '<S35>/Gain' */
  real32_T Data_Type_Conversion;       /* '<S59>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion_m;     /* '<S60>/Data_Type_Conversion' */
  real32_T rightVel1ms_mmPerSec;       /* '<S85>/Data_Type_Conversion3' */
  real32_T leftVel1ms_mmPerSec;        /* '<S76>/Data_Type_Conversion2' */
  real32_T EOL_pwm;                    /* '<S68>/EOL_TickStateMachine' */
  real32_T Data_Type_Conversion_a;     /* '<S65>/Data_Type_Conversion' */
  real32_T motorDistance;              /* '<S57>/Gain1' */
  int16_T ROB_NORTH;                   /* '<S25>/Signal Conversion' */
  int16_T ROB_SOUTH;                   /* '<S25>/Signal Conversion1' */
  int16_T ROB_EAST;                    /* '<S25>/Signal Conversion2' */
  int16_T ROB_WEST;                    /* '<S25>/Signal Conversion3' */
  int16_T rawCompassValue;             /* '<S5>/COM_A4SCA_A5SCL_Chart' */
  uint16_T headingRequest;             /* '<S132>/HighLevelMoves' */
  uint16_T leftBlocks;                 /* '<S145>/Data_Type_Conversion' */
  uint16_T rightBlocks;                /* '<S145>/Data_Type_Conversion1' */
  uint16_T ULSR_cm;                    /* '<S9>/ULSR_D8R_D7L_Chart' */
  uint16_T ULSL_cm;                    /* '<S9>/ULSL_D8R_D7L_Chart' */
  uint16_T currentHeading;             /* '<S31>/HeadingCalculation' */
  uint16_T encoderCounter;             /* '<S69>/Data_Type_Conversion' */
  uint8_T leftPosPin;                  /* '<S150>/Switch' */
  uint8_T leftNegPin;                  /* '<S150>/Switch' */
  uint8_T rightPosPin;                 /* '<S151>/Switch' */
  uint8_T rightNegPin;                 /* '<S151>/Switch' */
  uint8_T Merge;                       /* '<S26>/Merge' */
  uint8_T moveRequest;                 /* '<S26>/Switch' */
  uint8_T OutportBufferForDIAG_StatusFlg;/* '<S95>/None' */
  uint8_T DIAG_StatusFlg;              /* '<S109>/CONST_DIAG_FINISH_FLG' */
  uint8_T OutportBufferForangleCalibStatu;/* '<S104>/Angle_CalibrationUponReq' */
  uint8_T OutportBufferForangleCalibSta_a;/* '<S111>/CompassSelfDiagTestChart' */
  uint8_T OutportBufferFormoveRequest; /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T moveReq;                     /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T angleCalibStatus;            /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T encoderTstStatus;            /* '<S107>/Switch' */
  uint8_T moveReq_p;                   /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T comTstStatus;                /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T diagEnableReq;               /* '<S123>/HighLevelDiagTestControl' */
  uint8_T moveRequest_p;               /* '<S100>/GTSP_Chart' */
  uint8_T OutportBufferForswLaneCnt_uint8;/* '<S103>/ZgZgChart' */
  uint8_T moveRequest_i;               /* '<S103>/ZgZgChart' */
  uint8_T swLaneCnt_uint8;             /* '<S103>/ZgZgChart' */
  uint8_T currentRoutine;              /* '<S99>/MainStateMachine' */
  uint8_T sensorView;                  /* '<S98>/pumperHitSensorView' */
  uint8_T turnRequestFiltered;         /* '<S134>/Switch' */
  uint8_T rightMotorRequest;           /* '<S131>/Switch' */
  uint8_T leftMotorRequest;            /* '<S131>/Switch' */
  uint8_T turnRequest;                 /* '<S132>/HighLevelMoves' */
  uint8_T encoderStep;                 /* '<S135>/singleStepCalc' */
  uint8_T moveRequest_n;               /* '<S148>/stopRoutine' */
  uint8_T EOL_leftMoveReq;             /* '<S68>/EOL_TickStateMachine' */
  uint8_T EOL_rightMoveReq;            /* '<S68>/EOL_TickStateMachine' */
  boolean_T ULS_NotConnectedFlag_BOOL; /* '<S49>/Relational_Operator' */
  boolean_T ULS_NotConnectedFlag_BOOL_j;/* '<S50>/Relational_Operator' */
  boolean_T failFlag;                  /* '<S23>/Logical_Operator4' */
  boolean_T greenLED_BOOL;             /* '<S23>/Logical Operator2' */
  boolean_T redLED_BOOL;               /* '<S23>/Logical_Operator2' */
  boolean_T motorFaultFlag;            /* '<S47>/MotorMoveMonitor' */
  boolean_T motorFaultFlag_k;          /* '<S45>/MotorMoveMonitor' */
  boolean_T diagSensorFailure;         /* '<S26>/Data Type Conversion' */
  boolean_T OutportBufferForswitchLaneFlg_B;/* '<S26>/zigzagRoutine' */
  boolean_T hardwareFaultFlg;          /* '<S95>/Logical_Operator' */
  boolean_T OutportBufferForenableAngleCali;/* '<S95>/HighLevelTestRoutine' */
  boolean_T encoderDistErrorFlg_BOOL;  /* '<S117>/Logical_Operator' */
  boolean_T encoderDistErrorFlg_BOOL_m;/* '<S118>/Logical_Operator' */
  boolean_T compFaultFlag;             /* '<S113>/CompassSelfDiagTestChart' */
  boolean_T enableAngleCalib_BOOL;     /* '<S123>/HighLevelDiagTestControl' */
  boolean_T OutportBufferForGT_active; /* '<S100>/GTSP_Chart' */
  boolean_T GT_active;                 /* '<S100>/GTSP_Chart' */
  boolean_T OutportBufferForswitchLaneFlg_k;/* '<S103>/ZgZgChart' */
  boolean_T OutportBufferForzgzgActive;/* '<S103>/ZgZgChart' */
  boolean_T zgzgActive;                /* '<S103>/ZgZgChart' */
  boolean_T switchLaneFlg_BOOL;        /* '<S103>/ZgZgChart' */
  boolean_T OutportBufferFortargetReached;/* '<S27>/TargetReachedConfirmTime' */
  boolean_T targetReached;             /* '<S133>/TargetReachedConfirmTime' */
  boolean_T switchLaneStep;            /* '<S135>/singleStepCalc' */
  boolean_T hitRoutineRun;             /* '<S148>/stopRoutine' */
  boolean_T stuckHitFlg;               /* '<S148>/stopRoutine' */
  boolean_T refreshEvent;              /* '<S148>/stopRoutine' */
  boolean_T stopEvent;                 /* '<S148>/stopRoutine' */
  boolean_T counterReset;              /* '<S68>/EOL_TickStateMachine' */
  boolean_T value;                     /* '<S1>/Digital_IN_bool' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator_d;/* '<S121>/DeltaDistCalculator' */
  B_DeltaDistCalculator_RobotCo_T sf_DeltaDistCalculator;/* '<S119>/DeltaDistCalculator' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector;/* '<S87>/SpdTickDetector' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector_o;/* '<S78>/SpdTickDetector' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement_i;/* '<S58>/EncoderIncrement' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement;/* '<S57>/EncoderIncrement' */
  B_Analog_uint16_IN_RobotContr_T sf_Analog_uint16_IN1;/* '<S7>/Analog_uint16_IN1' */
  B_Analog_uint16_IN_RobotContr_T sf_Analog_uint16_IN;/* '<S7>/Analog_uint16_IN' */
} B_RobotControl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Unit_Delay_DSTATE;            /* '<S53>/Unit_Delay' */
  real_T Delay_DSTATE[5];              /* '<S65>/Delay' */
  real_T Delay1_DSTATE;                /* '<S65>/Delay1' */
  real_T initHeading;                  /* '<S103>/ZgZgChart' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S152>/FixPt Unit Delay1' */
  real32_T Unit_Delay5_DSTATE;         /* '<S26>/Unit_Delay5' */
  real32_T FixPtUnitDelay1_DSTATE_l;   /* '<S142>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_p;   /* '<S141>/FixPt Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S130>/Unit Delay' */
  real32_T Unit_Delay4_DSTATE;         /* '<S27>/Unit_Delay4' */
  real32_T Resettable_Delay_DSTATE;    /* '<S36>/Resettable_Delay' */
  real32_T Resettable_Delay1_DSTATE;   /* '<S36>/Resettable_Delay1' */
  real32_T Delay_DSTATE_a[5];          /* '<S59>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S59>/Delay1' */
  real32_T Delay_DSTATE_l[5];          /* '<S60>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S60>/Delay1' */
  real32_T MotorTransferFunction_states[2];/* '<S90>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_n;   /* '<S89>/FixPt Unit Delay1' */
  real32_T MotorTransferFunction_states_j[2];/* '<S81>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_b;   /* '<S80>/FixPt Unit Delay1' */
  real32_T Unit_Delay_DSTATE_i;        /* '<S69>/Unit_Delay' */
  real32_T tempDist;                   /* '<S47>/MotorMoveMonitor' */
  real32_T tempDist_j;                 /* '<S45>/MotorMoveMonitor' */
  real32_T tempDist_f;                 /* '<S100>/GTSP_Chart' */
  real32_T completeStep_prev;          /* '<S132>/HighLevelMoves' */
  real32_T completeStep_start;         /* '<S132>/HighLevelMoves' */
  real32_T tempDistance_mm;            /* '<S135>/singleStepCalc' */
  real32_T hitDistance;                /* '<S148>/stopRoutine' */
  int32_T sfEvent;                     /* '<S100>/GTSP_Chart' */
  int32_T sfEvent_j;                   /* '<S103>/ZgZgChart' */
  int32_T sfEvent_p;                   /* '<S132>/HighLevelMoves' */
  uint32_T refreshEventEventCounter;   /* '<S148>/stopRoutine' */
  uint32_T stopEventEventCounter;      /* '<S148>/stopRoutine' */
  int16_T Delay_DSTATE_k[4];           /* '<S147>/Delay' */
  int16_T Delay1_DSTATE_p;             /* '<S147>/Delay1' */
  int16_T Delay_DSTATE_f[4];           /* '<S146>/Delay' */
  int16_T Delay1_DSTATE_pw;            /* '<S146>/Delay1' */
  int16_T Unit_Delay_DSTATE_c;         /* '<S36>/Unit_Delay' */
  uint16_T startHeading;               /* '<S113>/CompassSelfDiagTestChart' */
  uint16_T headingRequest;             /* '<S103>/ZgZgChart' */
  uint16_T temporalCounter_i1;         /* '<S99>/MainStateMachine' */
  uint16_T temporalCounter_i2;         /* '<S148>/stopRoutine' */
  uint16_T temporalCounter_i3;         /* '<S148>/stopRoutine' */
  uint16_T temporalCounter_i1_i;       /* '<S68>/EOL_TickStateMachine' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S152>/FixPt Unit Delay2' */
  uint8_T Unit_Delay4_DSTATE_b;        /* '<S26>/Unit_Delay4' */
  uint8_T Unit_Delay1_DSTATE;          /* '<S95>/Unit_Delay1' */
  uint8_T Unit_Delay_DSTATE_j;         /* '<S95>/Unit_Delay' */
  uint8_T Unit_Delay2_DSTATE_h;        /* '<S95>/Unit_Delay2' */
  uint8_T Unit_Delay5_DSTATE_n;        /* '<S27>/Unit_Delay5' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S142>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_jc;   /* '<S141>/FixPt Unit Delay2' */
  uint8_T Unit_Delay_DSTATE_b;         /* '<S25>/Unit_Delay' */
  uint8_T Unit_Delay5_DSTATE_p;        /* '<S24>/Unit_Delay5' */
  uint8_T Unit_Delay6_DSTATE;          /* '<S24>/Unit_Delay6' */
  uint8_T Unit_Delay7_DSTATE;          /* '<S24>/Unit_Delay7' */
  uint8_T Unit_Delay8_DSTATE;          /* '<S24>/Unit_Delay8' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S89>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S80>/FixPt Unit Delay2' */
  uint8_T Unit_Delay2_DSTATE_b;        /* '<S24>/Unit_Delay2' */
  boolean_T Unit_Delay_DSTATE_h;       /* '<S26>/Unit_Delay' */
  boolean_T Unit_Delay1_DSTATE_c;      /* '<S26>/Unit_Delay1' */
  boolean_T Unit_Delay1_DSTATE_p;      /* '<S27>/Unit_Delay1' */
  boolean_T Unit_Delay2_DSTATE_o;      /* '<S27>/Unit_Delay2' */
  boolean_T Unit_Delay3_DSTATE_c;      /* '<S27>/Unit_Delay3' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S94>/Unit Delay' */
  boolean_T Unit_Delay3_DSTATE_d;      /* '<S32>/Unit_Delay3' */
  boolean_T Unit_Delay4_DSTATE_m;      /* '<S24>/Unit_Delay4' */
  boolean_T Unit_Delay_DSTATE_ja;      /* '<S67>/Unit_Delay' */
  int8_T Switch_Case_ActiveSubsystem;  /* '<S102>/Switch_Case' */
  int8_T Switch_Case_ActiveSubsystem_j;/* '<S108>/Switch_Case' */
  uint8_T is_active_c21_RobotControl;  /* '<S4>/Scheduler' */
  uint8_T is_c21_RobotControl;         /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i1_k;        /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i2_p;        /* '<S4>/Scheduler' */
  uint8_T is_active_c12_RobotControlLib;/* '<S47>/MotorMoveMonitor' */
  uint8_T is_c12_RobotControlLib;      /* '<S47>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_d;        /* '<S47>/MotorMoveMonitor' */
  uint8_T is_active_c34_RobotControlLib;/* '<S45>/MotorMoveMonitor' */
  uint8_T is_c34_RobotControlLib;      /* '<S45>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_in;       /* '<S45>/MotorMoveMonitor' */
  uint8_T is_active_c27_ROTH;          /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T is_c27_ROTH;                 /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T temporalCounter_i1_k3;       /* '<S111>/CompassSelfDiagTestChart' */
  uint8_T is_active_c31_ROTH;          /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T is_c31_ROTH;                 /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T is_turnHandler;              /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T steps;                       /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T filterToleranceCnt;          /* '<S113>/CompassSelfDiagTestChart' */
  uint8_T is_active_c26_ROTH;          /* '<S123>/HighLevelDiagTestControl' */
  uint8_T is_c26_ROTH;                 /* '<S123>/HighLevelDiagTestControl' */
  uint8_T is_SelfDiag;                 /* '<S123>/HighLevelDiagTestControl' */
  uint8_T temporalCounter_i1_c;        /* '<S123>/HighLevelDiagTestControl' */
  uint8_T is_active_c24_ROTH;          /* '<S100>/GTSP_Chart' */
  uint8_T is_c24_ROTH;                 /* '<S100>/GTSP_Chart' */
  uint8_T is_GTSP_Active;              /* '<S100>/GTSP_Chart' */
  uint8_T is_faceWest;                 /* '<S100>/GTSP_Chart' */
  uint8_T is_MostSouthLeft;            /* '<S100>/GTSP_Chart' */
  uint8_T is_facingSouth;              /* '<S100>/GTSP_Chart' */
  uint8_T is_GTSPsearch;               /* '<S100>/GTSP_Chart' */
  uint8_T counter;                     /* '<S100>/GTSP_Chart' */
  uint8_T round;                       /* '<S100>/GTSP_Chart' */
  uint8_T step1Flag;                   /* '<S100>/GTSP_Chart' */
  uint8_T is_active_c25_ROTH;          /* '<S103>/ZgZgChart' */
  uint8_T is_c25_ROTH;                 /* '<S103>/ZgZgChart' */
  uint8_T is_faceWest_h;               /* '<S103>/ZgZgChart' */
  uint8_T finishCounter;               /* '<S103>/ZgZgChart' */
  uint8_T is_active_c23_ROTH;          /* '<S99>/MainStateMachine' */
  uint8_T is_c23_ROTH;                 /* '<S99>/MainStateMachine' */
  uint8_T is_Running;                  /* '<S99>/MainStateMachine' */
  uint8_T zgzgCounter;                 /* '<S99>/MainStateMachine' */
  uint8_T encoderStep_prev;            /* '<S98>/pumperHitSensorView' */
  uint8_T encoderStep_start;           /* '<S98>/pumperHitSensorView' */
  uint8_T counter_j;                   /* '<S133>/TargetReachedConfirmTime' */
  uint8_T is_active_c37_MOVH;          /* '<S132>/HighLevelMoves' */
  uint8_T is_c37_MOVH;                 /* '<S132>/HighLevelMoves' */
  uint8_T is_forward;                  /* '<S132>/HighLevelMoves' */
  uint8_T is_TurnLeft;                 /* '<S132>/HighLevelMoves' */
  uint8_T is_UturnLeft;                /* '<S132>/HighLevelMoves' */
  uint8_T is_TurnLeft_f;               /* '<S132>/HighLevelMoves' */
  uint8_T is_Uturn;                    /* '<S132>/HighLevelMoves' */
  uint8_T is_TurnRight;                /* '<S132>/HighLevelMoves' */
  uint8_T is_TurnRight_c;              /* '<S132>/HighLevelMoves' */
  uint8_T is_UturnRight;               /* '<S132>/HighLevelMoves' */
  uint8_T is_TurnRight_b;              /* '<S132>/HighLevelMoves' */
  uint8_T uTurnCounter;                /* '<S132>/HighLevelMoves' */
  uint8_T stableCounter;               /* '<S132>/HighLevelMoves' */
  uint8_T uTurnCounter_prev;           /* '<S132>/HighLevelMoves' */
  uint8_T uTurnCounter_start;          /* '<S132>/HighLevelMoves' */
  uint8_T moveRequest_prev;            /* '<S132>/HighLevelMoves' */
  uint8_T moveRequest_start;           /* '<S132>/HighLevelMoves' */
  uint8_T is_active_c36_MOVH;          /* '<S135>/singleStepCalc' */
  uint8_T is_c36_MOVH;                 /* '<S135>/singleStepCalc' */
  uint8_T is_active_c19_RobotControlLib;/* '<S148>/stopRoutine' */
  uint8_T is_c19_RobotControlLib;      /* '<S148>/stopRoutine' */
  uint8_T is_stopRoutine;              /* '<S148>/stopRoutine' */
  uint8_T is_sideStuck;                /* '<S148>/stopRoutine' */
  uint8_T temporalCounter_i1_a;        /* '<S148>/stopRoutine' */
  uint8_T icLoad;                      /* '<S36>/Resettable_Delay' */
  uint8_T icLoad_o;                    /* '<S36>/Resettable_Delay1' */
  uint8_T is_active_c33_DSCA;          /* '<S68>/EOL_TickStateMachine' */
  uint8_T is_c33_DSCA;                 /* '<S68>/EOL_TickStateMachine' */
  boolean_T angleFinishFlg;            /* '<S111>/CompassSelfDiagTestChart' */
  boolean_T initHeading_p;             /* '<S100>/GTSP_Chart' */
  boolean_T activeFlag;                /* '<S100>/GTSP_Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<S98>/pumperHitSensorView' */
  boolean_T turnActive;                /* '<S132>/HighLevelMoves' */
  boolean_T escapeFlg;                 /* '<S148>/stopRoutine' */
  boolean_T Angle_CalibrationUponReq_MODE;/* '<S104>/Angle_CalibrationUponReq' */
  boolean_T endofLineTest_MODE;        /* '<S54>/endofLineTest' */
  boolean_T LeftMotorEncoderCounter_MODE;/* '<S67>/LeftMotorEncoderCounter' */
  boolean_T RightMotorEncoderCounter1_MODE;/* '<S67>/RightMotorEncoderCounter1' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator_d;/* '<S121>/DeltaDistCalculator' */
  DW_DeltaDistCalculator_RobotC_T sf_DeltaDistCalculator;/* '<S119>/DeltaDistCalculator' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector;/* '<S87>/SpdTickDetector' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector_o;/* '<S78>/SpdTickDetector' */
} DW_RobotControl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState GTSP_Chart_Trig_ZCE[2];   /* '<S100>/GTSP_Chart' */
  ZCSigState ZgZgChart_Trig_ZCE[2];    /* '<S103>/ZgZgChart' */
  ZCSigState HighLevelMoves_Trig_ZCE[2];/* '<S132>/HighLevelMoves' */
  ZCSigState Resettable_Delay_Reset_ZCE;/* '<S36>/Resettable_Delay' */
  ZCSigState Resettable_Delay1_Reset_ZCE;/* '<S36>/Resettable_Delay1' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement_i;/* '<S58>/EncoderIncrement' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement;/* '<S57>/EncoderIncrement' */
} PrevZCX_RobotControl_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Divide;                 /* '<S38>/Divide' */
  const real_T Divide_k;               /* '<S63>/Divide' */
  const real32_T Gain;                 /* '<S138>/Gain' */
  const boolean_T Logical_Operator;    /* '<S104>/Logical_Operator' */
  const boolean_T Logical_Operator_j;  /* '<S24>/Logical_Operator' */
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
 * Block '<S2>/Unit Delay' : Unused code path elimination
 * Block '<S2>/Unit Delay1' : Unused code path elimination
 * Block '<S2>/Unit Delay2' : Unused code path elimination
 * Block '<S2>/Unit Delay3' : Unused code path elimination
 * Block '<S2>/Unit Delay4' : Unused code path elimination
 * Block '<S35>/Scope' : Unused code path elimination
 * Block '<S70>/Add' : Unused code path elimination
 * Block '<S70>/CONST_ONE_UINT16' : Unused code path elimination
 * Block '<S70>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S70>/Relational_Operator' : Unused code path elimination
 * Block '<S70>/Switch' : Unused code path elimination
 * Block '<S70>/Unit_Delay' : Unused code path elimination
 * Block '<S24>/Scope4' : Unused code path elimination
 * Block '<S24>/Scope5' : Unused code path elimination
 * Block '<S24>/Unit_Delay1' : Unused code path elimination
 * Block '<S79>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S80>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S75>/Add4' : Unused code path elimination
 * Block '<S75>/Add5' : Unused code path elimination
 * Block '<S75>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S75>/Delay' : Unused code path elimination
 * Block '<S75>/Delay1' : Unused code path elimination
 * Block '<S75>/Gain3' : Unused code path elimination
 * Block '<S88>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S89>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S84>/Add4' : Unused code path elimination
 * Block '<S84>/Add5' : Unused code path elimination
 * Block '<S84>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S84>/Delay' : Unused code path elimination
 * Block '<S84>/Delay1' : Unused code path elimination
 * Block '<S84>/Gain3' : Unused code path elimination
 * Block '<S105>/CONST_FALSE' : Unused code path elimination
 * Block '<S106>/Data Type Conversion' : Unused code path elimination
 * Block '<S106>/Scope' : Unused code path elimination
 * Block '<S26>/Scope' : Unused code path elimination
 * Block '<S27>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S27>/ENU_TEST_INIT1' : Unused code path elimination
 * Block '<S130>/Data Type Conversion' : Unused code path elimination
 * Block '<S139>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S141>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S140>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S142>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S130>/Scope' : Unused code path elimination
 * Block '<S130>/Scope1' : Unused code path elimination
 * Block '<S130>/Scope2' : Unused code path elimination
 * Block '<S130>/Scope3' : Unused code path elimination
 * Block '<S27>/Gain4' : Unused code path elimination
 * Block '<S27>/Relational_Operator5' : Unused code path elimination
 * Block '<S27>/Scope' : Unused code path elimination
 * Block '<S27>/Scope1' : Unused code path elimination
 * Block '<S27>/Scope2' : Unused code path elimination
 * Block '<S28>/CAL_ROBO_LENG' : Unused code path elimination
 * Block '<S28>/CAL_ROBO_LENG1' : Unused code path elimination
 * Block '<S28>/Constant' : Unused code path elimination
 * Block '<S28>/Constant1' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion2' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion3' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion4' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion5' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion6' : Unused code path elimination
 * Block '<S28>/Divide' : Unused code path elimination
 * Block '<S28>/Divide1' : Unused code path elimination
 * Block '<S28>/Logical_Operator1' : Unused code path elimination
 * Block '<S28>/Relational_Operator' : Unused code path elimination
 * Block '<S28>/Relational_Operator1' : Unused code path elimination
 * Block '<S145>/Scope' : Unused code path elimination
 * Block '<S145>/Scope1' : Unused code path elimination
 * Block '<S21>/Scope1' : Unused code path elimination
 * Block '<S21>/Scope3' : Unused code path elimination
 * Block '<S21>/Scope4' : Unused code path elimination
 * Block '<S150>/CONST_noVelocity' : Unused code path elimination
 * Block '<S150>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S150>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S150>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S150>/Gain1' : Unused code path elimination
 * Block '<S151>/CONST_noVelocity' : Unused code path elimination
 * Block '<S151>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S151>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S151>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S151>/Gain1' : Unused code path elimination
 * Block '<S152>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S47>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S76>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S85>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S85>/Data_Type_Conversion2' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S100>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S29>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'RobotControl/InputHandler/EncoderAnalogIn'
 * '<S8>'   : 'RobotControl/InputHandler/Subsystem'
 * '<S9>'   : 'RobotControl/InputHandler/ULS_AnalogIn'
 * '<S10>'  : 'RobotControl/InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL_Chart'
 * '<S11>'  : 'RobotControl/InputHandler/EncoderAnalogIn/Analog_uint16_IN'
 * '<S12>'  : 'RobotControl/InputHandler/EncoderAnalogIn/Analog_uint16_IN1'
 * '<S13>'  : 'RobotControl/InputHandler/ULS_AnalogIn/ULSL_D8R_D7L_Chart'
 * '<S14>'  : 'RobotControl/InputHandler/ULS_AnalogIn/ULSR_D8R_D7L_Chart'
 * '<S15>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM'
 * '<S16>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM1'
 * '<S17>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM2'
 * '<S18>'  : 'RobotControl/OutputHandler/Digital_OUT_PWM3'
 * '<S19>'  : 'RobotControl/OutputHandler/Digital_OUT_bool'
 * '<S20>'  : 'RobotControl/OutputHandler/Digital_OUT_bool1'
 * '<S21>'  : 'RobotControl/RobotControl/RobotControlLib'
 * '<S22>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler'
 * '<S23>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont'
 * '<S24>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA'
 * '<S25>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler'
 * '<S26>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines'
 * '<S27>'  : 'RobotControl/RobotControl/RobotControlLib/MovementHandler'
 * '<S28>'  : 'RobotControl/RobotControl/RobotControlLib/ScanHandler'
 * '<S29>'  : 'RobotControl/RobotControl/RobotControlLib/StopRoutine'
 * '<S30>'  : 'RobotControl/RobotControl/RobotControlLib/motorHandler'
 * '<S31>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator'
 * '<S32>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter'
 * '<S33>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation'
 * '<S34>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/HeadingCalculator/HeadingCalculation1'
 * '<S35>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter'
 * '<S36>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter'
 * '<S37>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/movingAverage_1ms_to_5ms2'
 * '<S38>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/FromDegreeToRad2'
 * '<S39>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/OMEGA_Calc'
 * '<S40>'  : 'RobotControl/RobotControl/RobotControlLib/Compass_Handler/thetaFilter/thetaFilter/KalmanFilter/thetaOverFlowFilter_Deg'
 * '<S41>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper'
 * '<S42>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected'
 * '<S43>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor'
 * '<S44>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1'
 * '<S45>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor'
 * '<S46>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor'
 * '<S47>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor'
 * '<S48>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor'
 * '<S49>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL'
 * '<S50>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL1'
 * '<S51>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator'
 * '<S52>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderAdaptation'
 * '<S53>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation'
 * '<S54>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest'
 * '<S55>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator'
 * '<S56>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator'
 * '<S57>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor'
 * '<S58>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor'
 * '<S59>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms'
 * '<S60>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms1'
 * '<S61>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor/EncoderIncrement'
 * '<S62>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor/EncoderIncrement'
 * '<S63>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/FromDegreeToRad2'
 * '<S64>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/OMEGA_Calc'
 * '<S65>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/movingAverage_1ms_to_5ms'
 * '<S66>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/thetaOverFlowFilter_Rad'
 * '<S67>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest'
 * '<S68>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine'
 * '<S69>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/LeftMotorEncoderCounter'
 * '<S70>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/RightMotorEncoderCounter1'
 * '<S71>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/endofLineTest/EOL_TickStateMachine/EOL_TickStateMachine'
 * '<S72>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator'
 * '<S73>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator'
 * '<S74>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor'
 * '<S75>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S76>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter'
 * '<S77>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator'
 * '<S78>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector'
 * '<S79>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S80>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S81>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator/motorModelTfDis'
 * '<S82>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector'
 * '<S83>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor'
 * '<S84>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S85>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter'
 * '<S86>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator'
 * '<S87>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector'
 * '<S88>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S89>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S90>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator/motorModelTfDis'
 * '<S91>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector/SpdTickDetector'
 * '<S92>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/LeftMotor'
 * '<S93>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/RightMotor'
 * '<S94>'  : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler/Set_Reset'
 * '<S95>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine'
 * '<S96>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DistanceCalculator'
 * '<S97>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/End'
 * '<S98>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation'
 * '<S99>'  : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl'
 * '<S100>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine'
 * '<S101>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/ULS_FaultHandler'
 * '<S102>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/routineEnableSwitch'
 * '<S103>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine'
 * '<S104>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration'
 * '<S105>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Bluetooth'
 * '<S106>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest'
 * '<S107>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest'
 * '<S108>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine'
 * '<S109>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/None'
 * '<S110>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/QuaterTurnTargetDist'
 * '<S111>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq'
 * '<S112>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart'
 * '<S113>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem'
 * '<S114>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading'
 * '<S115>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart'
 * '<S116>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler'
 * '<S117>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest'
 * '<S118>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest'
 * '<S119>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator'
 * '<S120>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S121>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator'
 * '<S122>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/EncoderTest/RightEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S123>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl'
 * '<S124>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl'
 * '<S125>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView'
 * '<S126>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine'
 * '<S127>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart'
 * '<S128>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart'
 * '<S129>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc'
 * '<S130>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc'
 * '<S131>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MaxSpeedsOnly'
 * '<S132>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine'
 * '<S133>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime'
 * '<S134>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TurnHandler'
 * '<S135>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler'
 * '<S136>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc'
 * '<S137>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID'
 * '<S138>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/rateLimiter'
 * '<S139>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable'
 * '<S140>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1'
 * '<S141>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable/Unit Delay Resettable'
 * '<S142>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S143>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves'
 * '<S144>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime'
 * '<S145>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler'
 * '<S146>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff1'
 * '<S147>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff4'
 * '<S148>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine'
 * '<S149>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine'
 * '<S150>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/LeftMotorPin'
 * '<S151>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/RightMotorPin'
 * '<S152>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/Unit_Delay_Resettable'
 * '<S153>' : 'RobotControl/Scheduler/Scheduler'
 */
#endif                                 /* RTW_HEADER_RobotControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
