#include "neural.hpp"
#include "neuron.hpp"

NeuronBase::NeuronBase() : id(0), name(""), value(0)
{

}

NeuronBase::NeuronBase(const NeuronBase& neuron)
{
	id = neuron.id;
	name = neuron.name;
	value = neuron.value;
}

double NeuronBase::output() const
{
	return 0;
}

NeuronBase& NeuronBase::calculate() 
{
	return *this;
}

NeuronBase& NeuronBase::set(double v)
{
	return *this;
}

std::ostream& NeuronBase::serialize(std::ostream& out) const
{
	out << "NeuronBase" << std::endl;
}

/**
 * @brief      Constructs a new instance.
 */
Neuron::Neuron(int i)
{
	id = i;
	name = "";
}

Neuron::Neuron(int i, std::string label)
{
	id = i;
	name = label;
}

Neuron::Neuron(int i, std::string label, double v)
{
	id = i;
	name = label;
	value = v;
}

Neuron::Neuron(const NeuronBase &neuron)
{
	id = neuron.id;
	name = neuron.name;
	value = neuron.value;
}

Neuron& Neuron::addInput(const NeuronBase *input, double weight)
{
	if (weight == 0) {
		return *this;
	}

	NeuronInput i = {
		input,
		weight
	};
	inputs.push_back(i);

	return *this;
}

Neuron& Neuron::calculate()
{
	if (inputs.size() > 0) {
		double v = 0;
		for (auto n : inputs) {
			v += n.neuron->output() * n.w;
		}
		value = 1 / (1 + exp(-v));
	} 
	return *this;
}

Neuron& Neuron::bias(double bias)
{
	b = bias;

	return *this;
}

Neuron& Neuron::set(double v)
{
	return *this;
}

double Neuron::output() const
{
	return value;
}

std::ostream& Neuron::serialize(std::ostream& out) const
{
	out << "Neuron(ID:" << id;

	if (name != "") {
		out << ",Name:\"" << name << "\"";
	}

	out << ",Output:" << value << ",Inputs:" << inputs.size() << ")" << std::endl;
}

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os    The operating system
 * @param[in]  obj   The object
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator<< (std::ostream& os, const NeuronBase& obj)
{
	return obj.serialize(os);
}