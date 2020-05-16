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
 * @file     neuron.hpp
 * @author   Weinsen
 * @date     2020/05/12
 * @brief    { brief }
 * @defgroup Model
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_NEURON_HPP
#define NEUROTICK_NEURON_HPP

#include "neural.hpp"

class Neuron;
class NeuronBase;

typedef struct {
	const NeuronBase *neuron;
	double w;
} NeuronInput;


/**
 * @brief      This class describes a neuron base.
 */
class NeuronBase {

	protected:

		double value{0};
		int id;
		std::string name;

		friend class Neuron; 

	public:

		NeuronBase();
		NeuronBase(const NeuronBase& neuron);

		virtual double output() const;
		virtual NeuronBase& calculate();
		
		virtual NeuronBase& addInput() {};		
		virtual NeuronBase& addInput(const NeuronBase *input, double weight=1) {};	
		virtual NeuronBase& set(double v);
		virtual NeuronBase& reset();

		friend std::ostream& operator<< (std::ostream& os, const NeuronBase& obj);	
		virtual std::ostream& print(std::ostream& out) const;

};

/**
 * @brief      This class describes a neuron.
 */
class Neuron : public NeuronBase {

	private:

		std::vector<NeuronInput> inputs;
		double bias{0};

	public:

		Neuron(int i);
		Neuron(int i, std::string label);
		Neuron(int i, std::string label, double v);
		Neuron(const NeuronBase &neuron);

		double output() const;

		Neuron& calculate();

		Neuron& sigma();
		Neuron& addInput(const NeuronBase *input, double weight=1);
		Neuron& set(double v); 
		Neuron& reset(); 

		std::ostream& print(std::ostream& out) const;
		
};

#endif