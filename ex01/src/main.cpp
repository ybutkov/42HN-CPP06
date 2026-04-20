#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>


int main()
{
	Data* data = new Data("Data string", 42, 'c');
	std::cout << data->toString() << std::endl;

	uintptr_t serializedData = Serializer::serialize(data);
	std::cout << serializedData  << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << deserializedData->toString() << std::endl;

	delete data;
	return 0;
}
