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
 * @file     layer.hpp
 * @author   Weinsen
 * @date     2020/05/12
 * @brief    { brief }
 * @defgroup Model
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_LAYER_HPP
#define NEUROTICK_LAYER_HPP

#include "neural.hpp"

class Model;

/**
 * @brief      This class describes a layer.
 */
class Layer {

	private:
		std::vector<NeuronBase *> neurons;
		std::string name;
		Model& model;

	public:
		Layer(Model& model, std::string name);
		Layer& addNeuron();
		Layer& addNeuron(std::string name, double value=0);
		Layer& addNeuron(const NeuronBase& neuron);

		Layer& addNeurons(int q);

		Layer& calculate();

		std::string getName();

		int size();

		std::vector<NeuronBase *>& getNeurons();

		Layer& operator= (Layer& obj);
		friend std::ostream& operator<< (std::ostream& os, const Layer& obj);	
		std::ostream& print(std::ostream& out) const;


};

#endif
