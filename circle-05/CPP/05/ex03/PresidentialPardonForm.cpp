#include "PresidentialPardonForm.hpp"

// Canonical orthodox form
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon Default", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t) : AForm("PresidentialPardon " + t, 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

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
