#include "Serialize.hpp"

int main()
{
	Data data;
	data.s = "Data is Money";
	data.n = 42;

	// Serialize ser;
	
	uintptr_t serializedValue = Serialize::serialize(&data);
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "serializedValue  : " << serializedValue << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	Data *deserializedValue = Serialize::deserialize(serializedValue);

	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "&data            : " << &data << std::endl;
	std::cout << "deserializeValue : " << deserializedValue << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << deserializedValue->s << " + " << deserializedValue->n << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}