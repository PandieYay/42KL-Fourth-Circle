#include "MateriaSource.hpp"

int MateriaSource::_size = 0;

MateriaSource::MateriaSource(){
}

MateriaSource::MateriaSource(const MateriaSource &a){
    _size = a._size;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &a){
    _size = a._size;
	return *this;
}

MateriaSource::~MateriaSource(){
}

void MateriaSource::learnMateria(AMateria *materia){
    if (_size <= 3)
    {
        _materia[_size] = materia;
        ++_size;
    }
}

AMateria *MateriaSource::createMateria(string const &type){
    for (int i = 0; i < _size; i++)
    {
        if (_materia[i]->getType() == type)
            return(_materia[i]);
    }
    return (NULL);
}