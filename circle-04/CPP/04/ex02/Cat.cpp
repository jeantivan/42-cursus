#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Class Cat created with default constructor" << std::endl;
	brain = new Brain();
	std::cout << "Creating ideas for Cat object" << std::endl;

}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Class Cat copy constructor called" << std::endl;
	std::cout << "Copying ideas of Cat object" << std::endl;
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
		std::cout << "Copying ideas of Cat object" << std::endl;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "miaaau miaaau" << std::endl;
}

std::string Cat::getType() const {
	return (Animal::getType());
}
