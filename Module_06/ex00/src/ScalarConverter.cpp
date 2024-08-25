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

bool intChecker(const std::string input) {
	long num;

	std::stringstream ss(input);
	ss >> num;

	if (ss.fail() || num < INT_MIN || num > INT_MAX) return false;
	return true;
}

e_inputType inputTypeChecker(const std::string input) {
	int dotCounter = 0;

	if (input.length() == 0)
		invalidInputError();
	else if (input.length() == 1) {
		if (input[0] >= 48 && input[0] <= 57)
			return INT;
		else if ((input[0] >= 65 && input[0] <= 90) ||
				 (input[0] >= 97 && input[0] <= 122))
			return CHAR;
	} else if (input.length() > 1) {
		for (size_t i = 0; i < input.length(); i++) {
			if (i == 0 && input[i] == '-') continue;
			if (input[i] == '.') {
				dotCounter++;
				if (dotCounter > 1) invalidInputError();
				continue;
			}
			if (input[i] < 48 || input[i] > 57 ||
				(input[i] == 'f' && i != input.length() - 1))
				invalidInputError();
			if (i == input.length() - 1) {
				if (dotCounter == 0)
					return INT;
				else if (input[i] == 'f')
					return FLOAT;
				else
					return DOUBLE;
			}
		}
	}
	return INVALID;
}

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
