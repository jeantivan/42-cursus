#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name_;
	const int signGrade_;
	const int execGrade_;
	bool isSigned_;

	// Cannot be implemented because the class has 'const' attributes
	AForm &operator=(const AForm &other);

public:
	AForm();
	AForm(const AForm &other);
	virtual ~AForm();
	AForm(const std::string name, int signGrade, int execGrade);

	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

	void beSigned(const Bureaucrat& b);
	bool execute(Bureaucrat const& executor) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
		public:
			const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			const char*  what() const throw();
	}
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // FORM_HPP
