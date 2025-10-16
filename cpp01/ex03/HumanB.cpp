#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& new_weapon)
{
    weapon = &new_weapon;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " doesnt have a weapon\n";

}