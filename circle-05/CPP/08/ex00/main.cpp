#include <iostream>
#include <vector>
#include "easyfind.hpp"


int main() {
	int data[] = {2, 3, 5, 42, 12, 5, 4};
	int n = sizeof(data) / sizeof(data[0]);
	std::vector<int> numbers(data, data + n);
	std::vector<int>::iterator findIt;

	const std::vector<int> numbers2(data, data + n);
	std::vector<int>::const_iterator findIt2;

	try {

		findIt = easyfind<std::vector<int> >(numbers, 42);

		std::cout << *findIt << std::endl;
		findIt2 = easyfind<std::vector<int> >(numbers2, 2);

		std::cout << *(findIt2) << std::endl;

	} catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

}
