#include "Pool.h"
#include "NetworkResult.h"

Pool::Pool()
{
	pool = vector<NeuralNetwork*>();
}

Pool::~Pool()
{
	for(int i = 0; i < pool.size(); i++)
	{
		delete pool.at(i);
	}
	pool.clear();
}

void Pool::init(Params params)
{
	// clear pool
	for(int i = 0; i < pool.size(); i++)
	{
		delete pool.at(i);
	}
	pool.clear();

	// reinitialize pool
	for(int i = 0; i < params.poolSize; i++)
	{
		// make a bunch of neural networks with weights initialized to a random number from -maxWeight to maxWeight
		Params* newParams = new Params(params);
		NetworkParams* networkParams = new NetworkParams(newParams);
		NeuralNetwork* neuralNetwork = new NeuralNetwork(networkParams);
		pool.push_back(neuralNetwork);
	}
}

PoolResult Pool::run()
{
	NetworkParams* minParams;
	float minError = INT_MAX;
	for(int i = 0; i < pool.size(); i++)
	{
		NeuralNetwork* neuralNetwork = pool.at(i);

		float error = neuralNetwork->getError();

		if(error <= minError)
		{
			minParams = neuralNetwork->networkParams;
			minError = error;
		}
	}
	PoolResult poolResult = PoolResult();
	poolResult.networkParams = minParams;
	poolResult.error = minError;

	return poolResult;
}