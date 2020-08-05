/*
 * File: COM_A4SCA_A5SCL.c
 *
 * Code generated for Simulink model 'RobotControl'.
 *
 * Model version                  : 1.553
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Aug 05 14:53:55 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "COM_A4SCA_A5SCL.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S1>/COM_A4SCA_A5SCL' */
void RobotContr_COM_A4SCA_A5SCL_Init(void)
{
  /* SystemInitialize for Chart: '<S5>/COM_A4SCA_A5SCL_Chart' */
  RobotControl_B.rawCompassValue = 0;
}

/* Output and update for function-call system: '<S1>/COM_A4SCA_A5SCL' */
void RobotControl_COM_A4SCA_A5SCL(void)
{
  /* Chart: '<S5>/COM_A4SCA_A5SCL_Chart' */
  /* Gateway: InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL_Chart */
  /* During: InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL_Chart */
  /* Entry Internal: InputHandler/COM_A4SCA_A5SCL/COM_A4SCA_A5SCL_Chart */
  /* Transition: '<S10>:2' */
  /* Transition: '<S10>:4' */
  HMC5883L_CompassRead(&RobotControl_B.rawCompassValue);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
