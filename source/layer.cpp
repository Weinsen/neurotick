#include "layer.hpp"

namespace neurotick {

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

Layer& Layer::input(std::vector<double> input) 
{
	int i = 0;
	for (auto n : neurons) {
		n->set(input[i++]);
	}

	return *this;

}

Layer& Layer::addNeuron() 
{

	neurons.emplace_back(new Neuron(neurons.size()));

	return *this;

}

Layer& Layer::addNeuron(const NeuronBase& neuron)
{
	neurons.emplace_back(new Neuron(neuron));

	return *this;
}

Layer& Layer::addNeuron(std::string name, double value) 
{
	NeuronBase *nptr = new Neuron(neurons.size(), name, value);
	neurons.emplace_back(nptr);
	model.addNamed(name, nptr);

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

int Layer::size()
{
	return neurons.size();
}

std::string Layer::getName()
{
	return name;
}

std::vector<NeuronBase *>& Layer::getNeurons()
{
	return neurons;
}

std::vector<double> Layer::output()
{
	std::vector<double> out;
	for (auto n : neurons) {
		out.push_back(n->output());
	}
	return out;	
}

std::ostream& operator<< (std::ostream& os, const Layer& obj)
{
	return obj.print(os);
}

std::ostream& Layer::print(std::ostream& out) const
{
	out << "Layer(Name:" << name << ")" << std::endl;
	for (auto n : neurons) {
		out << *n << std::endl;
	}
	return out;
}

Layer& Layer::operator= (Layer& obj)
{
	if (this != &obj) {
		for (auto n : obj.getNeurons()) {
			addNeuron(*n);
		}
	}
	return *this;
}

}
