/*
 * File: HeadingsDirectionHandler.c
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

#include "HeadingsDirectionHandler.h"

/* Include model header file for global data */
#include "RobotControl.h"
#include "RobotControl_private.h"

/* System initialize for function-call system: '<S22>/HeadingsDirectionHandler' */
void R_HeadingsDirectionHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S26>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = ((uint8_T)ENU_END);
}

/* Output and update for function-call system: '<S22>/HeadingsDirectionHandler' */
void RobotC_HeadingsDirectionHandler(void)
{
  boolean_T rtb_Switch2;
  int16_T rtb_Switch_m_idx_0;
  int16_T rtb_Switch_m_idx_1;
  int16_T rtb_Switch_m_idx_2;
  int16_T rtb_Switch_m_idx_3;

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/ENU_SHIFT_HEADING'
   *  Logic: '<S104>/Logical Operator'
   *  RelationalOperator: '<S104>/Relational_Operator6'
   *  UnitDelay: '<S104>/Unit Delay'
   *  UnitDelay: '<S26>/Unit_Delay'
   */
  rtb_Switch2 = ((RobotControl_DW.Unit_Delay_DSTATE_b == ((uint8_T)
    ENU_SHIFT_HEADING)) || RobotControl_DW.UnitDelay_DSTATE_d);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/CAL_EAST'
   *  Constant: '<S26>/CAL_NORTH'
   *  Constant: '<S26>/CAL_SOUTH'
   *  Constant: '<S26>/CAL_WEST'
   */
  if (RobotControl_B.NVM_AngleStoreFlg) {
    rtb_Switch_m_idx_0 = RobotControl_B.DataTypeConversion_p;
    rtb_Switch_m_idx_1 = RobotControl_B.DataTypeConversion1_b;
    rtb_Switch_m_idx_2 = RobotControl_B.DataTypeConversion2_g;
    rtb_Switch_m_idx_3 = RobotControl_B.DataTypeConversion3_j;
  } else {
    rtb_Switch_m_idx_0 = CAL_NORTH;
    rtb_Switch_m_idx_1 = CAL_SOUTH;
    rtb_Switch_m_idx_2 = CAL_EAST;
    rtb_Switch_m_idx_3 = CAL_WEST;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Switch: '<S26>/Switch1' */
  if (rtb_Switch2) {
    /* SignalConversion: '<S26>/Signal Conversion' */
    RobotControl_B.ROB_NORTH = rtb_Switch_m_idx_3;

    /* SignalConversion: '<S26>/Signal Conversion1' */
    RobotControl_B.ROB_SOUTH = rtb_Switch_m_idx_2;

    /* SignalConversion: '<S26>/Signal Conversion2' */
    RobotControl_B.ROB_EAST = rtb_Switch_m_idx_0;

    /* SignalConversion: '<S26>/Signal Conversion3' */
    RobotControl_B.ROB_WEST = rtb_Switch_m_idx_1;
  } else {
    /* SignalConversion: '<S26>/Signal Conversion' */
    RobotControl_B.ROB_NORTH = rtb_Switch_m_idx_0;

    /* SignalConversion: '<S26>/Signal Conversion1' */
    RobotControl_B.ROB_SOUTH = rtb_Switch_m_idx_1;

    /* SignalConversion: '<S26>/Signal Conversion2' */
    RobotControl_B.ROB_EAST = rtb_Switch_m_idx_2;

    /* SignalConversion: '<S26>/Signal Conversion3' */
    RobotControl_B.ROB_WEST = rtb_Switch_m_idx_3;
  }

  /* End of Switch: '<S26>/Switch1' */

  /* Update for UnitDelay: '<S26>/Unit_Delay' */
  RobotControl_DW.Unit_Delay_DSTATE_b = RobotControl_B.currentRoutine;

  /* Update for UnitDelay: '<S104>/Unit Delay' */
  RobotControl_DW.UnitDelay_DSTATE_d = rtb_Switch2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
