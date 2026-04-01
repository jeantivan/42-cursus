#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_file.open(FILE_NAME);
	if (!this->_file.is_open())
	{
		std::cerr << "Error: could not open file " << FILE_NAME << std::endl;
		exit(1);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange()
{
	this->_file.close();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		// do something
	}
	(void)other;
	return *this;
}

void BitcoinExchange::readFile()
{
	bool firstLine = true;
	std::string line;
	std::string date;
	std::string value;

	while (std::getline(this->_file, line))
	{
		std::stringstream ss(line);
		if (firstLine)
		{
			if (line != "date,exchange_rate")
			{
				std::cerr << "Error: invalid file format" << std::endl;
				std::exit(1);
			}
			firstLine = false;
			continue;
		}
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		if (!isValidDate(date) || !isValidValue(value))
			continue;
		this->_exchangeRates[date] = std::strtof(value.c_str(), NULL);
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	std::istringstream ss(date);
	int year, month, day;
	char sep1, sep2;
	if (!(ss >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-' || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
	char *end;
	if (value.empty())
		return false;
	errno = 0;
	std::strtof(value.c_str(), &end);
	if (value.c_str() == end || *(end + 1) || errno != 0)
		return false;
	return true;
}

void BitcoinExchange::printExchangeRates() const
{
	for (std::map<std::string, float>::const_iterator it = this->_exchangeRates.begin(); it != this->_exchangeRates.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
