#include "Triangle.hpp"

Triangle::Triangle() : _a(Point(0, 0)) , _b(Point(0, 0)), _c(Point(0, 0)) {}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c) {}

Triangle::Triangle(const Triangle& other) : _a(other._a), _b(other._b), _c(other._c) {}

Triangle &Triangle::operator=(const Triangle& other) {
	if (this != &other) {
		this->_a = other._a;
		this->_b = other._b;
		this->_a = other._c;
	}
	return *this;
}

Triangle::~Triangle() {}

void Triangle::contains(const Point& p) {

	Fixed dab = (_b.x - _a.x) * (p.y - _a.y) - (_b.y - _a.y) * (p.x - _a.x);
	Fixed dbc = (_c.x - _b.x) * (p.y - _b.y) - (_c.y - _b.y) * (p.x - _b.x);
	Fixed dca = (_a.x - _c.x) * (p.y - _c.y) - (_a.y - _c.y) * (p.x - _c.x);

	// std::cout << "dab " << dab << std::endl;
	// std::cout << "dbc " << dbc << std::endl;
	// std::cout << "dca " << dca << std::endl;

	bool allPos = (dab > 0) && (dbc > 0) && (dca > 0);
	bool allNeg = (dab < 0) && (dbc < 0) && (dca < 0);

	std:: cout << "The point P " << p;
	if (!(allPos && allNeg))
		std::cout << " is inside";
	else
		std::cout << " is not inside";
	std::cout << " (" << allPos << " " << allNeg << ")";
	std::cout << " the triangle formed by A " << _a << " b " << _b << " c " << _c << std::endl;
}
