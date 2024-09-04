#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T &container, int value) {
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);

	std::cout << "The value '" << value;

	if (iter != container.end())
		std::cout << "' was found at position " << std::distance(container.begin(), iter) << std::endl;
	else
		std::cout << "' was not found inside the container" << std::endl;
}
