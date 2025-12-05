#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class  ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
	protected:
		void FormDoes() const override;
	public:
		ShrubberyCreationForm(const std::string &_target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); 
		~ShrubberyCreationForm() override;

		std::string getTarget() const;
};
