#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* Intern::createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	t_create creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	int i = 0;
	while (i < 3) {
		if (formName == names[i]) {
			AForm* f = creators[i](target);
			std::cout << "Intern creates " << f->getName() << std::endl;
			return f;
		}
		i++;
	}
	std::cout << "Intern couldn't create " << formName << std::endl;
	return 0;
}
