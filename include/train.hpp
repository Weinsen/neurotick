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
 * @brief    Training manager module.
 * @defgroup Train
 * 
 * This module is responsible for managing models and its iterative training.
 */

#ifndef NEUROTICK_TRAIN_HPP
#define NEUROTICK_TRAIN_HPP

#include <vector>
#include <random>
#include <cmath>
#include "neural.hpp"

namespace neurotick {

class Model;

/**
 * @brief      Class trainer. Manages multiple model instances and apply training methods.
 * 
 * @ingroup    Train
 */
class Trainer {

	private:
		int batch_size{10}; 			///< How many instances are running
		double sigma{1};				///< Default deviation on training
		std::vector<Model *> models; 	///< Vector of managed model pointers
		Model& model;					///< Role model

	public:
		/**
		 * @brief      Constructs a new instance of Trainer.
		 *
		 * @param      model  The model used as reference.
		 */
		Trainer(Model& model);

		/**
		 * @brief      Creates a model.
		 *
		 * @return     Reference of created model.
		 * 
		 * Creates a new model based on the one passed as reference to class Trainer.
		 * The new instance is given an unique ID and the reference is returned.
		 */
		Model& createModel();

		/**
		 * @brief      Creates multiples models based on configured batch size.
		 *
		 * @return     Reference of this.
		 * 
		 * Creates multiple instances based on reference model. To each one is 
		 * given an unique ID. This method is usefull for creating objects with
		 * embedded models, allowing to create and assign a NN upon object
		 * creation.
		 */
		Trainer& createModels();
		
		/**
		 * @brief      Creates multiples models.
		 *
		 * @return     Reference of this.
		 * 
		 * Sets the batch size to quantity and creates this number os instances
		 * based on reference model.
		 */
		Trainer& createModels(int quantity);

		/**
		 * @brief      Randomize the parameter vector of this model.
		 *
		 * @param      model  The model.
		 *
		 * @return     Reference of this.
		 */
		Trainer& randomizeVector(Model& model);

		/**
		 * @brief      Randomize the parameter vectors of all managed models.
		 *
		 * @return     Reference of this.
		 */
		Trainer& randomizeVectors();

		/**
		 * @brief      Sets the batch size.
		 *
		 * @param[in]  size  The size
		 *
		 * @return     Reference of this.
		 */
		Trainer& setBatch(int size);

		/**
		 * @brief      Sets the standard deviation upon randomization.
		 *
		 * @param[in]  s     The new value of sigma.
		 *
		 * @return     Reference of this.
		 */
		Trainer& setSigma(double s);

		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		Trainer& run();

		/**
		 * @brief      Train all models based on the parameter vector of this model.
		 *
		 * @param      model  The reference model.
		 *
		 * @return     Reference of this.
		 */
		Trainer& genetic(Model& model);

		/**
		 * @brief      Train all models based on the parameter vector of this model.
		 *
		 * @param      model  The pointer of model.
		 *
		 * @return     Reference of this.
		 */	
		Trainer& genetic(Model *model);		

		/**
		 * @brief      Returns the model.
		 *
		 * @param[in]  id    The identifier
		 *
		 * @return     The model.
		 */
		Model& getModel(int id);
		
		/**
		 * @brief      Returns outputs of all managed models.
		 *
		 * @return     Vector of vectors of output.
		 */
		std::vector<std::vector<double>> output();

		/**
		 * @brief      Returns the output vector of model with given id.
		 *
		 * @param[in]  id    The identifier of the model.
		 *
		 * @return     Output vector.
		 */
		std::vector<double> output(int id);

};

}

#endif
