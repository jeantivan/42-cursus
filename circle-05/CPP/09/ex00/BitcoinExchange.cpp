#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : csv_file(CSV_FILE), exchangeRates()
{
	std::ifstream cvs(csv_file.c_str());

	if (!cvs.is_open())
		throw ErrorFileException();

	loadExchangeRates(cvs);
	cvs.close();
}

BitcoinExchange::BitcoinExchange(const std::string &csv_f) : csv_file(csv_f), exchangeRates()
{
	std::ifstream cvs(csv_file.c_str());

	if (!cvs.is_open())
		throw ErrorFileException();

	loadExchangeRates(cvs);
	cvs.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : csv_file(other.csv_file), exchangeRates(other.exchangeRates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		csv_file = other.csv_file;
		exchangeRates = other.exchangeRates;
	}
	return *this;
}

const char *BitcoinExchange::ErrorFileException::what() const throw()
{
	return "Error: Could not open file";
}

const char *BitcoinExchange::InvalidFormatFileException::what() const throw()
{
	return "Error: Invalid format file";
}

void BitcoinExchange::loadExchangeRates(std::ifstream &cvs_file)
{
	bool firstLine = true;
	std::string line;
	std::string date;
	std::string value;

	while (std::getline(cvs_file, line))
	{
		std::stringstream ss(line);
		if (firstLine)
		{
			if (line != "date,exchange_rate")
				throw InvalidFormatFileException();

			firstLine = false;
			continue;
		}
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		if (!isValidDate(date) || !isValidValue(value))
		{
			throw InvalidFormatFileException();
		}
		exchangeRates[date] = std::strtof(value.c_str(), NULL);
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	std::istringstream ss(date);
	int year, month, day;
	char sep1, sep2;
	if (!(ss >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Months with 30 days: April, June, September, November
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) // February, check for leap year
	{
		// year % 4 == 0: Year have to be divisible by 4 to be a leap year.
		// year % 100 != 0: Exception if the year is divisible by 100 (like 1900), it is NOT a leap year.
		// year % 400 == 0: Exception to the exception: If the year is divisible by 400 (like 2000), it IS a leap year.
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeapYear ? 29 : 28))
			return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
	std::istringstream ss(value);
	float val;

	if (!(ss >> val))
		return false;

	char extra;
	if (ss >> extra)
		return false;

	return true;
}

void BitcoinExchange::calculate(const std::string &input_file) const
{
	std::ifstream input(input_file.c_str());

	if (!input.is_open())
		throw ErrorFileException();

	std::string line;
	std::string date;
	std::string value;
	bool firstLine = true;

	while (std::getline(input, line))
	{
		if (firstLine)
		{
			if (line != "date | value")
			{
				throw InvalidFormatFileException();
			}
			firstLine = false;
			continue;
		}
		std::stringstream ss(line);
		std::string date;
		std::string separator;
		std::string value;
		std::getline(ss, date, ' ');
		std::getline(ss, separator, ' ');
		std::getline(ss, value);

		if (separator != "|" || date.empty() || value.empty())
		{
			std::cerr << "Error: Invalid input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date => " << date << std::endl;
			continue;
		}
		float val = std::strtof(value.c_str(), NULL);
		if (!isValidValue(value))
		{
			std::cerr << "Error: Invalid value => " << value << std::endl;
			continue;
		}
		else if (val < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (val > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		// std::map::lower_bound(k) returns an iterator to the first element whose key is greater than or equal to k.
		// If the key exists: Returns an iterator pointing directly to that element.
		// If the key does not exist: Returns an iterator to the next closest element that is greater than k.
		// If there are no elements greater than or equal to k: Returns map::end().
		std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

		if (it == exchangeRates.end())
			it = --exchangeRates.end();
		else if (it != exchangeRates.begin() && it->first != date)
			it--;

		std::cout << date << " => " << val << " = " << val * it->second << std::endl;
	}
	input.close();
}

void BitcoinExchange::printExchangeRates() const
{
	for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
