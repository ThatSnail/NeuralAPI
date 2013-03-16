#pragma once

#include "NetworkParams.h"

class PoolResult
{
public:
	NetworkParams networkParams;
	float error;

	PoolResult(void);
	~PoolResult(void);
};

