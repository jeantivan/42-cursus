#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Class Animal default constructor" << std::endl;
}

Animal::Animal(const std::string t) : type(t) {
	std::cout << "Class Animal parameterized constructor: type = " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {

	std::cout << "Class Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Class Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Class Animal destructor" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound!" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}
