#include "RPN.hpp"

#include <cctype>
#include <cstddef>
#include <cstdlib>

RPN::RPN(std::string &input) : _input(input) {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_input = other._input;
	}

	return *this;
}

RPN::~RPN() {}

// Checks the validity of the input
bool RPN::isValidInput(const std::string &str) {
	std::string allowedInput = "0123456789+-/* ";

	if (str.find_first_not_of(allowedInput) != std::string::npos) return false;

	std::string subStr;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == ' ') {
			if (!isValidInt(subStr) || !isValidOperator(subStr)) return false;
			subStr.clear();
		} else
			subStr += *it;
	}
	// Check the last subStr if there's any
	if (!subStr.empty())
		if (!isValidInt(subStr) || !isValidOperator(subStr)) return false;

	return true;
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

// Pushes numbers to stack until it finds an operator sign. Returns the next
// operator's index.
size_t RPN::pushNumbersToStack(std::string &str, size_t i) {
	while (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*') {
		while (str[i] && isspace(str[i])) i++;
		size_t pos = i;
		if (!isdigit(str[i])) return i;
		while (isdigit(str[i])) i++;
		int numberToPush = std::atoi(str.substr(pos, i - pos).c_str());
		_numbersStack.push(numberToPush);
	}

	return i;
}

// Checks for all the operators in sequence and pushes them in reverse order to
// stack. Returns the next index.
size_t RPN::pushOperatorsToStack(std::string &str, size_t i) {
	size_t start = i;
	while (str[i] && !isdigit(str[i])) i++;
	size_t end = i - 1;
	while (end >= start && str[end] && !isdigit(str[end])) {
		if (str[end] && isspace(str[end]))
			end--;
		else {
			char operatorToPush = str[end];
			_operatorsStack.push(operatorToPush);
			end--;
		}
	}

	return i;
}

size_t RPN::skiptWhiteSpaces(std::string &input, size_t i) {
	while (isspace(input[i])) i++;
	return i;
}

void RPN::calculateResult() {
	std::size_t opIndex = 0;
	int result = 0;

	while (_input[opIndex]) {
		opIndex = pushNumbersToStack(_input, opIndex);
		opIndex = pushOperatorsToStack(_input, opIndex);

		if (_numbersStack.size() != _operatorsStack.size() + 1) {
			std::cerr << "Error" << std::endl;
			return;
		}
		while (!_numbersStack.empty() && _numbersStack.size() > 1) {
			int num1 = _numbersStack.top();
			_numbersStack.pop();
			int num2 = _numbersStack.top();
			_numbersStack.pop();
			char operatorSign = _operatorsStack.top();
			_operatorsStack.pop();

			if (operatorSign == '+')
				result = num2 + num1;
			else if (operatorSign == '-')
				result = num2 - num1;
			else if (operatorSign == '/')
				result = num2 / num1;
			else if (operatorSign == '*')
				result = num2 * num1;

			_numbersStack.push(result);
		}
	}
	std::cout << result << std::endl;
}
