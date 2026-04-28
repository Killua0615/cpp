#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &str) {
	std::string::size_type start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database file.");

	while (std::getline(file, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, pos));
		std::string rateStr = trim(line.substr(pos + 1));
		if (date.empty() || rateStr.empty())
			continue;
		char *endptr;
		double rate = std::strtod(rateStr.c_str(), &endptr);
		if (*endptr != '\0')
			continue;
		_database[date] = rate;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
	if (it == _database.begin())
		throw std::runtime_error("Error: date is before the earliest record in database.");
	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(file, line)) {
		std::cerr << "Error: empty input file." << std::endl;
		return;
	}

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		std::string::size_type pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (valueStr.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		char *endptr;
		double value = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		try {
			double rate = getExchangeRate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}
