#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

//Initialised from copy generation other
Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

//Function for reading the contents
const std::string& Form::getName() const { return this->_name; }
bool Form::getIsSigned() const { return this->_isSigned; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() { return "form grade too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName()
	   << " | signed: " << (f.getIsSigned() ? "true" : "false")
	   << " | gradeToSign: " << f.getGradeToSign()
	   << " | gradeToExecute: " << f.getGradeToExecute();
	return os;
}
