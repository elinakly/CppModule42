#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *DogBrain;
    public :
        Dog();
        Dog(const Dog& other);
        ~Dog() override;
        Dog& operator=(const Dog& other);

        void makeSound() const override;
};