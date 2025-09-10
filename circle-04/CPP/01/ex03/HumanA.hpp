#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	const std::string& _weapon;
public:
	HumanA(std::string name, Weapon _weapon);
	~HumanA();

	void attack();
};

#endif // HUMANA_HPP
