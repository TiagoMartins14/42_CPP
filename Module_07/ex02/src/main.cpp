#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char **) {

  std::cout << "Creating an empty array..... ";
  Array<int> emptyArray;
  std::cout << "SUCCESS!" << std::endl;
  std::cout << std::endl;

  std::cout << "Creating 'Array<int> numbers(MAX_VAL)' and 'int* mirror = new "
               "int[MAX_VAL]'..... ";
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  std::cout << "SUCCESS!" << std::endl;
  std::cout << std::endl;

  std::cout << "Comparing two arrays ('numbers' and 'mirror')..... ";
  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  std::cout << "SUCCESS!" << std::endl;
  std::cout << std::endl;

  {
    std::cout << "Creating 'Array<int> tmp'" << std::endl;
    std::cout << "Assigning 'tmp = numbers'" << std::endl;
    std::cout << "Creating 'Array<int> test(tmp)'" << std::endl;
    Array<int> tmp;
    tmp = numbers;
    Array<int> test(tmp);
    std::cout << "....." << std::endl;
    std::cout << "SUCCESS!" << std::endl;
    std::cout << std::endl;

    std::cout << "Comparing Two arrays ('test' and 'tmp')..... ";
    for (int i = 0; i < MAX_VAL; i++) {
      if (test[i] != tmp[i]) {
        std::cerr << "didn't save the same value!!" << std::endl;
        return 1;
      }
    }
    std::cout << "SUCCESS!" << std::endl;
    std::cout << std::endl;
  }

  std::cout
      << "Requesting an index (-2) from 'numbers' that is out of bounds..."
      << std::endl;
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }
  std::cout << std::endl;

  std::cout
      << "Requesting an index (MAX_VAL) from 'numbers' that is out of bounds..."
      << std::endl;
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }

  delete[] mirror;
  return 0;
}
