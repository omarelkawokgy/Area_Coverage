#include "ENCOD.h"


#define MIDDLE 100
#define CHECK_IF_LOW(X) (X < MIDDLE)?TRUE:FALSE
#define CHECK_IF_HIGH(X) (X > MIDDLE)?TRUE:FALSE
#define ANALOG_PIN_ZERO 0
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
	uint8 counter_ticks = UINT_SNA;

	while ((counter_ticks < ROBOT_SINGLE_STEP) && (BumperHit == FALSE))
	{
		current_encoder_status = analogRead(ANALOG_PIN_ZERO);

		while ((CHECK_IF_HIGH(current_encoder_status)) && (BumperHit == FALSE))
		{
			current_encoder_status = analogRead(ANALOG_PIN_ZERO);
			if (CHECK_IF_LOW(current_encoder_status))
			{
				counter_ticks++;
				Serial.print("Counter Ticks: ");
				Serial.println(counter_ticks);
			}
		}
	}

	if (counter_ticks >= ROBOT_SINGLE_STEP)
	{
		SingleStepComplete = RET_OK;
	}

 return SingleStepComplete;
}

Boolean right_encoder::CheckConnection(void)
{
  Boolean ret = RET_NOT_OK;
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
    return ret;
}
#endif
