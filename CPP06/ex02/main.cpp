#include "Base.hpp"
#include <cstdlib>
#include <ctime>

//Since genirate() return type is Base*, the caller cannot determine which type was passed.
//The objective of the task is to identify this using identify.

int main()
{
	//Set a different starting value each time using time(0) → The output of rand() changes each time
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
