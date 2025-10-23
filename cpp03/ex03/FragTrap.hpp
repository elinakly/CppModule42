#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
		unsigned int Frag_hit_points;
		unsigned int Frag_attack_damage;
    public:
        FragTrap();
        FragTrap(std::string n);
        FragTrap(const FragTrap& other);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& other);
		
        void 	attack(const std::string& target) override;
        void highFiveGuys(void);
};

#endif