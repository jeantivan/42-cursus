#include <iostream>
#include "Point.hpp"
#include "Triangle.hpp"

int main(void) {
{
	std::cout << "\nTest 1\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Triangle t(a, b, c);

	Point p(5, 3);

	t.contains(p);
}

{
	std::cout << "\nTest 2\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Triangle t(a, b, c);

	Point p(12, 5);

	t.contains(p);

}

{
	std::cout << "\nTest 3\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Triangle t(a, b, c);

	Point p(0, 0);

	t.contains(p);

}

{

	std::cout << "\nTest 4\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Triangle t(a, b, c);

	Point p(5, 0);

	t.contains(p);

}

{

	std::cout << "\nTest 5\n" << std::endl;

	Point a(0.5f, 1.0f);
	Point b(4.5f, 1.0f);
	Point c(2.5f, 5.0f);
	Triangle t(a, b, c);

	Point p(2.5f, 2.5f);

	t.contains(p);

}

{

	std::cout << "\nTest 6\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 0); // No es un triangulo real
	Triangle t(a, b, c);

	Point p(3, 0);

	t.contains(p);
}
}
