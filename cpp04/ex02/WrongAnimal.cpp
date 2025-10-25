#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    this->type = other.type;
    std::cout << "Copy WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal " << type << " Destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "WrongAnimal copy assignment called\n";
    }
    return(*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal " << type << " MakeSound() called\n";
}
