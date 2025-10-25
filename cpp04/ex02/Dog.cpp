#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    DogBrain = new Brain();
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    type = "Dog";
    DogBrain = new Brain(*other.DogBrain);
    std::cout << "Copy Dog constructor called.\n";
}

Dog::~Dog()
{
    std::cout << "Dog " << type << " destructor called\n";
    delete(DogBrain);
}

Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        this->Animal::operator=(other);
        delete(DogBrain);
        type = "Dog";
        DogBrain = new Brain(*other.DogBrain);
        std::cout << "Dog copy assignment operator called.\n";
    }
    return(*this);
}


void Dog::makeSound() const
{
    std::cout << "Dog do arf arf arf\n";
}
