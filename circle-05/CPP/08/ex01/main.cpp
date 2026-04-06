#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	// Inicializar la semilla para los números aleatorios
	srand(time(NULL));

	std::cout << "--- TEST 1: Subject example ---" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << " (Expected: 14)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Exception Handling ---" << std::endl;
	try
	{
		Span emptySpan(5);
		std::cout << "Searching on empty Span..." << std::endl;
		emptySpan.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		Span smallSpan(1);
		smallSpan.addNumber(42);
		std::cout << "Searching on Span with 1 element..." << std::endl;
		smallSpan.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		Span fullSpan(2);
		fullSpan.addNumber(1);
		fullSpan.addNumber(2);
		std::cout << "Searching on Span with 2 elements..." << std::endl;
		fullSpan.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: +10,000 Numbers & Iterator ---" << std::endl;
	try
	{
		unsigned int hugeSize = 15000;
		Span hugeSpan(hugeSize);
		std::vector<int> randomNumbers;

		for (unsigned int i = 0; i < hugeSize; i++)
		{
			randomNumbers.push_back(rand() % 1000000);
		}

		std::cout << "Adding " << hugeSize << " elements at once using assign()..." << std::endl;
		hugeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());

		std::cout << "Shortest Span on 15,000 elements: " << hugeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span on 15,000 elements: " << hugeSpan.longestSpan() << std::endl;
		std::cout << "¡Stress test passed successfully!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
