#include "Pool.h"
#include "Params.h"
#include "NetworkParams.h"
#include "PoolResult.h"
#include "Board.h"
#include "BoardInput.h"
#include "BoardOutput.h"
#include <random>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));

	Board* board = new Board();

	Pool* pool = new Pool();

	Params params = Params();
	params.poolSize = 4;
	params.hiddenLayers = 4;
	params.hiddenNodes = 4;
	params.maxWeight = 1;

	vector<InputNeuron*>* vInputs = new vector<InputNeuron*>();
	vInputs->push_back(new BoardInput(board, 0, 0));
	vInputs->push_back(new BoardInput(board, 0, 1));
	vInputs->push_back(new BoardInput(board, 0, 2));
	vInputs->push_back(new BoardInput(board, 1, 0));
	vInputs->push_back(new BoardInput(board, 1, 1));
	vInputs->push_back(new BoardInput(board, 1, 2));
	vInputs->push_back(new BoardInput(board, 2, 0));
	vInputs->push_back(new BoardInput(board, 2, 1));
	vInputs->push_back(new BoardInput(board, 2, 2));

	vector<OutputNeuron*>* vOutputs = new vector<OutputNeuron*>();
	vOutputs->push_back(new BoardOutput());

	params.vInputs = vInputs;
	params.vOutputs = vOutputs;

	pool->init(params);
	PoolResult result = pool->run();

	system("pause");

	delete pool;

	vInputs->clear();
	delete vInputs;

	vOutputs->clear();
	delete vOutputs;

	delete board;
}