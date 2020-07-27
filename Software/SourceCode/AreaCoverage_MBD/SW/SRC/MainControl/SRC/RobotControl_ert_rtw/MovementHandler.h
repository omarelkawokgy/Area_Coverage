/*
 * Code generation for system system '<S16>/MovementHandler'
 * For more details, see corresponding source file MovementHandler.c
 *
 */

#ifndef RTW_HEADER_MovementHandler_h_
#define RTW_HEADER_MovementHandler_h_
#include <math.h>
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
#include "rt_nonfinite.h"

extern void RobotContr_MovementHandler_Init(void);
extern void RobotControl_MovementHandler(void);

#endif                                 /* RTW_HEADER_MovementHandler_h_ */
