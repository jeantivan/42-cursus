#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int val;
	static const int fract_bits;

public:
	// Constructors;
	Fixed();
	Fixed(const Fixed &n);
	Fixed(const int n);
	Fixed(const float n);

	// Destructor
	~Fixed();

	// Operators
	Fixed& operator=(const Fixed& other);

	// Arithmetic
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Comparison
	bool operator<(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

	// Pre & Pos in/decrement
	Fixed& operator++(); // Pre
	Fixed operator++(int); // Pos
	Fixed& operator--(); // Pre
	Fixed operator--(int);


	// Members functions
	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;

	// Members functions overloaded
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& n);
#endif // FIXED_HPP
