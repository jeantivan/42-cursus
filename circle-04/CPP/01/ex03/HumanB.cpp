#include "HumanB.hpp"

HumanB::HumanB() : _name(""), _weapon(NULL) {}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon) {}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon == NULL)
		std::cout << _name << " is unarmed! Bare-handed attack!" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
