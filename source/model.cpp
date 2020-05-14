#include "model.hpp"

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

std::map<std::string, Layer *>& Model::getLayers() 
{
	return layers;
}

NeuronBase& Model::getNamedNeuron(std::string name)
{
	return *(namedNeurons[name]);	
}

int Model::connections()
{
	auto size = 0, aux = 0;
	for (auto layer : layers) {
		size += aux * layer.second->size(); 
		aux = layer.second->size();
	}
	return size;
}

Model& Model::operator= (Model& obj)
{
	if (this != &obj) {
		for (auto l : obj.getLayers()) {
			std::string name = (l.second)->getName();
			addLayer(name);
			getLayer(name) = *(l.second);
		}
	}
	return *this;
}