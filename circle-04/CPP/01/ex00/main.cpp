#include <iostream>

#include "Zombie.hpp"

int main()
{
	Zombie* zombie = newZombie("CR7");
	randomChump("Messi");
	zombie->announce();
	delete zombie;
	return (0);
}
