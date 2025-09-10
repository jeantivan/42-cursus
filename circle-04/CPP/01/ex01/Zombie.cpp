#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
	std::cout << "Oh no! Another default zombie!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Oh no! Another named zombie!" << std::endl;
}


Zombie::~Zombie() {
	std::cout << _name << " was killed!" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

