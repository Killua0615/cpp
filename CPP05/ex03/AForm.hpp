#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

	//protected: To prevent direct calls to form.action() from external sources (such as main)
	protected:
	//virtual function of the "actual type (derived class)** is called.
  //= 0, therefore AForm itself has no implementation; the derived class must implement it.
		virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
