#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat();
	Cat(const Cat &other);
	~Cat();
	Cat &operator=(const Cat &other);

	// Required by subject
	void makeSound() const;

	// Added by me
	const Brain *getBrain() const;
};

#endif // CAT_HPP
