#include "neural.hpp"

void Connector::connect(Model& model, std::string receptor, std::string layer)
{
	std::vector<NeuronBase *>* neurons1 = model.getLayer(receptor).getNeurons();
	std::vector<NeuronBase *>* neurons2 = model.getLayer(layer).getNeurons();

	for (auto n : *neurons1) {
		for (auto i : *neurons2) {
			n->addInput(i);
		}
	}
}

void Connector::connect(Model& model, NeuronBase& neuron, Layer& layer)
{
	std::vector<NeuronBase *>* neurons = layer.getNeurons();
}

void Connector::connect(Model& model, NeuronBase& neuron, std::string layer)
{
	std::vector<NeuronBase *>* neurons = model.getLayer(layer).getNeurons();
}

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

	neurons.emplace_back(new Neuron(neurons.size()));

	return *this;

}

Layer& Layer::addNeurons(int q) 
{
	while (q) {
		addNeuron();
		q--;
	}

	return *this;

}

Layer& Layer::addInput(std::string name, double value) 
{

	neurons.emplace_back(new NeuronInputValue(neurons.size(), value));

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