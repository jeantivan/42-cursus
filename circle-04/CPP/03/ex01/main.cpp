#include <iostream>

#include "ScavTrap.hpp"

int main() {
	std::cout << "\n---- Named constructor\n";
	// Named Constructor
	ScavTrap scav1("Goku");
	std::cout << "\n";

	// Copy constructor
	ClapTrap * scav2 = new ScavTrap("Vegeta");
	std::cout << "\n";

	// Default constructor
	ScavTrap scav3;
	std::cout << "\n";

	// Magic to use the operator '='
	scav3 = *static_cast<ScavTrap *>(scav2);
	std::cout << "\n";

	// Inherited function
	scav1.showStats();
	std::cout << "\n";

	scav2->showStats();
	std::cout << "\n";

	scav3.showStats();
	std::cout << "\n";

	scav1.attack(scav2->getName());
	std::cout << "\n";

	scav2->takeDamage(scav1.getAttackDamage());
	std::cout << "\n";

	return (0);
}
