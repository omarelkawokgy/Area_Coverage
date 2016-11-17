#ifndef ULSH_H
#define ULSH_H

#include "types.h"
#include "CONF.h"

class ULSH
{
private:
	ULSH();

	friend class RobotDevice;
public:

	static ULSH& getInstanceLeft(void);

	static ULSH& getInstanceRight(void);

	uint16 ULS_getLeftDist(void);

	uint16 ULS_getRightDist(void);

	L_R_Dist ULS_getDistanceboth(void);

	return_type CheckConnnection(void);
};

#endif
