/*
 * File: StopRoutine.c
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

#include "StopRoutine.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* Named constants for Chart: '<S161>/stopRoutine' */
#define Robo_CONST_TARGET_REACHED_BLIND (5U)
#define RobotCo_CONST_CONFIRM_TIME_STOP ((uint8_T)5U)
#define RobotCont_ENU_MOVE_TURN_RIGHT_n ((uint8_T)21U)
#define RobotCont_IN_NO_ACTIVE_CHILD_em ((uint8_T)0U)
#define RobotContr_CAL_hitEscapeDist_mm (50U)
#define RobotContr_CAL_sideStuckTimeout (7000U)
#define RobotContr_ENU_MOVE_TURN_LEFT_b ((uint8_T)20U)
#define RobotControl_BACKWARD          ((uint8_T)2U)
#define RobotControl_CAL_hitBakTimeout (400U)
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
#define RobotControl_IN_turnLeft_j     ((uint8_T)6U)
#define RobotControl_IN_turnRight_h    ((uint8_T)7U)
#define RobotControl_STOP              ((uint8_T)5U)

/* System initialize for atomic system: '<S1>/Digital_IN_bool' */
void RobotContr_Digital_IN_bool_Init(void)
{
  RobotControl_B.pumperHit_BOOL = false;
}

/* Output and update for atomic system: '<S1>/Digital_IN_bool' */
void RobotControl_Digital_IN_bool(uint8_T rtu_pin)
{
  /* Gateway: InputHandler/Digital_IN_bool */
  /* During: InputHandler/Digital_IN_bool */
  /* Entry Internal: InputHandler/Digital_IN_bool */
  /* Transition: '<S6>:2' */
  /* Transition: '<S6>:4' */
  RobotControl_B.pumperHit_BOOL = (digitalRead(rtu_pin) != 0);
}

/* System initialize for function-call system: '<S22>/StopRoutine' */
void RobotControl_StopRoutine_Init(void)
{
  /* SystemInitialize for Chart: '<S161>/stopRoutine' */
  RobotControl_DW.is_stopRoutine = RobotCont_IN_NO_ACTIVE_CHILD_em;
  RobotControl_DW.temporalCounter_i1_j = 0U;
  RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_em;
  RobotControl_DW.temporalCounter_i2 = 0U;
  RobotControl_DW.temporalCounter_i3 = 0U;
  RobotControl_DW.is_active_c19_RobotControl = 0U;
  RobotControl_DW.is_c19_RobotControl = RobotCont_IN_NO_ACTIVE_CHILD_em;
  RobotControl_DW.hitDistance = 0.0F;
  RobotControl_DW.escapeFlg = false;
  RobotControl_B.moveRequest_i = 0U;
  RobotControl_B.hitRoutineRun = false;
  RobotControl_B.stuckHitFlg_c = false;
  RobotControl_DW.refreshEventEventCounter = 0UL;
  RobotControl_B.refreshEvent = false;
  RobotControl_DW.stopEventEventCounter = 0UL;
  RobotControl_B.stopEvent = false;
}

