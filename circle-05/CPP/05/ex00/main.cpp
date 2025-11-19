#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test 1 (Basic example)\n" << std::endl;

		try {
			Bureaucrat bur1("Bush", 4);
			std::cout << bur1 << std::endl;
			Bureaucrat bur2 = bur1;
			std::cout << bur2 << std::endl;
			Bureaucrat bur3("Patroclio", 132);
			std::cout << bur3 << std::endl;
			// Can't asign using '='
			//bur2 = bur1;
			bur1.incrementGrade();
			std::cout << bur1 << std::endl;
			bur3.decrementGrade();
			std::cout << bur3 << std::endl;
		} catch (std::exception& e) {
			// No needed
		}
	}

	{
		std::cout << "\nTest 2 (Grade too high/low)\n" << std::endl;

		try {
			Bureaucrat bur1("Bush", 0);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat bur2("Patroclio", 200);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	};

	{
		std::cout << "\nTest 3 (Increment/decrement grade)\n" << std::endl;

			try {
			Bureaucrat bur3("Trump", 4);
			for (int i = 0; i < 10; i++)
			{
				bur3.incrementGrade();
				std::cout << bur3 << std::endl;
			}
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat bur4("Infante", 145);
			for (int i = 0; i < 10; i++)
			{
					bur4.decrementGrade();
					std::cout << bur4 << std::endl;
			}
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	};
	return 0;
}
