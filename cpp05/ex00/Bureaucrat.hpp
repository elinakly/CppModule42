#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		std::string  name;
		unsigned int grade;
	public:
		Bureaucrat(std::string  name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		std::string getName() const;
		unsigned int getGrade() const;
		void IncrementGrade();
		void DicrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);

