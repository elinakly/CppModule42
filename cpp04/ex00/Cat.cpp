#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    type = "Cat";
    std::cout << "Copy Cat constructor called.\n";
}

Cat::~Cat()
{
    std::cout << "Cat " << type << " destructor called\n";
}


Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
    {    
        this->Animal::operator=(other);
        type = "Cat";
        std::cout << "Cat copy assignment called.\n";
    }
    return(*this);
}


void Cat::makeSound() const
{
    std::cout << "Cat do meaw meaw meaw\n";
}

