#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Class WrongCat created with default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Class WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Class WrongCat destructor called" << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "meeeeee meee meeeeeee" << std::endl;
}
