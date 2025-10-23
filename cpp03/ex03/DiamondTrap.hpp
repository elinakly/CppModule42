#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string n);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

        DiamondTrap& operator=(const DiamondTrap& other);

        void attack(const std::string& target);
        void whoAmI();
        std::string get_diamond_name() {return name; } 
};

#endif