#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _keepperMode(false) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "(default) ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name), _keepperMode(false) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);

	std::cout << "ScavTrap: " << getName() << " created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: " << getName()  << " eliminated" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	setKeepperMode(other.getKeepperMode());

	std::cout << "ScavTrap cloned with constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		setKeepperMode(other.getKeepperMode());
	}

	std::cout << "ScavTrap operator '=' called" << std::endl;
	return (*this);
}

// Getters & Setters
bool ScavTrap::getKeepperMode() const {
	return _keepperMode;
}

void ScavTrap::setKeepperMode(bool active) {
	_keepperMode = active;
}

void ScavTrap::guardGate() {
	if (_keepperMode) {
		std::cout << "ScavTrap " << getName() << " is already guarding the gate" << std::endl;
		return ;
	}

	if (getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " doesn't have energy to guard the gate" << std::endl;
		return ;
	}

	setEnergyPoints(getEnergyPoints() - 1);
	setKeepperMode(true);
	std::cout << "ScavTrap " << getName() << " is now guarding the gate" << std::endl;
}

void ScavTrap::leaveGate() {
	if (!_keepperMode)
	{
		std::cout << "ScavTrap " << getName() << " is not guarding the gate" << std:: endl;
		return ;
	}

	_keepperMode = false;
		std::cout << "ScavTrap " << getName() << " stopped protecting the gate" << std:: endl;

}
