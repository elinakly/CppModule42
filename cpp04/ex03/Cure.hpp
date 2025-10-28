#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& other);
        ~Cure();

        Cure& operator=(const Cure& other);

        AMateria* clone() const override;
        void use(ICharacter& target) override;
};