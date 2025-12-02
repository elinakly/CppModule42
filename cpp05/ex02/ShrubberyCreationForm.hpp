#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include 
class Bureaucrat;

class  ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
	public:
		ShrubberyCreationForm(std::string &_target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); 
		~ShrubberyCreationForm() override;

		std::string getTarget() const;
        void FormDoes() const override;
};
