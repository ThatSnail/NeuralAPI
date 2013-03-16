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
	params.poolSize = 128;
	params.hiddenLayers = 4;
	params.hiddenNodes = 4;
	params.inputNodes = 2;
	params.outputNodes = 2;
	params.maxWeight = 1;

	pool->init(params);
	PoolResult result = pool->run();

	system("pause");

	delete pool;
}