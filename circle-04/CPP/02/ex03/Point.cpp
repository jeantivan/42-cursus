#include "Point.hpp"

Point::Point() : x(0) , y(0) {}

Point::Point(const float& x, const float& y) : x(x), y(y) {}

Point::Point(const int& x, const int& y) : x(x) , y(y) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x) , y(y) {}

Point::Point(const Point& other) : x(other.x) , y(other.y) {}

Point& Point::operator=(const Point& other)  {
	(void)other;
	return *this;
}

Point::~Point() {}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	Fixed det = (a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y);
	Fixed area = 0.5f * fabsf(det.toFloat());

	if (area <= 0)
		return false;

	Fixed dab = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
	Fixed dbc = (c.x - b.x) * (p.y - b.y) - (c.y - b.y) * (p.x - b.x);
	Fixed dca = (a.x - c.x) * (p.y - c.y) - (a.y - c.y) * (p.x - c.x);

	bool allPos = (dab > 0) && (dbc > 0) && (dca > 0);
	bool allNeg = (dab < 0) && (dbc < 0) && (dca < 0);

	return !(allPos && allNeg);
}
