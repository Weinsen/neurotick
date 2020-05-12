#include "neural.hpp"
#include "neuron.hpp"

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
}


Neuron& Neuron::addInput(const NeuronBase *input, double weight)
{
	NeuronInput i = {
		input,
		weight
	};
	inputs.push_back(i);

	return *this;
}

Neuron& Neuron::calculate()
{
	double output = 0;
	for (auto n : inputs) {
		output += n.neuron->output() * n.w;
	}
	value = output;
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
	out << "Neuron(ID:" << id << ",Output:" << value << ",Inputs:" << inputs.size() << ")" << std::endl;
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  v     { parameter_description }
 */
NeuronInputValue::NeuronInputValue(int i, double v)
{
	value = v;
	id = i;
}

double NeuronInputValue::output() const
{
	return value;
}

NeuronInputValue& NeuronInputValue::calculate()
{
	return *this;
}

NeuronInputValue& NeuronInputValue::set(double v)
{
	value = v;

	return *this;
}

std::ostream& NeuronInputValue::serialize(std::ostream& out) const
{
	out << "NeuronInputValue(ID:" << id << ")" << std::endl;
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