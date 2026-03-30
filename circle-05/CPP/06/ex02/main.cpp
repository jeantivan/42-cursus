#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define N 6

Base *generate(void)
{
	int prob = 1 + (rand() % 3);

	if (prob == 1)
		return (new A());
	if (prob == 2)
		return (new B());
	return (new C());
}

void identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "type NULL\n";
		return;
	}

	Base *res;
	if ((res = dynamic_cast<A *>(p)) != NULL)
		res->whoAmI();
	else if ((res = dynamic_cast<B *>(p))!= NULL)
		res->whoAmI();
	else if (((res = dynamic_cast<C *>(p))) != NULL)
		res->whoAmI();
	else
		res->whoAmI();
}

void identify(Base &p)
{
	try
	{
		A &res = dynamic_cast<A &>(p);
		res.whoAmI();
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		B &res = dynamic_cast<B &>(p);
		res.whoAmI();
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		C &res = dynamic_cast<C &>(p);
		res.whoAmI();
		return;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	srand(time(NULL));

	Base *classes[N];

	for (int i = 0; i < N; i++)
		classes[i] = generate();

	std::cout << "---- Test: Identify with pointer    \n\n";
	for (int i = 0; i < N; i++)
		identify(classes[i]);

	std::cout << "\n---- Test: Identify with reference  \n\n";
	for (int i = 0; i < N; i++)
		identify(*classes[i]);

	std::cout << "\n---- Free memory  \n\n";
	for (int i = 0; i < N; i++)
		delete classes[i];

	return 0;
}
