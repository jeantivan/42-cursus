#include <iostream>
#include <string>
#include "Array.hpp"

void basic_array()
{
	Array<std::string> arr(10);

	std::cout << "Array size: " << arr.size() << std::endl;

	std::cout << "\nArray elements " << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}

	std::cout << "\nArray new elements " << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		arr[i] = "42";
		std::cout << arr[i] << std::endl;
	}

	std::cout << "\nTry access index out of bounds" << std::endl;
	try {
		std::cout << arr[11] << std::endl;
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void copy_and_assign_array() {
	Array<float> arr_float(6);
	Array<float> arr_float3(12);

	for (unsigned int i = 0; i < arr_float.size(); i++) {
		arr_float[i] = 42.0f + i;
	}

	Array<float> arr_float2 = arr_float;
	for (unsigned int i = 0; i < arr_float2.size(); i++) {
		arr_float2[i] = 21.0f - i;
	}

	arr_float3 = arr_float;

	std::cout << "Array sizes" << std::endl;
	std::cout << "arr_float size " << arr_float.size() << std::endl;
	std::cout << "arr_float2 size " << arr_float.size() << std::endl;
	std::cout << "arr_float3 size " << arr_float.size() << std::endl;

	std::cout << std::endl;

	std::cout << "arr_float1 " << std::endl;
	for (unsigned int i = 0; i < arr_float.size(); i++) {
		std::cout << arr_float[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "arr_float2 " << std::endl;
	for (unsigned int i = 0; i < arr_float2.size(); i++) {
		std::cout << arr_float2[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "arr_float3 " << std::endl;
	for (unsigned int i = 0; i < arr_float3.size(); i++) {
		std::cout << arr_float3[i] << std::endl;
	}
}

void const_array() {
	Array<int> arr(4);

	std::cout << "Original array" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		std::cout << arr[i] << std::endl;
	}

	std::cout << "\n Const array" << std::endl;

	const Array<int> arr_copy = arr;
	for (unsigned int i = 0; i < arr_copy.size(); i++) {
		std::cout << arr_copy[i] << std::endl;
	}

	// Compiler error
	// arr_copy[2] = 3;
}

int main() {
	std::cout << "Test basic array\n" << std::endl;
	basic_array();
	std::cout << "\nTest copy and assign operations\n" << std::endl;
	copy_and_assign_array();
	std::cout << "\nTest const array\n" << std::endl;
	const_array();
}
