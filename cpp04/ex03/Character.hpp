#pragma once 

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
// #include "Floor.hpp"

#define slot 4

class Character : public ICharacter
{
    private:
        std::string		name;
		AMateria* 		inventory[slot];
		// Floor			floor;
    public:
        Character();
        Character(std::string name);
        Character(const Character&);
        Character& operator=(const Character& other);
        ~Character() override;
        std::string const & getName() const override { return name; }
        void equip(AMateria* m) override;
        void unequip(int idx) override;
        void use(int idx, ICharacter& target) override;
};