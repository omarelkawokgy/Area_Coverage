#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H
#include "types.h"
#include "CONF.h"

#ifdef ENABLE_SIMULATION
void ISR_BumperHit(void);
#endif
extern Boolean ToStartPoint;
extern volatile Boolean BumperHit;
extern Boolean ZigZagFlag;
#endif
