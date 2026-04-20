#include "ScalarPrinter.hpp"
#include <iostream>
#include <sstream>
#include <cctype>


void ScalarPrinter::output(char* value)
{
    std::cout << "char   : ";
    if (!value)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<unsigned char>(*value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << *value << "'" << std::endl;
}

void ScalarPrinter::output(int* value)
{
    std::cout << "int    : ";
    if (!value)
        std::cout << "impossible" << std::endl;
    else
        std::cout << *value << std::endl;
}

void ScalarPrinter::output(float* value)
{
    std::cout << "float  : ";
    if (!value)
        std::cout << "nanf" << std::endl;
    else
    {
        std::cout << *value;
        if (*value == static_cast<long>(*value))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarPrinter::output(double* value)
{
    std::cout << "double : ";
    if (!value)
        std::cout << "nan" << std::endl;
    else
    {
        std::cout << *value;
        if (*value == static_cast<long>(*value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}
