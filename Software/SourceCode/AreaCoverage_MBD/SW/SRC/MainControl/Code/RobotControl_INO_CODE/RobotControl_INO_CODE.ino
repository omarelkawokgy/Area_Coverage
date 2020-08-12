#define PROJECT_ROOT C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\Code\RobotControl_ert_rtw
#define SOURCEFOLDER C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\Code

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

//INPUTS
#define COMPASS_DEBUG true
#define ULSR_DEBUG true
#define ULSL_DEBUG true
#define PUMPER_DEBUG true
#define R_ENCODER_DEBUG true
#define L_ENCODER_DEBUG true
//OUTPUTS
#define LEFT_MOTOR_POS true
#define LEFT_MOTOR_NEG true
#define RIGHT_MOTOR_POS true
#define RIGHT_MOTOR_NEG true
#define RED_LED true
#define GREEN_LED true
//NVM
#define NVM_ANGLE_STORE_FLG true
#define NVM_NORTH_DEBUG true
#define NVM_SOUTH_DEBUG true
#define NVM_EAST_DEBUG true
#define NVM_WEST_DEBUG true

unsigned long previousMillis = 0; 

#if ((COMPASS_DEBUG) || (ULSR_DEBUG) || (ULSL_DEBUG) || (PUMPER_DEBUG)\
|| (R_ENCODER_DEBUG) || (L_ENCODER_DEBUG)\
|| (LEFT_MOTOR_POS) || (LEFT_MOTOR_NEG)\
|| (RIGHT_MOTOR_POS) || (RIGHT_MOTOR_NEG)\
|| (RED_LED) || (GREEN_LED)\
|| (NVM_ANGLE_STORE_FLG)\
|| (NVM_NORTH_DEBUG) || (NVM_SOUTH_DEBUG)\
|| (NVM_EAST_DEBUG) || (NVM_WEST_DEBUG))
uint16_t temp = 0;
#endif

void setup() {
//  // put your setup code here, to run once:
//Defining pin configurations
//INPUTS
pinMode(A0, INPUT); //rightEncoderTicks_uint16
pinMode(A1, INPUT); //leftEncoderTicks_uint16
pinMode(7, INPUT); //ULSL_cm
pinMode(8, INPUT); //ULSR_cm
pinMode(2, INPUT); //pumperHit_BOOL
//OUTPUTS
pinMode(5, OUTPUT); //leftPosPin
pinMode(6, OUTPUT); //leftNegPin
pinMode(9, OUTPUT); //rightPosPin
pinMode(10, OUTPUT); //rightNegPin
pinMode(3, OUTPUT); //redLED_BOOL
pinMode(11, OUTPUT); //greenLED_BOOL

RobotControl_initialize();
#if ((COMPASS_DEBUG) || (ULSR_DEBUG) || (ULSL_DEBUG) || (PUMPER_DEBUG)\
|| (R_ENCODER_DEBUG) || (L_ENCODER_DEBUG)\
|| (LEFT_MOTOR_POS) || (LEFT_MOTOR_NEG)\
|| (RIGHT_MOTOR_POS) || (RIGHT_MOTOR_NEG)\
|| (RED_LED) || (GREEN_LED)\
|| (NVM_ANGLE_STORE_FLG)\
|| (NVM_NORTH_DEBUG) || (NVM_SOUTH_DEBUG)\
|| (NVM_EAST_DEBUG) || (NVM_WEST_DEBUG))
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

    //INPUTS
    #ifdef COMPASS_DEBUG
    Serial.println(RobotControl_B.rawCompassValue);
    #endif
    
    #ifdef ULSR_DEBUG
    Serial.println(RobotControl_B.ULSR_cm);
    #endif
    
    #ifdef ULSL_DEBUG
    Serial.println(RobotControl_B.ULSL_cm);
    #endif
    
    #ifdef PUMPER_DEBUG
    Serial.println(RobotControl_B.pumperHit_BOOL);
    #endif
    
    #ifdef R_ENCODER_DEBUG
    Serial.println(RobotControl_B.rightEncoderTicks_uint16);
    #endif
    
    #ifdef L_ENCODER_DEBUG
    Serial.println(RobotControl_B.leftEncoderTicks_uint16);
    #endif   

    //OUTPUTS
    #ifdef LEFT_MOTOR_POS
    Serial.println(RobotControl_B.leftPosPin);
    #endif
    
    #ifdef LEFT_MOTOR_NEG
    Serial.println(RobotControl_B.leftNegPin);
    #endif
    
    #ifdef RIGHT_MOTOR_POS
    Serial.println(RobotControl_B.rightPosPin);
    #endif
    
    #ifdef RIGHT_MOTOR_NEG
    Serial.println(RobotControl_B.rightNegPin);
    #endif
    
    #ifdef RED_LED
    Serial.println(RobotControl_B.redLED_BOOL);
    #endif
    
    #ifdef GREEN_LED
    Serial.println(RobotControl_B.greenLED_BOOL);
    #endif 

    //NVM        
    #ifdef NVM_ANGLE_STORE_FLG
    Serial.println(RobotControl_B.NVM_AngleStoreFlg);
    #endif
    
    #ifdef NVM_NORTH_DEBUG
    Serial.println(RobotControl_B.NVM_NORTH);
    #endif
    
    #ifdef NVM_SOUTH_DEBUG
    Serial.println(RobotControl_B.NVM_SOUTH);
    #endif
    
    #ifdef NVM_EAST_DEBUG
    Serial.println(RobotControl_B.NVM_EAST);
    #endif
    
    #ifdef NVM_WEST_DEBUG
    Serial.println(RobotControl_B.NVM_WEST);
    #endif  
  }
}
