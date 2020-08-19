/*
 * File: RobotControl.h
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.581
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 17 10:27:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RobotControl_h_
#define RTW_HEADER_RobotControl_h_
#include <math.h>
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
#include "thetaFilter.h"

/* Includes for objects with custom storage classes. */
#include "Params.h"
#include "Constant.h"
#include "Enums.h"
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
  real_T Add1;                         /* '<S56>/Add1' */
  real_T deg;                          /* '<S66>/Product' */
  real_T Add5;                         /* '<S68>/Add5' */
  real32_T thetaError;                 /* '<S28>/Switch' */
  real32_T theta_Deg;                  /* '<S36>/Saturation' */
  real32_T theta_mDeg;                 /* '<S36>/Gain' */
  real32_T Data_Type_Conversion;       /* '<S62>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion_m;     /* '<S63>/Data_Type_Conversion' */
  real32_T rightVel1ms_mmPerSec;       /* '<S95>/Data_Type_Conversion3' */
  real32_T leftVel1ms_mmPerSec;        /* '<S86>/Data_Type_Conversion2' */

#if motorsHandleEOL_Variant

  real32_T VariantMergeForOutportright_EOL;

#define B_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  real32_T VariantMergeForOutportleft_EOL_;

#define B_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

  real32_T Data_Type_Conversion_a;     /* '<S68>/Data_Type_Conversion' */
  real32_T motorDistance;              /* '<S60>/Gain1' */
  real32_T Abs_g;                      /* '<S31>/Abs' */
  real32_T Switch_c;                   /* '<S31>/Switch' */
  real32_T VariantMerge_For_Variant_So;
  real32_T VariantMerge_For_Variant__i;
  real32_T Saturation1;                /* '<S31>/Saturation1' */
  real32_T Add_a5;                     /* '<S31>/Add' */
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
  uint16_T VariantMergeForOutportangleCali;
  uint16_T VariantMergeForOutportangleCa_g;
  uint16_T VariantMergeForOutportangleCa_a;
  uint16_T VariantMergeForOutportangleC_a1;
  uint16_T headingRequest;             /* '<S145>/HighLevelMoves' */
  uint16_T leftBlocks;                 /* '<S158>/Data_Type_Conversion' */
  uint16_T rightBlocks;                /* '<S158>/Data_Type_Conversion1' */
  uint16_T ULSR_cm;                    /* '<S9>/ULSR_D8R_D7L_Chart' */
  uint16_T ULSL_cm;                    /* '<S9>/ULSL_D8R_D7L_Chart' */
  uint16_T currentHeading;             /* '<S32>/HeadingCalculation' */
  uint16_T rightEncoderTicks_uint16;   /* '<S8>/rightEncoderTicks_uint16_chart' */
  uint16_T leftEncoderTicks_uint16;    /* '<S8>/leftEncoderTicks_uint16_chart' */
  uint8_T UnitDelay4;                  /* '<S2>/Unit Delay4' */
  uint8_T VariantMerge_For_Variant_Source;
  uint8_T leftPosPin;                  /* '<S163>/Switch' */
  uint8_T leftNegPin;                  /* '<S163>/Switch' */
  uint8_T VariantMerge_For_Variant_Sour_b;
  uint8_T rightPosPin;                 /* '<S164>/Switch' */
  uint8_T rightNegPin;                 /* '<S164>/Switch' */
  uint8_T Merge;                       /* '<S27>/Merge' */
  uint8_T moveRequest;                 /* '<S27>/Switch' */
  uint8_T VariantMergeForOutportDIAG_Stat;
  uint8_T VariantMergeForOutportangleCa_h;
  uint8_T VariantMergeForOutportcomTstSta;
  uint8_T moveRequest_l;               /* '<S110>/GTSP_Chart' */
  uint8_T OutportBufferForswLaneCnt_uint8;/* '<S113>/ZgZgChart' */
  uint8_T moveRequest_m;               /* '<S113>/ZgZgChart' */
  uint8_T swLaneCnt_uint8;             /* '<S113>/ZgZgChart' */
  uint8_T currentRoutine;              /* '<S109>/MainStateMachine' */
  uint8_T sensorView;                  /* '<S108>/pumperHitSensorView' */
  uint8_T turnRequestFiltered;         /* '<S147>/Switch' */
  uint8_T turnRequest;                 /* '<S145>/HighLevelMoves' */
  uint8_T encoderStep;                 /* '<S148>/singleStepCalc' */
  uint8_T moveRequest_i;               /* '<S161>/stopRoutine' */
  uint8_T Product;                     /* '<S163>/Product' */
  boolean_T ULSL_NotConnectedFlag_BOOL_h;/* '<S52>/Relational_Operator' */
  boolean_T ULSR_NotConnectedFlag_BOOL_a;/* '<S53>/Relational_Operator' */
  boolean_T failFlag;                  /* '<S42>/Logical_Operator4' */
  boolean_T greenLED_BOOL;             /* '<S42>/Logical Operator2' */
  boolean_T redLED_BOOL;               /* '<S42>/Logical_Operator2' */
  boolean_T rightMotorFaultFlag_k;     /* '<S50>/MotorMoveMonitor' */
  boolean_T leftMotorFaultFlag_j;      /* '<S48>/MotorMoveMonitor' */
  boolean_T NVM_AngleStoreFlg;         /* '<S7>/EEPROM_IO_Handler_Chart' */
  boolean_T OutportBufferForcompFaultFlag;/* '<S27>/DIAG_Routine' */
  boolean_T OutportBufferForswitchLaneFlg_B;/* '<S27>/zigzagRoutine' */
  boolean_T VariantMergeForOutportcompFault;
  boolean_T VariantMergeForOutportenableAng;
  boolean_T VariantMergeForOutportleftEncod;
  boolean_T VariantMergeForOutportrightEnco;
  boolean_T OutportBufferForGT_active; /* '<S110>/GTSP_Chart' */
  boolean_T GT_active;                 /* '<S110>/GTSP_Chart' */
  boolean_T OutportBufferForswitchLaneFlg_k;/* '<S113>/ZgZgChart' */
  boolean_T OutportBufferForzgzgActive;/* '<S113>/ZgZgChart' */
  boolean_T zgzgActive;                /* '<S113>/ZgZgChart' */
  boolean_T switchLaneFlg_BOOL;        /* '<S113>/ZgZgChart' */
  boolean_T OutportBufferFortargetReached;/* '<S28>/TargetReachedConfirmTime' */
  boolean_T targetReached;             /* '<S146>/TargetReachedConfirmTime' */
  boolean_T switchLaneStep;            /* '<S148>/singleStepCalc' */
  boolean_T hitRoutineRun;             /* '<S161>/stopRoutine' */
  boolean_T stuckHitFlg_c;             /* '<S161>/stopRoutine' */
  boolean_T refreshEvent;              /* '<S161>/stopRoutine' */
  boolean_T stopEvent;                 /* '<S161>/stopRoutine' */
  boolean_T pumperHit_BOOL;            /* '<S1>/Digital_IN_bool' */
  boolean_T Relational_Operator_b;     /* '<S164>/Relational_Operator' */
  boolean_T Logical_Operator_o;        /* '<S31>/Logical_Operator' */

