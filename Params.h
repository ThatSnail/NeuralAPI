#pragma once

#include <vector>
#include "InputNeuron.h"
#include "OutputNeuron.h"

using namespace std;

class InputNeuron;
class OutputNeuron;
class NetworkParams;

class Params
{
public:
	Params();
	~Params();

	// pool params
	int poolSize;
	vector<InputNeuron*>* vInputs;
	vector<OutputNeuron*>* vOutputs;

	// network params
	int hiddenLayers;
	int hiddenNodes;
	float maxWeight;
};

