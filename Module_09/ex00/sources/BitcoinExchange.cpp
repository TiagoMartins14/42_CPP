#include "BitcoinExchange.hpp"

#include <stdexcept>

BitcoinExchange::BitcoinExchange(std::ifstream &inputFile,
                                 std::ifstream &dataFile) {
  if (!inputFile.is_open()) {
    std::cerr << "Error: Could not open input file!" << std::endl;
    exit(1);
  }

  if (!dataFile.is_open()) {
    std::cerr << "Error: Could not open data file!" << std::endl;
    exit(2);
  }

  std::string line;

  // line.clear();
  std::getline(dataFile, line);
  while (std::getline(dataFile, line)) {
    split(line, _dailyExchangeRates, ',');
  }
}

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

void BitcoinExchange::trimWhiteSpaces(std::string &str) {
  size_t start = 0;
  while (start < str.size() && std::isspace(str[start])) {
    ++start;
  }

  size_t end = str.size();
  while (end > start && std::isspace(str[end - 1])) {
    --end;
  }
  str = str.substr(start, end - start);
}

void BitcoinExchange::split(
    std::string line, std::multimap<std::string, std::string> &inputFileMap,
    char delimiter) {
  size_t pos = line.find(delimiter);
  if (pos == std::string::npos)
    inputFileMap.insert(std::make_pair(line, "Invalid input."));
  else {
    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    trimWhiteSpaces(key);
    trimWhiteSpaces(value);
    inputFileMap.insert(std::make_pair(key, value));
  }
}

// For tests only
void BitcoinExchange::printMap(
    const std::multimap<std::string, std::string> &myMap) {
  for (std::multimap<std::string, std::string>::const_iterator it =
           myMap.begin();
       it != myMap.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
}

float BitcoinExchange::stringToFloat(
    const std::multimap<std::string, std::string>::iterator &it) {
  char *end;
  errno = 0;
  if (!(it->second).compare("Invalid input."))
    throw std::runtime_error("bad input => " + it->first);

  float number = std::strtof((it->second).c_str(), &end);

  if (end == (it->second).c_str())
    throw std::runtime_error("invalid input.");

  if (errno == ERANGE)
    throw std::runtime_error("input value " + it->second +
                             " is outside the range for float.");

  if (number < 0)
    throw std::runtime_error("not a positive number.");
  if ((it->second).find('.') == std::string::npos) {
    if (std::atol((it->second).c_str()) > 1000)
      throw std::runtime_error("too large a number.");
  }

  return number;
}

float BitcoinExchange::getExchangeRate(
    const std::string &valueDate,
    std::multimap<std::string, std::string> &dailyExchangeRates) {
  std::string oldestDate = dailyExchangeRates.begin()->first;
  std::string exchangeRateDate = "0000-00-00";

  std::multimap<std::string, std::string>::iterator it;
  for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end(); it++) {
    if (it->first < oldestDate)
      oldestDate = it->first;
  }

  if (valueDate < oldestDate)
    throw std::runtime_error("no exchange rate found for this date or older.");

  // Get the closest exchange rate date to the valueDate given;
  for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end(); it++) {
    if (it->first <= valueDate && exchangeRateDate <= it->first)
      exchangeRateDate = it->first;
  }

  // Get the exchange rate for the closest found date
  for (it = dailyExchangeRates.begin(); it != dailyExchangeRates.end(); it++) {
    if (it->first == exchangeRateDate)
      return stringToFloat(it);
  }
  return 0;
}

float BitcoinExchange::calculateExchange(float value, float exchangeRate) {
  return (value * exchangeRate);
}

void BitcoinExchange::printDailyExchange(std::string date, float value,
                                         float exchangeValue) {
  if (value == static_cast<int>(value))
    std::cout << date << " => " << static_cast<int>(value) << " = "
              << exchangeValue << std::endl;
  else
    std::cout << date << " => " << value << " = " << exchangeValue << std::endl;
}

bool BitcoinExchange::isLeapYear(const int &year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::isValidDate(const std::string &date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    throw std::runtime_error("invalid date.");

  int year, month, day;
  char dash1, dash2;
  std::stringstream ss(date);

  ss >> year >> dash1 >> month >> dash2 >> day;

  if (ss.fail() || dash1 != '-' || dash2 != '-')
    throw std::runtime_error("invalid date.");

  if (month < 1 || month > 12)
    throw std::runtime_error("invalid date.");

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (isLeapYear(year))
    daysInMonth[1] = 29;

  if (day < 1 || day > daysInMonth[month - 1])
    throw std::runtime_error("invalid date.");

  return;
}

void BitcoinExchange::printReport(std::ifstream &inputFile) {
  std::string line;
  std::getline(inputFile, line);

  while (std::getline(inputFile, line)) {
    split(line, _dailyValues, '|');
    std::multimap<std::string, std::string>::iterator it;
    it = _dailyValues.begin();
    std::string date = it->first;
    try {
      float value = stringToFloat(it);
      isValidDate(date);
      float exchangeRate = getExchangeRate(it->first, _dailyExchangeRates);
      float exchangeValue = calculateExchange(value, exchangeRate);

      printDailyExchange(date, value, exchangeValue);
    } catch (const std::runtime_error &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      std::cerr.flush();
    }
    _dailyValues.clear();
  }
}
