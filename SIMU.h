#ifndef SIMU_H
#define SIMU_H

#include "MapHandler.h"

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
	
};
#endif
