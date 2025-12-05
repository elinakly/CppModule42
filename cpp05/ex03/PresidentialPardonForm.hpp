#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	target;
	protected:
		void FormDoes() const override;
	public:
		PresidentialPardonForm(const  std::string &_target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other); 
		~PresidentialPardonForm() override;

		std::string getTarget() const;
};