#if MotorsEOL_DisabledVariant

  B_Diag_Routine_Enabled_RobotC_T Diag_Routine_Enabled;/* '<S114>/Diag_Routine_Enabled' */

#define B_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* MotorsEOL_DisabledVariant */

  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector;/* '<S97>/SpdTickDetector' */
  B_SpdTickDetector_RobotContro_T sf_SpdTickDetector_o;/* '<S88>/SpdTickDetector' */

#if rightMotorEOL_variant
#if motorsHandleEOL_Variant

  B_RightEndofLineTest_RobotCon_T RightEndofLineTest;/* '<S71>/RightEndofLineTest' */

#define B_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */
#endif                                 /* rightMotorEOL_variant */

#if leftMotorEOL_variant
#if motorsHandleEOL_Variant

  B_LeftEndofLineTest_RobotCont_T LeftEndofLineTest_g;/* '<S70>/LeftEndofLineTest' */

#define B_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */
#endif                                 /* leftMotorEOL_variant */

  B_EncoderIncrement_RobotContr_T EncoderIncrement_i;/* '<S61>/EncoderIncrement' */
  B_EncoderIncrement_RobotContr_T EncoderIncrement;/* '<S60>/EncoderIncrement' */
} B_RobotControl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Unit_Delay_DSTATE;            /* '<S56>/Unit_Delay' */
  real_T Delay_DSTATE[5];              /* '<S68>/Delay' */
  real_T Delay1_DSTATE;                /* '<S68>/Delay1' */
  real_T initHeading;                  /* '<S113>/ZgZgChart' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S165>/FixPt Unit Delay1' */
  real32_T Unit_Delay5_DSTATE;         /* '<S27>/Unit_Delay5' */
  real32_T FixPtUnitDelay1_DSTATE_l;   /* '<S155>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_p;   /* '<S154>/FixPt Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S143>/Unit Delay' */
  real32_T Unit_Delay4_DSTATE;         /* '<S28>/Unit_Delay4' */
  real32_T Resettable_Delay_DSTATE;    /* '<S37>/Resettable_Delay' */
  real32_T Resettable_Delay1_DSTATE;   /* '<S37>/Resettable_Delay1' */
  real32_T Delay_DSTATE_a[5];          /* '<S62>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S62>/Delay1' */
  real32_T Delay_DSTATE_l[5];          /* '<S63>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S63>/Delay1' */
  real32_T MotorTransferFunction_states[2];/* '<S100>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_n;   /* '<S99>/FixPt Unit Delay1' */
  real32_T MotorTransferFunction_states_j[2];/* '<S91>/MotorTransferFunction' */
  real32_T FixPtUnitDelay1_DSTATE_b;   /* '<S90>/FixPt Unit Delay1' */
  real32_T tempDist;                   /* '<S50>/MotorMoveMonitor' */
  real32_T tempDist_f;                 /* '<S48>/MotorMoveMonitor' */
  real32_T tempDist_l;                 /* '<S110>/GTSP_Chart' */
  real32_T completeStep_prev;          /* '<S145>/HighLevelMoves' */
  real32_T completeStep_start;         /* '<S145>/HighLevelMoves' */
  real32_T tempDistance_mm;            /* '<S148>/singleStepCalc' */
  real32_T hitDistance;                /* '<S161>/stopRoutine' */
  int32_T sfEvent;                     /* '<S110>/GTSP_Chart' */
  int32_T sfEvent_l;                   /* '<S113>/ZgZgChart' */
  int32_T sfEvent_h;                   /* '<S145>/HighLevelMoves' */
  uint32_T refreshEventEventCounter;   /* '<S161>/stopRoutine' */
  uint32_T stopEventEventCounter;      /* '<S161>/stopRoutine' */
  int16_T Delay_DSTATE_k[4];           /* '<S160>/Delay' */
  int16_T Delay1_DSTATE_p;             /* '<S160>/Delay1' */
  int16_T Delay_DSTATE_f[4];           /* '<S159>/Delay' */
  int16_T Delay1_DSTATE_pw;            /* '<S159>/Delay1' */
  int16_T Unit_Delay_DSTATE_c;         /* '<S37>/Unit_Delay' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  uint16_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  uint16_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  uint16_T headingRequest;             /* '<S113>/ZgZgChart' */
  uint16_T temporalCounter_i1;         /* '<S109>/MainStateMachine' */
  uint16_T temporalCounter_i2;         /* '<S161>/stopRoutine' */
  uint8_T UnitDelay4_DSTATE;           /* '<S2>/Unit Delay4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S165>/FixPt Unit Delay2' */
  uint8_T Unit_Delay4_DSTATE_b;        /* '<S27>/Unit_Delay4' */
  uint8_T Unit_Delay5_DSTATE_n;        /* '<S28>/Unit_Delay5' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S155>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_jc;   /* '<S154>/FixPt Unit Delay2' */
  uint8_T Unit_Delay_DSTATE_b;         /* '<S26>/Unit_Delay' */
  uint8_T Unit_Delay5_DSTATE_p;        /* '<S25>/Unit_Delay5' */
  uint8_T Unit_Delay6_DSTATE;          /* '<S25>/Unit_Delay6' */
  uint8_T Unit_Delay7_DSTATE;          /* '<S25>/Unit_Delay7' */
  uint8_T Unit_Delay8_DSTATE;          /* '<S25>/Unit_Delay8' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S99>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S90>/FixPt Unit Delay2' */
  uint8_T Unit_Delay2_DSTATE_b;        /* '<S25>/Unit_Delay2' */
  boolean_T Unit_Delay_DSTATE_h;       /* '<S27>/Unit_Delay' */
  boolean_T Unit_Delay1_DSTATE;        /* '<S27>/Unit_Delay1' */
  boolean_T Unit_Delay1_DSTATE_p;      /* '<S28>/Unit_Delay1' */
  boolean_T Unit_Delay2_DSTATE_o;      /* '<S28>/Unit_Delay2' */
  boolean_T Unit_Delay3_DSTATE_c;      /* '<S28>/Unit_Delay3' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S104>/Unit Delay' */
  boolean_T Unit_Delay3_DSTATE_d;      /* '<S33>/Unit_Delay3' */

