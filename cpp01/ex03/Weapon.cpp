#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return(type);
}

void Weapon::setType(const std::string& new_type)
{
    type = new_type;
}

