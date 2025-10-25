#pragma once

#include <string>
#include <iostream>


class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal(); //This ensures correct polymorphic cleanup. (and parent and child)
        Animal& operator=(const Animal& other);

        virtual void makeSound() const;
        std::string getType() const { return type; }

};