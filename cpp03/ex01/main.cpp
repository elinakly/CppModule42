#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    std::cout << "\n================\n";
    std::cout << "\nSCAV TRAP CALLED\n";
    std::cout << "\n================\n";

    ScavTrap s1("Guardian");
    ScavTrap s2(s1);
    ScavTrap s3;
    s3 = s1;

    s1.attack("Intruder");
    s1.takeDamage(50);
    s1.beRepaired(20);
    s1.guardGate(); // specific method

    s1.takeDamage(200); // should die
    s1.attack("Enemy after death"); // should fail
    s1.beRepaired(10); // should fail
    return 0;
}

