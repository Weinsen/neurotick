/*******************************************************************
* This file is part of block_race.
* 
* block_race is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* block_race is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with block_race.  If not, see <https://www.gnu.org/licenses/>
/******************************************************************/

/**
 * @file     racer.hpp
 * @author   Weinsen
 * @date     2020/05/15
 * @brief    { brief }
 * @defgroup { group }
 * 
 * { Full Description }
 */

#ifndef BLOCK_RACE_RACER_HPP
#define BLOCK_RACE_RACER_HPP

#include "neural.hpp"
#include "pointvector.hpp"

class Racer {

	private:
		int id;
		static int count;
		Model *model;
		std::string status;

	public:
		Racer();
		PointVector *goal;
		PointVector *pos;
		PointVector *vel;
		char getTag();
		int getId();
		Racer& update();
		Racer& engine(Model& model);
		Racer& target(PointVector& target);
		Racer& setStatus(std::string status);
		std::string getStatus();

};

#endif
