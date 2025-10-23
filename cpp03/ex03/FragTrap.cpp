#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    Frag_hit_points = 100;
    energy_point = 100;
    Frag_attack_damage = 30;
    std::cout << "Default constractor FragTrap is called\n";
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
    Frag_hit_points = 100;
    energy_point = 100;
    Frag_attack_damage = 30;
    std::cout << "Name FragTrap constractor is called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copy FragTrap constructor called.\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name  <<  " destructor called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->ClapTrap::operator=(other);
        std::cout << "FragTrap copy assignment called.\n";
    }
    return(*this);
}

void 	FragTrap::attack(const std::string& target)
{
    if (energy_point > 0 && hit_points > 0)
        {
            energy_point--;
            std::cout << "Piupiu.. FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
        }
        if (energy_point == 0)
            std::cout << "Woump FragTrap " << name << " run out of energy points \n";
        if (hit_points == 0)
            std::cout << "Shhhit FragTrap " << name << " cannot attack is already dead!\n";
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << name << " turn on the highFiveGuys mode!\n";   
}