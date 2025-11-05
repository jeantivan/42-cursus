#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	const Weapon& _weapon;
public:
	HumanA(std::string name, const Weapon& _weapon);
	~HumanA();

	void attack();
};

#endif // HUMANA_HPP
