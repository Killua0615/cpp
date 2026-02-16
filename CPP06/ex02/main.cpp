#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
