#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
    public:
        Ice();
		Ice(const Ice &a);
		Ice &operator = (const Ice &a);
        ~Ice();
        AMateria *clone() const;
        void use(ICharacter& target);
};

#endif