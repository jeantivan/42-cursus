#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon.getType()) {

}

HumanA::~HumanA()
{
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon << std::endl;
}
