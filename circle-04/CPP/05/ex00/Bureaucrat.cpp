#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default") , grade_(155) {
	std::cout << "Default Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : name_(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade_ = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {}

// Can't be implemented because the member name_ is 'const' and it cannot be assigned using '='
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	(void)other;
	return *this;
}

const std::string Bureaucrat::getName() const {
	return name_;
}

unsigned int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::decrementGrade() {
	if (grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
}

void Bureaucrat::incrementGrade() {
	if (grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: Grade to High. (grade < 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: Grade to Low. (grade > 150)";
}
