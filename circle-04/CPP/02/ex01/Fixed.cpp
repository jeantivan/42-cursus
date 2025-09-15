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

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	val = n << fract_bits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	val = static_cast<int>(round(n * (1 << fract_bits)));
}


Fixed::~Fixed() {
	std::cout << "Destructor called!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->val = other.val;
	}
	return *this;
}

int Fixed::toInt() const {
	return (val >> fract_bits);
}

float Fixed::toFloat() const {
	return static_cast<float>(val) / (1 << fract_bits);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return val;
}

void Fixed::setRawBits(int const raw) {
	val = raw;
}


std::ostream& operator<<(std::ostream& os, const Fixed& n) {
	os << n.toFloat();
	return os;
}
