
//#undef MATLAB_MEX_FILE
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\blinkTest.h"
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\Blink.h"
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\Blink.c"
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\blinkTest.c"
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\blinkTest_private.h"
//#include "C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\Normal_ERT_blinkTest_ert_rtw\I_O_Wrapper.h"

#define PROJECT_ROOT C:\Projects\myProject\CleanerRepo\Area_Coverage\Software\SourceCode\AreaCoverage_MBD\SW\MBD_Test\blinkTest_ert_rtw
#define TO_STRING(s) #s
#define ABSOLUTE_PATH(root, relative_path) TO_STRING(root\relative_path)
#define RELATIVE_PATH(library) ABSOLUTE_PATH(PROJECT_ROOT, library)

int x;

#include RELATIVE_PATH(blinkTest.h)
#include RELATIVE_PATH(blinkTest.c)
#include RELATIVE_PATH(Blink.h)
#include RELATIVE_PATH(Blink.c)
#include RELATIVE_PATH(blinkTest_private.h)

unsigned long previousMillis = 0; 

void setup() {
//  // put your setup code here, to run once:
blinkTest_initialize();
pinMode(LED_BUILTIN, OUTPUT);
}
//
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = micros();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    blinkTest_step();
  }
  x = analogRead(A2);
}
