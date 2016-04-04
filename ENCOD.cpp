#include "ENCOD.h"



left_encoder& left_encoder::getInstance(ENCODER_UINT16 ticks)
{
	static left_encoder left_device;
	left_device.left_encoder_ticks = ticks;
	return left_device;
}

void left_encoder::incrementTick(void)
{
	left_encoder_ticks++;
}

void left_encoder::read_left_encoder_ticks(ENCODER_UINT16* ticks)
{
	ticks = &left_encoder_ticks;
}
