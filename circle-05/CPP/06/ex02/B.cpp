#include "B.hpp"

void B::whoAmI() const {
	std::cout << "type B\n";
}

B::~B() { std::cout << "B destructor\n"; }
