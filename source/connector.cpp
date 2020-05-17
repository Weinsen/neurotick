#include "connector.hpp"

namespace neurotick {

// void Connector::connect(Model& model, std::string receptor, std::string layer)
// {
// 	std::vector<NeuronBase *>* neurons1 = model.getLayer(receptor).getNeurons();
// 	std::vector<NeuronBase *>* neurons2 = model.getLayer(layer).getNeurons();

// 	for (auto n : *neurons1) {
// 		for (auto i : *neurons2) {
// 			n->addInput(i);
// 		}
// 	}
// }

// void Connector::connect(Model& model, const char *receptor, const char *layer)
// {
// 	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
// 	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

// 	for (auto n : *neurons1) {
// 		for (auto i : *neurons2) {
// 			n->addInput(i);
// 		}
// 	}
// }

// void Connector::connect(Model& model, const char *receptor, const char *layer, std::vector<double> *weights)
// {
// 	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
// 	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

// 	for (auto n : *neurons1) {
// 		int i=0;
// 		for (auto w : *weights) {
// 			n->addInput((*neurons2)[i], w);
// 			i++;
// 		}
// 	}
// }

// void Connector::connect(Model& model, const char *receptor, const char *layer, std::vector<std::vector<double>> *weights)
// {
// 	std::vector<NeuronBase *>* neurons1 = model.getLayer(std::string(receptor)).getNeurons();
// 	std::vector<NeuronBase *>* neurons2 = model.getLayer(std::string(layer)).getNeurons();

// 	int i=0;
// 	for (auto n : *weights) {
// 		int j=0;
// 		for (auto w : n) {
// 			if (w != 0) {
// 				(*neurons1)[i]->addInput((*neurons2)[j], w);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void Connector::connect(Model& model)
{
	auto weights = model.getConnections();
	std::vector<double>::iterator w = weights.begin();
	std::vector<Layer *>::iterator l = model.getLayers().begin();

	// Check vector size
	if (weights.size() < model.parameters()) {
		throw std::invalid_argument("Vector smaller than necessary!");
	}

	model.resetConnections();

	while (l != std::prev(model.getLayers().end(), 1)) {
	
		auto layer1 = *l++;
		auto layer2 = *l;

		auto neurons1 = layer1->getNeurons();
		auto neurons2 = layer2->getNeurons();

		for (auto n2 : neurons2) {
			for (auto n1 : neurons1) {
				n2->addInput(n1, *w++);
			}
		}
	}
}

}
