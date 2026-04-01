#include <iostream>
#include "BitcoinExchange.hpp"

int main()
{
	BitcoinExchange exchange;
	exchange.readFile();
	exchange.printExchangeRates();
	return 0;
}
