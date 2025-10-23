#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), name("Default")
{
    std::cout << "Default DiamondTrap constructor called\n";
    this->hit_points = FragTrap::Frag_hit_points;
    this->energy_point = ScavTrap::Scav_energy_points;
    this->attack_damage = FragTrap::Frag_attack_damage;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"), // initialize virtual base only
      ScavTrap(),                     // default initialize ScavTrap
      FragTrap(),                     // default initialize FragTrap
      name(_name)
{
    hit_points = FragTrap::Frag_hit_points;
    energy_point = ScavTrap::Scav_energy_points;
    attack_damage = FragTrap::Frag_attack_damage;
    std::cout << "DiamondTrap name constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      name(other.name)
{
    std::cout << "Copy DiamondTrap constructor called.\n";

    this->hit_points = other.hit_points;
    this->energy_point = other.energy_point;
    this->attack_damage = other.attack_damage;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destructor called\n";
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);  // works only in inharetance 
        name = other.name;
		std::cout << "DiamondTrap copy assignment called.\n";
	}
    return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name 
            << std::endl << "ClapTrap name: " << ClapTrap::name <<std::endl;
}
