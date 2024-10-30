#include <vector>

#include "easyfind.hpp"



int main() {
	int intArr[] = {1, 2, 3, 4, 5, 5};
	std::vector<int> intContainer(intArr, intArr + 5);

	std::cout << "----- Testing with vector<int> -----" << std::endl << std::endl;

	std::cout << "std::vector<int> intContainer = {1, 2, 3, 4, 5, 5}" << std::endl << std::endl;

	easyfind(intContainer, 0);
	easyfind(intContainer, 1);
	easyfind(intContainer, 2);
	easyfind(intContainer, 3);
	easyfind(intContainer, 4);
	easyfind(intContainer, 5);
	easyfind(intContainer, 5);
	easyfind(intContainer, 6);
	easyfind(intContainer, -100);

	std::cout << std::endl;

	char charArr[] = {'b', 'c', 'd', 'e', 'f'};
	std::vector<char> charContainer(charArr, charArr + 5);

	std::cout << "----- Testing with vector<char> -----" << std::endl << std::endl;

	std::cout << "std::vector<char> charContainer = {'b', 'c', 'd', 'e', 'f'}" << std::endl << std::endl;

	easyfind(charContainer, 'a');
	easyfind(charContainer, 'b');
	easyfind(charContainer, 'c');
	easyfind(charContainer, 'd');
	easyfind(charContainer, 'e');
	easyfind(charContainer, 'f');
	easyfind(charContainer, 'g');

	return 0;
}
