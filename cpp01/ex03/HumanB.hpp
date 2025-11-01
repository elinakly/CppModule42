#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string& n) : name(n), weapon(nullptr) {}
        ~HumanB() = default;
        void attack();
        void setWeapon(Weapon& new_weapon);
};

#endif