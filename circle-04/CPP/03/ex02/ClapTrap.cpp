#include "ClapTrap.hpp"

const unsigned int ClapTrap::MAX_HIT_POINTS = 10;
const unsigned int ClapTrap::MAX_ENERGY_POINTS = 10;
const unsigned int ClapTrap::MAX_ATTACK_DAMAGE = 0;

ClapTrap::ClapTrap() : _name("Default"), _hit_points(MAX_HIT_POINTS), _energy_points(MAX_ENERGY_POINTS), _attack_damage(MAX_ATTACK_DAMAGE) {
	std::cout << "I'm " << _name << " ready to fight! " << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(MAX_HIT_POINTS), _energy_points(MAX_ENERGY_POINTS), _attack_damage(MAX_ATTACK_DAMAGE) {
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

// Protected Constructor, can only be used by child classes
ClapTrap::ClapTrap( \
	const std::string name, \
	const unsigned int hit_points, \
	const unsigned int energy_points, \
	const unsigned int attack_damage) : \
	_name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
	std::cout << "ClapTrap: Protected constructor called from a child class" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energy_points > 0)
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
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take more damage. Health is " << _hit_points << std::endl;
		return ;
	}
	int new_hit_points = static_cast<int>(_hit_points) - static_cast<int>(amount);
	if (new_hit_points > 0)
		_hit_points = new_hit_points;
	else
	{
		amount = _hit_points;
		_hit_points = 0;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	std::cout << _name << " health " << _hit_points << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap "<< _name << " doesn't have enough energy to be repaired!" << std::endl;
		return;
	}

	/**
	 * 📌📌📌📌📌
	 *
	 * This cannot be used because MAX_HIT_POINTS is ClapTrap::MAX_HIT_POINTS and beRepaired should not be reimplemented in ScavTrap. so using
	 * beRepaired in ScavTrap will use 'ClapTrap::MAX_HIT_POINTS' which is different from 'ScavTrap::MAX_HIT_POINTS'
	 *
	 *if (_hit_points == MAX_HIT_POINTS)
	 *{
	 *	std::cout << "ClapTrap " << "max health points reached!" << std::endl;
	 *	return ;
	 *}
	 *
	 * */

	// if (_hit_points + amount >= MAX_HIT_POINTS)
	// 	amount = MAX_HIT_POINTS - _hit_points;
	_hit_points += amount;
	_energy_points--;
	std::cout << "ClapTrap " << _name << " regained " << amount << " health points!" << std::endl;
}

void ClapTrap::showStats() {
	std::cout << _name << " stats:\n";
	std::cout << " -- hit points: " << _hit_points << "\n";
	std::cout << " -- energy points: " << _energy_points << "\n";
	std::cout << " -- attack damage: " << _attack_damage << std::endl;
}


// Getters & Setters
std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHitPoints() const {
	return _hit_points;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energy_points;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attack_damage;
}

void ClapTrap::setName(const std::string new_name)
{
	_name = new_name;
}

void ClapTrap::setHitPoints(unsigned int n)
{
	_hit_points = n;
}

void ClapTrap::setEnergyPoints(unsigned int n)
{
	_energy_points = n;
}

void ClapTrap::setAttackDamage(unsigned int n)
{
	_attack_damage = n;
}
