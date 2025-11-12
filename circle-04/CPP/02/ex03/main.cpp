#include <iostream>
#include "Point.hpp"

int main(void) {
{
	std::cout << "\nTest 1\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point p(5, 3);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}

{
	std::cout << "\nTest 2\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p(12, 5);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;

}

{
	std::cout << "\nTest 3\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point p(0, 0);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}

{

	std::cout << "\nTest 4\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point p(5, 0);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}

{

	std::cout << "\nTest 5\n" << std::endl;

	Point a(0.5f, 1.0f);
	Point b(4.5f, 1.0f);
	Point c(2.5f, 5.0f);
	Point p(2.5f, 2.5f);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}

{

	std::cout << "\nTest 6\n" << std::endl;

	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 0); // No es un triangulo real
	Point p(3, 0);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}

{

	std::cout << "\nTest 6\n" << std::endl;

	Point a(4, -2);
	Point b(3, 3);
	Point c(1, -42); // No es un triangulo real
	Point p(3.25f, -2.0f);

	std::cout << "isInside " << bsp(a, b, c, p) << std::endl;
}
}
