#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    type = "Dog";
   std::cout << "Copy Dog constructor called.\n";
}

Dog::~Dog()
{
    std::cout << "Dog " << type << " destructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        this->Animal::operator=(other);
        type = "Dog";
        std::cout << "Dog copy assignment called.\n";
    }
    return(*this);
}


void Dog::makeSound() const
{
    std::cout << "Dog do arf arf arf\n";
}
