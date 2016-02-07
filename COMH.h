#ifndef COMH_H
#define COMH_H
#include "types.h"
#include "CONF.h"

typedef uint16 angle;

class Comp
{
private:

public:
	Comp();

	static Heading ReadComp(uint16 Temp_angle);
};
#endif
