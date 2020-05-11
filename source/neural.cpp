#include "neural.hpp"

double NeuronBase::output()  const
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

double Neuron::output()
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

Layer& Layer::addNeuron(NeuronBase *neuron) 
{

	neurons.push_back(neuron);

	return *this;

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
		l->calculate();
	}

	return *this;

}

Model& Model::addLayer(Layer *layer) 
{

	layers.push_back(layer);

	return *this;

}