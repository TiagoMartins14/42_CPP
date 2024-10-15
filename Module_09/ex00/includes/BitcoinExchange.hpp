#pragma once
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
   private:
	std::multimap<std::string, std::string> _dailyValues;
	std::multimap<std::string, std::string> _dailyExchangeRates;

	float stringToFloat(
		const std::multimap<std::string, std::string>::iterator &it);
	float getExchangeRate(
		const std::string &valueDate,
		std::multimap<std::string, std::string> &dailyExchangeRates);
	float calculateExchange(float value, float exchangeRate);
	void printDailyExchange(std::string date, float value, float exchangeValue);
	void trimWhiteSpaces(std::string &str);
	void split(std::string line,
			   std::multimap<std::string, std::string> &inputFileMap,
			   char delimiter);
	void printMap(const std::multimap<std::string, std::string> &myMap);

   public:
	BitcoinExchange(std::ifstream &inputFile, std::ifstream &dataFile);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	void printReport(std::ifstream &inputFile);
};
