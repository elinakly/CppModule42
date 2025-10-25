
#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal(); //This ensures correct polymorphic cleanup. (and parent and child)
        WrongAnimal& operator=(const WrongAnimal& other);

        void makeSound() const; // if we dont do virtual its gonna print WrongAnimal sound
        std::string getType() const { return type; }

};