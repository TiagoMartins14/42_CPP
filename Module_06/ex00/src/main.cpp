#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr
        << "Invalid input. Valid input: <char> or <int> or <double> or <float>"
        << std::endl;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}
