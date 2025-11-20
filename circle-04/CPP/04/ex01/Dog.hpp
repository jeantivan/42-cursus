#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog &other);
	~Dog();
	Dog &operator=(const Dog &other);

	// Required by subject
	void makeSound() const;

	// Added by me
	const Brain *getBrain() const;
};

#endif // DOG_HPP