#if motorsHandleEOL_Variant

  boolean_T Unit_Delay4_DSTATE_m;      /* '<S25>/Unit_Delay4' */

#define DW_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

#if motorsHandleEOL_Variant

  boolean_T Unit_Delay1_DSTATE_c;      /* '<S25>/Unit_Delay1' */

#define DW_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */

  int8_T Switch_Case_ActiveSubsystem;  /* '<S112>/Switch_Case' */
  uint8_T is_active_c21_RobotControl;  /* '<S4>/Scheduler' */
  uint8_T is_c21_RobotControl;         /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i1_k;        /* '<S4>/Scheduler' */
  uint8_T temporalCounter_i2_p;        /* '<S4>/Scheduler' */
  uint8_T is_active_c14_RobotControl;  /* '<S50>/MotorMoveMonitor' */
  uint8_T is_c14_RobotControl;         /* '<S50>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_i;        /* '<S50>/MotorMoveMonitor' */
  uint8_T is_active_c34_RobotControl;  /* '<S48>/MotorMoveMonitor' */
  uint8_T is_c34_RobotControl;         /* '<S48>/MotorMoveMonitor' */
  uint8_T temporalCounter_i1_g;        /* '<S48>/MotorMoveMonitor' */
  uint8_T is_active_c13_RobotControl;  /* '<S7>/EEPROM_IO_Handler_Chart' */
  uint8_T is_c13_RobotControl;         /* '<S7>/EEPROM_IO_Handler_Chart' */
  uint8_T is_active_c32_RobotControl;  /* '<S110>/GTSP_Chart' */
  uint8_T is_c32_RobotControl;         /* '<S110>/GTSP_Chart' */
  uint8_T is_GTSP_Active;              /* '<S110>/GTSP_Chart' */
  uint8_T is_faceWest;                 /* '<S110>/GTSP_Chart' */
  uint8_T is_MostSouthLeft;            /* '<S110>/GTSP_Chart' */
  uint8_T is_facingSouth;              /* '<S110>/GTSP_Chart' */
  uint8_T is_GTSPsearch;               /* '<S110>/GTSP_Chart' */
  uint8_T counter;                     /* '<S110>/GTSP_Chart' */
  uint8_T round;                       /* '<S110>/GTSP_Chart' */
  uint8_T step1Flag;                   /* '<S110>/GTSP_Chart' */
  uint8_T is_active_c33_RobotControl;  /* '<S113>/ZgZgChart' */
  uint8_T is_c33_RobotControl;         /* '<S113>/ZgZgChart' */
  uint8_T is_faceWest_f;               /* '<S113>/ZgZgChart' */
  uint8_T finishCounter;               /* '<S113>/ZgZgChart' */
  uint8_T is_active_c25_RobotControl;  /* '<S109>/MainStateMachine' */
  uint8_T is_c25_RobotControl;         /* '<S109>/MainStateMachine' */
  uint8_T is_Running;                  /* '<S109>/MainStateMachine' */
  uint8_T zgzgCounter;                 /* '<S109>/MainStateMachine' */
  uint8_T encoderStep_prev;            /* '<S108>/pumperHitSensorView' */
  uint8_T encoderStep_start;           /* '<S108>/pumperHitSensorView' */
  uint8_T counter_m;                   /* '<S146>/TargetReachedConfirmTime' */
  uint8_T is_active_c37_RobotControl;  /* '<S145>/HighLevelMoves' */
  uint8_T is_c37_RobotControl;         /* '<S145>/HighLevelMoves' */
  uint8_T is_forward;                  /* '<S145>/HighLevelMoves' */
  uint8_T is_TurnLeft;                 /* '<S145>/HighLevelMoves' */
  uint8_T is_UturnLeft;                /* '<S145>/HighLevelMoves' */
  uint8_T is_TurnLeft_c;               /* '<S145>/HighLevelMoves' */
  uint8_T is_Uturn;                    /* '<S145>/HighLevelMoves' */
  uint8_T is_TurnRight;                /* '<S145>/HighLevelMoves' */
  uint8_T is_TurnRight_h;              /* '<S145>/HighLevelMoves' */
  uint8_T is_UturnRight;               /* '<S145>/HighLevelMoves' */
  uint8_T is_TurnRight_i;              /* '<S145>/HighLevelMoves' */
  uint8_T uTurnCounter;                /* '<S145>/HighLevelMoves' */
  uint8_T stableCounter;               /* '<S145>/HighLevelMoves' */
  uint8_T uTurnCounter_prev;           /* '<S145>/HighLevelMoves' */
  uint8_T uTurnCounter_start;          /* '<S145>/HighLevelMoves' */
  uint8_T moveRequest_prev;            /* '<S145>/HighLevelMoves' */
  uint8_T moveRequest_start;           /* '<S145>/HighLevelMoves' */
  uint8_T is_active_c36_RobotControl;  /* '<S148>/singleStepCalc' */
  uint8_T is_c36_RobotControl;         /* '<S148>/singleStepCalc' */
  uint8_T is_active_c19_RobotControl;  /* '<S161>/stopRoutine' */
  uint8_T is_c19_RobotControl;         /* '<S161>/stopRoutine' */
  uint8_T is_stopRoutine;              /* '<S161>/stopRoutine' */
  uint8_T is_sideStuck;                /* '<S161>/stopRoutine' */
  uint8_T temporalCounter_i1_j;        /* '<S161>/stopRoutine' */
  uint8_T temporalCounter_i3;          /* '<S161>/stopRoutine' */
  uint8_T icLoad;                      /* '<S37>/Resettable_Delay' */
  uint8_T icLoad_o;                    /* '<S37>/Resettable_Delay1' */
  boolean_T initHeading_i;             /* '<S110>/GTSP_Chart' */
  boolean_T activeFlag;                /* '<S110>/GTSP_Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<S108>/pumperHitSensorView' */
  boolean_T turnActive;                /* '<S145>/HighLevelMoves' */
  boolean_T escapeFlg;                 /* '<S161>/stopRoutine' */

