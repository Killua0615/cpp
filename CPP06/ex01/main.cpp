#include "Serializer.hpp"

int main()
{
	Data d;
	d.n = 42;
	d.x = 3.14;

	Data* original = &d;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original : " << original << std::endl;
	std::cout << "raw      : " << raw << std::endl;
	std::cout << "restored : " << restored << std::endl;

	if (restored == original)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "restored->n = " << restored->n << std::endl;
	std::cout << "restored->x = " << restored->x << std::endl;
	return 0;
}

/*
original is shown in hexadecimal bec it’s a pointer.
raw is shown in decimal bec it’s an integer type.

./serialize 
original : 0x16d792ae8
raw      : 6131624680
restored : 0x16d792ae8
OK
restored->n = 42
restored->x = 3.14
*/