#include "Bureaucrat.hpp"

Bureucrat::Bureucrat(std::string  name, unsigned int grade)
{
	this->name = name;
	this->grade = grade;

}
Bureucrat::Bureucrat(const Bureucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
}

Bureucrat::~Bureucrat()
{
	std::cout << "Destroed\n";
}

Bureucrat& Bureucrat::operator=(const Bureucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return(*this);
}

unsigned int Bureucrat::operator>>(const Bureucrat& other)
{
	return(this->grade);
}

void Bureucrat::GradeTooHighException()
{
	std::cout << "Grade is too high\n";
}

void Bureucrat::GradeTooLowException()
{
	std::cout << "Grade is too low\n";
}

std::string Bureucrat::getName()
{
	return(this->name);
}
unsigned int Bureucrat::getGrade()
{
	return(this->grade);
}
void Bureucrat::IncrementGrade(int grade)
{
	this->grade += grade;
}
void Bureucrat::DicrementGrade(int grade)
{
	this->grade -= grade;
}