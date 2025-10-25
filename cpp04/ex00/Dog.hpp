#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(const Dog& other);
        ~Dog() override;
        Dog& operator=(const Dog& other);

        void makeSound() const override;
};