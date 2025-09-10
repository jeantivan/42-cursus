#include "Harl.hpp"


int main()
{
	Harl harl;

	std::cout << "<< DEBUG >>" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "<< INFO >>" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "<< WARNING >>" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "<< ERROR >>" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "<< WRONG_LEVEL >>" << std::endl;
	harl.complain("WRONG_LEVEL");
	std::cout << std::endl;

	return (0);
}
