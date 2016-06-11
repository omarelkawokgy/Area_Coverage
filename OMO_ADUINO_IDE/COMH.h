#include <HMC5883L.h>
#include <Wire.h>

#ifndef COMH_H
#define COMH_H
#include "types.h"
#include "CONF.h"
#include "HMC5883L.h"


typedef uint16 angle;

class Comp
{
private:

public:
	Comp();

	static Heading ReadComp(void);
	
	static uint16 ReadRawData(void);
};
#endif
