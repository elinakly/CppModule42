#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
		Brain *CatBrain;
    public :
        Cat();
        Cat(const Cat& other);
        ~Cat() override;

        Cat& operator=(const Cat& other);

        void makeSound() const override;
};