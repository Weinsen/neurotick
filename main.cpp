#include "neural.hpp"
#include "neuron.hpp"
#include <iostream>
#include <fstream>

int main() 
{

	Model model;

	Connector linker;

	model.addLayer("l1").addLayer("l2").addLayer("l3").addLayer("l4");

	model.getLayer("l1").addNeuron("i1", -1).addNeuron("i2", -3).addNeuron("i3", -1).addNeuron("i4", -4);
	model.getLayer("l2").addNeurons(10);
	model.getLayer("l3").addNeuron("o1").addNeuron("o2");

	std::vector<double> w = { 
		 5,  1, -2,  2,  5, -1,  4, -1,  0,  7,
		10,  0, -2,  2,  0, -1,  4, -1,  0,  7,
		 3,  1,  0,  2,  5, -1,  0, -1,  0,  7,
		-4,  1, -2,  2,  0, -1,  0, -3,  0,  7,
		 0,  1, -2,  2,  0, -1, -2,  0,  0,  7,
		 1,  1, -2,  0,  5, -1,  0, -1,  0,  7
	};

	linker.connect(model, &w);

	model.calculate();

	model.getLayer("l2").addNeuron("o3", 2);	
	model.getLayer("l4") = model.getLayer("l2");

	// std::cout << model.getLayer("l1") <<  std::endl;
	// std::cout << model.getLayer("l2") <<  std::endl;
	// std::cout << model.getLayer("l3") <<  std::endl;
	std::cout << model.getLayer("l4") <<  std::endl;

	Model model2;
	model2 = model;

	model2.getLayer("l4").addNeuron("o4");
	std::cout << model2.getLayer("l4") <<  std::endl;

	return 0;

}