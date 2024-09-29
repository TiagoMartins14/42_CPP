#pragma once
#include <map>
#include <string>

class BitcoinExchange {
   private:
	std::map<std::string, std::string> _dailyValues;
	std::map<std::string, std::string> _dailyExchangeRates;

   public:
	BitcoinExchange(std::map<std::string, std::string> dailyValues,
					std::map<std::string, std::string> dailyExchangeRates);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	template <typename T>
	T calculateExchange(T value, T exchangeRate);
};
