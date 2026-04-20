#include "Data.hpp"
#include <sstream>  

Data::Data(const Data& other)
{
	*this = other;
}

Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		strData = other.strData;
		intData = other.intData;
		charData = other.charData;
	}
	return *this;
}

std::string Data::toString() const
{
    std::stringstream ss;
    ss << "strData: " << strData
        << ", intData: " << intData
        << ", charData: " << charData;
    return ss.str();
}
