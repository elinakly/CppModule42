#pragma once 

#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();
        std::string const &getType() const {return AMateriaType;} //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
