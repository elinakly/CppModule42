#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    hit_points = 100;
    Scav_energy_points = 50;
    attack_damage = 20;
    std::cout << "Default constractor ScavTrap is called\n";
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    hit_points = 100;
    Scav_energy_points = 50;
    attack_damage = 20;
    std::cout << "Name ScanTrap constractor is called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)   // works only in inharetance 
{
    std::cout << "Copy ScavTrap constructor called.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);  // works only in inharetance 
		std::cout << "ScavTrap copy assignment called.\n";
	}
    return(*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_point > 0 && hit_points > 0)
    {
        energy_point--;
        std::cout << "PPRRRRR.. ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
    }
    if (energy_point == 0)
        std::cout << "OOOEPS ScavTrap " << name << " run out of energy points \n";
    if (hit_points == 0)
        std::cout << "UUUH ScavTrap " << name << " cannot attack is already dead!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap" << name << "ScavTrap is now in Gate keeper mode.\n";
}