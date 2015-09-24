/********************************************************************

    ini_parser - a small ini parser in C++
    Copyright (C) 2015 Marcus Hansson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, see <http://www.gnu.org/licenses/>,
    or write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    You should have received a copy of the GNU General Public License
    along with ini_parser.

********************************************************************/

#ifndef _INI_SECTION_H
#define _INI_SECTION_H 1

#include <vector>
#include <map>
#include <string>

namespace Ini {
	class Section {
	public:
		std::string name;
		std::vector< std::pair<std::string, std::string> > lines;

		Ini::Section *previous;
		Ini::Section *next;

		Section(void);
		Section(std::string name);
		~Section(void);
	};
};

#endif
