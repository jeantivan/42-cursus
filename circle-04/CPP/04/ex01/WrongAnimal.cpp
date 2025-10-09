#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "Class WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string t) : type(t) {
	std::cout << "Class WrongAnimal parameterized constructor: type = " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {

	std::cout << "Class WrongAnimal copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Class WrongAnimal assignment operator called" << std::endl;
	return (*this);
}


WrongAnimal::~WrongAnimal() {
	std::cout << "Class WrongAnimal default destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}
