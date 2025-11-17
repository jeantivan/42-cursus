#include "FragTrap.hpp"

const unsigned int FragTrap::MAX_HIT_POINTS = 100;
const unsigned int FragTrap::MAX_ENERGY_POINTS = 100;
const unsigned int FragTrap::MAX_ATTACK_DAMAGE = 30;

FragTrap::FragTrap() : ClapTrap("Frag default", MAX_HIT_POINTS, MAX_ENERGY_POINTS, MAX_ATTACK_DAMAGE) {
	std::cout << "Default constructor for FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, MAX_HIT_POINTS, MAX_ENERGY_POINTS, MAX_ATTACK_DAMAGE) {
	std::cout << "FragTrap: " << _name << " created" << std::endl;
}


FragTrap::~FragTrap() {
	std::cout << "Destructor for FragTrap object" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor for FragTrap object" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Assignment operator of FragTrap object" << std::endl;
	return (*this);
}

// Override inherited functions
void FragTrap::attack(const std::string& target) {
	if (_energy_points - 1 >= 0)
		std::cout << "FragTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
	else
		std::cout << "FragTrap " << _name << " does not have energy for an attack!" << std::endl;
	if (_energy_points > 0)
		_energy_points--;
	std::cout << "Remaining energy for frag " << _energy_points << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	int new_hit_points = static_cast<int>(_hit_points) - static_cast<int>(amount);

	if (_hit_points == 0)
	{
		std::cout << "FragTrap " << " can't take more damage. Health is " << _hit_points << std::endl;
		return ;
	}
	if (new_hit_points > 0)
		_hit_points = new_hit_points;
	else
		_hit_points = 0;
	std::cout << _name << " health " << _hit_points << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_energy_points <= 0)
	{
		std::cout << "FragTrap " << _name << " doesn't have enough energy to be repaired!" << std::endl;
		return ;
	}
	if (_hit_points == MAX_HIT_POINTS)
	{
		std::cout << "FragTrap " << _name << " max health points reached!" << std::endl;
		return ;
	}
	if (_hit_points + amount >= MAX_HIT_POINTS)
		amount = MAX_HIT_POINTS - _hit_points;
	_hit_points += amount;
	_energy_points--;
	std::cout << "FragTrap " << _name << " regained " << amount << " health points!" << std::endl;
}

// Own functions
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: " << getName() << " says 'Hi Fives Guys!'" << std::endl;
}
