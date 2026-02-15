#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
	typedef AForm* (*t_create)(const std::string& target);

	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidential(const std::string& target);
};

#endif
