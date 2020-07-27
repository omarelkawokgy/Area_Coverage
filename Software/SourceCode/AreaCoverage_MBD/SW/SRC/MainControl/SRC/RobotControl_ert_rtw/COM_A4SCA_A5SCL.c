/*
 * Code generation for system system '<S1>/COM_A4SCA_A5SCL'
 *
 * Model                      : RobotControl
 * Model version              : 1.500
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Jul 27 18:15:17 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "COM_A4SCA_A5SCL.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S1>/COM_A4SCA_A5SCL' */
void RobotContr_COM_A4SCA_A5SCL_Init(void)
{
  /* SystemInitialize for Outport: '<S5>/thetaCompass' */
  RobotControl_B.COM_A4SCA_A5SCL = 0;
}

/* Output and update for function-call system: '<S1>/COM_A4SCA_A5SCL' */
void RobotControl_COM_A4SCA_A5SCL(void)
{
  /* Level2 S-Function Block: '<S5>/COM_A4SCA_A5SCL' (CompassSFunc) */
  {
    SimStruct *rts = RobotControl_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Termination for function-call system: '<S1>/COM_A4SCA_A5SCL' */
void RobotContr_COM_A4SCA_A5SCL_Term(void)
{
  /* Level2 S-Function Block: '<S5>/COM_A4SCA_A5SCL' (CompassSFunc) */
  {
    SimStruct *rts = RobotControl_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
