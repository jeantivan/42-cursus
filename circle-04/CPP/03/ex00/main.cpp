#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1;
	ClapTrap c2("Megatron");

	c2.takeDamage(7);
	c2.takeDamage(2);
	c2.takeDamage(1);
	c2.takeDamage(2);

	c2.beRepaired(2);
	c2.beRepaired(5);
	c2.beRepaired(12);
	c2.beRepaired(1);

	c2.takeDamage(2);

	ClapTrap c3;
	c3 = c2;

	c3.takeDamage(1);

	return 0;
}
