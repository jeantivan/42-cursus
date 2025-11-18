#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
	static const unsigned int MAX_HIT_POINTS;
	static const unsigned int MAX_ENERGY_POINTS;
	static const unsigned int MAX_ATTACK_DAMAGE;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void showStats();
};

#endif // CLAPTRAP_HPP
