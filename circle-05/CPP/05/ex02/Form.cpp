#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : name_("Default"), signGrade_(150), execGrade_(150), isSigned_(false) {
	std::cout << "Default form created\n";
}

// Destructor
Form::~Form() {
	std::cout << "Form " << name_ << " destroyed\n";
}

// Custom constructor
Form::Form(const std::string name, int signGrade, int execGrade) : name_(name), signGrade_(signGrade), execGrade_(execGrade), isSigned_(false) {
	if (signGrade_ < 1 || execGrade_ < 1)
		throw GradeTooHighException();
	if (signGrade_ > 150 || execGrade_ > 150)
		throw GradeTooLowException();
	std::cout << "Parametrized form created\n";
}

// Copy constructor
Form::Form(const Form& other) : name_(other.name_), signGrade_(other.signGrade_), execGrade_(other.execGrade_),  isSigned_(other.isSigned_) {
	std::cout << "Form copied\n" << *this;
}

// Getters
const std::string Form::getName() const {
	return name_;
}

int Form::getSignGrade() const {
	return signGrade_;
}

int Form::getExecGrade() const {
	return execGrade_;
}

bool Form::getIsSigned() const {
	return isSigned_;
}

// Sign the Form
void Form::beSigned(const Bureaucrat& buro) {
	if (isSigned_)
		throw AlreadySignedException();
	if (buro.getGrade() > signGrade_)
		throw GradeTooHighException();
	isSigned_ = true;
}

// Overload '<<' operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::string isSignedWord = f.getIsSigned() ? "true" : "false";

	std::cout << "Form " << f.getName() << " details:\n";
	std::cout << "\t- sign grade: " << f.getSignGrade()  << "\n";
	std::cout << "\t- exec grade: " << f.getExecGrade()  << "\n";
	std::cout << "\t- is signed: " << isSignedWord  << "\n";

	return os;
}

// Exceptions
const char *Form::GradeTooLowException::what() const throw() {
	return "Form grade too low.";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form grade too high.";
}

const char *Form::AlreadySignedException::what() const throw() {
	return "Form already signed.";
}

const char *Form::AlreadyExecutedException::what() const throw() {
	return "Form already executed.";
}
