#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;

	Array<int> b(5);
	std::cout << "b.size() = " << b.size() << std::endl;
  std::cout << " " << std::endl;

	std::size_t i = 0;
	while (i < b.size())
	{
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
		i++;
	}
  std::cout << " " << std::endl;

	b[0] = 42;
	Array<int> c(b);
	b[0] = 7;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "c[0] = " << c[0] << std::endl;
  std::cout << " " << std::endl;

	Array<std::string> s(3);
	s[0] = "aa";
	s[1] = "bb";
	s[2] = "cc";
	const Array<std::string> cs(s);
	std::cout << "cs[1] = " << cs[1] << std::endl;

	try
	{
		std::cout << b[999] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
