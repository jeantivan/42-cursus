#include "Intern.hpp"

Intern::Intern() {
	std::cout << GRAY << "Intern created" << RST"\n";
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << GRAY << "Intern copied" << RST"\n";
}

Intern::~Intern() {
	std::cout << GRAY << "Intern destroyed" << RST"\n";
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::makeShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string formTypes[] = { "shrubbery creation", "robotomy request", "presidential pardon", "ERROR"};

	if (formName == "" || formTarget == "")
	{
		std::cout << RED << "Error: empty strings are not valid." << RST"\n";
		return NULL;
	}

	AForm* (Intern::*functions[])(const std::string& target) = {
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm,
	};

	for(int i = 0; i < 4; i++)
	{
		if (formTypes[i] == formName)
		{
			return (this->*functions[i])(formTarget);
		}
	}
	throw InvalidFormNameException();
}

const char *Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name.";
}
