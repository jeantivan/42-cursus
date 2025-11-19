#include <iostream>

#include "ScavTrap.hpp"

int main() {
{
	std::cout << "\n---- Test Canonical orthodox form ----\n";

	std::cout << "\n-- Default constructor\n";
	ScavTrap scav_def;

	std::cout << "\n-- Parameter constructor\n";
	ScavTrap scav_parameter("Parameter");

	std::cout << "\n-- Copy constructor\n";
	ScavTrap scav_temp("Copy");
	ScavTrap scav_copy(scav_temp);

	std::cout << "\n-- Assign operator\n";
	ScavTrap scav_temp2("Assign");
	ScavTrap scav_assign;
	scav_assign = scav_temp2;

	std::cout << "\n-- Destructors\n";
}

{
	std::cout << "\n---- Test Inheritance ----\n";

	std::cout << "\n-- Show new stats\n\n";
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");

	std::cout << "\n";

	claptrap.showStats();
	scavtrap.showStats();

	std::cout << "\n-- Test attack\n\n";
	claptrap.attack(scavtrap.getName());
	scavtrap.attack(claptrap.getName());

	std::cout << "\n-- Test beRepaired & takeDamage\n\n";
	claptrap.takeDamage(scavtrap.getAttackDamage());
	scavtrap.takeDamage(claptrap.getAttackDamage());
	claptrap.beRepaired(42);
	claptrap.showStats();
	scavtrap.beRepaired(42);
	scavtrap.showStats();

	std::cout << "\n---- Begin destruction\n";

}

{
	std::cout << "\n---- Test Inheritance with pointer ----\n\n";
	ClapTrap *claptrap = new ClapTrap("Clap-PTR");
	ClapTrap *scavtrap = new ScavTrap("Scav-PTR");

	std::cout << "\n-- Showing stats\n\n";

	claptrap->showStats();
	std::cout << "\n";
	// Here showStats is inhereted from ClapTrap
	scavtrap->showStats();
	std::cout << "\n";

	std::cout << "\n-- Attacking\n\n";

	claptrap->attack("Nothing");
	std::cout << "\n";
	// Here attack is overwritten by ScavTrap implementation;
	scavtrap->attack("Again nothing");
	std::cout << "\n";


	std::cout << "\n-- Taking damage\n\n";
	// The member functions 'takeDamage' and 'beRepaired' are inhereted from ClapTrap
	claptrap->takeDamage(3);
	std::cout << "\n";

	scavtrap->takeDamage(42);
	std::cout << "\n";

	std::cout << "\n-- Repairing damage\n\n";

	claptrap->beRepaired(5);
	std::cout << "\n";

	scavtrap->beRepaired(42 * 10);
	std::cout << "\n";

	claptrap->showStats();
	std::cout << "\n";

	scavtrap->showStats();
	std::cout << "\n";

	std::cout << "\n-- Guarding gate\n\n";
	static_cast<ScavTrap *>(scavtrap)->guardGate();

	static_cast<ScavTrap *>(scavtrap)->guardGate();

	static_cast<ScavTrap *>(scavtrap)->leaveGate();

	static_cast<ScavTrap *>(scavtrap)->leaveGate();

	std::cout << "\n-- Freeing pointers\n\n";

	delete claptrap;
	delete scavtrap;
}
	return (0);
}
