#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default Cure constructor called\n"
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Copy Cure constructor called\n";
}

Cure::~Cure()
{
    std::cout << "Default ACure " << type << " Destructor called\n";
}


Cure& Cure::operator=(const Cure& other)
{
    if(this != other)
    {
        AMateria::operator=(other);
        std::cout << "Cure copy assignment called\n";
    }
    return(*this);
}


AMateria* Cure::clone() const
{
    return(new Cure(*this));
}

void use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl
}
