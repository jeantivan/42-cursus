#include <iostream>

#include "ScavTrap.hpp"

int main() {
	std::string const names[] = { "Goku", "Vegeta", "Gohan", "Trunks"};
	size_t const totNames(sizeof(names) / sizeof(std::string));

	ScavTrap  * robots[totNames];

	std::cout << "\n---- Test constructors\n" << std::endl;
	for (size_t  i = 0; i  < totNames; i++)
	{
		robots[i] = new ScavTrap(names[i]);
		std::cout << "\n";
	}
	std::cout << std::endl;

	std::cout << "\n---- Test copy constructors" << std::endl;
	ScavTrap gohan(*robots[2]);
	std::cout << "\n";

	ScavTrap trunks("trunks");
	trunks = *robots[3];

	std::cout << std::endl;

	std::cout << "\n---- Test inherit functions" << std::endl;
	robots[3]->attack(robots[0]->getName());
	std::cout << "\n";

	gohan.attack(robots[0]->getName());
	std::cout << "\n";

	robots[0]->takeDamage(robots[3]->getAttackDamage());
	std::cout << "\n";

	robots[0]->takeDamage(gohan.getAttackDamage());
	std::cout << "\n";

	robots[0]->beRepaired(30);
	std::cout << "ScavTrap: " << robots[0]->getName() << " health " << robots[0]->getHitPoints() << std::endl;

	std::cout << std::endl;

	std::cout << "\n---- Test new functions\n" << std::endl;
	robots[1]->guardGate();
	std::cout << "\n";

	robots[3]->guardGate();
	std::cout << "\n";

	robots[1]->leaveGate();
	std::cout << "\n";

	robots[2]->leaveGate();
	std::cout << std::endl;


	std::cout << "\n---- Test destructors\n" << std::endl;
	for (size_t  i = 0; i  < totNames; i++)
	{
		delete robots[i];
		std::cout << "\n";
	}

	return (0);
}
