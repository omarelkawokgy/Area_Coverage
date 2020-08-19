/*
 * File: HighLevelRoutines.c
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

#include "HighLevelRoutines.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S132>/DeltaDistCalculator' */
#define RobotContr_IN_NO_ACTIVE_CHILD_p ((uint8_T)0U)
#define RobotControl_IN_StartTurn      ((uint8_T)1U)
#define RobotControl_IN_targetReached  ((uint8_T)2U)

/* Named constants for Chart: '<S136>/HighLevelDiagTestControl' */
#define Ro_CONST_COMPASS_DIAG_FIN_TIMER ((uint8_T)10U)
#define RobotContr_ENU_DIAG_ANGLE_CALIB ((uint8_T)6U)
#define RobotContr_IN_NO_ACTIVE_CHILD_a ((uint8_T)0U)
#define RobotContro_IN_SelfDiagComplete ((uint8_T)5U)
#define RobotControl_ENU_DIAG_BLTOTH   ((uint8_T)5U)
#define RobotControl_ENU_DIAG_COMP     ((uint8_T)1U)
#define RobotControl_ENU_DIAG_ENCOD    ((uint8_T)2U)
#define RobotControl_ENU_DIAG_NONE     ((uint8_T)7U)
#define RobotControl_ENU_FAILED        ((uint8_T)2U)
#define RobotControl_ENU_FINISHED      ((uint8_T)4U)
#define RobotControl_ENU_PASSED        ((uint8_T)1U)
#define RobotControl_IN_AngleCalib     ((uint8_T)1U)
#define RobotControl_IN_BlueTooth      ((uint8_T)1U)
#define RobotControl_IN_CompassRoutine ((uint8_T)2U)
#define RobotControl_IN_EncoderRoutine ((uint8_T)3U)
#define RobotControl_IN_Failed         ((uint8_T)4U)
#define RobotControl_IN_SelfDiag       ((uint8_T)2U)

/* Named constants for Chart: '<S126>/CompassSelfDiagTestChart' */
#define RobotCon_ENU_TEST_NOT_CONFIRMED ((uint8_T)3U)
#define RobotCont_CONST_ERROR_TOLERANCE ((uint8_T)15U)
#define RobotContro_ENU_MOVE_TURN_RIGHT ((uint8_T)21U)
#define RobotControl_CAL_EAST          (0U)
#define RobotControl_CAL_NORTH         (270U)
#define RobotControl_CAL_SOUTH         (90U)
#define RobotControl_CAL_WEST          (180U)
#define RobotControl_ENU_MOVE_TURN_LEFT ((uint8_T)20U)
#define RobotControl_ENU_ROB_NONE      (400U)
#define RobotControl_ENU_STOP_k        ((uint8_T)5U)
#define RobotControl_ENU_TEST_INIT     ((uint8_T)5U)
#define RobotControl_IN_DiagPassed     ((uint8_T)1U)
#define RobotControl_IN_Stop           ((uint8_T)1U)
#define RobotControl_IN_init           ((uint8_T)2U)
#define RobotControl_IN_turnHandler    ((uint8_T)3U)
#define RobotControl_IN_turnLeft       ((uint8_T)2U)
#define RobotControl_IN_turnRight      ((uint8_T)3U)
#define RobotControl_IN_turnRightFault ((uint8_T)4U)

/* Named constants for Chart: '<S127>/EncoderHeadingHandler' */
#define RobotCont_CAL_ROB_ERRVAL_ENCODE ((uint8_T)10U)

/* Named constants for Chart: '<S124>/CompassSelfDiagTestChart' */
#define RobotContr_IN_finishFacingNorth ((uint8_T)5U)
#define RobotControl_IN_FacingEAST     ((uint8_T)1U)
#define RobotControl_IN_FacingSOUTH    ((uint8_T)2U)
#define RobotControl_IN_FacingWEST     ((uint8_T)3U)
#define RobotControl_IN_Moving         ((uint8_T)4U)
#define RobotControl_IN_initFacingNorth ((uint8_T)6U)

/* Named constants for Chart: '<S109>/MainStateMachine' */
#define RobotCont_CONST_DIAG_FINISH_FLG ((uint8_T)8U)
#define RobotCont_CONST_MODES_TOLERANCE ((uint8_T)5U)
#define RobotContro_CONST_ZGZAG_CNT_THD ((uint8_T)2U)
#define RobotControl_CAL_Init_timer    (400U)
#define RobotControl_CONST_MAXZIGZAG   ((uint8_T)30U)
#define RobotControl_ENU_DIAG          ((uint8_T)28U)
#define RobotControl_ENU_END           ((uint8_T)27U)
#define RobotControl_ENU_GTSP          ((uint8_T)25U)
#define RobotControl_ENU_SHIFT_HEADING ((uint8_T)29U)
#define RobotControl_ENU_ZIGZAG        ((uint8_T)26U)
#define RobotControl_IN_DIAG           ((uint8_T)1U)
#define RobotControl_IN_End            ((uint8_T)2U)
#define RobotControl_IN_FaultState     ((uint8_T)1U)
#define RobotControl_IN_GTSP           ((uint8_T)3U)
#define RobotControl_IN_Running        ((uint8_T)2U)
#define RobotControl_IN_ShiftHeadings  ((uint8_T)4U)
#define RobotControl_IN_ZIGZAG         ((uint8_T)5U)

/* Named constants for Chart: '<S113>/ZgZgChart' */
#define RobotContr_event_refreshEvent_o (0L)
#define RobotControl_IN_Freeze         ((uint8_T)1U)
#define RobotControl_IN_Idle_o         ((uint8_T)2U)
#define RobotControl_IN_MovingForward  ((uint8_T)3U)
#define RobotControl_IN_Start          ((uint8_T)1U)
#define RobotControl_IN_SwitchLane     ((uint8_T)4U)
#define RobotControl_IN_faceWest       ((uint8_T)5U)
#define RobotControl_IN_finishInit     ((uint8_T)2U)
#define RobotControl_IN_finishZigZag   ((uint8_T)6U)
#define RobotControl_IN_turingRight    ((uint8_T)3U)
#define RobotControl_IN_turningLeft    ((uint8_T)4U)
#define RobotControl_IN_uturn          ((uint8_T)5U)
#define RobotControl_event_stopEvent_k (1L)

/* Named constants for Chart: '<S110>/GTSP_Chart' */
#define RobotC_IN_preFinishLeftBlockedN ((uint8_T)7U)
#define RobotC_IN_preFinishLeftBlockedW ((uint8_T)8U)
#define RobotContr_IN_preFinishBlockedN ((uint8_T)5U)
#define RobotContr_IN_preFinishBlockedW ((uint8_T)6U)
#define RobotControl_CAL_GTSPdelayStart ((uint8_T)200U)
#define RobotControl_CAL_ROBO_LENG_mm  (250U)
#define RobotControl_IN_End_f          ((uint8_T)1U)
#define RobotControl_IN_Forward        ((uint8_T)1U)
#define RobotControl_IN_Freeze1        ((uint8_T)3U)
#define RobotControl_IN_Freeze3        ((uint8_T)1U)
#define RobotControl_IN_Freeze4        ((uint8_T)2U)
#define RobotControl_IN_Freeze5        ((uint8_T)3U)
#define RobotControl_IN_Freeze6        ((uint8_T)4U)
#define RobotControl_IN_Freeze_o       ((uint8_T)2U)
#define RobotControl_IN_GTSP_Active    ((uint8_T)1U)
#define RobotControl_IN_GTSPsearch     ((uint8_T)5U)
#define RobotControl_IN_MostSouthLeft  ((uint8_T)3U)
#define RobotControl_IN_TurnLeft_g     ((uint8_T)3U)
#define RobotControl_IN_emptyOnRight   ((uint8_T)4U)
#define RobotControl_IN_faceWest_e     ((uint8_T)4U)
#define RobotControl_IN_facingSouth    ((uint8_T)1U)
#define RobotControl_IN_facingWest     ((uint8_T)5U)
#define RobotControl_IN_finish_m       ((uint8_T)2U)
#define RobotControl_IN_finishedGTSP   ((uint8_T)4U)
#define RobotControl_IN_furtherDown    ((uint8_T)6U)
#define RobotControl_IN_intermediate   ((uint8_T)7U)
#define RobotControl_IN_preFinishNormal ((uint8_T)9U)
#define RobotControl_IN_start_b        ((uint8_T)3U)
#define RobotControl_IN_start_bh       ((uint8_T)8U)
#if MotorsEOL_DisabledVariant

/* Forward declaration for local functions */
static real_T RobotControl_directionCheck(real_T strtHeading_o, real_T
  CurrentHeading_o, real_T N_o, real_T E_o, real_T S_o, real_T W_o, real_T
  enTheta_o, const real32_T *DataTypeConversion1_o, const real32_T
  *DataTypeConversion3_o, const real32_T *DataTypeConversion4_o, real32_T
  *DataTypeConversion5_o);

#endif                                 /* MotorsEOL_DisabledVariant */

/* Forward declaration for local functions */
static void Robo_chartstep_c33_RobotControl(const real32_T
  *DataTypeConversion1_e, const real32_T *DataTypeConversion2_m, const real32_T *
  DataTypeConversion3_g, real32_T *DataTypeConversion4);
static void Robo_chartstep_c32_RobotControl(const real32_T *forwardDist, const
  real32_T *DataTypeConversion, const real32_T *DataTypeConversion1, real32_T
  *DataTypeConversion2, real32_T *DataTypeConversion3);

/*
 * System initialize for atomic system:
 *    '<S132>/DeltaDistCalculator'
 *    '<S134>/DeltaDistCalculator'
 */
#if MotorsEOL_DisabledVariant

void RobotC_DeltaDistCalculator_Init(B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  localDW->is_active_c42_RobotControl = 0U;
  localDW->is_c42_RobotControl = RobotContr_IN_NO_ACTIVE_CHILD_p;
  localDW->tempDist = 0.0F;
  localB->deltaDistTrav = 0.0F;
}

#endif                                 /* MotorsEOL_DisabledVariant */

/*
 * Output and update for atomic system:
 *    '<S132>/DeltaDistCalculator'
 *    '<S134>/DeltaDistCalculator'
 */
#if MotorsEOL_DisabledVariant

void RobotContro_DeltaDistCalculator(boolean_T rtu_targetReached, real32_T
  rtu_rightDistTravelled_mm, B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  /* During: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  /* Calculates delta distance traveled by robot while making quarter turn */
  if (localDW->is_active_c42_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    localDW->is_active_c42_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    /* Transition: '<S133>:2' */
    localDW->is_c42_RobotControl = RobotControl_IN_StartTurn;

    /* Entry 'StartTurn': '<S133>:1' */
    localDW->tempDist = rtu_rightDistTravelled_mm;
  } else if ((localDW->is_c42_RobotControl == RobotControl_IN_StartTurn) &&
             rtu_targetReached) {
    /* During 'StartTurn': '<S133>:1' */
    /* Transition: '<S133>:7' */
    localDW->is_c42_RobotControl = RobotControl_IN_targetReached;

    /* Entry 'targetReached': '<S133>:6' */
    localB->deltaDistTrav = rtu_rightDistTravelled_mm - localDW->tempDist;
  } else {
    /* During 'targetReached': '<S133>:6' */
  }
}

#endif                                 /* MotorsEOL_DisabledVariant */

/* Function for Chart: '<S126>/CompassSelfDiagTestChart' */
#if MotorsEOL_DisabledVariant

static real_T RobotControl_directionCheck(real_T strtHeading_o, real_T
  CurrentHeading_o, real_T N_o, real_T E_o, real_T S_o, real_T W_o, real_T
  enTheta_o, const real32_T *DataTypeConversion1_o, const real32_T
  *DataTypeConversion3_o, const real32_T *DataTypeConversion4_o, real32_T
  *DataTypeConversion5_o)
{
  real_T outFlg_o;

  /* Graphical Function 'directionCheck': '<S128>:49' */
  /* Transition: '<S128>:51' */
  if (((strtHeading_o == *DataTypeConversion3_o) && (CurrentHeading_o == N_o) &&
       ((enTheta_o >= 265.0) || (enTheta_o <= 275.0))) || ((strtHeading_o ==
        *DataTypeConversion5_o) && (CurrentHeading_o == W_o) && (enTheta_o ==
        RobotControl_CAL_WEST)) || ((strtHeading_o == *DataTypeConversion4_o) &&
       (CurrentHeading_o == S_o) && (enTheta_o == RobotControl_CAL_SOUTH)) ||
      ((strtHeading_o == *DataTypeConversion1_o) && (CurrentHeading_o == E_o) &&
       (enTheta_o == 0.0))) {
    /* Transition: '<S128>:53' */
    /* Transition: '<S128>:72' */
    /* Transition: '<S128>:56' */
    /* Transition: '<S128>:71' */
    /* Transition: '<S128>:61' */
    /* Transition: '<S128>:73' */
    /* Transition: '<S128>:63' */
    /* Transition: '<S128>:65' */
    outFlg_o = 1.0;

    /* Transition: '<S128>:67' */
  } else {
    /* Transition: '<S128>:57' */
    /* Transition: '<S128>:70' */
    /* Transition: '<S128>:69' */
    /* Transition: '<S128>:68' */
    outFlg_o = 0.0;
  }

  return outFlg_o;
}

#endif                                 /* MotorsEOL_DisabledVariant */

