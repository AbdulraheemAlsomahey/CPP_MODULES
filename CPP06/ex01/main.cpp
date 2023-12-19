#include "Serialize.hpp"

int main()
{
	Data data;
	data.s = "Data";
	data.n = 42;

	int n = 65;
	// Serialize ser;
	int *ptr = &n;
	char *c = reinterpret_cast<char *>(ptr);
	std::cout << c << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ptr << std::endl;
	// uintptr_t serializedValue = &data;
	// std::cout << "-----------------------------------------------------------------------------" << std::endl;
	// std::cout << "serializedValue  : " << serializedValue << std::endl;
	// std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	// Data *deserializedValue = Serialize::deserialize(serializedValue);

	// std::cout << "-----------------------------------------------------------------------------" << std::endl;
	// std::cout << "&data            : " << &data << std::endl;
	// std::cout << "deserializeValue : " << deserializedValue << std::endl;
	// std::cout << "-----------------------------------------------------------------------------" << std::endl;
	// std::cout << deserializedValue->s << " + " << deserializedValue->n << std::endl;
	// std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}