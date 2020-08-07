/*
 * File: MovementHandler.c
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

#include "MovementHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S135>/singleStepCalc' */
#define RobotContr_IN_NO_ACTIVE_CHILD_g ((uint8_T)0U)
#define RobotContr_IN_waitingSwitchLane ((uint8_T)4U)
#define RobotControl_CAL_BLOCK_SIZE_mm (250U)
#define RobotControl_IN_ForwardStep    ((uint8_T)1U)
#define RobotControl_IN_SwitchLaneStep ((uint8_T)2U)
#define RobotControl_IN_initiateDist   ((uint8_T)3U)

/* Named constants for Chart: '<S132>/HighLevelMoves' */
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

/* Named constants for Chart: '<S133>/TargetReachedConfirmTime' */
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

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_Stop(void)
{
  /* During 'Stop': '<S143>:37' */
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      RobotControl_DW.turnActive) {
    /* Constant: '<S132>/ENU_FORWARD' incorporates:
     *  Constant: '<S132>/ENU_BACKWARD'
     *  Constant: '<S132>/ENU_MOVE_TURN_LEFT'
     *  Constant: '<S132>/ENU_MOVE_TURN_RIGHT'
     *  Constant: '<S132>/ENU_MOVE_U_TURN'
     *  Constant: '<S132>/ENU_MOVE_U_TURN_LEFT'
     *  Constant: '<S132>/ENU_MOVE_U_TURN_RIGHT'
     *  Constant: '<S132>/ENU_STOP'
     */
    /* Transition: '<S143>:38' */
    /* previous turn not completed */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S143>:8' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Constant: '<S132>/ENU_BACKWARD' */
      /* Transition: '<S143>:11' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Constant: '<S132>/ENU_STOP' */
      /* Transition: '<S143>:39' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else {
      if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
        /* Transition: '<S143>:229' */
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

        /* Entry Internal 'TurnLeft': '<S143>:230' */
        /* Transition: '<S143>:231' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

        /* Constant: '<S132>/ENU_CCW' */
        /* Entry 'start': '<S143>:239' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      }
    }

    /* End of Constant: '<S132>/ENU_FORWARD' */
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_TurnLeft(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'TurnLeft': '<S143>:230' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S143>:240' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S143>:8' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S143>:11' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S143>:39' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_TurnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S143>:229' */
      /* Exit Internal 'TurnLeft': '<S143>:230' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S143>:230' */
      /* Transition: '<S143>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:239' */
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
      /* During 'finish': '<S143>:237' */
      break;

     case RobotControl_IN_start:
      /* During 'start': '<S143>:239' */
      if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_NORTH) {
        /* Transition: '<S143>:232' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_EAST) {
        /* Transition: '<S143>:236' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_SOUTH) {
        /* Transition: '<S143>:233' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else {
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_WEST)
        {
          /* Transition: '<S143>:235' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
        }
      }
      break;

     default:
      /* During 'turning': '<S143>:238' */
      if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
          (*Unit_Delay1)) {
        /* Transition: '<S143>:234' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_finish;

        /* Entry 'finish': '<S143>:237' */
        RobotControl_DW.turnActive = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_Uturn(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'Uturn': '<S143>:30' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S143>:34' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S143>:8' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S143>:11' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S143>:39' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S143>:229' */
      /* Exit Internal 'Uturn': '<S143>:30' */
      /* Exit Internal 'TurnRight': '<S143>:186' */
      RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_Uturn = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S143>:230' */
      /* Transition: '<S143>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:239' */
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
      /* During 'TurnRight': '<S143>:186' */
      if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD) {
        /* Transition: '<S143>:246' */
        /* Exit Internal 'TurnRight': '<S143>:186' */
        RobotControl_DW.is_TurnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_Uturn = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S143>:175' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S143>:194' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S143>:195' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S143>:192' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S143>:188' */
            /* headingRequest = ROB_EAST; */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S143>:191' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S143>:189' */
              /* headingRequest = ROB_WEST; */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
              RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S143>:193' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S143>:190' */
            RobotControl_DW.is_TurnRight = RobotControl_IN_finish;

            /* Entry 'finish': '<S143>:194' */
            RobotControl_DW.uTurnCounter++;
            RobotControl_DW.turnActive = false;
          }
          break;
        }
      }
    } else {
      /* During 'finish': '<S143>:175' */
    }
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_UturnLeft(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnLeft': '<S143>:28' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S143>:36' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S143>:8' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S143>:11' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S143>:39' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S143>:229' */
      /* Exit Internal 'UturnLeft': '<S143>:28' */
      /* Exit Internal 'TurnLeft': '<S143>:79' */
      RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnLeft = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S143>:230' */
      /* Transition: '<S143>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:239' */
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
      /* During 'TurnLeft': '<S143>:79' */
      if ((RobotControl_DW.uTurnCounter == 1) &&
          (RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start)) {
        /* Transition: '<S143>:115' */
        /* Exit Internal 'TurnLeft': '<S143>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_forwardStep;

        /* Constant: '<S132>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S143>:113' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S143>:114' */
        /* Exit Internal 'TurnLeft': '<S143>:79' */
        RobotControl_DW.is_TurnLeft_f = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S143>:112' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnLeft_f) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S143>:89' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S143>:90' */
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_NORTH) {
            /* Transition: '<S143>:82' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_EAST) {
            /* Transition: '<S143>:88' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S143>:84' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_WEST) {
              /* Transition: '<S143>:86' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
              RobotControl_DW.is_TurnLeft_f = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S143>:185' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S143>:81' */
            RobotControl_DW.is_TurnLeft_f = RobotControl_IN_finish;

            /* Entry 'finish': '<S143>:89' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S143>:112' */
      break;

     default:
      /* During 'forwardStep': '<S143>:113' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S143>:116' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S143>:79' */
        /* Transition: '<S143>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S132>/ENU_CCW' */
        /* Entry 'start': '<S143>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S143>:302' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

        /* Entry Internal 'TurnLeft': '<S143>:79' */
        /* Transition: '<S143>:80' */
        RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

        /* Constant: '<S132>/ENU_CCW' */
        /* Entry 'start': '<S143>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_UturnRight(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnRight': '<S143>:29' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S143>:32' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S143>:8' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S143>:11' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S143>:39' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S143>:229' */
      /* Exit Internal 'UturnRight': '<S143>:29' */
      /* Exit Internal 'TurnRight': '<S143>:95' */
      RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_UturnRight = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S143>:230' */
      /* Transition: '<S143>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:239' */
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
      /* During 'TurnRight': '<S143>:95' */
      if ((RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start) && (RobotControl_DW.uTurnCounter ==
           1)) {
        /* Transition: '<S143>:124' */
        /* Exit Internal 'TurnRight': '<S143>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_forwardStep;

        /* Constant: '<S132>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S143>:125' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S143>:123' */
        /* Exit Internal 'TurnRight': '<S143>:95' */
        RobotControl_DW.is_TurnRight_b = RobotContr_IN_NO_ACTIVE_CHILD_g;
        RobotControl_DW.is_UturnRight = RobotControl_IN_finish_f;

        /* Entry 'finish': '<S143>:120' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight_b) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S143>:242' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S143>:106' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S143>:104' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S143>:98' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S143>:102' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S143>:100' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
              RobotControl_DW.is_TurnRight_b = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S143>:183' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S143>:243' */
            RobotControl_DW.is_TurnRight_b = RobotControl_IN_finish;

            /* Entry 'finish': '<S143>:242' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_f:
      /* During 'finish': '<S143>:120' */
      break;

     default:
      /* During 'forwardStep': '<S143>:125' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S143>:122' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S143>:95' */
        /* Transition: '<S143>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S132>/ENU_CW' */
        /* Entry 'start': '<S143>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_p == RobotControl_event_stopEvent) {
        /* Transition: '<S143>:303' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

        /* Entry Internal 'TurnRight': '<S143>:95' */
        /* Transition: '<S143>:96' */
        RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

        /* Constant: '<S132>/ENU_CW' */
        /* Entry 'start': '<S143>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
static void RobotControl_forward(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During 'forward': '<S143>:4' */
  guard1 = false;
  guard2 = false;
  if (RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) {
    /* Transition: '<S143>:10' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Constant: '<S132>/ENU_FORWARD' */
      /* Transition: '<S143>:8' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S143>:4' */
      /* Transition: '<S143>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S143>:11' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S143>:31' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S143>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S143>:29' */
      /* Transition: '<S143>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:95' */
      /* Transition: '<S143>:96' */
      RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S143>:33' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S143>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S143>:30' */
      /* Transition: '<S143>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

      /* Entry Internal 'TurnRight': '<S143>:186' */
      /* Transition: '<S143>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S143>:35' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S143>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S143>:28' */
      /* Transition: '<S143>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

      /* Entry Internal 'TurnLeft': '<S143>:79' */
      /* Transition: '<S143>:80' */
      RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S143>:39' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;

      /* Constant: '<S132>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

      /* Constant: '<S132>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S143>:37' */
      /* Transition: '<S143>:309' */
      if ((RobotControl_B.OutportBufferForangleCalibStatu ==
           RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S143>:314' */
        /* Transition: '<S143>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S143>:336' */
      } else {
        /* Transition: '<S143>:335' */
      }

      /* End of Constant: '<S132>/ENU_ROB_NONE' */
      /* Transition: '<S143>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S143>:227' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S143>:217' */
      /* Transition: '<S143>:218' */
      RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CW' */
      /* Entry 'start': '<S143>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S143>:229' */
      /* Exit Internal 'forward': '<S143>:4' */
      RobotControl_DW.is_forward = RobotContr_IN_NO_ACTIVE_CHILD_g;
      RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S143>:230' */
      /* Transition: '<S143>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S132>/ENU_CCW' */
      /* Entry 'start': '<S143>:239' */
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
      /* During 'Idle': '<S143>:247' */
      /* Transition: '<S143>:271' */
      if (!((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
             RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
            RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)))
      {
        /* Transition: '<S143>:251' */
        if (RobotControl_B.headingRequest == (uint16_T)RobotControl_B.ROB_NORTH)
        {
          /* Transition: '<S143>:256' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S132>/ENU_CCW' */
            /* Transition: '<S143>:261' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S132>/ENU_CW' */
            /* Transition: '<S143>:263' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_SOUTH) {
          /* Transition: '<S143>:257' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S132>/ENU_CW' */
            /* Transition: '<S143>:264' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S132>/ENU_CCW' */
            /* Transition: '<S143>:265' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_EAST) {
          /* Transition: '<S143>:258' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S132>/ENU_CW' */
            /* Transition: '<S143>:266' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S132>/ENU_CCW' */
            /* Transition: '<S143>:267' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S143>:259' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S132>/ENU_CCW' */
            /* Transition: '<S143>:268' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S132>/ENU_CW' */
            /* Transition: '<S143>:269' */
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
      /* During 'fixingHeading': '<S143>:260' */
      /* Transition: '<S143>:273' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
      break;
    }
  }

  if (guard1) {
    if ((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
         RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
         RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)) {
      /* Constant: '<S132>/ENU_FORWARD' */
      /* Transition: '<S143>:272' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    }
  }
}

/* Function for Chart: '<S132>/HighLevelMoves' */
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
    /* Transition: '<S143>:3' */
    RobotControl_DW.is_c37_MOVH = RobotControl_IN_init;

    /* Entry 'init': '<S143>:295' */
    RobotControl_DW.stableCounter = 0U;

    /* Constant: '<S132>/ENU_STOP' */
    RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);

    /* Constant: '<S132>/ENU_ROB_NONE' */
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
      /* During 'TurnRight': '<S143>:217' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Transition: '<S143>:228' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S143>:8' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S132>/ENU_FORWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S143>:4' */
          /* Transition: '<S143>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Transition: '<S143>:11' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S132>/ENU_BACKWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S143>:31' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S143>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S143>:29' */
          /* Transition: '<S143>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S143>:95' */
          /* Transition: '<S143>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S143>:33' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S143>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S143>:30' */
          /* Transition: '<S143>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S143>:186' */
          /* Transition: '<S143>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S143>:35' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S143>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S143>:28' */
          /* Transition: '<S143>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S143>:79' */
          /* Transition: '<S143>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CCW' */
          /* Entry 'start': '<S143>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Transition: '<S143>:39' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;

          /* Constant: '<S132>/ENU_STOP' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S132>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S143>:37' */
          /* Transition: '<S143>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S143>:314' */
            /* Transition: '<S143>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S143>:336' */
          } else {
            /* Transition: '<S143>:335' */
          }

          /* Transition: '<S143>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S143>:227' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S143>:217' */
          /* Transition: '<S143>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT))
        {
          /* Transition: '<S143>:229' */
          /* Exit Internal 'TurnRight': '<S143>:217' */
          RobotControl_DW.is_TurnRight_c = RobotContr_IN_NO_ACTIVE_CHILD_g;
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

          /* Entry Internal 'TurnLeft': '<S143>:230' */
          /* Transition: '<S143>:231' */
          RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CCW' */
          /* Entry 'start': '<S143>:239' */
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
      /* During 'backward': '<S143>:5' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Constant: '<S132>/ENU_FORWARD' incorporates:
         *  Constant: '<S132>/ENU_BACKWARD'
         *  Constant: '<S132>/ENU_MOVE_TURN_LEFT'
         *  Constant: '<S132>/ENU_MOVE_TURN_RIGHT'
         *  Constant: '<S132>/ENU_MOVE_U_TURN'
         *  Constant: '<S132>/ENU_MOVE_U_TURN_LEFT'
         *  Constant: '<S132>/ENU_MOVE_U_TURN_RIGHT'
         *  Constant: '<S132>/ENU_STOP'
         */
        /* Transition: '<S143>:12' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S143>:8' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S143>:4' */
          /* Transition: '<S143>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Constant: '<S132>/ENU_BACKWARD' */
          /* Transition: '<S143>:11' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S143>:31' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S143>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S143>:29' */
          /* Transition: '<S143>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S143>:95' */
          /* Transition: '<S143>:96' */
          RobotControl_DW.is_TurnRight_b = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S143>:33' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S143>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S143>:30' */
          /* Transition: '<S143>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_a;

          /* Entry Internal 'TurnRight': '<S143>:186' */
          /* Transition: '<S143>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S143>:35' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S143>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S143>:28' */
          /* Transition: '<S143>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_b;

          /* Entry Internal 'TurnLeft': '<S143>:79' */
          /* Transition: '<S143>:80' */
          RobotControl_DW.is_TurnLeft_f = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CCW' */
          /* Entry 'start': '<S143>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Constant: '<S132>/ENU_STOP' */
          /* Transition: '<S143>:39' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

          /* Constant: '<S132>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S143>:37' */
          /* Transition: '<S143>:309' */
          if ((RobotControl_B.OutportBufferForangleCalibStatu ==
               RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S143>:314' */
            /* Transition: '<S143>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S143>:336' */
          } else {
            /* Transition: '<S143>:335' */
          }

          /* Transition: '<S143>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S143>:227' */
          RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S143>:217' */
          /* Transition: '<S143>:218' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_start;

          /* Constant: '<S132>/ENU_CW' */
          /* Entry 'start': '<S143>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else {
          if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
            /* Transition: '<S143>:229' */
            RobotControl_DW.is_c37_MOVH = RobotControl_IN_TurnLeft;

            /* Entry Internal 'TurnLeft': '<S143>:230' */
            /* Transition: '<S143>:231' */
            RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

            /* Constant: '<S132>/ENU_CCW' */
            /* Entry 'start': '<S143>:239' */
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
      /* During 'init': '<S143>:295' */
      if (RobotControl_DW.stableCounter >= RobotCont_CONST_MOVE_STABLE_CNT) {
        /* Transition: '<S143>:297' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_c37_MOVH = RobotControl_IN_Stop;

        /* Constant: '<S132>/ENU_ROB_NONE' */
        /* Entry Internal 'Stop': '<S143>:37' */
        /* Transition: '<S143>:309' */
        if ((RobotControl_B.OutportBufferForangleCalibStatu ==
             RobotControl_ENU_FINISHED) && (RobotControl_B.currentHeading ==
             ENU_ROB_NONE)) {
          /* Transition: '<S143>:314' */
          /* Transition: '<S143>:316' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

          /* Transition: '<S143>:336' */
        } else {
          /* Transition: '<S143>:335' */
        }

        /* Transition: '<S143>:333' */
      } else {
        RobotControl_DW.stableCounter++;
      }
      break;
    }

    if (guard1) {
      switch (RobotControl_DW.is_TurnRight_c) {
       case RobotControl_IN_finish:
        /* During 'finish': '<S143>:225' */
        break;

       case RobotControl_IN_start:
        /* During 'start': '<S143>:226' */
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
        {
          /* Transition: '<S143>:223' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_NORTH) {
          /* Transition: '<S143>:219' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S143>:222' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
        } else {
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S143>:220' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnRight_c = RobotControl_IN_turning;
          }
        }
        break;

       default:
        /* During 'turning': '<S143>:224' */
        if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
            (*Unit_Delay1)) {
          /* Transition: '<S143>:221' */
          RobotControl_DW.is_TurnRight_c = RobotControl_IN_finish;

          /* Entry 'finish': '<S143>:225' */
          RobotControl_DW.turnActive = false;
        }
        break;
      }
    }
  }
}

/* System initialize for function-call system: '<S21>/MovementHandler' */
void RobotContr_MovementHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S142>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S141>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 1U;

  /* InitializeConditions for UnitDelay: '<S27>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = ((uint8_T)CAL_NO_ERROR);

  /* SystemInitialize for Chart: '<S135>/singleStepCalc' */
  RobotControl_DW.is_active_c36_MOVH = 0U;
  RobotControl_DW.is_c36_MOVH = RobotContr_IN_NO_ACTIVE_CHILD_g;
  RobotControl_DW.tempDistance_mm = 0.0F;
  RobotControl_B.switchLaneStep = false;
  RobotControl_B.encoderStep = 0U;

  /* SystemInitialize for Chart: '<S132>/HighLevelMoves' */
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

  /* SystemInitialize for Chart: '<S133>/TargetReachedConfirmTime' */
  RobotControl_DW.counter_j = 0U;
  RobotControl_B.targetReached = false;
}

/* Output and update for function-call system: '<S21>/MovementHandler' */
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

  /* RelationalOperator: '<S129>/Relational_Operator' incorporates:
   *  Constant: '<S129>/ENU_FORWARD'
   *  UnitDelay: '<S27>/Unit_Delay5'
   */
  rtb_Relational_Operator_e4 = (RobotControl_DW.Unit_Delay5_DSTATE_n ==
    ((uint8_T)ENU_FORWARD));

  /* Product: '<S129>/Divide' incorporates:
   *  Constant: '<S129>/CONST_TWO_F32'
   *  Sum: '<S129>/Add'
   */
  rtb_Divide_e = (RobotControl_B.Data_Type_Conversion_m +
                  RobotControl_B.Data_Type_Conversion) / CONST_TWO_F32;

  /* Chart: '<S135>/singleStepCalc' */
  /* Gateway: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* During: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* calculating single step the robot moves in straight line mainlt forward state. to it update the sensor view and also gives change lane step */
  if (RobotControl_DW.is_active_c36_MOVH == 0U) {
    /* Entry: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    RobotControl_DW.is_active_c36_MOVH = 1U;

    /* Entry Internal: MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    /* Transition: '<S136>:39' */
    RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
  } else {
    switch (RobotControl_DW.is_c36_MOVH) {
     case RobotControl_IN_ForwardStep:
      /* During 'ForwardStep': '<S136>:57' */
      /* Transition: '<S136>:59' */
      RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      break;

     case RobotControl_IN_SwitchLaneStep:
      /* During 'SwitchLaneStep': '<S136>:42' */
      if (!RobotControl_B.OutportBufferForswitchLaneFlg_B) {
        /* Transition: '<S136>:44' */
        RobotControl_B.switchLaneStep = false;
        RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
      }
      break;

     case RobotControl_IN_initiateDist:
      /* During 'initiateDist': '<S136>:40' */
      if (RobotControl_B.OutportBufferForswitchLaneFlg_B && (rtb_Divide_e -
           RobotControl_DW.tempDistance_mm >= RobotControl_CAL_BLOCK_SIZE_mm)) {
        /* Transition: '<S136>:43' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_SwitchLaneStep;

        /* Entry 'SwitchLaneStep': '<S136>:42' */
        RobotControl_B.switchLaneStep = true;
      } else if ((!RobotControl_B.OutportBufferForswitchLaneFlg_B) &&
                 (rtb_Divide_e - RobotControl_DW.tempDistance_mm >= 50.0F)) {
        /* Transition: '<S136>:58' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_ForwardStep;

        /* Entry 'ForwardStep': '<S136>:57' */
        RobotControl_B.encoderStep = 1U;
      } else {
        if (!rtb_Relational_Operator_e4) {
          /* Transition: '<S136>:61' */
          RobotControl_DW.is_c36_MOVH = RobotContr_IN_waitingSwitchLane;
        }
      }
      break;

     default:
      /* During 'waitingSwitchLane': '<S136>:38' */
      if (rtb_Relational_Operator_e4) {
        /* Transition: '<S136>:41' */
        RobotControl_DW.is_c36_MOVH = RobotControl_IN_initiateDist;

        /* Entry 'initiateDist': '<S136>:40' */
        RobotControl_DW.tempDistance_mm = rtb_Divide_e;
        RobotControl_B.encoderStep = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S135>/singleStepCalc' */

  /* DataTypeConversion: '<S132>/Data Type Conversion1' */
  rtb_Divide_e = RobotControl_B.switchLaneStep;

  /* Chart: '<S132>/HighLevelMoves' incorporates:
   *  TriggerPort: '<S143>/input events'
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
      /* Event: '<S143>:300' */
      RobotControl_DW.sfEvent_p = RobotControl_event_refreshEvent;

      /* UnitDelay: '<S27>/Unit_Delay1' */
      RobotControl_chartstep_c37_MOVH(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }

    if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S143>:301' */
      RobotControl_DW.sfEvent_p = RobotControl_event_stopEvent;

      /* UnitDelay: '<S27>/Unit_Delay1' */
      RobotControl_chartstep_c37_MOVH(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }
  }

  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] = RobotControl_B.refreshEvent;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] = RobotControl_B.stopEvent;

  /* Gain: '<S130>/Gain5' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  rtb_headingRequest = (int32_T)((uint32_T)tmp * RobotControl_B.headingRequest >>
    9);

  /* End of Gain: '<S130>/Gain5' */

  /* Sum: '<S130>/Subtract' */
  rtb_Divide_e = RobotControl_B.theta_mDeg - (real32_T)rtb_headingRequest;

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/CONST_ZERO_F32'
   *  Gain: '<S130>/Gain3'
   *  RelationalOperator: '<S130>/Relational_Operator1'
   */
  if (rtb_Divide_e < CONST_ZERO_F32) {
    /* Gain: '<S130>/Gain' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Sum: '<S130>/Subtract2' incorporates:
     *  Constant: '<S130>/CAL_fullCircle_DEG'
     *  Gain: '<S130>/Gain'
     *  Sum: '<S130>/Subtract1'
     */
    rtb_CCW = ((real32_T)((uint32_T)tmp * CAL_fullCircle_DEG >> 9) +
               RobotControl_B.theta_mDeg) - (real32_T)rtb_headingRequest;

    /* Gain: '<S130>/Gain1' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S130>/Switch2' incorporates:
     *  Abs: '<S130>/Abs'
     *  Constant: '<S130>/CAL_halfCircle_DEG1'
     *  DataTypeConversion: '<S130>/Data_Type_Conversion1'
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S130>/Gain8'
     *  RelationalOperator: '<S130>/Relational_Operator3'
     */
    if (rtb_CCW > (int16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      rtb_Divide_e = (real32_T)fabs(rtb_Divide_e);
    } else {
      rtb_Divide_e = (real32_T)CONST_NegOne * rtb_CCW;
    }

    /* End of Switch: '<S130>/Switch2' */
  } else {
    if (((uint8_T)CAL_thetaGain) > 127) {
      /* Gain: '<S130>/Gain3' */
      tmp = MAX_uint16_T;
    } else {
      /* Gain: '<S130>/Gain3' */
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S130>/Switch1' incorporates:
     *  Abs: '<S130>/Abs1'
     *  Constant: '<S130>/CAL_fullCircle_DEG1'
     *  Constant: '<S130>/CAL_halfCircle_DEG'
     *  DataTypeConversion: '<S130>/Data_Type_Conversion'
     *  Gain: '<S130>/Gain2'
     *  Gain: '<S130>/Gain3'
     *  Gain: '<S130>/Gain7'
     *  RelationalOperator: '<S130>/Relational_Operator2'
     *  Sum: '<S130>/Subtract3'
     *  Sum: '<S130>/Subtract4'
     */
    if (rtb_Divide_e > (uint16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      /* Gain: '<S130>/Gain2' */
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

    /* End of Switch: '<S130>/Switch1' */
  }

  /* End of Switch: '<S130>/Switch' */

  /* Gain: '<S130>/Gain4' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  /* Product: '<S130>/Divide' incorporates:
   *  Constant: '<S130>/CAL_halfCircle_DEG2'
   *  Gain: '<S130>/Gain4'
   */
  rtb_CCW = rtb_Divide_e / (real32_T)(int16_T)((uint32_T)tmp *
    CAL_halfCircle_DEG >> 9);

  /* Abs: '<S27>/Abs' */
  rtb_Divide_e = (real32_T)fabs(rtb_CCW);

  /* Switch: '<S142>/Init' incorporates:
   *  Constant: '<S142>/Initial Condition'
   *  Logic: '<S142>/FixPt Logical Operator'
   *  UnitDelay: '<S142>/FixPt Unit Delay1'
   *  UnitDelay: '<S142>/FixPt Unit Delay2'
   *  UnitDelay: '<S27>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_j != 0)) {
    rtb_Init_j = 0.0F;
  } else {
    rtb_Init_j = RobotControl_DW.FixPtUnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S142>/Init' */

  /* Sum: '<S137>/Add' */
  rtb_Add_f = rtb_CCW + rtb_Init_j;

  /* Switch: '<S141>/Init' incorporates:
   *  Constant: '<S141>/Initial Condition'
   *  Logic: '<S141>/FixPt Logical Operator'
   *  UnitDelay: '<S141>/FixPt Unit Delay1'
   *  UnitDelay: '<S141>/FixPt Unit Delay2'
   *  UnitDelay: '<S27>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_jc != 0)) {
    rtb_Init_n = 0.0F;
  } else {
    rtb_Init_n = RobotControl_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S141>/Init' */

  /* Sum: '<S137>/Add2' */
  rtb_Add2_f = rtb_CCW - rtb_Init_n;

  /* Switch: '<S141>/Reset' incorporates:
   *  Constant: '<S137>/CONST_EnableDelay1'
   *  Switch: '<S139>/Enable'
   *  Switch: '<S140>/Enable'
   *  Switch: '<S142>/Reset'
   *  UnitDelay: '<S27>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o) {
    /* Update for UnitDelay: '<S141>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S141>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = 0.0F;

    /* Update for UnitDelay: '<S142>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S142>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = 0.0F;
  } else if (CONST_EnableDelay) {
    /* Switch: '<S139>/Enable' incorporates:
     *  Update for UnitDelay: '<S141>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Add2_f;

    /* Switch: '<S140>/Enable' incorporates:
     *  Update for UnitDelay: '<S142>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Add_f;
  } else {
    /* Update for UnitDelay: '<S141>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S139>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Init_n;

    /* Update for UnitDelay: '<S142>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S140>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Init_j;
  }

  /* End of Switch: '<S141>/Reset' */

  /* Sum: '<S138>/Add' incorporates:
   *  Gain: '<S137>/Kd'
   *  Gain: '<S137>/Ki'
   *  Gain: '<S137>/Kp'
   *  Sum: '<S137>/Add1'
   *  UnitDelay: '<S130>/Unit Delay'
   */
  rtb_CCW = ((CAL_Kd * rtb_Add2_f + CAL_Kp * rtb_CCW) + CAL_Ki * rtb_Add_f) -
    RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S138>/Constant'
   *  MinMax: '<S138>/MinMax1'
   *  RelationalOperator: '<S138>/Relational Operator'
   */
  if (rtb_CCW > 0.0F) {
    /* MinMax: '<S138>/MinMax' */
    if (2.5F <= rtb_CCW) {
      rtb_CCW = 2.5F;
    }

    /* End of MinMax: '<S138>/MinMax' */
  } else {
    if (!((rtb_CCW >= RobotControl_ConstB.Gain) || rtIsNaNF
          (RobotControl_ConstB.Gain))) {
      /* MinMax: '<S138>/MinMax1' */
      rtb_CCW = RobotControl_ConstB.Gain;
    }
  }

  /* End of Switch: '<S138>/Switch' */

  /* Sum: '<S138>/Add2' incorporates:
   *  UnitDelay: '<S130>/Unit Delay'
   */
  rtb_CCW += RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S134>/CONST_ZERO_F32'
   *  Constant: '<S134>/ENU_CCW'
   *  RelationalOperator: '<S134>/Relational_Operator'
   *  Switch: '<S134>/Switch1'
   *  UnitDelay: '<S27>/Unit_Delay3'
   *  UnitDelay: '<S27>/Unit_Delay4'
   */
  if (RobotControl_DW.Unit_Delay3_DSTATE_c) {
    RobotControl_B.turnRequestFiltered = RobotControl_B.turnRequest;
  } else if (RobotControl_DW.Unit_Delay4_DSTATE > CONST_ZERO_F32) {
    /* Switch: '<S134>/Switch1' incorporates:
     *  Constant: '<S134>/ENU_CW'
     */
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CW);
  } else {
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CCW);
  }

  /* End of Switch: '<S134>/Switch' */

  /* RelationalOperator: '<S131>/Relational_Operator2' incorporates:
   *  Constant: '<S131>/ENU_FORWARD4'
   */
  rtb_Relational_Operator_e4 = (RobotControl_B.turnRequestFiltered == ((uint8_T)
    ENU_FORWARD));

  /* RelationalOperator: '<S131>/Relational_Operator3' incorporates:
   *  Constant: '<S131>/ENU_BACKWARD3'
   */
  zcEvent_idx_1 = (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_BACKWARD));

  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S131>/ENU_BACKWARD'
   *  Constant: '<S131>/ENU_CCW'
   *  Constant: '<S131>/ENU_CW'
   *  Constant: '<S131>/ENU_FORWARD'
   *  Constant: '<S131>/ENU_STOP'
   *  RelationalOperator: '<S131>/Relational_Operator'
   *  RelationalOperator: '<S131>/Relational_Operator1'
   *  Switch: '<S131>/Switch'
   *  Switch: '<S131>/Switch1'
   *  Switch: '<S131>/Switch2'
   *  Switch: '<S131>/Switch3'
   */
  if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CCW)) {
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_FORWARD);
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_BACKWARD);
  } else if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CW)) {
    /* Switch: '<S131>/Switch1' incorporates:
     *  Constant: '<S131>/ENU_BACKWARD1'
     */
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_BACKWARD);

    /* Switch: '<S131>/Switch1' incorporates:
     *  Constant: '<S131>/ENU_FORWARD1'
     */
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_FORWARD);
  } else if (rtb_Relational_Operator_e4) {
    /* Switch: '<S131>/Switch2' incorporates:
     *  Constant: '<S131>/ENU_FORWARD3'
     *  Switch: '<S131>/Switch1'
     */
    RobotControl_B.rightMotorRequest = ((uint8_T)ENU_FORWARD);

    /* Switch: '<S131>/Switch2' incorporates:
     *  Constant: '<S131>/ENU_FORWARD2'
     *  Switch: '<S131>/Switch1'
     */
    RobotControl_B.leftMotorRequest = ((uint8_T)ENU_FORWARD);
  } else {
    if (zcEvent_idx_1) {
      /* Switch: '<S131>/Switch3' incorporates:
       *  Constant: '<S131>/ENU_BACKWARD4'
       *  Switch: '<S131>/Switch1'
       *  Switch: '<S131>/Switch2'
       */
      RobotControl_B.rightMotorRequest = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.rightMotorRequest = ((uint8_T)ENU_STOP);
    }

    /* Switch: '<S131>/Switch3' incorporates:
     *  Constant: '<S131>/ENU_BACKWARD2'
     *  Constant: '<S131>/ENU_STOP'
     *  Constant: '<S131>/ENU_STOP1'
     *  Switch: '<S131>/Switch1'
     *  Switch: '<S131>/Switch2'
     *  Switch: '<S131>/Switch3'
     */
    if (zcEvent_idx_1) {
      RobotControl_B.leftMotorRequest = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.leftMotorRequest = ((uint8_T)ENU_STOP);
    }

    /* End of Switch: '<S131>/Switch3' */
  }

  /* End of Switch: '<S131>/Switch' */

  /* Chart: '<S133>/TargetReachedConfirmTime' */
  /* Gateway: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* During: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* time needed to confirm steady state for the PID */
  /* Entry Internal: MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* Transition: '<S144>:2' */
  if (rtb_Divide_e <= RobotCo_CAL_ALLOWED_ERROR_VALUE) {
    /* Transition: '<S144>:4' */
    /* Transition: '<S144>:6' */
    RobotControl_DW.counter_j++;
    if (RobotControl_DW.counter_j > (int16_T)Robo_CONST_TARGET_REACHED_TIMER) {
      /* Transition: '<S144>:15' */
      /* Transition: '<S144>:16' */
      RobotControl_DW.counter_j = 0U;
      RobotControl_B.targetReached = true;

      /* Transition: '<S144>:21' */
    } else {
      /* Transition: '<S144>:8' */
    }

    /* Transition: '<S144>:14' */
  } else {
    /* Transition: '<S144>:9' */
    RobotControl_DW.counter_j = 0U;
    RobotControl_B.targetReached = false;
  }

  /* End of Chart: '<S133>/TargetReachedConfirmTime' */

  /* SignalConversion: '<S27>/OutportBufferFortargetReached' */
  RobotControl_B.OutportBufferFortargetReached = RobotControl_B.targetReached;

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/CAL_NO_ERROR'
   *  Constant: '<S27>/ENU_BACKWARD'
   *  Constant: '<S27>/ENU_FORWARD'
   *  Constant: '<S27>/ENU_SHIFT_HEADING'
   *  Constant: '<S27>/ENU_STOP'
   *  Constant: '<S27>/ENU_TEST_INIT'
   *  Logic: '<S27>/Logical Operator'
   *  Logic: '<S27>/Logical Operator1'
   *  Logic: '<S27>/Logical_Operator'
   *  RelationalOperator: '<S27>/Relational_Operator1'
   *  RelationalOperator: '<S27>/Relational_Operator2'
   *  RelationalOperator: '<S27>/Relational_Operator3'
   *  RelationalOperator: '<S27>/Relational_Operator4'
   *  RelationalOperator: '<S27>/Relational_Operator6'
   *  Switch: '<S27>/Switch1'
   */
  if ((RobotControl_B.turnRequest == ((uint8_T)ENU_STOP)) &&
      (RobotControl_B.comTstStatus != ((uint8_T)ENU_TEST_INIT)) &&
      (RobotControl_B.currentRoutine != ((uint8_T)ENU_SHIFT_HEADING))) {
    RobotControl_B.thetaError = ((uint8_T)CAL_NO_ERROR);
  } else if ((RobotControl_B.turnRequest == ((uint8_T)ENU_FORWARD)) ||
             (RobotControl_B.turnRequest == ((uint8_T)ENU_BACKWARD))) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/CAL_NO_ERROR1'
     */
    RobotControl_B.thetaError = ((uint8_T)CAL_NO_ERROR);
  } else {
    RobotControl_B.thetaError = rtb_CCW;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for UnitDelay: '<S27>/Unit_Delay5' */
  RobotControl_DW.Unit_Delay5_DSTATE_n = RobotControl_B.turnRequest;

  /* Update for UnitDelay: '<S27>/Unit_Delay1' */
  RobotControl_DW.Unit_Delay1_DSTATE_p = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S27>/Unit_Delay2' */
  RobotControl_DW.Unit_Delay2_DSTATE_o = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S142>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S142>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S141>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S141>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 0U;

  /* Update for UnitDelay: '<S130>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE = rtb_CCW;

  /* Update for UnitDelay: '<S27>/Unit_Delay3' */
  RobotControl_DW.Unit_Delay3_DSTATE_c = RobotControl_B.targetReached;

  /* Update for UnitDelay: '<S27>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = RobotControl_B.thetaError;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
