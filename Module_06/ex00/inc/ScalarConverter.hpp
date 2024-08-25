#pragma once
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

enum e_inputType { CHAR, INT, DOUBLE, FLOAT, INVALID };

class ScalarConverter {
   public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	static std::string invalidInputError();
	static void convert(const std::string &input);
};
