#include "A.hpp"

void A::whoAmI() const {
	std::cout << "type A\n";
}

A::~A() { std::cout << "A destructor\n"; }
