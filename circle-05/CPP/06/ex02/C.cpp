#include "C.hpp"

void C::whoAmI() const {
	std::cout << "type C\n";
}

C::~C() { std::cout << "C destructor\n"; }
