#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	srand((unsigned)time(NULL));


	Bureaucrat buro("Jean", 2);
	AForm* shrubbery = new ShrubberyCreationForm("tree");

	try {
		shrubbery->beSigned(buro);
		shrubbery->execute(buro);
	} catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	delete shrubbery;

	return 0;
}
