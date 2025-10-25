#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    type = "WrongCat";
    std::cout << "Copy WrongCat constructor called.\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat " << type << " destructor called\n";
}


WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
    {    
        this->WrongAnimal::operator=(other);
        type = "WrongCat";
        std::cout << "WrongCat copy assignment called.\n";
    }
    return(*this);
}


void WrongCat::makeSound() const
{
    std::cout << "WrongCat do meaw meaw meaw\n";
}

