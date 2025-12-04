#include "test.hpp"

void no_signed_forms() {
	std::cout << "\n" << BG_GREEN"====    No signed forms    ====" << RST"\n\n";

	Bureaucrat buro("Jean", 1);
	AForm *shrubbery = new ShrubberyCreationForm("Tree");
	AForm *robotomy = new RobotomyRequestForm("Pepito patatero");
	AForm *presidential = new PresidentialPardonForm("John Doe");

	std::cout << RED"\n";
	buro.executeForm(*shrubbery);
	buro.executeForm(*robotomy);
	buro.executeForm(*presidential);
	std::cout << RST"\n";

	delete shrubbery;
	delete robotomy;
	delete presidential;

}

void buro_grade_too_low_to_execute() {
	std::cout << "\n" << BG_GREEN"====    Buro grade too low    ====" << RST"\n\n";

	Bureaucrat buro("Jean", 1);
	Bureaucrat fake("Pepe", 150);

	AForm *shrubbery = new ShrubberyCreationForm("Tree");
	AForm *robotomy = new RobotomyRequestForm("Pepito patatero");
	AForm *presidential = new PresidentialPardonForm("John Doe");

	std::cout << "\n";
	buro.signForm(*shrubbery);
	buro.signForm(*robotomy);
	buro.signForm(*presidential);

	std::cout << "\n" << *shrubbery << "\n";
	std::cout << *robotomy << "\n";
	std::cout << *presidential << "\n";

	std::cout << RED;
	fake.executeForm(*shrubbery);
	fake.executeForm(*robotomy);
	fake.executeForm(*presidential);
	std::cout << RST"\n";

	delete shrubbery;
	delete robotomy;
	delete presidential;
}


void correct_execution() {
	std::cout << "\n" << BG_GREEN"====    Correct execution    ====" << RST"\n\n";

	AForm *shrubbery = new ShrubberyCreationForm("Tree");
	AForm *robotomy = new RobotomyRequestForm("Pepito patatero");
	AForm *presidential = new PresidentialPardonForm("John Doe");

	Bureaucrat almighty("Almighty", 1);
	Bureaucrat civil_executor("Civil", 150);
	Bureaucrat shrubbery_executor("Gardener", 137);
	Bureaucrat robotomy_executor("Mechanic", 45);
	Bureaucrat presidential_executor("Zaphod", 5);

	std::cout << "\n";
	civil_executor.signForm(*shrubbery);
	shrubbery_executor.signForm(*shrubbery);
	std::cout << "\n";

	shrubbery_executor.signForm(*robotomy);
	robotomy_executor.signForm(*robotomy);
	std::cout << "\n";


	robotomy_executor.signForm(*presidential);
	presidential_executor.signForm(*presidential);
	std::cout << "\n";

	std::cout << "\n";
	civil_executor.executeForm(*shrubbery);
	shrubbery_executor.executeForm(*shrubbery);
	std::cout << "\n";

	shrubbery_executor.executeForm(*robotomy);
	robotomy_executor.executeForm(*robotomy);
	std::cout << "\n";


	robotomy_executor.executeForm(*presidential);
	presidential_executor.executeForm(*presidential);
	std::cout << "\n";


	delete shrubbery;
	delete robotomy;
	delete presidential;
}
