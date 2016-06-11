#ifndef ULSH_H
#define ULSH_H

#include "CONF.h"
#include "types.h"

class ULSH
{
private:
       
public:
	ULSH();

	static uint16 ULS_getLeftDist(void);

	static uint16 ULS_getRightDist(void);

	static L_R_Dist ULS_getDistanceboth(void);
};

#endif
