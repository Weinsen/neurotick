#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "neural.hpp"

int main() 
{

	// Create model, layers and neurons
	Model model;
	model.addLayer("l1").addLayer("l2").addLayer("l3");
	model.getLayer("l1").addNeurons(4);
	model.getLayer("l2").addNeurons(10);
	model.getLayer("l3").addNeurons(2);
	// model.getLayer("l1").addNeuron("i1", -1).addNeuron("i2", -3).addNeuron("i3", -1).addNeuron("i4", -4);
	// model.getLayer("l2").addNeurons(10);
	// model.getLayer("l3").addNeuron("o1").addNeuron("o2");
	
	// Create connections using graph of weights
	Connector linker;
	std::vector<double> w = { 
		 5,  1, -2,  2,  5, -1,  4, -1,  0,  7,
		10,  0, -2,  2,  0, -1,  4, -1,  0,  7,
		 3,  1,  0,  2,  5, -1,  0, -1,  0,  7,
		 3,  1,  0,  2,  5, -1,  0, -1,  0,  7,
		-4,  1, -2,  2,  0, -1,  0, -3,  0,  7,
		 0,  1, -2,  2,  0, -1, -2,  0,  0,  7,
		 0,  1, -2,  2,  0, -1, -2,  0,  0,  7,
		 1,  1, -2,  0,  5, -1,  0, -1,  0,  7
	};

	model.setConnections(w);

	// Initilize trainer
	Trainer train(model);
	train.setBatch(2).createModels();
	train.run();

	model.calculate();

	train.randomizeVector(model);
	linker.connect(model);
	model.calculate();

	auto ret = train.output();
	for (auto r : ret) {
		for (auto v : r) {
			std::cout << v << std::endl;
		}
	}

	return 0;

}