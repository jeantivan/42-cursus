#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	if (formName == "" || formTarget == "")
	{
		std::cout << RED << "Error: empty strings are not valid." << RST "\n";
		return NULL;
	}

	AForm *(Intern::*functions[])(const std::string &target) = {
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm,
	};

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i] == formName)
		{
			std::cout << "Intern creates " << formName << "\n";
			return (this->*functions[i])(formTarget);
		}
	}
	throw InvalidFormNameException();
}

const char *Intern::InvalidFormNameException::what() const throw()
{
	return "invalid form name.";
}