/* Function for Chart: '<S113>/ZgZgChart' */
static void Robo_chartstep_c33_RobotControl(const real32_T
  *DataTypeConversion1_e, const real32_T *DataTypeConversion2_m, const real32_T *
  DataTypeConversion3_g, real32_T *DataTypeConversion4)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;

  /* During: RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart */
  /* zigzag is the main state machine for covering the area  */
  if (RobotControl_DW.is_active_c33_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart */
    RobotControl_DW.is_active_c33_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart */
    /* Transition: '<S141>:28' */
    RobotControl_DW.is_c33_RobotControl = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S141>:27' */
    RobotControl_B.zgzgActive = true;
    RobotControl_DW.finishCounter = 1U;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (RobotControl_DW.is_c33_RobotControl) {
     case RobotControl_IN_Freeze:
      /* During 'Freeze': '<S141>:121' */
      if (RobotControl_DW.sfEvent_l == RobotControl_event_stopEvent_k) {
        /* Transition: '<S141>:32' */
        if (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY))
        {
          /* Transition: '<S141>:38' */
          if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
            /* Constant: '<S113>/ENU_MOVE_U_TURN_RIGHT' */
            /* Transition: '<S141>:41' */
            RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN_RIGHT);
            RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S141>:31' */
            RobotControl_B.switchLaneFlg_BOOL = true;
            RobotControl_B.swLaneCnt_uint8++;
          } else if (RobotControl_B.currentHeading == *DataTypeConversion4) {
            /* Constant: '<S113>/ENU_MOVE_U_TURN_LEFT' */
            /* Transition: '<S141>:43' */
            RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN_LEFT);
            RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S141>:31' */
            RobotControl_B.switchLaneFlg_BOOL = true;
            RobotControl_B.swLaneCnt_uint8++;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }
      }
      break;

     case RobotControl_IN_Idle_o:
      /* During 'Idle': '<S141>:27' */
      if (RobotControl_B.currentRoutine == ((uint8_T)ENU_ZIGZAG)) {
        /* Transition: '<S141>:30' */
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S141>:92' */
        /* Transition: '<S141>:96' */
        RobotControl_DW.is_faceWest_f = RobotControl_IN_Start;

        /* Entry 'Start': '<S141>:104' */
        RobotControl_DW.initHeading = 0.0;
      }
      break;

     case RobotControl_IN_MovingForward:
      /* During 'MovingForward': '<S141>:29' */
      if ((RobotControl_B.currentHeading == *DataTypeConversion1_e) ||
          (RobotControl_B.currentHeading == *DataTypeConversion2_m)) {
        /* Transition: '<S141>:109' */
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S141>:92' */
        /* Transition: '<S141>:96' */
        RobotControl_DW.is_faceWest_f = RobotControl_IN_Start;

        /* Entry 'Start': '<S141>:104' */
        RobotControl_DW.initHeading = 0.0;
      } else {
        if (RobotControl_B.hitRoutineRun) {
          /* Transition: '<S141>:120' */
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_Freeze;
        }
      }
      break;

     case RobotControl_IN_SwitchLane:
      /* During 'SwitchLane': '<S141>:31' */
      if (RobotControl_DW.finishCounter > ((uint8_T)CAL_ZgZgCounterThd)) {
        /* Transition: '<S141>:54' */
        /* Exit 'SwitchLane': '<S141>:31' */
        RobotControl_B.switchLaneFlg_BOOL = false;
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_finishZigZag;

        /* Entry 'finishZigZag': '<S141>:53' */
        RobotControl_B.zgzgActive = false;

        /* Constant: '<S113>/ENU_STOP' */
        RobotControl_B.moveRequest_m = ((uint8_T)ENU_STOP);
      } else {
        if ((RobotControl_DW.headingRequest == RobotControl_B.currentHeading) &&
            RobotControl_B.OutportBufferFortargetReached) {
          /* Transition: '<S141>:55' */
          /* Exit 'SwitchLane': '<S141>:31' */
          RobotControl_B.switchLaneFlg_BOOL = false;
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_MovingForward;

          /* Constant: '<S113>/ENU_FORWARD' */
          /* Entry 'MovingForward': '<S141>:29' */
          RobotControl_B.moveRequest_m = ((uint8_T)ENU_FORWARD);
        }
      }
      break;

     case RobotControl_IN_faceWest:
      /* During 'faceWest': '<S141>:92' */
      if (RobotControl_DW.initHeading != 0.0) {
        /* Transition: '<S141>:108' */
        /* Exit Internal 'faceWest': '<S141>:92' */
        RobotControl_DW.is_faceWest_f = 0U;
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_MovingForward;

        /* Constant: '<S113>/ENU_FORWARD' */
        /* Entry 'MovingForward': '<S141>:29' */
        RobotControl_B.moveRequest_m = ((uint8_T)ENU_FORWARD);
      } else {
        switch (RobotControl_DW.is_faceWest_f) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S141>:104' */
          if (RobotControl_B.currentHeading == *DataTypeConversion4) {
            /* Transition: '<S141>:94' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_turingRight;

            /* Constant: '<S113>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S141>:103' */
            RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion1_e) {
            /* Transition: '<S141>:97' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_turningLeft;

            /* Entry 'turningLeft': '<S141>:105' */
            RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_TURN_RIGHT);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion2_m) {
            /* Transition: '<S141>:98' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_uturn;

            /* Entry 'uturn': '<S141>:107' */
            RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_TURN_LEFT);
          } else {
            if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
              /* Transition: '<S141>:101' */
              RobotControl_DW.is_faceWest_f = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S141>:106' */
              RobotControl_DW.initHeading = 1.0;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S141>:106' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S141>:103' */
          /* Transition: '<S141>:95' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S141>:100' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S141>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S141>:105' */
          /* Transition: '<S141>:99' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S141>:100' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S141>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         default:
          /* During 'uturn': '<S141>:107' */
          /* Transition: '<S141>:102' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S141>:100' */
            RobotControl_DW.is_faceWest_f = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S141>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;
        }
      }
      break;

     default:
      /* During 'finishZigZag': '<S141>:53' */
      if (RobotControl_B.currentRoutine == ((uint8_T)ENU_ZIGZAG)) {
        /* Transition: '<S141>:61' */
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S141>:27' */
        RobotControl_B.zgzgActive = true;
        RobotControl_DW.finishCounter = 1U;
      }
      break;
    }

    if (guard4) {
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_EMPTY))
          || (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_EMPTY)))
      {
        /* Transition: '<S141>:44' */
        if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
          /* Constant: '<S113>/ENU_MOVE_U_TURN_RIGHT' */
          /* Transition: '<S141>:45' */
          RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN_RIGHT);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S141>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading == *DataTypeConversion4) {
          /* Constant: '<S113>/ENU_MOVE_U_TURN' */
          /* Transition: '<S141>:46' */
          RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S141>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
    }

    if (guard3) {
      if (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_BUSY)) {
        /* Transition: '<S141>:90' */
        guard1 = true;
      } else if ((RobotControl_B.sensorView == ((uint8_T)
                   ENU_LEFT_EMPTY_RIGHT_CLEANED)) || (RobotControl_B.sensorView ==
                  ((uint8_T)ENU_LEFT_EMPTY_RIGHT_BUSY))) {
        /* Transition: '<S141>:47' */
        if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
          /* Constant: '<S113>/ENU_MOVE_U_TURN' */
          /* Transition: '<S141>:48' */
          RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S141>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading == *DataTypeConversion4) {
          /* Constant: '<S113>/ENU_MOVE_U_TURN_LEFT' */
          /* Transition: '<S141>:49' */
          RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN_LEFT);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S141>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }

    if (guard2) {
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_CLEANED)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_BUSY)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_CLEANED)))
      {
        /* Transition: '<S141>:50' */
        guard1 = true;
      }
    }

    if (guard1) {
      if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
        /* Constant: '<S113>/ENU_MOVE_U_TURN' */
        /* Transition: '<S141>:51' */
        RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN);
        RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S141>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else if (RobotControl_B.currentHeading == *DataTypeConversion4) {
        /* Constant: '<S113>/ENU_MOVE_U_TURN' */
        /* Transition: '<S141>:56' */
        RobotControl_B.moveRequest_m = ((uint8_T)ENU_MOVE_U_TURN);
        RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S141>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else {
        /* Transition: '<S141>:119' */
        RobotControl_DW.is_c33_RobotControl = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S141>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      }
    }
  }
}

