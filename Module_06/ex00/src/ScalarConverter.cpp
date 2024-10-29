#include <algorithm>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <limits>
#include <stdexcept>

#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string &input) {
  return (input.length() == 1 && std::isprint(input[0]) &&
          !std::isdigit(input[0]));
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

  if (str.length() < 4)
    return false;

  if (str.find('.') == std::string::npos || str.find('f') == std::string::npos)
    return false;

  if (str.find('f') != str.length() - 1)
    return false;

  if (str.find('.') == str.length() - 2)
    return false;

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

  if (str.length() < 3)
    return false;

  if (str.find('.') == std::string::npos)
    return false;

  if (str.find_first_of('.') != str.find_last_of('.'))
    return false;

  if (str.find('.') == str.length() - 1)
    return false;

  return true;
}

bool ScalarConverter::isPseudoLiteral(std::string &input) {
  if (strcmp(input.c_str(), "nan") == 0 || strcmp(input.c_str(), "nanf") == 0 ||
      strcmp(input.c_str(), "-inf") == 0 ||
      strcmp(input.c_str(), "+inf") == 0 ||
      strcmp(input.c_str(), "-inff") == 0 ||
      strcmp(input.c_str(), "+inff") == 0)
    return true;
  return false;
}

e_inputType ScalarConverter::inputTypeChecker(std::string &input) {
  if (isChar(input))
    return CHAR;
  if (isInt(input))
    return INT;
  if (isFloat(input))
    return FLOAT;
  if (isDouble(input))
    return DOUBLE;
  if (isPseudoLiteral(input))
    return PSEUDO_LITERAL;
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

  if (strcmp(input.c_str(), "nan") == 0 || strcmp(input.c_str(), "nanf") == 0) {
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

bool overflowChecker(long double num, e_inputType type) {
  switch (type) {
  case INVALID:

  case PSEUDO_LITERAL:

  case CHAR:
    return num < std::numeric_limits<char>::min() ||
           num > std::numeric_limits<char>::max();

  case INT:
    return num < std::numeric_limits<int>::min() ||
           num > std::numeric_limits<int>::max();

  case FLOAT:
    return num < -std::numeric_limits<float>::max() ||
           num > std::numeric_limits<float>::max();

  case DOUBLE:
    return num < -std::numeric_limits<double>::max() ||
           num > std::numeric_limits<double>::max();
  }
}

void ScalarConverter::convertToChar(std::string &input) {
  if (input.length() == 1) {
    char c = input[0];

    std::cout << "char: ";
    if (!isprint(c) || std::isdigit(input[0])) {
      std::cout << "Non displayable" << std::endl;
    } else {
      std::cout << "'" << c << "'" << std::endl;
    }
    return;
  }

  long double num = std::strtold(input.c_str(), NULL);
  char c = static_cast<char>(num);

  std::cout << "char: ";

  if (!isprint(c))
    std::cout << "Non displayable" << std::endl;
  else if (overflowChecker(num, CHAR))
    std::cout << "Overflowed" << std::endl;
  else
    std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::convertToInt(std::string &input) {
  if (input.length() == 1 && isprint(input[0])) {
    int asciiValue;
    if (isdigit(input[0]))
      asciiValue = static_cast<int>(static_cast<int>(input[0])) - 48;
    else
      asciiValue = static_cast<int>(static_cast<int>(input[0]));
    std::cout << "int: " << asciiValue << std::endl;
    return;
  }

  long double num = std::strtold(input.c_str(), NULL);

  std::cout << "int: ";

  if (overflowChecker(num, INT))
    std::cout << "Overflowed" << std::endl;
  else {
    int integer = static_cast<int>(num);
    std::cout << integer << std::endl;
  }
}

void ScalarConverter::convertToFloat(std::string &input) {
  if (input.length() == 1 && isprint(input[0])) {
    float asciiValue;
    if (isdigit(input[0]))
      asciiValue = static_cast<float>(static_cast<int>(input[0])) - 48;
    else
      asciiValue = static_cast<float>(static_cast<int>(input[0]));
    std::cout << "float: " << std::fixed << std::setprecision(1) << asciiValue
              << "f" << std::endl;
    return;
  }

  long double num = std::strtold(input.c_str(), NULL);

  std::cout << "float: ";
  if (overflowChecker(num, FLOAT))
    std::cout << "Overflowed" << std::endl;
  else {
    float fp = static_cast<float>(num);
    std::cout << std::fixed << std::setprecision(1) << fp << "f" << std::endl;
  }
}

void ScalarConverter::convertToDouble(std::string &input) {
  if (input.length() == 1 && isprint(input[0])) {
    double asciiValue;
    if (isdigit(input[0]))
      asciiValue = static_cast<double>(static_cast<int>(input[0])) - 48;
    else
      asciiValue = static_cast<double>(static_cast<int>(input[0]));
    std::cout << "double: " << std::fixed << std::setprecision(1) << asciiValue << std::endl;
    return;
  }

  long double num = std::strtold(input.c_str(), NULL);

  std::cout << "double: ";
  if (overflowChecker(num, DOUBLE))
    std::cout << "Overflowed" << std::endl;
  else {
    double dp = static_cast<double>(num);
    std::cout << std::fixed << std::setprecision(1) << dp << std::endl;
  }
}

void ScalarConverter::converterFunction(std::string &input) {
  convertToChar(input);
  convertToInt(input);
  convertToFloat(input);
  convertToDouble(input);
}

void ScalarConverter::convert(std::string &input) {
  switch (inputTypeChecker(input)) {
  case CHAR:
    // converterFunction(input);
    // break;
  case INT:
    // converterFunction(input);
    // break;
  case FLOAT:
    // converterFunction(input);
    // break;
  case DOUBLE:
    converterFunction(input);
    break;
  case PSEUDO_LITERAL:
    printPseudoLiterals(input);
    break;
  case INVALID:
    printImpossibleInput();
    break;
  }
}
