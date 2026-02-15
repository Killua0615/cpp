#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ": bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& f) const {
	try {
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn’t execute " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}
