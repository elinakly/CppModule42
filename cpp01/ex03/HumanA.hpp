#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanA(const std::string& n, Weapon& w) : name(n), weapon(&w)  {}
        ~HumanA() = default;
        void attack();
};

#endif