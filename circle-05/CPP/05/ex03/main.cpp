#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"

int main()
{
	srand((unsigned)time(NULL));

	Intern intern;

	try {
		AForm* shrubbery = intern.makeForm("shrubbery creation", "manzanas");
		std::cout << *shrubbery << "\n";

		AForm* robotomy = intern.makeForm("robotomy request", "God");
		std::cout << *robotomy << "\n";

		AForm* presidential = intern.makeForm("presidential pardon", "John");
		std::cout << *presidential << "\n";

		AForm* impossible = intern.makeForm("kickflip varial", "Tony Hawks");
		std::cout << *impossible << "\n";

	} catch (std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << RST"\n";
	}
	return 0;
}
