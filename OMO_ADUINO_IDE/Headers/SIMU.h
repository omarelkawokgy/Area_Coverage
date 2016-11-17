#ifdef ENABLE_SIMULATION
#ifndef SIMU_H
#define SIMU_H

#include "types.h"
#include "CONF.h"

class simu
{
public:
	//default constructor
	//simu(){};

	//printing map
	void printMap(Map m);

	//simu wheel turn
	void wheelTurn(Robot r);

	//robot bearing change
	void robotTurn(Robot r);

	void RemoveRobfromMap(Robot rob, Map m);
	
};
#endif
#endif
