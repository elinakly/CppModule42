#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include 
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
	public:
		RobotomyRequestForm(std::string &_target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other); 
		~RobotomyRequestForm() override;

		std::string getTarget() const;
        void FormDoes() const override;
};