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
 * @file     connector.hpp
 * @author   Weinsen
 * @date     2020/05/12
 * @brief    { brief }
 * @defgroup Model
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_CONNECTOR_HPP
#define NEUROTICK_CONNECTOR_HPP

#include "neural.hpp"

class Layer;
class Model;

/**
 * @brief      This class describes a connector.
 */
class Connector {

	private:
		std::string owner;
		std::string input;

	public:
		// void connect(Model& model, std::string receptor, std::string layer);
		// void connect(Model& model, const char *receptor, const char *layer);
		// void connect(Model& model, const char *receptor, const char *layer, std::vector<double> *weights);
		// void connect(Model& model, const char *receptor, const char *layer, std::vector<std::vector<double>> *weights);
		void connect(Model& model, std::vector<double>& weights);
		void connect(Model& model);

};

#endif
