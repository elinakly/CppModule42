#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < slot; i++)
        templates[i] = NULL;
    std::cout << "Default MateriaSource constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for(int i = 0; i < slot; i++)
    {
        if (other.templates[i])
            this->templates[i] = other.templates[i]->clone();
        else
            this->templates[i] = NULL;
    }
    std::cout << "Copy MateriaSource constructor called\n"; 
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < slot; i++)
	{
		if (templates[i])
		{
			delete templates[i];
			templates[i] = nullptr;
		}
	}
    std::cout << "Material destructor called\n";
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for(int i = 0; i < slot; i++)
        {
            delete templates[i]; 
            if (other.templates[i])
                this->templates[i] = other.templates[i]->clone();
            else
                this->templates[i] = NULL;
        }
        std::cout << "MateriaSource copy assignment called\n";
    }
    return(*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < slot; i++)
	{
		if (!templates[i])
		{
			templates[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < slot; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
			return templates[i]->clone();
	}
	return nullptr;
}

