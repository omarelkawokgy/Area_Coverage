/*
 * Code generation for system system '<S16>/DIAG_Cont'
 * For more details, see corresponding source file DIAG_Cont.c
 *
 */

#ifndef RTW_HEADER_DIAG_Cont_h_
#define RTW_HEADER_DIAG_Cont_h_
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

extern void RobotControl_DIAG_Cont_Init(void);
extern void RobotControl_DIAG_Cont(void);

#endif                                 /* RTW_HEADER_DIAG_Cont_h_ */
