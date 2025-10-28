#include "AMateria.hpp"

AMateria::AMateria() : type("Default")
{
    std::cout << "Default Material constructor called\n";
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "Type AMateria " << type << " constructor called\n";
}

AMateria::AMateria(const AMateria &other)  : type(other.type)
{
    std::cout << "Copy Animal constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "AMatireal copy assignment called\n";
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "Default AMatireal " << type << " Destructor called\n";
}


void AMateria::use(ICharacter& target)
{
    (void)target;
}
