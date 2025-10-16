#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzZ...\n";
}

Zombie::~Zombie() {
    std::cout << name << " was destroyed" << std::endl;
}
