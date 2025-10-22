#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << std::setw(42) << std::setfill('-') << " Dog constructor \n" << std::endl;
	Animal* dog = new Dog();
	Animal* dog2 = new Dog(*(Dog *)dog);
	std::cout << std::endl;

	std::cout << std::setw(42) << std::setfill('-') << " Dog destructor \n" << std::endl;
	delete dog;
	delete dog2;
	std::cout << std::endl;

	std::cout << std::setw(42) << std::setfill('-') << " Cat constructor \n" << std::endl;
	Animal* cat = new Cat();
	Animal* cat2 = new Cat(*(Cat *)cat);
	std::cout << std::endl;


	std::cout << std::setw(42) << std::setfill('-') << " Cat destructor \n" << std::endl;
	delete cat;
	delete cat2;
	std::cout << std::endl;

	Cat gatito;
	std::cout << "Gatito type: " << gatito.getType() << std::endl;
	gatito.makePooPoo();

	Dog scooby;
	std::cout << "Scooby type: " << scooby.getType() << std::endl;
	scooby.makePooPoo();

	// Fail to compile because Animal is an abstract class
	//Animal animal;
	return 0;
}
