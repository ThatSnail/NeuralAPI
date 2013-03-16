#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(NetworkParams* networkParams)
{
	this->networkParams = networkParams;
}


NeuralNetwork::~NeuralNetwork()
{
	delete networkParams;
}

float NeuralNetwork::getError()
{
	// TODO return real error
	return 0;
	vStack = vector<Neuron*>();
	//vStack.push_back(firstNeuron);
	while(vStack.size() > 0)
	{
		vStack.at(0)->fire(&vStack);
	}
}