#include "ScalarConverter.hpp"

#include <climits>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
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

static void printChar(const std::string &input) {
	std::cout << "char: ";
	if (inputTypeChecker(input) == CHAR) {
		std::cout << input;
	} else if (inputTypeChecker(input) == INT) {
		std::stringstream ss(input);
		int num;

		ss >> num;
		if (num < 0 || num > 127 || (num >= 9 && num <= 13) || num == 32)
			std::cout << "impossible";
		else
			std::cout << static_cast<char>(num);
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void printInt(const std::string &input) {
	std::stringstream ss(input);
	int num;

	ss >> num;
	std::cout << "int: ";
	if (!ss.fail()) {
		std::cout << static_cast<int>(num);
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void printDouble(const std::string &input) {
	std::stringstream ss(input);
	double num;

	ss >> num;
	std::cout << "double: ";
	if (!ss.fail()) {
		std::cout << static_cast<double>(num);
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void printFloat(const std::string &input) {
	std::stringstream ss(input);
	float num;

	ss >> num;
	std::cout << "float: ";
	if (!ss.fail()) {
		std::cout << static_cast<float>(num);
	} else
		std::cout << "impossible";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	printChar(input);
	printInt(input);
	printDouble(input);
	printFloat(input);
}
