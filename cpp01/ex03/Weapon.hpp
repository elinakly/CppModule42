#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(const std::string& t) : type(t) {}
        ~Weapon()  = default;
        const std::string& getType();
        void setType(const std::string& new_type);
};
#endif