#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	try {
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 50);
		Bureaucrat intern("Intern", 150);

		//The design returns objects created with new, making it well-suited to pointers. Since new returns pointers,
		AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
		AForm* f4 = someRandomIntern.makeForm("unknown form", "X");
		std::cout << " " << std::endl;

		if (f1) {
			intern.executeForm(*f1);
			mid.signForm(*f1);
			mid.executeForm(*f1);
			std::cout << " " << std::endl;
		}
		if (f2) {
			boss.signForm(*f2);
			boss.executeForm(*f2);
			std::cout << " " << std::endl;
		}
		if (f3) {
			mid.signForm(*f3);
			boss.signForm(*f3);
			boss.executeForm(*f3);
			std::cout << " " << std::endl;
		}
		if (f4) {
			boss.signForm(*f4);
			boss.executeForm(*f4);
		}

		//Items created with `new` do not disappear automatically; release them with `delete` when finished.
		delete f1;
		delete f2;
		delete f3;
		delete f4;

	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}
	return 0;
}
