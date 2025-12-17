#include <iostream>
#include <string>

#include "template.hpp"

void increment(int& n) {
	n++;
}

void replaceA(std::string& str) {
	if (str == "a")
		str.replace(0, 1, "42");
}

int main() {

	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter<int*, int>(arr, 10, show<int>);
	iter<int*, int>(arr, 10, power2<int>);
	std::cout << std::endl;
	iter<int*, int>(arr, 10, show<int>);
	iter<int*, int>(arr, 10, increment);
	std::cout << std::endl;
	iter<int*, int>(arr, 10, show<int>);

	std::cout << std::endl;
	std::string strings[7] = {"a", "b", "c", "a", "a", "c", "42"};

	iter<std::string*, int>(strings, 7, show<std::string>);
	iter<std::string*, int>(strings, 7, replaceA);
	std::cout << std::endl;
	iter<std::string*, int>(strings, 7, show<std::string>);


	return 0;
}
