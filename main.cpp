#include "neural.hpp"
#include <iostream>

int main() 
{

	Layer layer1;
	Layer layer2;

	Model model;
	model.addLayer(&layer1).addLayer(&layer2);

	NeuronInputValue neuron1(1);
	NeuronInputValue neuron2(2);

	layer1.addNeuron(&neuron1).addNeuron(&neuron2);

	Neuron neuron3;
	neuron3.addInput(&neuron1, 1).addInput(&neuron2, 0.5);

	layer2.addNeuron(&neuron3);
	
	model.calculate();

	std::cout << neuron3.output() << std::endl;

	return 0;

}