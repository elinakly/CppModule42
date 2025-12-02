#include "Form.hpp"

Form::Form(std::string name, unsigned int SignGrade, unsigned int ExecGrade): name(name),
			SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	if (SignGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
	else if (SignGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
	sign = false;
}

Form::Form(const Form& other) : name(other.name),
			SignGrade(other.SignGrade), ExecGrade(other.ExecGrade)
{
	sign = other.sign;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return(*this);
} 

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return("Form::Grade is too High\n");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return("Form::Grade is too low\n");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->SignGrade)
		throw Form::GradeTooLowException();
	this->sign = true;
}

std::string Form::getFormName() const
{
	return(this->name);
}

unsigned int Form::getSignGrade() const
{
	return(this->SignGrade);
}

unsigned int Form::getExecGrade() const
{
	return(this->ExecGrade);
}

bool Form::getStatus() const
{
	return(this->sign);
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form name         : " << f.getFormName() << "\n"
		<< "Sign status       : " << (f.getStatus() ? "Signed" : "Not signed") << "\n"
		<< "Grade to sign     : " << f.getSignGrade() << "\n"
		<< "Grade to execute  : " << f.getExecGrade() << "\n";
	return out;
}
