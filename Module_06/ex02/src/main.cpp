#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
	std::srand(std::time(0));
	int randomNum = std::rand() % 3;

	switch (randomNum) {
		case 0:
			return new A;

		case 1:
			return new B;

		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow type!" << std::endl;
}

void identify(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow type!" << std::endl;
}

int main() {
	Base* p = generate();

	std::cout << "Identify via pointer: ";
	identify(*p);

	std::cout << "Identify via reference: ";
	identify(*p);

	delete p;

	return 0;
}
