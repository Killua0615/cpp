#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		Form topSecret("TopSecret", 50, 10);
		Form easy("Easy", 150, 100);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << topSecret << std::endl;
		std::cout << easy << " \n" << std::endl;

		intern.signForm(topSecret);
		boss.signForm(topSecret);
		std::cout << " " << std::endl;

		intern.signForm(easy);

		std::cout << topSecret << std::endl;
		std::cout << easy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}
	return 0;
}
