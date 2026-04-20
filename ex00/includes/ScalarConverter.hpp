#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include "ScalarPrinter.hpp"


class ScalarConverter
{
    private:
        ScalarConverter() {};
        ScalarConverter(const ScalarConverter &other) { (void)other; };
        ScalarConverter& operator=(const ScalarConverter &other) { (void)other; return *this; };
        ~ScalarConverter() {};

		static ScalarPrinter printer;
		static double* getDouble(const std::string& literal);
		static char* convertChar(const std::string& literal);
		static int* convertInt(const std::string& literal);
		static float* convertFloat(const std::string& literal);
		static double* convertDouble(const std::string& literal);
	public:
		static void convert(const std::string& literal);
	
};

#endif
