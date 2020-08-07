/*
 * File: HighLevelRoutines.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.559
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Aug 07 13:50:23 2020
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

/* Named constants for Chart: '<S120>/DeltaDistCalculator' */
#define RobotCont_IN_NO_ACTIVE_CHILD_iw ((uint8_T)0U)
#define RobotControl_IN_StartTurn      ((uint8_T)1U)
#define RobotControl_IN_targetReached  ((uint8_T)2U)

/* Named constants for Chart: '<S100>/MainStateMachine' */
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

/* Named constants for Chart: '<S104>/ZgZgChart' */
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

/* Named constants for Chart: '<S101>/GTSP_Chart' */
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

/* Named constants for Chart: '<S124>/HighLevelDiagTestControl' */
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

/* Named constants for Chart: '<S114>/CompassSelfDiagTestChart' */
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

/* Named constants for Chart: '<S115>/EncoderHeadingHandler' */
#define RobotCont_CAL_ROB_ERRVAL_ENCODE ((uint8_T)10U)

/* Named constants for Chart: '<S112>/CompassSelfDiagTestChart' */
#define RobotContr_IN_finishFacingNorth ((uint8_T)5U)
#define RobotControl_IN_FacingEAST     ((uint8_T)1U)
#define RobotControl_IN_FacingSOUTH    ((uint8_T)2U)
#define RobotControl_IN_FacingWEST     ((uint8_T)3U)
#define RobotControl_IN_Moving         ((uint8_T)4U)
#define RobotControl_IN_initFacingNorth ((uint8_T)6U)

/* Forward declaration for local functions */
static void RobotControl_chartstep_c25_ROTH(const real32_T
  *DataTypeConversion1_e, const real32_T *DataTypeConversion2_m, const real32_T *
  DataTypeConversion3_g, real32_T *DataTypeConversion4_m);
static void RobotControl_chartstep_c24_ROTH(const real32_T *forwardDist, const
  real32_T *DataTypeConversion, const real32_T *DataTypeConversion1_g, real32_T *
  DataTypeConversion2, real32_T *DataTypeConversion3_l);
static real_T RobotControl_directionCheck(real_T strtHeading, real_T
  CurrentHeading, real_T N, real_T E, real_T S, real_T W, real_T enTheta, const
  real32_T *DataTypeConversion1, const real32_T *DataTypeConversion3, const
  real32_T *DataTypeConversion4, real32_T *DataTypeConversion5);

/*
 * System initialize for atomic system:
 *    '<S120>/DeltaDistCalculator'
 *    '<S122>/DeltaDistCalculator'
 */
void RobotC_DeltaDistCalculator_Init(B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  localDW->is_active_c30_ROTH = 0U;
  localDW->is_c30_ROTH = RobotCont_IN_NO_ACTIVE_CHILD_iw;
  localDW->tempDist = 0.0F;
  localB->deltaDistTrav = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S120>/DeltaDistCalculator'
 *    '<S122>/DeltaDistCalculator'
 */
void RobotContro_DeltaDistCalculator(boolean_T rtu_targetReached, real32_T
  rtu_rightDistTravelled_mm, B_DeltaDistCalculator_RobotCo_T *localB,
  DW_DeltaDistCalculator_RobotC_T *localDW)
{
  /* Gateway: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  /* During: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
  /* Calculates delta distance traveled by robot while making quarter turn */
  if (localDW->is_active_c30_ROTH == 0U) {
    /* Entry: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    localDW->is_active_c30_ROTH = 1U;

    /* Entry Internal: Routines/DIAG_Routine/EncoderTest/LeftEncoderTest/DeltaDistCalculator/DeltaDistCalculator */
    /* Transition: '<S121>:2' */
    localDW->is_c30_ROTH = RobotControl_IN_StartTurn;

    /* Entry 'StartTurn': '<S121>:1' */
    localDW->tempDist = rtu_rightDistTravelled_mm;
  } else if ((localDW->is_c30_ROTH == RobotControl_IN_StartTurn) &&
             rtu_targetReached) {
    /* During 'StartTurn': '<S121>:1' */
    /* Transition: '<S121>:7' */
    localDW->is_c30_ROTH = RobotControl_IN_targetReached;

    /* Entry 'targetReached': '<S121>:6' */
    localB->deltaDistTrav = rtu_rightDistTravelled_mm - localDW->tempDist;
  } else {
    /* During 'targetReached': '<S121>:6' */
  }
}

/* Function for Chart: '<S104>/ZgZgChart' */
static void RobotControl_chartstep_c25_ROTH(const real32_T
  *DataTypeConversion1_e, const real32_T *DataTypeConversion2_m, const real32_T *
  DataTypeConversion3_g, real32_T *DataTypeConversion4_m)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;

  /* During: Routines/zigzagRoutine/ZgZgChart */
  /* zigzag is the main state machine for covering the area  */
  if (RobotControl_DW.is_active_c25_ROTH == 0U) {
    /* Entry: Routines/zigzagRoutine/ZgZgChart */
    RobotControl_DW.is_active_c25_ROTH = 1U;

    /* Entry Internal: Routines/zigzagRoutine/ZgZgChart */
    /* Transition: '<S129>:28' */
    RobotControl_DW.is_c25_ROTH = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S129>:27' */
    RobotControl_B.zgzgActive = true;
    RobotControl_DW.finishCounter = 1U;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (RobotControl_DW.is_c25_ROTH) {
     case RobotControl_IN_Freeze:
      /* During 'Freeze': '<S129>:121' */
      if (RobotControl_DW.sfEvent_j == RobotControl_event_stopEvent_n) {
        /* Transition: '<S129>:32' */
        if (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY))
        {
          /* Transition: '<S129>:38' */
          if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
            /* Constant: '<S104>/ENU_MOVE_U_TURN_RIGHT' */
            /* Transition: '<S129>:41' */
            RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN_RIGHT);
            RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4_m;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S129>:31' */
            RobotControl_B.switchLaneFlg_BOOL = true;
            RobotControl_B.swLaneCnt_uint8++;
          } else if (RobotControl_B.currentHeading == *DataTypeConversion4_m) {
            /* Constant: '<S104>/ENU_MOVE_U_TURN_LEFT' */
            /* Transition: '<S129>:43' */
            RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN_LEFT);
            RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
            RobotControl_DW.finishCounter = 1U;
            RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

            /* Entry 'SwitchLane': '<S129>:31' */
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
      /* During 'Idle': '<S129>:27' */
      if (RobotControl_B.currentRoutine == RobotControl_ENU_ZIGZAG_m) {
        /* Transition: '<S129>:30' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S129>:92' */
        /* Transition: '<S129>:96' */
        RobotControl_DW.is_faceWest_h = RobotControl_IN_Start;

        /* Entry 'Start': '<S129>:104' */
        RobotControl_DW.initHeading = 0.0;
      }
      break;

     case RobotControl_IN_MovingForward:
      /* During 'MovingForward': '<S129>:29' */
      if ((RobotControl_B.currentHeading == *DataTypeConversion1_e) ||
          (RobotControl_B.currentHeading == *DataTypeConversion2_m)) {
        /* Transition: '<S129>:109' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_faceWest;

        /* Entry Internal 'faceWest': '<S129>:92' */
        /* Transition: '<S129>:96' */
        RobotControl_DW.is_faceWest_h = RobotControl_IN_Start;

        /* Entry 'Start': '<S129>:104' */
        RobotControl_DW.initHeading = 0.0;
      } else {
        if (RobotControl_B.hitRoutineRun) {
          /* Transition: '<S129>:120' */
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_Freeze;
        }
      }
      break;

     case RobotControl_IN_SwitchLane:
      /* During 'SwitchLane': '<S129>:31' */
      if (RobotControl_DW.finishCounter > RobotControl_CAL_ZgZgCounterThd) {
        /* Transition: '<S129>:54' */
        /* Exit 'SwitchLane': '<S129>:31' */
        RobotControl_B.switchLaneFlg_BOOL = false;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_finishZigZag;

        /* Entry 'finishZigZag': '<S129>:53' */
        RobotControl_B.zgzgActive = false;

        /* Constant: '<S104>/ENU_STOP' */
        RobotControl_B.moveRequest_i = ((uint8_T)ENU_STOP);
      } else {
        if ((RobotControl_DW.headingRequest == RobotControl_B.currentHeading) &&
            RobotControl_B.OutportBufferFortargetReached) {
          /* Transition: '<S129>:55' */
          /* Exit 'SwitchLane': '<S129>:31' */
          RobotControl_B.switchLaneFlg_BOOL = false;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_MovingForward;

          /* Constant: '<S104>/ENU_FORWARD' */
          /* Entry 'MovingForward': '<S129>:29' */
          RobotControl_B.moveRequest_i = ((uint8_T)ENU_FORWARD);
        }
      }
      break;

     case RobotControl_IN_faceWest:
      /* During 'faceWest': '<S129>:92' */
      if (RobotControl_DW.initHeading != 0.0) {
        /* Transition: '<S129>:108' */
        /* Exit Internal 'faceWest': '<S129>:92' */
        RobotControl_DW.is_faceWest_h = 0U;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_MovingForward;

        /* Constant: '<S104>/ENU_FORWARD' */
        /* Entry 'MovingForward': '<S129>:29' */
        RobotControl_B.moveRequest_i = ((uint8_T)ENU_FORWARD);
      } else {
        switch (RobotControl_DW.is_faceWest_h) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S129>:104' */
          if (RobotControl_B.currentHeading == *DataTypeConversion4_m) {
            /* Transition: '<S129>:94' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_turingRight;

            /* Constant: '<S104>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S129>:103' */
            RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion1_e) {
            /* Transition: '<S129>:97' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_turningLeft;

            /* Entry 'turningLeft': '<S129>:105' */
            RobotControl_B.moveRequest_i = RobotControl_MOVE_TURN_RIGHT;
          } else if (RobotControl_B.currentHeading == *DataTypeConversion2_m) {
            /* Transition: '<S129>:98' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_uturn;

            /* Entry 'uturn': '<S129>:107' */
            RobotControl_B.moveRequest_i = RobotControl_MOVE_TURN_LEFT;
          } else {
            if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
              /* Transition: '<S129>:101' */
              RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S129>:106' */
              RobotControl_DW.initHeading = 1.0;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S129>:106' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S129>:103' */
          /* Transition: '<S129>:95' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S129>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S129>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S129>:105' */
          /* Transition: '<S129>:99' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S129>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S129>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;

         default:
          /* During 'uturn': '<S129>:107' */
          /* Transition: '<S129>:102' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion3_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S129>:100' */
            RobotControl_DW.is_faceWest_h = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S129>:106' */
            RobotControl_DW.initHeading = 1.0;
          }
          break;
        }
      }
      break;

     default:
      /* During 'finishZigZag': '<S129>:53' */
      if (RobotControl_B.currentRoutine == RobotControl_ENU_ZIGZAG_m) {
        /* Transition: '<S129>:61' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S129>:27' */
        RobotControl_B.zgzgActive = true;
        RobotControl_DW.finishCounter = 1U;
      }
      break;
    }

    if (guard4) {
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_EMPTY))
          || (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_EMPTY)))
      {
        /* Transition: '<S129>:44' */
        if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
          /* Constant: '<S104>/ENU_MOVE_U_TURN_RIGHT' */
          /* Transition: '<S129>:45' */
          RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN_RIGHT);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4_m;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S129>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading == *DataTypeConversion4_m) {
          /* Constant: '<S104>/ENU_MOVE_U_TURN' */
          /* Transition: '<S129>:46' */
          RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S129>:31' */
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
        /* Transition: '<S129>:90' */
        guard1 = true;
      } else if ((RobotControl_B.sensorView == ((uint8_T)
                   ENU_LEFT_EMPTY_RIGHT_CLEANED)) || (RobotControl_B.sensorView ==
                  ((uint8_T)ENU_LEFT_EMPTY_RIGHT_BUSY))) {
        /* Transition: '<S129>:47' */
        if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
          /* Constant: '<S104>/ENU_MOVE_U_TURN' */
          /* Transition: '<S129>:48' */
          RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4_m;
          RobotControl_DW.finishCounter++;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S129>:31' */
          RobotControl_B.switchLaneFlg_BOOL = true;
          RobotControl_B.swLaneCnt_uint8++;
        } else if (RobotControl_B.currentHeading == *DataTypeConversion4_m) {
          /* Constant: '<S104>/ENU_MOVE_U_TURN_LEFT' */
          /* Transition: '<S129>:49' */
          RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN_LEFT);
          RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
          RobotControl_DW.finishCounter = 1U;
          RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

          /* Entry 'SwitchLane': '<S129>:31' */
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
        /* Transition: '<S129>:50' */
        guard1 = true;
      }
    }

    if (guard1) {
      if (RobotControl_B.currentHeading == *DataTypeConversion3_g) {
        /* Constant: '<S104>/ENU_MOVE_U_TURN' */
        /* Transition: '<S129>:51' */
        RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN);
        RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion4_m;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S129>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else if (RobotControl_B.currentHeading == *DataTypeConversion4_m) {
        /* Constant: '<S104>/ENU_MOVE_U_TURN' */
        /* Transition: '<S129>:56' */
        RobotControl_B.moveRequest_i = ((uint8_T)ENU_MOVE_U_TURN);
        RobotControl_DW.headingRequest = (uint16_T)*DataTypeConversion3_g;
        RobotControl_DW.finishCounter++;
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S129>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      } else {
        /* Transition: '<S129>:119' */
        RobotControl_DW.is_c25_ROTH = RobotControl_IN_SwitchLane;

        /* Entry 'SwitchLane': '<S129>:31' */
        RobotControl_B.switchLaneFlg_BOOL = true;
        RobotControl_B.swLaneCnt_uint8++;
      }
    }
  }
}

