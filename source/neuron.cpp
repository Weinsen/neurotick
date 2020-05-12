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

/**
 * @brief      Constructs a new instance.
 */
Neuron::Neuron()
{

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

double Neuron::output() const
{
	return value;
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  v     { parameter_description }
 */
NeuronInputValue::NeuronInputValue(double v)
{
	value = v;
}

double NeuronInputValue::output() const
{
	return value;
}

NeuronInputValue& NeuronInputValue::calculate()
{
	return *this;
}