#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data a("data a");

	Data *a_ptr = &a;

	uintptr_t a_serialized = Serializer::serialize(a_ptr);

	Data *a_deserialized = Serializer::deserialize(a_serialized);


	std::cout << "a_ptr " << a_ptr << "\n";

	std::cout << "a_serialized " << a_serialized << "\n";

	std::cout << "a_deserialized " << a_deserialized << "\n";

	std::cout << "a_ptr == a_deserialized " << (a_ptr == a_deserialized ? "true" : "false") << "\n";

	return 0;
}
