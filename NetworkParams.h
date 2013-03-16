#pragma once

#include "Params.h"

class NetworkParams
{
private:
	int hiddenLayers;
	int hiddenNodes;
	int inputNodes;
	int outputNodes;
	float maxWeight;

	static const int PRECISION = 6; // random number digit count

public:
	NetworkParams();
	NetworkParams(Params* params);
	~NetworkParams(void);

	float** inputWeightArray;
	float** outputWeightArray;
	float*** weightArray;
};

