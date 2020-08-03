/*
 * Code generation for system system '<S16>/motorHandler'
 * For more details, see corresponding source file motorHandler.c
 *
 */

#ifndef RTW_HEADER_motorHandler_h_
#define RTW_HEADER_motorHandler_h_
#include <math.h>
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

extern void RobotControl_motorHandler_Init(void);
extern void RobotControl_motorHandler(void);

#endif                                 /* RTW_HEADER_motorHandler_h_ */
