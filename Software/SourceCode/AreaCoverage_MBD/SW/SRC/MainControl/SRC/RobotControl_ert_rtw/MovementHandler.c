/*
 * File: MovementHandler.c
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

#include "MovementHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S136>/singleStepCalc' */
#define RobotContr_IN_NO_ACTIVE_CHILD_g ((uint8_T)0U)
#define RobotContr_IN_waitingSwitchLane ((uint8_T)4U)
#define RobotControl_CAL_BLOCK_SIZE_mm (250U)
#define RobotControl_IN_ForwardStep    ((uint8_T)1U)
#define RobotControl_IN_SwitchLaneStep ((uint8_T)2U)
#define RobotControl_IN_initiateDist   ((uint8_T)3U)

/* Named constants for Chart: '<S133>/HighLevelMoves' */
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

/* Named constants for Chart: '<S134>/TargetReachedConfirmTime' */
#define Robo_CONST_TARGET_REACHED_TIMER (100.0F)
#define RobotCo_CAL_ALLOWED_ERROR_VALUE (0.027778F)

/* Forward declaration for local functions */
static void RobotControl_Stop(void);
static void RobotControl_TurnLeft(const boolean_T *Unit_Delay1);
static void RobotControl_Uturn(const boolean_T *Unit_Delay1);
static void RobotControl_UturnLeft(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1);
static void RobotControl_UturnRight(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1);
static void RobotControl_forward(void);
static void RobotControl_chartstep_c37_MOVH(const real32_T
  *DataTypeConversion1_n, const boolean_T *Unit_Delay1);

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_Stop(void)
{
  /* During 'Stop': '<S144>:37' */
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      RobotControl_DW.turnActive) {
    /* Constant: '<S133>/ENU_FORWARD' incorporates:
     *  Constant: '<S133>/ENU_BACKWARD'
     *  Constant: '<S133>/ENU_MOVE_TURN_LEFT'
     *  Constant: '<S133>/ENU_MOVE_TURN_RIGHT'
     *  Constant: '<S133>/ENU_MOVE_U_TURN'
     *  Constant: '<S133>/ENU_MOVE_U_TURN_LEFT'
     *  Constant: '<S133>/ENU_MOVE_U_TURN_RIGHT'
     *  Constant: '<S133>/ENU_STOP'
     */
    /* Transition: '<S144>:38' */
    /* previous turn not completed */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S144>:8' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Constant: '<S133>/ENU_BACKWARD' */
      /* Transition: '<S144>:11' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Constant: '<S133>/ENU_STOP' */
      /* Transition: '<S144>:39' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else {
      if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
        /* Transition: '<S144>:229' */
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

        /* Entry Internal 'TurnLeft': '<S144>:230' */
        /* Transition: '<S144>:231' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

        /* Constant: '<S133>/ENU_CCW' */
        /* Entry 'start': '<S144>:239' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      }
    }

    /* End of Constant: '<S133>/ENU_FORWARD' */
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_TurnLeft(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'TurnLeft': '<S144>:230' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S144>:240' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S144>:8' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S144>:11' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S144>:39' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S144>:229' */
      /* Exit Internal 'TurnLeft': '<S144>:230' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S144>:230' */
      /* Transition: '<S144>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
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
      /* During 'finish': '<S144>:237' */
      break;

     case RobotControl_IN_start:
      /* During 'start': '<S144>:239' */
      if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_NORTH) {
        /* Transition: '<S144>:232' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_EAST) {
        /* Transition: '<S144>:236' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_SOUTH) {
        /* Transition: '<S144>:233' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else {
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_WEST)
        {
          /* Transition: '<S144>:235' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
        }
      }
      break;

     default:
      /* During 'turning': '<S144>:238' */
      if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
          (*Unit_Delay1)) {
        /* Transition: '<S144>:234' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_finish;

        /* Entry 'finish': '<S144>:237' */
        RobotControl_DW.turnActive = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_Uturn(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'Uturn': '<S144>:30' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S144>:34' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S144>:8' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S144>:11' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S144>:39' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S144>:229' */
      /* Exit Internal 'Uturn': '<S144>:30' */
      /* Exit Internal 'TurnRight': '<S144>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S144>:230' */
      /* Transition: '<S144>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (RobotControl_DW.is_Uturn == RobotControl_IN_TurnRight_a) {
      /* During 'TurnRight': '<S144>:186' */
      if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD) {
        /* Transition: '<S144>:246' */
        /* Exit Internal 'TurnRight': '<S144>:186' */
        RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_Uturn = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S144>:175' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S144>:194' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S144>:195' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S144>:192' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S144>:188' */
            /* headingRequest = ROB_EAST; */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S144>:191' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S144>:189' */
              /* headingRequest = ROB_WEST; */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
              RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S144>:193' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S144>:190' */
            RobotControl_DW.is_TurnRight = RobotControl_IN_finish;

            /* Entry 'finish': '<S144>:194' */
            RobotControl_DW.uTurnCounter++;
            RobotControl_DW.turnActive = false;
          }
          break;
        }
      }
    } else {
      /* During 'finish': '<S144>:175' */
    }
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_UturnLeft(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnLeft': '<S144>:28' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S144>:36' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S144>:8' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S144>:11' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S144>:39' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S144>:229' */
      /* Exit Internal 'UturnLeft': '<S144>:28' */
      /* Exit Internal 'TurnLeft': '<S144>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S144>:230' */
      /* Transition: '<S144>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
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
      /* During 'TurnLeft': '<S144>:79' */
      if ((RobotControl_DW.uTurnCounter == 1) &&
          (RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start)) {
        /* Transition: '<S144>:115' */
        /* Exit Internal 'TurnLeft': '<S144>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_forwardStep;

        /* Constant: '<S133>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S144>:113' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S144>:114' */
        /* Exit Internal 'TurnLeft': '<S144>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S144>:112' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnLeft_f) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S144>:89' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S144>:90' */
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_NORTH) {
            /* Transition: '<S144>:82' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_EAST) {
            /* Transition: '<S144>:88' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S144>:84' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_WEST) {
              /* Transition: '<S144>:86' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
              RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S144>:185' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S144>:81' */
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_finish;

            /* Entry 'finish': '<S144>:89' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S144>:112' */
      break;

     default:
      /* During 'forwardStep': '<S144>:113' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S144>:116' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S144>:79' */
        /* Transition: '<S144>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S133>/ENU_CCW' */
        /* Entry 'start': '<S144>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S144>:302' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S144>:79' */
        /* Transition: '<S144>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S133>/ENU_CCW' */
        /* Entry 'start': '<S144>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_UturnRight(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnRight': '<S144>:29' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S144>:32' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S144>:8' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S144>:11' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S144>:39' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S144>:229' */
      /* Exit Internal 'UturnRight': '<S144>:29' */
      /* Exit Internal 'TurnRight': '<S144>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S144>:230' */
      /* Transition: '<S144>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
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
      /* During 'TurnRight': '<S144>:95' */
      if ((RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start) && (RobotControl_DW.uTurnCounter ==
           1)) {
        /* Transition: '<S144>:124' */
        /* Exit Internal 'TurnRight': '<S144>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_forwardStep;

        /* Constant: '<S133>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S144>:125' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S144>:123' */
        /* Exit Internal 'TurnRight': '<S144>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S144>:120' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight_b) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S144>:242' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S144>:106' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S144>:104' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S144>:98' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S144>:102' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S144>:100' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
              RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S144>:183' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S144>:243' */
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_finish;

            /* Entry 'finish': '<S144>:242' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S144>:120' */
      break;

     default:
      /* During 'forwardStep': '<S144>:125' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S144>:122' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S144>:95' */
        /* Transition: '<S144>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S133>/ENU_CW' */
        /* Entry 'start': '<S144>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S144>:303' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S144>:95' */
        /* Transition: '<S144>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S133>/ENU_CW' */
        /* Entry 'start': '<S144>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_forward(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During 'forward': '<S144>:4' */
  guard1 = false;
  guard2 = false;
  if (RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) {
    /* Transition: '<S144>:10' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Constant: '<S133>/ENU_FORWARD' */
      /* Transition: '<S144>:8' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S144>:4' */
      /* Transition: '<S144>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S144>:11' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S144>:31' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S144>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S144>:29' */
      /* Transition: '<S144>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:95' */
      /* Transition: '<S144>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S144>:33' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S144>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S144>:30' */
      /* Transition: '<S144>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S144>:186' */
      /* Transition: '<S144>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S144>:35' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S144>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S144>:28' */
      /* Transition: '<S144>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S144>:79' */
      /* Transition: '<S144>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S144>:39' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S133>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S133>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S144>:37' */
      /* Transition: '<S144>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S144>:314' */
        /* Transition: '<S144>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S144>:336' */
      } else {
        /* Transition: '<S144>:335' */
      }

      /* End of Constant: '<S133>/ENU_ROB_NONE' */
      /* Transition: '<S144>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S144>:227' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S144>:217' */
      /* Transition: '<S144>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CW' */
      /* Entry 'start': '<S144>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S144>:229' */
      /* Exit Internal 'forward': '<S144>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S144>:230' */
      /* Transition: '<S144>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S133>/ENU_CCW' */
      /* Entry 'start': '<S144>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
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
      /* During 'Idle': '<S144>:247' */
      /* Transition: '<S144>:271' */
      if (!((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
             RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
            RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)))
      {
        /* Transition: '<S144>:251' */
        if (RobotControl_B.headingRequest == (uint16_T)RobotControl_B.ROB_NORTH)
        {
          /* Transition: '<S144>:256' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S133>/ENU_CCW' */
            /* Transition: '<S144>:261' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S133>/ENU_CW' */
            /* Transition: '<S144>:263' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_SOUTH) {
          /* Transition: '<S144>:257' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S133>/ENU_CW' */
            /* Transition: '<S144>:264' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S133>/ENU_CCW' */
            /* Transition: '<S144>:265' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_EAST) {
          /* Transition: '<S144>:258' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S133>/ENU_CW' */
            /* Transition: '<S144>:266' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S133>/ENU_CCW' */
            /* Transition: '<S144>:267' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S144>:259' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S133>/ENU_CCW' */
            /* Transition: '<S144>:268' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S133>/ENU_CW' */
            /* Transition: '<S144>:269' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
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
      /* During 'fixingHeading': '<S144>:260' */
      /* Transition: '<S144>:273' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
      break;
    }
  }

  if (guard1) {
    if ((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
         RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
         RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)) {
      /* Constant: '<S133>/ENU_FORWARD' */
      /* Transition: '<S144>:272' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    }
  }
}

/* Function for Chart: '<S133>/HighLevelMoves' */
static void RobotControl_chartstep_c37_MOVH(const real32_T
  *DataTypeConversion1_n, const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;
  RobotControl_DW.uTurnCounter_prev = RobotControl_DW.uTurnCounter_start;
  RobotControl_DW.uTurnCounter_start = RobotControl_DW.uTurnCounter;
  RobotControl_DW.completeStep_prev = RobotControl_DW.completeStep_start;
  RobotControl_DW.completeStep_start = *DataTypeConversion1_n;
  RobotControl_DW.moveRequest_prev = RobotControl_DW.moveRequest_start;
  RobotControl_DW.moveRequest_start = RobotControl_B.moveRequest;

  /* During: MovementHandler/MoveMainStatemachine/HighLevelMoves */
  /* movement state machine handles all the movement in slightly higher level. turn left , right, stop, forward, backward and also combinations like u-turn left u-turn right */
  if (RobotControl_DW.is_active_c37_MOVH == 0U) {
    RobotControl_DW.completeStep_prev = *DataTypeConversion1_n;
    RobotControl_DW.moveRequest_prev = RobotControl_B.moveRequest;

    /* Entry: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    RobotControl_DW.is_active_c37_MOVH = 1U;

    /* Entry Internal: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    /* Transition: '<S144>:3' */
    RobotControl_DW.is_c37_MOVH = RobotControl_IN_init;

    /* Entry 'init': '<S144>:295' */
    RobotControl_DW.stableCounter = 0U;

    /* Constant: '<S133>/ENU_STOP' */
    RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);

    /* Constant: '<S133>/ENU_ROB_NONE' */
    RobotControl_B.headingRequest = ENU_ROB_NONE;
  } else {
    guard1 = false;
    switch (RobotControl_DW.is_c37_MOVH) {
     case RobotControl_IN_Stop:
      RobotControl_Stop();
      break;

     case RobotControl_IN_TurnLeft:
      RobotControl_TurnLeft(Unit_Delay1);
      break;

     case RobotControl_IN_TurnRight:
      /* During 'TurnRight': '<S144>:217' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Transition: '<S144>:228' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S144>:8' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S133>/ENU_FORWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S144>:4' */
          /* Transition: '<S144>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Transition: '<S144>:11' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S133>/ENU_BACKWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S144>:31' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S144>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S144>:29' */
          /* Transition: '<S144>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S144>:95' */
          /* Transition: '<S144>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S144>:33' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S144>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S144>:30' */
          /* Transition: '<S144>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S144>:186' */
          /* Transition: '<S144>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S144>:35' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S144>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S144>:28' */
          /* Transition: '<S144>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S144>:79' */
          /* Transition: '<S144>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CCW' */
          /* Entry 'start': '<S144>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Transition: '<S144>:39' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S133>/ENU_STOP' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S133>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S144>:37' */
          /* Transition: '<S144>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S144>:314' */
            /* Transition: '<S144>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S144>:336' */
          } else {
            /* Transition: '<S144>:335' */
          }

          /* Transition: '<S144>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S144>:227' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S144>:217' */
          /* Transition: '<S144>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT))
        {
          /* Transition: '<S144>:229' */
          /* Exit Internal 'TurnRight': '<S144>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

          /* Entry Internal 'TurnLeft': '<S144>:230' */
          /* Transition: '<S144>:231' */
          RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CCW' */
          /* Entry 'start': '<S144>:239' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case RobotControl_IN_Uturn:
      RobotControl_Uturn(Unit_Delay1);
      break;

     case RobotControl_IN_UturnLeft:
      RobotControl_UturnLeft(DataTypeConversion1_n, Unit_Delay1);
      break;

     case RobotControl_IN_UturnRight:
      RobotControl_UturnRight(DataTypeConversion1_n, Unit_Delay1);
      break;

     case RobotControl_IN_backward:
      /* During 'backward': '<S144>:5' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Constant: '<S133>/ENU_FORWARD' incorporates:
         *  Constant: '<S133>/ENU_BACKWARD'
         *  Constant: '<S133>/ENU_MOVE_TURN_LEFT'
         *  Constant: '<S133>/ENU_MOVE_TURN_RIGHT'
         *  Constant: '<S133>/ENU_MOVE_U_TURN'
         *  Constant: '<S133>/ENU_MOVE_U_TURN_LEFT'
         *  Constant: '<S133>/ENU_MOVE_U_TURN_RIGHT'
         *  Constant: '<S133>/ENU_STOP'
         */
        /* Transition: '<S144>:12' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S144>:8' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S144>:4' */
          /* Transition: '<S144>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Constant: '<S133>/ENU_BACKWARD' */
          /* Transition: '<S144>:11' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S144>:31' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S144>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S144>:29' */
          /* Transition: '<S144>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S144>:95' */
          /* Transition: '<S144>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S144>:33' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S144>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S144>:30' */
          /* Transition: '<S144>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S144>:186' */
          /* Transition: '<S144>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S144>:35' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S144>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S144>:28' */
          /* Transition: '<S144>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S144>:79' */
          /* Transition: '<S144>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CCW' */
          /* Entry 'start': '<S144>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Constant: '<S133>/ENU_STOP' */
          /* Transition: '<S144>:39' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S133>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S144>:37' */
          /* Transition: '<S144>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S144>:314' */
            /* Transition: '<S144>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S144>:336' */
          } else {
            /* Transition: '<S144>:335' */
          }

          /* Transition: '<S144>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S144>:227' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S144>:217' */
          /* Transition: '<S144>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S133>/ENU_CW' */
          /* Entry 'start': '<S144>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else {
          if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
            /* Transition: '<S144>:229' */
            RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

            /* Entry Internal 'TurnLeft': '<S144>:230' */
            /* Transition: '<S144>:231' */
            RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

            /* Constant: '<S133>/ENU_CCW' */
            /* Entry 'start': '<S144>:239' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.turnActive = true;
          }
        }
      }
      break;

     case RobotControl_IN_forward:
      RobotControl_forward();
      break;

     default:
      /* During 'init': '<S144>:295' */
      if (RobotControl_DW.stableCounter >= RobotCont_CONST_MOVE_STABLE_CNT) {
        /* Transition: '<S144>:297' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

        /* Constant: '<S133>/ENU_ROB_NONE' */
        /* Entry Internal 'Stop': '<S144>:37' */
        /* Transition: '<S144>:309' */
        if ((RobotControl_B.OutportBufferForangleCalibStatu ==
             RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
             ENU_ROB_NONE)) {
          /* Transition: '<S144>:314' */
          /* Transition: '<S144>:316' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

          /* Transition: '<S144>:336' */
        } else {
          /* Transition: '<S144>:335' */
        }

        /* Transition: '<S144>:333' */
      } else {
        RobotControl_DW.stableCounter++;
      }
      break;
    }

    if (guard1) {
      switch (RobotControl_DW.is_TurnRight_c) {
       case RobotControl_IN_finish:
        /* During 'finish': '<S144>:225' */
        break;

       case RobotControl_IN_start:
        /* During 'start': '<S144>:226' */
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
        {
          /* Transition: '<S144>:223' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_NORTH) {
          /* Transition: '<S144>:219' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S144>:222' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else {
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S144>:220' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
          }
        }
        break;

       default:
        /* During 'turning': '<S144>:224' */
        if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
            (*Unit_Delay1)) {
          /* Transition: '<S144>:221' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_finish;

          /* Entry 'finish': '<S144>:225' */
          RobotControl_DW.turnActive = false;
        }
        break;
      }
    }
  }
}

/* System initialize for function-call system: '<S22>/MovementHandler' */
void RobotContr_MovementHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S143>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S142>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 1U;

  /* InitializeConditions for UnitDelay: '<S28>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = ((uint8_T)CAL_NO_ERROR);

  /* SystemInitialize for Chart: '<S136>/singleStepCalc' */
  RobotControl_DW.is_active_c36_MOVH = 0U;
  RobotControl_DW.is_c36_MOVH = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.tempDistance_mm = 0.0F;
  RobotControl_B.switchLaneStep = false;
  RobotControl_B.encoderStep = 0U;

  /* SystemInitialize for Chart: '<S133>/HighLevelMoves' */
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

  /* SystemInitialize for Chart: '<S134>/TargetReachedConfirmTime' */
  RobotControl_DW.counter_j = 0U;
  RobotControl_B.targetReached = false;
}

/* Output and update for function-call system: '<S22>/MovementHandler' */
void RobotControl_MovementHandler(void)
{
  boolean_T rtb_Relational_Operator_e4;
  real32_T rtb_Divide_e;
  int32_T rtb_headingRequest;
  real32_T rtb_Init_j;
  real32_T rtb_Init_n;
  real32_T rtb_Add2_f;
  real32_T rtb_Add_f;
  real32_T rtb_CCW;
  boolean_T zcEvent_idx_1;
  uint16_T tmp;

  /* RelationalOperator: '<S130>/Relational_Operator' incorporates:
   *  Constant: '<S130>/ENU_FORWARD'
   *  UnitDelay: '<S28>/Unit_Delay5'
   */
  rtb_Relational_Operator_e4 = (RobotControl_DW.Unit_Delay5_DSTATE_n ==
    ((uint8_T)ENU_FORWARD));

  /* Product: '<S130>/Divide' incorporates:
   *  Constant: '<S130>/CONST_TWO_F32'
   *  Sum: '<S130>/Add'
   */
  rtb_Divide_e = (RobotControl_B.Data_Type_Conversion_m +
                  RobotControl_B.Data_Type_Conversion) / CONST_TWO_F32;

  /* Chart: '<S136>/singleStepCalc' */
  /* Gateway: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* During: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* calculating single step the robot moves in straight line mainlt forward state. to it update the sensor view and also gives change lane step */
  if (RobotControl_DW.is_active_c36_MOVH == 0U) {
    /* Entry: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    RobotControl_DW.is_active_c36_MOVH = 1U;

    /* Entry Internal: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    /* Transition: '<S137>:39' */
    RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
  } else {
    switch (RobotControl_DW.is_c36_MOVH) {
     case RobotControl_IN_ForwardStep:
      /* During 'ForwardStep': '<S137>:57' */
      /* Transition: '<S137>:59' */
      RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      break;

     case RobotControl_IN_SwitchLaneStep:
      /* During 'SwitchLaneStep': '<S137>:42' */
      if (!RobotControl_B.OutportBufferForswitchLaneFlg_B) {
        /* Transition: '<S137>:44' */
        RobotControl_B.switchLaneStep = false;
        RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      }
      break;

     case RobotControl_IN_initiateDist:
      /* During 'initiateDist': '<S137>:40' */
      if (RobotControl_B.OutportBufferForswitchLaneFlg_B && (rtb_Divide_e -
           RobotControl_DW.tempDistance_mm >= RobotControl_CAL_BLOCK_SIZE_mm)) {
        /* Transition: '<S137>:43' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_SwitchLaneStep;

        /* Entry 'SwitchLaneStep': '<S137>:42' */
        RobotControl_B.switchLaneStep = true;
      } else if ((!RobotControl_B.OutportBufferForswitchLaneFlg_B) &&
                 (rtb_Divide_e - RobotControl_DW.tempDistance_mm >= 50.0F)) {
        /* Transition: '<S137>:58' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_ForwardStep;

        /* Entry 'ForwardStep': '<S137>:57' */
        RobotControl_B.encoderStep = 1U;
      } else {
        if (!rtb_Relational_Operator_e4) {
          /* Transition: '<S137>:61' */
          RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
        }
      }
      break;

     default:
      /* During 'waitingSwitchLane': '<S137>:38' */
      if (rtb_Relational_Operator_e4) {
        /* Transition: '<S137>:41' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_initiateDist;

        /* Entry 'initiateDist': '<S137>:40' */
        RobotControl_DW.tempDistance_mm = rtb_Divide_e;
        RobotControl_B.encoderStep = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S136>/singleStepCalc' */

  /* DataTypeConversion: '<S133>/Data Type Conversion1' */
  rtb_Divide_e = RobotControl_B.switchLaneStep;

  /* Chart: '<S133>/HighLevelMoves' incorporates:
   *  TriggerPort: '<S144>/input events'
   */
  rtb_Relational_Operator_e4 = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0]
    == POS_ZCSIG) != (int16_T)RobotControl_B.refreshEvent) &&
    (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] ==
                     POS_ZCSIG) != (int16_T)RobotControl_B.stopEvent) &&
                   (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] !=
                    UNINITIALIZED_ZCSIG));
  if (rtb_Relational_Operator_e4 || zcEvent_idx_1) {
    /* Gateway: MovementHandler/MoveMainStatemachine/HighLevelMoves */
    if ((int8_T)(rtb_Relational_Operator_e4 ? RobotControl_B.refreshEvent ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S144>:300' */
      RobotControl_DW.sfEvent_p = RobotControl_event_refreshEvent;

      /* UnitDelay: '<S28>/Unit_Delay1' */
      RobotControl_chartstep_c37_MOVH(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }

    if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S144>:301' */
      RobotControl_DW.sfEvent_p = RobotControl_event_stopEvent;

      /* UnitDelay: '<S28>/Unit_Delay1' */
      RobotControl_chartstep_c37_MOVH(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }
  }

  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] = RobotControl_B.refreshEvent;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] = RobotControl_B.stopEvent;

  /* Gain: '<S131>/Gain5' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  rtb_headingRequest = (int32_T)((uint32_T)tmp * RobotControl_B.headingRequest >>
    9);

  /* End of Gain: '<S131>/Gain5' */

  /* Sum: '<S131>/Subtract' */
  rtb_Divide_e = RobotControl_B.theta_mDeg - (real32_T)rtb_headingRequest;

  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S131>/CONST_ZERO_F32'
   *  Gain: '<S131>/Gain3'
   *  RelationalOperator: '<S131>/Relational_Operator1'
   */
  if (rtb_Divide_e < CONST_ZERO_F32) {
    /* Gain: '<S131>/Gain' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Sum: '<S131>/Subtract2' incorporates:
     *  Constant: '<S131>/CAL_fullCircle_DEG'
     *  Gain: '<S131>/Gain'
     *  Sum: '<S131>/Subtract1'
     */
    rtb_CCW = ((real32_T)((uint32_T)tmp * CAL_fullCircle_DEG >> 9) +
               RobotControl_B.theta_mDeg) - (real32_T)rtb_headingRequest;

    /* Gain: '<S131>/Gain1' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S131>/Switch2' incorporates:
     *  Abs: '<S131>/Abs'
     *  Constant: '<S131>/CAL_halfCircle_DEG1'
     *  DataTypeConversion: '<S131>/Data_Type_Conversion1'
     *  Gain: '<S131>/Gain1'
     *  Gain: '<S131>/Gain8'
     *  RelationalOperator: '<S131>/Relational_Operator3'
     */
    if (rtb_CCW > (int16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      rtb_Divide_e = (real32_T)fabs(rtb_Divide_e);
    } else {
      rtb_Divide_e = (real32_T)CONST_NegOne * rtb_CCW;
    }

    /* End of Switch: '<S131>/Switch2' */
  } else {
    if (((uint8_T)CAL_thetaGain) > 127) {
      /* Gain: '<S131>/Gain3' */
      tmp = MAX_uint16_T;
    } else {
      /* Gain: '<S131>/Gain3' */
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S131>/Switch1' incorporates:
     *  Abs: '<S131>/Abs1'
     *  Constant: '<S131>/CAL_fullCircle_DEG1'
     *  Constant: '<S131>/CAL_halfCircle_DEG'
     *  DataTypeConversion: '<S131>/Data_Type_Conversion'
     *  Gain: '<S131>/Gain2'
     *  Gain: '<S131>/Gain3'
     *  Gain: '<S131>/Gain7'
     *  RelationalOperator: '<S131>/Relational_Operator2'
     *  Sum: '<S131>/Subtract3'
     *  Sum: '<S131>/Subtract4'
     */
    if (rtb_Divide_e > (uint16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      /* Gain: '<S131>/Gain2' */
      if (((uint8_T)CAL_thetaGain) > 127) {
        tmp = MAX_uint16_T;
      } else {
        tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
      }

      rtb_Divide_e = (real32_T)fabs(RobotControl_B.theta_mDeg - (real32_T)
        ((int32_T)((uint32_T)tmp * CAL_fullCircle_DEG >> 9) + rtb_headingRequest));
    } else {
      rtb_Divide_e *= (real32_T)CONST_NegOne;
    }

    /* End of Switch: '<S131>/Switch1' */
  }

  /* End of Switch: '<S131>/Switch' */

  /* Gain: '<S131>/Gain4' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  /* Product: '<S131>/Divide' incorporates:
   *  Constant: '<S131>/CAL_halfCircle_DEG2'
   *  Gain: '<S131>/Gain4'
   */
  rtb_CCW = rtb_Divide_e / (real32_T)(int16_T)((uint32_T)tmp *
    CAL_halfCircle_DEG >> 9);

  /* Abs: '<S28>/Abs' */
  rtb_Divide_e = (real32_T)fabs(rtb_CCW);

  /* Switch: '<S143>/Init' incorporates:
   *  Constant: '<S143>/Initial Condition'
   *  Logic: '<S143>/FixPt Logical Operator'
   *  UnitDelay: '<S143>/FixPt Unit Delay1'
   *  UnitDelay: '<S143>/FixPt Unit Delay2'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_j != 0)) {
    rtb_Init_j = 0.0F;
  } else {
    rtb_Init_j = RobotControl_DW.FixPtUnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S143>/Init' */

  /* Sum: '<S138>/Add' */
  rtb_Add_f = rtb_CCW + rtb_Init_j;

  /* Switch: '<S142>/Init' incorporates:
   *  Constant: '<S142>/Initial Condition'
   *  Logic: '<S142>/FixPt Logical Operator'
   *  UnitDelay: '<S142>/FixPt Unit Delay1'
   *  UnitDelay: '<S142>/FixPt Unit Delay2'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_jc != 0)) {
    rtb_Init_n = 0.0F;
  } else {
    rtb_Init_n = RobotControl_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S142>/Init' */

  /* Sum: '<S138>/Add2' */
  rtb_Add2_f = rtb_CCW - rtb_Init_n;

  /* Switch: '<S142>/Reset' incorporates:
   *  Constant: '<S138>/CONST_EnableDelay1'
   *  Switch: '<S140>/Enable'
   *  Switch: '<S141>/Enable'
   *  Switch: '<S143>/Reset'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o) {
    /* Update for UnitDelay: '<S142>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S142>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = 0.0F;

    /* Update for UnitDelay: '<S143>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S143>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = 0.0F;
  } else if (CONST_EnableDelay) {
    /* Switch: '<S140>/Enable' incorporates:
     *  Update for UnitDelay: '<S142>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Add2_f;

    /* Switch: '<S141>/Enable' incorporates:
     *  Update for UnitDelay: '<S143>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Add_f;
  } else {
    /* Update for UnitDelay: '<S142>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S140>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Init_n;

    /* Update for UnitDelay: '<S143>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S141>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Init_j;
  }

  /* End of Switch: '<S142>/Reset' */

  /* Sum: '<S139>/Add' incorporates:
   *  Gain: '<S138>/Kd'
   *  Gain: '<S138>/Ki'
   *  Gain: '<S138>/Kp'
   *  Sum: '<S138>/Add1'
   *  UnitDelay: '<S131>/Unit Delay'
   */
  rtb_CCW = ((CAL_Kd * rtb_Add2_f + CAL_Kp * rtb_CCW) + CAL_Ki * rtb_Add_f) -
    RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S139>/Switch' incorporates:
   *  Constant: '<S139>/Constant'
   *  MinMax: '<S139>/MinMax1'
   *  RelationalOperator: '<S139>/Relational Operator'
   */
  if (rtb_CCW > 0.0F) {
    /* MinMax: '<S139>/MinMax' */
    if (2.5F <= rtb_CCW) {
      rtb_CCW = 2.5F;
    }

    /* End of MinMax: '<S139>/MinMax' */
  } else {
    if (!((rtb_CCW >= RobotControl_ConstB.Gain) || rtIsNaNF
          (RobotControl_ConstB.Gain))) {
      /* MinMax: '<S139>/MinMax1' */
      rtb_CCW = RobotControl_ConstB.Gain;
    }
  }

  /* End of Switch: '<S139>/Switch' */

  /* Sum: '<S139>/Add2' incorporates:
   *  UnitDelay: '<S131>/Unit Delay'
   */
  rtb_CCW += RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/CONST_ZERO_F32'
   *  Constant: '<S135>/ENU_CCW'
   *  RelationalOperator: '<S135>/Relational_Operator'
   *  Switch: '<S135>/Switch1'
   *  UnitDelay: '<S28>/Unit_Delay3'
   *  UnitDelay: '<S28>/Unit_Delay4'
   */
  if (RobotControl_DW.Unit_Delay3_DSTATE_c) {
    RobotControl_B.turnRequestFiltered = RobotControl_B.turnRequest;
  } else if (RobotControl_DW.Unit_Delay4_DSTATE > CONST_ZERO_F32) {
    /* Switch: '<S135>/Switch1' incorporates:
     *  Constant: '<S135>/ENU_CW'
     */
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CW);
  } else {
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CCW);
  }

  /* End of Switch: '<S135>/Switch' */

  /* RelationalOperator: '<S132>/Relational_Operator2' incorporates:
   *  Constant: '<S132>/ENU_FORWARD4'
   */
  rtb_Relational_Operator_e4 = (RobotControl_B.turnRequestFiltered == ((uint8_T)
    ENU_FORWARD));

  /* RelationalOperator: '<S132>/Relational_Operator3' incorporates:
   *  Constant: '<S132>/ENU_BACKWARD3'
   */
  zcEvent_idx_1 = (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_BACKWARD));

  /* Switch: '<S132>/Switch' incorporates:
   *  Constant: '<S132>/ENU_BACKWARD'
   *  Constant: '<S132>/ENU_CCW'
   *  Constant: '<S132>/ENU_CW'
   *  Constant: '<S132>/ENU_FORWARD'
   *  Constant: '<S132>/ENU_STOP'
   *  RelationalOperator: '<S132>/Relational_Operator'
   *  RelationalOperator: '<S132>/Relational_Operator1'
   *  Switch: '<S132>/Switch'
   *  Switch: '<S132>/Switch1'
   *  Switch: '<S132>/Switch2'
   *  Switch: '<S132>/Switch3'
   */
  if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CCW)) {
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_FORWARD);
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_BACKWARD);
  } else if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CW)) {
    /* Switch: '<S132>/Switch1' incorporates:
     *  Constant: '<S132>/ENU_BACKWARD1'
     */
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_BACKWARD);

    /* Switch: '<S132>/Switch1' incorporates:
     *  Constant: '<S132>/ENU_FORWARD1'
     */
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_FORWARD);
  } else if (rtb_Relational_Operator_e4) {
    /* Switch: '<S132>/Switch2' incorporates:
     *  Constant: '<S132>/ENU_FORWARD3'
     *  Switch: '<S132>/Switch1'
     */
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_FORWARD);

    /* Switch: '<S132>/Switch2' incorporates:
     *  Constant: '<S132>/ENU_FORWARD2'
     *  Switch: '<S132>/Switch1'
     */
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_FORWARD);
  } else {
    if (zcEvent_idx_1) {
      /* Switch: '<S132>/Switch3' incorporates:
       *  Constant: '<S132>/ENU_BACKWARD4'
       *  Switch: '<S132>/Switch1'
       *  Switch: '<S132>/Switch2'
       */
      RobotControl_B.rightMotorRequest = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.rightMotorRequest = ((uint8_T)ENU_STOP);
    }

    /* Switch: '<S132>/Switch3' incorporates:
     *  Constant: '<S132>/ENU_BACKWARD2'
     *  Constant: '<S132>/ENU_STOP'
     *  Constant: '<S132>/ENU_STOP1'
     *  Switch: '<S132>/Switch1'
     *  Switch: '<S132>/Switch2'
     *  Switch: '<S132>/Switch3'
     */
    if (zcEvent_idx_1) {
      RobotControl_B.leftMotorRequest = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.leftMotorRequest = ((uint8_T)ENU_STOP);
    }

    /* End of Switch: '<S132>/Switch3' */
  }

  /* End of Switch: '<S132>/Switch' */

  /* Chart: '<S134>/TargetReachedConfirmTime' */
  /* Gateway: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* During: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* time needed to confirm steady state for the PID */
  /* Entry Internal: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* Transition: '<S145>:2' */
  if (rtb_Divide_e <= RobotCo_CAL_ALLOWED_ERROR_VALUE) {
    /* Transition: '<S145>:4' */
    /* Transition: '<S145>:6' */
    RobotControl_DW.counter_j++;
    if (RobotControl_DW.counter_j > (int16_T)Robo_CONST_TARGET_REACHED_TIMER) {
      /* Transition: '<S145>:15' */
      /* Transition: '<S145>:16' */
      RobotControl_DW.counter_j = 0U;
      RobotControl_B.targetReached = true;

      /* Transition: '<S145>:21' */
    } else {
      /* Transition: '<S145>:8' */
    }

    /* Transition: '<S145>:14' */
  } else {
    /* Transition: '<S145>:9' */
    RobotControl_DW.counter_j = 0U;
    RobotControl_B.targetReached = false;
  }

  /* End of Chart: '<S134>/TargetReachedConfirmTime' */

  /* SignalConversion: '<S28>/OutportBufferFortargetReached' */
  RobotControl_B.OutportBufferFortargetReached = RobotControl_B.targetReached;

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/CAL_NO_ERROR'
   *  Constant: '<S28>/ENU_BACKWARD'
   *  Constant: '<S28>/ENU_FORWARD'
   *  Constant: '<S28>/ENU_SHIFT_HEADING'
   *  Constant: '<S28>/ENU_STOP'
   *  Constant: '<S28>/ENU_TEST_INIT'
   *  Logic: '<S28>/Logical Operator'
   *  Logic: '<S28>/Logical Operator1'
   *  Logic: '<S28>/Logical_Operator'
   *  RelationalOperator: '<S28>/Relational_Operator1'
   *  RelationalOperator: '<S28>/Relational_Operator2'
   *  RelationalOperator: '<S28>/Relational_Operator3'
   *  RelationalOperator: '<S28>/Relational_Operator4'
   *  RelationalOperator: '<S28>/Relational_Operator6'
   *  Switch: '<S28>/Switch1'
   */
  if ((RobotControl_B.turnRequest == ((uint8_T)ENU_STOP)) &&
      (RobotControl_B.comTstStatus != ((uint8_T)ENU_TEST_INIT)) &&
      (RobotControl_B.currentRoutine != ((uint8_T)ENU_SHIFT_HEADING))) {
    RobotControl_B.thetaError = ((uint8_T)CAL_NO_ERROR);
  } else if ((RobotControl_B.turnRequest == ((uint8_T)ENU_FORWARD)) ||
             (RobotControl_B.turnRequest == ((uint8_T)ENU_BACKWARD))) {
    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S28>/CAL_NO_ERROR1'
     */
    RobotControl_B.thetaError = ((uint8_T)CAL_NO_ERROR);
  } else {
    RobotControl_B.thetaError = rtb_CCW;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Update for UnitDelay: '<S28>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_n = RobotControl_B.turnRequest;

  /* Update for UnitDelay: '<S28>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_p = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S28>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_o = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S143>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S143>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S142>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S142>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 0U;

  /* Update for UnitDelay: '<S131>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE = rtb_CCW;

  /* Update for UnitDelay: '<S28>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_c = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S28>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = RobotControl_B.thetaError;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
