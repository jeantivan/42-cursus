#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
private:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	Animal(const std::string type);
	virtual ~Animal();
	Animal &operator=(const Animal &other);

	virtual std::string getType() const;
	virtual void makeSound() const;
	virtual void makePooPoo() const = 0;
};

#endif // ANIMAL_HPP
