#include <iostream>
#include "ClapTrap.hpp"

int main()
{
{
	std::cout << "\n----  Orthodox canonical form\n" << std::endl;
	ClapTrap c1;
	ClapTrap c2("Megatron");
	ClapTrap c3("Optimus");
	c1 = c3;
}
{
	std::cout << "\n----  Testing functions\n" << std::endl;
	ClapTrap clap("Mazinger Z");

	std::cout << "\n--  Taking damage\n" << std::endl;
	clap.takeDamage(7);
	clap.takeDamage(2);
	clap.takeDamage(1);
	clap.takeDamage(2);

	std::cout << "\n--  Repairing damage\n" << std::endl;
	clap.beRepaired(2);
	clap.beRepaired(12);
	clap.beRepaired(1);

	clap.takeDamage(2);

	std::cout << "\n--  Testing copy\n" << std::endl;
	ClapTrap c3;
	c3 = clap;

	c3.takeDamage(1);
}
	return 0;
}
