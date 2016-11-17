#ifndef ENCODER_H
#define ENCODER_H

#include "types.h"
#include "CONF.h"


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
	friend class positionHeadingHandler;
public:
	right_encoder();

	static right_encoder& getInstance(void);

	void incrementTick(void);

	uint16 read_right_encoder_ticks();

	return_type checkConnection(void);

};
#endif

#endif


