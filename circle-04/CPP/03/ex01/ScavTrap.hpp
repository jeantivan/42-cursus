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
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);
	ScavTrap(const std::string name);

	// Getters & Setters
	bool getKeepperMode() const;
	void setKeepperMode(bool active);

	void guardGate();
	void leaveGate();
};

#endif // SCAVTRAP_HPP
