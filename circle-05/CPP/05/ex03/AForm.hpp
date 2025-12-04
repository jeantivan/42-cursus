#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

#define BOLD_PURPLE  "\033[1;35m"
#define BOLD_CYAN  "\033[1;36m"
#define BOLD_YELLOW  "\033[1;33m"
#define NO_COLOR  "\033[0m"
#define RST  "\033[0;39m"
#define GRAY  "\033[0;90m"
#define RED  "\033[0;91m"
#define GREEN  "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE  "\033[0;94m"
#define MAGENTA  "\033[0;95m"
#define CYAN  "\033[0;96m"
#define WHITE  "\033[0;97m"
#define BG_GREEN  "\033[42;37m"

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
	virtual void formAction() const = 0;

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

	class NotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
