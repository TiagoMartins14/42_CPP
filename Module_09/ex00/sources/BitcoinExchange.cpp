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

float stringToFloat(const std::string &str) {
	char *end;
	errno = 0;

	float number = std::strtof(str.c_str(), &end);

	if (end == str.c_str()) throw std::runtime_error("Invalid input.");

	if (errno == ERANGE)
		throw std::runtime_error("Input value is outside the range for float.");

	return number;
}

float getExchangeRate(std::string &valueDate,
					  std::map<std::string, std::string> &dailyExchangeRates) {
	std::string oldestDate = dailyExchangeRates.begin()->first;
	std::string exchangeRateDate = "0000-00-00";

	std::map<std::string, std::string>::iterator it;
	for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end();
		 it++) {
		if (it->first < oldestDate) oldestDate = it->first;
	}

	if (valueDate < oldestDate)
		throw std::runtime_error(
			"No exchange rate found for this date or older.");

	// Get the closest exchange rate date to the valueDate given;
	for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end();
		 it++) {
		if (it->first < valueDate && exchangeRateDate < it->first)
			exchangeRateDate = it->first;
	}

	// Get the exchange rate for the closest found date
	for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end();
		 it++) {
		if (it->first == exchangeRateDate) return stringToFloat(it->second);
	}
	return 0;
}

float BitcoinExchange::calculateExchange(float value, float exchangeRate) {
	return (value * exchangeRate);
}

void printDailyExchange(std::string date, float value, float exchangeValue) {
	if (value == static_cast<int>(value))
		std::cout << date << " => " << static_cast<int>(value) << " = "
				  << exchangeValue << std::endl;
	else
		std::cout << date << " => " << value << " = " << exchangeValue
				  << std::endl;
}
