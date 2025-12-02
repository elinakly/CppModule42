#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const unsigned int SignGrade;
		const unsigned int ExecGrade;
	protected:
		virtual void FormDoes(int target) = 0;
	public:
		Form(std::string name, unsigned int SignGrade, unsigned int ExecGrade);
		Form(const Form& other);
		Form& operator=(const Form& other); 
		virtual ~Form();

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
		
		void beSigned(const Bureaucrat &b);
		std::string getFormName() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;
		bool getStatus() const;
};
std::ostream& operator<<(std::ostream& out, const Form& f);