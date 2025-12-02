#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string &_target): AForm("RobotomyRequestForm", 72, 45), target(_target)
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
    std::cout << "Drrrrr.." << getTarget() << " has been robotomized successfully 50% of the time.\n"; //Otherwise, it informs that the robotomy failed.

}