#include <iostream>

#include "whatever.hpp"

int main(int argc, char **argv) {

  	(void)argv;
  
	if (argc != 1)
	{
		std::cout << "Invalid input. Valid input: './StartWithAFewFunctions'" << std::endl;
		return 1;
	}
	int a = 2;
	int b = 3;

	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "string one";
	std::string d = "string two";

	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}
