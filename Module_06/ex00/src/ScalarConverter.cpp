#include <algorithm>
#include <cctype>
#include <cstring>
#include <iomanip>

#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string &input) {
	return (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]));
}

bool ScalarConverter::isInt(std::string &input) {
	std::string allowedInput = "0123456789";
	std::string str = input;

	if (input.size() > 0 && (input[0] == '+' || input[0] == '-'))
		str = str.substr(1);

	return (str.find_first_not_of(allowedInput) == std::string::npos &&
			str.find('.') == std::string::npos);
}

bool ScalarConverter::isFloat(std::string &input) {
	std::string allowedInput = "0123456789.f";
	std::string str = input;

	if (input.size() > 0 && (input[0] == '+' || input[0] == '-'))
		str = str.substr(1);

	if (str.length() < 4) return false;

	if (str.find('.') == std::string::npos ||
		str.find('f') == std::string::npos)
		return false;

	if (str.find('f') != str.length() - 1) return false;

	if (str.find('.') == str.length() - 2) return false;

	if (str.find_first_of('.') != str.find_last_of('.') ||
		str.find_first_of('f') != str.find_last_of('f'))
		return false;

	return true;
}

bool ScalarConverter::isDouble(std::string &input) {
	std::string allowedInput = "0123456789.";
	std::string str = input;

	if (input.size() > 0 && (input[0] == '+' || input[0] == '-'))
		str = str.substr(1);

	if (str.length() < 3) return false;

	if (str.find('.') == std::string::npos) return false;

	if (str.find_first_of('.') != str.find_last_of('.')) return false;

	if (str.find('.') == str.length() - 1) return false;

	return true;
}

bool ScalarConverter::isPseudoLiteral(std::string &input) {
	if (strcmp(input.c_str(), "nan") == 0 ||
		strcmp(input.c_str(), "nanf") == 0 ||
		strcmp(input.c_str(), "-inf") == 0 ||
		strcmp(input.c_str(), "+inf") == 0 ||
		strcmp(input.c_str(), "-inff") == 0 ||
		strcmp(input.c_str(), "+inff") == 0)
		return true;
	return false;
}

e_inputType ScalarConverter::inputTypeChecker(std::string &input) {
	if (isChar(input)) return CHAR;
	if (isInt(input)) return INT;
	if (isFloat(input)) return FLOAT;
	if (isDouble(input)) return DOUBLE;
	if (isPseudoLiteral(input)) return PSEUDO_LITERAL;
	return INVALID;
}

void ScalarConverter::printImpossibleInput() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printPseudoLiterals(std::string &input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (strcmp(input.c_str(), "nan") == 0 ||
		strcmp(input.c_str(), "nanf") == 0) {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}

	if (strcmp(input.c_str(), "-inf") == 0 ||
		strcmp(input.c_str(), "-inff") == 0) {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}

	if (strcmp(input.c_str(), "+inf") == 0 ||
		strcmp(input.c_str(), "+inff") == 0) {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void ScalarConverter::convertToChar(char c) {
	std::cout << "char: ";

	if (!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::convertToInt(int integer) {
	std::cout << "int :" << integer << std::endl;
}

void ScalarConverter::convertToFloat(float fp) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << fp << "f"
			  << std::endl;
}

void ScalarConverter::convertToDouble(double dp) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << dp
			  << std::endl;
}

void ScalarConverter::converterFunction(long double num) {
	convertToChar(static_cast<char>(num));
	convertToInt(static_cast<int>(num));
	convertToFloat(static_cast<float>(num));
	convertToDouble(static_cast<double>(num));
}

void ScalarConverter::convert(std::string &input) {
	switch (inputTypeChecker(input)) {
		case CHAR:
			converterFunction(input[0]);
			break;
		case INT:
			converterFunction(std::atoi(input.c_str()));
			break;
		case FLOAT:
			converterFunction(std::strtof(input.c_str(), NULL));
			break;
		case DOUBLE:
			converterFunction(std::strtold(input.c_str(), NULL));
			break;
		case PSEUDO_LITERAL:
			printPseudoLiterals(input);
			break;
		case INVALID:
			printImpossibleInput();
			break;
	}
}
