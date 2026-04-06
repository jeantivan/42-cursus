#include "iter.hpp"


#define RESET   "\033[0m"
#define CYAN	"\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED	 "\033[31m"

// -----------------------------------------------------------------------------
// Helper Functions
// -----------------------------------------------------------------------------

void replaceA(std::string &str)
{
	size_t pos;
	if ((pos = str.find("a")) != std::string::npos)
		str.replace(pos, 1, "42");
}

void showAwesome(const Awesome &item) {
	std::cout << "ID: " << item.id << " | Name: " << item.name << std::endl;
}

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void printHeader(const std::string& title) {
	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << CYAN << "   " << title << RESET << std::endl;
	std::cout << CYAN << "========================================" << RESET << std::endl;
}

void testIntArray() {
	printHeader("Test 1: 'iter' with 'int arr[10]'");

	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << YELLOW << "Original numbers:" << RESET << std::endl;
	iter(arr, 10, show<int>);
	std::cout << std::endl;

	std::cout << YELLOW << "\nMultiplying each number by itself (power2):" << RESET << std::endl;
	iter(arr, 10, power2<int>);
	iter(arr, 10, show<int>);
	std::cout << std::endl;

	std::cout << GREEN << "-> SUCCESS: Int array evaluated and modified." << RESET << std::endl;
}

void testConstIntArray() {
	printHeader("Test 2: 'iter' with 'const int arr[10]'");

	const int arr_const[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	std::cout << YELLOW << "Showing const numbers:" << RESET << std::endl;
	iter(arr_const, 10, show<int>);
	std::cout << std::endl;

	std::cout << RED << "(Note: power2<int> intentionally disabled to ensure const correctness)" << RESET << std::endl;
	// iter(arr_const, 10, power2<int>); // This should not compile

	std::cout << GREEN << "-> SUCCESS: Const int array evaluated safely." << RESET << std::endl;
}


void testStringArray() {
	printHeader("Test 3: 'iter' with 'std::string [7]'");

	std::string strings[7] = {"a", "b", "c", "Hola Mundo", "a", "c", "42"};

	std::cout << YELLOW << "Original strings:" << RESET << std::endl;
	iter(strings, 7, show<std::string>);
	std::cout << std::endl;

	std::cout << YELLOW << "\nReplacing the char 'a' with '42':" << RESET << std::endl;
	iter(strings, 7, replaceA);
	iter(strings, 7, show<std::string>);
	std::cout << std::endl;

	std::cout << GREEN << "-> SUCCESS: String array evaluated and modified." << RESET << std::endl;
}

void testConstStringArray() {
	printHeader("Test 4: 'iter' with 'const std::string [3]'");

	const std::string strs[3] = {"42 Madrid", "CPP 07", "Templates"};

	std::cout << YELLOW << "Showing const strings:" << RESET << std::endl;
	iter(strs, 3, show<std::string>);
	std::cout << std::endl;

	std::cout << RED << "(Note: replaceA intentionally disabled to ensure const correctness)" << RESET << std::endl;
	// iter(strs, 3, replaceA); // This should not compile

	std::cout << GREEN << "-> SUCCESS: Const string array evaluated safely." << RESET << std::endl;
}

void testSizeTLength() {
	printHeader("Test 5: 'iter' with 'size_t' as length parameter");

	int small_arr[2] = {42, 21};
	const size_t length_as_size_t = 2;

	std::cout << YELLOW << "Showing elements using size_t for length:" << RESET << std::endl;
	iter(small_arr, length_as_size_t, show<int>);
	std::cout << std::endl;

	std::cout << GREEN << "-> SUCCESS: Iter handles generic length types." << RESET << std::endl;
}


void testCustomStruct() {
	printHeader("Test 6: 'iter' with Custom Struct (Awesome)");

	Awesome awesome_arr[3] = {
		{1, "Alice"},
		{2, "Bob"},
		{3, "Charlie"}
	};

	std::cout << YELLOW << "Iterating through an array of Awesome objects:" << RESET << std::endl;
	iter(awesome_arr, 3, showAwesome);
	std::cout << GREEN << "-> SUCCESS: Iter supports custom data types." << RESET << std::endl;
}

void testNullPointer() {
	printHeader("Test 7: 'iter' with NULL pointer");

	int *null_arr = NULL;

	std::cout << YELLOW << "Attempting to iterate over a NULL array..." << RESET << std::endl;
	iter(null_arr, 5, show<int>);

	std::cout << GREEN << "-> SUCCESS: Did not crash! NULL safety confirmed." << RESET << std::endl;
}

int main()
{
	std::cout << "\nStarting extensive 'iter' template tests...\n" << std::endl;

	testIntArray();
	testConstIntArray();
	testStringArray();
	testConstStringArray();
	testSizeTLength();
	testCustomStruct();
	testNullPointer();

	std::cout << CYAN << "\n========================================" << RESET << std::endl;
	std::cout << GREEN << "   All tests completed successfully!    " << RESET << std::endl;
	std::cout << CYAN << "========================================\n" << RESET << std::endl;
	return 0;
}
