#include "Data.hpp"

Data::Data() : name("Default") {}

Data::Data(const std::string& n) : name(n) {}

Data::~Data() {}

Data::Data(const Data& other) : name(other.name) {}

Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return *this;
}

const std::string& Data::getName() const {
	return name;
}

void Data::setName(const std::string& newName) {
	name = newName;
}
