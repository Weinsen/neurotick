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
 * @file     train.hpp
 * @author   Weinsen
 * @date     2020/05/13
 * @brief    { brief }
 * @defgroup Train
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_TRAIN_HPP
#define NEUROTICK_TRAIN_HPP

#include <vector>
#include <random>
#include <cmath>
#include "neural.hpp"

class Model;

class Trainer {

	private:
		int batch_size{10};
		int sigma{1};
		std::vector<Model *> models;
		Model& model;

	public:
		Trainer(Model& model);
		Trainer& randomizeVector(Model& model);
		Trainer& setBatch(int size);
		Trainer& setSigma(int s);
		Trainer& run();

};

#endif
