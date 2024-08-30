#include "iter.hpp"
#include <iostream>

template <typename T> void duplicate(T &num) { num += 2; }

int main() {

  std::cout << std::endl << "---------- int array -----------" << std::endl;
  int intArr[] = {1, 2, 3, 4, 5};
  std::cout << "Before: ";
  for (int i = 0; i < 5; i++)
    std::cout << intArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(intArr, 5, duplicate<int>);

  for (int i = 0; i < 5; i++)
    std::cout << intArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- float array -----------" << std::endl;
  float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  std::cout << "Before: ";
  for (int i = 0; i < 5; i++)
    std::cout << floatArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(floatArr, 5, duplicate<float>);

  for (int i = 0; i < 5; i++)
    std::cout << floatArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- double array -----------" << std::endl;
  double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Before: ";
  for (int i = 0; i < 5; i++)
    std::cout << doubleArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(doubleArr, 5, duplicate<double>);

  for (int i = 0; i < 5; i++)
    std::cout << doubleArr[i] << "  ";
  std::cout << std::endl;

  std::cout << std::endl << "---------- char array -----------" << std::endl;
  char charArr[] = {'a', 'b', 'c', 'd', 'e'};
  std::cout << "Before: ";
  for (int i = 0; i < 5; i++)
    std::cout << charArr[i] << "  ";
  std::cout << std::endl;
  std::cout << "After:  ";
  iter(charArr, 5, duplicate<char>);

  for (int i = 0; i < 5; i++)
    std::cout << charArr[i] << "  ";
  std::cout << std::endl;
  return 0;
}
