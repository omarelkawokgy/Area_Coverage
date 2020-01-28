#ifndef COMH_H
#define COMH_H
#include "types.h"
#include "CONF.h"
#include <HMC5883L.h>
#include <Wire.h>

typedef uint16 angle;

 /*values of directions*/
extern uint16 NORTH_VALUE;
extern uint16 WEST_VALUE;
extern uint16 SOUTH_VALUE;
extern uint16 EAST_VALUE;

class Comp
{
private:

public:
	Comp();

  static void InitializeDirections(void);

	static Heading ReadComp(void);
	
	static uint16 ReadRawData(void);

  static Boolean CheckConnection(void);
};
#endif