/* Function for Chart: '<S110>/GTSP_Chart' */
static void Robo_chartstep_c32_RobotControl(const real32_T *forwardDist, const
  real32_T *DataTypeConversion, const real32_T *DataTypeConversion1, real32_T
  *DataTypeConversion2, real32_T *DataTypeConversion3)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During: RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart */
  /* Go to start point state machine. handles the logic of making the robot move to the most south west point on the map */
  if (RobotControl_DW.is_active_c32_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart */
    RobotControl_DW.is_active_c32_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart */
    /* Transition: '<S140>:6' */
    RobotControl_DW.is_c32_RobotControl = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S140>:5' */
    RobotControl_DW.counter = 0U;

    /* Constant: '<S110>/ENU_STOP' */
    RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
    RobotControl_DW.step1Flag = 0U;
    RobotControl_B.GT_active = true;
  } else {
    guard1 = false;
    guard2 = false;
    switch (RobotControl_DW.is_c32_RobotControl) {
     case RobotControl_IN_GTSP_Active:
      /* During 'GTSP_Active': '<S140>:7' */
      if (RobotControl_B.currentRoutine != ((uint8_T)ENU_GTSP)) {
        /* Transition: '<S140>:9' */
        /* Exit Internal 'GTSP_Active': '<S140>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.is_c32_RobotControl = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S140>:5' */
        RobotControl_DW.counter = 0U;

        /* Constant: '<S110>/ENU_STOP' */
        RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
        RobotControl_DW.step1Flag = 0U;
        RobotControl_B.GT_active = true;
      } else if (RobotControl_DW.step1Flag == 1) {
        /* Transition: '<S140>:68' */
        /* Exit Internal 'GTSP_Active': '<S140>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.activeFlag = true;
        RobotControl_DW.is_c32_RobotControl = RobotControl_IN_MostSouthLeft;
        RobotControl_DW.is_MostSouthLeft = RobotControl_IN_start_b;
      } else {
        switch (RobotControl_DW.is_GTSP_Active) {
         case RobotControl_IN_Forward:
          /* During 'Forward': '<S140>:10' */
          if (RobotControl_B.hitRoutineRun) {
            /* Transition: '<S140>:13' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Freeze_o;
          }
          break;

         case RobotControl_IN_Freeze_o:
          /* During 'Freeze': '<S140>:193' */
          if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
            /* Transition: '<S140>:194' */
            if ((RobotControl_B.sensorView == ((uint8_T)
                  ENU_LEFT_EMPTY_RIGHT_EMPTY)) || (RobotControl_B.sensorView ==
                 ((uint8_T)ENU_LEFT_EMPTY_RIGHT_CLEANED)) ||
                (RobotControl_B.sensorView == ((uint8_T)
                  ENU_LEFT_EMPTY_RIGHT_BUSY))) {
              /* Transition: '<S140>:15' */
              if (RobotControl_B.currentHeading == *DataTypeConversion) {
                /* Transition: '<S140>:18' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_TurnLeft_g;

                /* Constant: '<S110>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'TurnLeft': '<S140>:12' */
                RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_LEFT);
              } else if (RobotControl_B.currentHeading == *DataTypeConversion2)
              {
                /* Transition: '<S140>:20' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_preFinishNormal;

                /* Constant: '<S110>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'preFinishNormal': '<S140>:19' */
                RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_LEFT);
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }
          break;

         case RobotControl_IN_TurnLeft_g:
          /* During 'TurnLeft': '<S140>:12' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion2) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S140>:16' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

            /* Constant: '<S110>/ENU_FORWARD' */
            /* Entry 'Forward': '<S140>:10' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
          }
          break;

         case RobotControl_IN_finishedGTSP:
          /* During 'finishedGTSP': '<S140>:33' */
          break;

         case RobotContr_IN_preFinishBlockedN:
          /* During 'preFinishBlockedN': '<S140>:27' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S140>:36' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S140>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S110>/ENU_STOP' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
          }
          break;

         case RobotContr_IN_preFinishBlockedW:
          /* During 'preFinishBlockedW': '<S140>:28' */
          /* Transition: '<S140>:35' */
          RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

          /* Entry 'finishedGTSP': '<S140>:33' */
          RobotControl_DW.step1Flag = 1U;

          /* Constant: '<S110>/ENU_STOP' */
          RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
          break;

         case RobotC_IN_preFinishLeftBlockedN:
          /* During 'preFinishLeftBlockedN': '<S140>:21' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion1) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S140>:37' */
            /* Transition: '<S140>:157' */
            RobotControl_DW.is_GTSP_Active = 0U;
            RobotControl_DW.is_c32_RobotControl = RobotControl_IN_MostSouthLeft;
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_m;

            /* Entry 'finish': '<S140>:102' */
            RobotControl_B.GT_active = false;
          }
          break;

         case RobotC_IN_preFinishLeftBlockedW:
          /* During 'preFinishLeftBlockedW': '<S140>:25' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S140>:38' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S140>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S110>/ENU_STOP' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
          }
          break;

         default:
          /* During 'preFinishNormal': '<S140>:19' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion1) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S140>:34' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S140>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S110>/ENU_STOP' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
          }
          break;
        }
      }
      break;

     case RobotControl_IN_Idle_o:
      /* Constant: '<S110>/ENU_GTSP' */
      /* During 'Idle': '<S140>:5' */
      if ((RobotControl_B.currentRoutine == ((uint8_T)ENU_GTSP)) &&
          (RobotControl_DW.counter > RobotControl_CAL_GTSPdelayStart)) {
        /* Transition: '<S140>:8' */
        RobotControl_DW.is_c32_RobotControl = RobotControl_IN_faceWest_e;

        /* Entry Internal 'faceWest': '<S140>:126' */
        /* Transition: '<S140>:128' */
        RobotControl_DW.is_faceWest = RobotControl_IN_Start;

        /* Entry 'Start': '<S140>:127' */
        RobotControl_DW.initHeading_i = false;
      } else {
        RobotControl_DW.counter++;
      }
      break;

     case RobotControl_IN_MostSouthLeft:
      /* During 'MostSouthLeft': '<S140>:67' */
      switch (RobotControl_DW.is_MostSouthLeft) {
       case RobotControl_IN_facingSouth:
        /* During 'facingSouth': '<S140>:72' */
        if (!RobotControl_DW.activeFlag) {
          /* Transition: '<S140>:103' */
          /* Exit Internal 'facingSouth': '<S140>:72' */
          RobotControl_DW.is_facingSouth = 0U;

          /* Exit Internal 'GTSPsearch': '<S140>:94' */
          RobotControl_DW.is_GTSPsearch = 0U;
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_m;

          /* Entry 'finish': '<S140>:102' */
          RobotControl_B.GT_active = false;
        } else {
          switch (RobotControl_DW.is_facingSouth) {
           case RobotControl_IN_End_f:
            /* During 'End': '<S140>:89' */
            break;

           case RobotControl_IN_Freeze_o:
            /* During 'Freeze': '<S140>:197' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
              /* Transition: '<S140>:155' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_f;

              /* Entry 'End': '<S140>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze1:
            /* During 'Freeze1': '<S140>:199' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
              /* Transition: '<S140>:106' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_f;

              /* Entry 'End': '<S140>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze6:
            /* During 'Freeze6': '<S140>:205' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
              /* Transition: '<S140>:87' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_f;

              /* Entry 'End': '<S140>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           default:
            /* During 'GTSPsearch': '<S140>:94' */
            if ((*DataTypeConversion1 == RobotControl_B.currentHeading) &&
                RobotControl_B.OutportBufferFortargetReached &&
                (RobotControl_DW.round > 1) && RobotControl_B.hitRoutineRun) {
              /* Transition: '<S140>:95' */
              /* Transition: '<S140>:196' */
              /* Exit Internal 'GTSPsearch': '<S140>:94' */
              RobotControl_DW.is_GTSPsearch = 0U;

              /* Constant: '<S110>/ENU_STOP' */
              RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
              RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze_o;
            } else {
              switch (RobotControl_DW.is_GTSPsearch) {
               case RobotControl_IN_Freeze3:
                /* During 'Freeze3': '<S140>:200' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
                  /* Transition: '<S140>:201' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S110>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S140>:82' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                }
                break;

               case RobotControl_IN_Freeze4:
                /* During 'Freeze4': '<S140>:203' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
                  /* Transition: '<S140>:182' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S110>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S140>:82' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                }
                break;

               case RobotControl_IN_Freeze5:
                /* During 'Freeze5': '<S140>:207' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_k) {
                  /* Transition: '<S140>:208' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_furtherDown;

                  /* Constant: '<S110>/ENU_MOVE_TURN_LEFT' */
                  /* Entry 'furtherDown': '<S140>:91' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_LEFT);
                }
                break;

               case RobotControl_IN_emptyOnRight:
                /* During 'emptyOnRight': '<S140>:82' */
                if ((RobotControl_B.currentHeading == *DataTypeConversion2) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S140>:85' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_facingWest;

                  /* Constant: '<S110>/ENU_FORWARD' */
                  /* Entry 'facingWest': '<S140>:84' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
                }
                break;

               case RobotControl_IN_facingWest:
                /* During 'facingWest': '<S140>:84' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Constant: '<S110>/ENU_LEFT_EMPTY_RIGHT_BUSY' incorporates:
                   *  Constant: '<S110>/ENU_LEFT_BUSY_RIGHT_BUSY'
                   *  Constant: '<S110>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                   *  Constant: '<S110>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                   */
                  /* Transition: '<S140>:204' */
                  if ((RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_BUSY)) ||
                      (RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                    /* Transition: '<S140>:92' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze5;
                  } else {
                    if ((RobotControl_B.sensorView == ((uint8_T)
                          ENU_LEFT_BUSY_RIGHT_BUSY)) ||
                        (RobotControl_B.sensorView == ((uint8_T)
                          ENU_LEFT_BUSY_RIGHT_EMPTY))) {
                      /* Transition: '<S140>:90' */
                      RobotControl_DW.is_GTSPsearch = 0U;
                      RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze6;
                    }
                  }

                  /* End of Constant: '<S110>/ENU_LEFT_EMPTY_RIGHT_BUSY' */
                }
                break;

               case RobotControl_IN_furtherDown:
                /* During 'furtherDown': '<S140>:91' */
                if ((RobotControl_B.currentHeading == *DataTypeConversion1) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S140>:93' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_bh;

                  /* Constant: '<S110>/ENU_FORWARD' */
                  /* Entry 'start': '<S140>:77' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
                  RobotControl_DW.round++;
                }
                break;

               case RobotControl_IN_intermediate:
                /* During 'intermediate': '<S140>:173' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S140>:202' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze4;
                } else if ((RobotControl_B.sensorView != ((uint8_T)
                             ENU_LEFT_BUSY_RIGHT_EMPTY)) &&
                           (RobotControl_B.sensorView != ((uint8_T)
                             ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                  /* Transition: '<S140>:167' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_bh;

                  /* Constant: '<S110>/ENU_FORWARD' */
                  /* Entry 'start': '<S140>:77' */
                  RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
                  RobotControl_DW.round++;
                } else {
                  if (*forwardDist - RobotControl_DW.tempDist_l >
                      RobotControl_CAL_ROBO_LENG_mm) {
                    /* Transition: '<S140>:166' */
                    /* * 0.75)] */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                    /* Constant: '<S110>/ENU_MOVE_TURN_RIGHT' */
                    /* Entry 'emptyOnRight': '<S140>:82' */
                    RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                  }
                }
                break;

               default:
                /* Constant: '<S110>/ENU_LEFT_BUSY_RIGHT_EMPTY' incorporates:
                 *  Constant: '<S110>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                 */
                /* During 'start': '<S140>:77' */
                if (((RobotControl_B.sensorView == ((uint8_T)
                       ENU_LEFT_BUSY_RIGHT_EMPTY)) || (RobotControl_B.sensorView
                      == ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY))) &&
                    RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S140>:164' */
                  /* Transition: '<S140>:163' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze3;
                } else if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S140>:198' */
                  RobotControl_DW.is_GTSPsearch = 0U;
                  RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze1;
                } else {
                  if ((RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_BUSY_RIGHT_EMPTY)) ||
                      (RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                    /* Transition: '<S140>:81' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_intermediate;

                    /* Entry 'intermediate': '<S140>:173' */
                    RobotControl_DW.tempDist_l = *forwardDist;
                  }
                }
                break;
              }
            }
            break;
          }
        }
        break;

       case RobotControl_IN_finish_m:
        /* Constant: '<S110>/ENU_GTSP' */
        /* During 'finish': '<S140>:102' */
        if (RobotControl_B.currentRoutine == ((uint8_T)ENU_GTSP)) {
          /* Transition: '<S140>:101' */
          RobotControl_DW.is_MostSouthLeft = 0U;
          RobotControl_DW.is_c32_RobotControl = RobotControl_IN_Idle_o;

          /* Entry 'Idle': '<S140>:5' */
          RobotControl_DW.counter = 0U;

          /* Constant: '<S110>/ENU_STOP' */
          RobotControl_B.moveRequest_l = ((uint8_T)ENU_STOP);
          RobotControl_DW.step1Flag = 0U;
          RobotControl_B.GT_active = true;
        }
        break;

       default:
        /* During 'start': '<S140>:69' */
        if (RobotControl_B.currentHeading == *DataTypeConversion1) {
          /* Transition: '<S140>:73' */
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_facingSouth;

          /* Entry Internal 'facingSouth': '<S140>:72' */
          /* Transition: '<S140>:99' */
          RobotControl_DW.is_facingSouth = RobotControl_IN_GTSPsearch;

          /* Entry 'GTSPsearch': '<S140>:94' */
          RobotControl_DW.round = 0U;

          /* Entry Internal 'GTSPsearch': '<S140>:94' */
          /* Transition: '<S140>:78' */
          RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_bh;

          /* Constant: '<S110>/ENU_FORWARD' */
          /* Entry 'start': '<S140>:77' */
          RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.round++;
        } else {
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S140>:74' */
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_m;

            /* Entry 'finish': '<S140>:102' */
            RobotControl_B.GT_active = false;
          }
        }
        break;
      }
      break;

     default:
      /* During 'faceWest': '<S140>:126' */
      if (RobotControl_DW.initHeading_i) {
        /* Transition: '<S140>:139' */
        /* Exit Internal 'faceWest': '<S140>:126' */
        RobotControl_DW.is_faceWest = 0U;
        RobotControl_DW.is_c32_RobotControl = RobotControl_IN_GTSP_Active;

        /* Entry Internal 'GTSP_Active': '<S140>:7' */
        /* Transition: '<S140>:11' */
        RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

        /* Constant: '<S110>/ENU_FORWARD' */
        /* Entry 'Forward': '<S140>:10' */
        RobotControl_B.moveRequest_l = ((uint8_T)ENU_FORWARD);
      } else {
        switch (RobotControl_DW.is_faceWest) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S140>:127' */
          if (RobotControl_B.currentHeading == *DataTypeConversion1) {
            /* Transition: '<S140>:132' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turingRight;

            /* Constant: '<S110>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S140>:129' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_U_TURN);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion2) {
            /* Transition: '<S140>:133' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turningLeft;

            /* Constant: '<S110>/ENU_MOVE_TURN_RIGHT' */
            /* Entry 'turningLeft': '<S140>:130' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_RIGHT);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion3) {
            /* Transition: '<S140>:134' */
            RobotControl_DW.is_faceWest = RobotControl_IN_uturn;

            /* Constant: '<S110>/ENU_MOVE_TURN_LEFT' */
            /* Entry 'uturn': '<S140>:131' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_LEFT);
          } else {
            if (RobotControl_B.currentHeading == *DataTypeConversion) {
              /* Transition: '<S140>:142' */
              RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S140>:140' */
              RobotControl_DW.initHeading_i = true;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S140>:140' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S140>:129' */
          /* Transition: '<S140>:136' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S140>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S140>:140' */
            RobotControl_DW.initHeading_i = true;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S140>:130' */
          /* Transition: '<S140>:137' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S140>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S140>:140' */
            RobotControl_DW.initHeading_i = true;
          }
          break;

         default:
          /* During 'uturn': '<S140>:131' */
          /* Transition: '<S140>:138' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S140>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S140>:140' */
            RobotControl_DW.initHeading_i = true;
          }
          break;
        }
      }
      break;
    }

    if (guard2) {
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_EMPTY))
          || (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_EMPTY)))
      {
        /* Transition: '<S140>:23' */
        if (RobotControl_B.currentHeading == *DataTypeConversion) {
          /* Transition: '<S140>:24' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedN;

          /* Constant: '<S110>/ENU_MOVE_U_TURN' */
          /* Entry 'preFinishLeftBlockedN': '<S140>:21' */
          RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_U_TURN);
        } else if (RobotControl_B.currentHeading == *DataTypeConversion2) {
          /* Transition: '<S140>:26' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedW;

          /* Constant: '<S110>/ENU_MOVE_TURN_RIGHT' */
          /* Entry 'preFinishLeftBlockedW': '<S140>:25' */
          RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_TURN_RIGHT);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      /* Constant: '<S110>/ENU_LEFT_BUSY_RIGHT_BUSY' incorporates:
       *  Constant: '<S110>/ENU_LEFT_BUSY_RIGHT_CLEANED'
       *  Constant: '<S110>/ENU_LEFT_CLEANED_RIGHT_BUSY'
       *  Constant: '<S110>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
       */
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_BUSY)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_CLEANED)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_BUSY)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_CLEANED)))
      {
        /* Transition: '<S140>:30' */
        if (RobotControl_B.currentHeading == *DataTypeConversion2) {
          /* Transition: '<S140>:31' */
          RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedW;
        } else {
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S140>:32' */
            RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedN;

            /* Constant: '<S110>/ENU_MOVE_U_TURN' */
            /* Entry 'preFinishBlockedN': '<S140>:27' */
            RobotControl_B.moveRequest_l = ((uint8_T)ENU_MOVE_U_TURN);
          }
        }
      }
    }
  }
}

