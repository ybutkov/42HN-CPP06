#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

void test()
{
    const std::string tests[] = {
        "0", "nan", "nanf", "42.0f",
        "a", "Y", "9", "42.100000f",
        "-42", "42", "126", "127", "2147483647", "-2147483648", "2147483648",
        "0.0", "-4.2", "4.2", "0.0f", "-42.0f", "42.42f", "3.1415f",
        "+inf", "-inf", "+inff", "-inff",
        "hello", "0f", "f", "--42", "42,42", "42.42ups",	
    };

	const int count = sizeof(tests) / sizeof(tests[0]);


	for (int i = 0; i < count; ++i)
    {
		std::cout << "======== Test: " << tests[i] << " ========" << std::endl;
		try
		{
			ScalarConverter::convert(tests[i]);
			std::cout << "==================================\n" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
    }
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		test();
		return 0;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// double d = 4.42;
	// std::cout << "\n" << std::fixed << std::setprecision(20) << d << std::endl;
	return 0;
}
