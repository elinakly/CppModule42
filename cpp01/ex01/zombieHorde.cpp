#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return(std::cout << "Enter a valid(positive) number of zombie\n", nullptr);
    else if(N > 100000)
        return(std::cout << "That`s too many zombies!!\n", nullptr);
    if (name == "")
        return(nullptr);
    Zombie *hord = new Zombie[N];
    if(hord == nullptr)
        return(nullptr);
    for(int i = 0; i < N; i++)
        hord[i].changename(name);
    return(hord);
}