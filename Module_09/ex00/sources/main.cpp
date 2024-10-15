#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Invalid input! Valid input: ./btc [file_name].txt"
				  << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	std::ifstream dataFile("data.csv");

	BitcoinExchange exchangeCalculator(inputFile, dataFile);
	exchangeCalculator.printReport(inputFile);
}
