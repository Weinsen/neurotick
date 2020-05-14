/*******************************************************************
* This file is part of neurotick.
* 
* neurotick is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* neurotick is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with neurotick.  If not, see <https://www.gnu.org/licenses/>
/******************************************************************/

/**
 * @file     model.hpp
 * @author   Weinsen
 * @date     2020/05/12
 * @brief    { brief }
 * @defgroup Model
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_MODEL_HPP
#define NEUROTICK_MODEL_HPP

#include "neural.hpp"

class Layer;
class NeuronBase;

/**
 * @brief      This class describes a model.
 */
class Model {

	private:
		std::map<std::string, Layer *> layers;
		std::map<std::string, NeuronBase *> namedNeurons;

	public:
		Model();
		Model& addLayer(std::string name);
		Model& addNamed(std::string name, NeuronBase *neuron); 
		Model& calculate();
		Layer& getLayer(std::string name);
		NeuronBase& getNamedNeuron(std::string name);
		
		std::map<std::string, Layer *>& getLayers();

		Model& operator= (Model& obj);

		int connections();

};

#endif
