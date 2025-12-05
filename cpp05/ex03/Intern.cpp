
#include "Intern.hpp"
Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

const Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return(*this);
}

Intern::~Intern()
{
}

const char* Intern::NotfoundException::what() const noexcept
{
    return "Intern couldnt find a form\n";
}

AForm* Intern::makeForm(const std::string &FormName, const std::string& target) const
{
    std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;
    for(; i < 3; i++)
    {
        if(FormName == forms[i])
            break;
    }
    switch(i)
    {
        case 0:
            std::cout << "Intern creates " << FormName + '\n';
            return new  RobotomyRequestForm(target);
        case 1:
            std::cout << "Intern creates " << FormName + '\n';
            return new PresidentialPardonForm(target);
        case 2:
            std::cout << "Intern creates " << FormName + '\n';
            return new ShrubberyCreationForm(target);
        default:
            throw Intern::NotfoundException();

    }
}