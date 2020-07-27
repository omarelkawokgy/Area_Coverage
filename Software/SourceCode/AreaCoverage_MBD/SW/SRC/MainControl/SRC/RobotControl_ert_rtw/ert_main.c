#include "RobotControl.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  RobotControl_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.001;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(RobotControl_M, 0);
  RobotControl_initialize();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(RobotControl_M) == (NULL)) && !rtmGetStopRequested
    (RobotControl_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    runModel =
      (rtmGetErrorStatus(RobotControl_M) == (NULL)) && !rtmGetStopRequested
      (RobotControl_M);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  RobotControl_terminate();
  cli();
  return 0;
}
