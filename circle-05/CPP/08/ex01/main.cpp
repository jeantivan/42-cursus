#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"
#include <deque>

int main() {
	srand(time(NULL));

	unsigned int maxSize = 6;
	Span span(maxSize);

	try {
		for(unsigned int i = 0; i < maxSize; i++) {
			unsigned int rad = (1 + rand() % (20)) ;
			std::cout << rad << " ";
			span.addNumber(rad);
		}
		std::cout << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;

		std::cout << "longtest span: " << span.longestSpan() << std::endl;
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
