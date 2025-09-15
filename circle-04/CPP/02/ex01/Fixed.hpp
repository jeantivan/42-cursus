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

	// operators
	Fixed& operator=(const Fixed& other);

	// Members functions
	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& n);
#endif // FIXED_HPP
