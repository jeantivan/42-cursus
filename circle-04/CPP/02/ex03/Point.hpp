#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Point &operator=(const Point &other);

public:
	Fixed const x;
	Fixed const y;
	Point();
	Point(const Point &other);
	Point(const int& x,  const int& y);
	Point(const float& x,  const float& y);
	Point(const Fixed& x,  const Fixed& y);
	~Point();

};

std::ostream& operator<<(std::ostream& os, const Point& p);
bool bsp(const Point a, const Point b, const Point c, const Point p);

#endif // POINT_HPP
