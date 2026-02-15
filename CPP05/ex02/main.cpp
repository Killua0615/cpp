#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(std::time(NULL));

	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 50);
		Bureaucrat intern("Intern", 150);

		ShrubberyCreationForm s("home");
		RobotomyRequestForm r("Bender");
		PresidentialPardonForm p("Arthur");

		std::cout << boss << std::endl;
		std::cout << mid << std::endl;
		std::cout << intern << "\n" << std::endl;

		std::cout << s << std::endl;
		std::cout << r << std::endl;
		std::cout << p << "\n" << std::endl;

		intern.executeForm(s);
		intern.signForm(s);
		std::cout << " " << std::endl;
	
		mid.signForm(s);
		mid.executeForm(s);
		std::cout << " " << std::endl;

		boss.signForm(r);
		boss.executeForm(r);
		std::cout << " " << std::endl;

		mid.signForm(p);
		boss.signForm(p);
		mid.executeForm(p);
		boss.executeForm(p);

	} 
	//exception occurs display the cause and terminate without crashing the programme
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}
	return 0;
}
