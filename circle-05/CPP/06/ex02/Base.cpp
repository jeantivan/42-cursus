#include "Base.hpp"

void Base::whoAmI() const {
	std::cout << "type Base\n";
}

Base::~Base() { std::cout << "Base destructor\n"; }
