/*
 * Code generation for system system '<S17>/HeadingCalculator'
 * For more details, see corresponding source file HeadingCalculator.c
 *
 */

#ifndef RTW_HEADER_HeadingCalculator_h_
#define RTW_HEADER_HeadingCalculator_h_
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

extern void RobotCon_HeadingCalculator_Init(void);
extern void RobotControl_HeadingCalculator(void);

#endif                                 /* RTW_HEADER_HeadingCalculator_h_ */
