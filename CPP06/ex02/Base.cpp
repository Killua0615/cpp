#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base() {}

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0: std::cout << "Generated A" << std::endl; return new A();
		case 1: std::cout << "Generated B" << std::endl; return new B();
		default: std::cout << "Generated C" << std::endl; return new C();
	}
}

/*
Determine whether it is A, B, or C,practice both.
 dynamic_cast fails differently:
 - pointer cast returns NULL
 - reference cast throws an exception

`Base* p = new C();`
 Appearance type (compile-time type): Base*
 → The type of variable p. Only Base is known in the code
 Actual type (runtime type): C
 → The genuine contents created by new C().

If p points to content that is truly C → return C* (success)
If it is not C → return NULL (failure)
*/
void identify(Base* p)
{
	std::cout << "Identify pointer: ";
	if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
	else std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identify reference: ";
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; } catch (...) {}
	std::cout << "Unknown" << std::endl;
}
