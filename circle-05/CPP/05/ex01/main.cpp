#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void correct_form() {
	std::cout << "\n====    Correct forms    ====\n\n";

	try
	{
		Form def_form;
		std::cout << def_form << "\n";

		Form custom_form("Custom form", 42, 4);
		std::cout << custom_form << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST"\n";
	}
}

void grade_too_high_form() {
	std::cout << "\n====    Grade too high    ====\n\n";

	try
	{
		Form form("High grade", 1, 1);
		std::cout << form << "\n";
		Form form_high("Grade too high", -42, 0);
		std::cout << form_high << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST"\n";
	}
}

void grade_too_low_form() {
	std::cout << "\n====    Grade too low    ====\n\n";

	try
	{
		Form form_low("Grade too low", 150, 42);
		std::cout << form_low << "\n";
		Form form_too_low("Grade too low", 4242, 42);
		std::cout << form_too_low << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST"\n";
	}
}

void correct_signed_form() {
	std::cout << "\n====    Correct signed form    ====\n\n";
	Bureaucrat buro("Jean", 2);
	Form form("Good", 42, 42);

	try
	{
		std::cout << buro << "\n";
		std::cout << form << "\n";
		form.beSigned(buro);
		std::cout << GREEN << buro.getName() << " signed " << form.getName() << RST"\n";
		std::cout << form << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST"\n";
	}
}

void signed_twice_form() {
	std::cout << "\n====    Signed twice form    ====\n\n";
	Bureaucrat buro("Jean", 2);
	Form form("Good form", 42, 42);

	try
	{
		std::cout << buro << "\n";
		std::cout << form << "\n";
		form.beSigned(buro);
		std::cout << form << "\n";
		std::cout << GREEN << buro.getName() << " signed " << form.getName() << RST"\n";

		form.beSigned(buro);
		std::cout << form << "\n";
		std::cout << GREEN << buro.getName() << " signed " << form.getName() << RST"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << buro.getName() << " couldn't sign " << form.getName() << " because " << e.what() << RST"\n";
	}
}

void buro_grade_too_low() {
	std::cout << "\n====    Bureaucrat grade too low    ====\n\n";
	Bureaucrat buro("Jean", 149);
	Form form("Low grade", 22, 1);

	try
	{
		std::cout << buro << "\n";
		std::cout << form << "\n";
		form.beSigned(buro);
		std::cout << GREEN << buro.getName() << " signed " << form.getName() << RST"\n";
	}
	catch(const std::exception& e) {
		std::cerr << RED << buro.getName() << " couldn't sign " << form.getName() << " because " <<  e.what() << RST"\n";
	}

}

int main()
{

	grade_too_high_form();
	grade_too_low_form();
	signed_twice_form();
	buro_grade_too_low();
	correct_form();
	correct_signed_form();

	return 0;
}
