#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed() : val(0) {
}

Fixed::Fixed(const Fixed &n)
{
	*this = n;
};

Fixed::Fixed(const int n) {
	val = n << fract_bits;
}

Fixed::Fixed(const float n) {
	val = static_cast<int>(round(n * (1 << fract_bits)));
}


Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {

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
	return val;
}

void Fixed::setRawBits(int const raw) {
	val = raw;
}


std::ostream& operator<<(std::ostream& os, const Fixed& n) {
	os << n.toFloat();
	return os;
}

// Pre & Pos in/decrement
Fixed& Fixed::operator++() {
	val += (1 << fract_bits);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	val += (1 << fract_bits);
	return temp;
}

Fixed& Fixed::operator--() {
	val -= (1 << fract_bits);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	val -= (1 << fract_bits);
	return temp;
}

// Comparison operators
bool Fixed::operator<(const Fixed& other) {
	return val < other.val;
}

bool Fixed::operator>(const Fixed& other) {
	return val > other.val;
}

bool Fixed::operator<=(const Fixed& other) {
	return val <= other.val;
}

bool Fixed::operator>=(const Fixed& other) {
	return val >= other.val;
}

bool Fixed::operator==(const Fixed& other) {
	return val == other.val;
}

bool Fixed::operator!=(const Fixed& other) {
	return val != other.val;
}


// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.val = val + other.val;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;

	result.val = val - other.val;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;

	long temp = (static_cast<long>(val) * static_cast<long>(other.val)) >> fract_bits;
	result.val = static_cast<int>(temp);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;

	long temp;
	if (other.val == 0)
	{
		std::cerr << "Error division by 0 is forbidden" << std::endl;
		result.val = 0;
	}
	else {
		temp = (static_cast<long>(val) << fract_bits)  / static_cast<long>(other.val);
		result.val = static_cast<int>(temp);
	}
	return result;
}

// Min & Max member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a.val < b.val)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.val < b.val)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a.val > b.val)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.val > b.val)
		return a;
	return b;
}
