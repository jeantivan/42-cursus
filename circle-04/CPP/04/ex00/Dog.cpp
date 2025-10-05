#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Class Dog created with default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Class Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Class Dog destructor called" << std::endl;
}


Dog& Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "woof woof woof" << std::endl;
}
