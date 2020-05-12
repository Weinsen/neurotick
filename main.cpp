#include "neural.hpp"
#include "neuron.hpp"
#include <iostream>
#include <fstream>

int main() 
{

	Model model;

	Connector linker;

	model.addLayer("l1").addLayer("l2").addLayer("l3").addLayer("l4");

	model.getLayer("l1").addInput("i1", 1).addInput("i2", 1);
	model.getLayer("l2").addNeurons(50);
	model.getLayer("l3").addNeurons(50);
	model.getLayer("l4").addNamed("o1").addNamed("o2");

	linker.connect(model, "l2", "l1");
	linker.connect(model, "l3", "l2");
	linker.connect(model, "l4", "l3");

	model.calculate();
	std::cout << model.getLayer("l4");

	model.getNamedNeuron("i2").set(5);
	model.getNamedNeuron("i1").set(-1);

	model.calculate();
	std::cout << model.getLayer("l4");


	return 0;

}