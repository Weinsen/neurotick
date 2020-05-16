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
 * @file     pointvector.hpp
 * @author   Weinsen
 * @date     2020/05/16
 * @brief    { brief }
 * @defgroup { group }
 * 
 * { Full Description }
 */

#ifndef BLOCK_RACE_POINTVECTOR_HPP
#define BLOCK_RACE_POINTVECTOR_HPP

#include <vector>
#include <cmath>

class PointVector {

	private: 
		double x;
		double y;

	public:
		PointVector();
		PointVector(double x, double y);
		// double getCartesian();
		// double getPolar();
		double getX();
		double getY();
		std::vector<double> get();
		PointVector& set(std::vector<double> v);
		PointVector& set(double x, double y);
		PointVector& add(std::vector<double> v);
		PointVector& add(double x, double y);
		PointVector& setX(double x);
		PointVector& setY(double y);
		double getR();
		double getTheta();
		double getDegree();
		double distance(PointVector& point);

};

#endif
