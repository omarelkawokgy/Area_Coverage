/*
 * File: MovementHandler.c
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

#include "MovementHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S148>/singleStepCalc' */
#define RobotCont_IN_NO_ACTIVE_CHILD_ay ((uint8_T)0U)
#define RobotContr_IN_waitingSwitchLane ((uint8_T)4U)
#define RobotControl_CAL_BLOCK_SIZE_mm (250U)
#define RobotControl_IN_ForwardStep    ((uint8_T)1U)
#define RobotControl_IN_SwitchLaneStep ((uint8_T)2U)
#define RobotControl_IN_initiateDist   ((uint8_T)3U)

/* Named constants for Chart: '<S145>/HighLevelMoves' */
#define RobotCont_CONST_MOVE_STABLE_CNT ((uint8_T)5U)
#define RobotContro_CONST_UTURN_CNT_THD ((uint8_T)2U)
#define RobotControl_CAL_thetaGain     ((uint8_T)100U)
#define RobotControl_ENU_FINISHED_f    ((uint8_T)4U)
#define RobotControl_IN_Idle           ((uint8_T)1U)
#define RobotControl_IN_Stop_n         ((uint8_T)1U)
#define RobotControl_IN_TurnLeft       ((uint8_T)2U)
#define RobotControl_IN_TurnLeft_d     ((uint8_T)1U)
#define RobotControl_IN_TurnRight      ((uint8_T)3U)
#define RobotControl_IN_TurnRight_h    ((uint8_T)1U)
#define RobotControl_IN_Uturn          ((uint8_T)4U)
#define RobotControl_IN_UturnLeft      ((uint8_T)5U)
#define RobotControl_IN_UturnRight     ((uint8_T)6U)
#define RobotControl_IN_backward       ((uint8_T)7U)
#define RobotControl_IN_finish         ((uint8_T)1U)
#define RobotControl_IN_finish_g       ((uint8_T)2U)
#define RobotControl_IN_fixingHeading  ((uint8_T)2U)
#define RobotControl_IN_forward        ((uint8_T)8U)
#define RobotControl_IN_forwardStep    ((uint8_T)3U)
#define RobotControl_IN_init_b         ((uint8_T)9U)
#define RobotControl_IN_start          ((uint8_T)2U)
#define RobotControl_IN_turning        ((uint8_T)3U)
#define RobotControl_event_refreshEvent (0L)
#define RobotControl_event_stopEvent   (1L)

