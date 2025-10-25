#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
    std::cout << "Copy Brain constructor called\n";
}

Brain::~Brain()
{
    std::cout << "Default Brain Destructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
	    for (int i = 0; i < 100; i++)
		    ideas[i] = other.ideas[i];
        std::cout << "Brain copy assignment called\n";
    }
    return(*this);
}
