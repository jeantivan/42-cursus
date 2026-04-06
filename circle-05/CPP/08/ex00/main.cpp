#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"


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

void easyfindWithSimpleIteraror() {
	printHeader("TEST: find a value and modify it");

	int data[] = {2, 3, 5, 42, 12, 42, 4};
	int n = sizeof(data) / sizeof(data[0]);

	std::vector<int> numbers(data, data + n);
	std::vector<int>::iterator it;

	std::cout << "Vector original:";
	for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		std::cout << " " << *iter << " ";
	}
	std::cout << std::endl;

	try {
		it = easyfind(numbers, 42);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
		return ;
	}

	std::cout << YELLOW << "Value " << *it << " was found!" << RESET << std::endl;
	*it = 32;
	std::cout << GREEN << "Now the value is " << *it << RESET << std::endl;

	std::cout << "Vector changed:";
	for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		std::cout << " " << *iter << " ";
	}
	std::cout << std::endl;
}

void easyfindWithConstIterator() {
	printHeader("TEST: easyfind returns const_iterator");

	std::list<int> numbers;
	std::list<int>::const_iterator it;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);
	numbers.push_back(50);
	numbers.push_back(50);
	numbers.push_back(60);

	std::cout << "List original:";
	for (std::list<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		std::cout << " " << *iter << " ";
	}
	std::cout << std::endl;

	try {
		it = easyfind(numbers, 50);
	} catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return ;
	}

	std::cout << YELLOW << "Value " << *it << " was found!" << RESET << std::endl;
	std::cout << RED << "(Note: We cannot change the value of the iterator because is const)" << RESET << std::endl;
	// *it = 32;
}

void easyfindValueNotFound() {
	printHeader("TEST: easyfind fails to found value");

	std::deque<int> numbers;

	numbers.push_front(-42);
	numbers.push_front(-21);
	numbers.push_front(0);
	numbers.push_front(21);
	numbers.push_front(42);

	std::cout << "Deque original:";
	for (std::deque<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		std::cout << " " << *iter << " ";
	}
	std::cout << std::endl;
	try {
		std::deque<int>::iterator found = easyfind(numbers, 99);
		std::cout << *found << std::endl;
	} catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW "ERROR: This point could not be reached!" << std::endl;
}

int main() {
	std::cout << "\nStarting extensive 'easyfind' template tests...\n" << std::endl;

	easyfindWithSimpleIteraror();
	easyfindWithConstIterator();
	easyfindValueNotFound();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!    " << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;

	return 0;
}
