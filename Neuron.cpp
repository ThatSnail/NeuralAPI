#include "Neuron.h"
#include <cmath>

Neuron::Neuron(void)
{
	vInputs = new vector<ActionPotential*>();
	vChildren = new vector<Neuron*>();
}


Neuron::~Neuron(void)
{
	for(int i = 0; i < vInputs->size(); i++)
	{
		delete vInputs->at(i);
	}
	vInputs->clear();
	delete vInputs;
	vChildren->clear();
	delete vChildren;
}

void Neuron::fire(vector<Neuron*>* vStack)
{
	float sum = 0;
	for(unsigned int i = 0; i < vInputs->size(); i++)
	{
		ActionPotential* ap = vInputs->at(i);
		sum += ap->neuron->output * ap->weight;
	}
	output = activationFunction(sum);

	vStack->erase(vStack->begin());
	for(unsigned int i = 0; i < vChildren->size(); i++)
	{
		vStack->push_back(vChildren->at(i));
	}
}

float Neuron::activationFunction(float sum)
{
	return tanh(sum);
}