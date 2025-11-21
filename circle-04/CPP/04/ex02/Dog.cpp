#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Class Dog created with default constructor" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Class Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog::~Dog() {
	std::cout << "Class Dog destructor called" << std::endl;
	delete brain;
}


Dog& Dog::operator=(const Dog &other) {
	std::cout << "Class Dog '=' operator called";
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "woof woof woof" << std::endl;
}

const Brain* Dog::getBrain() const {
	return brain;
}
