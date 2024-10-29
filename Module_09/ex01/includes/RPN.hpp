#pragma once
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class RPN {
   public:
	RPN(std::string &input);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void calculateResult();

   private:
	std::string _input;
	std::stack<int> _numbersStack;
	std::stack<char> _operatorsStack;

	bool isValidInput(const std::string &str);
	void stringToVector(const std::string str);
	bool isValidInt(const std::string num);
	bool isValidOperator(const std::string operatorSign);
	bool isValidOperation();
	size_t pushNumbersToStack(std::string &str, size_t i);
	size_t pushoperatorsToStack(std::string &str, size_t i);
	size_t skiptWhiteSpaces(std::string &input, size_t i);
};
