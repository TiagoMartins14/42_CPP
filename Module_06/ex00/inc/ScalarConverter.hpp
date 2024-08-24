#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

enum e_inputType {
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
};

class ScalarConverter {
   public:
	ScalarConverter(std::string input);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	static std::string invalidInputError();
	static void convert(const std::string input);
	static void printChar(std::string input);
	static void printInt(std::string input);
	static void printDouble(std::string input);
	static void printFloat(std::string input);
};
