#include "iter.hpp"
#include <iostream>

template <typename T> void addTwo(T &num) { num += 2; }

int main(int argc, char **argv) {

  (void)argv;
  
  if (argc != 1)
  {
    std::cout << "Invalid input. Valid input: './Iter'" << std::endl;
    return 1;
  }
  std::cout << std::endl << "---------- int array -----------" << std::endl;
  int intArr[] = {1, 2, 3, 4, 5};
  std::cout << "Before: ";
  for (size_t i = 0; i < (sizeof(intArr) / sizeof(int)); i++)
    std::cout << intArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(intArr, sizeof(intArr) / sizeof(int), addTwo<int>);

  for (size_t i = 0; i < (sizeof(intArr) / sizeof(int)); i++)
    std::cout << intArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- float array -----------" << std::endl;
  float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  std::cout << "Before: ";
  for (size_t i = 0; i < (sizeof(floatArr) / sizeof(float)); i++)
    std::cout << floatArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(floatArr, sizeof(floatArr) / sizeof(float), addTwo<float>);

  for (size_t i = 0; i < (sizeof(floatArr) / sizeof(float)); i++)
    std::cout << floatArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- double array -----------" << std::endl;
  double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Before: ";
  for (size_t i = 0; i < (sizeof(doubleArr) / sizeof(double)); i++)
    std::cout << doubleArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(doubleArr, sizeof(doubleArr) / sizeof(double), addTwo<double>);

  for (size_t i = 0; i < (sizeof(doubleArr) / sizeof(double)); i++)
    std::cout << doubleArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- char array -----------" << std::endl;
  char charArr[] = {'a', 'b', 'c', 'd', 'e'};
  std::cout << "Before: ";
  for (size_t i = 0; i < (sizeof(charArr) / sizeof(char)); i++)
    std::cout << charArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(charArr, sizeof(charArr) / sizeof(char), addTwo<char>);

  for (size_t i = 0; i < (sizeof(charArr) / sizeof(char)); i++)
    std::cout << charArr[i] << "  ";
  std::cout << std::endl;
  return 0;
}
