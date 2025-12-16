#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int prob = 1 + (rand() % 3);

	if (prob == 1)
		return (new A());
	if (prob == 2)
		return (new B());
	return (new C());
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "type A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "type B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "type C\n";
	else
		std::cout << "type Base\n";
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "type A\n";
		return ;
	} catch (std::exception& e) {}

	try {
		dynamic_cast<B&>(p);
		std::cout << "type B\n";
		return ;
	} catch (std::exception& e) {}

	try {
		dynamic_cast<C&>(p);
		std::cout << "type C\n";
		return ;
	} catch (std::exception& e) {}

}

int main() {
	srand(time(NULL));

	Base *classes[20];

	for (int i = 0; i < 20; i++)
	{
		classes[i] = generate();
	}

	for(int i = 0; i < 20; i++)
	{
		identify(classes[i]);
	}

	for(int i = 0; i < 20; i++)
	{
		delete classes[i];
	}
	return 0;
}
