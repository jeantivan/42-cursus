#include <iostream>
#include <string>

#include "iter.hpp"

void replaceA(std::string &str)
{
	size_t pos;
	if ((pos = str.find("a")) != std::string::npos)
		str.replace(pos, 1, "42");
}



void showAwesome(const Awesome &item) {
	std::cout << "ID: " << item.id << " | Name: " << item.name << std::endl;
}

int main()
{
	std::cout << "\nTEST: 'iter' template function with 'int arr[10]'" << std::endl;

	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "show numbers" << std::endl;
	iter(arr, 10, show<int>);
	std::cout << std::endl;

	std::cout << "multiply each number by itself" << std::endl;
	iter(arr, 10, power2<int>);
	iter(arr, 10, show<int>);
	std::cout << std::endl;

	std::cout << "\nTEST: 'iter' template function with 'const int arr[10]'" << std::endl;
	const int arr_const[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	std::cout << "show numbers" << std::endl;
	iter(arr_const, 10, show<int>);
	std::cout << std::endl;

	// We can user power2 with iter, because the types are incompatibles
	//iter(arr_const, 10, power2<int>);


	// std::cout << std::endl;
	std::cout << "\nTEST: 'iter' template function with 'std::string [7]'" << std::endl;

	std::string strings[7] = {"a", "b", "c", "Hola Mundo", "a", "c", "42"};

	std::cout << "show strings" << std::endl;
	iter(strings, 7, show<std::string>);
	std::cout << std::endl;

	std::cout << "replace the char 'a' for '42'" << std::endl;
	iter(strings, 7, replaceA);
	iter(strings, 7, show<std::string>);
	std::cout << std::endl;

	std::cout << "\nTEST: 'iter' template function with 'const std::string [3]'" << std::endl;

	const std::string strs[3] = {"42 Madrid", "CPP 07", "Templates"};
	std::cout << "show strings" << std::endl;
	iter(strs, 3, show<std::string>);
	std::cout << std::endl;

	// We can user replaceA with iter, because the types are incompatibles
	// iter(strs, 3, replaceA);


	std::cout << "\nTEST: 'iter' template function with 'size_t' as length (S)" << std::endl;
	int small_arr[2] = {42, 21};
	const size_t length_as_size_t = 2;

	iter(small_arr, length_as_size_t, show<int>);
	std::cout << std::endl;

	std::cout << "\nTEST: 'iter' template function with 'Custom Struct'" << std::endl;
    Awesome awesome_arr[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };
    iter(awesome_arr, 3, showAwesome);
    std::cout << std::endl;


	std::cout << "\nTEST: 'iter' with NULL pointer" << std::endl;
	int *null_arr = NULL;
	iter(null_arr, 5, show<int>);
	std::cout << "Did not crash!" << std::endl;

	return 0;
}
