#ifndef SCALAR_PRINTER_HPP
# define SCALAR_PRINTER_HPP

#include <string>
#include <iostream>


class ScalarPrinter
{
    private:
        ScalarPrinter() {};
        ScalarPrinter(const ScalarPrinter &other) { (void)other; };
        ScalarPrinter& operator=(const ScalarPrinter &other) { (void)other; return *this; };
        ~ScalarPrinter() {};
        
        static std::string formatScalar(double value, bool isFloat);

	public:
		static void output(char* value);
		static void output(int* value);
		static void output(float* value);
		static void output(double* value);
};

#endif
