#include <iostream>

#include "whatever.hpp"

template <typename T>
void swap(T &val1, T &val2) {
	T temp = val1;

	val1 = val2;
	val2 = temp;
}

int main() {
	int val1 = 5;
	int val2 = 10;

	::swap(val1, val2);

	std::cout << "val1 is " << val1 << " and val2 is " << val2 << std::endl;
	return 0;
}
