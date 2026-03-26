#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	srand((unsigned)time(NULL));

	Intern intern;
	Bureaucrat GOD("Almighty", 1);
	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *presidential = NULL;
	AForm *impossible = NULL;

	try
	{
		shrubbery = intern.makeForm("shrubbery creation", "Manzanas");
		std::cout << *shrubbery << "\n";

		robotomy = intern.makeForm("robotomy request", "Messi");
		std::cout << *robotomy << "\n";

		presidential = intern.makeForm("presidential pardon", "For John");
		std::cout << *presidential << "\n";

		impossible = intern.makeForm("Mortgage loan", "Marvin");
		std::cout << *impossible << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Intern cannot create form because " << e.what() << RST "\n";
	}


	std::cout << YELLOW << "Execute the forms" << RST "\n";

	if (shrubbery)
	{
		GOD.signForm(*shrubbery);
		GOD.executeForm(*shrubbery);
	}
	if (robotomy)
	{
		GOD.signForm(*robotomy);
		GOD.executeForm(*robotomy);
	}
	if (presidential)
	{
		GOD.signForm(*presidential);
		GOD.executeForm(*presidential);
	}

	if (impossible)
	{
		GOD.signForm(*impossible);
		GOD.executeForm(*impossible);
	}

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return 0;
}
