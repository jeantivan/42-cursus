#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	static const size_t MAX_SIZE = 100;
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain &operator=(const Brain &other);

	void setIdea(size_t index, std::string new_idea);
	std::string getIdea(size_t index) const;
private:
	std::string ideas[MAX_SIZE];
};

#endif // BRAIN_HPP
