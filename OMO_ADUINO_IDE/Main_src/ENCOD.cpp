#include "Project_Path.h"
#include RELATIVE_PATH(ENCOD.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Main_Func_1.h)
#include RELATIVE_PATH(MOVH.h)
#undef PROJECT_PATH_H


//static volatile Boolean left_Encoder_flag = FALSE;
#ifdef OLD_ENCODER_DESIGN
left_encoder& left_encoder::getInstance(ENCODER_UINT8 ticks)
{
	static left_encoder left_device;
	left_device.left_encoder_ticks = ticks;
	return left_device;
}

void left_encoder::incrementTick(void)
{
	left_encoder_ticks++;
}

void left_encoder::read_left_encoder_ticks(ENCODER_UINT8* ticks)
{
	ticks = &left_encoder_ticks;
}
#else

right_encoder::right_encoder()
{

}

right_encoder& right_encoder::getInstance()
{
	static right_encoder encoder;
	return encoder;
}

uint16 right_encoder::read_right_encoder_ticks()
{
			return analogRead(ANALOG_PIN_ZERO);
}

return_type right_encoder::checkConnection(void)
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
#endif
