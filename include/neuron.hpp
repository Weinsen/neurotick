#ifndef NEURON_HPP
#define NEURON_HPP

#include "neural.hpp"

class Neuron;
class NeuronBase;
class NeuronInputValue;

typedef struct {
	const NeuronBase *neuron;
	double w;
} NeuronInput;


/**
 * @brief      This class describes a neuron base.
 */
class NeuronBase {

	protected:

		double value{0};

	public:

		virtual double output() const;
		virtual NeuronBase& calculate();
		
		virtual NeuronBase& addInput() {};		
		virtual NeuronBase& addInput(const NeuronBase *input, double weight=1) {};		

};

/**
 * @brief      This class describes a neuron.
 */
class Neuron : public NeuronBase {

	private:

		std::vector<NeuronInput> inputs;
		double b{0};

	public:

		Neuron();

		double output() const;

		Neuron& bias(double bias);
		Neuron& calculate();

		Neuron& sigma();
		Neuron& addInput(const NeuronBase *input, double weight=1);
		
};

/**
 * @brief      This class describes a neuron input value.
 */
class NeuronInputValue : public NeuronBase {

	private:

		std::string name{""};

	public:

		NeuronInputValue(double v=0);

		NeuronInputValue& calculate();

		double output() const;

};

#endif