/* System initialize for function-call system: '<S22>/HighLevelRoutines' */
void RobotCon_HighLevelRoutines_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S27>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_h = true;

  /* InitializeConditions for UnitDelay: '<S27>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_b = ((uint8_T)CONST_DIAG_UNCONFIRM);

  /* InitializeConditions for UnitDelay: '<S27>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE = CAL_NORTH;

  /* SystemInitialize for Chart: '<S109>/MainStateMachine' */
  RobotControl_DW.is_Running = 0U;
  RobotControl_DW.temporalCounter_i1 = 0U;
  RobotControl_DW.is_active_c25_RobotControl = 0U;
  RobotControl_DW.is_c25_RobotControl = 0U;
  RobotControl_DW.zgzgCounter = 0U;
  RobotControl_B.currentRoutine = 0U;

  /* SystemInitialize for Chart: '<S108>/pumperHitSensorView' */
  RobotControl_B.sensorView = 0U;
  RobotControl_DW.doneDoubleBufferReInit = 0;

  /* SystemInitialize for IfAction SubSystem: '<S27>/zigzagRoutine' */
  /* SystemInitialize for Chart: '<S113>/ZgZgChart' */
  RobotControl_DW.is_faceWest_f = 0U;
  RobotControl_DW.is_active_c33_RobotControl = 0U;
  RobotControl_DW.is_c33_RobotControl = 0U;
  RobotControl_DW.headingRequest = 0U;
  RobotControl_DW.finishCounter = 0U;
  RobotControl_DW.initHeading = 0.0;
  RobotControl_B.moveRequest_m = 0U;
  RobotControl_B.zgzgActive = true;
  RobotControl_B.switchLaneFlg_BOOL = false;
  RobotControl_B.swLaneCnt_uint8 = 0U;

  /* SystemInitialize for Outport: '<S113>/zgzgActive' */
  RobotControl_B.OutportBufferForzgzgActive = true;

  /* End of SystemInitialize for SubSystem: '<S27>/zigzagRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/StartPointRoutine' */
  /* SystemInitialize for Chart: '<S110>/GTSP_Chart' */
  RobotControl_DW.is_GTSP_Active = 0U;
  RobotControl_DW.is_MostSouthLeft = 0U;
  RobotControl_DW.is_facingSouth = 0U;
  RobotControl_DW.is_GTSPsearch = 0U;
  RobotControl_DW.is_faceWest = 0U;
  RobotControl_DW.is_active_c32_RobotControl = 0U;
  RobotControl_DW.is_c32_RobotControl = 0U;
  RobotControl_DW.counter = 0U;
  RobotControl_DW.round = 0U;
  RobotControl_DW.step1Flag = 0U;
  RobotControl_DW.initHeading_i = false;
  RobotControl_DW.activeFlag = false;
  RobotControl_DW.tempDist_l = 0.0F;
  RobotControl_B.moveRequest_l = 0U;
  RobotControl_B.GT_active = true;

  /* End of SystemInitialize for SubSystem: '<S27>/StartPointRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/DIAG_Routine' */
  /* SystemInitialize for Atomic SubSystem: '<S105>/Diag_Routine_Variant' */
#if motorsHandleEOL_Variant

  /* No code for variant choice */
#elif MotorsEOL_DisabledVariant

  /* System initialize for atomic system: '<S114>/Diag_Routine_Enabled' */

  /* InitializeConditions for UnitDelay: '<S116>/Unit_Delay1' */
  RobotControl_DW.Diag_Routine_Enabled.Unit_Delay1_DSTATE = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* InitializeConditions for UnitDelay: '<S116>/Unit_Delay' */
  RobotControl_DW.Diag_Routine_Enabled.Unit_Delay_DSTATE = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* InitializeConditions for UnitDelay: '<S116>/Unit_Delay2' */
  RobotControl_DW.Diag_Routine_Enabled.Unit_Delay2_DSTATE = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* SystemInitialize for Chart: '<S136>/HighLevelDiagTestControl' */
  RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
    RobotContr_IN_NO_ACTIVE_CHILD_a;
  RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k = 0U;
  RobotControl_DW.Diag_Routine_Enabled.is_active_c44_RobotControl = 0U;
  RobotControl_DW.Diag_Routine_Enabled.is_c44_RobotControl =
    RobotContr_IN_NO_ACTIVE_CHILD_a;
  RobotControl_B.Diag_Routine_Enabled.diagEnableReq = 0U;
  RobotControl_B.VariantMergeForOutportenableAng = false;
  RobotControl_B.VariantMergeForOutportDIAG_Stat = 9U;

  /* SystemInitialize for IfAction SubSystem: '<S116>/CompassTest' */
  /* SystemInitialize for Chart: '<S126>/CompassSelfDiagTestChart' */
  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
    RobotContr_IN_NO_ACTIVE_CHILD_a;
  RobotControl_DW.Diag_Routine_Enabled.is_active_c40_RobotControl = 0U;
  RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
    RobotContr_IN_NO_ACTIVE_CHILD_a;
  RobotControl_DW.Diag_Routine_Enabled.startHeading = 0U;
  RobotControl_DW.Diag_Routine_Enabled.steps = 0U;
  RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt = 0U;
  RobotControl_B.VariantMergeForOutportcompFault = false;
  RobotControl_B.Diag_Routine_Enabled.moveReq_p = 0U;
  RobotControl_B.VariantMergeForOutportcomTstSta = 3U;

  /* End of SystemInitialize for SubSystem: '<S116>/CompassTest' */

  /* SystemInitialize for IfAction SubSystem: '<S116>/EncoderTest' */

  /* SystemInitialize for Chart: '<S132>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init
    (&RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator,
     &RobotControl_DW.Diag_Routine_Enabled.sf_DeltaDistCalculator);

  /* SystemInitialize for Chart: '<S134>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init
    (&RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator_c,
     &RobotControl_DW.Diag_Routine_Enabled.sf_DeltaDistCalculator_c);

  /* End of SystemInitialize for SubSystem: '<S116>/EncoderTest' */

  /* SystemInitialize for IfAction SubSystem: '<S116>/Angle_Calibration' */
  /* SystemInitialize for Enabled SubSystem: '<S117>/Angle_CalibrationUponReq' */
  /* SystemInitialize for Chart: '<S124>/CompassSelfDiagTestChart' */
  RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;
  RobotControl_DW.Diag_Routine_Enabled.is_active_c39_RobotControl = 0U;
  RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
    RobotContr_IN_NO_ACTIVE_CHILD_a;
  RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = false;
  RobotControl_B.Diag_Routine_Enabled.moveReq = 0U;
  RobotControl_B.Diag_Routine_Enabled.NORTH = 0U;
  RobotControl_B.Diag_Routine_Enabled.SOUTH = 0U;
  RobotControl_B.Diag_Routine_Enabled.EAST = 0U;
  RobotControl_B.Diag_Routine_Enabled.WEST = 0U;
  RobotControl_B.Diag_Routine_Enabled.angleCalibStatus = 3U;

  /* SystemInitialize for Outport: '<S124>/moveRequest' */
  RobotControl_B.Diag_Routine_Enabled.OutportBufferFormoveRequest = ((uint8_T)
    ENU_STOP);

  /* SystemInitialize for Outport: '<S124>/angleCalibStatus' */
  RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalibStatu =
    ((uint8_T)ENU_TEST_NOT_CONFIRMED);

  /* End of SystemInitialize for SubSystem: '<S117>/Angle_CalibrationUponReq' */

  /* SystemInitialize for Outport: '<S117>/angleCalibStatus' */
  RobotControl_B.VariantMergeForOutportangleCa_h = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* End of SystemInitialize for SubSystem: '<S116>/Angle_Calibration' */
#endif                                 /* motorsHandleEOL_Variant */

  /* End of SystemInitialize for SubSystem: '<S105>/Diag_Routine_Variant' */

  /* SystemInitialize for Outport: '<S105>/DIAG_StatusFlg' */
  RobotControl_B.VariantMergeForOutportDIAG_Stat = ((uint8_T)
    CONST_DIAG_UNCONFIRM);

  /* End of SystemInitialize for SubSystem: '<S27>/DIAG_Routine' */

  /* SystemInitialize for Merge: '<S27>/Merge' */
  RobotControl_B.Merge = 5U;
}

/* Start for function-call system: '<S22>/HighLevelRoutines' */
void RobotCo_HighLevelRoutines_Start(void)
{
  /* Start for SwitchCase: '<S112>/Switch_Case' */
  RobotControl_DW.Switch_Case_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S27>/DIAG_Routine' */
  /* Start for Atomic SubSystem: '<S105>/Diag_Routine_Variant' */
#if motorsHandleEOL_Variant

  /* No code for variant choice */
#elif MotorsEOL_DisabledVariant

  /* Start for atomic system: '<S114>/Diag_Routine_Enabled' */

  /* Start for SwitchCase: '<S121>/Switch_Case' */
  RobotControl_DW.Diag_Routine_Enabled.Switch_Case_ActiveSubsystem = -1;

#endif                                 /* motorsHandleEOL_Variant */

  /* End of Start for SubSystem: '<S105>/Diag_Routine_Variant' */
  /* End of Start for SubSystem: '<S27>/DIAG_Routine' */
}

