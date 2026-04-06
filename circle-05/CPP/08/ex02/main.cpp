#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list>
#include "MutantStack.hpp"

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
	printHeader("TEST 1: Subject Example (MutantStack)");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << YELLOW << mstack.top() << RESET << " (Expected: 17)" << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << YELLOW << mstack.size() << RESET << " (Expected: 1)" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "\nIterating through MutantStack from bottom to top:" << std::endl;
	while (it != ite) {
		std::cout << GREEN << *it << RESET << " ";
		++it;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
}

void testListComparison() {
	printHeader("TEST 2: std::list Comparison (Should match Test 1)");

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << "Back element: " << YELLOW << mlist.back() << RESET << " (Expected: 17)" << std::endl;

	mlist.pop_back();
	std::cout << "Size after pop: " << YELLOW << mlist.size() << RESET << " (Expected: 1)" << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();

	++it;
	--it;

	std::cout << "\nIterating through std::list:" << std::endl;
	while (it != ite) {
		std::cout << GREEN << *it << RESET << " ";
		++it;
	}
	std::cout << std::endl;
}

void testConstIterator() {
	printHeader("TEST 3: 'const MutantStack' and const_iterator");

	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(21);
	mstack.push(84);

	const MutantStack<int> const_mstack(mstack);

	std::cout << "Iterating using const_iterator:" << std::endl;

	MutantStack<int>::const_iterator it = const_mstack.begin();
	MutantStack<int>::const_iterator ite = const_mstack.end();

	while (it != ite) {
		std::cout << GREEN << *it << RESET << " ";
		// *it = 100; // This would cause a compilation error, proving it's read-only!
		++it;
	}
	std::cout << std::endl;

	// const_mstack.push(10); // Compilation error: cannot push to a const stack
}

void testStlAlgorithms() {
	printHeader("TEST 4: Compatibility with STL Algorithms (std::sort)");

	MutantStack<int> ms;

	std::cout << "Original random elements:\n";
	for(int i = 0; i < 10; i++) {
		int r = 1 + rand() % 100;
		std::cout << r << " ";
		ms.push(r);
	}
	std::cout << std::endl;

	std::sort(ms.begin(), ms.end());

	std::cout << "\nElements after std::sort():\n";
	for(MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		std::cout << GREEN << *it << RESET << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Initialize random seed
	srand(time(NULL));

	std::cout << "\nStarting 'MutantStack' tests...\n" << std::endl;

	testSubjectExample();
	testListComparison();
	testConstIterator();
	testStlAlgorithms();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!	" << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;

	return 0;
}
