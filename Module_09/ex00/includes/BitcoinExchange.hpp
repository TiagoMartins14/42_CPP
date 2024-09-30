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

	template <typename T>
	const T getExchangeRate(
		std::map<std::string, std::string> &dailyValues,
		std::map<std::string, std::string> &dailyExchangeRates);

	template <typename T>
	const T calculateExchange(const T value, const T exchangeRate);

	template <typename T>
	void printDailyExchange(const T);
};
