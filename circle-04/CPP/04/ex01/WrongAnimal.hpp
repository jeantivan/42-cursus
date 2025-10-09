#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal(const std::string type);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
	virtual void makeSound() const;
};

#endif // WRONGANIMAL_HPP
