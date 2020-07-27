/*
 * Code generation for system system '<S17>/thetaFilter'
 * For more details, see corresponding source file thetaFilter.c
 *
 */

#ifndef RTW_HEADER_thetaFilter_h_
#define RTW_HEADER_thetaFilter_h_
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

extern void RobotControl_thetaFilter_Init(void);
extern void RobotControl_thetaFilter(void);

#endif                                 /* RTW_HEADER_thetaFilter_h_ */
