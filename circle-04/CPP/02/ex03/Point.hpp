#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:


public:
	Fixed x;
	Fixed y;
	Point();
	Point(const Point &other);
	Point(const int& x,  const int& y);
	Point(const float& x,  const float& y);
	Point(const Fixed& x,  const Fixed& y);
	~Point();
	Point &operator=(const Point &other);
};

std::ostream& operator<<(std::ostream& os, const Point& p);
#endif // POINT_HPP
