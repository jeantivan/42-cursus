#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();


	const std::string getName() const;
	int getGrade() const;
	void decrementGrade();
	void incrementGrade();

	// Try to sign a Form
	void signForm(AForm& f);

	// Exceptions
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

private:
	Bureaucrat &operator=(const Bureaucrat &other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
