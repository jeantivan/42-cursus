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

	void makeSound() const;
	std::string getType() const;
	void makePooPoo() const;
};

#endif // CAT_HPP
