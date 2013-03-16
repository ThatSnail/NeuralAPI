#pragma once

#include "NetworkParams.h"

class NetworkResult
{
public:
	NetworkResult(void);
	~NetworkResult(void);

	NetworkParams* networkParams;
	float error;
};

