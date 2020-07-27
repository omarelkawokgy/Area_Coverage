/*
 * Code generation for system system '<S16>/MovementHandler'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "MovementHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S130>/singleStepCalc' */
#define RobotContr_IN_NO_ACTIVE_CHILD_g ((uint8_T)0U)
#define RobotContr_IN_waitingSwitchLane ((uint8_T)4U)
#define RobotControl_CAL_BLOCK_SIZE_mm (250U)
#define RobotControl_IN_ForwardStep    ((uint8_T)1U)
#define RobotControl_IN_SwitchLaneStep ((uint8_T)2U)
#define RobotControl_IN_initiateDist   ((uint8_T)3U)

/* Named constants for Chart: '<S127>/HighLevelMoves' */
#define RobotCont_CONST_MOVE_STABLE_CNT ((uint8_T)5U)
#define RobotContro_CONST_UTURN_CNT_THD ((uint8_T)2U)
#define RobotControl_CAL_thetaGain     ((uint8_T)100U)
#define RobotControl_ENU_FINISHED      ((uint8_T)4U)
#define RobotControl_IN_Idle           ((uint8_T)1U)
#define RobotControl_IN_Stop           ((uint8_T)1U)
#define RobotControl_IN_TurnLeft       ((uint8_T)2U)
#define RobotControl_IN_TurnLeft_b     ((uint8_T)1U)
#define RobotControl_IN_TurnRight      ((uint8_T)3U)
#define RobotControl_IN_TurnRight_a    ((uint8_T)1U)
#define RobotControl_IN_Uturn          ((uint8_T)4U)
#define RobotControl_IN_UturnLeft      ((uint8_T)5U)
#define RobotControl_IN_UturnRight     ((uint8_T)6U)
#define RobotControl_IN_backward       ((uint8_T)7U)
#define RobotControl_IN_finish         ((uint8_T)1U)
#define RobotControl_IN_finish_f       ((uint8_T)2U)
#define RobotControl_IN_fixingHeading  ((uint8_T)2U)
#define RobotControl_IN_forward        ((uint8_T)8U)
#define RobotControl_IN_forwardStep    ((uint8_T)3U)
#define RobotControl_IN_init           ((uint8_T)9U)
#define RobotControl_IN_start          ((uint8_T)2U)
#define RobotControl_IN_turning        ((uint8_T)3U)
#define RobotControl_event_refreshEvent (0L)
#define RobotControl_event_stopEvent   (1L)

/* Named constants for Chart: '<S128>/TargetReachedConfirmTime' */
#define Robo_CONST_TARGET_REACHED_TIMER (100.0F)
#define RobotCo_CAL_ALLOWED_ERROR_VALUE (0.027778F)

