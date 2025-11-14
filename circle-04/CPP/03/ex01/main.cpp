#include <iostream>

#include "ScavTrap.hpp"

int main() {
	std::cout << "\n---- Named constructor\n";
	// Named Constructor
	ScavTrap goku("Goku");
	std::cout << "\n";

	// Copy constructor
	ClapTrap * vegeta = new ScavTrap("Vegeta");
	std::cout << "\n";

	// Default constructor
	ScavTrap trunks;
	std::cout << "\n";

	// Magic to use the operator '='
	trunks = *static_cast<ScavTrap *>(vegeta);
	std::cout << "\n";
	trunks = ScavTrap("Trunks");
	std::cout << "\n";

	// Inherited function
	goku.showStats();
	std::cout << "\n";

	vegeta->showStats();
	std::cout << "\n";

	trunks.showStats();
	std::cout << "\n";

	goku.attack(vegeta->getName());
	std::cout << "\n";

	vegeta->takeDamage(goku.getAttackDamage());
	std::cout << "\n";

	vegeta->attack(trunks.getName());
	std::cout << "\n";

	trunks.takeDamage(vegeta->getAttackDamage());
	std::cout << "\n";

	// Own functions
	goku.guardGate();
	std::cout << "\n";

	(static_cast<ScavTrap *>(vegeta))->guardGate();
	std::cout << "\n";
	// Free de ScavTrap pointer
	delete vegeta;
	return (0);
}
