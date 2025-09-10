#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Oh no! Another zombie!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " was killed!" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

