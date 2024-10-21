#pragma once
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
	std::vector<std::string> _operation;

	bool isValidInput(const std::string &str);
	void stringToVector(const std::string str);
	bool isValidInt(const std::string num);
	bool isValidOperator(const std::string operatorSign);
	bool isValidOperation();
};
