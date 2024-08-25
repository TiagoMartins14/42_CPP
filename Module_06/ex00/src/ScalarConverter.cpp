#include "ScalarConverter.hpp"

#include <climits>
#include <stdexcept>

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

std::string invalidInputError() {
	std::cerr
		<< "Invalid input. Valid input: <char> or <int> or <double> or <float>"
		<< std::endl;
	exit(2);
}

e_inputType inputTypeChecker(const std::string &input) {
	std::stringstream ss(input);

	int intValue;
	ss >> intValue;
	if (!ss.fail() && ss.eof()) {
		return INT;
	}

	ss.clear();
	ss.str(input);

	double doubleValue;
	ss >> doubleValue;
	if (!ss.fail()) {
		if (ss.eof()) {
			return DOUBLE;
		} else if (input[input.length() - 1] == 'f' &&
				   input.find('.') != std::string::npos) {
			return FLOAT;
		}
	}

	if (input.length() == 1 && std::isprint(input[0])) {
		return CHAR;
	}

	return INVALID;
}

static void printChar(std::string &input) {
	std::cout << "char: ";
	if (inputTypeChecker(input) == CHAR) {
		std::cout << input;
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void printInt(std::string input) {
	std::cout << "int: ";
	if (inputTypeChecker(input) == INT) {
		std::cout << input;
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}
static void printDouble(std::string input);
static void printFloat(std::string input);

void ScalarConverter::convert(const std::string input) {
	int inputType = inputTypeChecker(input);
	// Now print the right conversions
	switch (inputType) {
		default:
			invalidInputError();
		case:
			CHAR
	}
}