/* Named constants for Chart: '<S146>/TargetReachedConfirmTime' */
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
static void Robo_chartstep_c37_RobotControl(const real32_T
  *DataTypeConversion1_n, const boolean_T *Unit_Delay1);

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_Stop(void)
{
  /* During 'Stop': '<S156>:37' */
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      RobotControl_DW.turnActive) {
    /* Constant: '<S145>/ENU_FORWARD' incorporates:
     *  Constant: '<S145>/ENU_BACKWARD'
     *  Constant: '<S145>/ENU_MOVE_TURN_LEFT'
     *  Constant: '<S145>/ENU_MOVE_TURN_RIGHT'
     *  Constant: '<S145>/ENU_MOVE_U_TURN'
     *  Constant: '<S145>/ENU_MOVE_U_TURN_LEFT'
     *  Constant: '<S145>/ENU_MOVE_U_TURN_RIGHT'
     *  Constant: '<S145>/ENU_STOP'
     */
    /* Transition: '<S156>:38' */
    /* previous turn not completed */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S156>:8' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Constant: '<S145>/ENU_BACKWARD' */
      /* Transition: '<S156>:11' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Constant: '<S145>/ENU_STOP' */
      /* Transition: '<S156>:39' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else {
      if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
        /* Transition: '<S156>:229' */
        RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

        /* Entry Internal 'TurnLeft': '<S156>:230' */
        /* Transition: '<S156>:231' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

        /* Constant: '<S145>/ENU_CCW' */
        /* Entry 'start': '<S156>:239' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      }
    }

    /* End of Constant: '<S145>/ENU_FORWARD' */
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_TurnLeft(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'TurnLeft': '<S156>:230' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S156>:240' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S156>:8' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S156>:11' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S156>:39' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S156>:229' */
      /* Exit Internal 'TurnLeft': '<S156>:230' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S156>:230' */
      /* Transition: '<S156>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:239' */
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
      /* During 'finish': '<S156>:237' */
      break;

     case RobotControl_IN_start:
      /* During 'start': '<S156>:239' */
      if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_NORTH) {
        /* Transition: '<S156>:232' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_EAST) {
        /* Transition: '<S156>:236' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else if (RobotControl_B.currentHeading == (uint16_T)
                 RobotControl_B.ROB_SOUTH) {
        /* Transition: '<S156>:233' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
        RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
      } else {
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_WEST)
        {
          /* Transition: '<S156>:235' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnLeft = RobotControl_IN_turning;
        }
      }
      break;

     default:
      /* During 'turning': '<S156>:238' */
      if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
          (*Unit_Delay1)) {
        /* Transition: '<S156>:234' */
        RobotControl_DW.is_TurnLeft = RobotControl_IN_finish;

        /* Entry 'finish': '<S156>:237' */
        RobotControl_DW.turnActive = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_Uturn(const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'Uturn': '<S156>:30' */
  guard1 = false;
  if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) ||
      (!RobotControl_DW.turnActive)) {
    /* Transition: '<S156>:34' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S156>:8' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S156>:11' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S156>:39' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S156>:229' */
      /* Exit Internal 'Uturn': '<S156>:30' */
      /* Exit Internal 'TurnRight': '<S156>:186' */
      RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S156>:230' */
      /* Transition: '<S156>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:239' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (RobotControl_DW.is_Uturn == RobotControl_IN_TurnRight_h) {
      /* During 'TurnRight': '<S156>:186' */
      if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD) {
        /* Transition: '<S156>:246' */
        /* Exit Internal 'TurnRight': '<S156>:186' */
        RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
        RobotControl_DW.is_Uturn = RobotControl_IN_finish_g;

        /* Entry 'finish': '<S156>:175' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S156>:194' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S156>:195' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S156>:192' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S156>:188' */
            /* headingRequest = ROB_EAST; */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S156>:191' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S156>:189' */
              /* headingRequest = ROB_WEST; */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
              RobotControl_DW.is_TurnRight = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S156>:193' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S156>:190' */
            RobotControl_DW.is_TurnRight = RobotControl_IN_finish;

            /* Entry 'finish': '<S156>:194' */
            RobotControl_DW.uTurnCounter++;
            RobotControl_DW.turnActive = false;
          }
          break;
        }
      }
    } else {
      /* During 'finish': '<S156>:175' */
    }
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_UturnLeft(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnLeft': '<S156>:28' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S156>:36' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S156>:8' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S156>:11' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S156>:39' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S156>:229' */
      /* Exit Internal 'UturnLeft': '<S156>:28' */
      /* Exit Internal 'TurnLeft': '<S156>:79' */
      RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S156>:230' */
      /* Transition: '<S156>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:239' */
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
     case RobotControl_IN_TurnLeft_d:
      /* During 'TurnLeft': '<S156>:79' */
      if ((RobotControl_DW.uTurnCounter == 1) &&
          (RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start)) {
        /* Transition: '<S156>:115' */
        /* Exit Internal 'TurnLeft': '<S156>:79' */
        RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_forwardStep;

        /* Constant: '<S145>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S156>:113' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S156>:114' */
        /* Exit Internal 'TurnLeft': '<S156>:79' */
        RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
        RobotControl_DW.is_UturnLeft = RobotControl_IN_finish_g;

        /* Entry 'finish': '<S156>:112' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnLeft_c) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S156>:89' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S156>:90' */
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_NORTH) {
            /* Transition: '<S156>:82' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnLeft_c = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_EAST) {
            /* Transition: '<S156>:88' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnLeft_c = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S156>:84' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnLeft_c = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_WEST) {
              /* Transition: '<S156>:86' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
              RobotControl_DW.is_TurnLeft_c = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S156>:185' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S156>:81' */
            RobotControl_DW.is_TurnLeft_c = RobotControl_IN_finish;

            /* Entry 'finish': '<S156>:89' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_g:
      /* During 'finish': '<S156>:112' */
      break;

     default:
      /* During 'forwardStep': '<S156>:113' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S156>:116' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

        /* Entry Internal 'TurnLeft': '<S156>:79' */
        /* Transition: '<S156>:80' */
        RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

        /* Constant: '<S145>/ENU_CCW' */
        /* Entry 'start': '<S156>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_h == RobotControl_event_stopEvent) {
        /* Transition: '<S156>:302' */
        RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

        /* Entry Internal 'TurnLeft': '<S156>:79' */
        /* Transition: '<S156>:80' */
        RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

        /* Constant: '<S145>/ENU_CCW' */
        /* Entry 'start': '<S156>:90' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_UturnRight(const real32_T *DataTypeConversion1_n, const
  boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;

  /* During 'UturnRight': '<S156>:29' */
  /* [hasChanged(moveRequest) ...||  */
  guard1 = false;
  if (!RobotControl_DW.turnActive) {
    /* Transition: '<S156>:32' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Transition: '<S156>:8' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_FORWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S156>:11' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S156>:39' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S156>:229' */
      /* Exit Internal 'UturnRight': '<S156>:29' */
      /* Exit Internal 'TurnRight': '<S156>:95' */
      RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S156>:230' */
      /* Transition: '<S156>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:239' */
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
     case RobotControl_IN_TurnRight_h:
      /* During 'TurnRight': '<S156>:95' */
      if ((RobotControl_DW.uTurnCounter_prev !=
           RobotControl_DW.uTurnCounter_start) && (RobotControl_DW.uTurnCounter ==
           1)) {
        /* Transition: '<S156>:124' */
        /* Exit Internal 'TurnRight': '<S156>:95' */
        RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
        RobotControl_DW.is_UturnRight = RobotControl_IN_forwardStep;

        /* Constant: '<S145>/ENU_FORWARD' */
        /* Entry 'forwardStep': '<S156>:125' */
        /* counter = 0; */
        RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      } else if (RobotControl_DW.uTurnCounter == RobotContro_CONST_UTURN_CNT_THD)
      {
        /* Transition: '<S156>:123' */
        /* Exit Internal 'TurnRight': '<S156>:95' */
        RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
        RobotControl_DW.is_UturnRight = RobotControl_IN_finish_g;

        /* Entry 'finish': '<S156>:120' */
        RobotControl_DW.turnActive = false;
      } else {
        switch (RobotControl_DW.is_TurnRight_i) {
         case RobotControl_IN_finish:
          /* During 'finish': '<S156>:242' */
          break;

         case RobotControl_IN_start:
          /* During 'start': '<S156>:106' */
          if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
          {
            /* Transition: '<S156>:104' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
            RobotControl_DW.is_TurnRight_i = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_NORTH) {
            /* Transition: '<S156>:98' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
            RobotControl_DW.is_TurnRight_i = RobotControl_IN_turning;
          } else if (RobotControl_B.currentHeading == (uint16_T)
                     RobotControl_B.ROB_WEST) {
            /* Transition: '<S156>:102' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
            RobotControl_DW.is_TurnRight_i = RobotControl_IN_turning;
          } else {
            if (RobotControl_B.currentHeading == (uint16_T)
                RobotControl_B.ROB_SOUTH) {
              /* Transition: '<S156>:100' */
              RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
              RobotControl_DW.is_TurnRight_i = RobotControl_IN_turning;
            }
          }
          break;

         default:
          /* During 'turning': '<S156>:183' */
          if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
              (*Unit_Delay1)) {
            /* Transition: '<S156>:243' */
            RobotControl_DW.is_TurnRight_i = RobotControl_IN_finish;

            /* Entry 'finish': '<S156>:242' */
            RobotControl_DW.uTurnCounter++;
          }
          break;
        }
      }
      break;

     case RobotControl_IN_finish_g:
      /* During 'finish': '<S156>:120' */
      break;

     default:
      /* During 'forwardStep': '<S156>:125' */
      if ((RobotControl_DW.completeStep_prev !=
           RobotControl_DW.completeStep_start) && (*DataTypeConversion1_n ==
           1.0F)) {
        /* Transition: '<S156>:122' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

        /* Entry Internal 'TurnRight': '<S156>:95' */
        /* Transition: '<S156>:96' */
        RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

        /* Constant: '<S145>/ENU_CW' */
        /* Entry 'start': '<S156>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else if (RobotControl_DW.sfEvent_h == RobotControl_event_stopEvent) {
        /* Transition: '<S156>:303' */
        RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

        /* Entry Internal 'TurnRight': '<S156>:95' */
        /* Transition: '<S156>:96' */
        RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

        /* Constant: '<S145>/ENU_CW' */
        /* Entry 'start': '<S156>:106' */
        RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
        RobotControl_DW.turnActive = true;
      } else {
        /* counter++; */
      }
      break;
    }
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void RobotControl_forward(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* During 'forward': '<S156>:4' */
  guard1 = false;
  guard2 = false;
  if (RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start) {
    /* Transition: '<S156>:10' */
    if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
      /* Constant: '<S145>/ENU_FORWARD' */
      /* Transition: '<S156>:8' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

      /* Entry Internal 'forward': '<S156>:4' */
      /* Transition: '<S156>:248' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
      /* Transition: '<S156>:11' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_BACKWARD' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT)) {
      /* Transition: '<S156>:31' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

      /* Entry 'UturnRight': '<S156>:29' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnRight': '<S156>:29' */
      /* Transition: '<S156>:118' */
      RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:95' */
      /* Transition: '<S156>:96' */
      RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:106' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
      /* Transition: '<S156>:33' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

      /* Entry 'Uturn': '<S156>:30' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'Uturn': '<S156>:30' */
      /* Transition: '<S156>:142' */
      RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

      /* Entry Internal 'TurnRight': '<S156>:186' */
      /* Transition: '<S156>:187' */
      RobotControl_DW.is_TurnRight = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:195' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT)) {
      /* Transition: '<S156>:35' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

      /* Entry 'UturnLeft': '<S156>:28' */
      RobotControl_DW.uTurnCounter = 0U;

      /* Entry Internal 'UturnLeft': '<S156>:28' */
      /* Transition: '<S156>:111' */
      RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

      /* Entry Internal 'TurnLeft': '<S156>:79' */
      /* Transition: '<S156>:80' */
      RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:90' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
      /* Transition: '<S156>:39' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;

      /* Constant: '<S145>/ENU_STOP' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

      /* Constant: '<S145>/ENU_ROB_NONE' */
      /* Entry Internal 'Stop': '<S156>:37' */
      /* Transition: '<S156>:309' */
      if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
           RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
           ENU_ROB_NONE)) {
        /* Transition: '<S156>:314' */
        /* Transition: '<S156>:316' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

        /* Transition: '<S156>:336' */
      } else {
        /* Transition: '<S156>:335' */
      }

      /* End of Constant: '<S145>/ENU_ROB_NONE' */
      /* Transition: '<S156>:333' */
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT)) {
      /* Transition: '<S156>:227' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

      /* Entry Internal 'TurnRight': '<S156>:217' */
      /* Transition: '<S156>:218' */
      RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CW' */
      /* Entry 'start': '<S156>:226' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
      RobotControl_DW.turnActive = true;
    } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
      /* Transition: '<S156>:229' */
      /* Exit Internal 'forward': '<S156>:4' */
      RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
      RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

      /* Entry Internal 'TurnLeft': '<S156>:230' */
      /* Transition: '<S156>:231' */
      RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

      /* Constant: '<S145>/ENU_CCW' */
      /* Entry 'start': '<S156>:239' */
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
      /* During 'Idle': '<S156>:247' */
      /* Transition: '<S156>:271' */
      if (!((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
             RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
            RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)))
      {
        /* Transition: '<S156>:251' */
        if (RobotControl_B.headingRequest == (uint16_T)RobotControl_B.ROB_NORTH)
        {
          /* Transition: '<S156>:256' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S145>/ENU_CCW' */
            /* Transition: '<S156>:261' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S145>/ENU_CW' */
            /* Transition: '<S156>:263' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_SOUTH) {
          /* Transition: '<S156>:257' */
          if ((RobotControl_B.theta_mDeg < RobotControl_B.ROB_SOUTH *
               RobotControl_CAL_thetaGain) || (RobotControl_B.theta_mDeg >
               RobotControl_B.ROB_NORTH * RobotControl_CAL_thetaGain)) {
            /* Constant: '<S145>/ENU_CW' */
            /* Transition: '<S156>:264' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S145>/ENU_CCW' */
            /* Transition: '<S156>:265' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_EAST) {
          /* Transition: '<S156>:258' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S145>/ENU_CW' */
            /* Transition: '<S156>:266' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S145>/ENU_CCW' */
            /* Transition: '<S156>:267' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          }
        } else if (RobotControl_B.headingRequest == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S156>:259' */
          if (RobotControl_B.theta_mDeg > RobotControl_B.ROB_WEST *
              RobotControl_CAL_thetaGain) {
            /* Constant: '<S145>/ENU_CCW' */
            /* Transition: '<S156>:268' */
            RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
            RobotControl_DW.is_forward = RobotControl_IN_fixingHeading;
          } else {
            /* Constant: '<S145>/ENU_CW' */
            /* Transition: '<S156>:269' */
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
      /* During 'fixingHeading': '<S156>:260' */
      /* Transition: '<S156>:273' */
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
      break;
    }
  }

  if (guard1) {
    if ((RobotControl_B.theta_mDeg >= RobotControl_B.headingRequest *
         RobotControl_CAL_thetaGain - 500U) && (RobotControl_B.theta_mDeg <=
         RobotControl_B.headingRequest * RobotControl_CAL_thetaGain + 500U)) {
      /* Constant: '<S145>/ENU_FORWARD' */
      /* Transition: '<S156>:272' */
      RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
      RobotControl_DW.is_forward = RobotControl_IN_Idle;
    }
  }
}

/* Function for Chart: '<S145>/HighLevelMoves' */
static void Robo_chartstep_c37_RobotControl(const real32_T
  *DataTypeConversion1_n, const boolean_T *Unit_Delay1)
{
  boolean_T guard1 = false;
  RobotControl_DW.uTurnCounter_prev = RobotControl_DW.uTurnCounter_start;
  RobotControl_DW.uTurnCounter_start = RobotControl_DW.uTurnCounter;
  RobotControl_DW.completeStep_prev = RobotControl_DW.completeStep_start;
  RobotControl_DW.completeStep_start = *DataTypeConversion1_n;
  RobotControl_DW.moveRequest_prev = RobotControl_DW.moveRequest_start;
  RobotControl_DW.moveRequest_start = RobotControl_B.moveRequest;

  /* During: RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves */
  /* movement state machine handles all the movement in slightly higher level. turn left , right, stop, forward, backward and also combinations like u-turn left u-turn right */
  if (RobotControl_DW.is_active_c37_RobotControl == 0U) {
    RobotControl_DW.completeStep_prev = *DataTypeConversion1_n;
    RobotControl_DW.moveRequest_prev = RobotControl_B.moveRequest;

    /* Entry: RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves */
    RobotControl_DW.is_active_c37_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves */
    /* Transition: '<S156>:3' */
    RobotControl_DW.is_c37_RobotControl = RobotControl_IN_init_b;

    /* Entry 'init': '<S156>:295' */
    RobotControl_DW.stableCounter = 0U;

    /* Constant: '<S145>/ENU_STOP' */
    RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);

    /* Constant: '<S145>/ENU_ROB_NONE' */
    RobotControl_B.headingRequest = ENU_ROB_NONE;
  } else {
    guard1 = false;
    switch (RobotControl_DW.is_c37_RobotControl) {
     case RobotControl_IN_Stop_n:
      RobotControl_Stop();
      break;

     case RobotControl_IN_TurnLeft:
      RobotControl_TurnLeft(Unit_Delay1);
      break;

     case RobotControl_IN_TurnRight:
      /* During 'TurnRight': '<S156>:217' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Transition: '<S156>:228' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S156>:8' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;

          /* Constant: '<S145>/ENU_FORWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S156>:4' */
          /* Transition: '<S156>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Transition: '<S156>:11' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;

          /* Constant: '<S145>/ENU_BACKWARD' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S156>:31' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S156>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S156>:29' */
          /* Transition: '<S156>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

          /* Entry Internal 'TurnRight': '<S156>:95' */
          /* Transition: '<S156>:96' */
          RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S156>:33' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S156>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S156>:30' */
          /* Transition: '<S156>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

          /* Entry Internal 'TurnRight': '<S156>:186' */
          /* Transition: '<S156>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S156>:35' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S156>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S156>:28' */
          /* Transition: '<S156>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

          /* Entry Internal 'TurnLeft': '<S156>:79' */
          /* Transition: '<S156>:80' */
          RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CCW' */
          /* Entry 'start': '<S156>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Transition: '<S156>:39' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;

          /* Constant: '<S145>/ENU_STOP' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

          /* Constant: '<S145>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S156>:37' */
          /* Transition: '<S156>:309' */
          if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
               RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S156>:314' */
            /* Transition: '<S156>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S156>:336' */
          } else {
            /* Transition: '<S156>:335' */
          }

          /* Transition: '<S156>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S156>:227' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S156>:217' */
          /* Transition: '<S156>:218' */
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT))
        {
          /* Transition: '<S156>:229' */
          /* Exit Internal 'TurnRight': '<S156>:217' */
          RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

          /* Entry Internal 'TurnLeft': '<S156>:230' */
          /* Transition: '<S156>:231' */
          RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CCW' */
          /* Entry 'start': '<S156>:239' */
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
      /* During 'backward': '<S156>:5' */
      if ((RobotControl_DW.moveRequest_prev != RobotControl_DW.moveRequest_start)
          || (!RobotControl_DW.turnActive)) {
        /* Constant: '<S145>/ENU_FORWARD' incorporates:
         *  Constant: '<S145>/ENU_BACKWARD'
         *  Constant: '<S145>/ENU_MOVE_TURN_LEFT'
         *  Constant: '<S145>/ENU_MOVE_TURN_RIGHT'
         *  Constant: '<S145>/ENU_MOVE_U_TURN'
         *  Constant: '<S145>/ENU_MOVE_U_TURN_LEFT'
         *  Constant: '<S145>/ENU_MOVE_U_TURN_RIGHT'
         *  Constant: '<S145>/ENU_STOP'
         */
        /* Transition: '<S156>:12' */
        if (RobotControl_B.moveRequest == ((uint8_T)ENU_FORWARD)) {
          /* Transition: '<S156>:8' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_FORWARD);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_forward;

          /* Entry Internal 'forward': '<S156>:4' */
          /* Transition: '<S156>:248' */
          RobotControl_DW.is_forward = RobotControl_IN_Idle;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_BACKWARD)) {
          /* Constant: '<S145>/ENU_BACKWARD' */
          /* Transition: '<S156>:11' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_BACKWARD);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_backward;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_RIGHT))
        {
          /* Transition: '<S156>:31' */
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnRight;

          /* Entry 'UturnRight': '<S156>:29' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnRight': '<S156>:29' */
          /* Transition: '<S156>:118' */
          RobotControl_DW.is_UturnRight = RobotControl_IN_TurnRight_h;

          /* Entry Internal 'TurnRight': '<S156>:95' */
          /* Transition: '<S156>:96' */
          RobotControl_DW.is_TurnRight_i = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:106' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN)) {
          /* Transition: '<S156>:33' */
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Uturn;

          /* Entry 'Uturn': '<S156>:30' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'Uturn': '<S156>:30' */
          /* Transition: '<S156>:142' */
          RobotControl_DW.is_Uturn = RobotControl_IN_TurnRight_h;

          /* Entry Internal 'TurnRight': '<S156>:186' */
          /* Transition: '<S156>:187' */
          RobotControl_DW.is_TurnRight = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:195' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_U_TURN_LEFT))
        {
          /* Transition: '<S156>:35' */
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_UturnLeft;

          /* Entry 'UturnLeft': '<S156>:28' */
          RobotControl_DW.uTurnCounter = 0U;

          /* Entry Internal 'UturnLeft': '<S156>:28' */
          /* Transition: '<S156>:111' */
          RobotControl_DW.is_UturnLeft = RobotControl_IN_TurnLeft_d;

          /* Entry Internal 'TurnLeft': '<S156>:79' */
          /* Transition: '<S156>:80' */
          RobotControl_DW.is_TurnLeft_c = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CCW' */
          /* Entry 'start': '<S156>:90' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CCW);
          RobotControl_DW.turnActive = true;
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_STOP)) {
          /* Constant: '<S145>/ENU_STOP' */
          /* Transition: '<S156>:39' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_STOP);
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

          /* Constant: '<S145>/ENU_ROB_NONE' */
          /* Entry Internal 'Stop': '<S156>:37' */
          /* Transition: '<S156>:309' */
          if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
               RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
               ENU_ROB_NONE)) {
            /* Transition: '<S156>:314' */
            /* Transition: '<S156>:316' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

            /* Transition: '<S156>:336' */
          } else {
            /* Transition: '<S156>:335' */
          }

          /* Transition: '<S156>:333' */
        } else if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_RIGHT))
        {
          /* Transition: '<S156>:227' */
          RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnRight;

          /* Entry Internal 'TurnRight': '<S156>:217' */
          /* Transition: '<S156>:218' */
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_start;

          /* Constant: '<S145>/ENU_CW' */
          /* Entry 'start': '<S156>:226' */
          RobotControl_B.turnRequest = ((uint8_T)ENU_CW);
          RobotControl_DW.turnActive = true;
        } else {
          if (RobotControl_B.moveRequest == ((uint8_T)ENU_MOVE_TURN_LEFT)) {
            /* Transition: '<S156>:229' */
            RobotControl_DW.is_c37_RobotControl = RobotControl_IN_TurnLeft;

            /* Entry Internal 'TurnLeft': '<S156>:230' */
            /* Transition: '<S156>:231' */
            RobotControl_DW.is_TurnLeft = RobotControl_IN_start;

            /* Constant: '<S145>/ENU_CCW' */
            /* Entry 'start': '<S156>:239' */
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
      /* During 'init': '<S156>:295' */
      if (RobotControl_DW.stableCounter >= RobotCont_CONST_MOVE_STABLE_CNT) {
        /* Transition: '<S156>:297' */
        RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
        RobotControl_DW.is_c37_RobotControl = RobotControl_IN_Stop_n;

        /* Constant: '<S145>/ENU_ROB_NONE' */
        /* Entry Internal 'Stop': '<S156>:37' */
        /* Transition: '<S156>:309' */
        if ((RobotControl_B.VariantMergeForOutportangleCa_h ==
             RobotControl_ENU_FINISHED_f) && (RobotControl_B.currentHeading ==
             ENU_ROB_NONE)) {
          /* Transition: '<S156>:314' */
          /* Transition: '<S156>:316' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;

          /* Transition: '<S156>:336' */
        } else {
          /* Transition: '<S156>:335' */
        }

        /* Transition: '<S156>:333' */
      } else {
        RobotControl_DW.stableCounter++;
      }
      break;
    }

    if (guard1) {
      switch (RobotControl_DW.is_TurnRight_h) {
       case RobotControl_IN_finish:
        /* During 'finish': '<S156>:225' */
        break;

       case RobotControl_IN_start:
        /* During 'start': '<S156>:226' */
        if (RobotControl_B.currentHeading == (uint16_T)RobotControl_B.ROB_EAST)
        {
          /* Transition: '<S156>:223' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_SOUTH;
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_NORTH) {
          /* Transition: '<S156>:219' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_EAST;
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_turning;
        } else if (RobotControl_B.currentHeading == (uint16_T)
                   RobotControl_B.ROB_WEST) {
          /* Transition: '<S156>:222' */
          RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_NORTH;
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_turning;
        } else {
          if (RobotControl_B.currentHeading == (uint16_T)
              RobotControl_B.ROB_SOUTH) {
            /* Transition: '<S156>:220' */
            RobotControl_B.headingRequest = (uint16_T)RobotControl_B.ROB_WEST;
            RobotControl_DW.is_TurnRight_h = RobotControl_IN_turning;
          }
        }
        break;

       default:
        /* During 'turning': '<S156>:224' */
        if ((RobotControl_B.currentHeading == RobotControl_B.headingRequest) &&
            (*Unit_Delay1)) {
          /* Transition: '<S156>:221' */
          RobotControl_DW.is_TurnRight_h = RobotControl_IN_finish;

          /* Entry 'finish': '<S156>:225' */
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
  /* InitializeConditions for UnitDelay: '<S155>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S154>/FixPt Unit Delay2' */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 1U;

  /* InitializeConditions for UnitDelay: '<S28>/Unit_Delay4' */
  RobotControl_DW.Unit_Delay4_DSTATE = ((uint8_T)CAL_NO_ERROR);

  /* SystemInitialize for Chart: '<S148>/singleStepCalc' */
  RobotControl_DW.is_active_c36_RobotControl = 0U;
  RobotControl_DW.is_c36_RobotControl = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.tempDistance_mm = 0.0F;
  RobotControl_B.switchLaneStep = false;
  RobotControl_B.encoderStep = 0U;

  /* SystemInitialize for Chart: '<S145>/HighLevelMoves' */
  RobotControl_DW.is_TurnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_TurnRight_h = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_Uturn = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_TurnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_UturnLeft = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_TurnLeft_c = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_UturnRight = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_TurnRight_i = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_forward = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.is_active_c37_RobotControl = 0U;
  RobotControl_DW.is_c37_RobotControl = RobotCont_IN_NO_ACTIVE_CHILD_ay;
  RobotControl_DW.turnActive = false;
  RobotControl_DW.uTurnCounter = 0U;
  RobotControl_DW.stableCounter = 0U;
  RobotControl_B.turnRequest = 0U;
  RobotControl_B.headingRequest = 0U;
  RobotControl_DW.uTurnCounter_prev = RobotControl_DW.uTurnCounter;
  RobotControl_DW.uTurnCounter_start = RobotControl_DW.uTurnCounter;

  /* SystemInitialize for Chart: '<S146>/TargetReachedConfirmTime' */
  RobotControl_DW.counter_m = 0U;
  RobotControl_B.targetReached = false;
}

/* Output and update for function-call system: '<S22>/MovementHandler' */
void RobotControl_MovementHandler(void)
{
  boolean_T rtb_Relational_Operator_mf;
  real32_T rtb_Divide_e;
  int32_T rtb_headingRequest;
  real32_T rtb_Init;
  real32_T rtb_Init_f;
  real32_T rtb_Add2_f;
  real32_T rtb_Add_f;
  real32_T rtb_CCW;
  boolean_T zcEvent_idx_1;
  uint16_T tmp;

  /* RelationalOperator: '<S142>/Relational_Operator' incorporates:
   *  Constant: '<S142>/ENU_FORWARD'
   *  UnitDelay: '<S28>/Unit_Delay5'
   */
  rtb_Relational_Operator_mf = (RobotControl_DW.Unit_Delay5_DSTATE_n ==
    ((uint8_T)ENU_FORWARD));

  /* Product: '<S142>/Divide' incorporates:
   *  Constant: '<S142>/CONST_TWO_F32'
   *  Sum: '<S142>/Add'
   */
  rtb_Divide_e = (RobotControl_B.Data_Type_Conversion_m +
                  RobotControl_B.Data_Type_Conversion) / CONST_TWO_F32;

  /* Chart: '<S148>/singleStepCalc' */
  /* Gateway: RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* During: RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
  /* calculating single step the robot moves in straight line mainlt forward state. to it update the sensor view and also gives change lane step */
  if (RobotControl_DW.is_active_c36_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    RobotControl_DW.is_active_c36_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/MovementHandler/EcoderTicksCalc/EncoderHandler/singleStepCalc */
    /* Transition: '<S149>:39' */
    RobotControl_DW.is_c36_RobotControl = RobotContr_IN_waitingSwitchLane;
  } else {
    switch (RobotControl_DW.is_c36_RobotControl) {
     case RobotControl_IN_ForwardStep:
      /* During 'ForwardStep': '<S149>:57' */
      /* Transition: '<S149>:59' */
      RobotControl_DW.is_c36_RobotControl = RobotContr_IN_waitingSwitchLane;
      break;

     case RobotControl_IN_SwitchLaneStep:
      /* During 'SwitchLaneStep': '<S149>:42' */
      if (!RobotControl_B.OutportBufferForswitchLaneFlg_B) {
        /* Transition: '<S149>:44' */
        RobotControl_B.switchLaneStep = false;
        RobotControl_DW.is_c36_RobotControl = RobotContr_IN_waitingSwitchLane;
      }
      break;

     case RobotControl_IN_initiateDist:
      /* During 'initiateDist': '<S149>:40' */
      if (RobotControl_B.OutportBufferForswitchLaneFlg_B && (rtb_Divide_e -
           RobotControl_DW.tempDistance_mm >= RobotControl_CAL_BLOCK_SIZE_mm)) {
        /* Transition: '<S149>:43' */
        RobotControl_DW.is_c36_RobotControl = RobotControl_IN_SwitchLaneStep;

        /* Entry 'SwitchLaneStep': '<S149>:42' */
        RobotControl_B.switchLaneStep = true;
      } else if ((!RobotControl_B.OutportBufferForswitchLaneFlg_B) &&
                 (rtb_Divide_e - RobotControl_DW.tempDistance_mm >= 50.0F)) {
        /* Transition: '<S149>:58' */
        RobotControl_DW.is_c36_RobotControl = RobotControl_IN_ForwardStep;

        /* Entry 'ForwardStep': '<S149>:57' */
        RobotControl_B.encoderStep = 1U;
      } else {
        if (!rtb_Relational_Operator_mf) {
          /* Transition: '<S149>:61' */
          RobotControl_DW.is_c36_RobotControl = RobotContr_IN_waitingSwitchLane;
        }
      }
      break;

     default:
      /* During 'waitingSwitchLane': '<S149>:38' */
      if (rtb_Relational_Operator_mf) {
        /* Transition: '<S149>:41' */
        RobotControl_DW.is_c36_RobotControl = RobotControl_IN_initiateDist;

        /* Entry 'initiateDist': '<S149>:40' */
        RobotControl_DW.tempDistance_mm = rtb_Divide_e;
        RobotControl_B.encoderStep = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S148>/singleStepCalc' */

  /* DataTypeConversion: '<S145>/Data Type Conversion1' */
  rtb_Divide_e = RobotControl_B.switchLaneStep;

  /* Chart: '<S145>/HighLevelMoves' incorporates:
   *  TriggerPort: '<S156>/input events'
   */
  rtb_Relational_Operator_mf = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0]
    == POS_ZCSIG) != (int16_T)RobotControl_B.refreshEvent) &&
    (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] ==
                     POS_ZCSIG) != (int16_T)RobotControl_B.stopEvent) &&
                   (RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] !=
                    UNINITIALIZED_ZCSIG));
  if (rtb_Relational_Operator_mf || zcEvent_idx_1) {
    /* Gateway: RobotControl/RobotControlLib/MovementHandler/MoveMainStatemachine/HighLevelMoves */
    if ((int8_T)(rtb_Relational_Operator_mf ? RobotControl_B.refreshEvent ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S156>:300' */
      RobotControl_DW.sfEvent_h = RobotControl_event_refreshEvent;

      /* UnitDelay: '<S28>/Unit_Delay1' */
      Robo_chartstep_c37_RobotControl(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }

    if ((int8_T)(zcEvent_idx_1 ? RobotControl_B.stopEvent ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S156>:301' */
      RobotControl_DW.sfEvent_h = RobotControl_event_stopEvent;

      /* UnitDelay: '<S28>/Unit_Delay1' */
      Robo_chartstep_c37_RobotControl(&rtb_Divide_e,
        &RobotControl_DW.Unit_Delay1_DSTATE_p);
    }
  }

  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[0] = RobotControl_B.refreshEvent;
  RobotControl_PrevZCX.HighLevelMoves_Trig_ZCE[1] = RobotControl_B.stopEvent;

  /* Gain: '<S143>/Gain5' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  rtb_headingRequest = (int32_T)((uint32_T)tmp * RobotControl_B.headingRequest >>
    9);

  /* End of Gain: '<S143>/Gain5' */

  /* Sum: '<S143>/Subtract' */
  rtb_Divide_e = RobotControl_B.theta_mDeg - (real32_T)rtb_headingRequest;

  /* Switch: '<S143>/Switch' incorporates:
   *  Constant: '<S143>/CONST_ZERO_F32'
   *  Gain: '<S143>/Gain3'
   *  RelationalOperator: '<S143>/Relational_Operator1'
   */
  if (rtb_Divide_e < CONST_ZERO_F32) {
    /* Gain: '<S143>/Gain' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Sum: '<S143>/Subtract2' incorporates:
     *  Constant: '<S143>/CAL_fullCircle_DEG'
     *  Gain: '<S143>/Gain'
     *  Sum: '<S143>/Subtract1'
     */
    rtb_CCW = ((real32_T)((uint32_T)tmp * CAL_fullCircle_DEG >> 9) +
               RobotControl_B.theta_mDeg) - (real32_T)rtb_headingRequest;

    /* Gain: '<S143>/Gain1' */
    if (((uint8_T)CAL_thetaGain) > 127) {
      tmp = MAX_uint16_T;
    } else {
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S143>/Switch2' incorporates:
     *  Abs: '<S143>/Abs'
     *  Constant: '<S143>/CAL_halfCircle_DEG1'
     *  DataTypeConversion: '<S143>/Data_Type_Conversion1'
     *  Gain: '<S143>/Gain1'
     *  Gain: '<S143>/Gain8'
     *  RelationalOperator: '<S143>/Relational_Operator3'
     */
    if (rtb_CCW > (int16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      rtb_Divide_e = (real32_T)fabs(rtb_Divide_e);
    } else {
      rtb_Divide_e = (real32_T)CONST_NegOne * rtb_CCW;
    }

    /* End of Switch: '<S143>/Switch2' */
  } else {
    if (((uint8_T)CAL_thetaGain) > 127) {
      /* Gain: '<S143>/Gain3' */
      tmp = MAX_uint16_T;
    } else {
      /* Gain: '<S143>/Gain3' */
      tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
    }

    /* Switch: '<S143>/Switch1' incorporates:
     *  Abs: '<S143>/Abs1'
     *  Constant: '<S143>/CAL_fullCircle_DEG1'
     *  Constant: '<S143>/CAL_halfCircle_DEG'
     *  DataTypeConversion: '<S143>/Data_Type_Conversion'
     *  Gain: '<S143>/Gain2'
     *  Gain: '<S143>/Gain3'
     *  Gain: '<S143>/Gain7'
     *  RelationalOperator: '<S143>/Relational_Operator2'
     *  Sum: '<S143>/Subtract3'
     *  Sum: '<S143>/Subtract4'
     */
    if (rtb_Divide_e > (uint16_T)((uint32_T)tmp * CAL_halfCircle_DEG >> 9)) {
      /* Gain: '<S143>/Gain2' */
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

    /* End of Switch: '<S143>/Switch1' */
  }

  /* End of Switch: '<S143>/Switch' */

  /* Gain: '<S143>/Gain4' */
  if (((uint8_T)CAL_thetaGain) > 127) {
    tmp = MAX_uint16_T;
  } else {
    tmp = (uint16_T)((uint8_T)CAL_thetaGain) << 9;
  }

  /* Product: '<S143>/Divide' incorporates:
   *  Constant: '<S143>/CAL_halfCircle_DEG2'
   *  Gain: '<S143>/Gain4'
   */
  rtb_CCW = rtb_Divide_e / (real32_T)(int16_T)((uint32_T)tmp *
    CAL_halfCircle_DEG >> 9);

  /* Abs: '<S28>/Abs' */
  rtb_Divide_e = (real32_T)fabs(rtb_CCW);

  /* Switch: '<S155>/Init' incorporates:
   *  Constant: '<S155>/Initial Condition'
   *  Logic: '<S155>/FixPt Logical Operator'
   *  UnitDelay: '<S155>/FixPt Unit Delay1'
   *  UnitDelay: '<S155>/FixPt Unit Delay2'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_j != 0)) {
    rtb_Init = 0.0F;
  } else {
    rtb_Init = RobotControl_DW.FixPtUnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S155>/Init' */

  /* Sum: '<S150>/Add' */
  rtb_Add_f = rtb_CCW + rtb_Init;

  /* Switch: '<S154>/Init' incorporates:
   *  Constant: '<S154>/Initial Condition'
   *  Logic: '<S154>/FixPt Logical Operator'
   *  UnitDelay: '<S154>/FixPt Unit Delay1'
   *  UnitDelay: '<S154>/FixPt Unit Delay2'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o ||
      (RobotControl_DW.FixPtUnitDelay2_DSTATE_jc != 0)) {
    rtb_Init_f = 0.0F;
  } else {
    rtb_Init_f = RobotControl_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S154>/Init' */

  /* Sum: '<S150>/Add2' */
  rtb_Add2_f = rtb_CCW - rtb_Init_f;

  /* Switch: '<S154>/Reset' incorporates:
   *  Constant: '<S150>/CONST_EnableDelay1'
   *  Switch: '<S152>/Enable'
   *  Switch: '<S153>/Enable'
   *  Switch: '<S155>/Reset'
   *  UnitDelay: '<S28>/Unit_Delay2'
   */
  if (RobotControl_DW.Unit_Delay2_DSTATE_o) {
    /* Update for UnitDelay: '<S154>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S154>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = 0.0F;

    /* Update for UnitDelay: '<S155>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S155>/Initial Condition'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = 0.0F;
  } else if (CONST_EnableDelay) {
    /* Switch: '<S152>/Enable' incorporates:
     *  Update for UnitDelay: '<S154>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Add2_f;

    /* Switch: '<S153>/Enable' incorporates:
     *  Update for UnitDelay: '<S155>/FixPt Unit Delay1'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Add_f;
  } else {
    /* Update for UnitDelay: '<S154>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S152>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_p = rtb_Init_f;

    /* Update for UnitDelay: '<S155>/FixPt Unit Delay1' incorporates:
     *  Switch: '<S153>/Enable'
     */
    RobotControl_DW.FixPtUnitDelay1_DSTATE_l = rtb_Init;
  }

  /* End of Switch: '<S154>/Reset' */

  /* Sum: '<S151>/Add' incorporates:
   *  Gain: '<S150>/Kd'
   *  Gain: '<S150>/Ki'
   *  Gain: '<S150>/Kp'
   *  Sum: '<S150>/Add1'
   *  UnitDelay: '<S143>/Unit Delay'
   */
  rtb_CCW = ((CAL_Kd * rtb_Add2_f + CAL_Kp * rtb_CCW) + CAL_Ki * rtb_Add_f) -
    RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Constant'
   *  MinMax: '<S151>/MinMax1'
   *  RelationalOperator: '<S151>/Relational Operator'
   */
  if (rtb_CCW > 0.0F) {
    /* MinMax: '<S151>/MinMax' */
    if (2.5F <= rtb_CCW) {
      rtb_CCW = 2.5F;
    }

    /* End of MinMax: '<S151>/MinMax' */
  } else {
    if (!((rtb_CCW >= RobotControl_ConstB.Gain) || rtIsNaNF
          (RobotControl_ConstB.Gain))) {
      /* MinMax: '<S151>/MinMax1' */
      rtb_CCW = RobotControl_ConstB.Gain;
    }
  }

  /* End of Switch: '<S151>/Switch' */

  /* Sum: '<S151>/Add2' incorporates:
   *  UnitDelay: '<S143>/Unit Delay'
   */
  rtb_CCW += RobotControl_DW.UnitDelay_DSTATE;

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/CONST_ZERO_F32'
   *  Constant: '<S147>/ENU_CCW'
   *  RelationalOperator: '<S147>/Relational_Operator'
   *  Switch: '<S147>/Switch1'
   *  UnitDelay: '<S28>/Unit_Delay3'
   *  UnitDelay: '<S28>/Unit_Delay4'
   */
  if (RobotControl_DW.Unit_Delay3_DSTATE_c) {
    RobotControl_B.turnRequestFiltered = RobotControl_B.turnRequest;
  } else if (RobotControl_DW.Unit_Delay4_DSTATE > CONST_ZERO_F32) {
    /* Switch: '<S147>/Switch1' incorporates:
     *  Constant: '<S147>/ENU_CW'
     */
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CW);
  } else {
    RobotControl_B.turnRequestFiltered = ((uint8_T)ENU_CCW);
  }

  /* End of Switch: '<S147>/Switch' */

  /* RelationalOperator: '<S144>/Relational_Operator2' incorporates:
   *  Constant: '<S144>/ENU_FORWARD4'
   */
  rtb_Relational_Operator_mf = (RobotControl_B.turnRequestFiltered == ((uint8_T)
    ENU_FORWARD));

  /* RelationalOperator: '<S144>/Relational_Operator3' incorporates:
   *  Constant: '<S144>/ENU_BACKWARD3'
   */
  zcEvent_idx_1 = (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_BACKWARD));

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/ENU_BACKWARD'
   *  Constant: '<S144>/ENU_CCW'
   *  Constant: '<S144>/ENU_CW'
   *  Constant: '<S144>/ENU_FORWARD'
   *  Constant: '<S144>/ENU_STOP'
   *  RelationalOperator: '<S144>/Relational_Operator'
   *  RelationalOperator: '<S144>/Relational_Operator1'
   *  Switch: '<S144>/Switch'
   *  Switch: '<S144>/Switch1'
   *  Switch: '<S144>/Switch2'
   *  Switch: '<S144>/Switch3'
   */
  if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CCW)) {
    RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_FORWARD);
    RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_BACKWARD);
  } else if (RobotControl_B.turnRequestFiltered == ((uint8_T)ENU_CW)) {
    /* Switch: '<S144>/Switch1' incorporates:
     *  Constant: '<S144>/ENU_BACKWARD1'
     */
    RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_BACKWARD);

    /* Switch: '<S144>/Switch1' incorporates:
     *  Constant: '<S144>/ENU_FORWARD1'
     */
    RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_FORWARD);
  } else if (rtb_Relational_Operator_mf) {
    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S144>/ENU_FORWARD3'
     *  Switch: '<S144>/Switch1'
     */
    RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_FORWARD);

    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S144>/ENU_FORWARD2'
     *  Switch: '<S144>/Switch1'
     */
    RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_FORWARD);
  } else {
    if (zcEvent_idx_1) {
      /* Switch: '<S144>/Switch3' incorporates:
       *  Constant: '<S144>/ENU_BACKWARD4'
       *  Switch: '<S144>/Switch1'
       *  Switch: '<S144>/Switch2'
       */
      RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.VariantMerge_For_Variant_Sour_b = ((uint8_T)ENU_STOP);
    }

    /* Switch: '<S144>/Switch3' incorporates:
     *  Constant: '<S144>/ENU_BACKWARD2'
     *  Constant: '<S144>/ENU_STOP'
     *  Constant: '<S144>/ENU_STOP1'
     *  Switch: '<S144>/Switch1'
     *  Switch: '<S144>/Switch2'
     *  Switch: '<S144>/Switch3'
     */
    if (zcEvent_idx_1) {
      RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_BACKWARD);
    } else {
      RobotControl_B.VariantMerge_For_Variant_Source = ((uint8_T)ENU_STOP);
    }

    /* End of Switch: '<S144>/Switch3' */
  }

  /* End of Switch: '<S144>/Switch' */

  /* Chart: '<S146>/TargetReachedConfirmTime' */
  /* Gateway: RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* During: RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* time needed to confirm steady state for the PID */
  /* Entry Internal: RobotControl/RobotControlLib/MovementHandler/TargetReachedConfirmTime/TargetReachedConfirmTime */
  /* Transition: '<S157>:2' */
  if (rtb_Divide_e <= RobotCo_CAL_ALLOWED_ERROR_VALUE) {
    /* Transition: '<S157>:4' */
    /* Transition: '<S157>:6' */
    RobotControl_DW.counter_m++;
    if (RobotControl_DW.counter_m > (int16_T)Robo_CONST_TARGET_REACHED_TIMER) {
      /* Transition: '<S157>:15' */
      /* Transition: '<S157>:16' */
      RobotControl_DW.counter_m = 0U;
      RobotControl_B.targetReached = true;

      /* Transition: '<S157>:21' */
    } else {
      /* Transition: '<S157>:8' */
    }

    /* Transition: '<S157>:14' */
  } else {
    /* Transition: '<S157>:9' */
    RobotControl_DW.counter_m = 0U;
    RobotControl_B.targetReached = false;
  }

  /* End of Chart: '<S146>/TargetReachedConfirmTime' */

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
      (RobotControl_B.VariantMergeForOutportcomTstSta != ((uint8_T)ENU_TEST_INIT))
      && (RobotControl_B.currentRoutine != ((uint8_T)ENU_SHIFT_HEADING))) {
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

  /* Update for UnitDelay: '<S155>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S155>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S154>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S154>/FixPt Constant'
   */
  RobotControl_DW.FixPtUnitDelay2_DSTATE_jc = 0U;

  /* Update for UnitDelay: '<S143>/Unit Delay' */
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