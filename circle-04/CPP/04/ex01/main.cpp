#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

Dog basic;

std::cout << "\n---------\n";

{
	Dog tmp = basic;
}

std::cout << "\n---------\n";
	return 0;
}