/* Output and update for function-call system: '<S22>/HighLevelRoutines' */
void RobotControl_HighLevelRoutines(void)
{
  /* local block i/o variables */
  real32_T rtb_thetaEncod;
  int8_T rtPrevAction;
  int8_T rtAction;
  uint8_T rtb_leftBlocks_uint8;
  uint8_T rtb_rightBlocks_uint8;
  real32_T forwardDist;
  real32_T DataTypeConversion2_m;
  real32_T DataTypeConversion3_g;
  real32_T DataTypeConversion4;
  real32_T DataTypeConversion3;
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;

  /* Chart: '<S109>/MainStateMachine' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion3'
   *  UnitDelay: '<S27>/Unit_Delay'
   *  UnitDelay: '<S27>/Unit_Delay1'
   *  UnitDelay: '<S27>/Unit_Delay3'
   *  UnitDelay: '<S27>/Unit_Delay4'
   */
  /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine */
  if (RobotControl_DW.temporalCounter_i1 < 511U) {
    RobotControl_DW.temporalCounter_i1++;
  }

  /* During: RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine */
  /* robot modes handler */
  if (RobotControl_DW.is_active_c25_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine */
    RobotControl_DW.is_active_c25_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/RoutineControl/MainStateMachine */
    /* Transition: '<S139>:31' */
    RobotControl_DW.is_c25_RobotControl = RobotControl_IN_Running;

    /* Entry Internal 'Running': '<S139>:30' */
    /* Transition: '<S139>:2' */
    RobotControl_DW.is_Running = RobotControl_IN_DIAG;
    RobotControl_DW.temporalCounter_i1 = 0U;
  } else if (RobotControl_DW.is_c25_RobotControl != RobotControl_IN_FaultState)
  {
    /* During 'Running': '<S139>:30' */
    if (RobotControl_B.failFlag) {
      /* Transition: '<S139>:33' */
      /* Exit Internal 'Running': '<S139>:30' */
      RobotControl_DW.is_Running = 0U;
      RobotControl_DW.is_c25_RobotControl = RobotControl_IN_FaultState;

      /* Entry 'FaultState': '<S139>:32' */
      RobotControl_B.currentRoutine = RobotControl_ENU_END;
    } else {
      switch (RobotControl_DW.is_Running) {
       case RobotControl_IN_DIAG:
        /* During 'DIAG': '<S139>:1' */
        if (RobotControl_DW.Unit_Delay4_DSTATE_b ==
            RobotCont_CONST_DIAG_FINISH_FLG) {
          /* Transition: '<S139>:4' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S139>:3' */
          RobotControl_B.currentRoutine = RobotControl_ENU_GTSP;
        } else {
          if (RobotControl_DW.temporalCounter_i1 >= RobotControl_CAL_Init_timer)
          {
            RobotControl_B.currentRoutine = RobotControl_ENU_DIAG;
            RobotControl_DW.zgzgCounter = 0U;
          }
        }
        break;

       case RobotControl_IN_End:
        /* During 'End': '<S139>:7' */
        break;

       case RobotControl_IN_GTSP:
        /* During 'GTSP': '<S139>:3' */
        if ((!RobotControl_DW.Unit_Delay_DSTATE_h) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S139>:6' */
          RobotControl_DW.is_Running = RobotControl_IN_ZIGZAG;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'ZIGZAG': '<S139>:5' */
          RobotControl_B.currentRoutine = RobotControl_ENU_ZIGZAG;
          RobotControl_DW.zgzgCounter++;
        }
        break;

       case RobotControl_IN_ShiftHeadings:
        /* During 'ShiftHeadings': '<S139>:43' */
        if (RobotControl_DW.temporalCounter_i1 >=
            RobotCont_CONST_MODES_TOLERANCE) {
          /* Transition: '<S139>:44' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S139>:3' */
          RobotControl_B.currentRoutine = RobotControl_ENU_GTSP;
        }
        break;

       default:
        /* During 'ZIGZAG': '<S139>:5' */
        if ((!RobotControl_DW.Unit_Delay1_DSTATE) &&
            (RobotControl_DW.zgzgCounter >= RobotContro_CONST_ZGZAG_CNT_THD) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S139>:18' */
          RobotControl_DW.is_Running = RobotControl_IN_End;

          /* Entry 'End': '<S139>:7' */
          RobotControl_B.currentRoutine = RobotControl_ENU_END;
        } else {
          if ((!RobotControl_DW.Unit_Delay1_DSTATE) ||
              (RobotControl_B.OutportBufferForswLaneCnt_uint8 >
               RobotControl_CONST_MAXZIGZAG)) {
            /* Transition: '<S139>:13' */
            RobotControl_DW.is_Running = RobotControl_IN_ShiftHeadings;
            RobotControl_DW.temporalCounter_i1 = 0U;

            /* Entry 'ShiftHeadings': '<S139>:43' */
            RobotControl_B.currentRoutine = RobotControl_ENU_SHIFT_HEADING;
          }
        }
        break;
      }
    }
  } else {
    /* During 'FaultState': '<S139>:32' */
  }

  /* End of Chart: '<S109>/MainStateMachine' */

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S111>/CAL_ULS_UnconnectedBlks'
   *  DataTypeConversion: '<S111>/Data_Type_Conversion1'
   */
  if (RobotControl_B.ULSL_NotConnectedFlag_BOOL_h) {
    rtb_leftBlocks_uint8 = ((uint8_T)CAL_ULS_UnconnectedBlks);
  } else {
    rtb_leftBlocks_uint8 = (uint8_T)RobotControl_B.leftBlocks;
  }

  /* End of Switch: '<S111>/Switch' */

  /* Switch: '<S111>/Switch1' incorporates:
   *  Constant: '<S111>/CAL_ULS_UnconnectedBlks1'
   *  DataTypeConversion: '<S111>/Data_Type_Conversion2'
   */
  if (RobotControl_B.ULSR_NotConnectedFlag_BOOL_a) {
    rtb_rightBlocks_uint8 = ((uint8_T)CAL_ULS_UnconnectedBlks);
  } else {
    rtb_rightBlocks_uint8 = (uint8_T)RobotControl_B.rightBlocks;
  }

  /* End of Switch: '<S111>/Switch1' */

  /* Chart: '<S108>/pumperHitSensorView' incorporates:
   *  Constant: '<S108>/ENU_LEFT_BUSY_RIGHT_BUSY'
   *  Constant: '<S108>/ENU_LEFT_BUSY_RIGHT_EMPTY'
   *  Constant: '<S108>/ENU_LEFT_EMPTY_RIGHT_BUSY'
   *  Constant: '<S108>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
   */
  /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView */
  RobotControl_DW.encoderStep_prev = RobotControl_DW.encoderStep_start;
  RobotControl_DW.encoderStep_start = RobotControl_B.encoderStep;

  /* During: RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView */
  /* calculates the ULS sensor view to decide whether we have obstical at left or right */
  if (!RobotControl_DW.doneDoubleBufferReInit) {
    RobotControl_DW.doneDoubleBufferReInit = 1;
    RobotControl_DW.encoderStep_prev = RobotControl_B.encoderStep;
  }

  /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/HitSensorViewCalculation/pumperHitSensorView */
  /* Transition: '<S138>:67' */
  /* sensorView = 0; */
  if (RobotControl_B.pumperHit_BOOL || (RobotControl_DW.encoderStep_prev !=
       RobotControl_DW.encoderStep_start) ||
      RobotControl_B.OutportBufferFortargetReached) {
    /* Transition: '<S138>:70' */
    /* Transition: '<S138>:72' */
    if ((rtb_leftBlocks_uint8 <= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S138>:74' */
      /* Transition: '<S138>:87' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_BUSY_RIGHT_EMPTY);

      /* Transition: '<S138>:106' */
    } else {
      /* Transition: '<S138>:84' */
    }

    /* Transition: '<S138>:107' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 <= 1)) {
      /* Transition: '<S138>:81' */
      /* Transition: '<S138>:88' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_EMPTY_RIGHT_BUSY);

      /* Transition: '<S138>:108' */
    } else {
      /* Transition: '<S138>:85' */
    }

    /* Transition: '<S138>:109' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S138>:82' */
      /* Transition: '<S138>:89' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY);

      /* Transition: '<S138>:110' */
    } else {
      /* Transition: '<S138>:86' */
    }

    /* Transition: '<S138>:111' */
    if ((rtb_leftBlocks_uint8 < 1) && (rtb_rightBlocks_uint8 < 1)) {
      /* Transition: '<S138>:83' */
      /* Transition: '<S138>:93' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_BUSY_RIGHT_BUSY);

      /* Transition: '<S138>:94' */
    } else {
      /* Transition: '<S138>:92' */
    }

    /* Transition: '<S138>:97' */
  } else {
    /* Transition: '<S138>:96' */
  }

  /* End of Chart: '<S108>/pumperHitSensorView' */

  /* Switch: '<S106>/Switch1' incorporates:
   *  Constant: '<S106>/CONST_TWO_F32'
   *  Constant: '<S106>/CONST_ZERO_F32'
   *  Constant: '<S106>/ENU_FORWARD'
   *  Product: '<S106>/Divide'
   *  RelationalOperator: '<S106>/Relational_Operator'
   *  Sum: '<S106>/Add'
   *  UnitDelay: '<S27>/Unit_Delay2'
   */
  /* Transition: '<S138>:99' */
  if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
    forwardDist = (RobotControl_B.Data_Type_Conversion +
                   RobotControl_B.Data_Type_Conversion_m) / CONST_TWO_F32;
  } else {
    forwardDist = CONST_ZERO_F32;
  }

  /* End of Switch: '<S106>/Switch1' */

  /* UnitDelay: '<S27>/Unit_Delay5' */
  rtb_thetaEncod = RobotControl_DW.Unit_Delay5_DSTATE;

  /* SwitchCase: '<S112>/Switch_Case' */
  rtPrevAction = RobotControl_DW.Switch_Case_ActiveSubsystem;
  switch ((int32_T)RobotControl_B.currentRoutine) {
   case 26L:
    rtAction = 0;
    break;

   case 25L:
    rtAction = 1;
    break;

   case 28L:
    rtAction = 2;
    break;

   default:
    rtAction = 3;
    break;
  }

  RobotControl_DW.Switch_Case_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 2)) {
    /* Disable for Atomic SubSystem: '<S105>/Diag_Routine_Variant' */
#if motorsHandleEOL_Variant

    /* No code for variant choice */
#elif MotorsEOL_DisabledVariant

    /* Disable for atomic system: '<S114>/Diag_Routine_Enabled' */

    /* Disable for Enabled SubSystem: '<S117>/Angle_CalibrationUponReq' */
    /* Disable for SwitchCase: '<S121>/Switch_Case' */
    if ((RobotControl_DW.Diag_Routine_Enabled.Switch_Case_ActiveSubsystem == 3) &&
        RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE) {
      RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE = false;
    }

    /* End of Disable for SubSystem: '<S117>/Angle_CalibrationUponReq' */
    RobotControl_DW.Diag_Routine_Enabled.Switch_Case_ActiveSubsystem = -1;

    /* End of Disable for SwitchCase: '<S121>/Switch_Case' */
#endif                                 /* motorsHandleEOL_Variant */

    /* End of Disable for SubSystem: '<S105>/Diag_Routine_Variant' */
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S27>/zigzagRoutine' incorporates:
       *  SystemReset for ActionPort: '<S113>/ZigZagActive'
       */
      /* SystemReset for SwitchCase: '<S112>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S113>/ZgZgChart'
       */
      RobotControl_DW.is_faceWest_f = 0U;
      RobotControl_DW.is_active_c33_RobotControl = 0U;
      RobotControl_DW.is_c33_RobotControl = 0U;
      RobotControl_DW.headingRequest = 0U;
      RobotControl_DW.finishCounter = 0U;
      RobotControl_DW.initHeading = 0.0;
      RobotControl_B.moveRequest_m = 0U;
      RobotControl_B.zgzgActive = true;
      RobotControl_B.switchLaneFlg_BOOL = false;
      RobotControl_B.swLaneCnt_uint8 = 0U;

      /* End of SystemReset for SubSystem: '<S27>/zigzagRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S27>/zigzagRoutine' incorporates:
     *  ActionPort: '<S113>/ZigZagActive'
     */
    /* DataTypeConversion: '<S113>/Data Type Conversion1' */
    forwardDist = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S113>/Data Type Conversion2' */
    DataTypeConversion2_m = RobotControl_B.ROB_EAST;

    /* DataTypeConversion: '<S113>/Data Type Conversion3' */
    DataTypeConversion3_g = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S113>/Data Type Conversion4' */
    DataTypeConversion4 = RobotControl_B.ROB_SOUTH;

    /* Chart: '<S113>/ZgZgChart' incorporates:
     *  TriggerPort: '<S141>/input events'
     */
    zcEvent_idx_0 = (((RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] == POS_ZCSIG)
                      != (int16_T)RobotControl_B.refreshEvent) &&
                     (RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] !=
                      UNINITIALIZED_ZCSIG));
    zcEvent_idx_1 = (((RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] == POS_ZCSIG)
                      != (int16_T)RobotControl_B.stopEvent) &&
                     (RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] !=
                      UNINITIALIZED_ZCSIG));
    if (zcEvent_idx_0 || zcEvent_idx_1) {
      /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/zigzagRoutine/ZgZgChart */
      if ((int8_T)(zcEvent_idx_0 ? RobotControl_B.refreshEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S141>:89' */
        RobotControl_DW.sfEvent_l = RobotContr_event_refreshEvent_o;
        Robo_chartstep_c33_RobotControl(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4);
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S141>:88' */
        RobotControl_DW.sfEvent_l = RobotControl_event_stopEvent_k;
        Robo_chartstep_c33_RobotControl(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4);
      }
    }

    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S113>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_m;

    /* SignalConversion: '<S113>/OutportBufferForswLaneCnt_uint8' */
    RobotControl_B.OutportBufferForswLaneCnt_uint8 =
      RobotControl_B.swLaneCnt_uint8;

    /* SignalConversion: '<S113>/OutportBufferForswitchLaneFlg_BOOL' */
    RobotControl_B.OutportBufferForswitchLaneFlg_k =
      RobotControl_B.switchLaneFlg_BOOL;

    /* SignalConversion: '<S113>/OutportBufferForzgzgActive' */
    RobotControl_B.OutportBufferForzgzgActive = RobotControl_B.zgzgActive;

    /* End of Outputs for SubSystem: '<S27>/zigzagRoutine' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S27>/StartPointRoutine' incorporates:
       *  SystemReset for ActionPort: '<S110>/GTSPActive'
       */
      /* SystemReset for SwitchCase: '<S112>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S110>/GTSP_Chart'
       */
      RobotControl_DW.is_GTSP_Active = 0U;
      RobotControl_DW.is_MostSouthLeft = 0U;
      RobotControl_DW.is_facingSouth = 0U;
      RobotControl_DW.is_GTSPsearch = 0U;
      RobotControl_DW.is_faceWest = 0U;
      RobotControl_DW.is_active_c32_RobotControl = 0U;
      RobotControl_DW.is_c32_RobotControl = 0U;
      RobotControl_DW.counter = 0U;
      RobotControl_DW.round = 0U;
      RobotControl_DW.step1Flag = 0U;
      RobotControl_DW.initHeading_i = false;
      RobotControl_DW.activeFlag = false;
      RobotControl_DW.tempDist_l = 0.0F;
      RobotControl_B.moveRequest_l = 0U;
      RobotControl_B.GT_active = true;

      /* End of SystemReset for SubSystem: '<S27>/StartPointRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S27>/StartPointRoutine' incorporates:
     *  ActionPort: '<S110>/GTSPActive'
     */
    /* DataTypeConversion: '<S110>/Data Type Conversion' */
    DataTypeConversion2_m = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S110>/Data Type Conversion1' */
    DataTypeConversion3_g = RobotControl_B.ROB_SOUTH;

    /* DataTypeConversion: '<S110>/Data Type Conversion2' */
    DataTypeConversion4 = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S110>/Data Type Conversion3' */
    DataTypeConversion3 = RobotControl_B.ROB_EAST;

    /* Chart: '<S110>/GTSP_Chart' incorporates:
     *  TriggerPort: '<S140>/input events'
     */
    zcEvent_idx_0 = (((RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] == POS_ZCSIG)
                      != (int16_T)RobotControl_B.refreshEvent) &&
                     (RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] !=
                      UNINITIALIZED_ZCSIG));
    zcEvent_idx_1 = (((RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] == POS_ZCSIG)
                      != (int16_T)RobotControl_B.stopEvent) &&
                     (RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] !=
                      UNINITIALIZED_ZCSIG));
    if (zcEvent_idx_0 || zcEvent_idx_1) {
      /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/StartPointRoutine/GTSP_Chart */
      if ((int8_T)(zcEvent_idx_0 ? RobotControl_B.refreshEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S140>:146' */
        RobotControl_DW.sfEvent = RobotContr_event_refreshEvent_o;
        Robo_chartstep_c32_RobotControl(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4, &DataTypeConversion3);
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S140>:145' */
        RobotControl_DW.sfEvent = RobotControl_event_stopEvent_k;
        Robo_chartstep_c32_RobotControl(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4, &DataTypeConversion3);
      }
    }

    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S110>/OutportBufferForGT_active' */
    RobotControl_B.OutportBufferForGT_active = RobotControl_B.GT_active;

    /* SignalConversion: '<S110>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_l;

    /* End of Outputs for SubSystem: '<S27>/StartPointRoutine' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S27>/DIAG_Routine' incorporates:
     *  ActionPort: '<S105>/DIAG_Active'
     */
    /* Outputs for Atomic SubSystem: '<S105>/Diag_Routine_Variant' */
#if motorsHandleEOL_Variant

    /* Output and update for atomic system: '<S114>/Diag_Routine_Disabled' */

    /* Constant: '<S115>/ENU_STOP' */
    RobotControl_B.Merge = ((uint8_T)ENU_STOP);

    /* Constant: '<S115>/CONST_NORTH_DISABLED' */
    RobotControl_B.VariantMergeForOutportangleCa_g = CONST_NORTH_DISABLED;

    /* Constant: '<S115>/CONST_SOUTH_DISABLED' */
    RobotControl_B.VariantMergeForOutportangleCa_a = CONST_SOUTH_DISABLED;

    /* Constant: '<S115>/CONST_EAST_DISABLED' */
    RobotControl_B.VariantMergeForOutportangleCali = CONST_EAST_DISABLED;

    /* Constant: '<S115>/CONST_WEST_DISABLED' */
    RobotControl_B.VariantMergeForOutportangleC_a1 = CONST_WEST_DISABLED;

    /* Constant: '<S115>/CONST_DIAG_UNCONFIRM' */
    RobotControl_B.VariantMergeForOutportDIAG_Stat = ((uint8_T)
      CONST_DIAG_UNCONFIRM);

    /* Constant: '<S115>/ENU_TEST_NOT_CONFIRMED' */
    RobotControl_B.VariantMergeForOutportangleCa_h = ((uint8_T)
      ENU_TEST_NOT_CONFIRMED);

    /* Constant: '<S115>/CONST_ENABLE_ANGLE_CALIB_DISABLED' */
    RobotControl_B.VariantMergeForOutportenableAng =
      CONST_ENABLE_ANGLE_CALIB_DISABLED;

    /* Constant: '<S115>/ENU_TEST_NOT_CONFIRMED2' */
    RobotControl_B.VariantMergeForOutportcomTstSta = ((uint8_T)
      ENU_TEST_NOT_CONFIRMED);

    /* Constant: '<S115>/CONST_COMP_FLT_DISABLED' */
    RobotControl_B.VariantMergeForOutportcompFault = CONST_COMP_FLT_DISABLED;

    /* Constant: '<S115>/CONST_R_ENCOD_DISABLED' */
    RobotControl_B.VariantMergeForOutportrightEnco = CONST_R_ENCOD_DISABLED;

    /* Constant: '<S115>/CONST_L_ENCOD_DISABLED' */
    RobotControl_B.VariantMergeForOutportleftEncod = CONST_L_ENCOD_DISABLED;

#elif MotorsEOL_DisabledVariant

    /* Outputs for atomic system: '<S114>/Diag_Routine_Enabled' */
    {
      real32_T rtb_quarterTurnTargetDist_mm;
      int8_T rtPrevAction_o;
      int8_T rtAction_o;
      int16_T encodCurrentHeading_o;
      real32_T DataTypeConversion3_o;
      real32_T DataTypeConversion4_o;
      real32_T DataTypeConversion5_o;

      /* Chart: '<S136>/HighLevelDiagTestControl' incorporates:
       *  Constant: '<S116>/ENU_PASSED'
       *  UnitDelay: '<S116>/Unit_Delay'
       *  UnitDelay: '<S116>/Unit_Delay1'
       *  UnitDelay: '<S116>/Unit_Delay2'
       */
      /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k < 15U) {
        RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k++;
      }

      /* During: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      /* Highest level of state machine. Decides which state it should operate currently */
      if (RobotControl_DW.Diag_Routine_Enabled.is_active_c44_RobotControl == 0U)
      {
        /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
        RobotControl_DW.Diag_Routine_Enabled.is_active_c44_RobotControl = 1U;

        /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
        /* Transition: '<S137>:54' */
        if (!RobotControl_B.NVM_AngleStoreFlg) {
          /* Transition: '<S137>:52' */
          RobotControl_B.VariantMergeForOutportenableAng = true;
          RobotControl_DW.Diag_Routine_Enabled.is_c44_RobotControl =
            RobotControl_IN_AngleCalib;

          /* Entry 'AngleCalib': '<S137>:50' */
          RobotControl_B.Diag_Routine_Enabled.diagEnableReq =
            RobotContr_ENU_DIAG_ANGLE_CALIB;
        } else {
          /* Transition: '<S137>:53' */
          RobotControl_DW.Diag_Routine_Enabled.is_c44_RobotControl =
            RobotControl_IN_SelfDiag;

          /* Entry Internal 'SelfDiag': '<S137>:49' */
          /* Transition: '<S137>:3' */
          RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
            RobotControl_IN_CompassRoutine;
          RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k = 0U;
        }
      } else if (RobotControl_DW.Diag_Routine_Enabled.is_c44_RobotControl ==
                 RobotControl_IN_AngleCalib) {
        /* During 'AngleCalib': '<S137>:50' */
        if (RobotControl_DW.Diag_Routine_Enabled.Unit_Delay2_DSTATE ==
            RobotControl_ENU_FINISHED) {
          /* Transition: '<S137>:55' */
          RobotControl_B.VariantMergeForOutportenableAng = false;
          RobotControl_DW.Diag_Routine_Enabled.is_c44_RobotControl =
            RobotControl_IN_SelfDiag;

          /* Entry Internal 'SelfDiag': '<S137>:49' */
          /* Transition: '<S137>:3' */
          RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
            RobotControl_IN_CompassRoutine;
          RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k = 0U;
        }
      } else {
        /* During 'SelfDiag': '<S137>:49' */
        switch (RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag) {
         case RobotControl_IN_BlueTooth:
          /* During 'BlueTooth': '<S137>:8' */
          if (((uint8_T)ENU_PASSED) == RobotControl_ENU_FAILED) {
            /* Transition: '<S137>:19' */
            RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
              RobotControl_IN_Failed;

            /* Entry 'Failed': '<S137>:14' */
          } else {
            if (((uint8_T)ENU_PASSED) == RobotControl_ENU_PASSED) {
              /* Transition: '<S137>:43' */
              RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
                RobotContro_IN_SelfDiagComplete;

              /* Entry 'SelfDiagComplete': '<S137>:46' */
              RobotControl_B.Diag_Routine_Enabled.diagEnableReq =
                RobotControl_ENU_DIAG_NONE;
              RobotControl_B.VariantMergeForOutportDIAG_Stat = ((uint8_T)
                CONST_DIAG_FINISH_FLG);
            }
          }
          break;

         case RobotControl_IN_CompassRoutine:
          /* During 'CompassRoutine': '<S137>:4' */
          if (RobotControl_DW.Diag_Routine_Enabled.Unit_Delay_DSTATE ==
              RobotControl_ENU_PASSED) {
            /* Transition: '<S137>:9' */
            RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
              RobotControl_IN_EncoderRoutine;

            /* Entry 'EncoderRoutine': '<S137>:5' */
            RobotControl_B.Diag_Routine_Enabled.diagEnableReq =
              RobotControl_ENU_DIAG_ENCOD;
          } else if (RobotControl_DW.Diag_Routine_Enabled.Unit_Delay_DSTATE ==
                     RobotControl_ENU_FAILED) {
            /* Transition: '<S137>:15' */
            RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
              RobotControl_IN_Failed;

            /* Entry 'Failed': '<S137>:14' */
          } else {
            if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1_k >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              RobotControl_B.Diag_Routine_Enabled.diagEnableReq =
                RobotControl_ENU_DIAG_COMP;
            }
          }
          break;

         case RobotControl_IN_EncoderRoutine:
          /* During 'EncoderRoutine': '<S137>:5' */
          if (RobotControl_DW.Diag_Routine_Enabled.Unit_Delay1_DSTATE ==
              RobotControl_ENU_FAILED) {
            /* Transition: '<S137>:16' */
            RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
              RobotControl_IN_Failed;

            /* Entry 'Failed': '<S137>:14' */
          } else {
            if (RobotControl_DW.Diag_Routine_Enabled.Unit_Delay1_DSTATE ==
                RobotControl_ENU_PASSED) {
              /* Transition: '<S137>:10' */
              RobotControl_DW.Diag_Routine_Enabled.is_SelfDiag =
                RobotControl_IN_BlueTooth;

              /* Entry 'BlueTooth': '<S137>:8' */
              RobotControl_B.Diag_Routine_Enabled.diagEnableReq =
                RobotControl_ENU_DIAG_BLTOTH;
            }
          }
          break;

         case RobotControl_IN_Failed:
          /* During 'Failed': '<S137>:14' */
          break;

         default:
          /* During 'SelfDiagComplete': '<S137>:46' */
          break;
        }
      }

      /* End of Chart: '<S136>/HighLevelDiagTestControl' */

      /* Product: '<S123>/Product' incorporates:
       *  Constant: '<S123>/CAL_Wheel2WheelDist_mm'
       *  Constant: '<S123>/CONST_PI_F32'
       *  Constant: '<S123>/CONST_TWO_F32'
       *  Constant: '<S123>/CONST_TWO_F321'
       *  Product: '<S123>/Divide'
       *  Product: '<S123>/Divide1'
       */
      rtb_quarterTurnTargetDist_mm = CONST_PI_F32 / CONST_TWO_F32 * ((real32_T)
        CAL_Wheel2WheelDist_mm / CONST_TWO_F32);

      /* SwitchCase: '<S121>/Switch_Case' incorporates:
       *  Logic: '<S117>/Logical_Operator'
       */
      rtPrevAction_o =
        RobotControl_DW.Diag_Routine_Enabled.Switch_Case_ActiveSubsystem;
      switch ((int32_T)RobotControl_B.Diag_Routine_Enabled.diagEnableReq) {
       case 1L:
        rtAction_o = 0;
        break;

       case 2L:
        rtAction_o = 1;
        break;

       case 5L:
        rtAction_o = 2;
        break;

       case 6L:
        rtAction_o = 3;
        break;

       default:
        rtAction_o = 4;
        break;
      }

      RobotControl_DW.Diag_Routine_Enabled.Switch_Case_ActiveSubsystem =
        rtAction_o;

      /* Disable for Enabled SubSystem: '<S117>/Angle_CalibrationUponReq' */
      if ((rtPrevAction_o != rtAction_o) && (rtPrevAction_o == 3) &&
          RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE) {
        RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE =
          false;
      }

      /* End of Disable for SubSystem: '<S117>/Angle_CalibrationUponReq' */
      switch (rtAction_o) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S116>/CompassTest' incorporates:
         *  ActionPort: '<S119>/CompassTest'
         */
        /* DataTypeConversion: '<S126>/Data Type Conversion1' */
        rtb_quarterTurnTargetDist_mm = RobotControl_B.ROB_EAST;

        /* DataTypeConversion: '<S126>/Data Type Conversion3' */
        DataTypeConversion3_o = RobotControl_B.ROB_NORTH;

        /* DataTypeConversion: '<S126>/Data Type Conversion4' */
        DataTypeConversion4_o = RobotControl_B.ROB_SOUTH;

        /* DataTypeConversion: '<S126>/Data Type Conversion5' */
        DataTypeConversion5_o = RobotControl_B.ROB_WEST;

        /* Chart: '<S127>/EncoderHeadingHandler' */
        /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/encoderHeading/EncoderHeadingHandler */
        /* During: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/encoderHeading/EncoderHeadingHandler */
        /* calculates the encoder current heading */
        /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/encoderHeading/EncoderHeadingHandler */
        /* Transition: '<S129>:55' */
        if ((rtb_thetaEncod <= 280.0F) && (rtb_thetaEncod >= 260.0F)) {
          /* Transition: '<S129>:46' */
          /* NORTH */
          /* Transition: '<S129>:50' */
          encodCurrentHeading_o = (int16_T)270.0F;

          /* Transition: '<S129>:43' */
          /* Transition: '<S129>:41' */
          /* Transition: '<S129>:54' */
          /* Transition: '<S129>:42' */
        } else {
          /* Transition: '<S129>:51' */
          if ((rtb_thetaEncod <= 100.0F) && (rtb_thetaEncod >= 80.0F)) {
            /* Transition: '<S129>:62' */
            /* SOUTH */
            /* Transition: '<S129>:53' */
            encodCurrentHeading_o = (int16_T)90.0F;

            /* Transition: '<S129>:41' */
            /* Transition: '<S129>:54' */
            /* Transition: '<S129>:42' */
          } else {
            /* Transition: '<S129>:52' */
            if ((rtb_thetaEncod <= RobotCont_CAL_ROB_ERRVAL_ENCODE) ||
                (rtb_thetaEncod >= 350.0F)) {
              /* Transition: '<S129>:59' */
              /* EAST */
              /* Transition: '<S129>:63' */
              encodCurrentHeading_o = (int16_T)0.0F;

              /* Transition: '<S129>:54' */
              /* Transition: '<S129>:42' */
            } else {
              /* Transition: '<S129>:45' */
              if ((rtb_thetaEncod <= 190.0F) && (rtb_thetaEncod >= 170.0F)) {
                /* Transition: '<S129>:60' */
                /* WEST */
                /* Transition: '<S129>:40' */
                encodCurrentHeading_o = (int16_T)180.0F;

                /* Transition: '<S129>:42' */
              } else {
                /* Transition: '<S129>:39' */
                encodCurrentHeading_o = (int16_T)400.0F;
              }
            }
          }
        }

        /* End of Chart: '<S127>/EncoderHeadingHandler' */

        /* Chart: '<S126>/CompassSelfDiagTestChart' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion1'
         *  DataTypeConversion: '<S126>/Data Type Conversion3'
         *  DataTypeConversion: '<S126>/Data Type Conversion4'
         *  DataTypeConversion: '<S126>/Data Type Conversion5'
         */
        /* Transition: '<S129>:65' */
        /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        /* During: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        /* chart handles the logic to test the compass and how it works before. we proceed with the area coverage */
        if (RobotControl_DW.Diag_Routine_Enabled.is_active_c40_RobotControl ==
            0U) {
          /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
          RobotControl_DW.Diag_Routine_Enabled.is_active_c40_RobotControl = 1U;

          /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
          /* Transition: '<S128>:2' */
          RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
            RobotControl_IN_init;

          /* Entry 'init': '<S128>:1' */
          RobotControl_B.VariantMergeForOutportcomTstSta =
            RobotControl_ENU_TEST_INIT;
          RobotControl_B.Diag_Routine_Enabled.moveReq_p =
            RobotControl_ENU_STOP_k;
          RobotControl_DW.Diag_Routine_Enabled.steps = 0U;
          RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt = 0U;
        } else {
          switch (RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl) {
           case RobotControl_IN_DiagPassed:
            /* During 'DiagPassed': '<S128>:8' */
            break;

           case RobotControl_IN_init:
            /* During 'init': '<S128>:1' */
            if ((RobotControl_B.currentHeading != RobotControl_ENU_ROB_NONE) &&
                RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S128>:4' */
              RobotControl_DW.Diag_Routine_Enabled.startHeading =
                RobotControl_B.currentHeading;
              RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
                RobotControl_IN_turnHandler;
              RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                RobotControl_IN_Stop;

              /* Entry 'Stop': '<S128>:5' */
              RobotControl_B.VariantMergeForOutportcomTstSta =
                RobotCon_ENU_TEST_NOT_CONFIRMED;
              RobotControl_B.Diag_Routine_Enabled.moveReq_p =
                RobotControl_ENU_STOP_k;
            }
            break;

           case RobotControl_IN_turnHandler:
            /* During 'turnHandler': '<S128>:43' */
            if ((RobotControl_DW.Diag_Routine_Enabled.steps > 0) &&
                RobotControl_B.OutportBufferFortargetReached &&
                (RobotControl_B.currentHeading != (uint16_T)
                 encodCurrentHeading_o) &&
                (RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt >
                 RobotCont_CONST_ERROR_TOLERANCE)) {
              /* Transition: '<S128>:44' */
              /* Exit Internal 'turnHandler': '<S128>:43' */
              RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                RobotContr_IN_NO_ACTIVE_CHILD_a;
              RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
                RobotControl_IN_turnRightFault;

              /* Entry 'turnRightFault': '<S128>:7' */
              RobotControl_B.VariantMergeForOutportcompFault = true;
              RobotControl_B.VariantMergeForOutportcomTstSta =
                RobotControl_ENU_FAILED;
            } else {
              switch (RobotControl_DW.Diag_Routine_Enabled.is_turnHandler) {
               case RobotControl_IN_Stop:
                /* During 'Stop': '<S128>:5' */
                if (RobotControl_DW.Diag_Routine_Enabled.steps == 0) {
                  /* Transition: '<S128>:38' */
                  RobotControl_DW.Diag_Routine_Enabled.steps++;
                  RobotControl_B.Diag_Routine_Enabled.moveReq_p =
                    RobotContro_ENU_MOVE_TURN_RIGHT;
                  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                    RobotControl_IN_turnRight;
                } else if (RobotControl_directionCheck((real_T)
                            RobotControl_DW.Diag_Routine_Enabled.startHeading,
                            (real_T)encodCurrentHeading_o, (real_T)
                            RobotControl_CAL_NORTH, 0.0, (real_T)
                            RobotControl_CAL_SOUTH, (real_T)
                            RobotControl_CAL_WEST, (real_T)encodCurrentHeading_o,
                            &rtb_quarterTurnTargetDist_mm,
                            &DataTypeConversion3_o, &DataTypeConversion4_o,
                            &DataTypeConversion5_o) != 0.0) {
                  /* Transition: '<S128>:9' */
                  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                    RobotContr_IN_NO_ACTIVE_CHILD_a;
                  RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
                    RobotControl_IN_DiagPassed;

                  /* Entry 'DiagPassed': '<S128>:8' */
                  RobotControl_B.VariantMergeForOutportcompFault = false;
                  RobotControl_B.VariantMergeForOutportcomTstSta =
                    RobotControl_ENU_PASSED;
                } else if (RobotControl_DW.Diag_Routine_Enabled.steps == 1) {
                  /* Transition: '<S128>:39' */
                  RobotControl_DW.Diag_Routine_Enabled.steps++;
                  RobotControl_B.Diag_Routine_Enabled.moveReq_p =
                    RobotControl_ENU_MOVE_TURN_LEFT;
                  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                    RobotControl_IN_turnLeft;
                } else {
                  if ((RobotControl_DW.Diag_Routine_Enabled.steps == 2) &&
                      RobotControl_B.OutportBufferFortargetReached && ((uint16_T)
                       encodCurrentHeading_o != RobotControl_B.currentHeading))
                  {
                    /* Transition: '<S128>:123' */
                    RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                      RobotContr_IN_NO_ACTIVE_CHILD_a;
                    RobotControl_DW.Diag_Routine_Enabled.is_c40_RobotControl =
                      RobotControl_IN_turnRightFault;

                    /* Entry 'turnRightFault': '<S128>:7' */
                    RobotControl_B.VariantMergeForOutportcompFault = true;
                    RobotControl_B.VariantMergeForOutportcomTstSta =
                      RobotControl_ENU_FAILED;
                  }
                }
                break;

               case RobotControl_IN_turnLeft:
                /* During 'turnLeft': '<S128>:35' */
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_directionCheck((real_T)
                      RobotControl_DW.Diag_Routine_Enabled.startHeading, (real_T)
                      RobotControl_B.currentHeading, (real_T)
                      RobotControl_B.ROB_NORTH, (real_T)RobotControl_B.ROB_EAST,
                      (real_T)RobotControl_B.ROB_SOUTH, (real_T)
                      RobotControl_B.ROB_WEST, (real_T)encodCurrentHeading_o,
                      &rtb_quarterTurnTargetDist_mm, &DataTypeConversion3_o,
                      &DataTypeConversion4_o, &DataTypeConversion5_o) != 0.0)) {
                  /* Transition: '<S128>:36' */
                  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                    RobotControl_IN_Stop;

                  /* Entry 'Stop': '<S128>:5' */
                  RobotControl_B.VariantMergeForOutportcomTstSta =
                    RobotCon_ENU_TEST_NOT_CONFIRMED;
                  RobotControl_B.Diag_Routine_Enabled.moveReq_p =
                    RobotControl_ENU_STOP_k;
                } else {
                  if (RobotControl_B.OutportBufferFortargetReached &&
                      (RobotControl_B.currentHeading != (uint16_T)
                       encodCurrentHeading_o)) {
                    /* Transition: '<S128>:114' */
                    RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt++;
                    RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                      RobotControl_IN_turnLeft;
                  }
                }
                break;

               default:
                /* During 'turnRight': '<S128>:3' */
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_directionCheck((real_T)
                      RobotControl_DW.Diag_Routine_Enabled.startHeading, (real_T)
                      RobotControl_B.currentHeading, (real_T)
                      RobotControl_B.ROB_EAST, (real_T)RobotControl_B.ROB_SOUTH,
                      (real_T)RobotControl_B.ROB_WEST, (real_T)
                      RobotControl_B.ROB_NORTH, (real_T)encodCurrentHeading_o,
                      &rtb_quarterTurnTargetDist_mm, &DataTypeConversion3_o,
                      &DataTypeConversion4_o, &DataTypeConversion5_o) != 0.0)) {
                  /* Transition: '<S128>:6' */
                  RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt = 0U;
                  RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                    RobotControl_IN_Stop;

                  /* Entry 'Stop': '<S128>:5' */
                  RobotControl_B.VariantMergeForOutportcomTstSta =
                    RobotCon_ENU_TEST_NOT_CONFIRMED;
                  RobotControl_B.Diag_Routine_Enabled.moveReq_p =
                    RobotControl_ENU_STOP_k;
                } else {
                  if (RobotControl_B.OutportBufferFortargetReached &&
                      (RobotControl_B.currentHeading != (uint16_T)
                       encodCurrentHeading_o)) {
                    /* Transition: '<S128>:112' */
                    /* moveReq = ENU_STOP; */
                    RobotControl_DW.Diag_Routine_Enabled.filterToleranceCnt++;
                    RobotControl_DW.Diag_Routine_Enabled.is_turnHandler =
                      RobotControl_IN_turnRight;
                  }
                }
                break;
              }
            }
            break;

           default:
            /* During 'turnRightFault': '<S128>:7' */
            break;
          }
        }

        /* End of Chart: '<S126>/CompassSelfDiagTestChart' */

        /* SignalConversion: '<S119>/OutportBufferFormoveRequest' */
        RobotControl_B.Merge = RobotControl_B.Diag_Routine_Enabled.moveReq_p;

        /* End of Outputs for SubSystem: '<S116>/CompassTest' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S116>/EncoderTest' incorporates:
         *  ActionPort: '<S120>/EncoderTest'
         */
        /* SignalConversion: '<S120>/OutportBufferFormoveRequest' incorporates:
         *  Constant: '<S120>/ENU_MOVE_TURN_LEFT'
         */
        RobotControl_B.Merge = ((uint8_T)ENU_MOVE_TURN_LEFT);

        /* Chart: '<S132>/DeltaDistCalculator' */
        RobotContro_DeltaDistCalculator
          (RobotControl_B.OutportBufferFortargetReached,
           RobotControl_B.Data_Type_Conversion_m,
           &RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator,
           &RobotControl_DW.Diag_Routine_Enabled.sf_DeltaDistCalculator);

        /* Logic: '<S130>/Logical_Operator' incorporates:
         *  Abs: '<S130>/Abs'
         *  Constant: '<S130>/CONST_MinDistError_mm'
         *  DataTypeConversion: '<S130>/Data_Type_Conversion'
         *  RelationalOperator: '<S130>/Relational_Operator'
         *  Sum: '<S130>/Subtract'
         */
        RobotControl_B.VariantMergeForOutportleftEncod =
          (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
            (RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator.deltaDistTrav)
            - rtb_quarterTurnTargetDist_mm > CONST_MinDistError_mm));

        /* Chart: '<S134>/DeltaDistCalculator' */
        RobotContro_DeltaDistCalculator
          (RobotControl_B.OutportBufferFortargetReached,
           RobotControl_B.Data_Type_Conversion,
           &RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator_c,
           &RobotControl_DW.Diag_Routine_Enabled.sf_DeltaDistCalculator_c);

        /* Logic: '<S131>/Logical_Operator' incorporates:
         *  Abs: '<S131>/Abs'
         *  Constant: '<S131>/CONST_MinDistError_mm'
         *  DataTypeConversion: '<S131>/Data_Type_Conversion'
         *  RelationalOperator: '<S131>/Relational_Operator'
         *  Sum: '<S131>/Subtract'
         */
        RobotControl_B.VariantMergeForOutportrightEnco =
          (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
            (RobotControl_B.Diag_Routine_Enabled.sf_DeltaDistCalculator_c.deltaDistTrav)
            - rtb_quarterTurnTargetDist_mm > CONST_MinDistError_mm));

        /* Switch: '<S120>/Switch' incorporates:
         *  Constant: '<S120>/ENU_FAILED'
         *  Constant: '<S120>/ENU_TEST_NOT_CONFIRMED'
         *  Logic: '<S120>/Logical_Operator'
         *  Logic: '<S120>/Logical_Operator1'
         *  Switch: '<S120>/Switch1'
         */
        if ((RobotControl_B.VariantMergeForOutportleftEncod ||
             RobotControl_B.VariantMergeForOutportrightEnco) &&
            RobotControl_B.OutportBufferFortargetReached) {
          RobotControl_B.Diag_Routine_Enabled.encoderTstStatus = ((uint8_T)
            ENU_FAILED);
        } else if (RobotControl_B.OutportBufferFortargetReached) {
          /* Switch: '<S120>/Switch1' incorporates:
           *  Constant: '<S120>/ENU_PASSED'
           */
          RobotControl_B.Diag_Routine_Enabled.encoderTstStatus = ((uint8_T)
            ENU_PASSED);
        } else {
          RobotControl_B.Diag_Routine_Enabled.encoderTstStatus = ((uint8_T)
            ENU_TEST_NOT_CONFIRMED);
        }

        /* End of Switch: '<S120>/Switch' */
        /* End of Outputs for SubSystem: '<S116>/EncoderTest' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S116>/Bluetooth' incorporates:
         *  ActionPort: '<S118>/Bluetooth'
         */
        /* SignalConversion: '<S118>/OutportBufferFormoveRequest' incorporates:
         *  Constant: '<S118>/ENU_STOP'
         */
        RobotControl_B.Merge = ((uint8_T)ENU_STOP);

        /* End of Outputs for SubSystem: '<S116>/Bluetooth' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S116>/Angle_Calibration' incorporates:
         *  ActionPort: '<S117>/Angle_Calibration'
         */
        /* Outputs for Enabled SubSystem: '<S117>/Angle_CalibrationUponReq' incorporates:
         *  EnablePort: '<S124>/NVM_AngleStoreFlgEnable'
         */
        if (!RobotControl_B.NVM_AngleStoreFlg) {
          if (!RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE)
          {
            /* SystemReset for Chart: '<S124>/CompassSelfDiagTestChart' */
            RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;
            RobotControl_DW.Diag_Routine_Enabled.is_active_c39_RobotControl = 0U;
            RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
              RobotContr_IN_NO_ACTIVE_CHILD_a;
            RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = false;
            RobotControl_B.Diag_Routine_Enabled.moveReq = 0U;
            RobotControl_B.Diag_Routine_Enabled.NORTH = 0U;
            RobotControl_B.Diag_Routine_Enabled.SOUTH = 0U;
            RobotControl_B.Diag_Routine_Enabled.EAST = 0U;
            RobotControl_B.Diag_Routine_Enabled.WEST = 0U;
            RobotControl_B.Diag_Routine_Enabled.angleCalibStatus = 3U;
            RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE =
              true;
          }

          /* Chart: '<S124>/CompassSelfDiagTestChart' */
          /* Gateway: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 < 15U) {
            RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1++;
          }

          /* During: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          /* Calibrates 4 direction angles. it stores the specific number coming from compass depending on the encoder calculation of angle */
          if (RobotControl_DW.Diag_Routine_Enabled.is_active_c39_RobotControl ==
              0U) {
            /* Entry: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
            RobotControl_DW.Diag_Routine_Enabled.is_active_c39_RobotControl = 1U;

            /* Entry Internal: RobotControl/RobotControlLib/HighLevelRoutines/DIAG_Routine/Diag_Routine_Variant/Diag_Routine_Enabled/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
            /* Transition: '<S125>:2' */
            RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
              RobotControl_IN_initFacingNorth;

            /* Entry 'initFacingNorth': '<S125>:1' */
            RobotControl_B.Diag_Routine_Enabled.NORTH = (uint16_T)
              RobotControl_B.rawCompassValue;
            RobotControl_B.Diag_Routine_Enabled.moveReq =
              RobotControl_ENU_STOP_k;
            RobotControl_B.Diag_Routine_Enabled.angleCalibStatus =
              RobotCon_ENU_TEST_NOT_CONFIRMED;
            RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = false;
          } else {
            switch (RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl) {
             case RobotControl_IN_FacingEAST:
              /* During 'FacingEAST': '<S125>:38' */
              if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 >=
                  Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
                /* Transition: '<S125>:40' */
                RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = true;
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_Moving;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'Moving': '<S125>:36' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotContro_ENU_MOVE_TURN_RIGHT;
              }
              break;

             case RobotControl_IN_FacingSOUTH:
              /* During 'FacingSOUTH': '<S125>:41' */
              if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 >=
                  Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
                /* Transition: '<S125>:43' */
                RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = false;
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_Moving;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'Moving': '<S125>:36' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotContro_ENU_MOVE_TURN_RIGHT;
              }
              break;

             case RobotControl_IN_FacingWEST:
              /* During 'FacingWEST': '<S125>:44' */
              if (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 >=
                  Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
                /* Transition: '<S125>:61' */
                RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg = true;
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_Moving;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'Moving': '<S125>:36' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotContro_ENU_MOVE_TURN_RIGHT;
              }
              break;

             case RobotControl_IN_Moving:
              /* During 'Moving': '<S125>:36' */
              if ((RobotControl_B.currentHeading == RobotControl_CAL_EAST) &&
                  (!RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg) &&
                  RobotControl_B.OutportBufferFortargetReached) {
                /* Transition: '<S125>:39' */
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_FacingEAST;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'FacingEAST': '<S125>:38' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotControl_ENU_STOP_k;
                RobotControl_B.Diag_Routine_Enabled.EAST = (uint16_T)
                  RobotControl_B.rawCompassValue;
              } else if ((RobotControl_B.currentHeading ==
                          RobotControl_CAL_SOUTH) &&
                         RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg &&
                         RobotControl_B.OutportBufferFortargetReached) {
                /* Transition: '<S125>:42' */
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_FacingSOUTH;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'FacingSOUTH': '<S125>:41' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotControl_ENU_STOP_k;
                RobotControl_B.Diag_Routine_Enabled.SOUTH = (uint16_T)
                  RobotControl_B.rawCompassValue;
              } else if ((RobotControl_B.currentHeading == RobotControl_CAL_WEST)
                         &&
                         (!RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg) &&
                         RobotControl_B.OutportBufferFortargetReached) {
                /* Transition: '<S125>:45' */
                RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                  RobotControl_IN_FacingWEST;
                RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

                /* Entry 'FacingWEST': '<S125>:44' */
                RobotControl_B.Diag_Routine_Enabled.moveReq =
                  RobotControl_ENU_STOP_k;
                RobotControl_B.Diag_Routine_Enabled.WEST = (uint16_T)
                  RobotControl_B.rawCompassValue;
              } else {
                if ((RobotControl_B.currentHeading == RobotControl_CAL_NORTH) &&
                    RobotControl_DW.Diag_Routine_Enabled.angleFinishFlg &&
                    RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 >=
                     Ro_CONST_COMPASS_DIAG_FIN_TIMER)) {
                  /* Transition: '<S125>:59' */
                  RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                    RobotContr_IN_finishFacingNorth;

                  /* Entry 'finishFacingNorth': '<S125>:60' */
                  RobotControl_B.Diag_Routine_Enabled.moveReq =
                    RobotControl_ENU_STOP_k;
                  RobotControl_B.Diag_Routine_Enabled.angleCalibStatus =
                    RobotControl_ENU_FINISHED;
                }
              }
              break;

             case RobotContr_IN_finishFacingNorth:
              /* During 'finishFacingNorth': '<S125>:60' */
              break;

             default:
              /* During 'initFacingNorth': '<S125>:1' */
              /* Transition: '<S125>:37' */
              RobotControl_DW.Diag_Routine_Enabled.is_c39_RobotControl =
                RobotControl_IN_Moving;
              RobotControl_DW.Diag_Routine_Enabled.temporalCounter_i1 = 0U;

              /* Entry 'Moving': '<S125>:36' */
              RobotControl_B.Diag_Routine_Enabled.moveReq =
                RobotContro_ENU_MOVE_TURN_RIGHT;
              break;
            }
          }

          /* End of Chart: '<S124>/CompassSelfDiagTestChart' */

          /* SignalConversion: '<S124>/OutportBufferForangleCalibStatus' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalibStatu =
            RobotControl_B.Diag_Routine_Enabled.angleCalibStatus;

          /* SignalConversion: '<S124>/OutportBufferForangleCalib_EAST' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_EAST =
            RobotControl_B.Diag_Routine_Enabled.EAST;

          /* SignalConversion: '<S124>/OutportBufferForangleCalib_NORTH' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_NORT =
            RobotControl_B.Diag_Routine_Enabled.NORTH;

          /* SignalConversion: '<S124>/OutportBufferForangleCalib_SOUTH' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_SOUT =
            RobotControl_B.Diag_Routine_Enabled.SOUTH;

          /* SignalConversion: '<S124>/OutportBufferForangleCalib_WEST' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_WEST =
            RobotControl_B.Diag_Routine_Enabled.WEST;

          /* SignalConversion: '<S124>/OutportBufferFormoveRequest' */
          RobotControl_B.Diag_Routine_Enabled.OutportBufferFormoveRequest =
            RobotControl_B.Diag_Routine_Enabled.moveReq;
        } else {
          if (RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE)
          {
            RobotControl_DW.Diag_Routine_Enabled.Angle_CalibrationUponReq_MODE =
              false;
          }
        }

        /* End of Outputs for SubSystem: '<S117>/Angle_CalibrationUponReq' */

        /* SignalConversion: '<S117>/OutportBufferForangleCalibStatus' incorporates:
         *  Logic: '<S117>/Logical_Operator'
         */
        RobotControl_B.VariantMergeForOutportangleCa_h =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalibStatu;

        /* SignalConversion: '<S117>/OutportBufferForangleCalib_EAST' */
        RobotControl_B.VariantMergeForOutportangleCali =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_EAST;

        /* SignalConversion: '<S117>/OutportBufferForangleCalib_NORTH' */
        RobotControl_B.VariantMergeForOutportangleCa_g =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_NORT;

        /* SignalConversion: '<S117>/OutportBufferForangleCalib_SOUTH' */
        RobotControl_B.VariantMergeForOutportangleCa_a =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_SOUT;

        /* SignalConversion: '<S117>/OutportBufferForangleCalib_WEST' */
        RobotControl_B.VariantMergeForOutportangleC_a1 =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferForangleCalib_WEST;

        /* SignalConversion: '<S117>/OutportBufferFormoveRequest' */
        RobotControl_B.Merge =
          RobotControl_B.Diag_Routine_Enabled.OutportBufferFormoveRequest;

        /* End of Outputs for SubSystem: '<S116>/Angle_Calibration' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S116>/None' incorporates:
         *  ActionPort: '<S122>/DefaultDiagCase'
         */
        /* SignalConversion: '<S122>/OutportBufferFormoveRequest' incorporates:
         *  Constant: '<S122>/ENU_STOP'
         */
        RobotControl_B.Merge = ((uint8_T)ENU_STOP);

        /* End of Outputs for SubSystem: '<S116>/None' */
        break;
      }

      /* End of SwitchCase: '<S121>/Switch_Case' */
    }

