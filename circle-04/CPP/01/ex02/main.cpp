#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *ptr = &var;
	std::string &ref = var;

	std::cout << "Var address " << &var << std::endl;
	std::cout << "Ptr address " << ptr << std::endl;
	std::cout << "Ref address " << &ref << std::endl;

	std::cout << "Var val " << var << std::endl;
	std::cout << "Ptr val " << *ptr << std::endl;
	std::cout << "Ref val " << ref << std::endl;
	return (0);
}
