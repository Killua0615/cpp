#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/*
TEST CASE
./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

./convert a
char: 'a'
int: 97
float: 97.0f
double: 97.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert +inf
char: impossible
int: impossible
float: +inff
double: +inf

./convert 12abc
char: impossible
int: impossible
float: impossible
double: impossible
*/