/* Output and update for function-call system: '<S22>/StopRoutine' */
void RobotControl_StopRoutine(void)
{
  real32_T rtb_MinMax;

  /* MinMax: '<S30>/MinMax' */
  if ((RobotControl_B.Data_Type_Conversion >=
       RobotControl_B.Data_Type_Conversion_m) || rtIsNaNF
      (RobotControl_B.Data_Type_Conversion_m)) {
    rtb_MinMax = RobotControl_B.Data_Type_Conversion;
  } else {
    rtb_MinMax = RobotControl_B.Data_Type_Conversion_m;
  }

  /* End of MinMax: '<S30>/MinMax' */

  /* Chart: '<S161>/stopRoutine' incorporates:
   *  Constant: '<S30>/CAL_hitBackwardDist_mm1'
   */
  /* Gateway: RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
  if (RobotControl_DW.temporalCounter_i1_j < 1) {
    RobotControl_DW.temporalCounter_i1_j++;
  }

  if (RobotControl_DW.temporalCounter_i2 < 8191U) {
    RobotControl_DW.temporalCounter_i2++;
  }

  if (RobotControl_DW.temporalCounter_i3 < 7U) {
    RobotControl_DW.temporalCounter_i3++;
  }

  /* During: RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
  /* handles the stop routine. stop motors move backward for certain distance and proceed */
  if (RobotControl_DW.is_active_c19_RobotControl == 0U) {
    /* Entry: RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
    RobotControl_DW.is_active_c19_RobotControl = 1U;

    /* Entry Internal: RobotControl/RobotControlLib/StopRoutine/stopRoutine/stopRoutine */
    /* Transition: '<S162>:22' */
    RobotControl_DW.is_c19_RobotControl = RobotControl_IN_stopRoutine;
    RobotControl_DW.temporalCounter_i1_j = 0U;

    /* Entry Internal 'stopRoutine': '<S162>:18' */
    /* Transition: '<S162>:2' */
    RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
  } else {
    /* During 'stopRoutine': '<S162>:18' */
    if (RobotControl_DW.temporalCounter_i1_j == 1) {
      /* Event: '<S162>:19' */
      RobotControl_DW.refreshEventEventCounter++;
    }

    switch (RobotControl_DW.is_stopRoutine) {
     case RobotControl_IN_CompleteStuck:
      /* During 'CompleteStuck': '<S162>:50' */
      RobotControl_B.moveRequest_i = RobotControl_STOP;
      break;

     case RobotControl_IN_HitStop:
      /* During 'HitStop': '<S162>:3' */
      if (RobotControl_DW.temporalCounter_i2 >= RobotCo_CONST_CONFIRM_TIME_STOP)
      {
        /* Transition: '<S162>:7' */
        RobotControl_DW.is_stopRoutine = RobotControl_IN_backup;

        /* Entry 'backup': '<S162>:4' */
        RobotControl_DW.hitDistance = rtb_MinMax;
        RobotControl_B.moveRequest_i = RobotControl_BACKWARD;
      }
      break;

     case RobotControl_IN_Run:
      /* During 'Run': '<S162>:1' */
      if (RobotControl_B.pumperHit_BOOL) {
        /* Transition: '<S162>:6' */
        RobotControl_B.hitRoutineRun = true;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_HitStop;
        RobotControl_DW.temporalCounter_i2 = 0U;

        /* Entry 'HitStop': '<S162>:3' */
        RobotControl_B.moveRequest_i = RobotControl_STOP;
      }
      break;

     case RobotControl_IN_backup:
      /* During 'backup': '<S162>:4' */
      if (RobotControl_DW.hitDistance - rtb_MinMax > CAL_hitBackwardDist_mm) {
        /* Transition: '<S162>:8' */
        RobotControl_DW.is_stopRoutine = RobotControl_IN_hitFinish;
        RobotControl_DW.temporalCounter_i2 = 0U;

        /* Entry 'hitFinish': '<S162>:5' */
        RobotControl_B.moveRequest_i = RobotControl_STOP;
      }
      break;

     case RobotControl_IN_hitFinish:
      /* During 'hitFinish': '<S162>:5' */
      if (!RobotControl_B.pumperHit_BOOL) {
        /* Transition: '<S162>:12' */
        RobotControl_B.hitRoutineRun = false;

        /* Event: '<S162>:20' */
        RobotControl_DW.stopEventEventCounter++;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
      } else {
        if (RobotControl_DW.temporalCounter_i2 >= RobotControl_CAL_hitBakTimeout)
        {
          /* Transition: '<S162>:31' */
          /* 0.005*400 = 2sec */
          RobotControl_DW.escapeFlg = false;
          RobotControl_DW.is_stopRoutine = RobotControl_IN_sideStuck;
          RobotControl_DW.temporalCounter_i2 = 0U;

          /* Entry Internal 'sideStuck': '<S162>:30' */
          /* Transition: '<S162>:33' */
          if (RobotControl_B.leftBlocks < RobotControl_B.rightBlocks) {
            /* Transition: '<S162>:36' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnRight_h;
            RobotControl_DW.temporalCounter_i3 = 0U;

            /* Entry 'turnRight': '<S162>:35' */
            RobotControl_B.moveRequest_i = RobotCont_ENU_MOVE_TURN_RIGHT_n;
          } else if (RobotControl_B.leftBlocks > RobotControl_B.rightBlocks) {
            /* Transition: '<S162>:37' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnLeft_j;
            RobotControl_DW.temporalCounter_i3 = 0U;

            /* Entry 'turnLeft': '<S162>:32' */
            RobotControl_B.moveRequest_i = RobotContr_ENU_MOVE_TURN_LEFT_b;
          } else {
            /* Transition: '<S162>:58' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnLeft_j;
            RobotControl_DW.temporalCounter_i3 = 0U;

            /* Entry 'turnLeft': '<S162>:32' */
            RobotControl_B.moveRequest_i = RobotContr_ENU_MOVE_TURN_LEFT_b;
          }
        }
      }
      break;

     default:
      /* During 'sideStuck': '<S162>:30' */
      if (RobotControl_DW.escapeFlg) {
        /* Transition: '<S162>:49' */
        /* Exit Internal 'sideStuck': '<S162>:30' */
        RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_em;
        RobotControl_B.hitRoutineRun = false;

        /* Event: '<S162>:20' */
        RobotControl_DW.stopEventEventCounter++;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_Run;
      } else if (RobotControl_DW.temporalCounter_i2 >=
                 RobotContr_CAL_sideStuckTimeout) {
        /* Transition: '<S162>:51' */
        /* 0.005*5000 = 25sec */
        /* Exit Internal 'sideStuck': '<S162>:30' */
        RobotControl_DW.is_sideStuck = RobotCont_IN_NO_ACTIVE_CHILD_em;
        RobotControl_DW.is_stopRoutine = RobotControl_IN_CompleteStuck;

        /* Entry 'CompleteStuck': '<S162>:50' */
        RobotControl_B.moveRequest_i = RobotControl_STOP;
        RobotControl_B.stuckHitFlg_c = true;
      } else {
        switch (RobotControl_DW.is_sideStuck) {
         case RobotControl_IN_GetBakLeft:
          /* During 'GetBakLeft': '<S162>:47' */
          /* Transition: '<S162>:64' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i3 >= 5)) {
            /* Transition: '<S162>:65' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_escapeComplete;

            /* Entry 'escapeComplete': '<S162>:59' */
            RobotControl_B.moveRequest_i = RobotControl_STOP;
            RobotControl_DW.escapeFlg = true;
          }
          break;

         case RobotControl_IN_GetBakRight:
          /* During 'GetBakRight': '<S162>:43' */
          /* Transition: '<S162>:63' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i3 >= 5)) {
            /* Transition: '<S162>:65' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_escapeComplete;

            /* Entry 'escapeComplete': '<S162>:59' */
            RobotControl_B.moveRequest_i = RobotControl_STOP;
            RobotControl_DW.escapeFlg = true;
          }
          break;

         case RobotControl_IN_escapeComplete:
          /* During 'escapeComplete': '<S162>:59' */
          break;

         case RobotControl_IN_turnComplete:
          /* During 'turnComplete': '<S162>:38' */
          if (rtb_MinMax - RobotControl_DW.hitDistance >
              RobotContr_CAL_hitEscapeDist_mm) {
            /* Transition: '<S162>:44' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_GetBakRight;
            RobotControl_DW.temporalCounter_i3 = 0U;

            /* Entry 'GetBakRight': '<S162>:43' */
            RobotControl_B.moveRequest_i = RobotCont_ENU_MOVE_TURN_RIGHT_n;
          }
          break;

         case RobotControl_IN_turnComplete1:
          /* During 'turnComplete1': '<S162>:46' */
          if (rtb_MinMax - RobotControl_DW.hitDistance >
              RobotContr_CAL_hitEscapeDist_mm) {
            /* Transition: '<S162>:48' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_GetBakLeft;
            RobotControl_DW.temporalCounter_i3 = 0U;

            /* Entry 'GetBakLeft': '<S162>:47' */
            RobotControl_B.moveRequest_i = RobotContr_ENU_MOVE_TURN_LEFT_b;
          }
          break;

         case RobotControl_IN_turnLeft_j:
          /* During 'turnLeft': '<S162>:32' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i3 >= (int16_T)
               Robo_CONST_TARGET_REACHED_BLIND)) {
            /* Transition: '<S162>:42' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnComplete;

            /* Entry 'turnComplete': '<S162>:38' */
            RobotControl_B.moveRequest_i = RobotControl_FORWARD;
            RobotControl_DW.hitDistance = rtb_MinMax;
          }
          break;

         default:
          /* During 'turnRight': '<S162>:35' */
          if (RobotControl_B.OutportBufferFortargetReached &&
              (RobotControl_DW.temporalCounter_i3 >= (int16_T)
               Robo_CONST_TARGET_REACHED_BLIND)) {
            /* Transition: '<S162>:40' */
            RobotControl_DW.is_sideStuck = RobotControl_IN_turnComplete1;

            /* Entry 'turnComplete1': '<S162>:46' */
            RobotControl_B.moveRequest_i = RobotControl_FORWARD;
            RobotControl_DW.hitDistance = rtb_MinMax;
          }
          break;
        }
      }
      break;
    }
  }

  if (RobotControl_DW.temporalCounter_i1_j == 1) {
    RobotControl_DW.temporalCounter_i1_j = 0U;
  }

  if (RobotControl_DW.refreshEventEventCounter > 0UL) {
    RobotControl_B.refreshEvent = !RobotControl_B.refreshEvent;
    RobotControl_DW.refreshEventEventCounter--;
  }

  if (RobotControl_DW.stopEventEventCounter > 0UL) {
    RobotControl_B.stopEvent = !RobotControl_B.stopEvent;
    RobotControl_DW.stopEventEventCounter--;
  }

  /* End of Chart: '<S161>/stopRoutine' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
