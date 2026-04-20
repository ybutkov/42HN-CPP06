#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <errno.h>


double* ScalarConverter::getDouble(const std::string& literal)
{
    char* endptr;
    errno = 0;
    double value = std::strtod(literal.c_str(), &endptr);

    if (errno == ERANGE || endptr == literal.c_str() || (*endptr != '\0' && std::string(endptr) != "f"))
        return nullptr;

    return new double(value);
}

char* ScalarConverter::convertChar(const std::string& literal)
{
    double* dbl = getDouble(literal);
    if (!dbl) return nullptr;

    if (std::isnan(*dbl) || std::isinf(*dbl) || *dbl < 0 || *dbl > 127)
    {
        delete dbl;
        return nullptr;
    }
    char* res = new char(static_cast<char>(*dbl));
    delete dbl;
    return res;
}

int* ScalarConverter::convertInt(const std::string& literal)
{
    double* dbl = getDouble(literal);
    if (!dbl) return nullptr;

    if (std::isnan(*dbl) || std::isinf(*dbl) || *dbl < INT_MIN || *dbl > INT_MAX)
    {
        delete dbl;
        return nullptr;
    }
    
    int* res = new int(static_cast<int>(*dbl));
    delete dbl;
    return res;
}

float* ScalarConverter::convertFloat(const std::string& literal)
{
    double* dbl = getDouble(literal);
    if (!dbl) return nullptr;

    if (!std::isnan(*dbl) && !std::isinf(*dbl) && (std::abs(*dbl) > FLT_MAX))
    {
        delete dbl;
        return nullptr;
    }

    float* res = new float(static_cast<float>(*dbl));
    delete dbl;
    return res;
}

double* ScalarConverter::convertDouble(const std::string& literal)
{
    return getDouble(literal);
}

void ScalarConverter::convert(const std::string& literal)
{
	char* ch = convertChar(literal);
	int* integer = convertInt(literal);
	float* fl = convertFloat(literal);
	double* dbl = convertDouble(literal);
    printer.output(ch);
    printer.output(integer);
    printer.output(fl);
    printer.output(dbl);

    delete ch;
    delete integer;
    delete fl;
    delete dbl;
}