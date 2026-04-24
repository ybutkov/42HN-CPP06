#include "ScalarPrinter.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
#include <iomanip>


std::string ScalarPrinter::formatScalar(double value, bool isFloat)
{
    if (std::isnan(value))
        return isFloat ? "nanf" : "nan";
    if (std::isinf(value))
    {
        if (value < 0)
            return isFloat ? "-inff" : "-inf";
        else
            return isFloat ? "+inff" : "+inf";
    }

    std::ostringstream oss;
    if (isFloat)
        oss << std::setprecision(std::numeric_limits<float>::digits10 + 2);
    else
        oss << std::setprecision(std::numeric_limits<double>::digits10 + 2);
    oss << value;
    std::string s = oss.str();
    if (s.find('e') == std::string::npos && s.find('E') == std::string::npos
        && oss.str().find('.') == std::string::npos)
        oss << ".0";

    if (isFloat)
        oss << "f";

    return oss.str();
}

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
        std::cout << "impossible" << std::endl;
    else
        std::cout << formatScalar(*value, true) << std::endl;
}

void ScalarPrinter::output(double* value)
{
    std::cout << "double : ";
    if (!value)
        std::cout << "impossible" << std::endl;
    else
        std::cout << formatScalar(*value, false) << std::endl;
}
