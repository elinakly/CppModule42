#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default Ice constructor called\n";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "Copy Ice constructor called\n";
}

Ice::~Ice()
{
    std::cout << "Default AIce " << type << " Destructor called\n";
}


Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Ice copy assignment called\n";
    }
    return(*this);
}


AMateria* Ice::clone() const
{
    return(new Ice(*this));
}


void Ice::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}