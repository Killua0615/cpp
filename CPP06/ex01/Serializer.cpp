#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) { (void)src; }
Serializer& Serializer::operator=(const Serializer& rhs) { (void)rhs; return *this; }
Serializer::~Serializer() {}

//Cast to extract the address value as an integer
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

//↑serialised into an integer back into a Data* (pointer)
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
