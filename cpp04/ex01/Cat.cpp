#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    CatBrain = new Brain();
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    type = "Cat";
    CatBrain = new Brain(*other.CatBrain); //deep copy
    std::cout << "Copy Cat constructor called.\n";
}

Cat::~Cat()
{
    std::cout << "Cat " << type << " destructor called\n";
    delete(CatBrain);
}


Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = "Cat";
		delete(CatBrain);
		CatBrain = new Brain(*other.CatBrain);
		std::cout << "Cat copy assignment operator called.\n";
	}
    return(*this);
}


void Cat::makeSound() const
{
    std::cout << "Cat do meaw meaw meaw\n";
}

