#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H
#include "types.h"

#define CW_CHECK 1
#define CCW_CHECK 0

#ifdef ENABLE_SIMULATION
#include "CONF.h"
void ISR_BumperHit(void);
#endif
extern Boolean ToStartPoint;
extern volatile Boolean BumperHit;
#endif
