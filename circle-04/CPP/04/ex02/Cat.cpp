#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Class Cat created with default constructor" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Class Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat::~Cat() {
	std::cout << "Class Cat destructor called" << std::endl;
	delete brain;
}


Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "miaaau miaaau" << std::endl;
}

const Brain* Cat::getBrain() const {
	return brain;
}
