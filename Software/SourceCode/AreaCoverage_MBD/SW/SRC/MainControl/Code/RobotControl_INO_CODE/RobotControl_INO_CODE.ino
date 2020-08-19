/********************************************* PROJECT PATHS ***************************************************/

#define PROJECT_ROOT C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\SRC\RobotControl_ert_rtw
#define SOURCEFOLDER C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\SRC\MainControl\Code

#define TO_STRING(s) #s
#define ABSOLUTE_PATH(root, relative_path) TO_STRING(root\relative_path)
#define RELATIVE_PATH(library) ABSOLUTE_PATH(PROJECT_ROOT, library)

/********************************************* INCLUDES ***************************************************/
/* Main Function */
#include RELATIVE_PATH(RobotControl_types.h)
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
//#include RELATIVE_PATH(motorHandler.h)
//#include RELATIVE_PATH(motorHandler.c)
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
//#include RELATIVE_PATH(MISC.h)
/*miscilenous*/
#include RELATIVE_PATH(rt_nonfinite.c)
#include RELATIVE_PATH(rt_nonfinite.h)
#include RELATIVE_PATH(rtGetInf.c)
#include RELATIVE_PATH(rtGetInf.h)
#include RELATIVE_PATH(rtGetNaN.c)
#include RELATIVE_PATH(rtGetNaN.h)

/********************************************* MACRO_FLAGS ***************************************************/

//INPUTS
#define COMPASS_DEBUG false
#define ULSR_DEBUG false
#define ULSL_DEBUG false
#define PUMPER_DEBUG false
#define R_ENCODER_DEBUG false
#define L_ENCODER_DEBUG false
//OUTPUTS
#define LEFT_MOTOR_POS false
#define LEFT_MOTOR_NEG false
#define RIGHT_MOTOR_POS false
#define RIGHT_MOTOR_NEG false
#define RED_LED false
#define GREEN_LED false
//NVM
#define NVM_ANGLE_STORE_FLG false
#define NVM_NORTH_DEBUG false
#define NVM_SOUTH_DEBUG false
#define NVM_EAST_DEBUG false
#define NVM_WEST_DEBUG false
//DIAG
#define DIAG_DEBUG true

/********************************************* MACRO_DEFINES ***************************************************/

#define TIME_1MS 1000
#define TIME_50MS 50000
#define TIME_100MS 100000
#define TIME_500MS 500000
#define TIME_2000MS 2000000

/********************************************* MACRO_DEBUG_CONTROL ***************************************************/

#if LEFT_MOTOR_POS || LEFT_MOTOR_NEG || RIGHT_MOTOR_POS || RIGHT_MOTOR_NEG
unsigned long previousMillis_50 = 0;
#endif

#if PUMPER_DEBUG
unsigned long previousMillis_100 = 0;
#endif

#if COMPASS_DEBUG || ULSR_DEBUG || ULSL_DEBUG
unsigned long previousMillis_500 = 0;
#endif

#if RED_LED || GREEN_LED || NVM_ANGLE_STORE_FLG || NVM_NORTH_DEBUG\
|| NVM_SOUTH_DEBUG || NVM_EAST_DEBUG || NVM_WEST_DEBUG || DIAG_DEBUG
unsigned long previousMillis_2Sec = 0;
#endif

/*********************************************** GLOBAL_VARIABLES ***************************************************/

unsigned long previousMillis = 0; 

/********************************************* INITIALIZATION_FUNCTION ***************************************************/

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
Serial.begin(9600);
#if (COMPASS_DEBUG) || (ULSR_DEBUG) || (ULSL_DEBUG) || (PUMPER_DEBUG)\
|| (R_ENCODER_DEBUG) || (L_ENCODER_DEBUG)\
|| (LEFT_MOTOR_POS) || (LEFT_MOTOR_NEG)\
|| (RIGHT_MOTOR_POS) || (RIGHT_MOTOR_NEG)\
|| (RED_LED) || (GREEN_LED)\
|| (NVM_ANGLE_STORE_FLG)\
|| (NVM_NORTH_DEBUG) || (NVM_SOUTH_DEBUG)\
|| (NVM_EAST_DEBUG) || (NVM_WEST_DEBUG)\
|| DIAG_DEBUG
  Serial.begin(9600);
#endif
}

/********************************************* STEP_FUNCTION ***************************************************/
  unsigned long currentMicros = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //Micros() overflow at 70mins which is a lot for vacumming area

  
  currentMicros = micros();
  
  if ((currentMicros - previousMillis) >= TIME_1MS) 
  {
    previousMillis = currentMicros;
    
    RobotControl_step();

    #if R_ENCODER_DEBUG == true
    Serial.print("RENC: ");
    Serial.println(RobotControl_B.rightEncoderTicks_uint16);
    #endif
    
    #if L_ENCODER_DEBUG == true
    Serial.print("LENC: ");
    Serial.println(RobotControl_B.leftEncoderTicks_uint16);
    #endif   
  }


