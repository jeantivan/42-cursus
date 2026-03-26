#include "RobotomyRequestForm.hpp"

// Canonical orthodox form
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Default", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t) : AForm("RobotomyRequest " + t, 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::formAction() const
{
	int chances = 1 + (rand() % 100);

	if (chances % 2 == 0)
		std::cout << CYAN << "Rrrrrrr-KRRRR-Vvvvvvt!\n" << target << " was successfully robotomized!" << RST "\n";
	else
		std::cout << YELLOW << "Robotomy failed" << RST "\n";
}
