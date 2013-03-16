#pragma once

#include <vector>
#include "ActionPotential.h"
#include "NeuralNetwork.h"

using namespace std;

class ActionPotential;
class NeuralNetwork;

class Neuron
{
private:
	vector<ActionPotential> vInputs;
	vector<Neuron*> vChildren;
	float threshold;
	float output;
	float activationFunction(float sum);

public:
	Neuron(void);
	~Neuron(void);

	void fire(vector<Neuron*>* vStack);

	void initChildren(NeuralNetwork* network);
};

