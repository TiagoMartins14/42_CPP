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
			std::cout << "Class A generated!" << std::endl;
			return new A;

		case 1:
			std::cout << "Class B generated!" << std::endl;
			return new B;

		case 2:
			std::cout << "Class C generated!" << std::endl;
			return new C;

		default:
			return NULL;
	}
}

void identify(Base* p) {
	std::cout << "Identify via pointer: ";
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
	std::cout << "Identify via reference: ";
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type!" << std::endl;
}

int main() {
	std::cout << "---- Testing valid bases ----" << std::endl << std::endl;
	Base* p = generate();
	Base* base = new Base();

	identify(*p);
	identify(p);

	std::cout << std::endl;
	std::cout << "---- Testing invalid bases ----" << std::endl << std::endl;
	identify(*base);
	identify(base);
	identify(NULL);

	delete p;
	delete base;

	return 0;
}
