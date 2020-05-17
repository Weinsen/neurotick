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
 * @file     track.hpp
 * @author   Weinsen
 * @date     2020/05/16
 * @brief    { brief }
 * @defgroup BlockRace
 * 
 * { Full Description }
 */

#ifndef BLOCK_RACE_TRACK_HPP
#define BLOCK_RACE_TRACK_HPP

#include <random>
#include <iostream>
#include <chrono>
#include <thread>
#include "pointvector.hpp"
#include "racer.hpp"

class Track {

	private:
		int w{80};
		int h{30};
		int cap{10};
		int gen{0};
		int winner{0};
		double bestDistance;
		std::vector<Racer *> racers; 
		PointVector* destination;
		Trainer* eng;

	public:
		Track();

		Track& width(int width);
		Track& height(int height);
		Track& capacity(int capacity);
		Track& engine(Trainer* engine);
		Track& populate();
		Track& newGoal();
		Track& race(int iterations);
		Track& resetRacers();
		Track& setWinner(int w);

		int width();
		int height();
		int capacity();
		int getWinner();
		double getBestDistance();
		PointVector& goal();
};

#endif
