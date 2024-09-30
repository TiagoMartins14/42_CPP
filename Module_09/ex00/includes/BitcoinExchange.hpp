#pragma once
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
   private:
	std::map<std::string, std::string> _dailyValues;
	std::map<std::string, std::string> _dailyExchangeRates;

	float stringToFloat(const std::string &str);
	float getExchangeRate(
		const std::string &valueDate,
		std::map<std::string, std::string> dailyExchangeRates);
	float calculateExchange(float value, float exchangeRate);
	void printDailyExchange(std::string date, float value, float exchangeValue);

   public:
	BitcoinExchange(std::map<std::string, std::string> &dailyValues,
					std::map<std::string, std::string> &dailyExchangeRates);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	void printReport();
};
