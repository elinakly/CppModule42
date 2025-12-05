
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat john("John", 1);
        Bureaucrat bob("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\nShrubberyCreationForm\n";
        bob.signForm(shrub);       // works (needs grade 145)
        bob.executeForm(shrub);    // fail (exec grade 137)
        john.executeForm(shrub);   // works

        std::cout << "\nRobotomyRequestForm\n";
        john.signForm(robo);
        john.executeForm(robo);    // 50%

        std::cout << "\nTesting PresidentialPardonForm\n";
        john.signForm(pardon);
        john.executeForm(pardon);

        std::cout << "\n Intern search for form\n";
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        john.signForm(*rrf);
        AForm* wrong = someRandomIntern.makeForm("sdfs", "Bender"); 
        john.signForm(*wrong);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
