#include "Project_Path.h"
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Main_Func_1.h)
#undef PROJECT_PATH_H

void ERRH::Error_logErrorClass(Errortype ErrorClass)
{
	if (ErrorClass == ERROR_MAP_ACCESS_OUT_OF_BOUND)
	{
		BumperHit = TRUE;
	}
	Serial.println(ErrorClass, HEX);
}
