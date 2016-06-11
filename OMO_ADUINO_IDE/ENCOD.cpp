#include "ENCOD.h"

static volatile Boolean left_Encoder_flag = FALSE;

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
void left_encoder::L_encoder(void)
{
	left_Encoder_flag = TRUE;
}

Boolean left_encoder::get_L_encoder_flag(void)
{
	return left_Encoder_flag;
}
#endif