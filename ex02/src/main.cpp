#include "Base.hpp"
#include "Classes_ABC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace {
	Base* generate(void)
	{
		int choice = std::rand() % 3;

		if (choice == 0)
			return new A();
		else if (choice == 1)
			return new B();
		else
			return new C();
	}

	void identify(Base* p)
	{
		try
		{
			if (dynamic_cast<A*>(p))
			{
				std::cout << "Object pointed to A" << std::endl;
				return ;
			}

			if (dynamic_cast<B*>(p))
			{
				std::cout << "Object pointed to B" << std::endl;
				return ;
			}

			if (dynamic_cast<C*>(p))
			{
				std::cout << "Object pointed to C" << std::endl;
				return ;
			}
			std::cout << "Unknown Base type" << std::endl;
		}
		catch (const std::bad_cast& ex) {
			std::cout << "Not Base, A, B, C type. Error: " << ex.what() << std::endl;
		}
		catch (const std::exception& ex) {
			std::cout << "Error: " << ex.what() << std::endl;
		}

	}

	void identify(Base& p)
	{
		try
		{
			(void)dynamic_cast<A&>(p);
			std::cout << "Object referenced by A" << std::endl;
			return ;
		}
		catch (const std::bad_cast& ex) { }
		catch (const std::exception& ex) {
			std::cout << "Unexpected Error: " << ex.what() << std::endl;
			return ;
		}

		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Object referenced by B" << std::endl;
			return ;
		}
		catch (const std::bad_cast& ex) { }
		catch (const std::exception& ex) {
			std::cout << "Unexpected Error: " << ex.what() << std::endl;
			return ;
		}

		try
		{
			(void)dynamic_cast<C&>(p);
			std::cout << "Object referenced by C" << std::endl;
			return ;
		}
		catch (const std::bad_cast& ex) { }
		catch (const std::exception& ex) {
			std::cout << "Unexpected Error: " << ex.what() << std::endl;
			return ;
		}

	}
}

int main()
{
	std::srand(std::time(NULL));
	for (int i= 0; i < 5; ++i)
	{
		Base* rand = generate();
		identify(rand);
		identify(*rand);
		delete rand;
		std::cout << "=====================" << std::endl;
	}
	
}
