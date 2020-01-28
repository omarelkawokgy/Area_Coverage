#include "Project_Path.h"
#include RELATIVE_PATH(CNCH.h)
#include RELATIVE_PATH(MOVH.h)
#include RELATIVE_PATH(COMH.h)
#include RELATIVE_PATH(ULSH.h)
#include RELATIVE_PATH(ENCOD.h)
#include RELATIVE_PATH(ERRH.h)
#undef PROJECT_PATH_H

CNCH::CNCH()
{
	
}

return_type CNCH::Get_CheckResult(void)
{
	CheckResult = check_DevicesConnection();
	return CheckResult;
}

return_type CNCH::check_DevicesConnection(void)
{
	return_type ErrorCheck = RET_OK;


	ErrorCheck &= Motor_CheckConnection(CW_CHECK);
	ErrorCheck &= ENCOD_CheckConnection();
	ErrorCheck &= COMP_CheckConnection();
	delay(400);
	ErrorCheck &= Motor_CheckConnection(CCW_CHECK);
	delay(500);
	MOVE::MoveStop();
	ErrorCheck &= ULS_CheckConnnection();

	return ErrorCheck;
}

return_type CNCH::Motor_CheckConnection(const Boolean CW_CHECK_VAR)
{
	Boolean ret = RET_NOT_OK;
	if (CW_CHECK_VAR == CW_CHECK)
	{
		MOVE::SetMotorPins(LOW_PWM, HIGH_PWM, HIGH_PWM, LOW_PWM);
		ret = RET_OK;
	}
	else
	{
		MOVE::SetMotorPins(HIGH_PWM, LOW_PWM, LOW_PWM, HIGH_PWM);
		ret = RET_OK;
	}

	if (ret == RET_NOT_OK)
	{
		ERRH::Error_logErrorClass(ERROR_MOVE_MOTORS_NC);
	}
	return ret;
}

return_type CNCH::ULS_CheckConnnection(void)
{
	return_type ErrorCheck = RET_OK;
	uint16 ReadDist = UINT_SNA;

	ReadDist = ULSH::ULS_getLeftDist();
	ReadDist += ULSH::ULS_getRightDist();

	if (ReadDist == 0)
	{
		ErrorCheck = RET_NOT_OK;
		ERRH::Error_logErrorClass(ERROR_ULSH_ULSL_NC);
	}
	return ErrorCheck;
}

return_type CNCH::ENCOD_CheckConnection(void)
{
	return_type ret = RET_NOT_OK;
	uint8 current_encoder_status = 0;
	uint16 Timer = 0;

	current_encoder_status = analogRead(ANALOG_PIN_ZERO);
	while ((CHECK_IF_HIGH(current_encoder_status)) && (Timer > 5000))
	{
		current_encoder_status = analogRead(ANALOG_PIN_ZERO);
		if (CHECK_IF_LOW(current_encoder_status))
		{
			ret = RET_OK;
		}
		Timer++;
	}
	if (ret == RET_NOT_OK)
	{
		ERRH::Error_logErrorClass(ERROR_ENCOD_ENCODER_NC);
	}
	return ret;
}

return_type CNCH::COMP_CheckConnection(void)
{
	return_type ret = RET_NOT_OK;
	uint16 TempAngle = UINT_SNA;
	uint16 CurrentAngle = UINT_SNA;

	TempAngle = Comp::ReadRawData();
	delay(100);
	CurrentAngle = Comp::ReadRawData();

	if (TempAngle != CurrentAngle)
	{
		ret = RET_OK;
	}
	else
	{
		ERRH::Error_logErrorClass(ERROR_COMH_COMPASS_NC);
	}
	return ret;
}
