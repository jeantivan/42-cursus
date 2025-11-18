#include <iostream>
#include "ClapTrap.hpp"

int main()
{
{
	std::cout << "\n----  Orthodox canonical form\n" << std::endl;
	std::cout << "Default constructor\n";
	ClapTrap c1;
	std::cout << "\nParameter constructor\n";
	ClapTrap c2("Optimus");
	std::cout << "\nCopy constructor\n";
	ClapTrap c3(c1);
	std::cout << "\nAssign operator\n";
	c1 = c2;
	std::cout << "\nDestructor\n";
}
{
	std::cout << "\n----  Testing functions\n" << std::endl;
	ClapTrap clap("Mazinger Z");

	std::cout << "\n--  Taking damage\n" << std::endl;
	clap.takeDamage(7);
	clap.takeDamage(2);
	clap.takeDamage(1);
	clap.takeDamage(2);
	clap.showStats();

	std::cout << "\n--  Repairing damage\n" << std::endl;
	clap.beRepaired(2);
	clap.beRepaired(12);
	clap.beRepaired(1);

	clap.takeDamage(42);
	clap.showStats();
	clap.beRepaired(42);
	clap.showStats();

}
	return 0;
}
