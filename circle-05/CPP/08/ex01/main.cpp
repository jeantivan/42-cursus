#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// --- Colors and Formatting Macros ---
#define RESET   "\033[0m"
#define CYAN	"\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED	 "\033[31m"

void printHeader(const std::string& title) {
	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << CYAN << "   " << title << RESET << std::endl;
	std::cout << CYAN << "========================================" << RESET << std::endl;
}

void testSubjectExample() {
	printHeader("TEST: Subject example");

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << YELLOW << sp.shortestSpan() << RESET << " (Expected: 2)" << std::endl;
		std::cout << "Longest Span: " << YELLOW << sp.longestSpan() << RESET << " (Expected: 14)" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

void testExceptionHandling() {
	printHeader("TEST: Exception Handling");

	std::cout << YELLOW << "[1] Searching on empty Span..." << RESET << std::endl;
	try {
		Span emptySpan(5);
		emptySpan.shortestSpan();
	}
	catch (const std::exception &e) {
		std::cout << RED << "Error caught: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\n[2] Searching on Span with only 1 element..." << RESET << std::endl;
	try {
		Span smallSpan(1);
		smallSpan.addNumber(42);
		smallSpan.longestSpan();
	}
	catch (const std::exception &e) {
		std::cout << RED << "Error caught: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\n[3] Adding numbers beyond capacity..." << RESET << std::endl;
	try {
		Span fullSpan(2);
		fullSpan.addNumber(1);
		fullSpan.addNumber(2);
		std::cout << "Trying to add a 3rd element to a Span of size 2..." << std::endl;
		fullSpan.addNumber(3);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Error caught: " << e.what() << RESET << std::endl;
	}
}

void testUniqueStressTest() {
	printHeader("TEST: +15,000 Numbers (Guaranteed Non-Zero Span)");

	try {
		unsigned int hugeSize = 15000;
		Span hugeSpan(hugeSize);
		std::vector<int> uniqueNumbers;

		int currentValue = 0;


		for (unsigned int i = 0; i < hugeSize; i++) {
			// A random jump between 5 and 50
			int jump = (rand() % 46) + 5;
			currentValue += jump;
			uniqueNumbers.push_back(currentValue);
		}

		// We shuffle the vector so that the numbers are not inserted already sorted.
		std::random_shuffle(uniqueNumbers.begin(), uniqueNumbers.end());

		std::cout << "Adding " << hugeSize << " scattered elements using iterators..." << std::endl;

		hugeSpan.addNumbers(uniqueNumbers.begin(), uniqueNumbers.end());

		std::cout << GREEN << "Successfully added " << hugeSize << " elements!" << RESET << std::endl;

		std::cout << "Shortest Span: " << YELLOW << hugeSpan.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: "  << YELLOW << hugeSpan.longestSpan()  << RESET << std::endl;

	}
	catch (const std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

int main() {
	srand(time(NULL));

	std::cout << "\nStarting extensive 'Span' tests...\n" << std::endl;

	testSubjectExample();
	testExceptionHandling();
	testUniqueStressTest();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!	" << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;

	return 0;
}
