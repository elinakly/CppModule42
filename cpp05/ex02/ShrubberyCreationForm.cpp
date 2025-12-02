#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string &_target): AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return(*this);
} 

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string	ShrubberyCreationForm::getTarget() const
{
    return(this->target);
}

void ShrubberyCreationForm::FormDoes() const
{
   //Creates a file <target>_shrubbery in the working directory and writes ASCII tree inside it.
}