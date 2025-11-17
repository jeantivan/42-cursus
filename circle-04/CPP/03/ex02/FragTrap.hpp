#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	static const unsigned int MAX_HIT_POINTS;
	static const unsigned int MAX_ENERGY_POINTS;
	static const unsigned int MAX_ATTACK_DAMAGE;

public:
	FragTrap();
	FragTrap(const FragTrap &other);
	virtual ~FragTrap();
	FragTrap &operator=(const FragTrap &other);
	FragTrap(const std::string name);

	// Own functions
	void highFivesGuys();

	// Inherited functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // FRAGTRAP_HPP
