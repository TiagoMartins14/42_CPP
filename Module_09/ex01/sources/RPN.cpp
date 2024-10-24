#include "RPN.hpp"

#include <cstddef>

RPN::RPN(std::string &input) {
	if (isValidInput(input)) stringToVector(input);
}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_operation = other._operation;
	}

	return *this;
}

RPN::~RPN() {}

// Checks if there are no forbiden characters
bool RPN::isValidInput(const std::string &str) {
	std::string allowedInput = "0123456789+-/* ";

	return str.find_first_not_of(allowedInput) == std::string::npos;
}

// Converts the string to a vector
void RPN::stringToVector(const std::string str) {
	for (std::size_t i = 0; i < str.length();) {
		while (i < str.length() && isspace(str[i])) i++;

		std::size_t start = i;

		while (i < str.length() && !isspace(str[i])) i++;
		if (start < i) _operation.push_back(str.substr(start, i - start));
	}
}

// Checks if it is an integer between 0 and 9;
bool RPN::isValidInt(const std::string num) {
	if (num.empty()) return false;

	std::size_t pos = 0;

	if (num[0] == '+' || num[0] == '-') {
		if (num.length() != 2) return false;
		pos++;
	} else if (num.length() != 1)
		return false;

	if (!isdigit(num[pos])) return false;

	return true;
}

// Checks if it is a valid operator
bool RPN::isValidOperator(const std::string operatorSign) {
	std::string operators = "+-/*";

	if (operatorSign.length() != 1 ||
		operatorSign.find_first_not_of(operators) != std::string::npos)
		return false;
	return true;
}

// Checks if the amount of (numbers) matches the amount of (operations + 1)
bool RPN::isValidOperation() {
	std::string operators = "+-/*";
	std::size_t amountOfNumbers = 0;
	std::size_t amountOfOperators = 0;
	for (std::size_t i = 0; i < _operation.size();) {
		if (isValidInt(_operation[i])) {
			while (i < _operation.size() && isValidInt(_operation[i])) {
				amountOfNumbers++;
				i++;
			}
		}

		if (i >= 2 && isValidOperator(_operation[i])) {
			while (i < _operation.size() && isValidOperator(_operation[i])) {
				amountOfOperators++;
				i++;
			}
		} else
			return false;

		if (amountOfOperators + 1 != amountOfNumbers) return false;
	}

	return true;
}

void RPN::calculateResult() {
	if (!isValidOperation())
		std::cerr << "Error." << std::endl;
	else {
		std::size_t numIndex = 1;
		std::size_t opIndex = 0;
		int result = std::atoi(_operation[0].c_str());

		while (opIndex < _operation.size()) {
			while (opIndex < _operation.size() &&
				   !isValidOperator(_operation[opIndex]))
				opIndex++;
			while (numIndex < _operation.size() &&
				   !isValidInt(_operation[numIndex]))
				numIndex++;

			int num2 = std::atoi(_operation[numIndex].c_str());

			if (std::strcmp(_operation[opIndex].c_str(), "+") == 0)
				result += num2;
			else if (std::strcmp(_operation[opIndex].c_str(), "-") == 0)
				result -= num2;
			else if (std::strcmp(_operation[opIndex].c_str(), "/") == 0)
				result /= num2;
			else if (std::strcmp(_operation[opIndex].c_str(), "*") == 0)
				result *= num2;

			numIndex++;
			opIndex++;
		}
		std::cout << result << std::endl;
	}
}
