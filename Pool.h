#pragma once

#include <vector>
#include "NeuralNetwork.h"
#include "Params.h"
#include "PoolResult.h"

using namespace std;

class Pool
{
private:
	vector<NeuralNetwork*> pool;

public:
	Pool();
	~Pool();
	void init(Params params);

	PoolResult run();
};

