#pragma once

#include "Neuron.h"

class Neuron;
class InputNeuron;
class OutputNeuron;

class ActionPotential
{
public:
	Neuron* neuron;
	float weight;
	ActionPotential(Neuron* neuron, float weight);
};

