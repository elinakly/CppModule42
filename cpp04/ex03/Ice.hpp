#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        ~Ice();
        
        Ice& operator=(const Ice& other);

        AMateria* clone() const override;
        void use(ICharacter &target) override;
};