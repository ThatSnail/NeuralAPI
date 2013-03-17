#include "Pool.h"
#include "Params.h"
#include "NetworkParams.h"
#include "PoolResult.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	Pool* pool = new Pool();

	Params params = Params();
	params.poolSize = 1;
	params.hiddenLayers = 1;
	params.hiddenNodes = 1;
	params.inputNodes = 1;
	params.outputNodes = 1;
	params.maxWeight = 1;

	pool->init(params);
	PoolResult result = pool->run();

	system("pause");

	delete pool;
}