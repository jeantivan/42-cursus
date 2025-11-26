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
	try
	{
		Bureaucrat buro("Jean", 2);
		Form good("Good", 42, 42);

		std::cout << buro << "\n";
		std::cout << good << "\n";
		good.beSigned(buro);
		std::cout << good << "\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << RED"Exception: " << e.what() << RST"\n";
	}
}

void signed_twice_form() {
	std::cout << "\n====    Signed twice form    ====\n\n";
	try
	{
		Bureaucrat buro("Jean", 2);
		Form good("Good", 42, 42);

		std::cout << buro << "\n";
		std::cout << good << "\n";
		good.beSigned(buro);
		std::cout << good << "\n";

		good.beSigned(buro);
		std::cout << good << "\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << RED"Exception: " << e.what() << RST"\n";
	}
}

