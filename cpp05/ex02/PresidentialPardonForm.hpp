#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include 
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	target;
	public:
		PresidentialPardonForm(std::string &_target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other); 
		~PresidentialPardonForm() override;

		std::string getTarget() const;
        void FormDoes() const override;
};