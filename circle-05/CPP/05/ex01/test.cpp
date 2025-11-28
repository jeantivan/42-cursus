#include "test.hpp"

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
		std::cerr << RED"Exception: " << e.what() << RST"\n";
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
		std::cerr << RED"Exception: " << e.what() << RST"\n";
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
		std::cerr << RED"Exception: " << e.what() << RST"\n";
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
		std::cout << GREEN"Bureaucrat " << buro.getName() << " signed " << form.getName() << RST"\n";
		std::cout << form << "\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << RED"Exception: " << e.what() << RST"\n";
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
		std::cout << GREEN"Bureaucrat " << buro.getName() << " signed " << form.getName() << RST"\n";

		form.beSigned(buro);
		std::cout << form << "\n";
		std::cout << GREEN"Bureaucrat " << buro.getName() << " signed " << form.getName() << RST"\n";


	}
	catch(const std::exception& e)
	{
		std::cerr << RED"Exception: Bureaucrat " << buro.getName() << " couldn't sign " << form.getName() << " because " << e.what() << RST"\n";
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
		std::cout << GREEN"Bureaucrat " << buro.getName() << " signed " << form.getName() << RST"\n";
	}
	catch(const std::exception& e) {
		std::cerr << RED"Exception: Bureaucrat " << buro.getName() << " couldn't sign " << form.getName() << " because " <<  e.what() << RST"\n";
	}

}
