#include "Point.hpp"

Point::Point() : x(0) , y(0) {}

Point::Point(const float& x, const float& y) : x(x), y(y) {}

Point::Point(const int& x, const int& y) : x(x) , y(y) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x) , y(y) {}

Point::Point(const Point& other) : x(other.x) , y(other.y) {}

Point& Point::operator=(const Point& other)  {
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Point::~Point() {}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
