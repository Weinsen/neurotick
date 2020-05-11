#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <cmath>
#include <vector>
#include <memory>
#include <iostream>

class Neuron;
class NeuronBase;
class NeuronInputValue;
class Layer;

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

		double output();

		Neuron& bias(double bias);
		Neuron& calculate();

		Neuron& sigma();
		Neuron& addInput(const NeuronBase *input, double weight=1);
		
};

/**
 * @brief      This class describes a neuron input value.
 */
class NeuronInputValue : public NeuronBase {

	public:

		NeuronInputValue(double v=0);

		NeuronInputValue& calculate();

		double output() const;

};

/**
 * @brief      This class describes a layer.
 */
class Layer {

	private:
		std::vector<NeuronBase *> neurons;

	public:
		Layer();
		Layer& addNeuron(NeuronBase *neuron);
		Layer& calculate();

};

/**
 * @brief      This class describes a model.
 */
class Model {

	private:
		std::vector<Layer *> layers;

	public:
		Model();
		Model& addLayer(Layer *layer);
		Model& calculate();

};

#endif