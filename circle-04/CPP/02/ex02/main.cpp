#include <iostream>
#include "Fixed.hpp"


int main( void ) {
	Fixed a(5.05f);
	Fixed const b(2);
	Fixed c(0);
	Fixed d(42.42f);

	std::cout << "\n----- Arithmetic operators\n" << std::endl;
	std::cout << "Add: a " << a << " + b " << b << " = " << a + b << std::endl;
	std::cout << "Subtract: a " << a << " - d " << d << " = " << a - d << std::endl;
	std::cout << "Multi: d " << d << " * b " << b << " = " << d * b << std::endl;
	std::cout << "Div: d " << d << " / a " << a << " = " << d / a << std::endl;
	std::cout << "Div by zero: a " << a << " / c " << c << " = " << a / c << std::endl;

	std::cout << "\n----- Pre & post increment/decrement\n" << std::endl;

	Fixed x(12);

	std::cout << "Pre inc: ++x = " << ++x << " x = " << x << std::endl;
	std::cout << "Post inc: x++ = " << x++ << " x = " << x << std::endl;
	Fixed y(99.9f);
	std::cout << "Pre dec: --y = " << --y << " y = " << y << std::endl;
	std::cout << "Post dec: y-- = " << y-- << " y = " << y << std::endl;

	std::cout << "\n----- Comparison operators\n" << std::endl;

	Fixed n(32);
	Fixed m(32);
	Fixed p(42);
	Fixed q(42);

	std::cout << "'<': n (" << n << ") <  p (" << p << ") : " << (n < p) << std::endl;
	std::cout << "'>': m (" << m << ") >  p (" << p << ") : " << (m > p) << std::endl;
	std::cout << "'<=': p (" << p << ") <=  q (" << q << ") : " << (p <= q) << std::endl;
	std::cout << "'>=': q (" << p << ") >=  n (" << n << ") : " << (p >= n) << std::endl;
	std::cout << "'==': p (" << p << ") <=  q (" << q << ") : " << (p == q) << std::endl;
	std::cout << "'!=': p (" << p << ") !=  m (" << m << ") : " << (p != m) << std::endl;

	std::cout << "\n----- Function max & min\n" << std::endl;
	std::cout << "'max': Fixed::max(" << a << ", " << b << ") = " << Fixed::max( a, b ) << std::endl;
	std::cout << "'min': Fixed::min(" << y << ", " << d << ") = " << Fixed::min( y, d ) << std::endl;

	return (0);
}
