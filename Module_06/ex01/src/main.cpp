#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data mazda = {"Mazda", "RX8", 2004, 3000, false};

	uintptr_t mazdaUIntPtr = Serializer::serialize(&mazda);
	std::cout << "mazda address: " << &mazda << std::endl;
	std::cout << "serialize: " << mazdaUIntPtr << std::endl;
	std::cout << "deserialize " << Serializer::deserialize(mazdaUIntPtr)
			  << std::endl;
}
