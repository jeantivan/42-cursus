#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <csv_file>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange;
		std::string input_file = av[1];

		exchange.calculate(input_file);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
