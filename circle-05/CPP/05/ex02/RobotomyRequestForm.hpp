#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& t);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	void formAction() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
