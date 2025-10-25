#pragma once

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat() override;

        WrongCat& operator=(const WrongCat& other);

        void makeSound() const; // if we dont do override  its gonna print WrongAnimal sound / not WrongCat
};