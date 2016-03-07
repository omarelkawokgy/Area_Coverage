#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H
#include "types.h"

#ifdef ENABLE_SIMULATION
#include "CONF.h"
void ISR_BumperHit(void);
#endif
extern Boolean ToStartPoint;
#endif