/* Function for Chart: '<S101>/GTSP_Chart' */
static void RobotControl_chartstep_c24_ROTH(const real32_T *forwardDist, const
  real32_T *DataTypeConversion, const real32_T *DataTypeConversion1_g, real32_T *
  DataTypeConversion2, real32_T *DataTypeConversion3_l)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During: Routines/StartPointRoutine/GTSP_Chart */
  /* Go to start point state machine. handles the logic of making the robot move to the most south west point on the map */
  if (RobotControl_DW.is_active_c24_ROTH == 0U) {
    /* Entry: Routines/StartPointRoutine/GTSP_Chart */
    RobotControl_DW.is_active_c24_ROTH = 1U;

    /* Entry Internal: Routines/StartPointRoutine/GTSP_Chart */
    /* Transition: '<S128>:6' */
    RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

    /* Entry 'Idle': '<S128>:5' */
    RobotControl_DW.counter = 0U;

    /* Constant: '<S101>/ENU_STOP' */
    RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
    RobotControl_DW.step1Flag = 0U;
    RobotControl_B.GT_active = true;
  } else {
    guard1 = false;
    guard2 = false;
    switch (RobotControl_DW.is_c24_ROTH) {
     case RobotControl_IN_GTSP_Active:
      /* During 'GTSP_Active': '<S128>:7' */
      if (RobotControl_B.currentRoutine != ((uint8_T)ENU_GTSP)) {
        /* Transition: '<S128>:9' */
        /* Exit Internal 'GTSP_Active': '<S128>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

        /* Entry 'Idle': '<S128>:5' */
        RobotControl_DW.counter = 0U;

        /* Constant: '<S101>/ENU_STOP' */
        RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
        RobotControl_DW.step1Flag = 0U;
        RobotControl_B.GT_active = true;
      } else if (RobotControl_DW.step1Flag == 1) {
        /* Transition: '<S128>:68' */
        /* Exit Internal 'GTSP_Active': '<S128>:7' */
        RobotControl_DW.is_GTSP_Active = 0U;
        RobotControl_DW.activeFlag = true;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_MostSouthLeft;
        RobotControl_DW.is_MostSouthLeft = RobotControl_IN_start_h;
      } else {
        switch (RobotControl_DW.is_GTSP_Active) {
         case RobotControl_IN_Forward:
          /* During 'Forward': '<S128>:10' */
          if (RobotControl_B.hitRoutineRun) {
            /* Transition: '<S128>:13' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Freeze_j;
          }
          break;

         case RobotControl_IN_Freeze_j:
          /* During 'Freeze': '<S128>:193' */
          if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
            /* Transition: '<S128>:194' */
            if ((RobotControl_B.sensorView == ((uint8_T)
                  ENU_LEFT_EMPTY_RIGHT_EMPTY)) || (RobotControl_B.sensorView ==
                 ((uint8_T)ENU_LEFT_EMPTY_RIGHT_CLEANED)) ||
                (RobotControl_B.sensorView == ((uint8_T)
                  ENU_LEFT_EMPTY_RIGHT_BUSY))) {
              /* Transition: '<S128>:15' */
              if (RobotControl_B.currentHeading == *DataTypeConversion) {
                /* Transition: '<S128>:18' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_TurnLeft_e;

                /* Constant: '<S101>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'TurnLeft': '<S128>:12' */
                RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_LEFT);
              } else if (RobotControl_B.currentHeading == *DataTypeConversion2)
              {
                /* Transition: '<S128>:20' */
                RobotControl_DW.is_GTSP_Active = RobotControl_IN_preFinishNormal;

                /* Constant: '<S101>/ENU_MOVE_TURN_LEFT' */
                /* Entry 'preFinishNormal': '<S128>:19' */
                RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_LEFT);
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }
          break;

         case RobotControl_IN_TurnLeft_e:
          /* During 'TurnLeft': '<S128>:12' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion2) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S128>:16' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

            /* Constant: '<S101>/ENU_FORWARD' */
            /* Entry 'Forward': '<S128>:10' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
          }
          break;

         case RobotControl_IN_finishedGTSP:
          /* During 'finishedGTSP': '<S128>:33' */
          break;

         case RobotContr_IN_preFinishBlockedN:
          /* During 'preFinishBlockedN': '<S128>:27' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S128>:36' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S128>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S101>/ENU_STOP' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
          }
          break;

         case RobotContr_IN_preFinishBlockedW:
          /* During 'preFinishBlockedW': '<S128>:28' */
          /* Transition: '<S128>:35' */
          RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

          /* Entry 'finishedGTSP': '<S128>:33' */
          RobotControl_DW.step1Flag = 1U;

          /* Constant: '<S101>/ENU_STOP' */
          RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
          break;

         case RobotC_IN_preFinishLeftBlockedN:
          /* During 'preFinishLeftBlockedN': '<S128>:21' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion1_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S128>:37' */
            /* Transition: '<S128>:157' */
            RobotControl_DW.is_GTSP_Active = 0U;
            RobotControl_DW.is_c24_ROTH = RobotControl_IN_MostSouthLeft;
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

            /* Entry 'finish': '<S128>:102' */
            RobotControl_B.GT_active = false;
          }
          break;

         case RobotC_IN_preFinishLeftBlockedW:
          /* During 'preFinishLeftBlockedW': '<S128>:25' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S128>:38' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S128>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S101>/ENU_STOP' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
          }
          break;

         default:
          /* During 'preFinishNormal': '<S128>:19' */
          if ((RobotControl_B.currentHeading == *DataTypeConversion1_g) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S128>:34' */
            RobotControl_DW.is_GTSP_Active = RobotControl_IN_finishedGTSP;

            /* Entry 'finishedGTSP': '<S128>:33' */
            RobotControl_DW.step1Flag = 1U;

            /* Constant: '<S101>/ENU_STOP' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
          }
          break;
        }
      }
      break;

     case RobotControl_IN_Idle_o:
      /* Constant: '<S101>/ENU_GTSP' */
      /* During 'Idle': '<S128>:5' */
      if ((RobotControl_B.currentRoutine == ((uint8_T)ENU_GTSP)) &&
          (RobotControl_DW.counter > RobotControl_CAL_GTSPdelayStart)) {
        /* Transition: '<S128>:8' */
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_faceWest_c;

        /* Entry Internal 'faceWest': '<S128>:126' */
        /* Transition: '<S128>:128' */
        RobotControl_DW.is_faceWest = RobotControl_IN_Start;

        /* Entry 'Start': '<S128>:127' */
        RobotControl_DW.initHeading_p = false;
      } else {
        RobotControl_DW.counter++;
      }
      break;

     case RobotControl_IN_MostSouthLeft:
      /* During 'MostSouthLeft': '<S128>:67' */
      switch (RobotControl_DW.is_MostSouthLeft) {
       case RobotControl_IN_facingSouth:
        /* During 'facingSouth': '<S128>:72' */
        if (!RobotControl_DW.activeFlag) {
          /* Transition: '<S128>:103' */
          /* Exit Internal 'facingSouth': '<S128>:72' */
          RobotControl_DW.is_facingSouth = 0U;

          /* Exit Internal 'GTSPsearch': '<S128>:94' */
          RobotControl_DW.is_GTSPsearch = 0U;
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

          /* Entry 'finish': '<S128>:102' */
          RobotControl_B.GT_active = false;
        } else {
          switch (RobotControl_DW.is_facingSouth) {
           case RobotControl_IN_End_p:
            /* During 'End': '<S128>:89' */
            break;

           case RobotControl_IN_Freeze_j:
            /* During 'Freeze': '<S128>:197' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S128>:155' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S128>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze1:
            /* During 'Freeze1': '<S128>:199' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S128>:106' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S128>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           case RobotControl_IN_Freeze6:
            /* During 'Freeze6': '<S128>:205' */
            if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
              /* Transition: '<S128>:87' */
              RobotControl_DW.is_facingSouth = RobotControl_IN_End_p;

              /* Entry 'End': '<S128>:89' */
              RobotControl_DW.activeFlag = false;
            }
            break;

           default:
            /* During 'GTSPsearch': '<S128>:94' */
            if ((*DataTypeConversion1_g == RobotControl_B.currentHeading) &&
                RobotControl_B.OutportBufferFortargetReached &&
                (RobotControl_DW.round > 1) && RobotControl_B.hitRoutineRun) {
              /* Transition: '<S128>:95' */
              /* Transition: '<S128>:196' */
              /* Exit Internal 'GTSPsearch': '<S128>:94' */
              RobotControl_DW.is_GTSPsearch = 0U;

              /* Constant: '<S101>/ENU_STOP' */
              RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
              RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze_j;
            } else {
              switch (RobotControl_DW.is_GTSPsearch) {
               case RobotControl_IN_Freeze3:
                /* During 'Freeze3': '<S128>:200' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S128>:201' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S101>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S128>:82' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                }
                break;

               case RobotControl_IN_Freeze4:
                /* During 'Freeze4': '<S128>:203' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S128>:182' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                  /* Constant: '<S101>/ENU_MOVE_TURN_RIGHT' */
                  /* Entry 'emptyOnRight': '<S128>:82' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                }
                break;

               case RobotControl_IN_Freeze5:
                /* During 'Freeze5': '<S128>:207' */
                if (RobotControl_DW.sfEvent == RobotControl_event_stopEvent_n) {
                  /* Transition: '<S128>:208' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_furtherDown;

                  /* Constant: '<S101>/ENU_MOVE_TURN_LEFT' */
                  /* Entry 'furtherDown': '<S128>:91' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_LEFT);
                }
                break;

               case RobotControl_IN_emptyOnRight:
                /* During 'emptyOnRight': '<S128>:82' */
                if ((RobotControl_B.currentHeading == *DataTypeConversion2) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S128>:85' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_facingWest;

                  /* Constant: '<S101>/ENU_FORWARD' */
                  /* Entry 'facingWest': '<S128>:84' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
                }
                break;

               case RobotControl_IN_facingWest:
                /* During 'facingWest': '<S128>:84' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Constant: '<S101>/ENU_LEFT_EMPTY_RIGHT_BUSY' incorporates:
                   *  Constant: '<S101>/ENU_LEFT_BUSY_RIGHT_BUSY'
                   *  Constant: '<S101>/ENU_LEFT_BUSY_RIGHT_EMPTY'
                   *  Constant: '<S101>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                   */
                  /* Transition: '<S128>:204' */
                  if ((RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_BUSY)) ||
                      (RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                    /* Transition: '<S128>:92' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze5;
                  } else {
                    if ((RobotControl_B.sensorView == ((uint8_T)
                          ENU_LEFT_BUSY_RIGHT_BUSY)) ||
                        (RobotControl_B.sensorView == ((uint8_T)
                          ENU_LEFT_BUSY_RIGHT_EMPTY))) {
                      /* Transition: '<S128>:90' */
                      RobotControl_DW.is_GTSPsearch = 0U;
                      RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze6;
                    }
                  }

                  /* End of Constant: '<S101>/ENU_LEFT_EMPTY_RIGHT_BUSY' */
                }
                break;

               case RobotControl_IN_furtherDown:
                /* During 'furtherDown': '<S128>:91' */
                if ((RobotControl_B.currentHeading == *DataTypeConversion1_g) &&
                    RobotControl_B.OutportBufferFortargetReached) {
                  /* Transition: '<S128>:93' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

                  /* Constant: '<S101>/ENU_FORWARD' */
                  /* Entry 'start': '<S128>:77' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
                  RobotControl_DW.round++;
                }
                break;

               case RobotControl_IN_intermediate:
                /* During 'intermediate': '<S128>:173' */
                if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S128>:202' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze4;
                } else if ((RobotControl_B.sensorView != ((uint8_T)
                             ENU_LEFT_BUSY_RIGHT_EMPTY)) &&
                           (RobotControl_B.sensorView != ((uint8_T)
                             ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                  /* Transition: '<S128>:167' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

                  /* Constant: '<S101>/ENU_FORWARD' */
                  /* Entry 'start': '<S128>:77' */
                  RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
                  RobotControl_DW.round++;
                } else {
                  if (*forwardDist - RobotControl_DW.tempDist_f >
                      RobotControl_CAL_ROBO_LENG_mm) {
                    /* Transition: '<S128>:166' */
                    /* * 0.75)] */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_emptyOnRight;

                    /* Constant: '<S101>/ENU_MOVE_TURN_RIGHT' */
                    /* Entry 'emptyOnRight': '<S128>:82' */
                    RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_RIGHT);
                  }
                }
                break;

               default:
                /* Constant: '<S101>/ENU_LEFT_BUSY_RIGHT_EMPTY' incorporates:
                 *  Constant: '<S101>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
                 */
                /* During 'start': '<S128>:77' */
                if (((RobotControl_B.sensorView == ((uint8_T)
                       ENU_LEFT_BUSY_RIGHT_EMPTY)) || (RobotControl_B.sensorView
                      == ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY))) &&
                    RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S128>:164' */
                  /* Transition: '<S128>:163' */
                  RobotControl_DW.is_GTSPsearch = RobotControl_IN_Freeze3;
                } else if (RobotControl_B.hitRoutineRun) {
                  /* Transition: '<S128>:198' */
                  RobotControl_DW.is_GTSPsearch = 0U;
                  RobotControl_DW.is_facingSouth = RobotControl_IN_Freeze1;
                } else {
                  if ((RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_BUSY_RIGHT_EMPTY)) ||
                      (RobotControl_B.sensorView == ((uint8_T)
                        ENU_LEFT_EMPTY_RIGHT_EMPTY))) {
                    /* Transition: '<S128>:81' */
                    RobotControl_DW.is_GTSPsearch = RobotControl_IN_intermediate;

                    /* Entry 'intermediate': '<S128>:173' */
                    RobotControl_DW.tempDist_f = *forwardDist;
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
        /* Constant: '<S101>/ENU_GTSP' */
        /* During 'finish': '<S128>:102' */
        if (RobotControl_B.currentRoutine == ((uint8_T)ENU_GTSP)) {
          /* Transition: '<S128>:101' */
          RobotControl_DW.is_MostSouthLeft = 0U;
          RobotControl_DW.is_c24_ROTH = RobotControl_IN_Idle_o;

          /* Entry 'Idle': '<S128>:5' */
          RobotControl_DW.counter = 0U;

          /* Constant: '<S101>/ENU_STOP' */
          RobotControl_B.moveRequest_p = ((uint8_T)ENU_STOP);
          RobotControl_DW.step1Flag = 0U;
          RobotControl_B.GT_active = true;
        }
        break;

       default:
        /* During 'start': '<S128>:69' */
        if (RobotControl_B.currentHeading == *DataTypeConversion1_g) {
          /* Transition: '<S128>:73' */
          RobotControl_DW.is_MostSouthLeft = RobotControl_IN_facingSouth;

          /* Entry Internal 'facingSouth': '<S128>:72' */
          /* Transition: '<S128>:99' */
          RobotControl_DW.is_facingSouth = RobotControl_IN_GTSPsearch;

          /* Entry 'GTSPsearch': '<S128>:94' */
          RobotControl_DW.round = 0U;

          /* Entry Internal 'GTSPsearch': '<S128>:94' */
          /* Transition: '<S128>:78' */
          RobotControl_DW.is_GTSPsearch = RobotControl_IN_start_hx;

          /* Constant: '<S101>/ENU_FORWARD' */
          /* Entry 'start': '<S128>:77' */
          RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.round++;
        } else {
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S128>:74' */
            RobotControl_DW.is_MostSouthLeft = RobotControl_IN_finish_j;

            /* Entry 'finish': '<S128>:102' */
            RobotControl_B.GT_active = false;
          }
        }
        break;
      }
      break;

     default:
      /* During 'faceWest': '<S128>:126' */
      if (RobotControl_DW.initHeading_p) {
        /* Transition: '<S128>:139' */
        /* Exit Internal 'faceWest': '<S128>:126' */
        RobotControl_DW.is_faceWest = 0U;
        RobotControl_DW.is_c24_ROTH = RobotControl_IN_GTSP_Active;

        /* Entry Internal 'GTSP_Active': '<S128>:7' */
        /* Transition: '<S128>:11' */
        RobotControl_DW.is_GTSP_Active = RobotControl_IN_Forward;

        /* Constant: '<S101>/ENU_FORWARD' */
        /* Entry 'Forward': '<S128>:10' */
        RobotControl_B.moveRequest_p = ((uint8_T)ENU_FORWARD);
      } else {
        switch (RobotControl_DW.is_faceWest) {
         case RobotControl_IN_Start:
          /* During 'Start': '<S128>:127' */
          if (RobotControl_B.currentHeading == *DataTypeConversion1_g) {
            /* Transition: '<S128>:132' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turingRight;

            /* Constant: '<S101>/ENU_MOVE_U_TURN' */
            /* Entry 'turingRight': '<S128>:129' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_U_TURN);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion2) {
            /* Transition: '<S128>:133' */
            RobotControl_DW.is_faceWest = RobotControl_IN_turningLeft;

            /* Constant: '<S101>/ENU_MOVE_TURN_RIGHT' */
            /* Entry 'turningLeft': '<S128>:130' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_RIGHT);
          } else if (RobotControl_B.currentHeading == *DataTypeConversion3_l) {
            /* Transition: '<S128>:134' */
            RobotControl_DW.is_faceWest = RobotControl_IN_uturn;

            /* Constant: '<S101>/ENU_MOVE_TURN_LEFT' */
            /* Entry 'uturn': '<S128>:131' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_LEFT);
          } else {
            if (RobotControl_B.currentHeading == *DataTypeConversion) {
              /* Transition: '<S128>:142' */
              RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

              /* Entry 'finishInit': '<S128>:140' */
              RobotControl_DW.initHeading_p = true;
            }
          }
          break;

         case RobotControl_IN_finishInit:
          /* During 'finishInit': '<S128>:140' */
          break;

         case RobotControl_IN_turingRight:
          /* During 'turingRight': '<S128>:129' */
          /* Transition: '<S128>:136' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S128>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S128>:140' */
            RobotControl_DW.initHeading_p = true;
          }
          break;

         case RobotControl_IN_turningLeft:
          /* During 'turningLeft': '<S128>:130' */
          /* Transition: '<S128>:137' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S128>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S128>:140' */
            RobotControl_DW.initHeading_p = true;
          }
          break;

         default:
          /* During 'uturn': '<S128>:131' */
          /* Transition: '<S128>:138' */
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S128>:141' */
            RobotControl_DW.is_faceWest = RobotControl_IN_finishInit;

            /* Entry 'finishInit': '<S128>:140' */
            RobotControl_DW.initHeading_p = true;
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
        /* Transition: '<S128>:23' */
        if (RobotControl_B.currentHeading == *DataTypeConversion) {
          /* Transition: '<S128>:24' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedN;

          /* Constant: '<S101>/ENU_MOVE_U_TURN' */
          /* Entry 'preFinishLeftBlockedN': '<S128>:21' */
          RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_U_TURN);
        } else if (RobotControl_B.currentHeading == *DataTypeConversion2) {
          /* Transition: '<S128>:26' */
          RobotControl_DW.is_GTSP_Active = RobotC_IN_preFinishLeftBlockedW;

          /* Constant: '<S101>/ENU_MOVE_TURN_RIGHT' */
          /* Entry 'preFinishLeftBlockedW': '<S128>:25' */
          RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_TURN_RIGHT);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      /* Constant: '<S101>/ENU_LEFT_BUSY_RIGHT_BUSY' incorporates:
       *  Constant: '<S101>/ENU_LEFT_BUSY_RIGHT_CLEANED'
       *  Constant: '<S101>/ENU_LEFT_CLEANED_RIGHT_BUSY'
       *  Constant: '<S101>/ENU_LEFT_CLEANED_RIGHT_CLEANED'
       */
      if ((RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_BUSY)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_BUSY_RIGHT_CLEANED)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_BUSY)) ||
          (RobotControl_B.sensorView == ((uint8_T)ENU_LEFT_CLEANED_RIGHT_CLEANED)))
      {
        /* Transition: '<S128>:30' */
        if (RobotControl_B.currentHeading == *DataTypeConversion2) {
          /* Transition: '<S128>:31' */
          RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedW;
        } else {
          if (RobotControl_B.currentHeading == *DataTypeConversion) {
            /* Transition: '<S128>:32' */
            RobotControl_DW.is_GTSP_Active = RobotContr_IN_preFinishBlockedN;

            /* Constant: '<S101>/ENU_MOVE_U_TURN' */
            /* Entry 'preFinishBlockedN': '<S128>:27' */
            RobotControl_B.moveRequest_p = ((uint8_T)ENU_MOVE_U_TURN);
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S114>/CompassSelfDiagTestChart' */
static real_T RobotControl_directionCheck(real_T strtHeading, real_T
  CurrentHeading, real_T N, real_T E, real_T S, real_T W, real_T enTheta, const
  real32_T *DataTypeConversion1, const real32_T *DataTypeConversion3, const
  real32_T *DataTypeConversion4, real32_T *DataTypeConversion5)
{
  real_T outFlg;

  /* Graphical Function 'directionCheck': '<S116>:49' */
  /* Transition: '<S116>:51' */
  if (((strtHeading == *DataTypeConversion3) && (CurrentHeading == N) &&
       ((enTheta >= 265.0) || (enTheta <= 275.0))) || ((strtHeading ==
        *DataTypeConversion5) && (CurrentHeading == W) && (enTheta ==
        RobotControl_CAL_WEST)) || ((strtHeading == *DataTypeConversion4) &&
       (CurrentHeading == S) && (enTheta == RobotControl_CAL_SOUTH)) ||
      ((strtHeading == *DataTypeConversion1) && (CurrentHeading == E) &&
       (enTheta == 0.0))) {
    /* Transition: '<S116>:53' */
    /* Transition: '<S116>:72' */
    /* Transition: '<S116>:56' */
    /* Transition: '<S116>:71' */
    /* Transition: '<S116>:61' */
    /* Transition: '<S116>:73' */
    /* Transition: '<S116>:63' */
    /* Transition: '<S116>:65' */
    outFlg = 1.0;

    /* Transition: '<S116>:67' */
  } else {
    /* Transition: '<S116>:57' */
    /* Transition: '<S116>:70' */
    /* Transition: '<S116>:69' */
    /* Transition: '<S116>:68' */
    outFlg = 0.0;
  }

  return outFlg;
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

  /* SystemInitialize for Chart: '<S100>/MainStateMachine' */
  RobotControl_DW.is_Running = 0U;
  RobotControl_DW.temporalCounter_i1 = 0U;
  RobotControl_DW.is_active_c23_ROTH = 0U;
  RobotControl_DW.is_c23_ROTH = 0U;
  RobotControl_DW.zgzgCounter = 0U;
  RobotControl_B.currentRoutine = 0U;

  /* SystemInitialize for Chart: '<S99>/pumperHitSensorView' */
  RobotControl_B.sensorView = 0U;
  RobotControl_DW.doneDoubleBufferReInit = 0;

  /* SystemInitialize for IfAction SubSystem: '<S27>/zigzagRoutine' */
  /* SystemInitialize for Chart: '<S104>/ZgZgChart' */
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

  /* SystemInitialize for Outport: '<S104>/zgzgActive' */
  RobotControl_B.OutportBufferForzgzgActive = true;

  /* End of SystemInitialize for SubSystem: '<S27>/zigzagRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/StartPointRoutine' */
  /* SystemInitialize for Chart: '<S101>/GTSP_Chart' */
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

  /* End of SystemInitialize for SubSystem: '<S27>/StartPointRoutine' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/DIAG_Routine' */
  /* InitializeConditions for UnitDelay: '<S96>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE = ((uint8_T)ENU_TEST_NOT_CONFIRMED);

  /* InitializeConditions for UnitDelay: '<S96>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_j = ((uint8_T)ENU_TEST_NOT_CONFIRMED);

  /* InitializeConditions for UnitDelay: '<S96>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_h = ((uint8_T)ENU_TEST_NOT_CONFIRMED);

  /* SystemInitialize for Chart: '<S124>/HighLevelDiagTestControl' */
  RobotControl_DW.is_SelfDiag = 0U;
  RobotControl_DW.temporalCounter_i1_c = 0U;
  RobotControl_DW.is_active_c26_ROTH = 0U;
  RobotControl_DW.is_c26_ROTH = 0U;
  RobotControl_B.diagEnableReq = 0U;
  RobotControl_B.enableAngleCalib_BOOL = false;

  /* SystemInitialize for IfAction SubSystem: '<S96>/CompassTest' */
  /* SystemInitialize for Chart: '<S114>/CompassSelfDiagTestChart' */
  RobotControl_DW.is_turnHandler = 0U;
  RobotControl_DW.is_active_c31_ROTH = 0U;
  RobotControl_DW.is_c31_ROTH = 0U;
  RobotControl_DW.startHeading = 0U;
  RobotControl_DW.steps = 0U;
  RobotControl_DW.filterToleranceCnt = 0U;
  RobotControl_B.compFaultFlag = false;
  RobotControl_B.moveReq_p = 0U;
  RobotControl_B.comTstStatus = 3U;

  /* End of SystemInitialize for SubSystem: '<S96>/CompassTest' */

  /* SystemInitialize for IfAction SubSystem: '<S96>/EncoderTest' */

  /* SystemInitialize for Chart: '<S120>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init(&RobotControl_B.sf_DeltaDistCalculator,
    &RobotControl_DW.sf_DeltaDistCalculator);

  /* SystemInitialize for Chart: '<S122>/DeltaDistCalculator' */
  RobotC_DeltaDistCalculator_Init(&RobotControl_B.sf_DeltaDistCalculator_d,
    &RobotControl_DW.sf_DeltaDistCalculator_d);

  /* End of SystemInitialize for SubSystem: '<S96>/EncoderTest' */

  /* SystemInitialize for IfAction SubSystem: '<S96>/Angle_Calibration' */
  /* SystemInitialize for Enabled SubSystem: '<S105>/Angle_CalibrationUponReq' */
  /* SystemInitialize for Chart: '<S112>/CompassSelfDiagTestChart' */
  RobotControl_DW.temporalCounter_i1_k3 = 0U;
  RobotControl_DW.is_active_c27_ROTH = 0U;
  RobotControl_DW.is_c27_ROTH = 0U;
  RobotControl_DW.angleFinishFlg = false;
  RobotControl_B.moveReq = 0U;
  RobotControl_B.NORTH = 0U;
  RobotControl_B.SOUTH = 0U;
  RobotControl_B.EAST = 0U;
  RobotControl_B.WEST = 0U;
  RobotControl_B.angleCalibStatus = 3U;

  /* SystemInitialize for Outport: '<S112>/moveRequest' */
  RobotControl_B.OutportBufferFormoveRequest = ((uint8_T)ENU_STOP);

  /* SystemInitialize for Outport: '<S112>/angleCalibStatus' */
  RobotControl_B.OutportBufferForangleCalibSta_a = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* End of SystemInitialize for SubSystem: '<S105>/Angle_CalibrationUponReq' */

  /* SystemInitialize for Outport: '<S105>/angleCalibStatus' */
  RobotControl_B.OutportBufferForangleCalibStatu = ((uint8_T)
    ENU_TEST_NOT_CONFIRMED);

  /* End of SystemInitialize for SubSystem: '<S96>/Angle_Calibration' */

  /* SystemInitialize for IfAction SubSystem: '<S96>/None' */
  /* SystemInitialize for Outport: '<S110>/None' */
  RobotControl_B.DIAG_StatusFlg = ((uint8_T)CONST_DIAG_UNCONFIRM);

  /* End of SystemInitialize for SubSystem: '<S96>/None' */

  /* SystemInitialize for Outport: '<S96>/DIAG_StatusFlg' */
  RobotControl_B.OutportBufferForDIAG_StatusFlg = ((uint8_T)CONST_DIAG_UNCONFIRM);

  /* End of SystemInitialize for SubSystem: '<S27>/DIAG_Routine' */

  /* SystemInitialize for Merge: '<S27>/Merge' */
  RobotControl_B.Merge = 5U;
}

/* Start for function-call system: '<S22>/HighLevelRoutines' */
void RobotCo_HighLevelRoutines_Start(void)
{
  /* Start for SwitchCase: '<S103>/Switch_Case' */
  RobotControl_DW.Switch_Case_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S27>/DIAG_Routine' */
  /* Start for SwitchCase: '<S109>/Switch_Case' */
  RobotControl_DW.Switch_Case_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S27>/DIAG_Routine' */
}

/* Output and update for function-call system: '<S22>/HighLevelRoutines' */
void RobotControl_HighLevelRoutines(void)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  uint8_T rtb_leftBlocks_uint8;
  uint8_T rtb_rightBlocks_uint8;
  int16_T encodCurrentHeading;
  real32_T forwardDist;
  real32_T DataTypeConversion2_m;
  real32_T DataTypeConversion3_g;
  real32_T DataTypeConversion4_m;
  real32_T DataTypeConversion3_l;
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;

  /* Chart: '<S100>/MainStateMachine' incorporates:
   *  DataTypeConversion: '<S100>/Data Type Conversion3'
   *  UnitDelay: '<S27>/Unit_Delay'
   *  UnitDelay: '<S27>/Unit_Delay1'
   *  UnitDelay: '<S27>/Unit_Delay3'
   *  UnitDelay: '<S27>/Unit_Delay4'
   */
  /* Gateway: Routines/RoutineControl/MainStateMachine */
  if (RobotControl_DW.temporalCounter_i1 < 511U) {
    RobotControl_DW.temporalCounter_i1++;
  }

  /* During: Routines/RoutineControl/MainStateMachine */
  /* robot modes handler */
  if (RobotControl_DW.is_active_c23_ROTH == 0U) {
    /* Entry: Routines/RoutineControl/MainStateMachine */
    RobotControl_DW.is_active_c23_ROTH = 1U;

    /* Entry Internal: Routines/RoutineControl/MainStateMachine */
    /* Transition: '<S127>:31' */
    RobotControl_DW.is_c23_ROTH = RobotControl_IN_Running;

    /* Entry Internal 'Running': '<S127>:30' */
    /* Transition: '<S127>:2' */
    RobotControl_DW.is_Running = RobotControl_IN_DIAG;
    RobotControl_DW.temporalCounter_i1 = 0U;
  } else if (RobotControl_DW.is_c23_ROTH != RobotControl_IN_FaultState) {
    /* During 'Running': '<S127>:30' */
    if (RobotControl_B.failFlag) {
      /* Transition: '<S127>:33' */
      /* Exit Internal 'Running': '<S127>:30' */
      RobotControl_DW.is_Running = 0U;
      RobotControl_DW.is_c23_ROTH = RobotControl_IN_FaultState;

      /* Entry 'FaultState': '<S127>:32' */
      RobotControl_B.currentRoutine = RobotControl_ENU_END;
    } else {
      switch (RobotControl_DW.is_Running) {
       case RobotControl_IN_DIAG:
        /* During 'DIAG': '<S127>:1' */
        if (RobotControl_DW.Unit_Delay4_DSTATE_b ==
            RobotCont_CONST_DIAG_FINISH_FLG) {
          /* Transition: '<S127>:4' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S127>:3' */
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
        /* During 'End': '<S127>:7' */
        break;

       case RobotControl_IN_GTSP:
        /* During 'GTSP': '<S127>:3' */
        if ((!RobotControl_DW.Unit_Delay_DSTATE_h) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S127>:6' */
          RobotControl_DW.is_Running = RobotControl_IN_ZIGZAG;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'ZIGZAG': '<S127>:5' */
          RobotControl_B.currentRoutine = RobotControl_ENU_ZIGZAG;
          RobotControl_DW.zgzgCounter++;
        }
        break;

       case RobotControl_IN_ShiftHeadings:
        /* During 'ShiftHeadings': '<S127>:43' */
        if (RobotControl_DW.temporalCounter_i1 >=
            RobotCont_CONST_MODES_TOLERANCE) {
          /* Transition: '<S127>:44' */
          RobotControl_DW.is_Running = RobotControl_IN_GTSP;
          RobotControl_DW.temporalCounter_i1 = 0U;

          /* Entry 'GTSP': '<S127>:3' */
          RobotControl_B.currentRoutine = RobotControl_ENU_GTSP;
        }
        break;

       default:
        /* During 'ZIGZAG': '<S127>:5' */
        if ((!RobotControl_DW.Unit_Delay1_DSTATE_c) &&
            (RobotControl_DW.zgzgCounter >= RobotContro_CONST_ZGZAG_CNT_THD) &&
            (RobotControl_DW.temporalCounter_i1 >=
             RobotCont_CONST_MODES_TOLERANCE)) {
          /* Transition: '<S127>:18' */
          RobotControl_DW.is_Running = RobotControl_IN_End;

          /* Entry 'End': '<S127>:7' */
          RobotControl_B.currentRoutine = RobotControl_ENU_END;
        } else {
          if ((!RobotControl_DW.Unit_Delay1_DSTATE_c) ||
              (RobotControl_B.OutportBufferForswLaneCnt_uint8 >
               RobotControl_CONST_MAXZIGZAG)) {
            /* Transition: '<S127>:13' */
            RobotControl_DW.is_Running = RobotControl_IN_ShiftHeadings;
            RobotControl_DW.temporalCounter_i1 = 0U;

            /* Entry 'ShiftHeadings': '<S127>:43' */
            RobotControl_B.currentRoutine = RobotControl_ENU_SHIFT_HEADING;
          }
        }
        break;
      }
    }
  } else {
    /* During 'FaultState': '<S127>:32' */
  }

  /* End of Chart: '<S100>/MainStateMachine' */

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/CAL_ULS_UnconnectedBlks'
   *  DataTypeConversion: '<S102>/Data_Type_Conversion1'
   */
  if (RobotControl_B.ULS_NotConnectedFlag_BOOL) {
    rtb_leftBlocks_uint8 = ((uint8_T)CAL_ULS_UnconnectedBlks);
  } else {
    rtb_leftBlocks_uint8 = (uint8_T)RobotControl_B.leftBlocks;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Switch: '<S102>/Switch1' incorporates:
   *  Constant: '<S102>/CAL_ULS_UnconnectedBlks1'
   *  DataTypeConversion: '<S102>/Data_Type_Conversion2'
   */
  if (RobotControl_B.ULS_NotConnectedFlag_BOOL_j) {
    rtb_rightBlocks_uint8 = ((uint8_T)CAL_ULS_UnconnectedBlks);
  } else {
    rtb_rightBlocks_uint8 = (uint8_T)RobotControl_B.rightBlocks;
  }

  /* End of Switch: '<S102>/Switch1' */

  /* Chart: '<S99>/pumperHitSensorView' incorporates:
   *  Constant: '<S99>/ENU_LEFT_BUSY_RIGHT_BUSY'
   *  Constant: '<S99>/ENU_LEFT_BUSY_RIGHT_EMPTY'
   *  Constant: '<S99>/ENU_LEFT_EMPTY_RIGHT_BUSY'
   *  Constant: '<S99>/ENU_LEFT_EMPTY_RIGHT_EMPTY'
   */
  /* Gateway: Routines/HitSensorViewCalculation/pumperHitSensorView */
  RobotControl_DW.encoderStep_prev = RobotControl_DW.encoderStep_start;
  RobotControl_DW.encoderStep_start = RobotControl_B.encoderStep;

  /* During: Routines/HitSensorViewCalculation/pumperHitSensorView */
  /* calculates the ULS sensor view to decide whether we have obstical at left or right */
  if (!RobotControl_DW.doneDoubleBufferReInit) {
    RobotControl_DW.doneDoubleBufferReInit = 1;
    RobotControl_DW.encoderStep_prev = RobotControl_B.encoderStep;
  }

  /* Entry Internal: Routines/HitSensorViewCalculation/pumperHitSensorView */
  /* Transition: '<S126>:67' */
  /* sensorView = 0; */
  if (RobotControl_B.value || (RobotControl_DW.encoderStep_prev !=
       RobotControl_DW.encoderStep_start) ||
      RobotControl_B.OutportBufferFortargetReached) {
    /* Transition: '<S126>:70' */
    /* Transition: '<S126>:72' */
    if ((rtb_leftBlocks_uint8 <= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S126>:74' */
      /* Transition: '<S126>:87' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_BUSY_RIGHT_EMPTY);

      /* Transition: '<S126>:106' */
    } else {
      /* Transition: '<S126>:84' */
    }

    /* Transition: '<S126>:107' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 <= 1)) {
      /* Transition: '<S126>:81' */
      /* Transition: '<S126>:88' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_EMPTY_RIGHT_BUSY);

      /* Transition: '<S126>:108' */
    } else {
      /* Transition: '<S126>:85' */
    }

    /* Transition: '<S126>:109' */
    if ((rtb_leftBlocks_uint8 >= 1) && (rtb_rightBlocks_uint8 >= 1)) {
      /* Transition: '<S126>:82' */
      /* Transition: '<S126>:89' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_EMPTY_RIGHT_EMPTY);

      /* Transition: '<S126>:110' */
    } else {
      /* Transition: '<S126>:86' */
    }

    /* Transition: '<S126>:111' */
    if ((rtb_leftBlocks_uint8 < 1) && (rtb_rightBlocks_uint8 < 1)) {
      /* Transition: '<S126>:83' */
      /* Transition: '<S126>:93' */
      RobotControl_B.sensorView = ((uint8_T)ENU_LEFT_BUSY_RIGHT_BUSY);

      /* Transition: '<S126>:94' */
    } else {
      /* Transition: '<S126>:92' */
    }

    /* Transition: '<S126>:97' */
  } else {
    /* Transition: '<S126>:96' */
  }

  /* End of Chart: '<S99>/pumperHitSensorView' */

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S97>/CONST_TWO_F32'
   *  Constant: '<S97>/CONST_ZERO_F32'
   *  Constant: '<S97>/ENU_FORWARD'
   *  Product: '<S97>/Divide'
   *  RelationalOperator: '<S97>/Relational_Operator'
   *  Sum: '<S97>/Add'
   *  UnitDelay: '<S27>/Unit_Delay2'
   */
  /* Transition: '<S126>:99' */
  if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
    forwardDist = (RobotControl_B.Data_Type_Conversion +
                   RobotControl_B.Data_Type_Conversion_m) / CONST_TWO_F32;
  } else {
    forwardDist = CONST_ZERO_F32;
  }

  /* End of Switch: '<S97>/Switch1' */

  /* SwitchCase: '<S103>/Switch_Case' */
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
    /* Disable for SwitchCase: '<S109>/Switch_Case' */
    switch (RobotControl_DW.Switch_Case_ActiveSubsystem_j) {
     case 0:
     case 1:
     case 2:
      break;

     case 3:
      /* Disable for Enabled SubSystem: '<S105>/Angle_CalibrationUponReq' */
      if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
        RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
      }

      /* End of Disable for SubSystem: '<S105>/Angle_CalibrationUponReq' */
      break;

     case 4:
      /* Disable for Outport: '<S110>/None' */
      RobotControl_B.DIAG_StatusFlg = ((uint8_T)CONST_DIAG_UNCONFIRM);
      break;
    }

    RobotControl_DW.Switch_Case_ActiveSubsystem_j = -1;

    /* End of Disable for SwitchCase: '<S109>/Switch_Case' */
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S27>/zigzagRoutine' incorporates:
       *  SystemReset for ActionPort: '<S104>/ZigZagActive'
       */
      /* SystemReset for SwitchCase: '<S103>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S104>/ZgZgChart'
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

      /* End of SystemReset for SubSystem: '<S27>/zigzagRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S27>/zigzagRoutine' incorporates:
     *  ActionPort: '<S104>/ZigZagActive'
     */
    /* DataTypeConversion: '<S104>/Data Type Conversion1' */
    forwardDist = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S104>/Data Type Conversion2' */
    DataTypeConversion2_m = RobotControl_B.ROB_EAST;

    /* DataTypeConversion: '<S104>/Data Type Conversion3' */
    DataTypeConversion3_g = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S104>/Data Type Conversion4' */
    DataTypeConversion4_m = RobotControl_B.ROB_SOUTH;

    /* Chart: '<S104>/ZgZgChart' incorporates:
     *  TriggerPort: '<S129>/input events'
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
        /* Event: '<S129>:89' */
        RobotControl_DW.sfEvent_j = RobotContr_event_refreshEvent_p;
        RobotControl_chartstep_c25_ROTH(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4_m);
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S129>:88' */
        RobotControl_DW.sfEvent_j = RobotControl_event_stopEvent_n;
        RobotControl_chartstep_c25_ROTH(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4_m);
      }
    }

    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.ZgZgChart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S104>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_i;

    /* SignalConversion: '<S104>/OutportBufferForswLaneCnt_uint8' */
    RobotControl_B.OutportBufferForswLaneCnt_uint8 =
      RobotControl_B.swLaneCnt_uint8;

    /* SignalConversion: '<S104>/OutportBufferForswitchLaneFlg_BOOL' */
    RobotControl_B.OutportBufferForswitchLaneFlg_k =
      RobotControl_B.switchLaneFlg_BOOL;

    /* SignalConversion: '<S104>/OutportBufferForzgzgActive' */
    RobotControl_B.OutportBufferForzgzgActive = RobotControl_B.zgzgActive;

    /* End of Outputs for SubSystem: '<S27>/zigzagRoutine' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S27>/StartPointRoutine' incorporates:
       *  SystemReset for ActionPort: '<S101>/GTSPActive'
       */
      /* SystemReset for SwitchCase: '<S103>/Switch_Case' incorporates:
       *  SystemReset for Chart: '<S101>/GTSP_Chart'
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

      /* End of SystemReset for SubSystem: '<S27>/StartPointRoutine' */
    }

    /* Outputs for IfAction SubSystem: '<S27>/StartPointRoutine' incorporates:
     *  ActionPort: '<S101>/GTSPActive'
     */
    /* DataTypeConversion: '<S101>/Data Type Conversion' */
    DataTypeConversion2_m = RobotControl_B.ROB_NORTH;

    /* DataTypeConversion: '<S101>/Data Type Conversion1' */
    DataTypeConversion3_g = RobotControl_B.ROB_SOUTH;

    /* DataTypeConversion: '<S101>/Data Type Conversion2' */
    DataTypeConversion4_m = RobotControl_B.ROB_WEST;

    /* DataTypeConversion: '<S101>/Data Type Conversion3' */
    DataTypeConversion3_l = RobotControl_B.ROB_EAST;

    /* Chart: '<S101>/GTSP_Chart' incorporates:
     *  TriggerPort: '<S128>/input events'
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
        /* Event: '<S128>:146' */
        RobotControl_DW.sfEvent = RobotContr_event_refreshEvent_p;
        RobotControl_chartstep_c24_ROTH(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4_m, &DataTypeConversion3_l);
      }

      if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        /* Event: '<S128>:145' */
        RobotControl_DW.sfEvent = RobotControl_event_stopEvent_n;
        RobotControl_chartstep_c24_ROTH(&forwardDist, &DataTypeConversion2_m,
          &DataTypeConversion3_g, &DataTypeConversion4_m, &DataTypeConversion3_l);
      }
    }

    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[0] = RobotControl_B.refreshEvent;
    RobotControl_PrevZCX.GTSP_Chart_Trig_ZCE[1] = RobotControl_B.stopEvent;

    /* SignalConversion: '<S101>/OutportBufferForGT_active' */
    RobotControl_B.OutportBufferForGT_active = RobotControl_B.GT_active;

    /* SignalConversion: '<S101>/OutportBufferFormoveRequest' */
    RobotControl_B.Merge = RobotControl_B.moveRequest_p;

    /* End of Outputs for SubSystem: '<S27>/StartPointRoutine' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S27>/DIAG_Routine' incorporates:
     *  ActionPort: '<S96>/DIAG_Active'
     */
    /* Chart: '<S124>/HighLevelDiagTestControl' incorporates:
     *  Constant: '<S96>/ENU_PASSED'
     *  UnitDelay: '<S96>/Unit_Delay'
     *  UnitDelay: '<S96>/Unit_Delay1'
     *  UnitDelay: '<S96>/Unit_Delay2'
     */
    /* Gateway: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
    if (RobotControl_DW.temporalCounter_i1_c < 15U) {
      RobotControl_DW.temporalCounter_i1_c++;
    }

    /* During: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
    /* Highest level of state machine. Decides which state it should operate currently */
    if (RobotControl_DW.is_active_c26_ROTH == 0U) {
      /* Entry: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      RobotControl_DW.is_active_c26_ROTH = 1U;

      /* Entry Internal: Routines/DIAG_Routine/HighLevelTestRoutine/HighLevelDiagTestControl/HighLevelDiagTestControl */
      /* Transition: '<S125>:54' */
      if (!RobotControl_B.NVM_AngleStoreFlg) {
        /* Transition: '<S125>:52' */
        RobotControl_B.enableAngleCalib_BOOL = true;
        RobotControl_DW.is_c26_ROTH = RobotControl_IN_AngleCalib;

        /* Entry 'AngleCalib': '<S125>:50' */
        RobotControl_B.diagEnableReq = RobotContr_ENU_DIAG_ANGLE_CALIB;
      } else {
        /* Transition: '<S125>:53' */
        RobotControl_DW.is_c26_ROTH = RobotControl_IN_SelfDiag;

        /* Entry Internal 'SelfDiag': '<S125>:49' */
        /* Transition: '<S125>:3' */
        RobotControl_DW.is_SelfDiag = RobotControl_IN_CompassRoutine;
        RobotControl_DW.temporalCounter_i1_c = 0U;
      }
    } else if (RobotControl_DW.is_c26_ROTH == RobotControl_IN_AngleCalib) {
      /* During 'AngleCalib': '<S125>:50' */
      if (RobotControl_DW.Unit_Delay2_DSTATE_h == RobotControl_ENU_FINISHED_b) {
        /* Transition: '<S125>:55' */
        RobotControl_B.enableAngleCalib_BOOL = false;
        RobotControl_DW.is_c26_ROTH = RobotControl_IN_SelfDiag;

        /* Entry Internal 'SelfDiag': '<S125>:49' */
        /* Transition: '<S125>:3' */
        RobotControl_DW.is_SelfDiag = RobotControl_IN_CompassRoutine;
        RobotControl_DW.temporalCounter_i1_c = 0U;
      }
    } else {
      /* During 'SelfDiag': '<S125>:49' */
      switch (RobotControl_DW.is_SelfDiag) {
       case RobotControl_IN_BlueTooth:
        /* During 'BlueTooth': '<S125>:8' */
        if (((uint8_T)ENU_PASSED) == RobotControl_ENU_FAILED) {
          /* Transition: '<S125>:19' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S125>:14' */
        } else {
          if (((uint8_T)ENU_PASSED) == RobotControl_ENU_PASSED) {
            /* Transition: '<S125>:43' */
            RobotControl_DW.is_SelfDiag = RobotContro_IN_SelfDiagComplete;

            /* Entry 'SelfDiagComplete': '<S125>:46' */
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_NONE;
          }
        }
        break;

       case RobotControl_IN_CompassRoutine:
        /* During 'CompassRoutine': '<S125>:4' */
        if (RobotControl_DW.Unit_Delay_DSTATE_j == RobotControl_ENU_PASSED) {
          /* Transition: '<S125>:9' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_EncoderRoutine;

          /* Entry 'EncoderRoutine': '<S125>:5' */
          RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_ENCOD;
        } else if (RobotControl_DW.Unit_Delay_DSTATE_j ==
                   RobotControl_ENU_FAILED) {
          /* Transition: '<S125>:15' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S125>:14' */
        } else {
          if (RobotControl_DW.temporalCounter_i1_c >=
              Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_COMP;
          }
        }
        break;

       case RobotControl_IN_EncoderRoutine:
        /* During 'EncoderRoutine': '<S125>:5' */
        if (RobotControl_DW.Unit_Delay1_DSTATE == RobotControl_ENU_FAILED) {
          /* Transition: '<S125>:16' */
          RobotControl_DW.is_SelfDiag = RobotControl_IN_Failed;

          /* Entry 'Failed': '<S125>:14' */
        } else {
          if (RobotControl_DW.Unit_Delay1_DSTATE == RobotControl_ENU_PASSED) {
            /* Transition: '<S125>:10' */
            RobotControl_DW.is_SelfDiag = RobotControl_IN_BlueTooth;

            /* Entry 'BlueTooth': '<S125>:8' */
            RobotControl_B.diagEnableReq = RobotControl_ENU_DIAG_BLTOTH;
          }
        }
        break;

       case RobotControl_IN_Failed:
        /* During 'Failed': '<S125>:14' */
        break;

       default:
        /* During 'SelfDiagComplete': '<S125>:46' */
        break;
      }
    }

    /* End of Chart: '<S124>/HighLevelDiagTestControl' */

    /* Product: '<S111>/Product' incorporates:
     *  Constant: '<S111>/CAL_Wheel2WheelDist_mm'
     *  Constant: '<S111>/CONST_PI_F32'
     *  Constant: '<S111>/CONST_TWO_F32'
     *  Constant: '<S111>/CONST_TWO_F321'
     *  Product: '<S111>/Divide'
     *  Product: '<S111>/Divide1'
     */
    forwardDist = CONST_PI_F32 / CONST_TWO_F32 * ((real32_T)
      CAL_Wheel2WheelDist_mm / CONST_TWO_F32);

    /* SwitchCase: '<S109>/Switch_Case' incorporates:
     *  Logic: '<S105>/Logical_Operator'
     */
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
        /* Disable for Enabled SubSystem: '<S105>/Angle_CalibrationUponReq' */
        if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
        }

        /* End of Disable for SubSystem: '<S105>/Angle_CalibrationUponReq' */
        break;

       case 4:
        /* Disable for Outport: '<S110>/None' */
        RobotControl_B.DIAG_StatusFlg = ((uint8_T)CONST_DIAG_UNCONFIRM);
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S96>/CompassTest' incorporates:
       *  ActionPort: '<S107>/CompassTest'
       */
      /* DataTypeConversion: '<S114>/Data Type Conversion1' */
      forwardDist = RobotControl_B.ROB_EAST;

      /* DataTypeConversion: '<S114>/Data Type Conversion3' */
      DataTypeConversion2_m = RobotControl_B.ROB_NORTH;

      /* DataTypeConversion: '<S114>/Data Type Conversion4' */
      DataTypeConversion3_g = RobotControl_B.ROB_SOUTH;

      /* DataTypeConversion: '<S114>/Data Type Conversion5' */
      DataTypeConversion4_m = RobotControl_B.ROB_WEST;

      /* Chart: '<S115>/EncoderHeadingHandler' incorporates:
       *  UnitDelay: '<S27>/Unit_Delay5'
       */
      /* Gateway: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* During: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* calculates the encoder current heading */
      /* Entry Internal: Routines/DIAG_Routine/CompassTest/encoderHeading/EncoderHeadingHandler */
      /* Transition: '<S117>:55' */
      if ((RobotControl_DW.Unit_Delay5_DSTATE <= 280.0F) &&
          (RobotControl_DW.Unit_Delay5_DSTATE >= 260.0F)) {
        /* Transition: '<S117>:46' */
        /* NORTH */
        /* Transition: '<S117>:50' */
        encodCurrentHeading = (int16_T)270.0F;

        /* Transition: '<S117>:43' */
        /* Transition: '<S117>:41' */
        /* Transition: '<S117>:54' */
        /* Transition: '<S117>:42' */
      } else {
        /* Transition: '<S117>:51' */
        if ((RobotControl_DW.Unit_Delay5_DSTATE <= 100.0F) &&
            (RobotControl_DW.Unit_Delay5_DSTATE >= 80.0F)) {
          /* Transition: '<S117>:62' */
          /* SOUTH */
          /* Transition: '<S117>:53' */
          encodCurrentHeading = (int16_T)90.0F;

          /* Transition: '<S117>:41' */
          /* Transition: '<S117>:54' */
          /* Transition: '<S117>:42' */
        } else {
          /* Transition: '<S117>:52' */
          if ((RobotControl_DW.Unit_Delay5_DSTATE <=
               RobotCont_CAL_ROB_ERRVAL_ENCODE) ||
              (RobotControl_DW.Unit_Delay5_DSTATE >= 350.0F)) {
            /* Transition: '<S117>:59' */
            /* EAST */
            /* Transition: '<S117>:63' */
            encodCurrentHeading = (int16_T)0.0F;

            /* Transition: '<S117>:54' */
            /* Transition: '<S117>:42' */
          } else {
            /* Transition: '<S117>:45' */
            if ((RobotControl_DW.Unit_Delay5_DSTATE <= 190.0F) &&
                (RobotControl_DW.Unit_Delay5_DSTATE >= 170.0F)) {
              /* Transition: '<S117>:60' */
              /* WEST */
              /* Transition: '<S117>:40' */
              encodCurrentHeading = (int16_T)180.0F;

              /* Transition: '<S117>:42' */
            } else {
              /* Transition: '<S117>:39' */
              encodCurrentHeading = (int16_T)400.0F;
            }
          }
        }
      }

      /* End of Chart: '<S115>/EncoderHeadingHandler' */

      /* Chart: '<S114>/CompassSelfDiagTestChart' incorporates:
       *  DataTypeConversion: '<S114>/Data Type Conversion1'
       *  DataTypeConversion: '<S114>/Data Type Conversion3'
       *  DataTypeConversion: '<S114>/Data Type Conversion4'
       *  DataTypeConversion: '<S114>/Data Type Conversion5'
       */
      /* Transition: '<S117>:65' */
      /* Gateway: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
      /* During: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
      /* chart handles the logic to test the compass and how it works before. we proceed with the area coverage */
      if (RobotControl_DW.is_active_c31_ROTH == 0U) {
        /* Entry: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        RobotControl_DW.is_active_c31_ROTH = 1U;

        /* Entry Internal: Routines/DIAG_Routine/CompassTest/CompassSelfDiagTestSubsystem/CompassSelfDiagTestChart */
        /* Transition: '<S116>:2' */
        RobotControl_DW.is_c31_ROTH = RobotControl_IN_init_m;

        /* Entry 'init': '<S116>:1' */
        RobotControl_B.comTstStatus = RobotControl_ENU_TEST_INIT;
        RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
        RobotControl_DW.steps = 0U;
        RobotControl_DW.filterToleranceCnt = 0U;
      } else {
        switch (RobotControl_DW.is_c31_ROTH) {
         case RobotControl_IN_DiagPassed:
          /* During 'DiagPassed': '<S116>:8' */
          break;

         case RobotControl_IN_init_m:
          /* During 'init': '<S116>:1' */
          if ((RobotControl_B.currentHeading != RobotControl_ENU_ROB_NONE) &&
              RobotControl_B.OutportBufferFortargetReached) {
            /* Transition: '<S116>:4' */
            RobotControl_DW.startHeading = RobotControl_B.currentHeading;
            RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnHandler;
            RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

            /* Entry 'Stop': '<S116>:5' */
            RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
            RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
          }
          break;

         case RobotControl_IN_turnHandler:
          /* During 'turnHandler': '<S116>:43' */
          if ((RobotControl_DW.steps > 0) &&
              RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_B.currentHeading != (uint16_T)encodCurrentHeading) &&
              (RobotControl_DW.filterToleranceCnt >
               RobotCont_CONST_ERROR_TOLERANCE)) {
            /* Transition: '<S116>:44' */
            /* Exit Internal 'turnHandler': '<S116>:43' */
            RobotControl_DW.is_turnHandler = 0U;
            RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnRightFault;

            /* Entry 'turnRightFault': '<S116>:7' */
            RobotControl_B.compFaultFlag = true;
            RobotControl_B.comTstStatus = RobotControl_ENU_FAILED;
          } else {
            switch (RobotControl_DW.is_turnHandler) {
             case RobotControl_IN_Stop_o:
              /* During 'Stop': '<S116>:5' */
              if (RobotControl_DW.steps == 0) {
                /* Transition: '<S116>:38' */
                RobotControl_DW.steps++;
                RobotControl_B.moveReq_p = RobotCont_ENU_MOVE_TURN_RIGHT_d;
                RobotControl_DW.is_turnHandler = RobotControl_IN_turnRight_l;
              } else if (RobotControl_directionCheck((real_T)
                          RobotControl_DW.startHeading, (real_T)
                          encodCurrentHeading, (real_T)RobotControl_CAL_NORTH,
                          0.0, (real_T)RobotControl_CAL_SOUTH, (real_T)
                          RobotControl_CAL_WEST, (real_T)encodCurrentHeading,
                          &forwardDist, &DataTypeConversion2_m,
                          &DataTypeConversion3_g, &DataTypeConversion4_m) != 0.0)
              {
                /* Transition: '<S116>:9' */
                RobotControl_DW.is_turnHandler = 0U;
                RobotControl_DW.is_c31_ROTH = RobotControl_IN_DiagPassed;

                /* Entry 'DiagPassed': '<S116>:8' */
                RobotControl_B.compFaultFlag = false;
                RobotControl_B.comTstStatus = RobotControl_ENU_PASSED;
              } else if (RobotControl_DW.steps == 1) {
                /* Transition: '<S116>:39' */
                RobotControl_DW.steps++;
                RobotControl_B.moveReq_p = RobotContr_ENU_MOVE_TURN_LEFT_l;
                RobotControl_DW.is_turnHandler = RobotControl_IN_turnLeft_n;
              } else {
                if ((RobotControl_DW.steps == 2) &&
                    RobotControl_B.OutportBufferFortargetReached && ((uint16_T)
                     encodCurrentHeading != RobotControl_B.currentHeading)) {
                  /* Transition: '<S116>:123' */
                  RobotControl_DW.is_turnHandler = 0U;
                  RobotControl_DW.is_c31_ROTH = RobotControl_IN_turnRightFault;

                  /* Entry 'turnRightFault': '<S116>:7' */
                  RobotControl_B.compFaultFlag = true;
                  RobotControl_B.comTstStatus = RobotControl_ENU_FAILED;
                }
              }
              break;

             case RobotControl_IN_turnLeft_n:
              /* During 'turnLeft': '<S116>:35' */
              if (RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_directionCheck((real_T)
                    RobotControl_DW.startHeading, (real_T)
                    RobotControl_B.currentHeading, (real_T)
                    RobotControl_B.ROB_NORTH, (real_T)RobotControl_B.ROB_EAST,
                    (real_T)RobotControl_B.ROB_SOUTH, (real_T)
                    RobotControl_B.ROB_WEST, (real_T)encodCurrentHeading,
                    &forwardDist, &DataTypeConversion2_m, &DataTypeConversion3_g,
                    &DataTypeConversion4_m) != 0.0)) {
                /* Transition: '<S116>:36' */
                RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

                /* Entry 'Stop': '<S116>:5' */
                RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
                RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
              } else {
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_B.currentHeading != (uint16_T)
                     encodCurrentHeading)) {
                  /* Transition: '<S116>:114' */
                  RobotControl_DW.filterToleranceCnt++;
                  RobotControl_DW.is_turnHandler = RobotControl_IN_turnLeft_n;
                }
              }
              break;

             default:
              /* During 'turnRight': '<S116>:3' */
              if (RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_directionCheck((real_T)
                    RobotControl_DW.startHeading, (real_T)
                    RobotControl_B.currentHeading, (real_T)
                    RobotControl_B.ROB_EAST, (real_T)RobotControl_B.ROB_SOUTH,
                    (real_T)RobotControl_B.ROB_WEST, (real_T)
                    RobotControl_B.ROB_NORTH, (real_T)encodCurrentHeading,
                    &forwardDist, &DataTypeConversion2_m, &DataTypeConversion3_g,
                    &DataTypeConversion4_m) != 0.0)) {
                /* Transition: '<S116>:6' */
                RobotControl_DW.filterToleranceCnt = 0U;
                RobotControl_DW.is_turnHandler = RobotControl_IN_Stop_o;

                /* Entry 'Stop': '<S116>:5' */
                RobotControl_B.comTstStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
                RobotControl_B.moveReq_p = RobotControl_ENU_STOP_o;
              } else {
                if (RobotControl_B.OutportBufferFortargetReached &&
                    (RobotControl_B.currentHeading != (uint16_T)
                     encodCurrentHeading)) {
                  /* Transition: '<S116>:112' */
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
          /* During 'turnRightFault': '<S116>:7' */
          break;
        }
      }

      /* End of Chart: '<S114>/CompassSelfDiagTestChart' */

      /* SignalConversion: '<S107>/OutportBufferFormoveRequest' */
      RobotControl_B.Merge = RobotControl_B.moveReq_p;

      /* End of Outputs for SubSystem: '<S96>/CompassTest' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S96>/EncoderTest' incorporates:
       *  ActionPort: '<S108>/EncoderTest'
       */
      /* SignalConversion: '<S108>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S108>/ENU_MOVE_TURN_LEFT'
       */
      RobotControl_B.Merge = ((uint8_T)ENU_MOVE_TURN_LEFT);

      /* Chart: '<S120>/DeltaDistCalculator' */
      RobotContro_DeltaDistCalculator
        (RobotControl_B.OutportBufferFortargetReached,
         RobotControl_B.Data_Type_Conversion_m,
         &RobotControl_B.sf_DeltaDistCalculator,
         &RobotControl_DW.sf_DeltaDistCalculator);

      /* Logic: '<S118>/Logical_Operator' incorporates:
       *  Abs: '<S118>/Abs'
       *  Constant: '<S118>/CONST_MinDistError_mm'
       *  DataTypeConversion: '<S118>/Data_Type_Conversion'
       *  RelationalOperator: '<S118>/Relational_Operator'
       *  Sum: '<S118>/Subtract'
       */
      RobotControl_B.encoderDistErrorFlg_BOOL =
        (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
          (RobotControl_B.sf_DeltaDistCalculator.deltaDistTrav) - forwardDist >
          CONST_MinDistError_mm));

      /* Chart: '<S122>/DeltaDistCalculator' */
      RobotContro_DeltaDistCalculator
        (RobotControl_B.OutportBufferFortargetReached,
         RobotControl_B.Data_Type_Conversion,
         &RobotControl_B.sf_DeltaDistCalculator_d,
         &RobotControl_DW.sf_DeltaDistCalculator_d);

      /* Logic: '<S119>/Logical_Operator' incorporates:
       *  Abs: '<S119>/Abs'
       *  Constant: '<S119>/CONST_MinDistError_mm'
       *  DataTypeConversion: '<S119>/Data_Type_Conversion'
       *  RelationalOperator: '<S119>/Relational_Operator'
       *  Sum: '<S119>/Subtract'
       */
      RobotControl_B.encoderDistErrorFlg_BOOL_m =
        (RobotControl_B.OutportBufferFortargetReached && ((real32_T)fabs
          (RobotControl_B.sf_DeltaDistCalculator_d.deltaDistTrav) - forwardDist >
          CONST_MinDistError_mm));

      /* Switch: '<S108>/Switch' incorporates:
       *  Constant: '<S108>/ENU_FAILED'
       *  Constant: '<S108>/ENU_TEST_NOT_CONFIRMED'
       *  Logic: '<S108>/Logical_Operator'
       *  Logic: '<S108>/Logical_Operator1'
       *  Switch: '<S108>/Switch1'
       */
      if ((RobotControl_B.encoderDistErrorFlg_BOOL ||
           RobotControl_B.encoderDistErrorFlg_BOOL_m) &&
          RobotControl_B.OutportBufferFortargetReached) {
        RobotControl_B.encoderTstStatus = ((uint8_T)ENU_FAILED);
      } else if (RobotControl_B.OutportBufferFortargetReached) {
        /* Switch: '<S108>/Switch1' incorporates:
         *  Constant: '<S108>/ENU_PASSED'
         */
        RobotControl_B.encoderTstStatus = ((uint8_T)ENU_PASSED);
      } else {
        RobotControl_B.encoderTstStatus = ((uint8_T)ENU_TEST_NOT_CONFIRMED);
      }

      /* End of Switch: '<S108>/Switch' */
      /* End of Outputs for SubSystem: '<S96>/EncoderTest' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S96>/Bluetooth' incorporates:
       *  ActionPort: '<S106>/Bluetooth'
       */
      /* SignalConversion: '<S106>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S106>/ENU_STOP'
       */
      RobotControl_B.Merge = ((uint8_T)ENU_STOP);

      /* End of Outputs for SubSystem: '<S96>/Bluetooth' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S96>/Angle_Calibration' incorporates:
       *  ActionPort: '<S105>/Angle_Calibration'
       */
      /* Outputs for Enabled SubSystem: '<S105>/Angle_CalibrationUponReq' incorporates:
       *  EnablePort: '<S112>/NVM_AngleStoreFlgEnable'
       */
      if (!RobotControl_B.NVM_AngleStoreFlg) {
        if (!RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          /* SystemReset for Chart: '<S112>/CompassSelfDiagTestChart' */
          RobotControl_DW.temporalCounter_i1_k3 = 0U;
          RobotControl_DW.is_active_c27_ROTH = 0U;
          RobotControl_DW.is_c27_ROTH = 0U;
          RobotControl_DW.angleFinishFlg = false;
          RobotControl_B.moveReq = 0U;
          RobotControl_B.NORTH = 0U;
          RobotControl_B.SOUTH = 0U;
          RobotControl_B.EAST = 0U;
          RobotControl_B.WEST = 0U;
          RobotControl_B.angleCalibStatus = 3U;
          RobotControl_DW.Angle_CalibrationUponReq_MODE = true;
        }

        /* Chart: '<S112>/CompassSelfDiagTestChart' */
        /* Gateway: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
        if (RobotControl_DW.temporalCounter_i1_k3 < 15U) {
          RobotControl_DW.temporalCounter_i1_k3++;
        }

        /* During: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
        /* Calibrates 4 direction angles. it stores the specific number coming from compass depending on the encoder calculation of angle */
        if (RobotControl_DW.is_active_c27_ROTH == 0U) {
          /* Entry: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          RobotControl_DW.is_active_c27_ROTH = 1U;

          /* Entry Internal: Routines/DIAG_Routine/Angle_Calibration/Angle_CalibrationUponReq/CompassSelfDiagTestChart */
          /* Transition: '<S113>:2' */
          RobotControl_DW.is_c27_ROTH = RobotControl_IN_initFacingNorth;

          /* Entry 'initFacingNorth': '<S113>:1' */
          RobotControl_B.NORTH = (uint16_T)RobotControl_B.rawCompassValue;
          RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
          RobotControl_B.angleCalibStatus = RobotCon_ENU_TEST_NOT_CONFIRMED;
          RobotControl_DW.angleFinishFlg = false;
        } else {
          switch (RobotControl_DW.is_c27_ROTH) {
           case RobotControl_IN_FacingEAST:
            /* During 'FacingEAST': '<S113>:38' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S113>:40' */
              RobotControl_DW.angleFinishFlg = true;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S113>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_FacingSOUTH:
            /* During 'FacingSOUTH': '<S113>:41' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S113>:43' */
              RobotControl_DW.angleFinishFlg = false;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S113>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_FacingWEST:
            /* During 'FacingWEST': '<S113>:44' */
            if (RobotControl_DW.temporalCounter_i1_k3 >=
                Ro_CONST_COMPASS_DIAG_FIN_TIMER) {
              /* Transition: '<S113>:61' */
              RobotControl_DW.angleFinishFlg = true;
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'Moving': '<S113>:36' */
              RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            }
            break;

           case RobotControl_IN_Moving:
            /* During 'Moving': '<S113>:36' */
            if ((RobotControl_B.currentHeading == RobotControl_CAL_EAST) &&
                (!RobotControl_DW.angleFinishFlg) &&
                RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S113>:39' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingEAST;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingEAST': '<S113>:38' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
              RobotControl_B.EAST = (uint16_T)RobotControl_B.rawCompassValue;
            } else if ((RobotControl_B.currentHeading == RobotControl_CAL_SOUTH)
                       && RobotControl_DW.angleFinishFlg &&
                       RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S113>:42' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingSOUTH;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingSOUTH': '<S113>:41' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
              RobotControl_B.SOUTH = (uint16_T)RobotControl_B.rawCompassValue;
            } else if ((RobotControl_B.currentHeading == RobotControl_CAL_WEST) &&
                       (!RobotControl_DW.angleFinishFlg) &&
                       RobotControl_B.OutportBufferFortargetReached) {
              /* Transition: '<S113>:45' */
              RobotControl_DW.is_c27_ROTH = RobotControl_IN_FacingWEST;
              RobotControl_DW.temporalCounter_i1_k3 = 0U;

              /* Entry 'FacingWEST': '<S113>:44' */
              RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
              RobotControl_B.WEST = (uint16_T)RobotControl_B.rawCompassValue;
            } else {
              if ((RobotControl_B.currentHeading == RobotControl_CAL_NORTH) &&
                  RobotControl_DW.angleFinishFlg &&
                  RobotControl_B.OutportBufferFortargetReached &&
                  (RobotControl_DW.temporalCounter_i1_k3 >=
                   Ro_CONST_COMPASS_DIAG_FIN_TIMER)) {
                /* Transition: '<S113>:59' */
                RobotControl_DW.is_c27_ROTH = RobotContr_IN_finishFacingNorth;

                /* Entry 'finishFacingNorth': '<S113>:60' */
                RobotControl_B.moveReq = RobotControl_ENU_STOP_o;
                RobotControl_B.angleCalibStatus = RobotControl_ENU_FINISHED_b;
              }
            }
            break;

           case RobotContr_IN_finishFacingNorth:
            /* During 'finishFacingNorth': '<S113>:60' */
            break;

           default:
            /* During 'initFacingNorth': '<S113>:1' */
            /* Transition: '<S113>:37' */
            RobotControl_DW.is_c27_ROTH = RobotControl_IN_Moving;
            RobotControl_DW.temporalCounter_i1_k3 = 0U;

            /* Entry 'Moving': '<S113>:36' */
            RobotControl_B.moveReq = RobotCont_ENU_MOVE_TURN_RIGHT_d;
            break;
          }
        }

        /* End of Chart: '<S112>/CompassSelfDiagTestChart' */

        /* SignalConversion: '<S112>/OutportBufferForangleCalibStatus' */
        RobotControl_B.OutportBufferForangleCalibSta_a =
          RobotControl_B.angleCalibStatus;

        /* SignalConversion: '<S112>/OutportBufferForangleCalib_EAST' */
        RobotControl_B.OutportBufferForangleCalib__jq3 = RobotControl_B.EAST;

        /* SignalConversion: '<S112>/OutportBufferForangleCalib_NORTH' */
        RobotControl_B.OutportBufferForangleCalib__fyn = RobotControl_B.NORTH;

        /* SignalConversion: '<S112>/OutportBufferForangleCalib_SOUTH' */
        RobotControl_B.OutportBufferForangleCalib__im4 = RobotControl_B.SOUTH;

        /* SignalConversion: '<S112>/OutportBufferForangleCalib_WEST' */
        RobotControl_B.OutportBufferForangleCalib__nfn = RobotControl_B.WEST;

        /* SignalConversion: '<S112>/OutportBufferFormoveRequest' */
        RobotControl_B.OutportBufferFormoveRequest = RobotControl_B.moveReq;
      } else {
        if (RobotControl_DW.Angle_CalibrationUponReq_MODE) {
          RobotControl_DW.Angle_CalibrationUponReq_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S105>/Angle_CalibrationUponReq' */

      /* SignalConversion: '<S105>/OutportBufferForangleCalibStatus' incorporates:
       *  Logic: '<S105>/Logical_Operator'
       */
      RobotControl_B.OutportBufferForangleCalibStatu =
        RobotControl_B.OutportBufferForangleCalibSta_a;

      /* SignalConversion: '<S105>/OutportBufferForangleCalib_EAST' */
      RobotControl_B.OutportBufferForangleCalib_E_jq =
        RobotControl_B.OutportBufferForangleCalib__jq3;

      /* SignalConversion: '<S105>/OutportBufferForangleCalib_NORTH' */
      RobotControl_B.OutportBufferForangleCalib_N_fy =
        RobotControl_B.OutportBufferForangleCalib__fyn;

      /* SignalConversion: '<S105>/OutportBufferForangleCalib_SOUTH' */
      RobotControl_B.OutportBufferForangleCalib_S_im =
        RobotControl_B.OutportBufferForangleCalib__im4;

      /* SignalConversion: '<S105>/OutportBufferForangleCalib_WEST' */
      RobotControl_B.OutportBufferForangleCalib_W_nf =
        RobotControl_B.OutportBufferForangleCalib__nfn;

      /* SignalConversion: '<S105>/OutportBufferFormoveRequest' */
      RobotControl_B.Merge = RobotControl_B.OutportBufferFormoveRequest;

      /* End of Outputs for SubSystem: '<S96>/Angle_Calibration' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S96>/None' incorporates:
       *  ActionPort: '<S110>/DefaultDiagCase'
       */
      /* SignalConversion: '<S110>/OutportBufferForNone' incorporates:
       *  Constant: '<S110>/CONST_DIAG_FINISH_FLG'
       */
      RobotControl_B.DIAG_StatusFlg = ((uint8_T)CONST_DIAG_FINISH_FLG);

      /* SignalConversion: '<S110>/OutportBufferFormoveRequest' incorporates:
       *  Constant: '<S110>/ENU_STOP'
       */
      RobotControl_B.Merge = ((uint8_T)ENU_STOP);

      /* End of Outputs for SubSystem: '<S96>/None' */
      break;
    }

    /* End of SwitchCase: '<S109>/Switch_Case' */

    /* Logic: '<S96>/Logical_Operator' */
    RobotControl_B.hardwareFaultFlg = (RobotControl_B.compFaultFlag ||
      RobotControl_B.encoderDistErrorFlg_BOOL_m ||
      RobotControl_B.encoderDistErrorFlg_BOOL);

    /* SignalConversion: '<S96>/OutportBufferForDIAG_StatusFlg' */
    RobotControl_B.OutportBufferForDIAG_StatusFlg =
      RobotControl_B.DIAG_StatusFlg;

    /* SignalConversion: '<S96>/OutportBufferForangleCalib_EAST' */
    RobotControl_B.OutportBufferForangleCalib_EA_j =
      RobotControl_B.OutportBufferForangleCalib_E_jq;

    /* SignalConversion: '<S96>/OutportBufferForangleCalib_NORTH' */
    RobotControl_B.OutportBufferForangleCalib_NO_f =
      RobotControl_B.OutportBufferForangleCalib_N_fy;

    /* SignalConversion: '<S96>/OutportBufferForangleCalib_SOUTH' */
    RobotControl_B.OutportBufferForangleCalib_SO_i =
      RobotControl_B.OutportBufferForangleCalib_S_im;

    /* SignalConversion: '<S96>/OutportBufferForangleCalib_WEST' */
    RobotControl_B.OutportBufferForangleCalib_WE_n =
      RobotControl_B.OutportBufferForangleCalib_W_nf;

    /* SignalConversion: '<S96>/OutportBufferForenableAngleCalib_BOOL' */
    RobotControl_B.OutportBufferForenableAngleCali =
      RobotControl_B.enableAngleCalib_BOOL;

    /* End of Outputs for SubSystem: '<S27>/DIAG_Routine' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S27>/End' incorporates:
     *  ActionPort: '<S98>/ENDactive'
     */
    /* DataTypeConversion: '<S98>/Data_Type_Conversion' incorporates:
     *  Constant: '<S98>/ENU_STOP'
     */
    RobotControl_B.Merge = ((uint8_T)ENU_STOP);

    /* End of Outputs for SubSystem: '<S27>/End' */
    break;
  }

  /* End of SwitchCase: '<S103>/Switch_Case' */

  /* DataTypeConversion: '<S27>/Data Type Conversion' */
  RobotControl_B.diagSensorFailure = RobotControl_B.hardwareFaultFlg;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_EAST' */
  RobotControl_B.OutportBufferForangleCalib_EAST =
    RobotControl_B.OutportBufferForangleCalib_EA_j;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_NORTH' */
  RobotControl_B.OutportBufferForangleCalib_NORT =
    RobotControl_B.OutportBufferForangleCalib_NO_f;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_SOUTH' */
  RobotControl_B.OutportBufferForangleCalib_SOUT =
    RobotControl_B.OutportBufferForangleCalib_SO_i;

  /* SignalConversion: '<S27>/OutportBufferForangleCalib_WEST' */
  RobotControl_B.OutportBufferForangleCalib_WEST =
    RobotControl_B.OutportBufferForangleCalib_WE_n;

  /* SignalConversion: '<S27>/OutportBufferForswitchLaneFlg_BOOL' */
  RobotControl_B.OutportBufferForswitchLaneFlg_B =
    RobotControl_B.OutportBufferForswitchLaneFlg_k;

  /* Switch: '<S27>/Switch' */
  if (RobotControl_B.hitRoutineRun) {
    RobotControl_B.moveRequest = RobotControl_B.moveRequest_n;
  } else {
    RobotControl_B.moveRequest = RobotControl_B.Merge;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for UnitDelay: '<S27>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_h = RobotControl_B.OutportBufferForGT_active;

  /* Update for UnitDelay: '<S27>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_c =
    RobotControl_B.OutportBufferForzgzgActive;

  /* Update for UnitDelay: '<S27>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE_b =
    RobotControl_B.OutportBufferForDIAG_StatusFlg;

  /* Update for UnitDelay: '<S27>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE = RobotControl_B.Data_Type_Conversion_a;

  /* Update for SwitchCase: '<S103>/Switch_Case' */
  if (RobotControl_DW.Switch_Case_ActiveSubsystem == 2) {
    /* Update for IfAction SubSystem: '<S27>/DIAG_Routine' incorporates:
     *  Update for ActionPort: '<S96>/DIAG_Active'
     */
    /* Update for UnitDelay: '<S96>/Unit_Delay1' */
    RobotControl_DW.Unit_Delay1_DSTATE = RobotControl_B.encoderTstStatus;

    /* Update for UnitDelay: '<S96>/Unit_Delay' */
    RobotControl_DW.Unit_Delay_DSTATE_j = RobotControl_B.comTstStatus;

    /* Update for UnitDelay: '<S96>/Unit_Delay2' */
    RobotControl_DW.Unit_Delay2_DSTATE_h =
      RobotControl_B.OutportBufferForangleCalibStatu;

    /* End of Update for SubSystem: '<S27>/DIAG_Routine' */
  }

  /* End of Update for SwitchCase: '<S103>/Switch_Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