#if MotorsEOL_DisabledVariant

  DW_Diag_Routine_Enabled_Robot_T Diag_Routine_Enabled;/* '<S114>/Diag_Routine_Enabled' */

#define DW_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* MotorsEOL_DisabledVariant */

  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector;/* '<S97>/SpdTickDetector' */
  DW_SpdTickDetector_RobotContr_T sf_SpdTickDetector_o;/* '<S88>/SpdTickDetector' */

#if rightMotorEOL_variant
#if motorsHandleEOL_Variant

  DW_RightEndofLineTest_RobotCo_T RightEndofLineTest;/* '<S71>/RightEndofLineTest' */

#define DW_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */
#endif                                 /* rightMotorEOL_variant */

#if leftMotorEOL_variant
#if motorsHandleEOL_Variant

  DW_LeftEndofLineTest_RobotCon_T LeftEndofLineTest_g;/* '<S70>/LeftEndofLineTest' */

#define DW_ROBOTCONTROL_T_VARIANT_EXISTS
#endif                                 /* motorsHandleEOL_Variant */
#endif                                 /* leftMotorEOL_variant */

} DW_RobotControl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState GTSP_Chart_Trig_ZCE[2];   /* '<S110>/GTSP_Chart' */
  ZCSigState ZgZgChart_Trig_ZCE[2];    /* '<S113>/ZgZgChart' */
  ZCSigState HighLevelMoves_Trig_ZCE[2];/* '<S145>/HighLevelMoves' */
  ZCSigState Resettable_Delay_Reset_ZCE;/* '<S37>/Resettable_Delay' */
  ZCSigState Resettable_Delay1_Reset_ZCE;/* '<S37>/Resettable_Delay1' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement_i;/* '<S61>/EncoderIncrement' */
  ZCE_EncoderIncrement_RobotCon_T EncoderIncrement;/* '<S60>/EncoderIncrement' */
} PrevZCX_RobotControl_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Divide;                 /* '<S39>/Divide' */
  const real_T Divide_k;               /* '<S66>/Divide' */
  const real32_T Gain;                 /* '<S151>/Gain' */
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

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
#if debuggingFlag_variant

