/*
 * Code generation for system system '<S16>/StopRoutine'
 * For more details, see corresponding source file StopRoutine.c
 *
 */

#ifndef RTW_HEADER_StopRoutine_h_
#define RTW_HEADER_StopRoutine_h_
#ifndef RobotControl_COMMON_INCLUDES_
# define RobotControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalio.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* RobotControl_COMMON_INCLUDES_ */

#include "RobotControl_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

extern void RobotControl_StopRoutine_Init(void);
extern void RobotControl_StopRoutine(void);

#endif                                 /* RTW_HEADER_StopRoutine_h_ */
