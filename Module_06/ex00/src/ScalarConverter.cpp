#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

e_inputType inputTypeChecker(const std::string &input) {
	std::stringstream ss(input);

	int intValue;
	ss >> intValue;
	if (!ss.fail() && ss.eof()) {
		if (input.find('.') == std::string::npos) return INT;
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

// static int decimalCount(const std::string &input) {
// 	size_t dotPos = input.find('.');
// 	if (dotPos == std::string::npos) return 1;
// 	if (inputTypeChecker(input) == FLOAT) return input.length() - dotPos - 2;
// 	return input.length() - dotPos - 1;
// }

static char castChar(const std::string &input) {
	if (inputTypeChecker(input) == CHAR) {
		return input[0];
	} else if (inputTypeChecker(input) == INT ||
			   inputTypeChecker(input) == FLOAT ||
			   inputTypeChecker(input) == DOUBLE) {
		std::stringstream ss(input);
		int num;

		ss >> num;
		if (num < 32 || num > 126)
			throw "impossible";
		else
			return static_cast<char>(num);
	} else
		throw "impossible.";
}

static int castInt(const std::string &input) {
	std::cout << "int: ";

	if (input.length() == 1 &&
		((input[0] > 31 && input[0] < 48) || (input[0] > 57 && input[0] < 127)))
		return static_cast<int>(input[0]);
	else {
		std::stringstream ss(input);
		int num;

		ss >> num;
		return static_cast<int>(num);
	}
}

static double castDouble(const std::string &input) {
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<double>::infinity();
	else if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<double>::infinity();
	else if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (input.length() == 1 && ((input[0] > 31 && input[0] < 48) ||
									 (input[0] > 57 && input[0] < 127)))
		return static_cast<double>(input[0]);
	else {
		std::stringstream ss(input);
		double num;

		ss >> num;
		return static_cast<double>(num);
	}
}

static float castFloat(const std::string &input) {
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<double>::infinity();
	else if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<double>::infinity();
	else if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (input.length() == 1 && ((input[0] > 31 && input[0] < 48) ||
									 (input[0] > 57 && input[0] < 127)))
		return static_cast<float>(input[0]);
	else {
		std::stringstream ss(input);
		float num;

		ss >> num;
		return static_cast<float>(num);
	}
}

template <typename T>
T convertToActualType(std::string &input, e_inputType type) {
	switch (type) {
		case CHAR:
			return castChar(input);
		case INT:
			return castInt(input);
		case DOUBLE:
			return castDouble(input);
		case FLOAT:
			return castFloat(input);
		case INVALID:
			return "impossible.";
		default:
			return "impossible.";
	}
}

template <typename T>
static void printSelectedType(T &input, e_inputType type) {
	if (strcmp(input.c_str(), "impossible.") == 0) {
		std::cout << "invalid." << std::endl;
		return;
	}
	switch (type) {
		case CHAR:
			std::cout << static_cast<char>(input[0]) << std::endl;
			break;
		case INT:
			std::cout << static_cast<int>(input) << std::endl;
			break;
		case DOUBLE:
			std::cout << static_cast<double>(input) << std::endl;
			break;
		case FLOAT:
			std::cout << static_cast<float>(input) << std::endl;
			break;
		case INVALID:
			std::cout << "invalid." << std::endl;
			break;
	}
}

template <typename T>
void ScalarConverter::convert(const std::string &input) {
	T convertedInput = convertToActualType<T>(input, inputTypeChecker(input));

	std::cout << "char: ";
	printSelectedType(convertedInput, CHAR);
	std::cout << "int: ";
	printSelectedType(convertedInput, INT);
	std::cout << "double: ";
	printSelectedType(convertedInput, DOUBLE);
	std::cout << "float: ";
	printSelectedType(convertedInput, FLOAT);
}
