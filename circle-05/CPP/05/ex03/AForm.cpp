#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : name_("Default"), signGrade_(150), execGrade_(150), isSigned_(false)
{
	// std::cout << "Default form created\n";
}

// Destructor
AForm::~AForm()
{
	// std::cout << "Form " << name_ << " destroyed\n";
}

// Custom constructor
AForm::AForm(const std::string name, int signGrade, int execGrade) : name_(name), signGrade_(signGrade), execGrade_(execGrade), isSigned_(false)
{
	if (signGrade_ < 1 || execGrade_ < 1)
		throw GradeTooHighException();
	if (signGrade_ > 150 || execGrade_ > 150)
		throw GradeTooLowException();
	// std::cout << "Parametrized form created\n";
}

// Copy constructor
AForm::AForm(const AForm &other) : name_(other.name_), signGrade_(other.signGrade_), execGrade_(other.execGrade_), isSigned_(other.isSigned_)
{
	// std::cout << "Form copied\n" << *this;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned_ = other.getIsSigned();
	}
	return *this;
}

// Getters
const std::string &AForm::getName() const
{
	return name_;
}

int AForm::getSignGrade() const
{
	return signGrade_;
}

int AForm::getExecGrade() const
{
	return execGrade_;
}

bool AForm::getIsSigned() const
{
	return isSigned_;
}

// Sign the Form
void AForm::beSigned(const Bureaucrat &buro)
{
	if (isSigned_)
		throw AlreadySignedException();
	if (buro.getGrade() > signGrade_)
		throw GradeTooLowException();
	isSigned_ = true;
}

// Execute the form
void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned_)
		throw NotSignedException();
	if (executor.getGrade() > execGrade_)
		throw GradeTooHighException();
	formAction();
}

// Overload '<<' operator
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	std::string isSignedWord = f.getIsSigned() ? "true" : "false";

	os << "Form " << f.getName() << " details:\n";
	os << "\t- sign grade: " << f.getSignGrade() << "\n";
	os << "\t- exec grade: " << f.getExecGrade() << "\n";
	os << "\t- is signed: " << isSignedWord << "\n";

	return os;
}

// Exceptions
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high.";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form already signed.";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed.";
}
