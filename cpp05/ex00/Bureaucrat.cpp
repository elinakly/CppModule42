#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string  name, unsigned int grade)
{
	this->name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroed\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade higher than MaxGrade.";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade lower than MinGrade.";
}

std::string Bureaucrat::getName() const
{
	return(this->name);
}
unsigned int Bureaucrat::getGrade() const
{
	return(this->grade);
}
void Bureaucrat::IncrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}
void Bureaucrat::DicrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur)
{
	out << bur.getName() << ", bureaucrat grade is " << bur.getGrade();
	return(out);
}