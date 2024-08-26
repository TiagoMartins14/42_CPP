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

static int decimalCount(const std::string &input) {
  size_t dotPos = input.find('.');
  if (dotPos == std::string::npos)
    return 1;
  return input.length() - dotPos - 1;
}

static void printChar(const std::string &input) {
  std::cout << "char: ";
  if (inputTypeChecker(input) == CHAR) {
    std::cout << input;
  } else if (inputTypeChecker(input) == INT ||
             inputTypeChecker(input) == FLOAT ||
             inputTypeChecker(input) == DOUBLE) {
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
  std::cout << "double: ";
  if (input == "+inf" || input == "+inff")
    std::cout << std::numeric_limits<double>::infinity();
  else if (input == "-inf" || input == "-inff")
    std::cout << -std::numeric_limits<double>::infinity();
  else if (input == "nan" || input == "nanf")
    std::cout << std::numeric_limits<double>::quiet_NaN();
  else {

    std::stringstream ss(input);
    double num;

    ss >> num;
    if (inputTypeChecker(input) == DOUBLE)
      std::cout << input;
    else if (!ss.fail()) {
      if (inputTypeChecker(input) == FLOAT)
        std::cout.precision(decimalCount(input) - 1);
      else
        std::cout.precision(decimalCount(input));
      std::cout << std::fixed << std::showpoint << static_cast<double>(num);
    } else
      std::cout << "impossible";
  }
  std::cout << std::endl;
}

static void printFloat(const std::string &input) {
  std::cout << "float: ";
  if (input == "+inf" || input == "+inff")
    std::cout << std::numeric_limits<double>::infinity() << "f";
  else if (input == "-inf" || input == "-inff")
    std::cout << -std::numeric_limits<double>::infinity() << "f";
  else if (input == "nan" || input == "nanf")
    std::cout << std::numeric_limits<double>::quiet_NaN() << "f";
  else {
    std::stringstream ss(input);
    float num;

    ss >> num;
    if (inputTypeChecker(input) == FLOAT)
      std::cout << input;
    else if (!ss.fail()) {
      std::cout.precision(decimalCount(input));
      std::cout << std::fixed << std::showpoint << static_cast<float>(num)
                << "f";
    } else
      std::cout << "impossible";
  }
  std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
  printChar(input);
  printInt(input);
  printFloat(input);
  printDouble(input);
}
