#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	std::cout << "--- TEST 1: Object Stack memory ---" << "\n";
	Data originalData("Super datar");
	Data *ptrOriginal = &originalData;

	std::cout << "Original pointer:     " << ptrOriginal << "\n";

	uintptr_t raw = Serializer::serialize(ptrOriginal);
	std::cout << "Serialized value:    " << raw << "\n";

	Data *ptrDeserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << ptrDeserialized << "\n";

	if (ptrOriginal == ptrDeserialized)
		std::cout << "[SUCCESS] Memory addresses match.\n";
	else
		std::cout << "[ERROR] The memory addresses are different.\n";

	std::cout << "Original name: " << ptrOriginal->getName() << "\n";
	std::cout << "Name through deserialized pointer: " << ptrDeserialized->getName() << "\n";

	ptrDeserialized->setName("Modified data from clone");
	std::cout << "Original name after modifying the clone: " << ptrOriginal->getName() << "\n\n";

	std::cout << "--- TEST 2: Objects in the Heap (new) ---" << "\n";
	Data *ptrHeap = new Data("Dynamic data");

	uintptr_t rawHeap = Serializer::serialize(ptrHeap);
	Data *ptrHeapDeserialized = Serializer::deserialize(rawHeap);

	std::cout << "Original heap pointer: " << ptrHeap << "\n";
	std::cout << "Deserialized heap pointer: " << ptrHeapDeserialized << "\n";
	std::cout << "Contained value: " << ptrHeapDeserialized->getName() << "\n";

	delete ptrHeap;
	std::cout << "[SUCCESS] Memory of the Heap handled correctly.\n\n";

	std::cout << "--- TEST 3: NULL POINTER ---" << "\n";
	Data *ptrNull = NULL;

	uintptr_t rawNull = Serializer::serialize(ptrNull);
	Data *ptrNullDeserialized = Serializer::deserialize(rawNull);

	std::cout << "Original NULL pointer: " << ptrNull << "\n";
	std::cout << "Deserialized NULL pointer: " << ptrNullDeserialized << "\n";

	if (ptrNullDeserialized == NULL)
		std::cout << "[SUCCESS] The NULL pointer remained NULL after deserialization.\n";

	return 0;
}
