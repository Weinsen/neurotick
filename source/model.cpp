#include "model.hpp"

int Model::count = 0;

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
Model::Model() 
{
	id = count++;
}

Model::Model(Model& obj) 
{
	id = count++;
	for (auto l : obj.getLayers()) {
		std::string name = l->getName();
		addLayer(name);
		getLayer(name) = *l;
	}
	connections = obj.connections;
}

Model& Model::calculate() 
{

	for (auto l : layers) {
		l->calculate();
	}

	return *this;

}

Model& Model::addLayer(std::string name) 
{

	namedLayers[name] = (new Layer(*this, name));
	layers.push_back(namedLayers[name]);

	return *this;

}

Model& Model::addNamed(std::string name, NeuronBase *neuron) 
{
	namedNeurons[name] = neuron;

	return *this;
}

Layer& Model::getLayer(std::string name) 
{
	return *(namedLayers[name]);
}

std::vector<Layer *>& Model::getLayers() 
{
	return layers;
}

NeuronBase& Model::getNamedNeuron(std::string name)
{
	return *(namedNeurons[name]);	
}

Model& Model::setConnections(std::vector<double>& conn)
{
	connections = conn;

	Connector linker;

	linker.connect(*this);

	return *this;
}

Model& Model::resetConnections()
{
	for (auto l : layers) {
		for (auto n : l->getNeurons()) {
			n->reset();
		}
	}

	return *this;
}

std::vector<double>& Model::getConnections()
{
	return connections;
}

int Model::parameters()
{
	auto size = 0, aux = 0;
	for (auto layer : layers) {
		size += (aux + 1) * layer->size(); 
		aux = layer->size();
	}
	size -= layers[0]->size();
	return size;
}

Model& Model::input(std::vector<double> input)
{
	layers.front()->input(input);
	return *this;
}

std::vector<double> Model::output()
{
	return layers.back()->output();
}

std::ostream& operator<< (std::ostream& os, const Model& obj)
{
	return obj.print(os);
}

std::ostream& Model::print(std::ostream& out) const
{
	out << "Model(ID:" << id << ")" << std::endl;
	for (auto l : layers) {
		out << *l << std::endl;
	}
	return out;
}

Model& Model::operator= (Model& obj)
{
	if (this != &obj) {
		for (auto l : obj.getLayers()) {
			std::string name = l->getName();
			addLayer(name);
			getLayer(name) = *l;
		}
	}
	connections = obj.connections;
	return *this;
}