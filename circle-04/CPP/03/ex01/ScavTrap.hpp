#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _keepperMode;

public:
	ScavTrap();
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);
	ScavTrap(const std::string name);

	// Getters & Setters
	bool getKeepperMode() const;
	void setKeepperMode(bool active);

	// Own functions
	void guardGate();
	void leaveGate();

	// Inherited functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // SCAVTRAP_HPP
