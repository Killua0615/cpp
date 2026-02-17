#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}

void inc(int &x)
{
	x++;
}

int main()
{
	int a[] = {1, 2, 3, 4};
	iter(a, 4, inc);
	iter(a, 4, print<int>);

  //const therefore its contents cannot be modified
	const std::string s[] = {"aa", "bb", "cc"};
	iter(s, 3, print<std::string>);

	return 0;
}
