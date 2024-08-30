#include "Array.tpp"
#include <iostream>

int main() {

  Array<int> *intArray = new Array<int>;
  Array<float> *floatArray = new Array<float>(14);

  std::cout << intArray->size() << std::endl;
  std::cout << floatArray->size() << std::endl;

  delete intArray;
  delete floatArray;
  return 0;
}
