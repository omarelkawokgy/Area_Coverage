/*
 * Code generation for system system '<S16>/HighLevelRoutines'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "HighLevelRoutines.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S114>/DeltaDistCalculator' */
#define RobotContr_IN_NO_ACTIVE_CHILD_i ((uint8_T)0U)
#define RobotControl_IN_StartTurn      ((uint8_T)1U)
#define RobotControl_IN_targetReached  ((uint8_T)2U)

/* Named constants for Chart: '<S94>/MainStateMachine' */
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

/* Named constants for Chart: '<S98>/ZgZgChart' */
#define RobotContr_event_refreshEvent_p (0L)
#define RobotControl_CAL_ZgZgCounterThd ((uint8_T)2U)
#define RobotControl_ENU_ZIGZAG_m      ((uint8_T)0U)
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
#define RobotControl_MOVE_TURN_LEFT    ((uint8_T)20U)
#define RobotControl_MOVE_TURN_RIGHT   ((uint8_T)21U)
#define RobotControl_event_stopEvent_n (1L)

/* Named constants for Chart: '<S95>/GTSP_Chart' */
#define RobotC_IN_preFinishLeftBlockedN ((uint8_T)7U)
#define RobotC_IN_preFinishLeftBlockedW ((uint8_T)8U)
#define RobotContr_IN_preFinishBlockedN ((uint8_T)5U)
#define RobotContr_IN_preFinishBlockedW ((uint8_T)6U)
#define RobotControl_CAL_GTSPdelayStart ((uint8_T)200U)
#define RobotControl_CAL_ROBO_LENG_mm  (250U)
#define RobotControl_IN_End_p          ((uint8_T)1U)
#define RobotControl_IN_Forward        ((uint8_T)1U)
#define RobotControl_IN_Freeze1        ((uint8_T)3U)
#define RobotControl_IN_Freeze3        ((uint8_T)1U)
#define RobotControl_IN_Freeze4        ((uint8_T)2U)
#define RobotControl_IN_Freeze5        ((uint8_T)3U)
#define RobotControl_IN_Freeze6        ((uint8_T)4U)
#define RobotControl_IN_Freeze_j       ((uint8_T)2U)
#define RobotControl_IN_GTSP_Active    ((uint8_T)1U)
#define RobotControl_IN_GTSPsearch     ((uint8_T)5U)
#define RobotControl_IN_MostSouthLeft  ((uint8_T)3U)
#define RobotControl_IN_TurnLeft_e     ((uint8_T)3U)
#define RobotControl_IN_emptyOnRight   ((uint8_T)4U)
#define RobotControl_IN_faceWest_c     ((uint8_T)4U)
#define RobotControl_IN_facingSouth    ((uint8_T)1U)
#define RobotControl_IN_facingWest     ((uint8_T)5U)
#define RobotControl_IN_finish_j       ((uint8_T)2U)
#define RobotControl_IN_finishedGTSP   ((uint8_T)4U)
#define RobotControl_IN_furtherDown    ((uint8_T)6U)
#define RobotControl_IN_intermediate   ((uint8_T)7U)
#define RobotControl_IN_preFinishNormal ((uint8_T)9U)
#define RobotControl_IN_start_h        ((uint8_T)3U)
#define RobotControl_IN_start_hx       ((uint8_T)8U)

/* Named constants for Chart: '<S118>/HighLevelDiagTestControl' */
#define Ro_CONST_COMPASS_DIAG_FIN_TIMER ((uint8_T)10U)
#define RobotContr_ENU_DIAG_ANGLE_CALIB ((uint8_T)6U)
#define RobotContro_IN_SelfDiagComplete ((uint8_T)5U)
#define RobotControl_ENU_DIAG_BLTOTH   ((uint8_T)5U)
#define RobotControl_ENU_DIAG_COMP     ((uint8_T)1U)
#define RobotControl_ENU_DIAG_ENCOD    ((uint8_T)2U)
#define RobotControl_ENU_DIAG_NONE     ((uint8_T)7U)
#define RobotControl_ENU_FAILED        ((uint8_T)2U)
#define RobotControl_ENU_FINISHED_b    ((uint8_T)4U)
#define RobotControl_ENU_PASSED        ((uint8_T)1U)
#define RobotControl_IN_AngleCalib     ((uint8_T)1U)
#define RobotControl_IN_BlueTooth      ((uint8_T)1U)
#define RobotControl_IN_CompassRoutine ((uint8_T)2U)
#define RobotControl_IN_EncoderRoutine ((uint8_T)3U)
#define RobotControl_IN_Failed         ((uint8_T)4U)
#define RobotControl_IN_SelfDiag       ((uint8_T)2U)

/* Named constants for Chart: '<S108>/CompassSelfDiagTestChart' */
#define RobotCon_ENU_TEST_NOT_CONFIRMED ((uint8_T)3U)
#define RobotCont_CONST_ERROR_TOLERANCE ((uint8_T)15U)
#define RobotCont_ENU_MOVE_TURN_RIGHT_d ((uint8_T)21U)
#define RobotContr_ENU_MOVE_TURN_LEFT_l ((uint8_T)20U)
#define RobotControl_CAL_EAST          (0U)
#define RobotControl_CAL_NORTH         (270U)
#define RobotControl_CAL_SOUTH         (90U)
#define RobotControl_CAL_WEST          (180U)
#define RobotControl_ENU_ROB_NONE      (400U)
#define RobotControl_ENU_STOP_o        ((uint8_T)5U)
#define RobotControl_ENU_TEST_INIT     ((uint8_T)5U)
#define RobotControl_IN_DiagPassed     ((uint8_T)1U)
#define RobotControl_IN_Stop_o         ((uint8_T)1U)
#define RobotControl_IN_init_m         ((uint8_T)2U)
#define RobotControl_IN_turnHandler    ((uint8_T)3U)
#define RobotControl_IN_turnLeft_n     ((uint8_T)2U)
#define RobotControl_IN_turnRightFault ((uint8_T)4U)
#define RobotControl_IN_turnRight_l    ((uint8_T)3U)

/* Named constants for Chart: '<S109>/EncoderHeadingHandler' */
#define RobotCont_CAL_ROB_ERRVAL_ENCODE ((uint8_T)10U)

/* Named constants for Chart: '<S106>/CompassSelfDiagTestChart' */
#define RobotContr_IN_finishFacingNorth ((uint8_T)5U)
#define RobotControl_IN_FacingEAST     ((uint8_T)1U)
#define RobotControl_IN_FacingSOUTH    ((uint8_T)2U)
#define RobotControl_IN_FacingWEST     ((uint8_T)3U)
#define RobotControl_IN_Moving         ((uint8_T)4U)
#define RobotControl_IN_initFacingNorth ((uint8_T)6U)

/* Forward declaration for local functions */
static void RobotControl_chartstep_c25_ROTH(void);
static void RobotControl_chartstep_c24_ROTH(void);
static real_T RobotControl_directionCheck(real_T strtHeading, real_T
  CurrentHeading, real_T N, real_T E, real_T S, real_T W, real_T enTheta);

/*
 * System initialize for atomic system:
 *    '<S114>/DeltaDistCalculator'
 *    '<S116>/DeltaDistCalculator'
 */
void RobotC_DeltaDistCalculator_Init(B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  localDW->is_active_c30_ROTH = 0U;
  localDW->is_c30_ROTH = RobotContr_IN_NO_ACTIVE_CHILD_i;
  localDW->tempDist = 0.0F;
  localB->deltaDistTrav = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S114>/DeltaDistCalculator'
 *    '<S116>/DeltaDistCalculator'
 */
void RobotContro_DeltaDistCalculator(boolean_T rtu_targetReached, real32_T
  rtu_rightDistTravelled_mm, B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  /* Gateway: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  /* During: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  if (localDW->is_active_c30_ROTH == 0U) {
    /* Entry: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    localDW->is_active_c30_ROTH = 1U;

    /* Entry Internal: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    /* Transition: '<S115>:2' */
    localDW->is_c30_ROTH = RobotControl_IN_StartTurn;

    /* Entry 'StartTurn': '<S115>:1' */
    localDW->tempDist = rtu_rightDistTravelled_mm;
  } else if ((localDW->is_c30_ROTH == RobotControl_IN_StartTurn) &&
             rtu_targetReached) {
    /* During 'StartTurn': '<S115>:1' */
    /* Transition: '<S115>:7' */
    localDW->is_c30_ROTH = RobotControl_IN_targetReached;

    /* Entry 'targetReached': '<S115>:6' */
    localB->deltaDistTrav = rtu_rightDistTravelled_mm - localDW->tempDist;
  } else {
    /* During 'targetReached': '<S115>:6' */
  }
}

