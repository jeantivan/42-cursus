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

// Inherited functions
void ScavTrap::attack(const std::string& target)
{
	if (_energy_points - 1 > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
		<< _attack_damage << " points of damage" << std::endl;
	} else
		std::cout << "ScavTrap " << _name << " does not have energy for an attack!" << std::endl;
	if (_energy_points > 0)
		_energy_points--;

	std::cout << "Remaining energy of scav " << _energy_points << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	int new_hit_points = static_cast<int>(_hit_points) - static_cast<int>(amount);

	if (_hit_points == 0)
	{
		std::cout << "ScavTrap " << _name << " can't take more damage. Health is " << _hit_points << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	if (new_hit_points > 0)
	{
		_hit_points = new_hit_points;
	}
	else
		_hit_points = 0;
	std::cout << _name << " health " << _hit_points << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_energy_points <= 0)
	{
		std::cout << "ScavTrap "<< _name << " doesn't have enough energy to be repaired!" << std::endl;
		return;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout << "ScavTrap " << _name << " regained " << amount << " health points!" << std::endl;
}

// Own functions
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
