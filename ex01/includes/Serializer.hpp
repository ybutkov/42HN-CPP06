#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include "Data.hpp"
#include <string>
#include <iostream>


class Serializer
{
    private:
        Serializer() {};
        Serializer(const Serializer &other) { (void)other; };
        Serializer& operator=(const Serializer &other) { (void)other; return *this; };
        ~Serializer() {};

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
};

#endif
