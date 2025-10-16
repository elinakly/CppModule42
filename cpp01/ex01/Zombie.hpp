#ifndef ZOOMBIE_HPP
#define ZOOMBIE_HPP

#include <iostream>
#include <string>
// #include <iomanip> 

class Zombie
{
    private:
        std::string name = "";
    public:
        Zombie() {};
        ~Zombie();
        void changename(std::string n);
        // void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif