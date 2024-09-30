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

float BitcoinExchange::calculateExchange(float value, float exchangeRate) {
	return (value * exchangeRate);
}

float stringToFloat(const std::string &str) {
	char *end;
	errno = 0;

	float number = std::strtof(str.c_str(), &end);

	if (end == str.c_str()) throw std::runtime_error("Invalid input.");

	if (errno == ERANGE)
		throw std::runtime_error("Input value is outside the range for float.");

	return number;
}

float getExchangeRate(std::map<std::string, std::string> &dailyValues,
					  std::map<std::string, std::string> &dailyExchangeRates) {}
