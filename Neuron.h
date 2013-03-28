#pragma once

#include <vector>
#include "ActionPotential.h"

using namespace std;

class InputNeuron;
class ActionPotential;

class OutputNeuron;

class Neuron
{
protected:
	float threshold;
	float activationFunction(float sum);

public:
	Neuron(void);
	~Neuron(void);

	float output;

	vector<ActionPotential*>* vInputs;
	vector<Neuron*>* vChildren;

	virtual void fire(vector<Neuron*>* vStack);
};

