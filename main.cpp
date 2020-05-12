#include "neural.hpp"
#include "neuron.hpp"
#include <iostream>
#include <fstream>

int main() 
{

	Layer layer1;
	Layer layer2;

	Model model;

	Connector linker;

	model.addLayer("l1").addLayer("l2").addLayer("l3");

	model.getLayer("l1").addInput("left", 1).addInput("right", 1);
	model.getLayer("l2").addNeurons(50);
	model.getLayer("l3").addNeurons(50);
	model.getLayer("l4").addNeurons(1);

	std::vector<NeuronBase *>* neurons4 = model.getLayer("l4").getNeurons();

	linker.connect(model, std::string("l2"), std::string("l1"));
	linker.connect(model, std::string("l3"), std::string("l2"));
	linker.connect(model, std::string("l4"), std::string("l3"));
	
	model.calculate();
	
	for (auto n : *neurons4) {
		std::cout << n->output() << std::endl;
	}

	std::fstream fs;
	fs.open("./model", std::ios::app);

	return 0;

}