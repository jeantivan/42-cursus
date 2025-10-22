#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Class Dog created with default constructor" << std::endl;
	brain = new Brain();
	std::cout << "Creating ideas for Dog object" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Class Dog copy constructor called" << std::endl;
	std::cout << "Copying brain ideas of Dog object..." << std::endl;
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
		std::cout << "Copying brain ideas of Dog Object..." << std::endl;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "woof woof woof" << std::endl;
}

std::string Dog::getType() const {
	return (Animal::getType());
}

void Dog::makePooPoo() const {
	std::cout << "🐈💩💩" << std::endl;
}
