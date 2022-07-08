#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
    private:
        string _name;
        AMateria *_inventory[4];
    public:
        Character(string name);
        string const & getName() const = 0;
        void equip(AMateria* m) = 0;
        void unequip(int idx) = 0;
        void use(int idx, ICharacter& target) = 0;
};

#endif