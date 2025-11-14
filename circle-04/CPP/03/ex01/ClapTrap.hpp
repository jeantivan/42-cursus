#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string name);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);

	// Getters & Setters
	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

	void setName(const std::string new_name);
	void setHitPoints(unsigned int n);
	void setEnergyPoints(unsigned int n);
	void setAttackDamage(unsigned int n);

	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	void showStats();
};

#endif // CLAPTRAP_HPP
