#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string  name, unsigned int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) 
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat::Grade higher than MaxGrade.";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat::Grade lower than MinGrade.";
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
	else
		grade--;
}
void Bureaucrat::DicrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(Form &F) const
{
	try
	{	
		F.beSigned(*this);
		std::cout << this->name <<  " signed " << F.getFormName() << "\n\n";
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << this->name << "  couldn’t sign " << F.getFormName() << " because " << e.what() << "\n";
	}

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur)
{
	out << bur.getName() << ", bureaucrat grade is " << bur.getGrade();
	return(out);
}