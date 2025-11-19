#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	// std::cout << std::setw(42) << std::setfill('-') << " Dog constructor \n" << std::endl;
	// Animal* dog = new Dog();
	// Animal* dog2 = new Dog(*(Dog *)dog);
	// std::cout << std::endl;

	// std::cout << std::setw(42) << std::setfill('-') << " Dog destructor \n" << std::endl;
	// delete dog;
	// delete dog2;
	// std::cout << std::endl;

	// std::cout << std::setw(42) << std::setfill('-') << " Cat constructor \n" << std::endl;
	// Animal* cat = new Cat();
	// Animal* cat2 = new Cat(*(Cat *)cat);
	// std::cout << std::endl;


	// std::cout << std::setw(42) << std::setfill('-') << " Cat destructor \n" << std::endl;
	// delete cat;
	// delete cat2;
	// std::cout << std::endl;

	// std::cout << std::setw(42) << std::setfill('-') << " Subject exercise \n" << std::endl;
	// Animal *animals[100];
	// std::cout << std::endl;

	// std::cout << std::setw(21) << std::setfill('-') << " Creating Dog half... \n" << std::endl;
	// for (int i = 0; i < 50; i++)
	// {
	// 	std::cout << "\n-- Dog #" << i + 1 << std::endl;
	// 	animals[i] = new Dog();
	// }
	// std::cout << std::setw(21) << std::setfill('-') << " Creating Cat half... \n" << std::endl;
	// for (int i = 50; i < 100; i++)
	// {
	// 	std::cout << "\n-- Cat #" << i + 1 << std::endl;
	// 	animals[i] = new Cat();
	// }

	// std::cout << std::setw(42) << std::setfill('-') << " Deleting all animals \n" << std::endl;
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << "\n-- Animal #" << i + 1 << std::endl;

	// 	delete animals[i];
	// }

Dog basic;

std::cout << "\n---------\n";

{
	Dog tmp = basic;
}

std::cout << "\n---------\n";
	return 0;
}
