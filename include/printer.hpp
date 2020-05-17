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
 * @file     printer.hpp
 * @author   Weinsen
 * @date     2020/05/15
 * @brief    { brief }
 * @defgroup Debug
 * 
 * { Full Description }
 */

#ifndef NEUROTICK_PRINTER_HPP
#define NEUROTICK_PRINTER_HPP

#include "neural.hpp"

namespace neurotick {

class Printer {

	public:
		std::ostream& print(Model& model);

};

}

#endif
