#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat& other);
        ~Cat() override;

        Cat& operator=(const Cat& other);

        void makeSound() const override;
};