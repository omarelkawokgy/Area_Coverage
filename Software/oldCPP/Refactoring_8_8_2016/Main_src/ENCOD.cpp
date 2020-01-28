#include "Project_Path.h"
#include RELATIVE_PATH(ENCOD.h)
#include RELATIVE_PATH(ERRH.h)
#include RELATIVE_PATH(Main_Func_1.h)
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

Boolean right_encoder::read_right_encoder_ticks(void)
{
	Boolean SingleStepComplete = RET_NOT_OK;
	uint16 current_encoder_status = UINT_SNA;
	uint16 counter_ticks = UINT_SNA;

	while ((counter_ticks < ROBOT_SINGLE_STEP) && (BumperHit == FALSE))
	{
		current_encoder_status = analogRead(ANALOG_PIN_ZERO);

		while ((CHECK_IF_HIGH(current_encoder_status)) && (BumperHit == FALSE))
		{
			current_encoder_status = analogRead(ANALOG_PIN_ZERO);
			if (CHECK_IF_LOW(current_encoder_status))
			{
				counter_ticks++;
#if 0 
				Serial.print("Counter Ticks: ");
				Serial.println(counter_ticks);
#endif
			}
		}
	}

	if (counter_ticks >= ROBOT_SINGLE_STEP)
	{
		SingleStepComplete = RET_OK;
	}
	else
	{
		ERRH::Error_logErrorClass(WARNING_ENCOD_NOT_COMPLETE_STEP);
	}

 return SingleStepComplete;
}

#endif
