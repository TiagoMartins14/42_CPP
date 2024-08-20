#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
	: _input(other._input) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

std::string ScalarConverter::getInput() { return _input; }

std::string invalidInputError() {
	std::cerr
		<< "Invalid input. Valid input: <char> or <int> or <double> or <float>"
		<< std::endl;
	exit(2);
}

void ScalarConverter::convert(const std::string input) {
	int inputType;
	int dotCounter = 0;

	if (input.length() == 0)
		invalidInputError();
	else if (input.length() == 1) {
		if (input[0] >= 48 && input[0] <= 57)
			inputType = INT;
		else if ((input[0] >= 65 && input[0] <= 90) ||
				 (input[0] >= 97 && input[0] <= 122))
			inputType = CHAR;
	} else if (input.length() > 1) {
		for (size_t i = 0; i < input.length(); i++) {
			if (i == 0 && input[i] == '-') continue;
			if (input[i] == '.') {
				dotCounter++;
			}
			if (dotCounter > 1) invalidInputError();
			if (input[i] < 48 || input[i] > 57 ||
				(input[i] == 'f' && i != input.length() - 1))
				invalidInputError();
			if (i == input.length() - 1) {
				if (dotCounter == 0)
					inputType = INT;
				else if (input[i] == 'f')
					inputType = FLOAT;
				else
					inputType = DOUBLE;
			}
		}
	}
	// Now print the right conversions
}