/* Forward declaration for local functions */
static void RobotControl_Stop(void);
static void RobotControl_TurnLeft(void);
static void RobotControl_Uturn(void);
static void RobotControl_UturnLeft(void);
static void RobotControl_UturnRight(void);
static void RobotControl_forward(void);
static void RobotControl_chartstep_c37_MOVH(void);

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_Stop(void)
{
  /* During 'Stop': '<S138>:37' */
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      RobotControl_DW.turnActive) {
    /* Constant: '<S127>/ENU_FORWARD' incorporates:
     *  Constant: '<S127>/ENU_BACKWARD'
     *  Constant: '<S127>/ENU_MOVE_TURN_LEFT'
     *  Constant: '<S127>/ENU_MOVE_TURN_RIGHT'
     *  Constant: '<S127>/ENU_MOVE_U_TURN'
     *  Constant: '<S127>/ENU_MOVE_U_TURN_LEFT'
     *  Constant: '<S127>/ENU_MOVE_U_TURN_RIGHT'
     *  Constant: '<S127>/ENU_STOP'
     */
    /* Transition: '<S138>:38' */
    /* previous turn not completed */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Transition: '<S138>:8' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Constant: '<S127>/ENU_BACKWARD' */
      /* Transition: '<S138>:11' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Constant: '<S127>/ENU_STOP' */
      /* Transition: '<S138>:39' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else {
      if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT) {
        /* Transition: '<S138>:229' */
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

        /* Entry Internal 'TurnLeft': '<S138>:230' */
        /* Transition: '<S138>:231' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

        /* Constant: '<S127>/ENU_CCW' */
        /* Entry 'start': '<S138>:239' */
        RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
        RobotControl_DW.turnActive = true;
      }
    }

    /* End of Constant: '<S127>/ENU_FORWARD' */
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_TurnLeft(void)
{
  boolean_T guard1 = false;

  /* During 'TurnLeft': '<S138>:230' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S138>:240' */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Transition: '<S138>:8' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_FORWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Transition: '<S138>:11' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Transition: '<S138>:39' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_STOP' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT)
    {
      /* Transition: '<S138>:229' */
      /* Exit Internal 'TurnLeft': '<S138>:230' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S138>:230' */
      /* Transition: '<S138>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:239' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    switch (RobotControl_DW.is_TurnLeft) {
     case RobotControl_IN_finish:
      /* During 'finish': '<S138>:237' */
      break;

     case RobotControl_IN_start:
      /* During 'start': '<S138>:239' */
      if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_NORTH) {
        /* Transition: '<S138>:232' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_EAST) {
        /* Transition: '<S138>:236' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_SOUTH) {
        /* Transition: '<S138>:233' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else {
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_WEST)
        {
          /* Transition: '<S138>:235' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
        }
      }
      break;

     default:
      /* During 'turning': '<S138>:238' */
      if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
          RobotControl_B.Unit_Delay1) {
        /* Transition: '<S138>:234' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_finish;

        /* Entry 'finish': '<S138>:237' */
        RobotControl_DW.turnActive = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_Uturn(void)
{
  boolean_T guard1 = false;

  /* During 'Uturn': '<S138>:30' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S138>:34' */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Transition: '<S138>:8' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_FORWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Transition: '<S138>:11' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Transition: '<S138>:39' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_STOP' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT)
    {
      /* Transition: '<S138>:229' */
      /* Exit Internal 'Uturn': '<S138>:30' */
      /* Exit Internal 'TurnRight': '<S138>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S138>:230' */
      /* Transition: '<S138>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:239' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (RobotControl_DW.is_Uturn == RobotControl_IN_TurnRight_a) {
      /* During 'TurnRight': '<S138>:186' */
      if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD) {
        /* Transition: '<S138>:246' */
        /* Exit Internal 'TurnRight': '<S138>:186' */
        RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_Uturn = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S138>:175' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S138>:194' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S138>:195' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S138>:192' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S138>:188' */
            /* headingRequest = ROB_EAST; */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S138>:191' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S138>:189' */
              /* headingRequest = ROB_WEST; */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
              RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S138>:193' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              RobotControl_B.Unit_Delay1) {
            /* Transition: '<S138>:190' */
            RobotControl_DW.is_TurnRight = RobotControl_IN_finish;

            /* Entry 'finish': '<S138>:194' */
            RobotControl_DW.uTurnCounter++;
            RobotControl_DW.turnActive = false;
          }
          break;
        }
      }
    } else {
      /* During 'finish': '<S138>:175' */
    }
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_UturnLeft(void)
{
  boolean_T guard1 = false;

  /* During 'UturnLeft': '<S138>:28' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S138>:36' */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Transition: '<S138>:8' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_FORWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Transition: '<S138>:11' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Transition: '<S138>:39' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_STOP' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT)
    {
      /* Transition: '<S138>:229' */
      /* Exit Internal 'UturnLeft': '<S138>:28' */
      /* Exit Internal 'TurnLeft': '<S138>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S138>:230' */
      /* Transition: '<S138>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:239' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    switch (RobotControl_DW.is_UturnLeft) {
     case RobotControl_IN_TurnLeft_b:
      /* During 'TurnLeft': '<S138>:79' */
      if ((RobotControl_DW.uTurnCounter == 1) &&
          (RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start)) {
        /* Transition: '<S138>:115' */
        /* Exit Internal 'TurnLeft': '<S138>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_forwardStep;

        /* Constant: '<S127>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S138>:113' */
        /* counter = 0; */
        RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S138>:114' */
        /* Exit Internal 'TurnLeft': '<S138>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S138>:112' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnLeft_f) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S138>:89' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S138>:90' */
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_NORTH) {
            /* Transition: '<S138>:82' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_EAST) {
            /* Transition: '<S138>:88' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S138>:84' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_WEST) {
              /* Transition: '<S138>:86' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
              RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S138>:185' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              RobotControl_B.Unit_Delay1) {
            /* Transition: '<S138>:81' */
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_finish;

            /* Entry 'finish': '<S138>:89' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S138>:112' */
      break;

     default:
      /* During 'forwardStep': '<S138>:113' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) &&
          (RobotControl_B.DataTypeConversion1_n == 1.0F)) {
        /* Transition: '<S138>:116' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S138>:79' */
        /* Transition: '<S138>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S127>/ENU_CCW' */
        /* Entry 'start': '<S138>:90' */
        RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S138>:302' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S138>:79' */
        /* Transition: '<S138>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S127>/ENU_CCW' */
        /* Entry 'start': '<S138>:90' */
        RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_UturnRight(void)
{
  boolean_T guard1 = false;

  /* During 'UturnRight': '<S138>:29' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S138>:32' */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Transition: '<S138>:8' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_FORWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Transition: '<S138>:11' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Transition: '<S138>:39' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_STOP' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT)
    {
      /* Transition: '<S138>:229' */
      /* Exit Internal 'UturnRight': '<S138>:29' */
      /* Exit Internal 'TurnRight': '<S138>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S138>:230' */
      /* Transition: '<S138>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:239' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    switch (RobotControl_DW.is_UturnRight) {
     case RobotControl_IN_TurnRight_a:
      /* During 'TurnRight': '<S138>:95' */
      if ((RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start) && (RobotControl_DW.uTurnCounter ==
           1)) {
        /* Transition: '<S138>:124' */
        /* Exit Internal 'TurnRight': '<S138>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_forwardStep;

        /* Constant: '<S127>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S138>:125' */
        /* counter = 0; */
        RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S138>:123' */
        /* Exit Internal 'TurnRight': '<S138>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S138>:120' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight_b) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S138>:242' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S138>:106' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S138>:104' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S138>:98' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S138>:102' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S138>:100' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
              RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S138>:183' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              RobotControl_B.Unit_Delay1) {
            /* Transition: '<S138>:243' */
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_finish;

            /* Entry 'finish': '<S138>:242' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S138>:120' */
      break;

     default:
      /* During 'forwardStep': '<S138>:125' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) &&
          (RobotControl_B.DataTypeConversion1_n == 1.0F)) {
        /* Transition: '<S138>:122' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S138>:95' */
        /* Transition: '<S138>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S127>/ENU_CW' */
        /* Entry 'start': '<S138>:106' */
        RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S138>:303' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S138>:95' */
        /* Transition: '<S138>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S127>/ENU_CW' */
        /* Entry 'start': '<S138>:106' */
        RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_forward(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During 'forward': '<S138>:4' */
  guard1 = false;
  guard2 = false;
  if (RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) {
    /* Transition: '<S138>:10' */
    if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
      /* Constant: '<S127>/ENU_FORWARD' */
      /* Transition: '<S138>:8' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S138>:4' */
      /* Transition: '<S138>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
      /* Transition: '<S138>:11' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest ==
               RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
      /* Transition: '<S138>:31' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S138>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S138>:29' */
      /* Transition: '<S138>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:95' */
      /* Transition: '<S138>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:106' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN) {
      /* Transition: '<S138>:33' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S138>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S138>:30' */
      /* Transition: '<S138>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S138>:186' */
      /* Transition: '<S138>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:195' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN_LEFT)
    {
      /* Transition: '<S138>:35' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S138>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S138>:28' */
      /* Transition: '<S138>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S138>:79' */
      /* Transition: '<S138>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:90' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
      /* Transition: '<S138>:39' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S127>/ENU_STOP' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S127>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S138>:37' */
      /* Transition: '<S138>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           RobotControl_P.ENU_ROB_NONE)) {
        /* Transition: '<S138>:314' */
        /* Transition: '<S138>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S138>:336' */
      } else {
        /* Transition: '<S138>:335' */
      }

      /* End of Constant: '<S127>/ENU_ROB_NONE' */
      /* Transition: '<S138>:333' */
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_RIGHT)
    {
      /* Transition: '<S138>:227' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S138>:217' */
      /* Transition: '<S138>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CW' */
      /* Entry 'start': '<S138>:226' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT)
    {
      /* Transition: '<S138>:229' */
      /* Exit Internal 'forward': '<S138>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S138>:230' */
      /* Transition: '<S138>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S127>/ENU_CCW' */
      /* Entry 'start': '<S138>:239' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
      RobotControl_DW.turnActive = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2) {
    switch (RobotControl_DW.is_forward) {
     case RobotControl_IN_Idle:
      /* During 'Idle': '<S138>:247' */
      /* Transition: '<S138>:271' */
      if (!((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
             RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
            RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)))
      {
        /* Transition: '<S138>:251' */
        if (RobotControl_B.headingRequest == (uint16_T)RobotControl_B.ROB_NORTH)
        {
          /* Transition: '<S138>:256' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S127>/ENU_CCW' */
            /* Transition: '<S138>:261' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S127>/ENU_CW' */
            /* Transition: '<S138>:263' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_SOUTH) {
          /* Transition: '<S138>:257' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S127>/ENU_CW' */
            /* Transition: '<S138>:264' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S127>/ENU_CCW' */
            /* Transition: '<S138>:265' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_EAST) {
          /* Transition: '<S138>:258' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S127>/ENU_CW' */
            /* Transition: '<S138>:266' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S127>/ENU_CCW' */
            /* Transition: '<S138>:267' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S138>:259' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S127>/ENU_CCW' */
            /* Transition: '<S138>:268' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S127>/ENU_CW' */
            /* Transition: '<S138>:269' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      /* During 'fixingHeading': '<S138>:260' */
      /* Transition: '<S138>:273' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
      break;
    }
  }

  if (guard1) {
    if ((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
         RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
         RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)) {
      /* Constant: '<S127>/ENU_FORWARD' */
      /* Transition: '<S138>:272' */
      RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    }
  }
}

/* Function for Chart: '<S127>/HighLevelMoves' */
static void RobotControl_chartstep_c37_MOVH(void)
{
  boolean_T guard1 = false;
  RobotControl_DW.uTurnCounter_prev = RobotControl_DW.uTurnCounter_start;
  RobotControl_DW.uTurnCounter_start = RobotControl_DW.uTurnCounter;
  RobotControl_DW.completeStep_prev = RobotControl_DW.completeStep_start;
  RobotControl_DW.completeStep_start = RobotControl_B.DataTypeConversion1_n;
  RobotControl_DW.moveRequest_prev = RobotControl_DW.moveRequest_start;
  RobotControl_DW.moveRequest_start = RobotControl_B.moveRequest;

  /* During: MovementHandler/MoveMainStatemachine/HighLevelMoves */
  if (RobotControl_DW.is_active_c37_MOVH == 0U) {
    RobotControl_DW.completeStep_prev = RobotControl_B.DataTypeConversion1_n;
    RobotControl_DW.moveRequest_prev = RobotControl_B.moveRequest;

    /* Entry: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    RobotControl_DW.is_active_c37_MOVH = 1U;

    /* Entry Internal: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    /* Transition: '<S138>:3' */
    RobotControl_DW.is_c37_MOVH = RobotControl_IN_init;

    /* Entry 'init': '<S138>:295' */
    RobotControl_DW.stableCounter = 0U;

    /* Constant: '<S127>/ENU_STOP' */
    RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;

    /* Constant: '<S127>/ENU_ROB_NONE' */
    RobotControl_B.headingRequest = RobotControl_P.ENU_ROB_NONE;
  } else {
    guard1 = false;
    switch (RobotControl_DW.is_c37_MOVH) {
     case RobotControl_IN_Stop:
      RobotControl_Stop();
      break;

     case RobotControl_IN_TurnLeft:
      RobotControl_TurnLeft();
      break;

     case RobotControl_IN_TurnRight:
      /* During 'TurnRight': '<S138>:217' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Transition: '<S138>:228' */
        if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
          /* Transition: '<S138>:8' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S127>/ENU_FORWARD' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S138>:4' */
          /* Transition: '<S138>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
          /* Transition: '<S138>:11' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S127>/ENU_BACKWARD' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
          /* Transition: '<S138>:31' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S138>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S138>:29' */
          /* Transition: '<S138>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S138>:95' */
          /* Transition: '<S138>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:106' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN)
        {
          /* Transition: '<S138>:33' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S138>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S138>:30' */
          /* Transition: '<S138>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S138>:186' */
          /* Transition: '<S138>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:195' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_U_TURN_LEFT) {
          /* Transition: '<S138>:35' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S138>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S138>:28' */
          /* Transition: '<S138>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S138>:79' */
          /* Transition: '<S138>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CCW' */
          /* Entry 'start': '<S138>:90' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
          /* Transition: '<S138>:39' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S127>/ENU_STOP' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S127>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S138>:37' */
          /* Transition: '<S138>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               RobotControl_P.ENU_ROB_NONE)) {
            /* Transition: '<S138>:314' */
            /* Transition: '<S138>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S138>:336' */
          } else {
            /* Transition: '<S138>:335' */
          }

          /* Transition: '<S138>:333' */
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_TURN_RIGHT) {
          /* Transition: '<S138>:227' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S138>:217' */
          /* Transition: '<S138>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:226' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_TURN_LEFT) {
          /* Transition: '<S138>:229' */
          /* Exit Internal 'TurnRight': '<S138>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

          /* Entry Internal 'TurnLeft': '<S138>:230' */
          /* Transition: '<S138>:231' */
          RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CCW' */
          /* Entry 'start': '<S138>:239' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
          RobotControl_DW.turnActive = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case RobotControl_IN_Uturn:
      RobotControl_Uturn();
      break;

     case RobotControl_IN_UturnLeft:
      RobotControl_UturnLeft();
      break;

     case RobotControl_IN_UturnRight:
      RobotControl_UturnRight();
      break;

     case RobotControl_IN_backward:
      /* During 'backward': '<S138>:5' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Constant: '<S127>/ENU_FORWARD' incorporates:
         *  Constant: '<S127>/ENU_BACKWARD'
         *  Constant: '<S127>/ENU_MOVE_TURN_LEFT'
         *  Constant: '<S127>/ENU_MOVE_TURN_RIGHT'
         *  Constant: '<S127>/ENU_MOVE_U_TURN'
         *  Constant: '<S127>/ENU_MOVE_U_TURN_LEFT'
         *  Constant: '<S127>/ENU_MOVE_U_TURN_RIGHT'
         *  Constant: '<S127>/ENU_STOP'
         */
        /* Transition: '<S138>:12' */
        if (RobotControl_B.moveRequest == RobotControl_P.ENU_FORWARD) {
          /* Transition: '<S138>:8' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_FORWARD;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S138>:4' */
          /* Transition: '<S138>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_BACKWARD) {
          /* Constant: '<S127>/ENU_BACKWARD' */
          /* Transition: '<S138>:11' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_BACKWARD;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_U_TURN_RIGHT) {
          /* Transition: '<S138>:31' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S138>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S138>:29' */
          /* Transition: '<S138>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S138>:95' */
          /* Transition: '<S138>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:106' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_U_TURN)
        {
          /* Transition: '<S138>:33' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S138>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S138>:30' */
          /* Transition: '<S138>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S138>:186' */
          /* Transition: '<S138>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:195' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_U_TURN_LEFT) {
          /* Transition: '<S138>:35' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S138>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S138>:28' */
          /* Transition: '<S138>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S138>:79' */
          /* Transition: '<S138>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CCW' */
          /* Entry 'start': '<S138>:90' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == RobotControl_P.ENU_STOP) {
          /* Constant: '<S127>/ENU_STOP' */
          /* Transition: '<S138>:39' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_STOP;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S127>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S138>:37' */
          /* Transition: '<S138>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               RobotControl_P.ENU_ROB_NONE)) {
            /* Transition: '<S138>:314' */
            /* Transition: '<S138>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S138>:336' */
          } else {
            /* Transition: '<S138>:335' */
          }

          /* Transition: '<S138>:333' */
        } else if (RobotControl_B.moveRequest ==
                   RobotControl_P.ENU_MOVE_TURN_RIGHT) {
          /* Transition: '<S138>:227' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S138>:217' */
          /* Transition: '<S138>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S127>/ENU_CW' */
          /* Entry 'start': '<S138>:226' */
          RobotControl_B.turnRequest = RobotControl_P.ENU_CW;
          RobotControl_DW.turnActive = true;
        } else {
          if (RobotControl_B.moveRequest == RobotControl_P.ENU_MOVE_TURN_LEFT) {
            /* Transition: '<S138>:229' */
            RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

            /* Entry Internal 'TurnLeft': '<S138>:230' */
            /* Transition: '<S138>:231' */
            RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

            /* Constant: '<S127>/ENU_CCW' */
            /* Entry 'start': '<S138>:239' */
            RobotControl_B.turnRequest = RobotControl_P.ENU_CCW;
            RobotControl_DW.turnActive = true;
          }
        }
      }
      break;

     case RobotControl_IN_forward:
      RobotControl_forward();
      break;

     default:
      /* During 'init': '<S138>:295' */
      if (RobotControl_DW.stableCounter >= RobotCont_CONST_MOVE_STABLE_CNT) {
        /* Transition: '<S138>:297' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

        /* Constant: '<S127>/ENU_ROB_NONE' */
        /* Entry Internal 'Stop': '<S138>:37' */
        /* Transition: '<S138>:309' */
        if ((RobotControl_B.OutportBufferForangleCalibStatu ==
             RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
             RobotControl_P.ENU_ROB_NONE)) {
          /* Transition: '<S138>:314' */
          /* Transition: '<S138>:316' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

          /* Transition: '<S138>:336' */
        } else {
          /* Transition: '<S138>:335' */
        }

        /* Transition: '<S138>:333' */
      } else {
        RobotControl_DW.stableCounter++;
      }
      break;
    }

    if (guard1) {
      switch (RobotControl_DW.is_TurnRight_c) {
       case RobotControl_IN_finish:
        /* During 'finish': '<S138>:225' */
        break;

       case RobotControl_IN_start:
        /* During 'start': '<S138>:226' */
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
        {
          /* Transition: '<S138>:223' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_NORTH) {
          /* Transition: '<S138>:219' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S138>:222' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else {
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S138>:220' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
          }
        }
        break;

       default:
        /* During 'turning': '<S138>:224' */
        if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
            RobotControl_B.Unit_Delay1) {
          /* Transition: '<S138>:221' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_finish;

          /* Entry 'finish': '<S138>:225' */
          RobotControl_DW.turnActive = false;
        }
        break;
      }
    }
  }
}

/* System initialize for function-call system: '<S16>/MovementHandler' */
void RobotContr_MovementHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S22>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_n = 0U;

  /* InitializeConditions for UnitDelay: '<S22>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_p = false;

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_o = false;

  /* InitializeConditions for UnitDelay: '<S136>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S136>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S137>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jh = 1U;

  /* InitializeConditions for UnitDelay: '<S137>/FixPt Unit Delay1' */
  RobotControl_DW.FixPtUnitDelay1_DSTATE_l = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_c = false;

  /* InitializeConditions for UnitDelay: '<S22>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = RobotControl_P.CAL_NO_ERROR;

  /* SystemInitialize for Chart: '<S130>/singleStepCalc' */
  RobotControl_DW.is_active_c36_MOVH = 0U;
  RobotControl_DW.is_c36_MOVH = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.tempDistance_mm = 0.0F;
  RobotControl_B.switchLaneStep = false;
  RobotControl_B.encoderStep = 0U;

  /* SystemInitialize for Chart: '<S127>/HighLevelMoves' */
  RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.is_active_c37_MOVH = 0U;
  RobotControl_DW.is_c37_MOVH = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.turnActive = false;
  RobotControl_DW.uTurnCounter = 0U;
  RobotControl_DW.stableCounter = 0U;
  RobotControl_B.turnRequest = 0U;
  RobotControl_B.headingRequest = 0U;
  RobotControl_DW.uTurnCounter_prev = RobotControl_DW.uTurnCounter;
  RobotControl_DW.uTurnCounter_start = RobotControl_DW.uTurnCounter;

  /* SystemInitialize for Chart: '<S128>/TargetReachedConfirmTime' */
  RobotControl_DW.counter_j = 0U;
  RobotControl_B.targetReached = false;

  /* SystemInitialize for Outport: '<S22>/rightMotorRequest' */
  RobotControl_B.rightMotorRequest = 0U;

  /* SystemInitialize for Outport: '<S22>/leftMotorRequest' */
  RobotControl_B.leftMotorRequest = 0U;

  /* SystemInitialize for Outport: '<S22>/thetaError' */
  RobotControl_B.thetaError = 0.0F;

  /* SystemInitialize for Outport: '<S22>/targetReached' */
  RobotControl_B.OutportBufferFortargetReached = false;

  /* SystemInitialize for Outport: '<S22>/turnRequest1' */
  RobotControl_B.turnRequestFiltered = 0U;
}

/* Output and update for function-call system: '<S16>/MovementHandler' */
void RobotControl_MovementHandler(void)
{
  /* local block i/o variables */
  real32_T rtb_errorLmited;
  real32_T rtb_errorPID_Input;
  real32_T rtb_Error;
  real32_T rtb_DataTypeConversion_b;
  real32_T rtb_error_DEG;
  uint16_T rtb_Gain4;
  boolean_T rtb_Relational_Operator3;
  boolean_T rtb_Relational_Operator2;
  boolean_T rtb_Relational_Operator2_m;
  boolean_T rtb_Relational_Operator4;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Relational_Operator1_hl;
  boolean_T rtb_Relational_Operator;
  real32_T rtb_Divide_e;
  int32_T rtb_headingRequest;
  real32_T rtb_CCW;
  real32_T rtb_Init_g;
  real32_T rtb_Add_d3;
  real32_T rtb_Add_c;
  boolean_T zcEvent_idx_1;
  uint16_T tmp;

  /* RelationalOperator: '<S124>/Relational_Operator' incorporates:
   *  Constant: '<S124>/ENU_FORWARD'
   *  UnitDelay: '<S22>/Unit_Delay5'
   */
  rtb_Relational_Operator = (RobotControl_DW.Unit_Delay5_DSTATE_n ==
    RobotControl_P.ENU_FORWARD);

  /* Product: '<S124>/Divide' incorporates:
   *  Constant: '<S124>/CONST_TWO_F32'
   *  Sum: '<S124>/Add'
   */
  rtb_Divide_e = (RobotControl_B.Data_Type_Conversion_m +
                  RobotControl_B.Data_Type_Conversion) /
    RobotControl_P.CONST_TWO_F32;

  /* Chart: '<S130>/singleStepCalc' */
  /* Gateway: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* During: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  if (RobotControl_DW.is_active_c36_MOVH == 0U) {
    /* Entry: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    RobotControl_DW.is_active_c36_MOVH = 1U;

    /* Entry Internal: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    /* Transition: '<S131>:39' */
    RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
  } else {
    switch (RobotControl_DW.is_c36_MOVH) {
     case RobotControl_IN_ForwardStep:
      /* During 'ForwardStep': '<S131>:57' */
      /* Transition: '<S131>:59' */
      RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      break;

     case RobotControl_IN_SwitchLaneStep:
      /* During 'SwitchLaneStep': '<S131>:42' */
      if (!RobotControl_B.OutportBufferForswitchLaneFlg_B) {
        /* Transition: '<S131>:44' */
        RobotControl_B.switchLaneStep = false;
        RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      }
      break;

     case RobotControl_IN_initiateDist:
      /* During 'initiateDist': '<S131>:40' */
      if (RobotControl_B.OutportBufferForswitchLaneFlg_B && (rtb_Divide_e -
           RobotControl_DW.tempDistance_mm >= RobotControl_CAL_BLOCK_SIZE_mm)) {
        /* Transition: '<S131>:43' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_SwitchLaneStep;

        /* Entry 'SwitchLaneStep': '<S131>:42' */
        RobotControl_B.switchLaneStep = true;
      } else if ((!RobotControl_B.OutportBufferForswitchLaneFlg_B) &&
                 (rtb_Divide_e - RobotControl_DW.tempDistance_mm >= 50.0F)) {
        /* Transition: '<S131>:58' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_ForwardStep;

        /* Entry 'ForwardStep': '<S131>:57' */
        RobotControl_B.encoderStep = 1U;
      } else {
        if (!rtb_Relational_Operator) {
          /* Transition: '<S131>:61' */
          RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
        }
      }
      break;

     default:
      /* During 'waitingSwitchLane': '<S131>:38' */
      if (rtb_Relational_Operator) {
        /* Transition: '<S131>:41' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_initiateDist;

        /* Entry 'initiateDist': '<S131>:40' */
        RobotControl_DW.tempDistance_mm = rtb_Divide_e;
        RobotControl_B.encoderStep = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S130>/singleStepCalc' */

  /* DataTypeConversion: '<S127>/Data Type Conversion1' */
  RobotControl_B.DataTypeConversion1_n = RobotControl_B.switchLaneStep;

  /* UnitDelay: '<S22>/Unit_Delay1' */
  RobotControl_B.Unit_Delay1 = RobotControl_DW.Unit_Delay1_DSTATE_p;

  /* Chart: '<S127>/HighLevelMoves' incorporates:
   *  TriggerPort: '<S138>/input events'
   */
  rtb_Relational_Operator = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] ==
    POS_ZCSIG) != (int16_T)RobotControl_B.refreshEvent) &&
    (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] ==
                     POS_ZCSIG) != (int16_T)RobotControl_B.stopEvent) &&
                   (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] !=
                    UNINITIALIZED_ZCSIG));
  if (rtb_Relational_Operator || zcEvent_idx_1) {
    /* Gateway: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    if ((int8_T)(rtb_Relational_Operator ? RobotControl_B.refreshEvent ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S138>:300' */
      RobotControl_DW.sfEvent_p = RobotControl_event_refreshEvent;
      RobotControl_chartstep_c37_MOVH();
    }

    if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S138>:301' */
      RobotControl_DW.sfEvent_p = RobotControl_event_stopEvent;
      RobotControl_chartstep_c37_MOVH();
    }
  }

  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] = RobotControl_B.refreshEvent;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] = RobotControl_B.stopEvent;

  /* RelationalOperator: '<S22>/Relational_Operator2' incorporates:
   *  Constant: '<S22>/ENU_STOP'
   */
  rtb_Relational_Operator2_m = (RobotControl_B.turnRequest ==
    RobotControl_P.ENU_STOP);

  /* RelationalOperator: '<S22>/Relational_Operator4' incorporates:
   *  Constant: '<S22>/ENU_TEST_INIT'
   */
  rtb_Relational_Operator4 = (RobotControl_B.comTstStatus !=
    RobotControl_P.ENU_TEST_INIT);

  /* Logic: '<S22>/Logical Operator1' incorporates:
   *  Constant: '<S22>/ENU_SHIFT_HEADING'
   *  Logic: '<S22>/Logical Operator'
   *  RelationalOperator: '<S22>/Relational_Operator6'
   */
  rtb_LogicalOperator1 = (rtb_Relational_Operator2_m && rtb_Relational_Operator4
    && (RobotControl_B.currentRoutine != RobotControl_P.ENU_SHIFT_HEADING));

  /* Gain: '<S125>/Gain5' */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  rtb_headingRequest = (int32_T)((uint32_T)tmp * RobotControl_B.headingRequest >>
    9);

  /* End of Gain: '<S125>/Gain5' */

  /* Sum: '<S125>/Subtract' */
  rtb_Divide_e = RobotControl_B.theta_mDeg - (real32_T)rtb_headingRequest;

  /* Gain: '<S125>/Gain' */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  /* Sum: '<S125>/Subtract2' incorporates:
   *  Constant: '<S125>/CAL_fullCircle_DEG'
   *  Gain: '<S125>/Gain'
   *  Sum: '<S125>/Subtract1'
   */
  rtb_CCW = ((real32_T)((uint32_T)tmp * RobotControl_P.CAL_fullCircle_DEG >> 9)
             + RobotControl_B.theta_mDeg) - (real32_T)rtb_headingRequest;

  /* Gain: '<S125>/Gain1' */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  /* DataTypeConversion: '<S125>/Data_Type_Conversion1' incorporates:
   *  Constant: '<S125>/CAL_halfCircle_DEG1'
   *  Gain: '<S125>/Gain1'
   */
  rtb_error_DEG = (int16_T)((uint32_T)tmp * RobotControl_P.CAL_halfCircle_DEG >>
    9);

  /* RelationalOperator: '<S125>/Relational_Operator3' */
  rtb_Relational_Operator3 = (rtb_CCW > rtb_error_DEG);

  /* RelationalOperator: '<S125>/Relational_Operator1' incorporates:
   *  Constant: '<S125>/CONST_ZERO_F32'
   */
  rtb_Relational_Operator1_hl = (rtb_Divide_e < RobotControl_P.CONST_ZERO_F32);

  /* Gain: '<S125>/Gain3' incorporates:
   *  Constant: '<S125>/CAL_halfCircle_DEG'
   */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  rtb_Gain4 = (uint16_T)((uint32_T)tmp * RobotControl_P.CAL_halfCircle_DEG >> 9);

  /* End of Gain: '<S125>/Gain3' */

  /* DataTypeConversion: '<S125>/Data_Type_Conversion' */
  rtb_error_DEG = rtb_Gain4;

  /* RelationalOperator: '<S125>/Relational_Operator2' */
  rtb_Relational_Operator2 = (rtb_Divide_e > rtb_error_DEG);

  /* Switch: '<S125>/Switch' incorporates:
   *  Switch: '<S125>/Switch1'
   */
  if (rtb_Relational_Operator1_hl) {
    /* Switch: '<S125>/Switch2' incorporates:
     *  Abs: '<S125>/Abs'
     *  Gain: '<S125>/Gain8'
     */
    if (rtb_Relational_Operator3) {
      rtb_error_DEG = (real32_T)fabs(rtb_Divide_e);
    } else {
      rtb_error_DEG = (real32_T)RobotControl_P.CONST_NegOne * rtb_CCW;
    }

    /* End of Switch: '<S125>/Switch2' */
  } else if (rtb_Relational_Operator2) {
    /* Gain: '<S125>/Gain2' incorporates:
     *  Switch: '<S125>/Switch1'
     */
    if (RobotControl_P.CAL_thetaGain > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
    }

    /* Switch: '<S125>/Switch1' incorporates:
     *  Abs: '<S125>/Abs1'
     *  Constant: '<S125>/CAL_fullCircle_DEG1'
     *  Gain: '<S125>/Gain2'
     *  Sum: '<S125>/Subtract3'
     *  Sum: '<S125>/Subtract4'
     */
    rtb_error_DEG = (real32_T)fabs(RobotControl_B.theta_mDeg - (real32_T)
      ((int32_T)((uint32_T)tmp * RobotControl_P.CAL_fullCircle_DEG >> 9) +
       rtb_headingRequest));
  } else {
    /* Switch: '<S125>/Switch1' incorporates:
     *  Gain: '<S125>/Gain7'
     */
    rtb_error_DEG = (real32_T)RobotControl_P.CONST_NegOne * rtb_Divide_e;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Gain: '<S125>/Gain4' */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  /* Product: '<S125>/Divide' incorporates:
   *  Constant: '<S125>/CAL_halfCircle_DEG2'
   *  Gain: '<S125>/Gain4'
   */
  rtb_errorPID_Input = rtb_error_DEG / (real32_T)(int16_T)((uint32_T)tmp *
    RobotControl_P.CAL_halfCircle_DEG >> 9);

  /* Switch: '<S136>/Init' incorporates:
   *  Constant: '<S136>/Initial Condition'
   *  Logic: '<S136>/FixPt Logical Operator'
   *  UnitDelay: '<S136>/FixPt Unit Delay1'
   *  UnitDelay: '<S136>/FixPt Unit Delay2'
   *  UnitDelay: '<S22>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_j != 0)) {
    rtb_Divide_e = 0.0F;
  } else {
    rtb_Divide_e = RobotControl_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S136>/Init' */

  /* Sum: '<S132>/Add2' */
  rtb_CCW = rtb_errorPID_Input - rtb_Divide_e;

  /* Switch: '<S137>/Init' incorporates:
   *  Constant: '<S137>/Initial Condition'
   *  Logic: '<S137>/FixPt Logical Operator'
   *  UnitDelay: '<S137>/FixPt Unit Delay1'
   *  UnitDelay: '<S137>/FixPt Unit Delay2'
   *  UnitDelay: '<S22>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_jh != 0)) {
    rtb_Init_g = 0.0F;
  } else {
    rtb_Init_g = RobotControl_DW.FixPtUnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S137>/Init' */

  /* Sum: '<S132>/Add' */
  rtb_Add_d3 = rtb_errorPID_Input + rtb_Init_g;

  /* Sum: '<S132>/Add1' incorporates:
   *  Gain: '<S132>/Kd'
   *  Gain: '<S132>/Ki'
   *  Gain: '<S132>/Kp'
   */
  rtb_Error = (RobotControl_P.CAL_Kd * rtb_CCW + RobotControl_P.CAL_Kp *
               rtb_errorPID_Input) + RobotControl_P.CAL_Ki * rtb_Add_d3;

  /* Sum: '<S133>/Add' incorporates:
   *  UnitDelay: '<S125>/Unit Delay'
   */
  rtb_Add_c = rtb_Error - RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S133>/Switch' incorporates:
   *  Constant: '<S133>/Constant'
   *  MinMax: '<S133>/MinMax1'
   *  RelationalOperator: '<S133>/Relational Operator'
   */
  if (rtb_Add_c > 0.0F) {
    /* MinMax: '<S133>/MinMax' */
    if (2.5F <= rtb_Add_c) {
      rtb_DataTypeConversion_b = 2.5F;
    } else {
      rtb_DataTypeConversion_b = rtb_Add_c;
    }

    /* End of MinMax: '<S133>/MinMax' */
  } else if ((rtb_Add_c >= RobotControl_ConstB.Gain) || rtIsNaNF
             (RobotControl_ConstB.Gain)) {
    /* MinMax: '<S133>/MinMax1' */
    rtb_DataTypeConversion_b = rtb_Add_c;
  } else {
    /* MinMax: '<S133>/MinMax1' */
    rtb_DataTypeConversion_b = RobotControl_ConstB.Gain;
  }

  /* End of Switch: '<S133>/Switch' */

  /* Sum: '<S133>/Add2' incorporates:
   *  UnitDelay: '<S125>/Unit Delay'
   */
  rtb_errorLmited = RobotControl_DW.UnitDelay_DSTATE + rtb_DataTypeConversion_b;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/CAL_NO_ERROR'
   *  Constant: '<S22>/ENU_BACKWARD'
   *  Constant: '<S22>/ENU_FORWARD'
   *  Logic: '<S22>/Logical_Operator'
   *  RelationalOperator: '<S22>/Relational_Operator1'
   *  RelationalOperator: '<S22>/Relational_Operator3'
   *  Switch: '<S22>/Switch1'
   */
  if (rtb_LogicalOperator1) {
    RobotControl_B.thetaError = RobotControl_P.CAL_NO_ERROR;
  } else if ((RobotControl_B.turnRequest == RobotControl_P.ENU_FORWARD) ||
             (RobotControl_B.turnRequest == RobotControl_P.ENU_BACKWARD)) {
    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/CAL_NO_ERROR1'
     */
    RobotControl_B.thetaError = RobotControl_P.CAL_NO_ERROR;
  } else {
    RobotControl_B.thetaError = rtb_errorLmited;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Chart: '<S128>/TargetReachedConfirmTime' incorporates:
   *  Abs: '<S22>/Abs'
   */
  /* Gateway: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* During: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* Entry Internal: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* Transition: '<S139>:2' */
  if ((real32_T)fabs(rtb_errorPID_Input) <= RobotCo_CAL_ALLOWED_ERROR_VALUE) {
    /* Transition: '<S139>:4' */
    /* Transition: '<S139>:6' */
    RobotControl_DW.counter_j++;
    if (RobotControl_DW.counter_j > (int16_T)Robo_CONST_TARGET_REACHED_TIMER) {
      /* Transition: '<S139>:15' */
      /* Transition: '<S139>:16' */
      RobotControl_DW.counter_j = 0U;
      RobotControl_B.targetReached = true;

      /* Transition: '<S139>:21' */
    } else {
      /* Transition: '<S139>:8' */
    }

    /* Transition: '<S139>:14' */
  } else {
    /* Transition: '<S139>:9' */
    RobotControl_DW.counter_j = 0U;
    RobotControl_B.targetReached = false;
  }

  /* End of Chart: '<S128>/TargetReachedConfirmTime' */

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/CONST_ZERO_F32'
   *  Constant: '<S129>/ENU_CCW'
   *  RelationalOperator: '<S129>/Relational_Operator'
   *  Switch: '<S129>/Switch1'
   *  UnitDelay: '<S22>/Unit_Delay3'
   *  UnitDelay: '<S22>/Unit_Delay4'
   */
  if (RobotControl_DW.Unit_Delay3_DSTATE_c) {
    RobotControl_B.turnRequestFiltered = RobotControl_B.turnRequest;
  } else if (RobotControl_DW.Unit_Delay4_DSTATE > RobotControl_P.CONST_ZERO_F32)
  {
    /* Switch: '<S129>/Switch1' incorporates:
     *  Constant: '<S129>/ENU_CW'
     */
    RobotControl_B.turnRequestFiltered = RobotControl_P.ENU_CW;
  } else {
    RobotControl_B.turnRequestFiltered = RobotControl_P.ENU_CCW;
  }

  /* End of Switch: '<S129>/Switch' */

  /* Gain: '<S22>/Gain4' */
  if (RobotControl_P.CAL_thetaGain > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)RobotControl_P.CAL_thetaGain << 9;
  }

  rtb_Gain4 = (uint16_T)((uint32_T)tmp * RobotControl_B.headingRequest >> 9);

  /* End of Gain: '<S22>/Gain4' */

  /* DataTypeConversion: '<S125>/Data Type Conversion' */
  rtb_DataTypeConversion_b = (real32_T)rtb_headingRequest;

  /* Switch: '<S136>/Reset' incorporates:
   *  Constant: '<S132>/CONST_EnableDelay1'
   *  Switch: '<S134>/Enable'
   *  Switch: '<S135>/Enable'
   *  Switch: '<S137>/Reset'
   *  UnitDelay: '<S22>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o) {
    /* Update for UnitDelay: '<S136>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S136>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = 0.0F;

    /* Update for UnitDelay: '<S137>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S137>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = 0.0F;
  } else if (RobotControl_P.CONST_EnableDelay) {
    /* Switch: '<S134>/Enable' incorporates:
     *  Update for UnitDelay: '<S136>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_CCW;

    /* Switch: '<S135>/Enable' incorporates:
     *  Update for UnitDelay: '<S137>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Add_d3;
  } else {
    /* Update for UnitDelay: '<S136>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S134>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Divide_e;

    /* Update for UnitDelay: '<S137>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S135>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Init_g;
  }

  /* End of Switch: '<S136>/Reset' */

  /* RelationalOperator: '<S126>/Relational_Operator2' incorporates:
   *  Constant: '<S126>/ENU_FORWARD4'
   */
  rtb_Relational_Operator = (RobotControl_B.turnRequestFiltered ==
    RobotControl_P.ENU_FORWARD);

  /* RelationalOperator: '<S126>/Relational_Operator3' incorporates:
   *  Constant: '<S126>/ENU_BACKWARD3'
   */
  zcEvent_idx_1 = (RobotControl_B.turnRequestFiltered ==
                   RobotControl_P.ENU_BACKWARD);

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/ENU_BACKWARD'
   *  Constant: '<S126>/ENU_CCW'
   *  Constant: '<S126>/ENU_CW'
   *  Constant: '<S126>/ENU_FORWARD'
   *  Constant: '<S126>/ENU_STOP'
   *  RelationalOperator: '<S126>/Relational_Operator'
   *  RelationalOperator: '<S126>/Relational_Operator1'
   *  Switch: '<S126>/Switch'
   *  Switch: '<S126>/Switch1'
   *  Switch: '<S126>/Switch2'
   *  Switch: '<S126>/Switch3'
   */
  if (RobotControl_B.turnRequestFiltered == RobotControl_P.ENU_CCW) {
    RobotControl_B.rightMotorRequest = RobotControl_P.ENU_FORWARD;
    RobotControl_B.leftMotorRequest = RobotControl_P.ENU_BACKWARD;
  } else if (RobotControl_B.turnRequestFiltered == RobotControl_P.ENU_CW) {
    /* Switch: '<S126>/Switch1' incorporates:
     *  Constant: '<S126>/ENU_BACKWARD1'
     */
    RobotControl_B.rightMotorRequest = RobotControl_P.ENU_BACKWARD;

    /* Switch: '<S126>/Switch1' incorporates:
     *  Constant: '<S126>/ENU_FORWARD1'
     */
    RobotControl_B.leftMotorRequest = RobotControl_P.ENU_FORWARD;
  } else if (rtb_Relational_Operator) {
    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S126>/ENU_FORWARD3'
     *  Switch: '<S126>/Switch1'
     */
    RobotControl_B.rightMotorRequest = RobotControl_P.ENU_FORWARD;

    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S126>/ENU_FORWARD2'
     *  Switch: '<S126>/Switch1'
     */
    RobotControl_B.leftMotorRequest = RobotControl_P.ENU_FORWARD;
  } else {
    if (zcEvent_idx_1) {
      /* Switch: '<S126>/Switch3' incorporates:
       *  Constant: '<S126>/ENU_BACKWARD4'
       *  Switch: '<S126>/Switch1'
       *  Switch: '<S126>/Switch2'
       */
      RobotControl_B.rightMotorRequest = RobotControl_P.ENU_BACKWARD;
    } else {
      RobotControl_B.rightMotorRequest = RobotControl_P.ENU_STOP;
    }

    /* Switch: '<S126>/Switch3' incorporates:
     *  Constant: '<S126>/ENU_BACKWARD2'
     *  Constant: '<S126>/ENU_STOP'
     *  Constant: '<S126>/ENU_STOP1'
     *  Switch: '<S126>/Switch1'
     *  Switch: '<S126>/Switch2'
     *  Switch: '<S126>/Switch3'
     */
    if (zcEvent_idx_1) {
      RobotControl_B.leftMotorRequest = RobotControl_P.ENU_BACKWARD;
    } else {
      RobotControl_B.leftMotorRequest = RobotControl_P.ENU_STOP;
    }

    /* End of Switch: '<S126>/Switch3' */
  }

  /* End of Switch: '<S126>/Switch' */

  /* SignalConversion: '<S22>/OutportBufferFortargetReached' */
  RobotControl_B.OutportBufferFortargetReached = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S22>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_n = RobotControl_B.turnRequest;

  /* Update for UnitDelay: '<S22>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_p = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S125>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE = rtb_errorLmited;

  /* Update for UnitDelay: '<S22>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_o = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S136>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S136>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S137>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S137>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jh = 0U;

  /* Update for UnitDelay: '<S22>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_c = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S22>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = RobotControl_B.thetaError;
}
