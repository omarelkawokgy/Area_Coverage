/*
 * Code generation for system system '<S16>/StopRoutine'
 *
 * Model                      : RobotControl
 * Model version              : 1.509
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 30 11:39:58 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "StopRoutine.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S143>/stopRoutine' */
#define Robo_CONST_TARGET_REACHED_BLIND (5U)
#define RobotCo_CONST_CONFIRM_TIME_STOP ((uint8_T)5U)
#define RobotCont_IN_NO_ACTIVE_CHILD_id ((uint8_T)0U)
#define RobotContr_CAL_hitEscapeDist_mm (50U)
#define RobotContr_CAL_sideStuckTimeout (7000U)
#define RobotContro_ENU_MOVE_TURN_RIGHT ((uint8_T)21U)
#define RobotControl_BACKWARD          ((uint8_T)2U)
#define RobotControl_CAL_hitBakTimeout (400U)
#define RobotControl_ENU_MOVE_TURN_LEFT ((uint8_T)20U)
#define RobotControl_FORWARD           ((uint8_T)1U)
#define RobotControl_IN_CompleteStuck  ((uint8_T)1U)
#define RobotControl_IN_GetBakLeft     ((uint8_T)1U)
#define RobotControl_IN_GetBakRight    ((uint8_T)2U)
#define RobotControl_IN_HitStop        ((uint8_T)2U)
#define RobotControl_IN_Run            ((uint8_T)3U)
#define RobotControl_IN_backup         ((uint8_T)4U)
#define RobotControl_IN_escapeComplete ((uint8_T)3U)
#define RobotControl_IN_hitFinish      ((uint8_T)5U)
#define RobotControl_IN_sideStuck      ((uint8_T)6U)
#define RobotControl_IN_stopRoutine    ((uint8_T)1U)
#define RobotControl_IN_turnComplete   ((uint8_T)4U)
#define RobotControl_IN_turnComplete1  ((uint8_T)5U)
#define RobotControl_IN_turnLeft       ((uint8_T)6U)
#define RobotControl_IN_turnRight      ((uint8_T)7U)
#define RobotControl_STOP              ((uint8_T)5U)

/* System initialize for function-call system: '<S16>/StopRoutine' */
void RobotControl_StopRoutine_Init(void)
{
  /* SystemInitialize for Chart: '<S143>/stopRoutine' */
  RobotControl_DW.is_stopRoutine = RobotCont_IN_NO_ACTIVE_CHILD_id;
  RobotControl_DW.temporalCounter_i1_a = 0U;
  RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_id;
  RobotControl_DW.temporalCounter_i3 = 0U;
  RobotControl_DW.temporalCounter_i2 = 0U;
  RobotControl_DW.is_active_c19_RobotControlLib = 0U;
  RobotControl_DW.is_c19_RobotControlLib = RobotCont_IN_NO_ACTIVE_CHILD_id;
  RobotControl_DW.hitDistance = 0.0F;
  RobotControl_DW.escapeFlg = false;
  RobotControl_B.moveRequest_n = 0U;
  RobotControl_B.hitRoutineRun = false;
  RobotControl_B.stuckHitFlg = false;
  RobotControl_DW.refreshEventEventCounter = 0UL;
  RobotControl_B.refreshEvent = false;
  RobotControl_DW.stopEventEventCounter = 0UL;
  RobotControl_B.stopEvent = false;
}

