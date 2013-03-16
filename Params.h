#pragma once
class Params
{
public:
	Params();
	~Params();

	// pool params
	int poolSize;

	// network params
	int hiddenLayers;
	int hiddenNodes;
	int inputNodes;
	int outputNodes;
	float maxWeight;
};

