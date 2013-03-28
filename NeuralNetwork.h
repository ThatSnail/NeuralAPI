#pragma once

#include "Neuron.h"
#include "NetworkParams.h"
#include <vector>

using namespace std;
class Neuron;
class NetworkParams;
class InputNeuron;

class NeuralNetwork
{
private:
	vector<Neuron*> vStack;
public:
	NeuralNetwork(NetworkParams* networkParams);
	~NeuralNetwork();

	NetworkParams* networkParams;
	void initNeurons();
	void runNetwork();

	float getError();
};

