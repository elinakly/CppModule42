#include "AForm.hpp"

AForm::AForm(std::string name, unsigned int SignGrade, unsigned int ExecGrade): name(name),
			SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	if (SignGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
	else if (SignGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
	sign = false;
}

AForm::AForm(const AForm& other) : name(other.name),
			SignGrade(other.SignGrade), ExecGrade(other.ExecGrade)
{
	sign = other.sign;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return(*this);
} 

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return("AForm::Grade is too High\n");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return("AForm::Grade is too low\n");
}

const char *AForm::NotSignedException::what() const noexcept
{
	return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->SignGrade)
		throw AForm::GradeTooLowException();
	this->sign = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->ExecGrade)
		throw AForm::GradeTooLowException();
	FormDoes();
}

std::string AForm::getFormName() const
{
	return(this->name);
}

unsigned int AForm::getSignGrade() const
{
	return(this->SignGrade);
}

unsigned int AForm::getExecGrade() const
{
	return(this->ExecGrade);
}

bool AForm::getStatus() const
{
	return(this->sign);
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "AForm name         : " << f.getFormName() << "\n"
		<< "Sign status       : " << (f.getStatus() ? "Signed" : "Not signed") << "\n"
		<< "Grade to sign     : " << f.getSignGrade() << "\n"
		<< "Grade to execute  : " << f.getExecGrade() << "\n";
	return out;
}
