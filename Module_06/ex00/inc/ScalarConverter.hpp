#pragma once
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

enum e_inputType { CHAR, INT, DOUBLE, FLOAT, PSEUDO_LITERAL, INVALID };

class ScalarConverter {
   public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	template <typename T>
	static void convert(const std::string &input);
};
