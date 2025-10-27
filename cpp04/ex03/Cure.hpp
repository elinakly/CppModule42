#pragma once

#include <iostream>
#include <string>

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