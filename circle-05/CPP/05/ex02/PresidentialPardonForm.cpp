#include "PresidentialPardonForm.hpp"

// Canonical orthodox form
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon Default", 72, 45), target("") {
	std::cout << "PresidentialPardon 'Default' created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& t) : AForm("PresidentialPardon " + t, 72, 45), target(t) {
	std::cout << "PresidentialPardon '" + target + "' created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {
	std::cout << "PresidentialPardon copied\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardon " << getName() << " destroyed\n";
}

void PresidentialPardonForm::formAction() const {

}
