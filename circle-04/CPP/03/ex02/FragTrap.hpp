#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"



#endif // FRAGTRAP_HPP
class FragTrap : public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(const FragTrap &other);
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);
	FragTrap(const std::string name);

	void highFivesGuys();
};
