#include <iostream>
#include "Fixed.hpp"


int main( void ) {

	std::cout << "----Default constructor\n" << std::endl;
	Fixed a;
	std::cout << std::endl;

	std::cout << "\n----Int constructor\n" << std::endl;
	Fixed const b( 10 );
	std::cout << std::endl;

	std::cout << "\n----Float constructor\n" << std::endl;
	Fixed const c( 42.42f );
	std::cout << std::endl;

	std::cout << "\n----Copy constructor\n" << std::endl;
	Fixed const d( b );
	std::cout << std::endl;

	std::cout << "\n----Assignment operator\n" << std::endl;
	a = c;
	std::cout << std::endl;


	std::cout << "\n----Fixed::toInt() member function\n" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout <<  "\n----Fixed::toFloat() member function\n" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	std::cout << "\n----'<<' Operator overload ()\n" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n----Destructors\n" << std::endl;

	return (0);
}
