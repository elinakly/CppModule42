#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
	protected:
		void FormDoes() const override;
	public:
		RobotomyRequestForm(const std::string &_target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other); 
		~RobotomyRequestForm() override;

		std::string getTarget() const;
};