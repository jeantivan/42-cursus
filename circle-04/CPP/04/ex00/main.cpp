#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << "\n------ Basic test ------\n" << std::endl;
	std::cout << "animal var type: " << animal.getType() << std::endl;
	animal.makeSound();

	std::cout << "dog var type: " << dog.getType() << std::endl;
	dog.makeSound();

	std::cout << "cat var type: " << cat.getType() << std::endl;
	cat.makeSound();


	std::cout << "\n------ Pointers objects ------\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n--- Animal pointers type ---\n" << std::endl;

	std::cout << "Animal * meta type " << meta->getType() << std::endl;
	std::cout << "Animal * j type " << j->getType() << std::endl;
	std::cout << "Animal * i type " << i->getType() << std::endl;

	std::cout << "\n--- Making sound ---\n" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n------ Deleting pointers objects ------\n" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n------ WrongAnimal & WrongCat ------\n" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << "\n------ Destructors pointers ------\n" << std::endl;
	delete wrongAnimal;
	delete wrongCat;

	std::cout << "\n------ Other destructors ------\n" << std::endl;

	return 0;
}
