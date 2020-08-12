#define PROJECT_ROOT C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\SRC\RobotControl_ert_rtw
#define SOURCEFOLDER C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\SRC

#define TO_STRING(s) #s
#define ABSOLUTE_PATH(root, relative_path) TO_STRING(root\relative_path)
#define RELATIVE_PATH(library) ABSOLUTE_PATH(PROJECT_ROOT, library)
/* Main Function */
#include RELATIVE_PATH(RobotControl.h)
#include RELATIVE_PATH(RobotControl.c)
#include RELATIVE_PATH(RobotControl_data.c)
#include RELATIVE_PATH(RobotControl_private.h)
/* Compass Function */
#include RELATIVE_PATH(COM_A4SCA_A5SCL.h)
#include RELATIVE_PATH(COM_A4SCA_A5SCL.c)
#include RELATIVE_PATH(thetaFilter.h)
#include RELATIVE_PATH(thetaFilter.c)
#include RELATIVE_PATH(HeadingCalculator.h)
#include RELATIVE_PATH(HeadingCalculator.c)
/* Diag Function */
#include RELATIVE_PATH(DIAG_Cont.h)
#include RELATIVE_PATH(DIAG_Cont.c)
/* DSCA Function */
#include RELATIVE_PATH(DSCA.h)
#include RELATIVE_PATH(DSCA.c)
/* DirectionHandler Function */
#include RELATIVE_PATH(HeadingsDirectionHandler.h)
#include RELATIVE_PATH(HeadingsDirectionHandler.c)
/* HighLevelRoutines Function */
#include RELATIVE_PATH(HighLevelRoutines.h)
#include RELATIVE_PATH(HighLevelRoutines.c)
/* motorHandler Function */
#include RELATIVE_PATH(motorHandler.h)
#include RELATIVE_PATH(motorHandler.c)
/* MovementHandler Function */
#include RELATIVE_PATH(MovementHandler.h)
#include RELATIVE_PATH(MovementHandler.c)
/* ScanHandler Function */
#include RELATIVE_PATH(ScanHandler.h)
#include RELATIVE_PATH(ScanHandler.c)
/* StopRoutine Function */
#include RELATIVE_PATH(StopRoutine.h)
#include RELATIVE_PATH(StopRoutine.c)
/*parameters*/
#include RELATIVE_PATH(Params.h)
#include RELATIVE_PATH(Constant.h)
#include RELATIVE_PATH(MISC.h)
/*miscilenous*/
#include RELATIVE_PATH(rt_nonfinite.c)
#include RELATIVE_PATH(rt_nonfinite.h)
#include RELATIVE_PATH(rtGetInf.c)
#include RELATIVE_PATH(rtGetInf.h)
#include RELATIVE_PATH(rtGetNaN.c)
#include RELATIVE_PATH(rtGetNaN.h)

#define COMPASS_DEBUG false
#define ULSR_DEBUG true
#define ULSL_DEBUG false
#define PUMPER_DEBUG false
#define R_ENCODER_DEBUG false
#define L_ENCODER_DEBUG false

unsigned long previousMillis = 0; 

#if ((COMPASS_DEBUG) || (ULSR_DEBUG) || (ULSL_DEBUG) || (PUMPER_DEBUG) || (R_ENCODER_DEBUG) || (L_ENCODER_DEBUG))
uint16_t temp = 0;
#endif

void setup() {
//  // put your setup code here, to run once:
RobotControl_initialize();
#if (COMPASS_DEBUG) || (ULSR_DEBUG) || (ULSL_DEBUG) || (PUMPER_DEBUG) || (R_ENCODER_DEBUG) || (L_ENCODER_DEBUG)
  Serial.begin(9600);
#endif
}
//
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = micros();
  if (currentMillis - previousMillis >= 1000) 
  {
    previousMillis = currentMillis;
    RobotControl_step();
    
    #ifdef COMPASS_DEBUG
    Serial.println();
    #endif
    
    #ifdef ULSR_DEBUG
    ULSL_Hndler_Outputs_wrapper(PIN_D8, &temp);
    Serial.println(temp);
    #endif
    
    #ifdef ULSL_DEBUG
    Serial.println();
    #endif
    
    #ifdef PUMPER_DEBUG
    Serial.println();
    #endif
    
    #ifdef R_ENCODER_DEBUG
    Serial.println();
    #endif
    
    #ifdef L_ENCODER_DEBUG
    Serial.println();
    #endif    
  }
}
