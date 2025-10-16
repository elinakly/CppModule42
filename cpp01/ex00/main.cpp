#include "Zombie.hpp"

int main()
{
    randomChump("Elina");
    Zombie* z = newZombie("Filipe");
    delete z;      
    return(0);
}