extern boolean_T leftEncoderDistErrorFlg;/* Simulink.Signal object 'leftEncoderDistErrorFlg' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T rightEncoderDistErrorFlg;/* Simulink.Signal object 'rightEncoderDistErrorFlg' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T ULSR_NotConnectedFlag_BOOL;/* Simulink.Signal object 'ULSR_NotConnectedFlag_BOOL' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T ULSL_NotConnectedFlag_BOOL;/* Simulink.Signal object 'ULSL_NotConnectedFlag_BOOL' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T rightMotorFaultFlag;  /* Simulink.Signal object 'rightMotorFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T compFaultFlag;        /* Simulink.Signal object 'compFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T leftMotorFaultFlag;   /* Simulink.Signal object 'leftMotorFaultFlag' */

#endif                                 /* debuggingFlag_variant */

#if debuggingFlag_variant

extern boolean_T stuckHitFlg;          /* Simulink.Signal object 'stuckHitFlg' */

#endif                                 /* debuggingFlag_variant */

/* Model entry point functions */
extern void RobotControl_initialize(void);
extern void RobotControl_step(void);

/* Real-time Model object */
extern RT_MODEL_RobotControl_T *const RobotControl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S36>/Scope' : Unused code path elimination
 * Block '<S25>/Scope' : Unused code path elimination
 * Block '<S25>/Scope4' : Unused code path elimination
 * Block '<S25>/Scope5' : Unused code path elimination
 * Block '<S89>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S90>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S85>/Add4' : Unused code path elimination
 * Block '<S85>/Add5' : Unused code path elimination
 * Block '<S85>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S85>/Delay' : Unused code path elimination
 * Block '<S85>/Delay1' : Unused code path elimination
 * Block '<S85>/Gain3' : Unused code path elimination
 * Block '<S98>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S99>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S94>/Add4' : Unused code path elimination
 * Block '<S94>/Add5' : Unused code path elimination
 * Block '<S94>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S94>/Delay' : Unused code path elimination
 * Block '<S94>/Delay1' : Unused code path elimination
 * Block '<S94>/Gain3' : Unused code path elimination
 * Block '<S118>/CONST_FALSE' : Unused code path elimination
 * Block '<S119>/Data Type Conversion' : Unused code path elimination
 * Block '<S119>/Scope' : Unused code path elimination
 * Block '<S27>/Scope' : Unused code path elimination
 * Block '<S28>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S28>/ENU_TEST_INIT1' : Unused code path elimination
 * Block '<S143>/Data Type Conversion' : Unused code path elimination
 * Block '<S152>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S154>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S153>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S155>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S143>/Scope' : Unused code path elimination
 * Block '<S143>/Scope1' : Unused code path elimination
 * Block '<S143>/Scope2' : Unused code path elimination
 * Block '<S143>/Scope3' : Unused code path elimination
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
 * Block '<S158>/Scope' : Unused code path elimination
 * Block '<S158>/Scope1' : Unused code path elimination
 * Block '<S22>/Scope1' : Unused code path elimination
 * Block '<S22>/Scope3' : Unused code path elimination
 * Block '<S22>/Scope4' : Unused code path elimination
 * Block '<S163>/CONST_noVelocity' : Unused code path elimination
 * Block '<S163>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S163>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S163>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S163>/Gain1' : Unused code path elimination
 * Block '<S164>/CONST_noVelocity' : Unused code path elimination
 * Block '<S164>/CONST_noVelocity1' : Unused code path elimination
 * Block '<S164>/Data_Type_Conversion' : Unused code path elimination
 * Block '<S164>/Data_Type_Conversion1' : Unused code path elimination
 * Block '<S164>/Gain1' : Unused code path elimination
 * Block '<S165>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S50>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S86>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S95>/Data_Type_Conversion1' : Eliminate redundant data type conversion
 * Block '<S95>/Data_Type_Conversion2' : Eliminate redundant data type conversion
 * Block '<S126>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S110>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Data_Type_Conversion' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<S42>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/LED_Handler'
 * '<S43>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/MonitorDiag'
 * '<S44>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper'
 * '<S45>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected'
 * '<S46>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor'
 * '<S47>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1'
 * '<S48>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor'
 * '<S49>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor/MotorMoveMonitor/MotorMoveMonitor'
 * '<S50>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor'
 * '<S51>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/Pumper/MotorFaultMonitor1/MotorMoveMonitor/MotorMoveMonitor'
 * '<S52>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL'
 * '<S53>'  : 'RobotControl/RobotControl/RobotControlLib/DIAG_Cont/ULS_NotConnected/ULSL1'
 * '<S54>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator'
 * '<S55>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderAdaptation'
 * '<S56>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation'
 * '<S57>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest'
 * '<S58>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator'
 * '<S59>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator'
 * '<S60>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor'
 * '<S61>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor'
 * '<S62>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms'
 * '<S63>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/movingAverage_1ms_to_5ms1'
 * '<S64>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/LeftMotor/EncoderIncrement'
 * '<S65>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/DistanceCalculator/RightMotor/EncoderIncrement'
 * '<S66>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/FromDegreeToRad2'
 * '<S67>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/OMEGA_Calc'
 * '<S68>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/movingAverage_1ms_to_5ms'
 * '<S69>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/EncoderThetaCalculation/thetaOverFlowFilter_Rad'
 * '<S70>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest'
 * '<S71>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1'
 * '<S72>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest'
 * '<S73>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest_disabled'
 * '<S74>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine'
 * '<S75>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/LeftMotorEncoderCounter'
 * '<S76>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/LeftEndofLineTest/LeftEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine'
 * '<S77>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest'
 * '<S78>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest_disabled'
 * '<S79>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine'
 * '<S80>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/RightMotorEncoderCounter1'
 * '<S81>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/Encoder_endofLineTest/rightEndofLineTest1/RightEndofLineTest/EOL_TickStateMachine/EOL_TickStateMachine'
 * '<S82>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator'
 * '<S83>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator'
 * '<S84>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor'
 * '<S85>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S86>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter'
 * '<S87>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator'
 * '<S88>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector'
 * '<S89>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S90>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S91>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/MotorModelEstimator/motorModelTfDis'
 * '<S92>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/LeftVelocityCalculator/LeftMotor/SpdTickDetector/SpdTickDetector'
 * '<S93>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor'
 * '<S94>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/movingAverage_1ms_to_5ms'
 * '<S95>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter'
 * '<S96>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator'
 * '<S97>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector'
 * '<S98>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1'
 * '<S99>'  : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/KalmanFilter/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S100>' : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/MotorModelEstimator/motorModelTfDis'
 * '<S101>' : 'RobotControl/RobotControl/RobotControlLib/DSCA/VelocityCalculator/RightVelocityCalculator/RightMotor/SpdTickDetector/SpdTickDetector'
 * '<S102>' : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/LeftMotor'
 * '<S103>' : 'RobotControl/RobotControl/RobotControlLib/DSCA/directionFeedbackCalculator/RightMotor'
 * '<S104>' : 'RobotControl/RobotControl/RobotControlLib/HeadingsDirectionHandler/Set_Reset'
 * '<S105>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine'
 * '<S106>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DistanceCalculator'
 * '<S107>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/End'
 * '<S108>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation'
 * '<S109>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl'
 * '<S110>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine'
 * '<S111>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/ULS_FaultHandler'
 * '<S112>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/routineEnableSwitch'
 * '<S113>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine'
 * '<S114>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant'
 * '<S115>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Disabled'
 * '<S116>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled'
 * '<S117>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration'
 * '<S118>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Bluetooth'
 * '<S119>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest'
 * '<S120>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest'
 * '<S121>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine'
 * '<S122>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/None'
 * '<S123>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/QuaterTurnTargetDist'
 * '<S124>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq'
 * '<S125>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart'
 * '<S126>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem'
 * '<S127>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/encoderHeading'
 * '<S128>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart'
 * '<S129>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/encoderHeading/EncoderHeadingHandler'
 * '<S130>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest'
 * '<S131>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/RightEncoderTest'
 * '<S132>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator'
 * '<S133>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S134>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/RightEncoderTest/DeltaDistCalculator'
 * '<S135>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/RightEncoderTest/DeltaDistCalculator/DeltaDistCalculator'
 * '<S136>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl'
 * '<S137>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl'
 * '<S138>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView'
 * '<S139>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine'
 * '<S140>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart'
 * '<S141>' : 'RobotControl/RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart'
 * '<S142>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc'
 * '<S143>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc'
 * '<S144>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MaxSpeedsOnly'
 * '<S145>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine'
 * '<S146>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime'
 * '<S147>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TurnHandler'
 * '<S148>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler'
 * '<S149>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc'
 * '<S150>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID'
 * '<S151>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/rateLimiter'
 * '<S152>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable'
 * '<S153>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1'
 * '<S154>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable/Unit Delay Resettable'
 * '<S155>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/ErrorCalc/PID/Unit_Delay_Enabled_Resettable1/Unit Delay Resettable'
 * '<S156>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves'
 * '<S157>' : 'RobotControl/RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime'
 * '<S158>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler'
 * '<S159>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff1'
 * '<S160>' : 'RobotControl/RobotControl/RobotControlLib/ScanHandler/ULS_Handler/movingAverage_buff4'
 * '<S161>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine'
 * '<S162>' : 'RobotControl/RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine'
 * '<S163>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/LeftMotorPin'
 * '<S164>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/RightMotorPin'
 * '<S165>' : 'RobotControl/RobotControl/RobotControlLib/motorHandler/Unit_Delay_Resettable'
 * '<S166>' : 'RobotControl/Scheduler/Scheduler'
 */
#endif                                 /* RTW_HEADER_RobotControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
