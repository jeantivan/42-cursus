#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "Point.hpp"

class Triangle
{
private:
	Point _a;
	Point _b;
	Point _c;

public:
	Triangle();
	Triangle(const Triangle &other);
	Triangle(const Point& a, const Point& b, const Point& c);
	~Triangle();
	Triangle &operator=(const Triangle &other);

	void contains(const Point& p);
};

#endif // TRIANGLE_HPP
