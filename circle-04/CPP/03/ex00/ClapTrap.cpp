#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Bumblebee"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "I'm " << _name << " ready to fight! " << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "I'm " << _name << " ready to fight!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage) {
	std::cout << "A new " << _name << " has emerged!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << _name << " was destroyed!" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	std::cout << _name << " was successfully cloned!" << std::endl;
	return *this;
}


void ClapTrap::attack(const std::string &target) {
	if (_energy_points - 1 >= 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
		<< _attack_damage << " points of damage" << std::endl;
	} else
		std::cout << "ClapTrap " << _name << " does not have energy for an attack!" << std::endl;
	if (_energy_points > 0)
		_energy_points--;

	std::cout << "Remaining energy " << _energy_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	int new_hit_points = static_cast<int>(_hit_points) - static_cast<int>(amount);

	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take more damage. Health is " << _hit_points << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	if (new_hit_points > 0)
	{
		_hit_points = new_hit_points;
	}
	else
		_hit_points = 0;
	std::cout << _name << " health " << _hit_points << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap "<< _name << " doesn't have enough energy to be repaired!" << std::endl;
		return;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout << "ClapTrap " << _name << " regained " << amount << " health points!" << std::endl;
}

void ClapTrap::showStats() {
	std::cout << _name << " stats:\n";
	std::cout << " -- hit points: " << _hit_points << "\n";
	std::cout << " -- energy points: " << _energy_points << "\n";
	std::cout << " -- attack damage: " << _attack_damage << std::endl;
}
