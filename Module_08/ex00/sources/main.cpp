#include <vector>

#include "easyfind.hpp"

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	std::vector<int> intContainer(intArr, intArr + 5);

	easyfind(intContainer, 0);
	easyfind(intContainer, 1);
	easyfind(intContainer, 2);
	easyfind(intContainer, 3);
	easyfind(intContainer, 4);
	easyfind(intContainer, 5);
	easyfind(intContainer, 6);
	easyfind(intContainer, -100);

	return 0;
}
