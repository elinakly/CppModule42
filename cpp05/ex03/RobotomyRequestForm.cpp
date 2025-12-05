#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target): AForm("RobotomyRequestForm", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return(*this);
} 

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string	RobotomyRequestForm::getTarget() const
{
    return(this->target);
}

void RobotomyRequestForm::FormDoes() const
{
    std::cout << "Drrrrr.. *drilling noises*/n";
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully.\n";
	else
		std::cout << getTarget() << " robotomy failed\n";
}