#endif                                 /* motorsHandleEOL_Variant */

    /* End of Outputs for SubSystem: '<S105>/Diag_Routine_Variant' */
    /* End of Outputs for SubSystem: '<S27>/DIAG_Routine' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S27>/End' incorporates:
     *  ActionPort: '<S107>/ENDactive'
     */
    /* DataTypeConversion: '<S107>/Data_Type_Conversion' incorporates:
     *  Constant: '<S107>/ENU_STOP'
     */
    RobotControl_B.Merge = ((uint8_T)ENU_STOP);

    /* End of Outputs for SubSystem: '<S27>/End' */
    break;
  }

  /* End of SwitchCase: '<S112>/Switch_Case' */

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_EAST' */
  RobotControl_B.OutportBufferForangleCalib_EAST =
    RobotControl_B.VariantMergeForOutportangleCali;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_NORTH' */
  RobotControl_B.OutportBufferForangleCalib_NORT =
    RobotControl_B.VariantMergeForOutportangleCa_g;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_SOUTH' */
  RobotControl_B.OutportBufferForangleCalib_SOUT =
    RobotControl_B.VariantMergeForOutportangleCa_a;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_WEST' */
  RobotControl_B.OutportBufferForangleCalib_WEST =
    RobotControl_B.VariantMergeForOutportangleC_a1;

  /* SignalConversion: '<S27>/OutportBufferForcompFaultFlag' */
  RobotControl_B.OutportBufferForcompFaultFlag =
    RobotControl_B.VariantMergeForOutportcompFault;

  /* SignalConversion: '<S27>/OutportBufferForswitchLaneFlg_BOOL' */
  RobotControl_B.OutportBufferForswitchLaneFlg_B =
    RobotControl_B.OutportBufferForswitchLaneFlg_k;

  /* Switch: '<S27>/Switch' */
  if (RobotControl_B.hitRoutineRun) {
    RobotControl_B.moveRequest = RobotControl_B.moveRequest_i;
  } else {
    RobotControl_B.moveRequest = RobotControl_B.Merge;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for UnitDelay: '<S27>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_h = RobotControl_B.OutportBufferForGT_active;

  /* Update for UnitDelay: '<S27>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE = RobotControl_B.OutportBufferForzgzgActive;

  /* Update for UnitDelay: '<S27>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_b =
    RobotControl_B.VariantMergeForOutportDIAG_Stat;

  /* Update for UnitDelay: '<S27>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE = RobotControl_B.Data_Type_Conversion_a;

  /* Update for SwitchCase: '<S112>/Switch_Case' */
  if (RobotControl_DW.Switch_Case_ActiveSubsystem == 2) {
    /* Update for IfAction SubSystem: '<S27>/DIAG_Routine' incorporates:
     *  Update for ActionPort: '<S105>/DIAG_Active'
     */
    /* Update for Atomic SubSystem: '<S105>/Diag_Routine_Variant' */
#if motorsHandleEOL_Variant

    /* No code for variant choice */
#elif MotorsEOL_DisabledVariant

    /* Update for atomic system: '<S114>/Diag_Routine_Enabled' */

    /* Update for UnitDelay: '<S116>/Unit_Delay1' */
    RobotControl_DW.Diag_Routine_Enabled.Unit_Delay1_DSTATE =
      RobotControl_B.Diag_Routine_Enabled.encoderTstStatus;

    /* Update for UnitDelay: '<S116>/Unit_Delay' */
    RobotControl_DW.Diag_Routine_Enabled.Unit_Delay_DSTATE =
      RobotControl_B.VariantMergeForOutportcomTstSta;

    /* Update for UnitDelay: '<S116>/Unit_Delay2' */
    RobotControl_DW.Diag_Routine_Enabled.Unit_Delay2_DSTATE =
      RobotControl_B.VariantMergeForOutportangleCa_h;

#endif                                 /* motorsHandleEOL_Variant */

    /* End of Update for SubSystem: '<S105>/Diag_Routine_Variant' */
    /* End of Update for SubSystem: '<S27>/DIAG_Routine' */
  }

  /* End of Update for SwitchCase: '<S112>/Switch_Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
