#include <iostream>

#include "ScavTrap.hpp"

int main() {
	std::string const names[] = { "Goku", "Vegeta", "Gohan", "Trunks"};
	size_t const totNames(sizeof(names) / sizeof(std::string));

	ScavTrap  * robots[totNames];

	std::cout << "Test constructors" << std::endl;
	for (size_t  i = 0; i  < totNames; i++)
	{
		robots[i] = new ScavTrap(names[i]);
	}
	std::cout << std::endl;

	std::cout << "Test copy constructors" << std::endl;
	ScavTrap gohan(*robots[2]);
	ScavTrap trunks = *robots[3];

	std::cout << std::endl;

	std::cout << "Test inherit functions" << std::endl;
	robots[3]->attack(robots[0]->getName());
	gohan.attack(robots[0]->getName());
	robots[0]->takeDamage(robots[3]->getAttackDamage());
	robots[0]->takeDamage(gohan.getAttackDamage());

	robots[0]->beRepaired(30);
	std::cout << "ScavTrap: " << robots[0]->getName() << " health " << robots[0]->getHitPoints() << std::endl;

	std::cout << std::endl;

	std::cout << "Test new functions" << std::endl;
	robots[1]->guardGate();
	robots[3]->guardGate();

	robots[1]->leaveGate();
	robots[2]->leaveGate();

	std::cout << std::endl;


	std::cout << "Test destructors" << std::endl;
	for (size_t  i = 0; i  < totNames; i++)
	{
		delete robots[i];
	}
	return (0);
}
