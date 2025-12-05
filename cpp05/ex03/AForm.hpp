#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool sign;
		const unsigned int SignGrade;
		const unsigned int ExecGrade;
	protected:
		virtual void FormDoes() const = 0;
	public:
		AForm(std::string name, unsigned int SignGrade, unsigned int ExecGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other); 
		virtual ~AForm();

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
		
		class NotSignedException : public std::exception
		{
			public: 
				const char *what() const noexcept override;
		};

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		std::string getFormName() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;
		bool getStatus() const;
};
std::ostream& operator<<(std::ostream& out, const AForm& f);