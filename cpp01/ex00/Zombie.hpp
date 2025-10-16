#ifndef ZOOMBIE_HPP
#define ZOOMBIE_HPP

#include <iostream>
#include <string>
// #include <iomanip> 

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string n) : name(n){};
        ~Zombie();
        void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif