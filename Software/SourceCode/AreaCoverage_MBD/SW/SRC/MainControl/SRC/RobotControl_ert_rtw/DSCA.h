/*
 * Code generation for system system '<S16>/DSCA'
 * For more details, see corresponding source file DSCA.c
 *
 */

#ifndef RTW_HEADER_DSCA_h_
#define RTW_HEADER_DSCA_h_
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "MW_digitalio.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<S52>/EncoderIncrement' */
typedef struct {
  int32_T distCounter;                 /* '<S56>/Add' */
} B_EncoderIncrement_RobotContr_T;

/* Zero-crossing (trigger) state for system '<S52>/EncoderIncrement' */
typedef struct {
  ZCSigState EncoderIncrement_Trig_ZCE;/* '<S52>/EncoderIncrement' */
} ZCE_EncoderIncrement_RobotCon_T;

/* Block signals for system '<S73>/SpdTickDetector' */
typedef struct {
  real32_T spd;                        /* '<S73>/SpdTickDetector' */
} B_SpdTickDetector_RobotContro_T;

/* Block states (auto storage) for system '<S73>/SpdTickDetector' */
typedef struct {
  real32_T encoderTick_prev;           /* '<S73>/SpdTickDetector' */
  real32_T encoderTick_start;          /* '<S73>/SpdTickDetector' */
  uint8_T is_active_c9_DSCA;           /* '<S73>/SpdTickDetector' */
  uint8_T is_c9_DSCA;                  /* '<S73>/SpdTickDetector' */
  uint8_T cycleCnt;                    /* '<S73>/SpdTickDetector' */
} DW_SpdTickDetector_RobotContr_T;

extern void RobotCont_EncoderIncrement_Init(B_EncoderIncrement_RobotContr_T
  *localB);
extern void RobotControl_EncoderIncrement(boolean_T rtu_EncoderTicks_Bool,
  uint8_T rtu_motorDirection, B_EncoderIncrement_RobotContr_T *localB,
  ZCE_EncoderIncrement_RobotCon_T *localZCE);
extern void RobotContr_SpdTickDetector_Init(B_SpdTickDetector_RobotContro_T
  *localB, DW_SpdTickDetector_RobotContr_T *localDW);
extern void RobotControl_SpdTickDetector(real32_T rtu_encoderTick,
  B_SpdTickDetector_RobotContro_T *localB, DW_SpdTickDetector_RobotContr_T
  *localDW);
extern void RobotContr_EncoderAnalogIn_Init(void);
extern void RobotCont_EncoderAnalogIn_Start(void);
extern void RobotControl_EncoderAnalogIn(void);
extern void RobotControl_DSCA_Init(void);
extern void RobotControl_DSCA_Start(void);
extern void RobotControl_DSCA(void);

#endif                                 /* RTW_HEADER_DSCA_h_ */
