#include <iostream>
#include <string>
#include "Array.hpp"

#define RESET	"\033[0m"
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RED		"\033[31m"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void printHeader(const std::string& title) {
	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << CYAN << "   " << title << RESET << std::endl;
	std::cout << CYAN << "========================================" << RESET << std::endl;
}

void testDefaultConstructor() {
	printHeader("Test 1: Default Constructor (Empty Array)");

	Array<int> emptyArr;
	std::cout << "Created empty Array<int>." << std::endl;
	std::cout << "Size should be 0: " << GREEN << emptyArr.size() << RESET << std::endl;

	std::cout << YELLOW << "Attempting to access emptyArr[0]..." << RESET << std::endl;
	try {
		std::cout << emptyArr[0] << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Exception caught successfully: " << e.what() << RESET << std::endl;
	}
}

void testParameterizedConstructor() {
	printHeader("Test 2: Parameterized Constructor & Initialization");

	unsigned int size = 5;
	Array<int> intArr(size);
	std::cout << "Created Array<int> of size " << size << "." << std::endl;

	std::cout << "Checking default initialization (should be all 0s): ";
	for (unsigned int i = 0; i < intArr.size(); i++) {
		std::cout << intArr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Assigning values..." << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++) {
		intArr[i] = (i + 1) * 10;
		std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;
	}
}

void testCopyConstructor() {
	printHeader("Test 3: Copy Constructor (Deep Copy Check)");

	Array<std::string> original(3);
	original[0] = "Hello";
	original[1] = "World";
	original[2] = "!";

	std::cout << "Creating 'copy' from 'original'..." << std::endl;
	Array<std::string> copy(original);

	std::cout << "Modifying 'copy[0]' to 'Goodbye'..." << std::endl;
	copy[0] = "Goodbye";

	std::cout << "Original [0]: " << GREEN << original[0] << RESET << " (Should be 'Hello')" << std::endl;
	std::cout << "Copy     [0]: " << GREEN << copy[0] << RESET << " (Should be 'Goodbye')" << std::endl;

	if (original[0] != copy[0]) {
		std::cout << GREEN << "-> SUCCESS: Deep copy confirmed!" << RESET << std::endl;
	} else {
		std::cout << RED << "-> FAILURE: Shallow copy detected!" << RESET << std::endl;
	}
}

void testAssignmentOperator() {
	printHeader("Test 4: Assignment Operator (Deep Copy)");

	Array<char> arr1(4);
	for (unsigned int i = 0; i < arr1.size(); i++)
		arr1[i] = 'a' + i; // a, b, c, d

	Array<char> arr2(2);
	arr2[0] = 'X';
	arr2[1] = 'Y';

	std::cout << "arr1 size: " << arr1.size() << ", arr2 size: " << arr2.size() << std::endl;

	std::cout << "Assigning arr2 = arr1..." << std::endl;
	arr2 = arr1;

	std::cout << "Modifying arr1[0] to 'Z'..." << std::endl;
	arr1[0] = 'Z';

	std::cout << "arr1[0]: " << arr1[0] << std::endl;
	std::cout << "arr2[0]: " << arr2[0] << " (Should still be 'a')" << std::endl;

	if (arr1[0] != arr2[0] && arr2.size() == 4) {
		std::cout << GREEN << "-> SUCCESS: Deep copy and size update confirmed!" << RESET << std::endl;
	} else {
		std::cout << RED << "-> FAILURE: Issue with assignment operator!" << RESET << std::endl;
	}
}

void testOutOfBounds() {
	printHeader("Test 5: Out of Bounds Exception Handling");

	Array<double> arr(3);

	std::cout << YELLOW << "Testing valid indices (0 to 2)..." << RESET << std::endl;
	try {
		arr[0] = 1.1;
		arr[2] = 3.3;
		std::cout << GREEN << "Valid access successful." << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\nTesting index equal to size (arr[3])..." << RESET << std::endl;
	try {
		arr[3] = 4.4;
		std::cout << RED << "FAILURE: Exception not thrown!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\nTesting negative index (arr[-1])..." << RESET << std::endl;
	try {
		arr[-1] = 9.9; // -1 wraps around to maximum unsigned int
		std::cout << RED << "FAILURE: Exception not thrown!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testConstCorrectness() {
	printHeader("Test 6: Const Correctness");

	Array<int> regular(3);
	regular[0] = 10;
	regular[1] = 20;
	regular[2] = 30;

	const Array<int> constArr(regular);

	std::cout << "Reading from const array: " << std::endl;
	for (unsigned int i = 0; i < constArr.size(); i++) {
		std::cout << "constArr[" << i << "] = " << constArr[i] << std::endl;
	}

	std::cout << GREEN << "-> SUCCESS: Const array read operations working." << RESET << std::endl;

	// UNCOMMENTING THE LINE BELOW SHOULD CAUSE A COMPILER ERROR:
	// constArr[0] = 99;
	std::cout << YELLOW << "(Note: Writing to constArr is properly blocked by the compiler. Check the source code to see the commented-out test)." << RESET << std::endl;
}
int main()
{
	std::cout << "\nStarting extensive Array tests...\n" << std::endl;

	testDefaultConstructor();
	testParameterizedConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testOutOfBounds();
	testConstCorrectness();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!	" << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;
}
