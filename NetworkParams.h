#pragma once

#include <vector>
#include "Params.h"
#include "InputNeuron.h"
#include "OutputNeuron.h"

class InputNeuron;

using namespace std;

class Params;
class InputNeuron;
class OutputNeuron;

class NetworkParams
{
private:
	static const int PRECISION = 6; // random number digit count

public:
	NetworkParams();
	NetworkParams(Params* params);
	~NetworkParams();

	int hiddenLayers;
	int hiddenNodes;
	float maxWeight;

	float** inputWeightArray;
	float** outputWeightArray;
	float*** weightArray;

	vector<InputNeuron*>* vInputs;
	vector<OutputNeuron*>* vOutputs;
};

