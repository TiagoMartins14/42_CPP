#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid input. Valid input: ONE <char> or <int> or <double> "
                 "or <float>"
              << std::endl;
    return 1;
  }
  std::string input = argv[1];
  ScalarConverter::convert(input);
  return 0;
}
