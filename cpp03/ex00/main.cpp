#include "ClapTrap.hpp"
#include <iomanip>

int main()
{
    ClapTrap a;
    ClapTrap b("Bob");
    ClapTrap c(b);
    ClapTrap d;                  
    d = a;
    
    b.attack("Enemy");
    b.takeDamage(3);
    b.beRepaired(5);

    b.takeDamage(20); // should die
    b.attack("Another Enemy"); // should fail (dead)
    b.beRepaired(2);  // should fail (dead)

    return 0;
}

