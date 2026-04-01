#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#define FILE_NAME "data1.csv"

class BitcoinExchange
{
private:
	std::ifstream _file;
	std::map<std::string, float> _exchangeRates;

	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &value) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void readFile();
	void printExchangeRates() const;
};

#endif // BITCOINEXCHANGE_HPP
