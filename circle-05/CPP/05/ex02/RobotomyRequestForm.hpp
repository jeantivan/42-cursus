#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &t);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void formAction() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
