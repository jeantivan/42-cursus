#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon weapon = Weapon("sword");

		HumanA Bob("Bob", weapon);
		Bob.attack();
		weapon.setType("pistol");
		Bob.attack();
	}

	{
		Weapon weapon = Weapon("pistol");
		HumanB tito = HumanB("Tito");
		tito.attack();
		tito.setWeapon(weapon);
		tito.attack();
		weapon.setType("knife");
		tito.attack();
	}
	return (0);
}
