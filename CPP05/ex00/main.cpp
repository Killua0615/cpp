// main.cpp
#include "Bureaucrat.hpp"

static void testCreate(const std::string& name, int grade) {
	try {
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Create failed: " << e.what() << std::endl;
	}
}

static void testInc(const std::string& name, int grade) {
	try {
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "after increment: " << b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Increment failed: " << e.what() << std::endl;
	}
}

static void testDec(const std::string& name, int grade) {
	try {
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << "after decrement: " << b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Decrement failed: " << e.what() << std::endl;
	}
}

int main() {
	testCreate("OK_1", 1);
	testCreate("OK_150", 150);
	testCreate("BAD_0", 0);
	testCreate("BAD_151", 151);

	testInc("INC_from_2", 2);
	testInc("INC_from_1", 1);

	testDec("DEC_from_149", 149);
	testDec("DEC_from_150", 150);

	return 0;
}
