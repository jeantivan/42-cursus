#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	std::cout << "TEST: 'swap' with type 'int'\n" << std::endl;
	std::cout << "Values before swap ";
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap(a, b);
	std::cout << "Values after swap ";
	std::cout << "a = " << a << ", b = " << b << std::endl;

	int c = 42;
	int d = 21;

	std::cout << "\nTEST: min and max with type 'int'\n" << std::endl;

	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << "\nTEST: 'swap' with type 'std::string'\n" << std::endl;

	std::string str1 = "Madrid";
	std::string str2 = "Barcelona";
	std::cout << "Values before swap ";

	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	::swap(str1, str2);

	std::cout << "Values after swap ";
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;


	std::cout << "\nTEST: min and max with type 'string'\n" << std::endl;
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min( str1, str2 ) = " << ::min(str1, str2) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max(str1, str2) << std::endl;
}
