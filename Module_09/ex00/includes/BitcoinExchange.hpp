#pragma once
#include <cerrno>
#include <cstdlib>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
   private:
	std::map<std::string, std::string> _dailyValues;
	std::map<std::string, std::string> _dailyExchangeRates;

   public:
	BitcoinExchange(std::map<std::string, std::string> &dailyValues,
					std::map<std::string, std::string> &dailyExchangeRates);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	float stringToFloat(const std::string &str);

	float getExchangeRate(
		std::map<std::string, std::string> &dailyValues,
		std::map<std::string, std::string> &dailyExchangeRates);

	float calculateExchange(float value, float exchangeRate);

	void printDailyExchange(float);
};
