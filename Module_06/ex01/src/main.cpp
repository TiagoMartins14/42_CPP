#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
int main() {
  Data mazda("Mazda", "RX8", 2002, 3000, false);

  uintptr_t mazdaUIntPtr = Serializer::serialize(&mazda);
  std::cout << "mazda pointer: " << &mazda << std::endl;
  std::cout << "serialize: " << mazdaUIntPtr << std::endl;
  std::cout << "deserialize " << Serializer::deserialize(mazdaUIntPtr)
            << std::endl;
}
