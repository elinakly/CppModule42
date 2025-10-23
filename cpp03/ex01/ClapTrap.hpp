#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    protected: // so we can use "private" in ScavTrap
        std::string name;
        unsigned int hit_points = 10;
        unsigned int energy_point = 10;
        unsigned int attack_damage = 2;
    public:
        ClapTrap();
        ClapTrap(std::string n);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        unsigned int get_energy_points() { return energy_point; }
        unsigned int get_attack_damage() { return attack_damage; }
        unsigned int get_hit_points() { return hit_points; }
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif