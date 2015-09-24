#include "ini_parser_test.h"

namespace Test {
	bool assert(bool test, std::string msg)
	{
		if (test)
		{
			printf("%s", msg);
		}

		return test;
	};

	void test()
	{
		/*
		std::ifstream gameSettingsFile ("../game.ini", std::ios::in | std::ios::out);

		if (assert(gameSettingsFile.is_open(), "Could not open game settings file"))
		{
			std::string src = "";
			std::string line = "";

			std::string meta = "";
			getline(gameSettingsFile, meta);
				
			while (getline(gameSettingsFile, line))
			{
				src += line + '\n';
			}

			int rooms = std::stoi(&meta[0], nullptr, 10);
			int connections = std::stoi(&meta[0], nullptr, 10);
			int actions = std::stoi(&meta[0], nullptr, 10);

			Ini::Parser parser (src);
			parser.scan();

			assert(parser.lines.size() == (rooms + connections + actions), "# sections didn't match");
		}*/
	};
};