#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(
	std::map<std::string, std::string> &dailyValues,
	std::map<std::string, std::string> &dailyExchangeRates)
	: _dailyValues(dailyValues), _dailyExchangeRates(dailyExchangeRates) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
	: _dailyValues(copy._dailyValues),
	  _dailyExchangeRates(copy._dailyExchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		_dailyValues = copy._dailyValues;
		_dailyExchangeRates = copy._dailyExchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
