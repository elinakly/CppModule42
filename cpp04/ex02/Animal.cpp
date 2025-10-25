#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Default Animal constructor called\n";
}

Animal::Animal(const Animal& other)
{
    this->type = other.type;
    std::cout << "Copy Animal constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Default Animal " << type << " Destructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "Animal copy assignment called\n";
    }
    return(*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal " << type << " MakeSound() called\n";
}
