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

#include "include/ini_parser.h"

namespace Ini {
	Parser::Parser(std::istream *input)
		:current_i(0), current_char(), src(input), current_section(NULL)
	{
	};

	Parser::~Parser(void)
	{
		delete current_section;
		current_section = NULL;
	};

	void Parser::scan()
	{
        if (!scan_char())
            return;

		for(; !src->eof();)
		{
			if (current_char == L_SECTION)
			{
				scan_section();

				//we'll skip everything after R_SECTION
				// put your comments there or w/e
				//Also
				// let's skip all empty lines
				do
                    skip_until_after(NEWLINE);
                while (current_char == NEWLINE);
			}

			else
            {
                scan_line();

                do
                    skip_until_after(NEWLINE);
                while (current_char == NEWLINE);
            }
		}
	};

	void Parser::scan_line()
	{
	    if (current_char == NEWLINE)
            return;

		std::string line = "";
		line += current_char;

		while (scan_char() && current_char != NEWLINE)
            line += current_char;

		current_section->lines.push_back(
			parse_assignment(line));
	};

	bool Parser::scan_char()
	{
		++current_i;
		src->get(current_char);

        if (src->eof())
        {
            current_char = ((char) 0);
            return false;
        }

		return true;
	};

	void Parser::scan_section()
	{
		if (current_char != L_SECTION)
			return;

		std::string line = "";
		while (scan_char() && current_char != R_SECTION && current_char != NEWLINE)
		{
			line += current_char;
		}

		//Remember:
		// Section takes care of freeing the resources of its siblings
		// so new is actually safe here

		Section *section = new Section(line);
		section->previous = current_section;

		if (current_section)
		{
			section->previous = current_section;
			current_section->next = section;
		}

		current_section = section;
	};

	/// <summary>
	/// Skip_until_after the specified end.
	/// </summary>
	/// <param name="end">The end.</param>
	void Parser::skip_until_after(const char end)
	{
		for (; current_char != end && scan_char(); );
		scan_char();
	};

	std::pair<std::string, std::string> Parser::parse_assignment(std::string line) const
	{
		std::string lhe = "";
		std::string rhe = "";

		char c;
		int i = 0;
		for (; i < std::strlen(line.c_str()); ++i)
		{
		    c = line[i];

			if (c == ASSIGNMENT)
				break;

			lhe += c;
		}

		++i; // skip ASSIGNMENT

		for (; i < std::strlen(line.c_str()); ++i)
		{
		    c = line[i];

			if (c == NEWLINE)
				break;

			rhe += c;
		}

		return std::pair<std::string, std::string> (lhe, rhe);
	};
};
