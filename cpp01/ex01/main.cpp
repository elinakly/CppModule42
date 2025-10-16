#include "Zombie.hpp"

int main()
{
    int size = 5;
    std::string name = "Elina";

    Zombie* horde = zombieHorde(size, name);
    if (horde == nullptr)
        return(1);
    // for (int i = 0; i < size; i++)
    //     horde[i].announce();
    delete[] horde;
}