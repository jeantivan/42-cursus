#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(const WrongCat &other);
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif // WRONGCAT_HPP
