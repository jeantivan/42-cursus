#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#define CSV_FILE "data1.csv"

class BitcoinExchange
{
private:
	std::string csv_file;
	std::map<std::string, float> exchangeRates;

	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &value) const;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &cvs_f);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadExchangeRates(std::ifstream &cvs_file);
	void printExchangeRates() const;

	class ErrorFileException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class InvalidFormatFileException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif // BITCOINEXCHANGE_HPP
