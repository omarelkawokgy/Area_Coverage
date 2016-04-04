#include "ENCOD.h"

left_encoder& left_encoder::getInstance(void)
{
	static left_encoder(left_encoder_ticks);

}

void left_encoder::incrementTick(void)
{
	left_encoder_ticks++;
}

void left_encoder::read_left_encoder_ticks(ENCODER_UINT16* ticks)
{
	ticks = &left_encoder_ticks;
}
