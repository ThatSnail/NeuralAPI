#pragma once

#include "Neuron.h"

class Neuron;

class ActionPotential
{
public:
	Neuron* neuron;
	float weight;
	ActionPotential(Neuron* neuron, float weight);
};

