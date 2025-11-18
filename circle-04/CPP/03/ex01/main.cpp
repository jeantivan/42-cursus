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


	// std::cout << "\n---- Named constructor\n";
	// // Named Constructor
	// ScavTrap goku("Goku");
	// std::cout << "\n";

	// // Copy constructor
	// ClapTrap * vegeta = new ScavTrap("Vegeta");
	// std::cout << "\n";

	// // Default constructor
	// ScavTrap trunks;
	// std::cout << "\n";

	// // Magic to use the operator '='
	// trunks = *static_cast<ScavTrap *>(vegeta);
	// std::cout << "\n";
	// trunks = ScavTrap("Trunks");
	// std::cout << "\n";

	// // Inherited function
	// goku.showStats();
	// std::cout << "\n";

	// vegeta->showStats();
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// goku.attack(vegeta->getName());
	// std::cout << "\n";

	// vegeta->takeDamage(goku.getAttackDamage());
	// std::cout << "\n";

	// vegeta->attack(trunks.getName());
	// std::cout << "\n";

	// trunks.takeDamage(vegeta->getAttackDamage());
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// trunks.beRepaired(vegeta->getAttackDamage());
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// trunks.takeDamage(42);
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// trunks.beRepaired(84);
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// trunks.beRepaired(310);
	// std::cout << "\n";

	// trunks.showStats();
	// std::cout << "\n";

	// // Own functions
	// goku.guardGate();
	// std::cout << "\n";

	// goku.guardGate();
	// std::cout << "\n";

	// (static_cast<ScavTrap *>(vegeta))->guardGate();
	// std::cout << "\n";

	// goku.leaveGate();
	// std::cout << "\n";

	// (static_cast<ScavTrap *>(vegeta))->leaveGate();
	// std::cout << "\n";

	// // Free de ScavTrap pointer
	// delete vegeta;
	return (0);
}
