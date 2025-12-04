#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);

	AForm* makeShrubberyForm(const std::string& target);
	AForm* makeRobotomyForm(const std::string& target);
	AForm* makePresidentialForm(const std::string& target);

	AForm* makeForm(const std::string& formName, const std::string& formTarget);

	class InvalidFormNameException : public std::exception {
		public:
			const char* what() const throw();
	};
};

#endif // INTERN_HPP
