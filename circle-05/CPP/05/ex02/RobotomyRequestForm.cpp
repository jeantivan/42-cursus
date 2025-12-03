#include "RobotomyRequestForm.hpp"

// Canonical orthodox form
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Default", 72, 45), target("") {
	std::cout << "RobotomyRequest 'Default' created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("RobotomyRequest " + t, 72, 45), target(t) {
	std::cout << "RobotomyRequest '" + target + "' created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
	std::cout << "RobotomyRequest copied\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequest " << getName() << " destroyed\n";
}

void RobotomyRequestForm::formAction() const {
	int chances = 1 + (rand() % 100);

	if (chances % 2 == 0)
		std::cout << "Rrrrrrr-KRRRR-Vvvvvvt!\n " + target + " was successfully robotomized!\n";
	else
		std::cout << "Robotomy failed\n";
}
