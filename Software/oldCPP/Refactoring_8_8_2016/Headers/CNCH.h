#ifndef CNCH_H
#define CNCH_H

#include "types.h"
#include "CONF.h"

#define CW_CHECK 1
#define CCW_CHECK 0

class CNCH
{
private:
	return_type CheckResult = RET_NOT_OK;

	return_type Motor_CheckConnection(const Boolean CW_CHECK_VAR);

	return_type ULS_CheckConnnection(void);

	return_type ENCOD_CheckConnection(void);

	return_type COMP_CheckConnection(void);

	return_type check_DevicesConnection(void);
public:
	CNCH();

	return_type Get_CheckResult(void);
};

#endif
