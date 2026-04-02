#include <iostream>
#include "BitcoinExchange.hpp"

int main()
{
	try {
		BitcoinExchange exchange("data.csv");
		exchange.printExchangeRates();
	} catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
