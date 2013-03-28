#include "NeuralNetwork.h"
#include "Board.h"
#include "BoardInput.h"

#include <iostream>

NeuralNetwork::NeuralNetwork(NetworkParams* networkParams)
{
	this->networkParams = networkParams;
}


NeuralNetwork::~NeuralNetwork()
{
	delete networkParams;
}

void NeuralNetwork::initNeurons()
{
	// make hidden neurons
	vector<vector<Neuron*>> hiddenNeurons = vector<vector<Neuron*>>();
	for(int i = 0; i < networkParams->hiddenLayers; i++)
	{
		vector<Neuron*> hiddenNeuronLayer = vector<Neuron*>();
		for(int j = 0; j < networkParams->hiddenNodes; j++)
		{
			hiddenNeuronLayer.push_back(new Neuron());
		}
		hiddenNeurons.push_back(hiddenNeuronLayer);
	}

	// vChildren
	{
		// first inputs to first hidden nodes
		for(int i = 0; i < networkParams->vInputs->size(); i++)
		{
			InputNeuron* inputNeuron = networkParams->vInputs->at(i);
			for(int j = 0; j < networkParams->hiddenNodes; j++)
			{
				inputNeuron->vChildren->push_back(hiddenNeurons.at(0).at(j));
			}
		}

		// map hidden children
		for(int i = 0; i < hiddenNeurons.size() - 1; i++)
		{
			vector<Neuron*> layer = hiddenNeurons.at(i);
			for(int j = 0; j < layer.size(); j++)
			{
				Neuron* neuron = layer.at(j);
				for(int k = 0; k < layer.size(); k++)
				{
					Neuron* childNeuron = hiddenNeurons.at(i + 1).at(k);
					neuron->vChildren->push_back(childNeuron);
				}
			}
		}
	
		// last hidden row to outputs
		vector<Neuron*> layer = hiddenNeurons.at(networkParams->hiddenLayers - 1);
		for(int i = 0; i < layer.size(); i++)
		{
			Neuron* neuron = layer.at(i);
			for(int j = 0; j < networkParams->vOutputs->size(); j++)
			{
				neuron->vChildren->push_back((Neuron*)networkParams->vOutputs->at(j));
			}
		}
	}

	// vInputs
	{
		// first hidden row to inputs
		vector<Neuron*> layer = hiddenNeurons.at(0);
		for(int i = 0; i < networkParams->hiddenNodes; i++)
		{
			for(int j = 0; j < networkParams->vInputs->size(); j++)
			{
				ActionPotential* ap = new ActionPotential((Neuron*)networkParams->vInputs->at(j), networkParams->inputWeightArray[j][i]);
				layer.at(i)->vInputs->push_back(ap);
			}
		}

		// hidden neurons to previous hidden neurons
		for(int i = 1; i < networkParams->hiddenLayers; i++)
		{
			vector<Neuron*> layer = hiddenNeurons.at(i);
			for(int j = 0; j < layer.size(); j++)
			{
				Neuron* neuron = layer.at(j);
				vector<Neuron*> prevLayer = hiddenNeurons.at(i - 1);
				for(int k = 0; k < prevLayer.size(); k++)
				{
					ActionPotential* ap = new ActionPotential(prevLayer.at(k), networkParams->weightArray[i-1][k][j]);
					neuron->vInputs->push_back(ap);
				}
			}
		}

		// output neurons to last hidden neurons
		for(int i = 0; i < networkParams->vOutputs->size(); i++)
		{
			Neuron* outputNeuron = (Neuron*)networkParams->vOutputs->at(i);
			for(int j = 0; j < networkParams->hiddenNodes; j++)
			{
				Neuron* hiddenNeuron = hiddenNeurons.at(networkParams->hiddenLayers - 1).at(j);
				ActionPotential* ap = new ActionPotential(hiddenNeuron, networkParams->outputWeightArray[j][i]);
				outputNeuron->vInputs->push_back(ap);
			}
		}
	}

	// cleanup
	hiddenNeurons.clear();
}

float NeuralNetwork::getError()
{
	// custom
	Board* board = ((BoardInput*)networkParams->vInputs->at(0))->board;

	// clear board first
	board->reset();

	int result = -1;
	while(true)
	{
		// set outputs
		runNetwork();

		// get outputs and make a move
		int move = floor(networkParams->vOutputs->at(0)->output);
		int spacesLeft = board->getSpacesLeft();
		move %= spacesLeft;
		while(move < 0){move += spacesLeft;}
		board->moveOffset(move);
		cout << "SPACES LEFT: " << spacesLeft << endl;
		cout << "COMPUTER MOVED: " << move << endl;
		//board->move(move % 3, floor((double)move / 3));

		// TODO check wincon
		switch(board->getResult())
		{
		case Board::X:
			result = 0;
			break;
		case Board::DRAW:
			result = 1;
			break;
		case Board::O:
			result = 2;
			break;
		}
		if(result != -1)
			break;

		// TODO enemy move
		board->moveOptimal();

		// TODO check wincon
		switch(board->getResult())
		{
		case Board::X:
			result = 0;
			break;
		case Board::DRAW:
			result = 1;
			break;
		case Board::O:
			result = 2;
			break;
		}
		if(result != -1)
			break;
	}
	cout << "RESULT: " << result << endl;
	return result;
}

void NeuralNetwork::runNetwork()
{
	vStack = vector<Neuron*>();
	for(int i = 0; i < networkParams->vInputs->size(); i++)
	{
		vStack.push_back((Neuron*)networkParams->vInputs->at(i));
	}
	while(vStack.size() > 0)
	{
		vStack.at(0)->fire(&vStack);
	}
}