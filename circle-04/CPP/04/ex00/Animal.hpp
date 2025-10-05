#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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

	std::string getType() const;
	virtual void makeSound() const;
};

#endif // ANIMAL_HPP
