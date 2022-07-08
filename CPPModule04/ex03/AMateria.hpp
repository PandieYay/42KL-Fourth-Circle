#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria;
#include "ICharacter.hpp"
#include <string>

using std::string;

class AMateria {
    protected:
        string _type;
    public:
        AMateria(string const & type);
    	virtual ~AMateria();
        string const & getType() const; //Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif