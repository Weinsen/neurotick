#include "neural.hpp"
#include "neuron.hpp"
#include <iostream>
#include <fstream>

int main() 
{

	Layer layer1;
	Layer layer2;

	Model model;
	model.addLayer("l1").addLayer("l2").addLayer("l3");

	model.getLayer("l1").addInput("left", 1).addInput("right", 1);
	model.getLayer("l2").addNeurons(50);
	model.getLayer("l3").addNeurons(50);
	model.getLayer("l4").addNeurons(1);

	std::vector<NeuronBase *>* neurons1 = model.getLayer("l1").getNeurons();
	std::vector<NeuronBase *>* neurons2 = model.getLayer("l2").getNeurons();
	std::vector<NeuronBase *>* neurons3 = model.getLayer("l3").getNeurons();
	std::vector<NeuronBase *>* neurons4 = model.getLayer("l4").getNeurons();

	for (auto n : *neurons2) {
		for (auto i : *neurons1) {
			n->addInput(i);
		}
	}

	for (auto n : *neurons3) {
		for (auto i : *neurons2) {
			n->addInput(i);
		}
	}

	for (auto n : *neurons4) {
		for (auto i : *neurons3) {
			n->addInput(i);
		}
	}

	model.calculate();
	
	for (auto n : *neurons4) {
		std::cout << n->output() << std::endl;
	}

	std::fstream fs;
	fs.open("./model", std::ios::app);

	return 0;

}