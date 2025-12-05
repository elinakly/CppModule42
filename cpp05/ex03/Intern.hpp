#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
class AForm;


class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern& other);
        const Intern& operator=(const Intern& other);
        ~Intern();
        AForm* makeForm(const std::string &FormName, const std::string &target) const;
        class NotfoundException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};