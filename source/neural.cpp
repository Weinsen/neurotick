#include "neural.hpp"

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
Layer::Layer() 
{

}

Layer& Layer::calculate() 
{

	for (auto n : neurons) {
		n->calculate();
	}

	return *this;

}

Layer& Layer::addNeuron() 
{

	neurons.emplace_back(new Neuron());

	return *this;

}

Layer& Layer::addNeurons(int q) 
{
	while (q) {
		neurons.emplace_back(new Neuron());
		q--;
	}

	return *this;

}

Layer& Layer::addInput(std::string name, double value) 
{

	neurons.emplace_back(new NeuronInputValue(value));

	return *this;

}

std::vector<NeuronBase *>* Layer::getNeurons()
{
	return &neurons;
}

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
Model::Model() 
{

}

Model& Model::calculate() 
{

	for (auto l : layers) {
		l.second.calculate();
	}

	return *this;

}

Model& Model::addLayer(std::string name) 
{

	Layer layer;
	layers[name] = layer;

	return *this;

}

Layer& Model::getLayer(std::string name) 
{

	return layers[name];

}