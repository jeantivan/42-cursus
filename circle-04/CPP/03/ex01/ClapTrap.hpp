#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
// Attributes
protected:
	std::string _name;
	static const unsigned int MAX_HIT_POINTS;
	static const unsigned int MAX_ENERGY_POINTS;
	static const unsigned int MAX_ATTACK_DAMAGE;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

// Member functions
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

protected:
	ClapTrap(const std::string name, const unsigned int hit_points, const unsigned int energy_point, const unsigned int attack_damage);
};

#endif // CLAPTRAP_HPP
