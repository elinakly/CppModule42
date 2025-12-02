#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string  name;
		unsigned int grade;
	public:
		Bureaucrat(std::string  name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override; //cannot throw, override fuct what from exception
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
		void signForm(Form &F) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);

