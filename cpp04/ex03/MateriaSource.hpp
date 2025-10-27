#pragma once

#include <iostream>
#include <string>

#define slot 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*	templates[slot];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource() override;
        void learnMateria(AMateria* m) override;
        AMateria* createMateria(std::string const & type) override;
};