#if LEFT_MOTOR_POS || LEFT_MOTOR_NEG || RIGHT_MOTOR_POS || RIGHT_MOTOR_NEG
  if (currentMicros - previousMillis_50 >= TIME_50MS)
  {
    previousMillis_50 = currentMicros;
    //OUTPUTS
    #if LEFT_MOTOR_POS == true
    Serial.print("LPP: ");
    Serial.println(RobotControl_B.leftPosPin);
    #endif
    
    #if LEFT_MOTOR_NEG == true
    Serial.print("LNP: ");
    Serial.println(RobotControl_B.leftNegPin);
    #endif
    
    #if RIGHT_MOTOR_POS == true
    Serial.print("RPP: ");
    Serial.println(RobotControl_B.rightPosPin);
    #endif
    
    #if RIGHT_MOTOR_NEG == true
    Serial.print("RNP: ");
    Serial.println(RobotControl_B.rightNegPin);
    #endif
  }
#endif

#if PUMPER_DEBUG
  if (currentMicros - previousMillis_100 >= TIME_100MS)
  {
    previousMillis_100 = currentMicros;
    #if PUMPER_DEBUG == true
    Serial.print("PH: ");
    Serial.println(RobotControl_B.pumperHit_BOOL);
    #endif
  }
#endif

#if COMPASS_DEBUG || ULSR_DEBUG || ULSL_DEBUG
  if (currentMicros - previousMillis_500 >= TIME_500MS)
  {
    previousMillis_500 = currentMicros;
    //INPUTS
    #if COMPASS_DEBUG == true
    Serial.print("COM: ");
    Serial.println(RobotControl_B.rawCompassValue);
    #endif
    
    #if ULSR_DEBUG == true
    Serial.print("ULSR: ");
    Serial.println(RobotControl_B.ULSR_cm);
    #endif
    
    #if ULSL_DEBUG == true
    Serial.print("ULSL: ");
    Serial.println(RobotControl_B.ULSL_cm);
    #endif
  }
#endif

#if RED_LED || GREEN_LED || NVM_ANGLE_STORE_FLG || NVM_NORTH_DEBUG\
|| NVM_SOUTH_DEBUG || NVM_EAST_DEBUG || NVM_WEST_DEBUG || DIAG_DEBUG
  if (currentMicros - previousMillis_2Sec >= TIME_2000MS)
  {
    previousMillis_2Sec = currentMicros;
    #if RED_LED == true
    Serial.print("RLED: ");
    Serial.println(RobotControl_B.redLED_BOOL);
    #endif
    
    #if GREEN_LED == true
    Serial.print("GLED: ");
    Serial.println(RobotControl_B.greenLED_BOOL);
    #endif 

    //NVM        
    #if NVM_ANGLE_STORE_FLG == true
    Serial.print("NVMF: ");
    Serial.println(RobotControl_B.NVM_AngleStoreFlg);
    #endif
    
    #if NVM_NORTH_DEBUG == true
    Serial.print("NVMN: ");
    Serial.println(RobotControl_B.NVM_NORTH);
    #endif
    
    #if NVM_SOUTH_DEBUG == true
    Serial.print("NVMS: ");
    Serial.println(RobotControl_B.NVM_SOUTH);
    #endif
    
    #if NVM_EAST_DEBUG == true
    Serial.print("NVME: ");
    Serial.println(RobotControl_B.NVM_EAST);
    #endif
    
    #if NVM_WEST_DEBUG == true
    Serial.print("NVMW: ");
    Serial.println(RobotControl_B.NVM_WEST);
    #endif  

    #if DIAG_DEBUG == true
    Serial.print("STUK: ");
    Serial.println(stuckHitFlg);

    Serial.print("LMFF: ");
    Serial.println(leftMotorFaultFlag);

    Serial.print("RMFF: ");
    Serial.println(rightMotorFaultFlag);

    Serial.print("ULS_LNCF: ");
    Serial.println(ULSL_NotConnectedFlag_BOOL);

    Serial.print("ULS_RNCF: ");
    Serial.println(ULSR_NotConnectedFlag_BOOL);

    Serial.print("COMFF: ");
    Serial.println(compFaultFlag);

    Serial.print("REDEF: ");
    Serial.println(rightEncoderDistErrorFlg);

    Serial.print("LEDEF: ");
    Serial.println(leftEncoderDistErrorFlg);
    Serial.println();
    #endif
  }
#endif
}

