#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=========================\n";
	{
		try
		{
			Bureaucrat a("Bob", 100);
			std::cout << a << "\n";
			Form f("Bla", 100, 1);
			std::cout << f << "\n";
			a.signForm(f);
			std::cout << f << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	std::cout << "=========================\n";
	
	{
		try
		{
			Bureaucrat b("Lola", 25);
			Form f1("Blabla", 20, 1);
			std::cout << f1 << "\n";
			b.signForm(f1);
			std::cout << f1 << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	std::cout << "=========================\n";

	{
		try
		{
			Bureaucrat c("Miky", 150);
			Form f2("Blablabla", 200, 1);
			std::cout << f2 << "\n";
			c.signForm(f2);
			std::cout << f2 << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	std::cout << "=========================\n";
}