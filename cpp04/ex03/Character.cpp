#include "Character.hpp"

Character::Character() : name("Default")
{
    for (int i = 0; i < slot; i++)
        inventory[i] = NULL;
    floor = NULL;
    std::cout << "Default Character constructor called\n";
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < slot; i++)
        inventory[i] = NULL;
    floor = NULL;
    std::cout << "Name " << name << " ICharacter constructor called\n";
}

Character::Character(const Character& other) 
{
    this->name = other.name;
    for(int i = 0; i < slot; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    this->floor = other.floor;
    std::cout << "Copy Character constructor called\n"; 
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for(int i = 0; i < slot; i++)
        {
            delete inventory[i]; 
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
        this->floor = other.floor;
        std::cout << "Character copy assignment called\n";
    }
    return(*this);
}

Character::~Character()
{
    for(int i = 0; i < slot; i++)
    {
        delete(inventory[i]);
    }
    std::cout << "Character destructor called\n";
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < slot; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < slot && inventory[idx])
        inventory[idx]->use(target);
}

