#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
{
	std::cout << "\n===== Canonical orthodox form =====\n";

	std::cout << "\n--- Creating a Dog ---\n\n";
	Dog dog1;
	std::cout << "\n--- Creating a Cat ---\n\n";
	Cat cat1;

	std::cout << "\n--- Copy the Dog ---\n\n";
	Dog dog2(dog1);
	std::cout << "\n--- Copy the Cat ---\n\n";
	Cat cat2(cat1);

	std::cout << "\n--- Assign the Dog ---\n\n";
	Dog dog3;
	dog3 = dog1;
	std::cout << "\n--- Assign the Cat ---\n\n";
	Cat cat3;
	cat3 = cat1;

	std::cout << "\n--- Check deep copy of Dog ---\n\n";

	std::cout << "dog1 brain address " << dog1.getBrain() << " \n";
	std::cout << "dog2 brain address " << dog2.getBrain() << " \n";
	std::cout << "dog3 brain address " << dog3.getBrain() << " \n";

	std::cout << "\n--- dogN idea '# 42' address ---\n\n";

	std::cout << "dog1.brain->ideas[42] " << &dog1.getBrain()->getIdea(42) << " \n";
	std::cout << "dog2.brain->ideas[42]  " << &dog2.getBrain()->getIdea(42)  << " \n";
	std::cout << "dog3.brain->ideas[42]  " << &dog3.getBrain()->getIdea(42)  << " \n";

	std::cout << "\n--- Check deep copy of Cat ---\n\n";

	std::cout << "cat1 brain address " << cat1.getBrain() << " \n";
	std::cout << "cat2 brain address " << cat2.getBrain() << " \n";
	std::cout << "cat3 brain address " << cat3.getBrain() << " \n";

	std::cout << "\n--- catN idea '# 42' address ---\n\n";

	std::cout << "cat1.brain->ideas[42] " << &cat1.getBrain()->getIdea(42) << " \n";
	std::cout << "cat2.brain->ideas[42]  " << &cat2.getBrain()->getIdea(42)  << " \n";
	std::cout << "cat3.brain->ideas[42]  " << &cat3.getBrain()->getIdea(42)  << " \n";

	std::cout << "\n-- Automatic destruction\n\n";
}

{
	std::cout << "\n===== Subject requirement =====\n\n";

	Animal *animals[40];

	for (int i = 0; i < 40; i++)
	{
		if (i < 20)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < 40; i++)
	{
		std:: cout << i << " ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 40; i++)
	{
		delete animals[i];
	}
}
}
