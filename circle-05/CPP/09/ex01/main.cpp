#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <RPN expression>" << std::endl;
		return 1;
	}

	try
	{
		std::string expression(av[1]);
		RPN rpn;
		std::cout << rpn.evaluate(expression) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
