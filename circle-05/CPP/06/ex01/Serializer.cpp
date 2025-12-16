#include "Serializer.hpp"

// This methods don't work because the class can't be instantiated
Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }

Serializer& Serializer::operator=(const Serializer &other)  { (void)other; return *this; }

// Static methods
uintptr_t Serializer::serialize(Data *data) {
	return reinterpret_cast<uintptr_t>(data);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
