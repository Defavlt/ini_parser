/********************************************************************
    This file is part of ini_parser.

    ini_parser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ini_parser is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ini_parser.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/
/********************************************************************
    This file is part of ini_parser.

    ini_parser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ini_parser is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ini_parser.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

#ifndef _INI_PARSER_H
#define _INI_PARSER_H 1

#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include "ini_section.h"

namespace Ini {
	class Parser
	{
	private:
	    static const char L_SECTION = '[';
        static const char R_SECTION = ']';
        static const char S_DELIMITER = '"';
        static const char ASSIGNMENT = '=';
        static const char NEWLINE = '\n';

		unsigned int current_i;
		char current_char;
		std::istream *src;

        Ini::Section *current_section;

	protected:
		bool scan_char();
		void scan_line();
		void scan_section();
		void skip_until_after(const char end);

		std::pair<std::string, std::string> parse_assignment(std::string line) const;

	public:
	    void setSection(Ini::Section* section) { current_section = section; }
	    Ini::Section *getSection()
	    {
	        if (!current_section)
                current_section = new Ini::Section ();

	        return current_section;
        };

		Parser(std::istream *input_stream);
		~Parser(void);
		void scan();

	};
}

#endif
