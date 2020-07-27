/*
 * Code generation for system system '<S16>/ScanHandler'
 * For more details, see corresponding source file ScanHandler.c
 *
 */

#ifndef RTW_HEADER_ScanHandler_h_
#define RTW_HEADER_ScanHandler_h_
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

extern void RobotControl_ULS_AnalogIn_Init(void);
extern void RobotControl_ULS_AnalogIn(void);
extern void RobotControl_ScanHandler_Init(void);
extern void RobotControl_ScanHandler(void);

#endif                                 /* RTW_HEADER_ScanHandler_h_ */
