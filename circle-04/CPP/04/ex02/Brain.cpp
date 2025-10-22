#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Class Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for(size_t i = 0; i < MAX_SIZE; i++)
	{
		ideas[i] = std::string(other.ideas[i]);
	}
	std::cout << "Class Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Class Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other)
	{
		for(size_t i = 0; i < MAX_SIZE; i++)
		{
			ideas[i] = std::string(other.ideas[i]);
		}
	}
	std::cout << "Class Brain '=' operator called" << std::endl;
	return (*this);
}

std::string Brain::getIdea(size_t index) const {
	if (index > 99)
	{
		std::cerr << "Error: index out of bounds" << std::endl;
		return "";
	}
	return ideas[index];
}

void Brain::setIdea(size_t index, std::string new_idea) {
	if (index > 99)
	{
		std::cerr << "Error: index out of bounds" << std::endl;
		return ;
	}
	ideas[index] = new_idea;
}
