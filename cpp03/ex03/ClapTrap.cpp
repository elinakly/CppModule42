#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default")
{
	std::cout << "Default ClapTrap constructor called." << std::endl;    
}

ClapTrap::ClapTrap(std::string n) : name(n)
{
	std::cout << "Name ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy ClapTrap constructor called." << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy ClapTrap assignment operator called." << std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_point = other.energy_point;
        this->attack_damage = other.attack_damage;
    }
    return(*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed." << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_point > 0 && hit_points > 0)
    {
        energy_point--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
    }
    if (energy_point == 0)
        std::cout << "ClapTrap " << name << " run out of energy points \n";
    if (hit_points == 0)
        std::cout << "ClapTrap " << name << " cannot attack is already dead!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!\n";
        return;
    }
    if(amount >= hit_points)
    {
        hit_points = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and dies!\n";
    }
    else 
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << name << " is being damaged by " << amount << " points of damage!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_point > 0 && hit_points > 0)
    {
        hit_points += amount;
        energy_point--;
        std::cout << "ClapTrap " << name << " repairs itself for "
                  << amount << " HP, now at " << hit_points << " HP.\n";
    }
    else if (energy_point == 0)
        std::cout << "ClapTrap " << name << " cannot repair (no energy).\n";
    else if (hit_points == 0)
        std::cout << "ClapTrap " << name << " cannot repair (died).\n";        
}
