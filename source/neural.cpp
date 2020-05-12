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

void Connector::connect(Model& model, const char *receptor, const char *layer)
{
	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

	for (auto n : *neurons1) {
		for (auto i : *neurons2) {
			n->addInput(i);
		}
	}
}

void Connector::connect(Model& model, const char *receptor, const char *layer, std::vector<double> *weights)
{
	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

	for (auto n : *neurons1) {
		int i=0;
		for (auto w : *weights) {
			n->addInput((*neurons2)[i], w);
			i++;
		}
	}
}

void Connector::connect(Model& model, const char *receptor, const char *layer, std::vector<std::vector<double>> *weights)
{
	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

	int i=0;
	for (auto n : *weights) {
		int j=0;
		for (auto w : n) {
			if (w != 0) {
				(*neurons1)[i]->addInput((*neurons2)[j], w);
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
Layer::Layer(Model& model, std::string name) : model(model), name(name)
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
	NeuronBase *nptr = new NeuronInputValue(neurons.size(), value);
	neurons.emplace_back(nptr);
	model.addNamed(name, nptr);

	return *this;
}

Layer& Layer::addNamed(std::string name) 
{
	NeuronBase *nptr = new Neuron(neurons.size());
	neurons.emplace_back(nptr);
	model.addNamed(name, nptr);

	return *this;
}

std::vector<NeuronBase *>* Layer::getNeurons()
{
	return &neurons;
}

std::ostream& operator<< (std::ostream& os, const Layer& obj)
{
	return obj.serialize(os);
}

std::ostream& Layer::serialize(std::ostream& out) const
{
	out << "Layer(Name:" << name << ")" << std::endl;
	for (auto n : neurons) {
		out << "\t" << *n;
	}
	return out;
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
		l.second->calculate();
	}

	return *this;

}

Model& Model::addLayer(std::string name) 
{

	layers[name] = (new Layer(*this, name));

	return *this;

}

Model& Model::addNamed(std::string name, NeuronBase *neuron) 
{
	namedNeurons[name] = neuron;

	return *this;
}

Layer& Model::getLayer(std::string name) 
{
	return *(layers[name]);
}

NeuronBase& Model::getNamedNeuron(std::string name)
{
	return *(namedNeurons[name]);	
}

