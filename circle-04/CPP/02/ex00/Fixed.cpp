#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const Fixed &n)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = n;
};


Fixed::~Fixed() {
	std::cout << "Destructor called!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->val = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return val;
}

void Fixed::setRawBits(int const raw) {
	val = raw;
}
