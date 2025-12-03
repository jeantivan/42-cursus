#include "ShrubberyCreationForm.hpp"

// Canonical orthodox form
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm Default", 145, 137), target("") {
	std::cout << "ShrubberyForm 'Default' created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) : AForm("ShrubberyForm " + t, 145, 137), target(t) {
	std::cout << "ShrubberyForm '" + target + "' created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
	std::cout << "ShrubberyForm copied\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyForm " << getName() << " destroyed\n";
}

// Exception
const char* ShrubberyCreationForm::InvalidFileException::what() const throw()
{
	return "It was not possible to plant the tree in the file";
}

void ShrubberyCreationForm::formAction() const {
	std::string filename = target + "_shrubbery";
	std::ofstream file;

	file.open(filename.c_str(), std::ios::out);
	if (file.fail())
		throw InvalidFileException();

	file << "               ,@@@@@@@,\n";
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    file << "       |o|        | |         | |\n";
    file << "       |.|        | |         | |\n";
    file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

	std::cout << "Tree planted in " + filename + "\n";

	file.close();
}