/* Output and update for function-call system: '<S16>/StopRoutine' */
void RobotControl_StopRoutine(void)
{
  real32_T rtb_MinMax;

  /* MinMax: '<S24>/MinMax' */
  if ((RobotControl_B.Data_Type_Conversion >=
       RobotControl_B.Data_Type_Conversion_m) || rtIsNaNF
      (RobotControl_B.Data_Type_Conversion_m)) {
    rtb_MinMax = RobotControl_B.Data_Type_Conversion;
  } else {
    rtb_MinMax = RobotControl_B.Data_Type_Conversion_m;
  }

  /* End of MinMax: '<S24>/MinMax' */

  /* Chart: '<S143>/stopRoutine' incorporates:
   *  Constant: '<S24>/CAL_hitBackwardDist_mm1'
   */
  /* Gateway: RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
  if (RobotControl_DW.temporalCounter_i1_a < 1) {
    RobotControl_DW.temporalCounter_i1_a++;
  }

  if (RobotControl_DW.temporalCounter_i2 < 511U) {
    RobotControl_DW.temporalCounter_i2++;
  }

  if (RobotControl_DW.temporalCounter_i3 < 8191U) {
    RobotControl_DW.temporalCounter_i3++;
  }

  /* During: RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
  if (RobotControl_DW.is_active_c19_RobotControlLib == 0U) {
    /* Entry: RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
    RobotControl_DW.is_active_c19_RobotControlLib = 1U;

    /* Entry Internal: RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
    /* Transition: '<S144>:22' */
    RobotControl_DW.is_c19_RobotControlLib = RobotControl_IN_stopRoutine;
    RobotControl_DW.temporalCounter_i1_a = 0U;

    /* Entry Internal 'stopRoutine': '<S144>:18' */
    /* Transition: '<S144>:2' */
    RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
  } else {
    /* During 'stopRoutine': '<S144>:18' */
    if (RobotControl_DW.temporalCounter_i1_a == 1) {
      /* Event: '<S144>:19' */
      RobotControl_DW.refreshEventEventCounter++;
    }

    switch (RobotControl_DW.is_stopRoutine) {
     case RobotControl_IN_CompleteStuck:
      /* During 'CompleteStuck': '<S144>:50' */
      RobotControl_B.moveRequest_n = RobotControl_STOP;
      break;

     case RobotControl_IN_HitStop:
      /* During 'HitStop': '<S144>:3' */
      if (RobotControl_DW.temporalCounter_i2 >= RobotCo_CONST_CONFIRM_TIME_STOP)
      {
        /* Transition: '<S144>:7' */
        RobotControl_DW.is_stopRoutine = RobotControl_IN_backup;

        /* Entry 'backup': '<S144>:4' */
        RobotControl_DW.hitDistance = rtb_MinMax;
        RobotControl_B.moveRequest_n = RobotControl_BACKWARD;
      }
      break;

     case RobotControl_IN_Run:
      /* During 'Run': '<S144>:1' */
      if (RobotControl_B.DigitalInput) {
        /* Transition: '<S144>:6' */
        RobotControl_B.hitRoutineRun = true;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_HitStop;
        RobotControl_DW.temporalCounter_i2 = 0U;

        /* Entry 'HitStop': '<S144>:3' */
        RobotControl_B.moveRequest_n = RobotControl_STOP;
      }
      break;

     case RobotControl_IN_backup:
      /* During 'backup': '<S144>:4' */
      if (RobotControl_DW.hitDistance - rtb_MinMax > 150.0F) {
        /* Transition: '<S144>:8' */
        RobotControl_DW.is_stopRoutine = RobotControl_IN_hitFinish;
        RobotControl_DW.temporalCounter_i2 = 0U;

        /* Entry 'hitFinish': '<S144>:5' */
        RobotControl_B.moveRequest_n = RobotControl_STOP;
      }
      break;

     case RobotControl_IN_hitFinish:
      /* During 'hitFinish': '<S144>:5' */
      if (!RobotControl_B.DigitalInput) {
        /* Transition: '<S144>:12' */
        RobotControl_B.hitRoutineRun = false;

        /* Event: '<S144>:20' */
        RobotControl_DW.stopEventEventCounter++;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
      } else {
        if (RobotControl_DW.temporalCounter_i2 >= RobotControl_CAL_hitBakTimeout)
        {
          /* Transition: '<S144>:31' */
          /* 0.005*400 = 2sec */
          RobotControl_DW.escapeFlg = false;
          RobotControl_DW.is_stopRoutine = RobotControl_IN_sideStuck;
          RobotControl_DW.temporalCounter_i3 = 0U;

          /* Entry Internal 'sideStuck': '<S144>:30' */
          /* Transition: '<S144>:33' */
          if (RobotControl_B.leftBlocks < RobotControl_B.rightBlocks) {
            /* Transition: '<S144>:36' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnRight;
            RobotControl_DW.temporalCounter_i2 = 0U;

            /* Entry 'turnRight': '<S144>:35' */
            RobotControl_B.moveRequest_n = RobotContro_ENU_MOVE_TURN_RIGHT;
          } else if (RobotControl_B.leftBlocks > RobotControl_B.rightBlocks) {
            /* Transition: '<S144>:37' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnLeft;
            RobotControl_DW.temporalCounter_i2 = 0U;

            /* Entry 'turnLeft': '<S144>:32' */
            RobotControl_B.moveRequest_n = RobotControl_ENU_MOVE_TURN_LEFT;
          } else {
            /* Transition: '<S144>:58' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnLeft;
            RobotControl_DW.temporalCounter_i2 = 0U;

            /* Entry 'turnLeft': '<S144>:32' */
            RobotControl_B.moveRequest_n = RobotControl_ENU_MOVE_TURN_LEFT;
          }
        }
      }
      break;

     default:
      /* During 'sideStuck': '<S144>:30' */
      if (RobotControl_DW.escapeFlg) {
        /* Transition: '<S144>:49' */
        /* Exit Internal 'sideStuck': '<S144>:30' */
        RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_id;
        RobotControl_B.hitRoutineRun = false;

        /* Event: '<S144>:20' */
        RobotControl_DW.stopEventEventCounter++;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
      } else if (RobotControl_DW.temporalCounter_i3 >=
                 RobotContr_CAL_sideStuckTimeout) {
        /* Transition: '<S144>:51' */
        /* 0.005*5000 = 25sec */
        /* Exit Internal 'sideStuck': '<S144>:30' */
        RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_id;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_CompleteStuck;

        /* Entry 'CompleteStuck': '<S144>:50' */
        RobotControl_B.moveRequest_n = RobotControl_STOP;
        RobotControl_B.stuckHitFlg = true;
      } else {
        switch (RobotControl_DW.is_sideStuck) {
         case RobotControl_IN_GetBakLeft:
          /* During 'GetBakLeft': '<S144>:47' */
          /* Transition: '<S144>:64' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i2 >= 5U)) {
            /* Transition: '<S144>:65' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_escapeComplete;

            /* Entry 'escapeComplete': '<S144>:59' */
            RobotControl_B.moveRequest_n = RobotControl_STOP;
            RobotControl_DW.escapeFlg = true;
          }
          break;

         case RobotControl_IN_GetBakRight:
          /* During 'GetBakRight': '<S144>:43' */
          /* Transition: '<S144>:63' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i2 >= 5U)) {
            /* Transition: '<S144>:65' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_escapeComplete;

            /* Entry 'escapeComplete': '<S144>:59' */
            RobotControl_B.moveRequest_n = RobotControl_STOP;
            RobotControl_DW.escapeFlg = true;
          }
          break;

         case RobotControl_IN_escapeComplete:
          /* During 'escapeComplete': '<S144>:59' */
          break;

         case RobotControl_IN_turnComplete:
          /* During 'turnComplete': '<S144>:38' */
          if (rtb_MinMax - RobotControl_DW.hitDistance >
              RobotContr_CAL_hitEscapeDist_mm) {
            /* Transition: '<S144>:44' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_GetBakRight;
            RobotControl_DW.temporalCounter_i2 = 0U;

            /* Entry 'GetBakRight': '<S144>:43' */
            RobotControl_B.moveRequest_n = RobotContro_ENU_MOVE_TURN_RIGHT;
          }
          break;

         case RobotControl_IN_turnComplete1:
          /* During 'turnComplete1': '<S144>:46' */
          if (rtb_MinMax - RobotControl_DW.hitDistance >
              RobotContr_CAL_hitEscapeDist_mm) {
            /* Transition: '<S144>:48' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_GetBakLeft;
            RobotControl_DW.temporalCounter_i2 = 0U;

            /* Entry 'GetBakLeft': '<S144>:47' */
            RobotControl_B.moveRequest_n = RobotControl_ENU_MOVE_TURN_LEFT;
          }
          break;

         case RobotControl_IN_turnLeft:
          /* During 'turnLeft': '<S144>:32' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i2 >=
               Robo_CONST_TARGET_REACHED_BLIND)) {
            /* Transition: '<S144>:42' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnComplete;

            /* Entry 'turnComplete': '<S144>:38' */
            RobotControl_B.moveRequest_n = RobotControl_FORWARD;
            RobotControl_DW.hitDistance = rtb_MinMax;
          }
          break;

         default:
          /* During 'turnRight': '<S144>:35' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i2 >=
               Robo_CONST_TARGET_REACHED_BLIND)) {
            /* Transition: '<S144>:40' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnComplete1;

            /* Entry 'turnComplete1': '<S144>:46' */
            RobotControl_B.moveRequest_n = RobotControl_FORWARD;
            RobotControl_DW.hitDistance = rtb_MinMax;
          }
          break;
        }
      }
      break;
    }
  }

  if (RobotControl_DW.temporalCounter_i1_a == 1) {
    RobotControl_DW.temporalCounter_i1_a = 0U;
  }

  if (RobotControl_DW.refreshEventEventCounter > 0UL) {
    RobotControl_B.refreshEvent = !RobotControl_B.refreshEvent;
    RobotControl_DW.refreshEventEventCounter--;
  }

  if (RobotControl_DW.stopEventEventCounter > 0UL) {
    RobotControl_B.stopEvent = !RobotControl_B.stopEvent;
    RobotControl_DW.stopEventEventCounter--;
  }

  /* End of Chart: '<S143>/stopRoutine' */
}
