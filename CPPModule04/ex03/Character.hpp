#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
    private:
        string _name;
        AMateria *_inventory[4];
        static int _size;
    public:
        Character(string name);
		Character(const Character &a);
		Character &operator = (const Character &a);
        ~Character();
        string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif