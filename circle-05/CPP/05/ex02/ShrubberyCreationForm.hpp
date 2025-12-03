#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& t);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	void formAction() const;
	void implantTree() const;

	class InvalidFileException : public std::exception {
		public:
			const char* what() const throw();
	};
};

#endif // SHRUBBERYCREATIONFORM_HPP
