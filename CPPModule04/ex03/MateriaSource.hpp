#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
    public:
        void learnMateria(AMateria*);
        AMateria *createMateria(string const &type);
};

#endif