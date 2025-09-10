#include "Zombie.hpp"

int main() {
	Zombie* zombies1;
	Zombie* zombies2;

	zombies1 = zombieHorde(4, "ZEN P");
	for(int i = 0; i < 4; i++)
	{
		zombies1[i].announce();
	}
	zombies2 = zombieHorde(6, "Lil Supa");
	for(int i = 0; i < 6; i++)
	{
		zombies2[i].announce();
	}

	delete []zombies1;
	delete []zombies2;

	return (0);
}
