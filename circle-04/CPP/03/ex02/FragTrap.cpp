#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Default constructor for FragTrap" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor for FragTrap object" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Parameter constructor for FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor for FragTrap object" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Assignment operator of FragTrap object" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: " << getName() << " says 'Hi Fives Guys!'" << std::endl;
}

