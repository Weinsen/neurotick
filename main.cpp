#include "neural.hpp"
#include "neuron.hpp"
#include <iostream>
#include <fstream>

int main() 
{

	Model model;

	Connector linker;

	model.addLayer("l1").addLayer("l2").addLayer("l3");

	model.getLayer("l1").addInput("i1", 1).addInput("i2", 1).addInput("i3", -3).addInput("i4", -4);
	model.getLayer("l2").addNeurons(10);
	model.getLayer("l3").addNamed("o1").addNamed("o2");

	std::vector<std::vector<double>> w = {
		{ 0,  1, -1,  2},
		{ 0, -1,  1,  2},
		{ 3,  0,  0, -2},
		{-2,  1, -1,  2},
		{ 2,  0, -2,  2},
		{ 0,  1, -1,  2},
		{ 0,  1, -1,  2},
		{ 8,  0, -5,  2},
		{-1,  1, -1,  2},
		{ 0,  1, -1,  2}
	};

	linker.connect(model, "l2", "l1", &w);
	linker.connect(model, "l3", "l2");

	model.calculate();

	std::cout << model.getLayer("l2");
	std::cout << model.getLayer("l3");


	return 0;

}