/* Function for Chart: '<S98>/ZgZgChart' */
static void RobotControl_chartstep_c25_ROTH(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;

  /* During: Routines/zigzagRoutine/ZgZgChart */
  if (RobotControl_DW.is_active_c25_ROTH == 0U) {
    /* Entry: Routines/zigzagRoutine/ZgZgChart */
    RobotControl_DW.is_active_c25_ROTH = 1U;

    /* Entry Internal: Routines/zigzagRoutine/ZgZgChart */
    /* Transition: '<S123>:28' */
    RobotControl_DW.is_c25_ROTH = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S123>:27' */
    RobotControl_B.zgzgActive = true;
    RobotControl_DW.finishCounter = 1U;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (RobotControl_DW.is_c25_ROTH) {
     case RobotControl_IN_Freeze:
      /* During 'Freeze': '<S123>:121' */
      if (RobotControl_DW.sfEvent_j == RobotControl_event_stopEvent_n) {
        /* Transition: '<S123>:32' */
        if (RobotControl_B.sensorView ==
            RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY) {
          /* Transition: '<S123>:38' */
          if (RobotControl_B.currentHeading ==
              RobotControl_B.DataTypeConversion3_g) {
            /* Constant: '<S98>/ENU_MOVE_U_TURN_RIGHT' */
            /* Transition: '<S123>:41' */
            RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN_RIGHT;
            RobotControl_DW.headingRequest = (uint16_T)
              RobotControl_B.DataTypeConversion4_m;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S123>:31' */
            RobotControl_B.switchLaneFlg_BOOL = true;
            RobotControl_B.swLaneCnt_uint8++;
          } else if (RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion4_m) {
            /* Constant: '<S98>/ENU_MOVE_U_TURN_LEFT' */
            /* Transition: '<S123>:43' */
            RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN_LEFT;
            RobotControl_DW.headingRequest = (uint16_T)
              RobotControl_B.DataTypeConversion3_g;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S123>:31' */
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
      /* During 'Idle': '<S123>:27' */
      if (RobotControl_B.currentRoutine == RobotControl_ENU_ZIGZAG_m) {
        /* Transition: '<S123>:30' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S123>:92' */
        /* Transition: '<S123>:96' */
        RobotControl_DW.is_faceWest_h = RobotControl_IN_Start;

        /* Entry 'Start': '<S123>:104' */
        RobotControl_DW.initHeading = 0.0;
      }
      break;

     case RobotControl_IN_MovingForward:
      /* During 'MovingForward': '<S123>:29' */
      if ((RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion1_e)
          || (RobotControl_B.currentHeading ==
              RobotControl_B.DataTypeConversion2_m)) {
        /* Transition: '<S123>:109' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S123>:92' */
        /* Transition: '<S123>:96' */
        RobotControl_DW.is_faceWest_h = RobotControl_IN_Start;

        /* Entry 'Start': '<S123>:104' */
        RobotControl_DW.initHeading = 0.0;
      } else {
        if (RobotControl_B.hitRoutineRun) {
          /* Transition: '<S123>:120' */
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_Freeze;
        }
      }
      break;

     case RobotControl_IN_SwitchLane:
      /* During 'SwitchLane': '<S123>:31' */
      if (RobotControl_DW.finishCounter > RobotControl_CAL_ZgZgCounterThd) {
        /* Transition: '<S123>:54' */
        /* Exit 'SwitchLane': '<S123>:31' */
        RobotControl_B.switchLaneFlg_BOOL = false;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_finishZigZag;

        /* Entry 'finishZigZag': '<S123>:53' */
        RobotControl_B.zgzgActive = false;

        /* Constant: '<S98>/ENU_STOP' */
        RobotControl_B.moveRequest_i = RobotControl_P.ENU_STOP;
      } else {
        if ((RobotControl_DW.headingRequest == RobotControl_B.currentHeading) &&
            RobotControl_B.OutportBufferFortargetReached) {
          /* Transition: '<S123>:55' */
          /* Exit 'SwitchLane': '<S123>:31' */
          RobotControl_B.switchLaneFlg_BOOL = false;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_MovingForward;

          /* Constant: '<S98>/ENU_FORWARD' */
          /* Entry 'MovingForward': '<S123>:29' */
          RobotControl_B.moveRequest_i = RobotControl_P.ENU_FORWARD;
        }
      }
      break;

     case RobotControl_IN_faceWest:
      /* During 'faceWest': '<S123>:92' */
      if (RobotControl_DW.initHeading != 0.0) {
        /* Transition: '<S123>:108' */
        /* Exit Internal 'faceWest': '<S123>:92' */
        RobotControl_DW.is_faceWest_h = 0U;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_MovingForward;

        /* Constant: '<S98>/ENU_FORWARD' */
        /* Entry 'MovingForward': '<S123>:29' */
        RobotControl_B.moveRequest_i = RobotControl_P.ENU_FORWARD;
      } else {
        switch (RobotControl_DW.is_faceWest_h) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S123>:104' */
          if (RobotControl_B.currentHeading ==
              RobotControl_B.DataTypeConversion4_m) {
            /* Transition: '<S123>:94' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_turingRight;

            /* Constant: '<S98>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S123>:103' */
            RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN;
          } else if (RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion1_e) {
            /* Transition: '<S123>:97' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_turningLeft;

            /* Entry 'turningLeft': '<S123>:105' */
            RobotControl_B.moveRequest_i = RobotControl_MOVE_TURN_RIGHT;
          } else if (RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion2_m) {
            /* Transition: '<S123>:98' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_uturn;

            /* Entry 'uturn': '<S123>:107' */
            RobotControl_B.moveRequest_i = RobotControl_MOVE_TURN_LEFT;
          } else {
            if (RobotControl_B.currentHeading ==
                RobotControl_B.DataTypeConversion3_g) {
              /* Transition: '<S123>:101' */
              RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S123>:106' */
              RobotControl_DW.initHeading = 1.0;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S123>:106' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S123>:103' */
          /* Transition: '<S123>:95' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S123>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S123>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S123>:105' */
          /* Transition: '<S123>:99' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S123>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S123>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         default:
          /* During 'uturn': '<S123>:107' */
          /* Transition: '<S123>:102' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S123>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S123>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;
        }
      }
      break;

     default:
      /* During 'finishZigZag': '<S123>:53' */
      if (RobotControl_B.currentRoutine == RobotControl_ENU_ZIGZAG_m) {
        /* Transition: '<S123>:61' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S123>:27' */
        RobotControl_B.zgzgActive = true;
        RobotControl_DW.finishCounter = 1U;
      }
      break;
    }

    if (guard4) {
      if ((RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_EMPTY) ||
          (RobotControl_B.sensorView == RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY))
      {
        /* Transition: '<S123>:44' */
        if (RobotControl_B.currentHeading ==
            RobotControl_B.DataTypeConversion3_g) {
          /* Constant: '<S98>/ENU_MOVE_U_TURN_RIGHT' */
          /* Transition: '<S123>:45' */
          RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN_RIGHT;
          RobotControl_DW.headingRequest = (uint16_T)
            RobotControl_B.DataTypeConversion4_m;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S123>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading ==
                   RobotControl_B.DataTypeConversion4_m) {
          /* Constant: '<S98>/ENU_MOVE_U_TURN' */
          /* Transition: '<S123>:46' */
          RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN;
          RobotControl_DW.headingRequest = (uint16_T)
            RobotControl_B.DataTypeConversion3_g;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S123>:31' */
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
      if (RobotControl_B.sensorView == RobotControl_P.ENU_LEFT_BUSY_RIGHT_BUSY)
      {
        /* Transition: '<S123>:90' */
        guard1 = true;
      } else if ((RobotControl_B.sensorView ==
                  RobotControl_P.ENU_LEFT_EMPTY_RIGHT_CLEANED) ||
                 (RobotControl_B.sensorView ==
                  RobotControl_P.ENU_LEFT_EMPTY_RIGHT_BUSY)) {
        /* Transition: '<S123>:47' */
        if (RobotControl_B.currentHeading ==
            RobotControl_B.DataTypeConversion3_g) {
          /* Constant: '<S98>/ENU_MOVE_U_TURN' */
          /* Transition: '<S123>:48' */
          RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN;
          RobotControl_DW.headingRequest = (uint16_T)
            RobotControl_B.DataTypeConversion4_m;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S123>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading ==
                   RobotControl_B.DataTypeConversion4_m) {
          /* Constant: '<S98>/ENU_MOVE_U_TURN_LEFT' */
          /* Transition: '<S123>:49' */
          RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN_LEFT;
          RobotControl_DW.headingRequest = (uint16_T)
            RobotControl_B.DataTypeConversion3_g;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S123>:31' */
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
      if ((RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_BUSY_RIGHT_CLEANED) ||
          (RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_BUSY) ||
          (RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_CLEANED)) {
        /* Transition: '<S123>:50' */
        guard1 = true;
      }
    }

    if (guard1) {
      if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion3_g)
      {
        /* Constant: '<S98>/ENU_MOVE_U_TURN' */
        /* Transition: '<S123>:51' */
        RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN;
        RobotControl_DW.headingRequest = (uint16_T)
          RobotControl_B.DataTypeConversion4_m;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S123>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else if (RobotControl_B.currentHeading ==
                 RobotControl_B.DataTypeConversion4_m) {
        /* Constant: '<S98>/ENU_MOVE_U_TURN' */
        /* Transition: '<S123>:56' */
        RobotControl_B.moveRequest_i = RobotControl_P.ENU_MOVE_U_TURN;
        RobotControl_DW.headingRequest = (uint16_T)
          RobotControl_B.DataTypeConversion3_g;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S123>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else {
        /* Transition: '<S123>:119' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S123>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      }
    }
  }
}

/* Function for Chart: '<S95>/GTSP_Chart' */
static void RobotControl_chartstep_c24_ROTH(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During: Routines/StartPointRoutine/GTSP_Chart */
  if (RobotControl_DW.is_active_c24_ROTH == 0U) {
    /* Entry: Routines/StartPointRoutine/GTSP_Chart */
    RobotControl_DW.is_active_c24_ROTH = 1U;

    /* Entry Internal: Routines/StartPointRoutine/GTSP_Chart */
    /* Transition: '<S122>:6' */
    RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S122>:5' */
    RobotControl_DW.counter = 0U;

    /* Constant: '<S95>/ENU_STOP' */
    RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
    RobotControl_DW.step1Flag = 0U;
    RobotControl_B.GT_active = true;
  } else {
    guard1 = false;
    guard2 = false;
    switch (RobotControl_DW.is_c24_ROTH) {
     case RobotControl_IN_GTSP_Active:
      /* During 'GTSP_Active': '<S122>:7' */
      if (RobotControl_B.currentRoutine != RobotControl_P.ENU_GTSP) {
        /* Transition: '<S122>:9' */
        /* Exit Internal 'GTSP_Active': '<S122>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S122>:5' */
        RobotControl_DW.counter = 0U;

        /* Constant: '<S95>/ENU_STOP' */
        RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
        RobotControl_DW.step1Flag = 0U;
        RobotControl_B.GT_active = true;
      } else if (RobotControl_DW.step1Flag == 1) {
        /* Transition: '<S122>:68' */
        /* Exit Internal 'GTSP_Active': '<S122>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.activeFlag = true;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_MostSouthLeft;
        RobotControl_DW.is_MostSouthLeft = RobotControl_IN_start_h;
      } else {
        switch (RobotControl_DW.is_GTSP_Active) {
         case RobotControl_IN_Forward:
          /* During 'Forward': '<S122>:10' */
          if (RobotControl_B.hitRoutineRun) {
            /* Transition: '<S122>:13' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Freeze_j;
          }
          break;

         case RobotControl_IN_Freeze_j:
          /* During 'Freeze': '<S122>:193' */
          if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
            /* Transition: '<S122>:194' */
            if ((RobotControl_B.sensorView ==
                 RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY) ||
                (RobotControl_B.sensorView ==
                 RobotControl_P.ENU_LEFT_EMPTY_RIGHT_CLEANED) ||
                (RobotControl_B.sensorView ==
                 RobotControl_P.ENU_LEFT_EMPTY_RIGHT_BUSY)) {
              /* Transition: '<S122>:15' */
              if (RobotControl_B.currentHeading ==
                  RobotControl_B.DataTypeConversion) {
                /* Transition: '<S122>:18' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_TurnLeft_e;

                /* Constant: '<S95>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'TurnLeft': '<S122>:12' */
                RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_TURN_LEFT;
              } else if (RobotControl_B.currentHeading ==
                         RobotControl_B.DataTypeConversion2) {
                /* Transition: '<S122>:20' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_preFinishNormal;

                /* Constant: '<S95>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'preFinishNormal': '<S122>:19' */
                RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_TURN_LEFT;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }
          break;

         case RobotControl_IN_TurnLeft_e:
          /* During 'TurnLeft': '<S122>:12' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion2) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S122>:16' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

            /* Constant: '<S95>/ENU_FORWARD' */
            /* Entry 'Forward': '<S122>:10' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
          }
          break;

         case RobotControl_IN_finishedGTSP:
          /* During 'finishedGTSP': '<S122>:33' */
          break;

         case RobotContr_IN_preFinishBlockedN:
          /* During 'preFinishBlockedN': '<S122>:27' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S122>:36' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S122>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S95>/ENU_STOP' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
          }
          break;

         case RobotContr_IN_preFinishBlockedW:
          /* During 'preFinishBlockedW': '<S122>:28' */
          /* Transition: '<S122>:35' */
          RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

          /* Entry 'finishedGTSP': '<S122>:33' */
          RobotControl_DW.step1Flag = 1U;

          /* Constant: '<S95>/ENU_STOP' */
          RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
          break;

         case RobotC_IN_preFinishLeftBlockedN:
          /* During 'preFinishLeftBlockedN': '<S122>:21' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion1_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S122>:37' */
            /* Transition: '<S122>:157' */
            RobotControl_DW.is_GTSP_Active = 0U;
            RobotControl_DW.is_c24_ROTH = RobotControl_IN_MostSouthLeft;
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

            /* Entry 'finish': '<S122>:102' */
            RobotControl_B.GT_active = false;
          }
          break;

         case RobotC_IN_preFinishLeftBlockedW:
          /* During 'preFinishLeftBlockedW': '<S122>:25' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S122>:38' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S122>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S95>/ENU_STOP' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
          }
          break;

         default:
          /* During 'preFinishNormal': '<S122>:19' */
          if ((RobotControl_B.currentHeading ==
               RobotControl_B.DataTypeConversion1_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S122>:34' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S122>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S95>/ENU_STOP' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_Idle_o:
      /* Constant: '<S95>/ENU_GTSP' */
      /* During 'Idle': '<S122>:5' */
      if ((RobotControl_B.currentRoutine == RobotControl_P.ENU_GTSP) &&
          (RobotControl_DW.counter > RobotControl_CAL_GTSPdelayStart)) {
        /* Transition: '<S122>:8' */
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_faceWest_c;

        /* Entry Internal 'faceWest': '<S122>:126' */
        /* Transition: '<S122>:128' */
        RobotControl_DW.is_faceWest = RobotControl_IN_Start;

        /* Entry 'Start': '<S122>:127' */
        RobotControl_DW.initHeading_p = false;
      } else {
        RobotControl_DW.counter++;
      }
      break;

     case RobotControl_IN_MostSouthLeft:
      /* During 'MostSouthLeft': '<S122>:67' */
      switch (RobotControl_DW.is_MostSouthLeft) {
       case RobotControl_IN_facingSouth:
        /* During 'facingSouth': '<S122>:72' */
        if (!RobotControl_DW.activeFlag) {
          /* Transition: '<S122>:103' */
          /* Exit Internal 'facingSouth': '<S122>:72' */
          RobotControl_DW.is_facingSouth = 0U;

          /* Exit Internal 'GTSPsearch': '<S122>:94' */
          RobotControl_DW.is_GTSPsearch = 0U;
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

          /* Entry 'finish': '<S122>:102' */
          RobotControl_B.GT_active = false;
        } else {
          switch (RobotControl_DW.is_facingSouth) {
           case RobotControl_IN_End_p:
            /* During 'End': '<S122>:89' */
            break;

           case RobotControl_IN_Freeze_j:
            /* During 'Freeze': '<S122>:197' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S122>:155' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S122>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze1:
            /* During 'Freeze1': '<S122>:199' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S122>:106' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S122>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze6:
            /* During 'Freeze6': '<S122>:205' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S122>:87' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S122>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           default:
            /* During 'GTSPsearch': '<S122>:94' */
            if ((RobotControl_B.DataTypeConversion1_g ==
                 RobotControl_B.currentHeading) &&
                RobotControl_B.OutportBufferFortargetReached &&
                (RobotControl_DW.round > 1) && RobotControl_B.hitRoutineRun) {
              /* Transition: '<S122>:95' */
              /* Transition: '<S122>:196' */
              /* Exit Internal 'GTSPsearch': '<S122>:94' */
              RobotControl_DW.is_GTSPsearch = 0U;

              /* Constant: '<S95>/ENU_STOP' */
              RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
              RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze_j;
            } else {
              switch (RobotControl_DW.is_GTSPsearch) {
               case RobotControl_IN_Freeze3:
                /* During 'Freeze3': '<S122>:200' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S122>:201' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S95>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S122>:82' */
                  RobotControl_B.moveRequest_p =
                    RobotControl_P.ENU_MOVE_TURN_RIGHT;
                }
                break;

               case RobotControl_IN_Freeze4:
                /* During 'Freeze4': '<S122>:203' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S122>:182' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S95>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S122>:82' */
                  RobotControl_B.moveRequest_p =
                    RobotControl_P.ENU_MOVE_TURN_RIGHT;
                }
                break;

               case RobotControl_IN_Freeze5:
                /* During 'Freeze5': '<S122>:207' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S122>:208' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_furtherDown;

                  /* Constant: '<S95>/ENU_MOVE_TURN_LEFT' */
                  /* Entry 'furtherDown': '<S122>:91' */
                  RobotControl_B.moveRequest_p =
                    RobotControl_P.ENU_MOVE_TURN_LEFT;
                }
                break;

               case RobotControl_IN_emptyOnRight:
                /* During 'emptyOnRight': '<S122>:82' */
                if ((RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion2) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S122>:85' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_facingWest;

                  /* Constant: '<S95>/ENU_FORWARD' */
                  /* Entry 'facingWest': '<S122>:84' */
                  RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
                }
                break;

               case RobotControl_IN_facingWest:
                /* During 'facingWest': '<S122>:84' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Constant: '<S95>/ENU_LEFT_EMPTY_RIGHT_BUSY' incorporates:
                   *  Constant: '<S95>/ENU_LEFT_BUSY_RIGHT_BUSY'
                   *  Constant: '<S95>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                   *  Constant: '<S95>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                   */
                  /* Transition: '<S122>:204' */
                  if ((RobotControl_B.sensorView ==
                       RobotControl_P.ENU_LEFT_EMPTY_RIGHT_BUSY) ||
                      (RobotControl_B.sensorView ==
                       RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY)) {
                    /* Transition: '<S122>:92' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze5;
                  } else {
                    if ((RobotControl_B.sensorView ==
                         RobotControl_P.ENU_LEFT_BUSY_RIGHT_BUSY) ||
                        (RobotControl_B.sensorView ==
                         RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY)) {
                      /* Transition: '<S122>:90' */
                      RobotControl_DW.is_GTSPsearch = 0U;
                      RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze6;
                    }
                  }

                  /* End of Constant: '<S95>/ENU_LEFT_EMPTY_RIGHT_BUSY' */
                }
                break;

               case RobotControl_IN_furtherDown:
                /* During 'furtherDown': '<S122>:91' */
                if ((RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion1_g) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S122>:93' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

                  /* Constant: '<S95>/ENU_FORWARD' */
                  /* Entry 'start': '<S122>:77' */
                  RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
                  RobotControl_DW.round++;
                }
                break;

               case RobotControl_IN_intermediate:
                /* During 'intermediate': '<S122>:173' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S122>:202' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze4;
                } else if ((RobotControl_B.sensorView !=
                            RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY) &&
                           (RobotControl_B.sensorView !=
                            RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY)) {
                  /* Transition: '<S122>:167' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

                  /* Constant: '<S95>/ENU_FORWARD' */
                  /* Entry 'start': '<S122>:77' */
                  RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
                  RobotControl_DW.round++;
                } else {
                  if (RobotControl_B.forwardDist - RobotControl_DW.tempDist_f >
                      RobotControl_CAL_ROBO_LENG_mm) {
                    /* Transition: '<S122>:166' */
                    /* * 0.75)] */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                    /* Constant: '<S95>/ENU_MOVE_TURN_RIGHT' */
                    /* Entry 'emptyOnRight': '<S122>:82' */
                    RobotControl_B.moveRequest_p =
                      RobotControl_P.ENU_MOVE_TURN_RIGHT;
                  }
                }
                break;

               default:
                /* Constant: '<S95>/ENU_LEFT_BUSY_RIGHT_EMPTY' incorporates:
                 *  Constant: '<S95>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                 */
                /* During 'start': '<S122>:77' */
                if (((RobotControl_B.sensorView ==
                      RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY) ||
                     (RobotControl_B.sensorView ==
                      RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY)) &&
                    RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S122>:164' */
                  /* Transition: '<S122>:163' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze3;
                } else if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S122>:198' */
                  RobotControl_DW.is_GTSPsearch = 0U;
                  RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze1;
                } else {
                  if ((RobotControl_B.sensorView ==
                       RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY) ||
                      (RobotControl_B.sensorView ==
                       RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY)) {
                    /* Transition: '<S122>:81' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_intermediate;

                    /* Entry 'intermediate': '<S122>:173' */
                    RobotControl_DW.tempDist_f = RobotControl_B.forwardDist;
                  }
                }
                break;
              }
            }
            break;
          }
        }
        break;

       case RobotControl_IN_finish_j:
        /* Constant: '<S95>/ENU_GTSP' */
        /* During 'finish': '<S122>:102' */
        if (RobotControl_B.currentRoutine == RobotControl_P.ENU_GTSP) {
          /* Transition: '<S122>:101' */
          RobotControl_DW.is_MostSouthLeft = 0U;
          RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

          /* Entry 'Idle': '<S122>:5' */
          RobotControl_DW.counter = 0U;

          /* Constant: '<S95>/ENU_STOP' */
          RobotControl_B.moveRequest_p = RobotControl_P.ENU_STOP;
          RobotControl_DW.step1Flag = 0U;
          RobotControl_B.GT_active = true;
        }
        break;

       default:
        /* During 'start': '<S122>:69' */
        if (RobotControl_B.currentHeading ==
            RobotControl_B.DataTypeConversion1_g) {
          /* Transition: '<S122>:73' */
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_facingSouth;

          /* Entry Internal 'facingSouth': '<S122>:72' */
          /* Transition: '<S122>:99' */
          RobotControl_DW.is_facingSouth = RobotControl_IN_GTSPsearch;

          /* Entry 'GTSPsearch': '<S122>:94' */
          RobotControl_DW.round = 0U;

          /* Entry Internal 'GTSPsearch': '<S122>:94' */
          /* Transition: '<S122>:78' */
          RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

          /* Constant: '<S95>/ENU_FORWARD' */
          /* Entry 'start': '<S122>:77' */
          RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
          RobotControl_DW.round++;
        } else {
          if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
          {
            /* Transition: '<S122>:74' */
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

            /* Entry 'finish': '<S122>:102' */
            RobotControl_B.GT_active = false;
          }
        }
        break;
      }
      break;

     default:
      /* During 'faceWest': '<S122>:126' */
      if (RobotControl_DW.initHeading_p) {
        /* Transition: '<S122>:139' */
        /* Exit Internal 'faceWest': '<S122>:126' */
        RobotControl_DW.is_faceWest = 0U;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_GTSP_Active;

        /* Entry Internal 'GTSP_Active': '<S122>:7' */
        /* Transition: '<S122>:11' */
        RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

        /* Constant: '<S95>/ENU_FORWARD' */
        /* Entry 'Forward': '<S122>:10' */
        RobotControl_B.moveRequest_p = RobotControl_P.ENU_FORWARD;
      } else {
        switch (RobotControl_DW.is_faceWest) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S122>:127' */
          if (RobotControl_B.currentHeading ==
              RobotControl_B.DataTypeConversion1_g) {
            /* Transition: '<S122>:132' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turingRight;

            /* Constant: '<S95>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S122>:129' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_U_TURN;
          } else if (RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion2) {
            /* Transition: '<S122>:133' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turningLeft;

            /* Constant: '<S95>/ENU_MOVE_TURN_RIGHT' */
            /* Entry 'turningLeft': '<S122>:130' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_TURN_RIGHT;
          } else if (RobotControl_B.currentHeading ==
                     RobotControl_B.DataTypeConversion3_l) {
            /* Transition: '<S122>:134' */
            RobotControl_DW.is_faceWest = RobotControl_IN_uturn;

            /* Constant: '<S95>/ENU_MOVE_TURN_LEFT' */
            /* Entry 'uturn': '<S122>:131' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_TURN_LEFT;
          } else {
            if (RobotControl_B.currentHeading ==
                RobotControl_B.DataTypeConversion) {
              /* Transition: '<S122>:142' */
              RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S122>:140' */
              RobotControl_DW.initHeading_p = true;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S122>:140' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S122>:129' */
          /* Transition: '<S122>:136' */
          if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
          {
            /* Transition: '<S122>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S122>:140' */
            RobotControl_DW.initHeading_p = true;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S122>:130' */
          /* Transition: '<S122>:137' */
          if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
          {
            /* Transition: '<S122>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S122>:140' */
            RobotControl_DW.initHeading_p = true;
          }
          break;

         default:
          /* During 'uturn': '<S122>:131' */
          /* Transition: '<S122>:138' */
          if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
          {
            /* Transition: '<S122>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S122>:140' */
            RobotControl_DW.initHeading_p = true;
          }
          break;
        }
      }
      break;
    }

    if (guard2) {
      if ((RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_EMPTY) ||
          (RobotControl_B.sensorView == RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY))
      {
        /* Transition: '<S122>:23' */
        if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
        {
          /* Transition: '<S122>:24' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedN;

          /* Constant: '<S95>/ENU_MOVE_U_TURN' */
          /* Entry 'preFinishLeftBlockedN': '<S122>:21' */
          RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_U_TURN;
        } else if (RobotControl_B.currentHeading ==
                   RobotControl_B.DataTypeConversion2) {
          /* Transition: '<S122>:26' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedW;

          /* Constant: '<S95>/ENU_MOVE_TURN_RIGHT' */
          /* Entry 'preFinishLeftBlockedW': '<S122>:25' */
          RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_TURN_RIGHT;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      /* Constant: '<S95>/ENU_LEFT_BUSY_RIGHT_BUSY' incorporates:
       *  Constant: '<S95>/ENU_LEFT_BUSY_RIGHT_CLEANED'
       *  Constant: '<S95>/ENU_LEFT_CLEANED_RIGHT_BUSY'
       *  Constant: '<S95>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
       */
      if ((RobotControl_B.sensorView == RobotControl_P.ENU_LEFT_BUSY_RIGHT_BUSY)
          || (RobotControl_B.sensorView ==
              RobotControl_P.ENU_LEFT_BUSY_RIGHT_CLEANED) ||
          (RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_BUSY) ||
          (RobotControl_B.sensorView ==
           RobotControl_P.ENU_LEFT_CLEANED_RIGHT_CLEANED)) {
        /* Transition: '<S122>:30' */
        if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion2)
        {
          /* Transition: '<S122>:31' */
          RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedW;
        } else {
          if (RobotControl_B.currentHeading == RobotControl_B.DataTypeConversion)
          {
            /* Transition: '<S122>:32' */
            RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedN;

            /* Constant: '<S95>/ENU_MOVE_U_TURN' */
            /* Entry 'preFinishBlockedN': '<S122>:27' */
            RobotControl_B.moveRequest_p = RobotControl_P.ENU_MOVE_U_TURN;
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S108>/CompassSelfDiagTestChart' */
static real_T RobotControl_directionCheck(real_T strtHeading, real_T
  CurrentHeading, real_T N, real_T E, real_T S, real_T W, real_T enTheta)
{
  real_T outFlg;

  /* Graphical Function 'directionCheck': '<S110>:49' */
  /* Transition: '<S110>:51' */
  if (((strtHeading == RobotControl_B.DataTypeConversion3) && (CurrentHeading ==
        N) && ((enTheta >= 265.0) || (enTheta <= 275.0))) || ((strtHeading ==
        RobotControl_B.DataTypeConversion5) && (CurrentHeading == W) && (enTheta
        == RobotControl_CAL_WEST)) || ((strtHeading ==
        RobotControl_B.DataTypeConversion4) && (CurrentHeading == S) && (enTheta
        == RobotControl_CAL_SOUTH)) || ((strtHeading ==
        RobotControl_B.DataTypeConversion1) && (CurrentHeading == E) && (enTheta
        == 0.0))) {
    /* Transition: '<S110>:53' */
    /* Transition: '<S110>:72' */
    /* Transition: '<S110>:56' */
    /* Transition: '<S110>:71' */
    /* Transition: '<S110>:61' */
    /* Transition: '<S110>:73' */
    /* Transition: '<S110>:63' */
    /* Transition: '<S110>:65' */
    outFlg = 1.0;

    /* Transition: '<S110>:67' */
  } else {
    /* Transition: '<S110>:57' */
    /* Transition: '<S110>:70' */
    /* Transition: '<S110>:69' */
    /* Transition: '<S110>:68' */
    outFlg = 0.0;
  }

  return outFlg;
}

/* System initialize for function-call system: '<S16>/HighLevelRoutines' */
void RobotCon_HighLevelRoutines_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S21>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_h = true;

  /* InitializeConditions for UnitDelay: '<S21>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_c = false;

  /* InitializeConditions for UnitDelay: '<S21>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_b = RobotControl_P.CONST_DIAG_UNCONFIRM;

  /* InitializeConditions for UnitDelay: '<S21>/Unit_Delay2' */
  RobotControl_B.moveRequest = 0U;

  /* InitializeConditions for UnitDelay: '<S21>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE = RobotControl_P.CAL_NORTH;

  /* SystemInitialize for Chart: '<S94>/MainStateMachine' */
  RobotControl_DW.is_Running = 0U;
  RobotControl_DW.temporalCounter_i1 = 0U;
  RobotControl_DW.is_active_c23_ROTH = 0U;
  RobotControl_DW.is_c23_ROTH = 0U;
  RobotControl_DW.zgzgCounter = 0U;
  RobotControl_B.currentRoutine = 0U;

  /* SystemInitialize for Chart: '<S93>/pumperHitSensorView' */
  RobotControl_B.sensorView = 0U;
  RobotControl_DW.doneDoubleBufferReInit = 0;

  /* SystemInitialize for IfAction SubSystem: '<S21>/zigzagRoutine' */
  /* SystemInitialize for Chart: '<S98>/ZgZgChart' */
  RobotControl_DW.is_faceWest_h = 0U;
  RobotControl_DW.is_active_c25_ROTH = 0U;
  RobotControl_DW.is_c25_ROTH = 0U;
  RobotControl_DW.headingRequest = 0U;
  RobotControl_DW.finishCounter = 0U;
  RobotControl_DW.initHeading = 0.0;
  RobotControl_B.moveRequest_i = 0U;
  RobotControl_B.zgzgActive = true;
  RobotControl_B.switchLaneFlg_BOOL = false;
  RobotControl_B.swLaneCnt_uint8 = 0U;

  /* SystemInitialize for Outport: '<S98>/zgzgActive' */
  RobotControl_B.OutportBufferForzgzgActive = true;

  /* SystemInitialize for Outport: '<S98>/switchLaneFlg_BOOL' */
  RobotControl_B.OutportBufferForswitchLaneFlg_k = false;

  /* SystemInitialize for Outport: '<S98>/swLaneCnt_uint8' */
  RobotControl_B.OutportBufferForswLaneCnt_uint8 = 0U;

  /* End of SystemInitialize for SubSystem: '<S21>/zigzagRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/StartPointRoutine' */
  /* SystemInitialize for Chart: '<S95>/GTSP_Chart' */
  RobotControl_DW.is_GTSP_Active = 0U;
  RobotControl_DW.is_MostSouthLeft = 0U;
  RobotControl_DW.is_facingSouth = 0U;
  RobotControl_DW.is_GTSPsearch = 0U;
  RobotControl_DW.is_faceWest = 0U;
  RobotControl_DW.is_active_c24_ROTH = 0U;
  RobotControl_DW.is_c24_ROTH = 0U;
  RobotControl_DW.counter = 0U;
  RobotControl_DW.round = 0U;
  RobotControl_DW.step1Flag = 0U;
  RobotControl_DW.initHeading_p = false;
  RobotControl_DW.activeFlag = false;
  RobotControl_DW.tempDist_f = 0.0F;
  RobotControl_B.moveRequest_p = 0U;
  RobotControl_B.GT_active = true;

  /* SystemInitialize for Outport: '<S95>/GT_active' */
  RobotControl_B.OutportBufferForGT_active = false;

  /* End of SystemInitialize for SubSystem: '<S21>/StartPointRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/DIAG_Routine' */
  /* InitializeConditions for UnitDelay: '<S90>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE = RobotControl_P.ENU_TEST_NOT_CONFIRMED;

  /* InitializeConditions for UnitDelay: '<S90>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_j = RobotControl_P.ENU_TEST_NOT_CONFIRMED;

  /* InitializeConditions for UnitDelay: '<S90>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_h = RobotControl_P.ENU_TEST_NOT_CONFIRMED;

  /* SystemInitialize for Chart: '<S118>/HighLevelDiagTestControl' */
  RobotControl_DW.is_SelfDiag = 0U;
  RobotControl_DW.temporalCounter_i1_c = 0U;
  RobotControl_DW.is_active_c26_ROTH = 0U;
  RobotControl_DW.is_c26_ROTH = 0U;
  RobotControl_B.diagEnableReq = 0U;
  RobotControl_B.enableAngleCalib_BOOL = false;

  /* SystemInitialize for IfAction SubSystem: '<S90>/CompassTest' */
  /* SystemInitialize for Chart: '<S108>/CompassSelfDiagTestChart' */
  RobotControl_DW.is_turnHandler = 0U;
  RobotControl_DW.is_active_c31_ROTH = 0U;
  RobotControl_DW.is_c31_ROTH = 0U;
  RobotControl_DW.startHeading = 0U;
  RobotControl_DW.steps = 0U;
  RobotControl_DW.filterToleranceCnt = 0U;
  RobotControl_B.compFaultFlag = false;
  RobotControl_B.moveReq_p = 0U;
  RobotControl_B.comTstStatus = 3U;

  /* End of SystemInitialize for SubSystem: '<S90>/CompassTest' */

  /* SystemInitialize for IfAction SubSystem: '<S90>/EncoderTest' */
  /* SystemInitialize for Chart: '<S114>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init(&RobotControl_B.sf_DeltaDistCalculator,
    &RobotControl_DW.sf_DeltaDistCalculator);

  /* SystemInitialize for Chart: '<S116>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init(&RobotControl_B.sf_DeltaDistCalculator_d,
    &RobotControl_DW.sf_DeltaDistCalculator_d);

  /* SystemInitialize for Outport: '<S102>/rightEncodDistErrorFlg_BOOL' */
  RobotControl_B.encoderDistErrorFlg_BOOL_m = false;

  /* SystemInitialize for Outport: '<S102>/leftEncodDistErrorFlg_BOOL' */
  RobotControl_B.encoderDistErrorFlg_BOOL = false;

  /* SystemInitialize for Outport: '<S102>/encoderTstStatus' */
  RobotControl_B.encoderTstStatus = 0U;

  /* End of SystemInitialize for SubSystem: '<S90>/EncoderTest' */

  /* SystemInitialize for IfAction SubSystem: '<S90>/Angle_Calibration' */
  /* SystemInitialize for Enabled SubSystem: '<S99>/Angle_CalibrationUponReq' */
  /* SystemInitialize for Chart: '<S106>/CompassSelfDiagTestChart' */
  RobotControl_DW.temporalCounter_i1_k3 = 0U;
  RobotControl_DW.is_active_c27_ROTH = 0U;
  RobotControl_DW.is_c27_ROTH = 0U;
  RobotControl_DW.angleFinishFlg = false;
  RobotControl_B.moveReq = 0U;
  RobotControl_B.angleCalibStatus = 3U;

  /* SystemInitialize for Outport: '<S106>/moveRequest' */
  RobotControl_B.OutportBufferFormoveRequest = RobotControl_P.ENU_STOP;

  /* SystemInitialize for Outport: '<S106>/angleCalibStatus' */
  RobotControl_B.OutportBufferForangleCalibSta_a =
    RobotControl_P.ENU_TEST_NOT_CONFIRMED;

  /* End of SystemInitialize for SubSystem: '<S99>/Angle_CalibrationUponReq' */

  /* SystemInitialize for Outport: '<S99>/angleCalibStatus' */
  RobotControl_B.OutportBufferForangleCalibStatu =
    RobotControl_P.ENU_TEST_NOT_CONFIRMED;

  /* End of SystemInitialize for SubSystem: '<S90>/Angle_Calibration' */

  /* SystemInitialize for IfAction SubSystem: '<S90>/None' */
  /* SystemInitialize for Outport: '<S104>/None' */
  RobotControl_B.DIAG_StatusFlg = RobotControl_P.CONST_DIAG_UNCONFIRM;

  /* End of SystemInitialize for SubSystem: '<S90>/None' */

  /* SystemInitialize for Outport: '<S90>/hardwareFaultFlg' */
  RobotControl_B.hardwareFaultFlg = false;

  /* SystemInitialize for Outport: '<S90>/DIAG_StatusFlg' */
  RobotControl_B.OutportBufferForDIAG_StatusFlg =
    RobotControl_P.CONST_DIAG_UNCONFIRM;

  /* SystemInitialize for Outport: '<S90>/enableAngleCalib_BOOL' */
  RobotControl_B.OutportBufferForenableAngleCali = false;

  /* End of SystemInitialize for SubSystem: '<S21>/DIAG_Routine' */

  /* SystemInitialize for Merge: '<S21>/Merge' */
  RobotControl_B.Merge = 5U;

  /* SystemInitialize for Outport: '<S21>/moveRequest' */
  RobotControl_B.moveRequest = 0U;

  /* SystemInitialize for Outport: '<S21>/switchLaneFlg_BOOL' */
  RobotControl_B.OutportBufferForswitchLaneFlg_B = false;

  /* SystemInitialize for Outport: '<S21>/diagSensorFailure' */
  RobotControl_B.diagSensorFailure = false;
}

/* Start for function-call system: '<S16>/HighLevelRoutines' */
void RobotCo_HighLevelRoutines_Start(void)
{
  /* Start for SwitchCase: '<S97>/Switch_Case' */
  RobotControl_DW.Switch_Case_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S21>/DIAG_Routine' */
  /* Start for SwitchCase: '<S103>/Switch_Case' */
  RobotControl_DW.Switch_Case_ActiveSubsystem_j = -1;

  /* Start for IfAction SubSystem: '<S90>/Angle_Calibration' */
  /* Start for Enabled SubSystem: '<S99>/Angle_CalibrationUponReq' */
  RobotControl_DW.Angle_CalibrationUponReq_MODE = false;

  /* End of Start for SubSystem: '<S99>/Angle_CalibrationUponReq' */
  /* End of Start for SubSystem: '<S90>/Angle_Calibration' */
  /* End of Start for SubSystem: '<S21>/DIAG_Routine' */
}

/* Output and update for function-call system: '<S16>/HighLevelRoutines' */
void RobotControl_HighLevelRoutines(void)
{
  /* local block i/o variables */
  real32_T rtb_thetaEncod;
  uint8_T rtb_leftBlocks_uint8;
  uint8_T rtb_rightBlocks_uint8;
  int8_T rtPrevAction;
  int8_T rtAction;
  real32_T rtb_quarterTurnTargetDist_mm;
  boolean_T zcEvent_idx_1;
  boolean_T zcEvent_idx_0;

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S96>/CAL_ULS_UnconnectedBlks'
   *  DataTypeConversion: '<S96>/Data_Type_Conversion1'
   */
  if (RobotControl_B.ULS_NotConnectedFlag_BOOL) {
    rtb_leftBlocks_uint8 = RobotControl_P.CAL_ULS_UnconnectedBlks;
  } else {
    rtb_leftBlocks_uint8 = (uint8_T)RobotControl_B.leftBlocks;
  }

  /* End of Switch: '<S96>/Switch' */

  /* Switch: '<S96>/Switch1' incorporates:
   *  Constant: '<S96>/CAL_ULS_UnconnectedBlks1'
   *  DataTypeConversion: '<S96>/Data_Type_Conversion2'
   */
  if (RobotControl_B.ULS_NotConnectedFlag_BOOL_j) {
    rtb_rightBlocks_uint8 = RobotControl_P.CAL_ULS_UnconnectedBlks;
  } else {
    rtb_rightBlocks_uint8 = (uint8_T)RobotControl_B.rightBlocks;
  }

  /* End of Switch: '<S96>/Switch1' */

  /* Chart: '<S94>/MainStateMachine' incorporates:
   *  DataTypeConversion: '<S94>/Data Type Conversion3'
   *  UnitDelay: '<S21>/Unit_Delay'
   *  UnitDelay: '<S21>/Unit_Delay1'
   *  UnitDelay: '<S21>/Unit_Delay3'
   *  UnitDelay: '<S21>/Unit_Delay4'
   */
  /* Gateway: Routines/RoutineControl/MainStateMachine */
  if (RobotControl_DW.temporalCounter_i1 < 511U) {
    RobotControl_DW.temporalCounter_i1++;
  }

  /* During: Routines/RoutineControl/MainStateMachine */
  if (RobotControl_DW.is_active_c23_ROTH == 0U) {
    /* Entry: Routines/RoutineControl/MainStateMachine */
    RobotControl_DW.is_active_c23_ROTH = 1U;

    /* Entry Internal: Routines/RoutineControl/MainStateMachine */
    /* Transition: '<S121>:31' */
    RobotControl_DW.is_c23_ROTH = RobotControl_IN_Running;

    /* Entry Internal 'Running': '<S121>:30' */
    /* Transition: '<S121>:2' */
    RobotControl_DW.is_Running = RobotControl_IN_DIAG;
    RobotControl_DW.temporalCounter_i1 = 0U;
  } else if (RobotControl_DW.is_c23_ROTH != RobotControl_IN_FaultState) {
    /* During 'Running': '<S121>:30' */
    if (RobotControl_B.failFlag) {
      /* Transition: '<S121>:33' */
      /* Exit Internal 'Running': '<S121>:30' */
      RobotControl_DW.is_Running = 0U;
      RobotControl_DW.is_c23_ROTH = RobotControl_IN_FaultState;

      /* Entry 'FaultState': '<S121>:32' */
      RobotControl_B.currentRoutine = RobotControl_ENU_END;
    } else {
      switch (RobotControl_DW.is_Running) {
       case RobotControl_IN_DIAG:
        /* During 'DIAG': '<S121>:1' */
        if (RobotControl_DW.Unit_Delay4_DSTATE_b ==
            RobotCont_CONST_DIAG_FINISH_FLG) {
          /* Transition: '<S121>:4' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S121>:3' */
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
        /* During 'End': '<S121>:7' */
        break;

       case RobotControl_IN_GTSP:
        /* During 'GTSP': '<S121>:3' */
        if ((!RobotControl_DW.Unit_Delay_DSTATE_h) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S121>:6' */
          RobotControl_DW.is_Running = RobotControl_IN_ZIGZAG;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'ZIGZAG': '<S121>:5' */
          RobotControl_B.currentRoutine = RobotControl_ENU_ZIGZAG;
          RobotControl_DW.zgzgCounter++;
        }
        break;

       case RobotControl_IN_ShiftHeadings:
        /* During 'ShiftHeadings': '<S121>:43' */
        if (RobotControl_DW.temporalCounter_i1 >=
            RobotCont_CONST_MODES_TOLERANCE) {
          /* Transition: '<S121>:44' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S121>:3' */
          RobotControl_B.currentRoutine = RobotControl_ENU_GTSP;
        }
        break;

       default:
        /* During 'ZIGZAG': '<S121>:5' */
        if ((!RobotControl_DW.Unit_Delay1_DSTATE_c) &&
            (RobotControl_DW.zgzgCounter >= RobotContro_CONST_ZGZAG_CNT_THD) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S121>:18' */
          RobotControl_DW.is_Running = RobotControl_IN_End;

          /* Entry 'End': '<S121>:7' */
          RobotControl_B.currentRoutine = RobotControl_ENU_END;
        } else {
          if ((!RobotControl_DW.Unit_Delay1_DSTATE_c) ||
              (RobotControl_B.OutportBufferForswLaneCnt_uint8 >
               RobotControl_CONST_MAXZIGZAG)) {
            /* Transition: '<S121>:13' */
            RobotControl_DW.is_Running = RobotControl_IN_ShiftHeadings;
            RobotControl_DW.temporalCounter_i1 = 0U;

            /* Entry 'ShiftHeadings': '<S121>:43' */
            RobotControl_B.currentRoutine = RobotControl_ENU_SHIFT_HEADING;
          }
        }
        break;
      }
    }
  } else {
    /* During 'FaultState': '<S121>:32' */
  }

  /* End of Chart: '<S94>/MainStateMachine' */

  /* Chart: '<S93>/pumperHitSensorView' incorporates:
   *  Constant: '<S93>/ENU_LEFT_BUSY_RIGHT_BUSY'
   *  Constant: '<S93>/ENU_LEFT_BUSY_RIGHT_EMPTY'
   *  Constant: '<S93>/ENU_LEFT_EMPTY_RIGHT_BUSY'
   *  Constant: '<S93>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
   */
  /* Gateway: Routines/HitSensorViewCalculation/pumperHitSensorView */
  RobotControl_DW.encoderStep_prev = RobotControl_DW.encoderStep_start;
  RobotControl_DW.encoderStep_start = RobotControl_B.encoderStep;

  /* During: Routines/HitSensorViewCalculation/pumperHitSensorView */
  if (!RobotControl_DW.doneDoubleBufferReInit) {
    RobotControl_DW.doneDoubleBufferReInit = 1;
    RobotControl_DW.encoderStep_prev = RobotControl_B.encoderStep;
  }

  /* Entry Internal: Routines/HitSensorViewCalculation/pumperHitSensorView */
  /* Transition: '<S120>:67' */
  /* sensorView = 0; */
  if (RobotControl_B.DigitalInput || (RobotControl_DW.encoderStep_prev !=
       RobotControl_DW.encoderStep_start) ||
      RobotControl_B.OutportBufferFortargetReached) {
    /* Transition: '<S120>:70' */
    /* Transition: '<S120>:72' */
    if ((rtb_leftBlocks_uint8 <= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S120>:74' */
      /* Transition: '<S120>:87' */
      RobotControl_B.sensorView = RobotControl_P.ENU_LEFT_BUSY_RIGHT_EMPTY;

      /* Transition: '<S120>:106' */
    } else {
      /* Transition: '<S120>:84' */
    }

    /* Transition: '<S120>:107' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 <= 1)) {
      /* Transition: '<S120>:81' */
      /* Transition: '<S120>:88' */
      RobotControl_B.sensorView = RobotControl_P.ENU_LEFT_EMPTY_RIGHT_BUSY;

      /* Transition: '<S120>:108' */
    } else {
      /* Transition: '<S120>:85' */
    }

    /* Transition: '<S120>:109' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S120>:82' */
      /* Transition: '<S120>:89' */
      RobotControl_B.sensorView = RobotControl_P.ENU_LEFT_EMPTY_RIGHT_EMPTY;

      /* Transition: '<S120>:110' */
    } else {
      /* Transition: '<S120>:86' */
    }

    /* Transition: '<S120>:111' */
    if ((rtb_leftBlocks_uint8 < 1) && (rtb_rightBlocks_uint8 < 1)) {
      /* Transition: '<S120>:83' */
      /* Transition: '<S120>:93' */
      RobotControl_B.sensorView = RobotControl_P.ENU_LEFT_BUSY_RIGHT_BUSY;

      /* Transition: '<S120>:94' */
    } else {
      /* Transition: '<S120>:92' */
    }

    /* Transition: '<S120>:97' */
  } else {
    /* Transition: '<S120>:96' */
  }

  /* End of Chart: '<S93>/pumperHitSensorView' */

  /* Switch: '<S91>/Switch1' incorporates:
   *  Constant: '<S91>/CONST_TWO_F32'
   *  Constant: '<S91>/CONST_ZERO_F32'
   *  Constant: '<S91>/ENU_FORWARD'
   *  Product: '<S91>/Divide'
   *  RelationalOperator: '<S91>/Relational_Operator'
   *  Sum: '<S91>/Add'
   *  UnitDelay: '<S21>/Unit_Delay2'
   */
  /* Transition: '<S120>:99' */
  if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
    RobotControl_B.forwardDist = (RobotControl_B.Data_Type_Conversion +
      RobotControl_B.Data_Type_Conversion_m) / RobotControl_P.CONST_TWO_F32;
  } else {
    RobotControl_B.forwardDist = RobotControl_P.CONST_ZERO_F32;
  }

  /* End of Switch: '<S91>/Switch1' */

  /* UnitDelay: '<S21>/Unit_Delay5' */
  rtb_thetaEncod = RobotControl_DW.Unit_Delay5_DSTATE;

  /* SwitchCase: '<S97>/Switch_Case' */
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
    /* Disable for SwitchCase: '<S103>/Switch_Case' */
    switch (RobotControl_DW.Switch_Case_ActiveSubsystem_j) {
     case 0:
     case 1:
     case 2:
      break;

     case 3:
      /* Disable for Enabled SubSystem: '<S99>/Angle_CalibrationUponReq' */
      if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
        RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
      }

      /* End of Disable for SubSystem: '<S99>/Angle_CalibrationUponReq' */
      break;

     case 4:
      /* Disable for Outport: '<S104>/None' */
      RobotControl_B.DIAG_StatusFlg = RobotControl_P.CONST_DIAG_UNCONFIRM;
      break;
    }

    RobotControl_DW.Switch_Case_ActiveSubsystem_j = -1;

    /* End of Disable for SwitchCase: '<S103>/Switch_Case' */
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S21>/zigzagRoutine' incorporates:
       *  SystemReset for ActionPort: '<S98>/ZigZagActive'
       */
      /* SystemReset for SwitchCase: '<S97>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S98>/ZgZgChart'
       */
      RobotControl_DW.is_faceWest_h = 0U;
      RobotControl_DW.is_active_c25_ROTH = 0U;
      RobotControl_DW.is_c25_ROTH = 0U;
      RobotControl_DW.headingRequest = 0U;
      RobotControl_DW.finishCounter = 0U;
      RobotControl_DW.initHeading = 0.0;
      RobotControl_B.moveRequest_i = 0U;
      RobotControl_B.zgzgActive = true;
      RobotControl_B.switchLaneFlg_BOOL = false;
      RobotControl_B.swLaneCnt_uint8 = 0U;

      /* End of SystemReset for SubSystem: '<S21>/zigzagRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S21>/zigzagRoutine' incorporates:
     *  ActionPort: '<S98>/ZigZagActive'
     */
    /* DataTypeConversion: '<S98>/Data Type Conversion1' */
    RobotControl_B.DataTypeConversion1_e = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S98>/Data Type Conversion2' */
    RobotControl_B.DataTypeConversion2_m = RobotControl_B.ROB_EAST;

    /* DataTypeConversion: '<S98>/Data Type Conversion3' */
    RobotControl_B.DataTypeConversion3_g = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S98>/Data Type Conversion4' */
    RobotControl_B.DataTypeConversion4_m = RobotControl_B.ROB_SOUTH;

    /* Chart: '<S98>/ZgZgChart' incorporates:
     *  TriggerPort: '<S123>/input events'
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
      /* Gateway: Routines/zigzagRoutine/ZgZgChart */
      if ((int8_T)(zcEvent_idx_0 ? RobotControl_B.refreshEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S123>:89' */
        RobotControl_DW.sfEvent_j = RobotContr_event_refreshEvent_p;
        RobotControl_chartstep_c25_ROTH();
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S123>:88' */
        RobotControl_DW.sfEvent_j = RobotControl_event_stopEvent_n;
        RobotControl_chartstep_c25_ROTH();
      }
    }

    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S98>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_i;

    /* SignalConversion: '<S98>/OutportBufferForswLaneCnt_uint8' */
    RobotControl_B.OutportBufferForswLaneCnt_uint8 =
      RobotControl_B.swLaneCnt_uint8;

    /* SignalConversion: '<S98>/OutportBufferForswitchLaneFlg_BOOL' */
    RobotControl_B.OutportBufferForswitchLaneFlg_k =
      RobotControl_B.switchLaneFlg_BOOL;

    /* SignalConversion: '<S98>/OutportBufferForzgzgActive' */
    RobotControl_B.OutportBufferForzgzgActive = RobotControl_B.zgzgActive;

    /* End of Outputs for SubSystem: '<S21>/zigzagRoutine' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S21>/StartPointRoutine' incorporates:
       *  SystemReset for ActionPort: '<S95>/GTSPActive'
       */
      /* SystemReset for SwitchCase: '<S97>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S95>/GTSP_Chart'
       */
      RobotControl_DW.is_GTSP_Active = 0U;
      RobotControl_DW.is_MostSouthLeft = 0U;
      RobotControl_DW.is_facingSouth = 0U;
      RobotControl_DW.is_GTSPsearch = 0U;
      RobotControl_DW.is_faceWest = 0U;
      RobotControl_DW.is_active_c24_ROTH = 0U;
      RobotControl_DW.is_c24_ROTH = 0U;
      RobotControl_DW.counter = 0U;
      RobotControl_DW.round = 0U;
      RobotControl_DW.step1Flag = 0U;
      RobotControl_DW.initHeading_p = false;
      RobotControl_DW.activeFlag = false;
      RobotControl_DW.tempDist_f = 0.0F;
      RobotControl_B.moveRequest_p = 0U;
      RobotControl_B.GT_active = true;

      /* End of SystemReset for SubSystem: '<S21>/StartPointRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S21>/StartPointRoutine' incorporates:
     *  ActionPort: '<S95>/GTSPActive'
     */
    /* DataTypeConversion: '<S95>/Data Type Conversion' */
    RobotControl_B.DataTypeConversion = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S95>/Data Type Conversion1' */
    RobotControl_B.DataTypeConversion1_g = RobotControl_B.ROB_SOUTH;

    /* DataTypeConversion: '<S95>/Data Type Conversion2' */
    RobotControl_B.DataTypeConversion2 = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S95>/Data Type Conversion3' */
    RobotControl_B.DataTypeConversion3_l = RobotControl_B.ROB_EAST;

    /* Chart: '<S95>/GTSP_Chart' incorporates:
     *  TriggerPort: '<S122>/input events'
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
      /* Gateway: Routines/StartPointRoutine/GTSP_Chart */
      if ((int8_T)(zcEvent_idx_0 ? RobotControl_B.refreshEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S122>:146' */
        RobotControl_DW.sfEvent = RobotContr_event_refreshEvent_p;
        RobotControl_chartstep_c24_ROTH();
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S122>:145' */
        RobotControl_DW.sfEvent = RobotControl_event_stopEvent_n;
        RobotControl_chartstep_c24_ROTH();
      }
    }

    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S95>/OutportBufferForGT_active' */
    RobotControl_B.OutportBufferForGT_active = RobotControl_B.GT_active;

    /* SignalConversion: '<S95>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_p;

    /* End of Outputs for SubSystem: '<S21>/StartPointRoutine' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S21>/DIAG_Routine' incorporates:
     *  ActionPort: '<S90>/DIAG_Active'
     */
    /* Chart: '<S118>/HighLevelDiagTestControl' incorporates:
     *  Constant: '<S90>/ENU_PASSED'
     *  UnitDelay: '<S90>/Unit_Delay'
     *  UnitDelay: '<S90>/Unit_Delay1'
     *  UnitDelay: '<S90>/Unit_Delay2'
     */
    /* Gateway: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
    if (RobotControl_DW.temporalCounter_i1_c < 15U) {
      RobotControl_DW.temporalCounter_i1_c++;
    }

    /* During: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
    if (RobotControl_DW.is_active_c26_ROTH == 0U) {
      /* Entry: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      RobotControl_DW.is_active_c26_ROTH = 1U;

      /* Entry Internal: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      /* Transition: '<S119>:54' */
      /* Transition: '<S119>:52' */
      RobotControl_B.enableAngleCalib_BOOL = true;
      RobotControl_DW.is_c26_ROTH = RobotControl_IN_AngleCalib;

      /* Entry 'AngleCalib': '<S119>:50' */
      RobotControl_B.diagEnableReq = RobotContr_ENU_DIAG_ANGLE_CALIB;
    } else if (RobotControl_DW.is_c26_ROTH == RobotControl_IN_AngleCalib) {
      /* During 'AngleCalib': '<S119>:50' */
      if (RobotControl_DW.Unit_Delay2_DSTATE_h == RobotControl_ENU_FINISHED_b) {
        /* Transition: '<S119>:55' */
        RobotControl_B.enableAngleCalib_BOOL = false;
        RobotControl_DW.is_c26_ROTH = RobotControl_IN_SelfDiag;

        /* Entry Internal 'SelfDiag': '<S119>:49' */
        /* Transition: '<S119>:3' */
        RobotControl_DW.is_SelfDiag = RobotControl_IN_CompassRoutine;
        RobotControl_DW.temporalCounter_i1_c = 0U;
      }
    } else {
      /* During 'SelfDiag': '<S119>:49' */
      switch (RobotControl_DW.is_SelfDiag) {
       case RobotControl_IN_BlueTooth:
        /* During 'BlueTooth': '<S119>:8' */
        if (RobotControl_P.ENU_PASSED == RobotControl_ENU_FAILED) {
          /* Transition: '<S119>:19' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S119>:14' */
        } else {
          if (RobotControl_P.ENU_PASSED == RobotControl_ENU_PASSED) {
            /* Transition: '<S119>:43' */
            RobotControl_DW.is_SelfDiag = RobotContro_IN_SelfDiagComplete;

            /* Entry 'SelfDiagComplete': '<S119>:46' */
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_NONE;
          }
        }
        break;

       case RobotControl_IN_CompassRoutine:
        /* During 'CompassRoutine': '<S119>:4' */
        if (RobotControl_DW.Unit_Delay_DSTATE_j == RobotControl_ENU_PASSED) {
          /* Transition: '<S119>:9' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_EncoderRoutine;

          /* Entry 'EncoderRoutine': '<S119>:5' */
          RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_ENCOD;
        } else if (RobotControl_DW.Unit_Delay_DSTATE_j ==
                   RobotControl_ENU_FAILED) {
          /* Transition: '<S119>:15' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S119>:14' */
        } else {
          if (RobotControl_DW.temporalCounter_i1_c >=
              Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_COMP;
          }
        }
        break;

       case RobotControl_IN_EncoderRoutine:
        /* During 'EncoderRoutine': '<S119>:5' */
        if (RobotControl_DW.Unit_Delay1_DSTATE == RobotControl_ENU_FAILED) {
          /* Transition: '<S119>:16' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S119>:14' */
        } else {
          if (RobotControl_DW.Unit_Delay1_DSTATE == RobotControl_ENU_PASSED) {
            /* Transition: '<S119>:10' */
            RobotControl_DW.is_SelfDiag = RobotControl_IN_BlueTooth;

            /* Entry 'BlueTooth': '<S119>:8' */
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_BLTOTH;
          }
        }
        break;

       case RobotControl_IN_Failed:
        /* During 'Failed': '<S119>:14' */
        break;

       default:
        /* During 'SelfDiagComplete': '<S119>:46' */
        break;
      }
    }

    /* End of Chart: '<S118>/HighLevelDiagTestControl' */

    /* Product: '<S105>/Product' incorporates:
     *  Constant: '<S105>/CAL_Wheel2WheelDist_mm'
     *  Constant: '<S105>/CONST_PI_F32'
     *  Constant: '<S105>/CONST_TWO_F32'
     *  Constant: '<S105>/CONST_TWO_F321'
     *  Product: '<S105>/Divide'
     *  Product: '<S105>/Divide1'
     */
    rtb_quarterTurnTargetDist_mm = RobotControl_P.CONST_PI_F32 /
      RobotControl_P.CONST_TWO_F32 * ((real32_T)
      RobotControl_P.CAL_Wheel2WheelDist_mm / RobotControl_P.CONST_TWO_F32);

    /* SwitchCase: '<S103>/Switch_Case' */
    rtPrevAction = RobotControl_DW.Switch_Case_ActiveSubsystem_j;
    switch ((int32_T)RobotControl_B.diagEnableReq) {
     case 1L:
      rtAction = 0;
      break;

     case 2L:
      rtAction = 1;
      break;

     case 5L:
      rtAction = 2;
      break;

     case 6L:
      rtAction = 3;
      break;

     default:
      rtAction = 4;
      break;
    }

    RobotControl_DW.Switch_Case_ActiveSubsystem_j = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
       case 1:
       case 2:
        break;

       case 3:
        /* Disable for Enabled SubSystem: '<S99>/Angle_CalibrationUponReq' */
        if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
        }

        /* End of Disable for SubSystem: '<S99>/Angle_CalibrationUponReq' */
        break;

       case 4:
        /* Disable for Outport: '<S104>/None' */
        RobotControl_B.DIAG_StatusFlg = RobotControl_P.CONST_DIAG_UNCONFIRM;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* DataTypeConversion: '<S108>/Data Type Conversion1' */
      RobotControl_B.DataTypeConversion1 = RobotControl_B.ROB_EAST;

      /* DataTypeConversion: '<S108>/Data Type Conversion3' */
      RobotControl_B.DataTypeConversion3 = RobotControl_B.ROB_NORTH;

      /* DataTypeConversion: '<S108>/Data Type Conversion4' */
      RobotControl_B.DataTypeConversion4 = RobotControl_B.ROB_SOUTH;

      /* DataTypeConversion: '<S108>/Data Type Conversion5' */
      RobotControl_B.DataTypeConversion5 = RobotControl_B.ROB_WEST;

      /* Chart: '<S109>/EncoderHeadingHandler' */
      /* Gateway: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* During: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* Entry Internal: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* Transition: '<S111>:55' */
      if ((rtb_thetaEncod <= 280.0F) && (rtb_thetaEncod >= 260.0F)) {
        /* Transition: '<S111>:46' */
        /* NORTH */
        /* Transition: '<S111>:50' */
        rtb_quarterTurnTargetDist_mm = 270.0F;

        /* Transition: '<S111>:43' */
        /* Transition: '<S111>:41' */
        /* Transition: '<S111>:54' */
        /* Transition: '<S111>:42' */
      } else {
        /* Transition: '<S111>:51' */
        if ((rtb_thetaEncod <= 100.0F) && (rtb_thetaEncod >= 80.0F)) {
          /* Transition: '<S111>:62' */
          /* SOUTH */
          /* Transition: '<S111>:53' */
          rtb_quarterTurnTargetDist_mm = 90.0F;

          /* Transition: '<S111>:41' */
          /* Transition: '<S111>:54' */
          /* Transition: '<S111>:42' */
        } else {
          /* Transition: '<S111>:52' */
          if ((rtb_thetaEncod <= RobotCont_CAL_ROB_ERRVAL_ENCODE) ||
              (rtb_thetaEncod >= 350.0F)) {
            /* Transition: '<S111>:59' */
            /* EAST */
            /* Transition: '<S111>:63' */
            rtb_quarterTurnTargetDist_mm = 0.0F;

            /* Transition: '<S111>:54' */
            /* Transition: '<S111>:42' */
          } else {
            /* Transition: '<S111>:45' */
            if ((rtb_thetaEncod <= 190.0F) && (rtb_thetaEncod >= 170.0F)) {
              /* Transition: '<S111>:60' */
              /* WEST */
              /* Transition: '<S111>:40' */
              rtb_quarterTurnTargetDist_mm = 180.0F;

              /* Transition: '<S111>:42' */
            } else {
              /* Transition: '<S111>:39' */
              rtb_quarterTurnTargetDist_mm = 400.0F;
            }
          }
        }
      }

      /* End of Chart: '<S109>/EncoderHeadingHandler' */

      /* Chart: '<S108>/CompassSelfDiagTestChart' */
      /* Transition: '<S111>:65' */
      /* Gateway: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
      /* During: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
      if (RobotControl_DW.is_active_c31_ROTH == 0U) {
        /* Entry: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        RobotControl_DW.is_active_c31_ROTH = 1U;

        /* Entry Internal: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        /* Transition: '<S110>:2' */
        RobotControl_DW.is_c31_ROTH = RobotControl_IN_init_m;

        /* Entry 'init': '<S110>:1' */
        RobotControl_B.comTstStatus = RobotControl_ENU_TEST_INIT;
        RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
        RobotControl_DW.steps = 0U;
        RobotControl_DW.filterToleranceCnt = 0U;
      } else {
        switch (RobotControl_DW.is_c31_ROTH) {
         case RobotControl_IN_DiagPassed:
          /* During 'DiagPassed': '<S110>:8' */
          break;

         case RobotControl_IN_init_m:
          /* During 'init': '<S110>:1' */
          if ((RobotControl_B.currentHeading != RobotControl_ENU_ROB_NONE) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S110>:4' */
            RobotControl_DW.startHeading = RobotControl_B.currentHeading;
            RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnHandler;
            RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

            /* Entry 'Stop': '<S110>:5' */
            RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
            RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
          }
          break;

         case RobotControl_IN_turnHandler:
          /* During 'turnHandler': '<S110>:43' */
          if ((RobotControl_DW.steps > 0) &&
              RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_B.currentHeading != (uint16_T)
               rtb_quarterTurnTargetDist_mm) &&
              (RobotControl_DW.filterToleranceCnt >
               RobotCont_CONST_ERROR_TOLERANCE)) {
            /* Transition: '<S110>:44' */
            /* Exit Internal 'turnHandler': '<S110>:43' */
            RobotControl_DW.is_turnHandler = 0U;
            RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnRightFault;

            /* Entry 'turnRightFault': '<S110>:7' */
            RobotControl_B.compFaultFlag = true;
            RobotControl_B.comTstStatus = RobotControl_ENU_FAILED;
          } else {
            switch (RobotControl_DW.is_turnHandler) {
             case RobotControl_IN_Stop_o:
              /* During 'Stop': '<S110>:5' */
              if (RobotControl_DW.steps == 0) {
                /* Transition: '<S110>:38' */
                RobotControl_DW.steps++;
                RobotControl_B.moveReq_p = RobotCont_ENU_MOVE_TURN_RIGHT_d;
                RobotControl_DW.is_turnHandler = RobotControl_IN_turnRight_l;
              } else if (RobotControl_directionCheck((real_T)
                          RobotControl_DW.startHeading, (real_T)
                          rtb_quarterTurnTargetDist_mm, (real_T)
                          RobotControl_CAL_NORTH, 0.0, (real_T)
                          RobotControl_CAL_SOUTH, (real_T)RobotControl_CAL_WEST,
                          (real_T)rtb_quarterTurnTargetDist_mm) != 0.0) {
                /* Transition: '<S110>:9' */
                RobotControl_DW.is_turnHandler = 0U;
                RobotControl_DW.is_c31_ROTH = RobotControl_IN_DiagPassed;

                /* Entry 'DiagPassed': '<S110>:8' */
                RobotControl_B.compFaultFlag = false;
                RobotControl_B.comTstStatus = RobotControl_ENU_PASSED;
              } else if (RobotControl_DW.steps == 1) {
                /* Transition: '<S110>:39' */
                RobotControl_DW.steps++;
                RobotControl_B.moveReq_p = RobotContr_ENU_MOVE_TURN_LEFT_l;
                RobotControl_DW.is_turnHandler = RobotControl_IN_turnLeft_n;
              } else {
                if ((RobotControl_DW.steps == 2) &&
                    RobotControl_B.OutportBufferFortargetReached && ((uint16_T)
                     rtb_quarterTurnTargetDist_mm !=
                     RobotControl_B.currentHeading)) {
                  /* Transition: '<S110>:123' */
                  RobotControl_DW.is_turnHandler = 0U;
                  RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnRightFault;

                  /* Entry 'turnRightFault': '<S110>:7' */
                  RobotControl_B.compFaultFlag = true;
                  RobotControl_B.comTstStatus = RobotControl_ENU_FAILED;
                }
              }
              break;

             case RobotControl_IN_turnLeft_n:
              /* During 'turnLeft': '<S110>:35' */
              if (RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_directionCheck((real_T)
                    RobotControl_DW.startHeading, (real_T)
                    RobotControl_B.currentHeading, (real_T)
                    RobotControl_B.DataTypeConversion3, (real_T)
                    RobotControl_B.DataTypeConversion1, (real_T)
                    RobotControl_B.DataTypeConversion4, (real_T)
                    RobotControl_B.DataTypeConversion5, (real_T)
                    rtb_quarterTurnTargetDist_mm) != 0.0)) {
                /* Transition: '<S110>:36' */
                RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

                /* Entry 'Stop': '<S110>:5' */
                RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
                RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
              } else {
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_B.currentHeading != (uint16_T)
                     rtb_quarterTurnTargetDist_mm)) {
                  /* Transition: '<S110>:114' */
                  RobotControl_DW.filterToleranceCnt++;
                  RobotControl_DW.is_turnHandler = RobotControl_IN_turnLeft_n;
                }
              }
              break;

             default:
              /* During 'turnRight': '<S110>:3' */
              if (RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_directionCheck((real_T)
                    RobotControl_DW.startHeading, (real_T)
                    RobotControl_B.currentHeading, (real_T)
                    RobotControl_B.DataTypeConversion1, (real_T)
                    RobotControl_B.DataTypeConversion4, (real_T)
                    RobotControl_B.DataTypeConversion5, (real_T)
                    RobotControl_B.DataTypeConversion3, (real_T)
                    rtb_quarterTurnTargetDist_mm) != 0.0)) {
                /* Transition: '<S110>:6' */
                RobotControl_DW.filterToleranceCnt = 0U;
                RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

                /* Entry 'Stop': '<S110>:5' */
                RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
                RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
              } else {
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_B.currentHeading != (uint16_T)
                     rtb_quarterTurnTargetDist_mm)) {
                  /* Transition: '<S110>:112' */
                  /* moveReq = ENU_STOP; */
                  RobotControl_DW.filterToleranceCnt++;
                  RobotControl_DW.is_turnHandler = RobotControl_IN_turnRight_l;
                }
              }
              break;
            }
          }
          break;

         default:
          /* During 'turnRightFault': '<S110>:7' */
          break;
        }
      }

      /* End of Chart: '<S108>/CompassSelfDiagTestChart' */

      /* SignalConversion: '<S101>/OutportBufferFormoveRequest' */
      RobotControl_B.Merge = RobotControl_B.moveReq_p;

      /* End of Outputs for SubSystem: '<S90>/CompassTest' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S90>/EncoderTest' incorporates:
       *  ActionPort: '<S102>/EncoderTest'
       */
      /* SignalConversion: '<S102>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S102>/ENU_MOVE_TURN_LEFT'
       */
      RobotControl_B.Merge = RobotControl_P.ENU_MOVE_TURN_LEFT;

      /* Chart: '<S114>/DeltaDistCalculator' */
      RobotContro_DeltaDistCalculator
        (RobotControl_B.OutportBufferFortargetReached,
         RobotControl_B.Data_Type_Conversion_m,
         &RobotControl_B.sf_DeltaDistCalculator,
         &RobotControl_DW.sf_DeltaDistCalculator);

      /* Logic: '<S112>/Logical_Operator' incorporates:
       *  Abs: '<S112>/Abs'
       *  Constant: '<S112>/CONST_MinDistError_mm'
       *  DataTypeConversion: '<S112>/Data_Type_Conversion'
       *  RelationalOperator: '<S112>/Relational_Operator'
       *  Sum: '<S112>/Subtract'
       */
      RobotControl_B.encoderDistErrorFlg_BOOL =
        (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
          (RobotControl_B.sf_DeltaDistCalculator.deltaDistTrav) -
          rtb_quarterTurnTargetDist_mm > RobotControl_P.CONST_MinDistError_mm));

      /* Chart: '<S116>/DeltaDistCalculator' */
      RobotContro_DeltaDistCalculator
        (RobotControl_B.OutportBufferFortargetReached,
         RobotControl_B.Data_Type_Conversion,
         &RobotControl_B.sf_DeltaDistCalculator_d,
         &RobotControl_DW.sf_DeltaDistCalculator_d);

      /* Logic: '<S113>/Logical_Operator' incorporates:
       *  Abs: '<S113>/Abs'
       *  Constant: '<S113>/CONST_MinDistError_mm'
       *  DataTypeConversion: '<S113>/Data_Type_Conversion'
       *  RelationalOperator: '<S113>/Relational_Operator'
       *  Sum: '<S113>/Subtract'
       */
      RobotControl_B.encoderDistErrorFlg_BOOL_m =
        (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
          (RobotControl_B.sf_DeltaDistCalculator_d.deltaDistTrav) -
          rtb_quarterTurnTargetDist_mm > RobotControl_P.CONST_MinDistError_mm));

      /* Switch: '<S102>/Switch' incorporates:
       *  Constant: '<S102>/ENU_FAILED'
       *  Constant: '<S102>/ENU_TEST_NOT_CONFIRMED'
       *  Logic: '<S102>/Logical_Operator'
       *  Logic: '<S102>/Logical_Operator1'
       *  Switch: '<S102>/Switch1'
       */
      if ((RobotControl_B.encoderDistErrorFlg_BOOL ||
           RobotControl_B.encoderDistErrorFlg_BOOL_m) &&
          RobotControl_B.OutportBufferFortargetReached) {
        RobotControl_B.encoderTstStatus = RobotControl_P.ENU_FAILED;
      } else if (RobotControl_B.OutportBufferFortargetReached) {
        /* Switch: '<S102>/Switch1' incorporates:
         *  Constant: '<S102>/ENU_PASSED'
         */
        RobotControl_B.encoderTstStatus = RobotControl_P.ENU_PASSED;
      } else {
        RobotControl_B.encoderTstStatus = RobotControl_P.ENU_TEST_NOT_CONFIRMED;
      }

      /* End of Switch: '<S102>/Switch' */
      /* End of Outputs for SubSystem: '<S90>/EncoderTest' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S90>/Bluetooth' incorporates:
       *  ActionPort: '<S100>/Bluetooth'
       */
      /* SignalConversion: '<S100>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S100>/ENU_STOP'
       */
      RobotControl_B.Merge = RobotControl_P.ENU_STOP;

      /* End of Outputs for SubSystem: '<S90>/Bluetooth' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S90>/Angle_Calibration' incorporates:
       *  ActionPort: '<S99>/Angle_Calibration'
       */
      /* Outputs for Enabled SubSystem: '<S99>/Angle_CalibrationUponReq' incorporates:
       *  EnablePort: '<S106>/NVM_AngleStoreFlgEnable'
       */
      if (RobotControl_ConstB.Logical_Operator) {
        if (!RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          /* SystemReset for Chart: '<S106>/CompassSelfDiagTestChart' */
          RobotControl_DW.temporalCounter_i1_k3 = 0U;
          RobotControl_DW.is_active_c27_ROTH = 0U;
          RobotControl_DW.is_c27_ROTH = 0U;
          RobotControl_DW.angleFinishFlg = false;
          RobotControl_B.moveReq = 0U;
          RobotControl_B.angleCalibStatus = 3U;
          RobotControl_DW.Angle_CalibrationUponReq_MODE = true;
        }

        /* Chart: '<S106>/CompassSelfDiagTestChart' */
        /* Gateway: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
        if (RobotControl_DW.temporalCounter_i1_k3 < 15U) {
          RobotControl_DW.temporalCounter_i1_k3++;
        }

        /* During: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
        if (RobotControl_DW.is_active_c27_ROTH == 0U) {
          /* Entry: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          RobotControl_DW.is_active_c27_ROTH = 1U;

          /* Entry Internal: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          /* Transition: '<S107>:2' */
          RobotControl_DW.is_c27_ROTH = RobotControl_IN_initFacingNorth;

          /* Entry 'initFacingNorth': '<S107>:1' */
          RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
          RobotControl_B.angleCalibStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
          RobotControl_DW.angleFinishFlg = false;
        } else {
          switch (RobotControl_DW.is_c27_ROTH) {
           case RobotControl_IN_FacingEAST:
            /* During 'FacingEAST': '<S107>:38' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S107>:40' */
              RobotControl_DW.angleFinishFlg = true;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S107>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_FacingSOUTH:
            /* During 'FacingSOUTH': '<S107>:41' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S107>:43' */
              RobotControl_DW.angleFinishFlg = false;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S107>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_FacingWEST:
            /* During 'FacingWEST': '<S107>:44' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S107>:61' */
              RobotControl_DW.angleFinishFlg = true;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S107>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_Moving:
            /* During 'Moving': '<S107>:36' */
            if ((RobotControl_B.currentHeading == RobotControl_CAL_EAST) &&
                (!RobotControl_DW.angleFinishFlg) &&
                RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S107>:39' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingEAST;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingEAST': '<S107>:38' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
            } else if ((RobotControl_B.currentHeading == RobotControl_CAL_SOUTH)
                       && RobotControl_DW.angleFinishFlg &&
                       RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S107>:42' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingSOUTH;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingSOUTH': '<S107>:41' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
            } else if ((RobotControl_B.currentHeading == RobotControl_CAL_WEST) &&
                       (!RobotControl_DW.angleFinishFlg) &&
                       RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S107>:45' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingWEST;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingWEST': '<S107>:44' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
            } else {
              if ((RobotControl_B.currentHeading == RobotControl_CAL_NORTH) &&
                  RobotControl_DW.angleFinishFlg &&
                  RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_DW.temporalCounter_i1_k3 >=
                   Ro_CONST_COMPASS_DIAG_FIN_TIMER)) {
                /* Transition: '<S107>:59' */
                RobotControl_DW.is_c27_ROTH = RobotContr_IN_finishFacingNorth;

                /* Entry 'finishFacingNorth': '<S107>:60' */
                RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
                RobotControl_B.angleCalibStatus = RobotControl_ENU_FINISHED_b;
              }
            }
            break;

           case RobotContr_IN_finishFacingNorth:
            /* During 'finishFacingNorth': '<S107>:60' */
            break;

           default:
            /* During 'initFacingNorth': '<S107>:1' */
            /* Transition: '<S107>:37' */
            RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
            RobotControl_DW.temporalCounter_i1_k3 = 0U;

            /* Entry 'Moving': '<S107>:36' */
            RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            break;
          }
        }

        /* End of Chart: '<S106>/CompassSelfDiagTestChart' */

        /* SignalConversion: '<S106>/OutportBufferForangleCalibStatus' */
        RobotControl_B.OutportBufferForangleCalibSta_a =
          RobotControl_B.angleCalibStatus;

        /* SignalConversion: '<S106>/OutportBufferFormoveRequest' */
        RobotControl_B.OutportBufferFormoveRequest = RobotControl_B.moveReq;
      } else {
        if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S99>/Angle_CalibrationUponReq' */

      /* SignalConversion: '<S99>/OutportBufferForangleCalibStatus' */
      RobotControl_B.OutportBufferForangleCalibStatu =
        RobotControl_B.OutportBufferForangleCalibSta_a;

      /* SignalConversion: '<S99>/OutportBufferFormoveRequest' */
      RobotControl_B.Merge = RobotControl_B.OutportBufferFormoveRequest;

      /* End of Outputs for SubSystem: '<S90>/Angle_Calibration' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S90>/None' incorporates:
       *  ActionPort: '<S104>/DefaultDiagCase'
       */
      /* SignalConversion: '<S104>/OutportBufferForNone' incorporates:
       *  Constant: '<S104>/CONST_DIAG_FINISH_FLG'
       */
      RobotControl_B.DIAG_StatusFlg = RobotControl_P.CONST_DIAG_FINISH_FLG;

      /* SignalConversion: '<S104>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S104>/ENU_STOP'
       */
      RobotControl_B.Merge = RobotControl_P.ENU_STOP;

      /* End of Outputs for SubSystem: '<S90>/None' */
      break;
    }

    /* End of SwitchCase: '<S103>/Switch_Case' */

    /* Logic: '<S90>/Logical_Operator' */
    RobotControl_B.hardwareFaultFlg = (RobotControl_B.compFaultFlag ||
      RobotControl_B.encoderDistErrorFlg_BOOL_m ||
      RobotControl_B.encoderDistErrorFlg_BOOL);

    /* SignalConversion: '<S90>/OutportBufferForDIAG_StatusFlg' */
    RobotControl_B.OutportBufferForDIAG_StatusFlg =
      RobotControl_B.DIAG_StatusFlg;

    /* SignalConversion: '<S90>/OutportBufferForenableAngleCalib_BOOL' */
    RobotControl_B.OutportBufferForenableAngleCali =
      RobotControl_B.enableAngleCalib_BOOL;

    /* Update for UnitDelay: '<S90>/Unit_Delay1' */
    RobotControl_DW.Unit_Delay1_DSTATE = RobotControl_B.encoderTstStatus;

    /* Update for UnitDelay: '<S90>/Unit_Delay' */
    RobotControl_DW.Unit_Delay_DSTATE_j = RobotControl_B.comTstStatus;

    /* Update for UnitDelay: '<S90>/Unit_Delay2' */
    RobotControl_DW.Unit_Delay2_DSTATE_h =
      RobotControl_B.OutportBufferForangleCalibStatu;

    /* End of Outputs for SubSystem: '<S21>/DIAG_Routine' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S21>/End' incorporates:
     *  ActionPort: '<S92>/ENDactive'
     */
    /* DataTypeConversion: '<S92>/Data_Type_Conversion' incorporates:
     *  Constant: '<S92>/ENU_STOP'
     */
    RobotControl_B.Merge = RobotControl_P.ENU_STOP;

    /* End of Outputs for SubSystem: '<S21>/End' */
    break;
  }

  /* End of SwitchCase: '<S97>/Switch_Case' */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  RobotControl_B.diagSensorFailure = RobotControl_B.hardwareFaultFlg;

  /* SignalConversion: '<S21>/OutportBufferForswitchLaneFlg_BOOL' */
  RobotControl_B.OutportBufferForswitchLaneFlg_B =
    RobotControl_B.OutportBufferForswitchLaneFlg_k;

  /* Switch: '<S21>/Switch' */
  if (RobotControl_B.hitRoutineRun) {
    RobotControl_B.moveRequest = RobotControl_B.moveRequest_n;
  } else {
    RobotControl_B.moveRequest = RobotControl_B.Merge;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Update for UnitDelay: '<S21>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_h = RobotControl_B.OutportBufferForGT_active;

  /* Update for UnitDelay: '<S21>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_c =
    RobotControl_B.OutportBufferForzgzgActive;

  /* Update for UnitDelay: '<S21>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_b =
    RobotControl_B.OutportBufferForDIAG_StatusFlg;

  /* Update for UnitDelay: '<S21>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE = RobotControl_B.Data_Type_Conversion_a;
}
