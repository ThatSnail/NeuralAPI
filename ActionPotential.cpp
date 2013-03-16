#include "ActionPotential.h"

ActionPotential::ActionPotential(Neuron* neuron, float weight)
{
	this->neuron = neuron;
	this->weight = weight;
}