#ifndef ENCODER_H
#define ENCODER_H

#include "CONF.h"
#include "Main_Func_1.h"

class left_encoder
{
#ifdef OLD_ENCODER_DESIGN
private:
	V_ENCODER_UINT8 left_encoder_ticks;

	left_encoder(){}

	left_encoder(ENCODER_UINT16 left_encoder_local)
	{
		left_encoder_ticks = left_encoder_local;
	}
public:
	static left_encoder& getInstance(uint8 ticks);

	void incrementTick(void);

	void read_left_encoder_ticks(ENCODER_UINT8* ticks);
#else
public:
	static void L_encoder(void);
	static Boolean get_L_encoder_flag(void);
#endif
};

#ifdef SINGLE_ENCODER_ROBOT
class right_encoder
{
private:
	V_ENCODER_UINT16 right_encoder_ticks;

	right_encoder(){}

	right_encoder(V_ENCODER_UINT16 right_encoder_local)
	{
		right_encoder_ticks = right_encoder_local;
	}
public:
	static right_encoder& getInstance(void);

	void incrementTick(void);

static Boolean read_right_encoder_ticks(void);

static Boolean CheckConnection(void);
};
#endif

#endif
