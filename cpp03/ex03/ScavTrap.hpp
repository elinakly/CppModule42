#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:
        unsigned int Scav_energy_points;
    public:
        ScavTrap();
        ScavTrap(std::string n);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target) override;
};

#endif
