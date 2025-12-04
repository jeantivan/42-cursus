#include "RobotomyRequestForm.hpp"

// Canonical orthodox form
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Default", 72, 45), target("") {
	std::cout << GRAY << "RobotomyRequest 'Default' created" << RST"\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("RobotomyRequest " + t, 72, 45), target(t) {
	std::cout << GRAY << "RobotomyRequest '" + target + "' created" << RST"\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
	std::cout << GRAY << "RobotomyRequest copied" << RST"\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << GRAY << "RobotomyRequest " << getName() << " destroyed" << RST"\n";
}

void RobotomyRequestForm::formAction() const {
	int chances = 1 + (rand() % 100);

	if (chances % 2 == 0)
		std::cout << CYAN << "Rrrrrrr-KRRRR-Vvvvvvt!\n " + target + " was successfully robotomized!" << RST"\n";
	else
		std::cout << YELLOW << "Robotomy failed" << RST"\n";
}
