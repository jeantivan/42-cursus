#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int val;
	static const int fract_bits;

public:
	Fixed();
	Fixed(const Fixed &n);
	~Fixed();
	Fixed& operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif // FIXED_HPP
