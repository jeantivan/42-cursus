#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Class Cat created with default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Class Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Class Cat destructor called" << std::endl;
}


Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "miaaau miaaau" << std::endl;
}
