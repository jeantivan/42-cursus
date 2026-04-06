#include <iostream>
#include "whatever.hpp"

#define RESET	"\033[0m"
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RED		"\033[31m"

void printHeader(const std::string& title) {
	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << CYAN << "   " << title << RESET << std::endl;
	std::cout << CYAN << "========================================" << RESET << std::endl;
}

void testSwapWithIntType() {
	printHeader("TEST: 'swap' with type 'int'");

	int a = 2;
	int b = 3;

	std::cout << YELLOW << "Values before swap" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap(a, b);
	std::cout << GREEN << "\nValues after swap " << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
}

void testMinMaxWithIntType() {
	printHeader("TEST: 'min' and 'max' with type 'int'");

	int c = 42;
	int d = 21;

	std::cout << YELLOW <<  "Values c = " << c << " d = " << d << RESET << std::endl;
	std::cout << "min( c, d ) = " << GREEN << ::min(c, d) << RESET << std::endl;
	std::cout << "max( c, d ) = " << GREEN << ::max(c, d) << RESET << std::endl;
}

void testSwapWithStdString() {
	printHeader("TEST: 'swap' with type 'std::string'");

	std::string str1 = "Madrid";
	std::string str2 = "Barcelona";
	std::cout << YELLOW"Values before swap" << RESET << std::endl;

	std::cout << "str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
	::swap(str1, str2);

	std::cout << GREEN << "\nValues after swap" << RESET << std::endl;
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
}

void testMinMaxWithStdString() {
	printHeader("TEST: 'min' and 'max' with type 'string'");

	std::string str1 = "Venezuela";
	std::string str2 = "Colombia";

	std::cout << YELLOW << "Values str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
	std::cout << "min( str1, str2 ) = " << GREEN << ::min(str1, str2) << RESET << std::endl;
	std::cout << "max( str1, str2 ) = " << GREEN << ::max(str1, str2) << RESET << std::endl;
}

int main()
{
	std::cout << "\nStarting extensive 'swap', 'min' & 'max' template tests...\n" << std::endl;

	testSwapWithIntType();
	testMinMaxWithIntType();
	testSwapWithStdString();
	testMinMaxWithStdString();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!    " << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;
	return 0;
}
