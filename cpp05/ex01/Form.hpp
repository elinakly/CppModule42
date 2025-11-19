#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const unsigned int SingGrade;
		const unsigned int ExecGrade;
	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other); 
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		
		void beSigned(Bureucrat &b);

};
std::ostream& operator<<()