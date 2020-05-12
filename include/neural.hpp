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
		void connect(Model& model, const char *receptor, const char *layer);

};

/**
 * @brief      This class describes a layer.
 */
class Layer {

	private:
		std::vector<NeuronBase *> neurons;
		std::string name;
		Model& model;

	public:
		Layer(Model& model, std::string name);
		Layer& addNeuron();
		Layer& addNeurons(int q);
		Layer& addInput(std::string name, double value);
		Layer& addNamed(std::string name);
		Layer& calculate();

		std::vector<NeuronBase *>* getNeurons();

		friend std::ostream& operator<< (std::ostream& os, const Layer& obj);	
		std::ostream& serialize(std::ostream& out) const;


};

/**
 * @brief      This class describes a model.
 */
class Model {

	private:
		std::map<std::string, Layer *> layers;
		std::map<std::string, NeuronBase *> namedNeurons;

	public:
		Model();
		Model& addLayer(std::string name);
		Model& addNamed(std::string name, NeuronBase *neuron); 
		Model& calculate();
		Layer& getLayer(std::string name);
		NeuronBase& getNamedNeuron(std::string name);

};

#endif