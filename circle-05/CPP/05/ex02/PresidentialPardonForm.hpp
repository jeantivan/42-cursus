#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>


class PresidentialPardonForm : public AForm
{
private:
	std::string target;
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& t);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	void formAction() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP
