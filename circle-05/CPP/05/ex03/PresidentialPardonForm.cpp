#include "PresidentialPardonForm.hpp"

// Canonical orthodox form
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon Default", 25, 5), target("")
{
	std::cout << GRAY << "PresidentialPardon 'Default' created" << RST "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t) : AForm("PresidentialPardon " + t, 25, 5), target(t)
{
	std::cout << GRAY << "PresidentialPardon '" << target << "' created" << RST "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	std::cout << GRAY << "PresidentialPardon copied" << RST "\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GRAY << "PresidentialPardon " << getName() << " destroyed" << RST "\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::formAction() const
{
	std::cout << BLUE << target << " has been pardoned by Zaphod Beeblebrox." << RST "\n";
}
