#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat a("Bob", 100);
			std::cout << a << std::endl;
			a.DicrementGrade();
			std::cout << a << std::endl;
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	{
		try
		{
			Bureaucrat b("Lola", 1);
			std::cout << b << std::endl;
			b.IncrementGrade();
			std::cout << b << std::endl;
			
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			Bureaucrat c("Miky", 150);
			std::cout << c << std::endl;
			c.DicrementGrade();
			std::cout << c << std::endl;
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}