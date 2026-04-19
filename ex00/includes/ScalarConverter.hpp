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

		// static void formatString(const std::string& type, void* value);
		// static void display(void* value, const std::string& type);
		// static void ScalarConverter::display(char* value);
		// static void ScalarConverter::display(int* value);
		// static void ScalarConverter::display(float* value);
		// static void ScalarConverter::display(double* value);

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
