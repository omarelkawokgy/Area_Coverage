#ifndef COMH_H
#define COMH_H
#include "types.h"
#include <HMC5883L.h>
#include <Wire.h>
#include "CONF.h"

 /*values of directions*/
extern uint16 NORTH_VALUE;
extern uint16 WEST_VALUE;
extern uint16 SOUTH_VALUE;
extern uint16 EAST_VALUE;

class Comp
{
private:

	friend class positionHeadingHandler;
public:
	Comp();
	static Comp& getInstance(void);

	void InitializeDirections(void);

	Heading ReadComp(void);
	
	uint16 ReadRawData(void);

	return_type CheckConnection(void);

};
#endif
