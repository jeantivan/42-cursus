#include <iostream>
#include "FragTrap.hpp"

int main() {
	std::cout << "=== Creación por defecto ===" << std::endl;
    FragTrap ft1;

    std::cout << "\n=== Creación con nombre ===" << std::endl;
    FragTrap ft2("Bob");

    std::cout << "\n=== Copia de objeto (constructor de copia) ===" << std::endl;
    FragTrap ft3(ft2);

    std::cout << "\n=== Asignación de objetos (operator=) ===" << std::endl;
    ft1 = ft3;

    std::cout << "\n=== Prueba de método especial ===" << std::endl;
    ft2.highFivesGuys();

    std::cout << "\n=== Prueba de método heredado ===" << std::endl;
    FragTrap ft4("Alex");
    ft4.attack(ft3.getName());
    ft4.showStats();

    std::cout << "\n=== Fin del main, comienza destrucción ===" << std::endl;
	return 0;
}
