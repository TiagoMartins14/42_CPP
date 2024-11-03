#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc < 2)
		std::cerr << "Invalid input. Valid input: ./RPN [equation]"
				  << std::endl;
	else {
		std::string input = argv[1];

		for (std::size_t i = 2; argv[i]; i++) {
			std::string addArg = argv[i];
			input += " " + addArg;
		}

		RPN calculator(input);
		try {
			calculator.calculateResult();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
