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

	static void convert(std::string &input);

   private:
	static bool isChar(std::string &input);
	static bool isInt(std::string &input);
	static bool isFloat(std::string &input);
	static bool isDouble(std::string &input);
	static bool isPseudoLiteral(std::string &input);
	static e_inputType inputTypeChecker(std::string &input);
	static void printImpossibleInput();
	static void printPseudoLiterals(std::string &input);
	static void convertToChar(char c);
	static void convertToInt(int integer);
	static void convertToFloat(float fp);
	static void convertToDouble(double dp);
	static void converterFunction(long double num);
};
