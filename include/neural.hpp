#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <cmath>
#include <vector>
#include <memory>
#include <iostream>
#include <map>

#include "neuron.hpp"

class Layer;
class Model;

/**
 * @brief      This class describes a connector.
 */
class Connector {

	private:
		std::string owner;
		std::string input;

	public:
		void connect(Model& model, std::string receptor, std::string layer);
		void connect(Model& model, NeuronBase& neuron, Layer& layer);
		void connect(Model& model, NeuronBase& neuron, std::string layer);

};

/**
 * @brief      This class describes a layer.
 */
class Layer {

	private:
		std::vector<NeuronBase *> neurons;
		std::string name;

	public:
		Layer();
		Layer& addNeuron();
		Layer& addNeurons(int q);
		Layer& addInput(std::string name, double value);
		Layer& calculate();

		std::vector<NeuronBase *>* getNeurons();

};

/**
 * @brief      This class describes a model.
 */
class Model {

	private:
		std::map<std::string, Layer> layers;

	public:
		Model();
		Model& addLayer(std::string name);
		Model& calculate();
		Layer& getLayer(std::string name);

};

#endif